# dockerfiles

Dockerfiles repository

## comandos

### Run the container

`$ docker run -v ${PWD}:/src/ -it {container-name} <command>`

### build image

Build `docker build -t {image-name} .`

```bash
docker build -t z88dk-dev .
```

Tag `docker image tag {image-name} {USER}/{image-name}:latest`

```bash
docker image tag z88dk-dev dgzornoza/z88dk-dev:latest
```

Push `docker image push {USER}/{image-name}:latest`

```bash
docker image push dgzornoza/z88dk-dev:latest
```
