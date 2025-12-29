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

## install packages base with gcc compiler
RUN apk --no-cache add build-base \
	&& apk add --no-cache -t .build_deps git subversion \
	&& apk add nodejs npm

# extra-packages
RUN apk add nano && apk add curl

# ASM Image ############################################################
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
	

# z88dk Image ############################################################

ENV Z88DK_PATH="/opt/z88dk"

RUN apk add --no-cache build-base libxml2 m4 curl gmp-dev gmp \
    && apk add --no-cache -t .build_deps bison flex libxml2-dev git subversion boost-dev texinfo \
		perl-template-toolkit perl-app-cpanminus \
	&& apk add nodejs npm \
    && git clone --depth 1 --recursive https://github.com/z88dk/z88dk.git ${Z88DK_PATH}	

RUN cpanm -l $HOME/perl5 --no-wget local::lib Template::Plugin::YAML 

# extra-packages
RUN apk add perl && apk add && apk add nano

# Add, edit or uncomment the following lines to customize the z88dk compilation
# COPY clib_const.m4 ${Z88DK_PATH}/libsrc/_DEVELOPMENT/target/
# COPY config_sp1.m4 ${Z88DK_PATH}/libsrc/_DEVELOPMENT/target/zx/config/

RUN cd ${Z88DK_PATH} \
	&& eval "$(perl -I$HOME/perl5/lib/perl5 -Mlocal::lib)" \
    && chmod 777 build.sh \
    && BUILD_SDCC=1 BUILD_SDCC_HTTP=1 ./build.sh \
    && make install-clean bins-clean  \
    && apk del .build_deps

ENV PATH="${Z88DK_PATH}/bin:${PATH}" \
    ZCCCFG="${Z88DK_PATH}/lib/config/"

WORKDIR /workspaces/
