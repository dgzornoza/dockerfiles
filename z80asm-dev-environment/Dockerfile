# To create the image:
#   $ docker build -t z80asm-dev .
# To run the container:
#   $ docker run -v ${PWD}:/src/ -it z80asm-dev <command>

FROM alpine:latest

LABEL Version="1.0.0" \
      Date="2023/09/01" \
      Docker_Version="24.0.2, build cb74dfc" \
      Maintainer="David Gonzalez Zornoza (https://github.com/dgzornoza)" \
      Description="Docker container with Z80 ASM environment for visual studio dev-container"

## install packages base with gcc compiler
RUN apk --no-cache add build-base \
	&& apk add --no-cache -t .build_deps git subversion \
	&& apk add nodejs npm

# extra-packages
RUN apk add nano && apk add curl


ENV INSTALL_PATH="/opt"
ENV PASMO_PATH="/opt/pasmo"
ENV SJASMPLUS_PATH="/opt/sjasmplus"

# INSTALL PASMO ASM ----------------------------
COPY ./pasmo-0.5.5.tar.gz ${INSTALL_PATH}

RUN cd ${INSTALL_PATH} \
	&& tar -zxvf ./pasmo-0.5.5.tar.gz \
	&& rm ./pasmo-0.5.5.tar.gz \
	&& mv ./pasmo-0.5.5 pasmo
	
# compile pasmo
RUN cd ${PASMO_PATH} \
    && chmod 777 configure \
    && ./configure \
    && make \
	&& make install

# INSTALL SJASMPLUS ASM ----------------------------
RUN cd ${INSTALL_PATH} \
	&& git clone --recursive -j8 https://github.com/z00m128/sjasmplus.git
	
RUN cd ${SJASMPLUS_PATH} \	    
    && make \
	&& make install
    
	
RUN apk del .build_deps
	
WORKDIR /workspaces/