#!/bin/bash
cd ../..
docker build . -t school21/miniverter:1.0 -f "src/docker_alpine/Dockerfile" && docker run --rm -it school21/miniverter:1.0