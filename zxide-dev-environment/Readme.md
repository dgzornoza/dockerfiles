# imagen para ZxIde

En esta guia se indican los pasos para crear una imagen a usar en un devcontainer para la extension ZxIde de vscode con todas las herramientas necesarias.
Estos pasos sirven para evitar que cada contenedor crezca demasiado, instalando todas las extensiones de vscode necesarias en la imagen.

Aqui se encontrara la siguiente estructura de directorios:

- .devcontainer: carpeta con la configuracion del devcontainer
- z88dk-sample: carpeta con un proyecto de ejemplo para z88dk
- Readme.md: este archivo
- z88dk-sample.code-workspace: archivo con el espacio de trabajo para el proyecto z88dk-sample

## Descripcion

Se podria usar el dockerfile para crear la imagen, pero con cada proyecto que se crea con el devcontainer se instalan las extensiones de vscode necesarias, lo que hace que el contenedor crezca mucho (sobretodo con las extensiones de c/c++). Para evitarlo, se va a crear una imagen con todas las extensiones y dependencias necesarias, y luego se usara esa imagen en los devcontainers.

Debido a que algunas extensiones solo se activan cuando se detecta un proyecto de cierto tipo, se ha creado un proyecto de ejemplo para z88dk, que se encuentra en la carpeta z88dk-sample. Este proyecto se usa para que vscode detecte las extensiones necesarias y las instale en el contenedor.

## Pasos para crear la imagen

1. abrir el archivo 'z88dk-sample.code-workspace' con vscode (workspace que incluye el proyecto de ejemplo)
2. abrir la paleta de comandos (Ctrl+Shift+P)
3. seleccionar "Dev Containers: Reopen in Container"
4. esperar a que se cree la imagen, instalen todas las extensiones y dependencias de vscode y se inicie el contenedor
5. cerrar vscode
6. crear la imagen final con el comando:

   ```bash
   docker commit zxide-dev-environment zxide-dev
   ```

7. etiquetar la imagen con el comando:

    ```bash
    docker tag zxide-dev {docker-hub-user}/zxide-dev:latest
    ```

8. subir la imagen a docker hub con el comando:

    ```bash
    docker push {docker-hub-user}/zxide-dev:latest
    ```

9. ya se puede usar esta imagen en cualquier devcontainer, especificandola en el archivo devcontainer.json:

    ```json
    "image": "{docker-hub-user}/zxide-dev:latest"
    ```
