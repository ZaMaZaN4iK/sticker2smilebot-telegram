# sticker2smilebot-telegram
Automatically replaces stickers to simple smiles.

### Dependencies
* C++ compiler with C++17 support
* CMake + make/ninja/whatever else
* Conan

### How to build
* Clone this repository
* mkdir build && cd build
* `tgbot-cpp` you can get here: https://github.com/ZaMaZaN4iK/conan-tgbot-cpp. This package is available here: https://bintray.com/zamazan4ik/conan/tgbot-cpp%3Azamazan4ik
* `conan install ..`
* `cmake ..`
* `make` (if you use make)

### How to run
You must provide Telegram Bot API token to the `sticker2smilebot_telegram` with `--token` option. `sticker2smilebot_telegram` has other command line options but only `--token` is mandatory - other options have some reasonable defaults.

So your command line for running `sticker2smilebot_telegram` can be like this one:
`npaperbot-telegram --token ${TOKEN} --log-path ${LOG_PATH}`

I recommend to run this bot as a service(e.g. as systemd service) on a machine or as a Docker container (Dockerfile is also provided).
