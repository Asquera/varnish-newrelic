varnish-newrelic
================



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


To clean everything, execute the `clean` shell script in the **vmod** folder. This removes all generated
files and directories.