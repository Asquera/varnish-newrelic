import newrelic;
backend default {
    .host = "127.0.0.1";
    .port = "8080";
}

sub vcl_recv {
    if (req.url ~ "\.(png|gif|jpg)$") {
        newrelic.add_header();
    }
}
