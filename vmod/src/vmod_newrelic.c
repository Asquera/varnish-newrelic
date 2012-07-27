#include <sys/time.h>
#include <stdio.h>

#include "vrt.h"
#include "bin/varnishd/cache.h"
#include "vcc_if.h"

void vmod_set_x_request_start(struct sess* session) {
    struct timeval detail_time;
    gettimeofday(&detail_time, 0);
    
    char start[20];
    
    sprintf(start, "t=%lu%06lu", detail_time.tv_sec, detail_time.tv_usec);
    VRT_SetHdr(session, HDR_REQ, "\020X-Request-Start:", start, vrt_magic_string_end);
}
