FROM ubuntu:bionic
RUN apt-get update && \
	apt-get install -y build-essential git cmake autoconf libtool pkg-config libboost-all-dev libcrypto++ wget
RUN wget https://raw.githubusercontent.com/libbitcoin/libbitcoin/version3/install.sh
RUN chmod +x install.sh
RUN ./install.sh --prefix=/usr/local/bin --build-boost --disable-shared
RUN mkdir -p /src
WORKDIR /src
COPY . .
WORKDIR /src/build
RUN cmake ..
