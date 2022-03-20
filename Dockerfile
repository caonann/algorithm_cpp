FROM ubuntu:20.04
RUN mv /etc/apt/sources.list /etc/apt/sources.list.bak
COPY ./.sources.list /etc/apt/sources.list

RUN apt-get clean all && apt-get update && \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y wget git curl iputils-ping net-tools vim cmake gcc g++ python3.9 && \
    ln -s /usr/bin/python3.9 /usr/bin/python && \
    echo "alias g='/app/generate.py'" >> ~/.bashrc &&\
    apt-get clean && \
    apt-get autoremove &&\
    rm -rf /var/lib/apt/lists/* &&\
    rm -rf /var/cache/apt/archives/*
    
WORKDIR /app