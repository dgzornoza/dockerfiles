# To create the image:
#   $ docker build -t pasmo-dev .
# To run the container:
#   $ docker run -v ${PWD}:/src/ -it pasmo-dev <command>

FROM alpine:latest

LABEL Version="0.5.5" \
      Date="2023/09/01" \
      Docker_Version="24.0.2, build cb74dfc" \
      Maintainer="David Gonzalez Zornoza (https://github.com/dgzornoza)" \
      Description="Docker container with Pasmo ASM environment for visual studio dev-container"

ENV PASMO_INSTALL_PATH="/opt"
ENV PASMO_PATH="/opt/pasmo"

# copy pasmo
COPY ./pasmo-0.5.5.tar.gz ${PASMO_INSTALL_PATH}

RUN cd ${PASMO_INSTALL_PATH} \
	&& tar -zxvf ./pasmo-0.5.5.tar.gz \
	&& rm ./pasmo-0.5.5.tar.gz \
	&& mv ./pasmo-0.5.5 pasmo
	
## install packages base with gcc compiler
RUN apk --no-cache add build-base

# extra-packages
RUN apk add nano && apk add curl

# compile pasmo
RUN cd ${PASMO_PATH} \
    && chmod 777 configure \
    && ./configure \
    && make \
	&& make install

WORKDIR /workspaces/