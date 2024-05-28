# Instalar y cargar las librerías necesarias
library(tuneR)
library(seewave)

# Leer los archivos de sonido
nombre <- readWave("nombre.wav")
apellidos <- readWave("apellidos.wav")

# Ajustar los márgenes gráficos
par(mar = c(5, 4, 4, 2) + 0.1)

# Paso 2: Dibujar la forma de onda de ambos sonidos
png("forma_onda_nombre.png")
oscillo(nombre, title = "Forma de onda del nombre")
dev.off()

png("forma_onda_apellido.png")
oscillo(apellidos, title = "Forma de onda del apellidos")
dev.off()

# Paso 3: Obtener la información de las cabeceras de ambos sonidos
str(nombre)
str(apellidos)

# Paso 4: Unir ambos sonidos en uno nuevo
combined <- pastew(nombre, apellidos, output = "Wave")

# Paso 5: Dibujar la forma de onda de la señal resultante
png("forma_onda_combinada.png")
oscillo(combined, title = "Forma de onda de la señal combinada")
dev.off()

# Paso 6: Pasarle un filtro de frecuencia para eliminar las frecuencias entre 10000Hz y 20000Hz
from_freq <- 10000 / (combined@samp.rate / 2)
to_freq <- 20000 / (combined@samp.rate / 2)

filtered_matrix <- bwfilter(combined@left, f = combined@samp.rate, channel = 1, from = from_freq, to = to_freq, bandpass = FALSE)

# Convertir la matriz filtrada de nuevo a un objeto Wave
filtered <- Wave(left = as.integer(filtered_matrix), samp.rate = combined@samp.rate, bit = combined@bit)

# Dibujar la forma de onda del sonido filtrado
png("forma_onda_filtrada.png")
oscillo(filtered, f = filtered@samp.rate, title = "Forma de onda de la señal filtrada")
dev.off()

# Paso 7: Almacenar la señal obtenida como un fichero WAV denominado “mezcla.wav”
writeWave(filtered, file = "mezcla.wav")

