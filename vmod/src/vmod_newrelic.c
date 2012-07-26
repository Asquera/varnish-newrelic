#include <sys/time.h>
#include <stdio.h>

#include "vrt.h"
#include "bin/varnishd/cache.h"
#include "vcc_if.h"

void vmod_add_header(struct sess* session) {
    struct timeval detail_time;
    gettimeofday(&detail_time, NULL);
    
    char start[20];
    
    sprintf(start, "t=%lu%06lu", detail_time.tv_sec, detail_time.tv_usec);
    VRT_SetHdr(session, HDR_REQ, "\020X-Request-Start:", start, vrt_magic_string_end);
}
