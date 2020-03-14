# sticker2smilebot-telegram
Automatically replaces stickers to simple smiles.

### Dependencies
* C++ compiler with C++17 support
* CMake
* Conan

### How to build
* Clone this repository
* `cmake -B build`
* `cmake --build build --target install`

### How to run
You must provide Telegram Bot API token to the `sticker2smilebot-telegram` with `--token` option. `sticker2smilebot-telegram` has other command line options but only `--token` is mandatory - other options have some reasonable defaults.
Since `libcurl` can be built without bundled certificates you need to provide them explicitly via `--ca-info` bot option.

So your command line for running `sticker2smilebot-telegram` can be like this one:
`sticker2smilebot_telegram --token ${TOKEN} --log-path ${LOG_PATH}`

I recommend to run this bot as a service(e.g. as systemd service) on a machine.
Also Docker images are available here: https://hub.docker.com/repository/docker/zamazan4ik/sticker2smilebot-telegram
