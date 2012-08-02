varnish-newrelic
================

A small varnish vmod that allows to set the `X-Request-Start` header for use with
[New Relic RPM](http://newrelic.com/) more conveniently.
The vmod just encapsulates a small code snippet
(found [here](http://blog.jacobelder.com/2010/07/tracking-request-queue-time-on-new-relic-rpm-with-varnish/))
and offers a simple function for use in `vcl` scripts. See example below.



### Prerequisites

Dependening on the system setup it might be necessary to install the following packages

* [libtool](http://www.gnu.org/software/libtool/libtool.html)
* [libpcre](http://pcre.org/)

For example in Ubuntu:

    sudo apt-get install libpcre3-dev libtool

### Installation

Download the [varnish source](https://www.varnish-cache.org/releases).
Unpack it to a folder and follow the instructions in the `INSTALL` file.
This should build varnish from source and install it on the system.
Varnish needs `autoconf` and `automake` installed.
In order to compile a varnish module successfully, path variables to the varnish source
and the vmods folder are necessary.
Either provide them by specifying environment variables.

    export VARNISHSRC=path/to/varnish_src
    export VMODDIR=/usr/local/lib/varnish/vmods/ # path might differ

or by providing these variables when calling the `configure` script.

    ./configure VARNISHSRC=path/to/varnish_src VMODDIR=/usr/local/lib/varnish/vmods/


The following steps install the vmod.

    cd vmod
    sh autogen.sh
    ./configure
    make
    make install

Running the `autogen` script can result in an error message, stating the "*required file `ltmain.sh` not found*".
It is [suggested to re-run](https://www.varnish-cache.org/trac/wiki/Installation) the script a second time.



### Example

After the vmod is installed just import the `newrelic` vmod and can be referenced with the
`newrelic.set_x_request_start` function at different points.

    import newrelic;
    backend default {
        .host = "127.0.0.1";
        .port = "4567";
    }
    sub vcl_recv {
        newrelic.set_x_request_start();
    }

To check that everything is correctly set up you can start a small test web application from  he `test`
folder. It needs Ruby with the sinatra gem insalled. Just start it and should display the time stamp
of the `X-Request-Start` header



### Debian Package

A new source package can be created from within the vmod folder.

    dh_make -p <packagename>_<version> -l --createorig

The parameter `l` signals a library source package. `createorig` creates orig.tar.gz file.

* Configure the information regarding package name, maintainer and version in `debian/control` and
`debian/changelog`
* Remove all *.ex files