FROM ubuntu:20.04

RUN apt update && \
    apt-get update && \
    apt-get upgrade && \
    apt-get  -y install \
    gcc \
    g++ \
    bash \
    valgrind \
    check \
    make \
    libgtest-dev

COPY . /project

WORKDIR "/project/src"
