# Creación y carga de un módulo LKM en Linux
**Desarrollado por:** Pablo Montero Rollán

**Fecha:** 7 de junio de 2024

## Introducción
En este documento se describe el proceso de creación, carga y verificación de un módulo cargable del núcleo (LKM) en Linux.

![](/img/Seminars/Seminar-LKM/carpetaantes.png)

![](/img/Seminars/Seminar-LKM/carpetadespues.png)

## Desarrollo del módulo
El módulo fue escrito en C.

[Código](/Seminars/Seminar-LKM/LKM.c)

## Makefile
El Makefile utilizado para compilar el módulo.

[Makefile](/Seminars/Seminar-LKM/Makefile)

## Instalación de cabeceras de Linux
Instalar las cabeceras del kernel con los siguientes comandos:

    sudo apt-get update
    sudo apt-cache search linux-headers-$(uname -r)
    sudo apt-get install linux-headers-$(uname -r)

![](/img/Seminars/Seminar-LKM/aptgetupdate.png)

![](/img/Seminars/Seminar-LKM/aptcache.png)

![](/img/Seminars/Seminar-LKM/aptgetinstall.png)

## Instalación de _gcc-12_
Instalar gcc-12 para el correcto funcionamiento. Sin esta instalación nos parecerá este error:

![](/img/Seminars/Seminar-LKM/errorgcc-12.png)


El procedimiento es el siguiente:

![](/img/Seminars/Seminar-LKM/aptgetinstallgcc-12.png)

![](/img/Seminars/Seminar-LKM/aptgetinstall.png)


## Compilación del módulo
Para compilar el módulo, se ejecutó el comando `make` en el directorio que contiene los archivos `hello.c` y `Makefile`.

![](/img/Seminars/Seminar-LKM/make.png)

## Carga del módulo
El módulo se cargó en el kernel con el comando `insmod`:

![](/img/Seminars/Seminar-LKM/insmod.png)

## Listar los módulos

![](/img/Seminars/Seminar-LKM/lista.png)

## Verificación del funcionamiento del módulo
Para verificar que el módulo se cargó correctamente, se inspeccionaron los logs del sistema con `dmesg`:

![](/img/Seminars/Seminar-LKM/hello.png)

## Descarga del módulo
El módulo se descargó del kernel con el comando `rmmod`:

![](/img/Seminars/Seminar-LKM/rmmod.png)

## Última verificación tras la descarga

![](/img/Seminars/Seminar-LKM/goodbye.png)

