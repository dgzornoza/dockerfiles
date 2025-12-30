# Docker file with vscode devcontainer for debug extension in container
# this file require z88dk instalation and sjasmplus to use in debug session
FROM mcr.microsoft.com/vscode/devcontainers/base:latest

# Variables de entorno
ENV INSTALL_PATH="/opt" 
ENV PASMO_PATH="${INSTALL_PATH}/pasmo" \
    SJASMPLUS_PATH="${INSTALL_PATH}/sjasmplus" \
    Z88DK_PATH="${INSTALL_PATH}/z88dk"

# Instalar paquetes base y dependencias de build
# nodejs & npm is vscode devcontainer requirements
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
	nodejs \	
    npm \	
    git \
    subversion \
    nano \
    curl \
    libxml2-dev \
    m4 \
    libgmp-dev \
    bison \
    flex \
    libboost-dev \
    texinfo \
    cpanminus \
    perl \
    && rm -rf /var/lib/apt/lists/*

# --- INSTALL PASMO ASM ---
COPY ./pasmo-0.5.5.tar.gz ${INSTALL_PATH}

RUN cd ${INSTALL_PATH} \
    && tar -zxvf ./pasmo-0.5.5.tar.gz \
    && rm ./pasmo-0.5.5.tar.gz \
    && mv ./pasmo-0.5.5 ${PASMO_PATH} \
    && cd ${PASMO_PATH} \
    && chmod +x configure \
    && ./configure \
    && make \
    && make install

# --- INSTALL SJASMPLUS ASM ---
RUN git clone --recursive -j8 https://github.com/z00m128/sjasmplus.git ${SJASMPLUS_PATH} \
    && cd ${SJASMPLUS_PATH} \
    && make \
    && make install

# --- INSTALL Z88DK ---
RUN git clone --depth 1 --recursive https://github.com/z88dk/z88dk.git ${Z88DK_PATH} \
    && cpanm -l $HOME/perl5 --no-wget local::lib Template::Plugin::YAML \
    && cd ${Z88DK_PATH} \
    && eval "$(perl -I$HOME/perl5/lib/perl5 -Mlocal::lib)" \
    && chmod +x build.sh \
    && BUILD_SDCC=1 BUILD_SDCC_HTTP=1 ./build.sh \
    && make install-clean bins-clean

# Set environment variables for PATH and ZCCCFG
ENV PATH="${Z88DK_PATH}/bin:${PATH}" \
    ZCCCFG="${Z88DK_PATH}/lib/config/"

	

WORKDIR /workspaces/


