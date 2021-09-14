FROM debian:stable

# sure we don't get notifications we can't answer during building.
ENV    DEBIAN_FRONTEND noninteractive

WORKDIR /opt/

RUN apt-get update \
 && apt-get install -y \
      cmake \
      build-essential \
 && apt-get clean \
 && rm -rf /var/lib/apt/lists/*

COPY ./ /opt
RUN cmake . && make

FROM debian:stable-slim

WORKDIR /root/

COPY --from=0 /opt/combi ./
ENTRYPOINT ["./combi"]
