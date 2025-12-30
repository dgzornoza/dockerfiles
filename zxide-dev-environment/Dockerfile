# To create the image:
#   $ docker build -t zxide-dev .
# To run the container:
#   $ docker run -v ${PWD}:/src/ -it zxide-dev <command>
FROM alpine:latest

LABEL Version="1.0.0" \
      Date="2025/12/29" \
      Docker_Version="29.1.2" \
      Maintainer="David Gonzalez Zornoza (https://github.com/dgzornoza)" \
      Description="Docker container with zxide environment (z88dk, sjasmplus, pasmo) for visual studio dev-container"

## Install base packages with gcc compiler
RUN apk --no-cache add build-base \
    && apk add --no-cache -t .build_deps git subversion \
    && apk add nodejs npm \
    && apk add nano curl

# Environment variables
ENV INSTALL_PATH="/opt"
ENV PASMO_PATH="${INSTALL_PATH}/pasmo" \
    SJASMPLUS_PATH="${INSTALL_PATH}/sjasmplus" \
    Z88DK_PATH="${INSTALL_PATH}/z88dk"

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
RUN apk add --no-cache libxml2 m4 gmp-dev gmp \
    && apk add --no-cache -t .build_deps git bison flex libxml2-dev boost-dev texinfo perl-template-toolkit perl-app-cpanminus \
    && git clone --depth 1 --recursive https://github.com/z88dk/z88dk.git ${Z88DK_PATH} \
    && cpanm -l $HOME/perl5 --no-wget local::lib Template::Plugin::YAML \
    && cd ${Z88DK_PATH} \
    && eval "$(perl -I$HOME/perl5/lib/perl5 -Mlocal::lib)" \
    && chmod +x build.sh \
    && BUILD_SDCC=1 BUILD_SDCC_HTTP=1 ./build.sh \
    && make install-clean bins-clean

# Cleanup build dependencies
RUN apk del .build_deps

# Set environment variables for PATH and ZCCCFG
ENV PATH="${Z88DK_PATH}/bin:${PATH}" \
    ZCCCFG="${Z88DK_PATH}/lib/config/"

WORKDIR /workspaces/
