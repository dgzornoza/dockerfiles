# imagen para ZxIde

En esta guia se indican los pasos para crear una imagen para ZxIde con todas las herramientas necesarias.
Estos pasos sirven para evitar que cada contenedor crezca demasiado, instalando todas las extensiones de vscode necesarias en la imagen.

## creacion de la imagen base

En esta carpeta se encuentra un Dockerfile que crea una imagen base con todas las herramientas necesarias para trabajar con ZxIde.
Para crear la imagen, ejecutar el siguiente comando en la terminal:

```bash
docker build -t zxide-base .
```

## creacion de la imagen final

La imagen final se crea a partir de la imagen base, instalando las extensiones de vscode necesarias y el servidor de vscode.
Esta es la forma mas segura de instalar las extensiones, ya que sera vscode quien las instale correctamente.
Para crear la imagen final, ejecutar los siguientes comandos:

```bash
# ejecutar la imagen base en modo interactivo para instalar las extensiones
docker run -it --name temp-z88dk <tu-imagen-base> bash

```
