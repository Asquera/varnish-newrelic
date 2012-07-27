import newrelic;
backend default {
    .host = "127.0.0.1";
    .port = "4567";
}

sub vcl_recv {
    newrelic.set_x_request_start();
}
