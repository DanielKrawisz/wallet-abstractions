FROM ubuntu:bionic
RUN apt-get update && \
	apt-get install -y build-essential git cmake autoconf libtool pkg-config
RUN mkdir -p /src
WORKDIR /src
COPY . .
WORKDIR /src/build
RUN cmake ..
