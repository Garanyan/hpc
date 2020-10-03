FROM ubuntu:20.04
ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update && apt-get install -y cmake gcc g++ build-essential cmake automake

COPY main.cpp /root/main.cpp
COPY matrix.cpp /root/matrix.cpp
COPY matrix.hpp /root/matrix.hpp
COPY CMakeLists.txt /root/CMakeLists.txt

RUN mkdir -p /root/build && cd /root/build && cmake -DCMAKE_BUILD_TYPE=Release .. && \
    cmake --build /root/build --target Matrix -- -j 3

RUN cp /root/build/Matrix /root/Matrix_release && rm -rf /root/build/*

RUN cd /root/build && cmake -DCMAKE_BUILD_TYPE=Debug  .. && \
    cmake --build /root/build --target Matrix -- -j 3

RUN cp /root/build/Matrix /root/Matrix_debug

RUN echo '#!/bin/bash \n\n\
set -ex\n\
/root/Matrix_release \n\
/root/Matrix_debug \n' >> /root/start.sh && \
     chmod +x /root/start.sh

ENTRYPOINT ["/root/start.sh"]

