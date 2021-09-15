FROM debian:10
# sure we don't get notifications we can't answer during building.
ENV    DEBIAN_FRONTEND noninteractive
WORKDIR /opt/
RUN apt-get update
RUN apt-get install -y \
      cmake \
      build-essential
COPY ./ /opt
RUN cmake . && make

FROM gcr.io/distroless/base-debian10
WORKDIR /root/
COPY --from=0 /opt/combi ./
ENTRYPOINT ["./combi"]
