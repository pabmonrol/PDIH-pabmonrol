
# Creation and Loading of an LKM Module in Linux

## Introduction
This document describes the process of creating, loading, and verifying a Loadable Kernel Module (LKM) in Linux.

![Before Directory](/img/Seminars/Seminar-LKM/carpteaantes.png)

![After Directory](/img/Seminars/Seminar-LKM/carpetadespues.png)

## Module Development
The module was written in C.

[Code](/Seminars/Seminar-LKM/LKM.c)

## Makefile
The Makefile used to compile the module.

[Makefile](/Seminars/Seminar-LKM/Makefile)

## Installation of Linux Headers
Install the kernel headers with the following commands:

```sh
sudo apt-get update
sudo apt-cache search linux-headers-$(uname -r)
sudo apt-get install linux-headers-$(uname -r)
```

![Update](/img/Seminars/Seminar-LKM/aptgetupdate.png)

![Cache Search](/img/Seminars/Seminar-LKM/aptcache.png)

![Install Headers](/img/Seminars/Seminar-LKM/aptgetinstall.png)

## Installation of gcc-12
Install gcc-12 for proper functionality. Without this installation, you will encounter the following error:

![Error](/img/Seminars/Seminar-LKM/errorgcc-12.png)

The procedure is as follows:

![Install gcc-12](/img/Seminars/Seminar-LKM/aptgetinstallgcc-12.png)

![Install Command](/img/Seminars/Seminar-LKM/aptgetinstall.png)

## Module Compilation
To compile the module, execute the `make` command in the directory containing the `hello.c` and `Makefile` files.

![Make Command](/img/Seminars/Seminar-LKM/make.png)

## Module Loading
The module was loaded into the kernel with the `insmod` command:

![insmod Command](/img/Seminars/Seminar-LKM/insmod.png)

## Listing the Modules

![Module List](/img/Seminars/Seminar-LKM/lista.png)

## Verifying the Module Functionality
To verify that the module was loaded correctly, the system logs were inspected with `dmesg`:

![dmesg Output](/img/Seminars/Seminar-LKM/hello.png)

## Unloading the Module
The module was unloaded from the kernel with the `rmmod` command:

![rmmod Command](/img/Seminars/Seminar-LKM/rmmod.png)

## Final Verification after Unloading

![Goodbye Message](/img/Seminars/Seminar-LKM/goodbye.png)
