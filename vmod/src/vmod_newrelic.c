#include <stdlib.h>
#include <stdio.h>

#include "vrt.h"
#include "bin/varnishd/cache.h"
#include "vcc_if.h"


void vmod_add_header(struct sess* session) {

}

/*
 * Add X-Request-Start header so we can track queue times in New Relic RPM beginning at Varnish.
 *

#include <sys/time.h>

struct timeval detail_time;
gettimeofday(&detail_time,NULL);
char start[20]; 
sprintf(start, "t=%lu%06lu", detail_time.tv_sec, detail_time.tv_usec);
VRT_SetHdr(sp, HDR_REQ, "\020X-Request-Start:", start, vrt_magic_string_end);
*/