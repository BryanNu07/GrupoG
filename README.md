#  Repositorio de Actividades - Grupo G

¡Bienvenidos al repositorio oficial del **Grupo G**! Este espacio está destinado a almacenar y organizar de manera profesional todas nuestras resoluciones de ejercicios de programación. 

Para que el profesor pueda identificar el trabajo de cada uno sin confusiones, **cada integrante del grupo tendrá su propia carpeta raíz nombrada con sus nombres y apellidos**.

---

##  Estructura del Repositorio

El directorio principal del proyecto debe organizarse de la siguiente manera:

grupoG/
├── README.md                           # Este archivo (Guía general)
├── .gitignore                          # Filtro para no subir archivos basura (.exe)
│
├── Juan_Perez_Alvarez/                 # <--- CARPETA INDIVIDUAL (Tus Nombres y Apellidos)
│   ├── README.md                       # Explicación específica de tus ejercicios y pruebas
│   ├── ejercicios/                     # Carpeta con tus códigos fuente (.cpp)
│   │   ├── ejercicio1_buscador.cpp
│   │   └── ejercicio2_iterador.cpp
│   └── capturas/                       # Carpeta con tus evidencias de ejecución (.png, .jpg)
│       ├── captura_ej1.png
│       └── captura_ej2.png
│
└── Maria_Gomez_Restrepo/               # <--- Carpeta del siguiente integrante...
    ├── README.md
    ├── ejercicios/
    └── capturas/

---

##  ¿Qué debe incluir tu carpeta personal?

Al subir tus aportes, asegúrate de cumplir con los siguientes requisitos dentro de tu carpeta de nombres y apellidos:

### 1.  Carpeta `ejercicios/`
* Aloja únicamente los archivos de código fuente con extensión `.cpp`.
* Los nombres de los archivos deben ser claros y descriptivos (Ej: `ejercicio1_buscador.cpp`).
* El código debe estar limpio, ordenado y contener comentarios breves si la lógica es compleja.

### 2.  Carpeta `capturas/`
* Contiene las imágenes que demuestran que tu código compila y funciona correctamente en la terminal.
* Toma la captura directamente a la consola donde se aprecie el resultado del programa ejecutado.
* Intenta recortar los bordes sobrantes de tu pantalla para que el repositorio se vea limpio.

### 📄 Tu propio `README.md` (Interno de tu carpeta)
Este archivo es la portada de tu entrega. Debe contener de forma obligatoria:
* **Título de la actividad** y fecha de realización.
* Tu **Nombre Completo**.
* Una breve **explicación de los casos de prueba** que ejecutaste (qué datos de entrada usaste en la terminal y qué salidas generó tu programa).

---

## 🛠️ Buenas Prácticas para el Grupo

1. **Formato de nombres:** Para evitar problemas en sistemas operativos como Linux o Mac, nombra tu carpeta principal usando guiones bajos en lugar de espacios (Ej: `Luis_Alfonso_Delgado/` en lugar de `Luis Alfonso Delgado/`).
2. **¡No subas ejecutables!** Asegúrate de tener el archivo `.gitignore` en la raíz del repositorio para evitar que se suban archivos `.exe`, `.out` o carpetas ocultas de los editores (`.vscode`, `.idea`).
3. **Commits descriptivos:** Cuando subas tus archivos por la terminal, usa mensajes claros y profesionales:
   * *Bien:* `git commit -m "feat(JuanPerez): agregar ejercicio 1 y evidencias de ejecucion"`
   * *Mal:* `git commit -m "subiendo mi tarea"` o `git commit -m "cambios"`

¡Mucho éxito con el código, equipo!