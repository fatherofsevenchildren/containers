FROM quay.io/school21/alpine:3.16

RUN apk --no-cache --upgrade add \
    git \
    git-lfs \
    curl \
    jq \
    bash \
    build-base \
    python3 \
    valgrind \
    cppcheck \
    alpine-sdk \
    pcre-dev \
    check \
    check-dev \
    clang-extra-tools \
    gtest \
    gtest-dev

COPY . /project

WORKDIR "/project/src"
