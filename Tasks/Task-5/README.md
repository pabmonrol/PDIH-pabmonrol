# Practice 5: Análisis de Formas de Onda de Archivos de Sonido

Este proyecto tiene como objetivo leer, analizar y visualizar las formas de onda de archivos de sonido utilizando R. Utiliza las librerías `tuneR` y `seewave` para realizar el procesamiento de los archivos de sonido.

## Contenido del Proyecto

- **file.R**: Script principal que realiza las siguientes tareas:
  - Instala y carga las librerías necesarias.
  - Lee los archivos de sonido.
  - Ajusta los márgenes gráficos.
  - Dibuja y guarda las formas de onda de los sonidos en archivos PNG.

## Dependencias

El script requiere las siguientes librerías de R:

- `tuneR`
- `seewave`

Estas librerías deben estar instaladas y cargadas en su entorno de R.

## Uso

1. **Preparar los archivos de sonido**: Asegúrese de tener los archivos de sonido `nombre.wav` y `apellidos.wav` en el mismo directorio que el script `file.R`.

2. **Ejecutar el script**: Ejecute el script en R para procesar los archivos de sonido y generar las formas de onda.

    ```R
    source("file.R")
    ```

3. **Resultados**: Los archivos PNG con las formas de onda de los sonidos.
   
![](/img/Tasks/Task-5/forma_onda_nombre.png)

![](/img/Tasks/Task-5/forma_onda_apellido.png)

![](/img/Tasks/Task-5/forma_onda_combinada.png)

![](/img/Tasks/Task-5/forma_onda_filtrada.png)

## Audios

[](/Tasks/Task-5/audio/nombre.wav)

[](/Tasks/Task-5/audio/apellidos.wav)

[](/Tasks/Task-5/audio/guau.wav)

[](/Tasks/Task-5/audio/mezcla.wav)
