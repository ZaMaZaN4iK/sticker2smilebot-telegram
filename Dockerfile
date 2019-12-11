FROM fedora:latest

LABEL maintainer="Alexander Zaitsev <zamazan4ik@tut.by>"

ARG STICKER2SMILE_VERSION=1.0.0

ARG STICKER2SMILE_SOURCE_URL=https://github.com/ZaMaZaN4iK/sticker2smilebot-telegram/archive/v${STICKER2SMILE_VERSION}.zip

RUN dnf install -y perl autoconf automake libtool wget unzip clang cmake make python3-pip \
    && pip install conan

RUN conan remote add zamazan4ik https://api.bintray.com/conan/zamazan4ik/conan

WORKDIR /npaperbot_telegram

RUN wget https://github.com/ZaMaZaN4iK/sticker2smilebot-telegram/archive/v${STICKER2SMILE_VERSION}.zip && unzip v${STICKER2SMILE_VERSION}.zip

WORKDIR sticker2smilebot-telegram-${STICKER2SMILE_VERSION}

RUN mkdir build

WORKDIR build

RUN CC=clang CXX=clang++ conan install .. --build=missing && CC=clang CXX=clang++ cmake .. -DCMAKE_BUILD_TYPE=Release && make

WORKDIR bin

RUN chmod +x ./sticker2smilebot_telegram
RUN mkdir logs

ENTRYPOINT ["/sticker2smilebot_telegram/sticker2smilebot-telegram-${STICKER2SMILE_VERSION}/build/bin/sticker2smilebot_telegram"]

