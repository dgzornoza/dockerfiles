# Dockerfile for devcontainer with Python 3.12, Poetry, git, and nano
FROM python:3.12-slim

# Establecer variables de entorno para Poetry
ENV POETRY_VERSION=2.0.0 \
    POETRY_HOME="/root/.local"
ENV PATH="$POETRY_HOME/bin:$PATH"

# Instalar dependencias del sistema y Poetry en una simple capa para mejorar la eficiencia
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    git \
    nano \
    curl \
    cmake \
    gcc \
    g++ \
    build-essential && \
    curl -sSL https://install.python-poetry.org | python3 - && \
    ln -s $POETRY_HOME/bin/poetry /usr/local/bin/poetry && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Set workdir
WORKDIR /workspaces

CMD ["bash"]
