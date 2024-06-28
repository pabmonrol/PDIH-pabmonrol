# Practice 5: Sound File Waveform Analysis

This project aims to read, analyze, and visualize the waveforms of sound files using R. It utilizes the `tuneR` and `seewave` libraries to process the sound files.

## Project Content

- **file.R**: Main script that performs the following tasks:
  - Installs and loads the necessary libraries.
  - Reads the sound files.
  - Adjusts the graphic margins.
  - Draws and saves the sound waveforms as PNG files.

## Dependencies

The script requires the following R libraries:

- `tuneR`
- `seewave`

These libraries must be installed and loaded in your R environment.

## Usage

1. **Prepare the sound files**: Ensure you have the sound files `nombre.wav` and `apellidos.wav` in the same directory as the `file.R` script.

2. **Run the script**: Execute the script in R to process the sound files and generate the waveforms.

    ```R
    source("file.R")
    ```

3. **Results**: The PNG files with the sound waveforms.
   
![](/img/Tasks/Task-5/forma_onda_nombre.png)

![](/img/Tasks/Task-5/forma_onda_apellido.png)

![](/img/Tasks/Task-5/forma_onda_combinada.png)

![](/img/Tasks/Task-5/forma_onda_filtrada.png)

## Audios

[Nombre](/Tasks/Task-5/audio/nombre.wav)

[Apellidos](/Tasks/Task-5/audio/apellidos.wav)

[Extra](/Tasks/Task-5/audio/guau.wav)

[Mezcla](/Tasks/Task-5/audio/mezcla.wav)
