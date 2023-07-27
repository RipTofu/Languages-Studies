import random
import pandas as pd
import matplotlib.pyplot as plt

# Determinar semilla
random.seed(1234)


# Clases
class Tracks:
    def __init__(self, _qualy, _nombre, _tiempo_record, _tiempo_estimado):
        self.qualy = _qualy
        self.nombre = _nombre
        self.tiempo_record = _tiempo_record
        self.tiempo_estimado = _tiempo_estimado

    # Generación de número aleatorio

    def numero_random(self):
        tiempo_generado = round(random.uniform(self.tiempo_record, self.tiempo_estimado), 2)
        return tiempo_generado


class Pilotos:
    def __init__(self, _nombre, _equipo):
        self.nombre = _nombre
        self.equipo = _equipo
        self.tiempo_qualy = []


# Datos a dataframes
tracks = pd.read_csv("tracks.csv", delimiter=",")
equipos = pd.read_csv("equipos.csv", delimiter=",")
trackz = []
pilotz = []
# Extracción de datos para generación de objetos de clases.
for i in range(len(tracks)):
    qualy = tracks.iloc[i, 9]
    nombre = tracks.iloc[i, 2]
    tiempo_r = tracks.iloc[i, 6]
    tiempo_e = tracks.iloc[i, 7]
    trackz.append(Tracks(qualy, nombre, tiempo_r, tiempo_e))
    # Cada objeto se almacena en la lista tracksz

for i in range(len(equipos)):
    nombre1 = equipos.iloc[i, 1]
    nombre2 = equipos.iloc[i, 3]
    equipo = equipos.iloc[i, 0]
    pilotz.append(Pilotos(nombre1, equipo))
    pilotz.append(Pilotos(nombre2, equipo))

# Creacion de archivos
for carrera in trackz:
    nombrepista = carrera.nombre
    linea_escribir = "Piloto,Equipo"
    for lap in range(carrera.qualy):
        vuelta = "L" + str(lap + 1)
        linea_escribir = linea_escribir + "," + vuelta
    for piloto in pilotz:
        linea = piloto.nombre
        linea = linea + "," + piloto.equipo
        for e in range(carrera.qualy):
            num = carrera.numero_random()
            linea = linea + "," + str(num)
        linea_escribir = linea_escribir + "\n" + linea
    nombrearchivo = "resultado_" + nombrepista + ".txt"
    file = open(nombrearchivo, "w")
    file.writelines(linea_escribir)
    file.close()

# Extracción de datos almacenados en los nuevos archivos
rspa = pd.read_csv("resultado_spa.txt", delimiter=",")
rmnc = pd.read_csv("resultado_monaco.txt", delimiter=",")
rsvs = pd.read_csv("resultado_silverstone.txt", delimiter=",")
rabh = pd.read_csv("resultado_abudhabi.txt", delimiter=",")
rzvt = pd.read_csv("resultado_zandvoort.txt", delimiter=",")

# Matriz de tiempo por piloto
resultados = []
for numero, piloto in enumerate(pilotz):
    spa = rspa.iloc[numero, -1]
    mnc = rmnc.iloc[numero, -1]
    svs = rsvs.iloc[numero, -1]
    abh = rabh.iloc[numero, -1]
    zvt = rzvt.iloc[numero, -1]
    resultados.append([piloto.nombre, mnc, svs, spa, zvt, abh])

# Grafico
x = []
for carrera in trackz:
    x.append(carrera.nombre)
for f in resultados:
    y = f[1:]
    plt.plot(x, y)
nombres = []
for piloto in pilotz:
    nombres.append(piloto.nombre)
plt.xlabel("Pista")
plt.ylabel("Tiempo")
plt.legend(nombres)
plt.show()
