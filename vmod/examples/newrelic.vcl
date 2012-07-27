import newrelic;
backend default {
    .host = "127.0.0.1";
    .port = "3000";
}

C{
    #include <sys/time.h>
    #include <stdio.h>
}C

sub vcl_recv {
    C{
        struct timeval detail_time;
        gettimeofday(&detail_time,NULL);
        char start[20]; 
        sprintf(start, "t=%lu%06lu", detail_time.tv_sec, detail_time.tv_usec);
        VRT_SetHdr(sp, HDR_REQ, "\020X-Request-Start:", start, vrt_magic_string_end);
    }C
}
