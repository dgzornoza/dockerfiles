# python-dev-environment

Proyecto para crear una imagen de docker, conteniendo un entorno de desarrollo para python con las herramientas comunmente utilizadas para ser usada como devcontainer en vscode.

## Descripcion

Imagen de desarrollo para Python basada en la imagen oficial `python:3.12-slim`, pensada para usar en Dev Containers.

- Incluye Python 3.12 y utilidades del sistema: `git`, `nano`, `curl`, `cmake`, `gcc`, `g++`, `build-essential`.
- Instala Poetry (por defecto `POETRY_VERSION=2.0.0`) y lo configura globalmente;
- Optimizada para caché de dependencias: copia `pyproject.toml` y `poetry.lock` antes de ejecutar `poetry install` para evitar reinstalaciones innecesarias.
- Configura Poetry para no crear entornos virtuales (`virtualenvs.create false`) y deja el entorno listo dentro del contenedor.
- Directorio de trabajo: `/workspaces`. Comando por defecto: `bash`.

## Pasos para crear la imagen

1. abrir la carpeta con vscode
2. abrir la paleta de comandos (Ctrl+Shift+P)
3. seleccionar "Dev Containers: Reopen in Container"
4. esperar a que se cree la imagen, instalen todas las extensiones y dependencias de vscode y se inicie el contenedor
5. cerrar vscode
6. crear la imagen final con el comando:

   ```bash
   docker commit python-dev-environment python-dev
   ```

7. etiquetar la imagen con el comando:

    ```bash
    docker tag python-dev dgzornoza/python-dev:latest
    ```

8. subir la imagen a docker hub con el comando:

    ```bash
    docker push dgzornoza/python-dev:latest
    ```

## Usando la imagen

para usar la imagen como un devcontainer, realizar los siguientes pasos:

1. descargar la plantilla `python-project-template.zip
` que contiene un proyecto python basico desde la ultima [release](https:/https://github.com/dgzornoza/dockerfiles/releases)
2. descomprimir el archivo zip
3. abrir la carpeta del proyecto con vscode
4. abrir la paleta de comandos (Ctrl+Shift+P)
5. seleccionar "Dev Containers: Reopen in Container"
6. esperar a que se inicie el contenedor
7. comenzar a desarrollar!
