#include <CLI/CLI.hpp>

#include <tgbot/net/CurlHttpClient.h>
#include <tgbot/tgbot.h>

#include <spdlog/sinks/daily_file_sink.h>

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    CLI::App app("Sticker2Smile Telegram Bot");

    std::string token;
    app.add_option("--token", token, "Telegram Bot API token")->required();

    std::string LogsPath = "logs/log.txt";
    app.add_option("--log-path", LogsPath, "Path to log folder");

    CLI11_PARSE(app, argc, argv);

    auto daily_logger = spdlog::daily_logger_mt("daily_logger", LogsPath, 0, 0);
    daily_logger->flush_on(spdlog::level::info);

    TgBot::CurlHttpClient httpClient;

    TgBot::Bot bot(token, httpClient);
    bot.getEvents().onAnyMessage([&bot, daily_logger](TgBot::Message::Ptr message)
    {
        if (message->sticker != nullptr)
        {
            bot.getApi().deleteMessage(message->chat->id, message->messageId);
            bot.getApi().sendMessage(message->chat->id, message->sticker->emoji);
            daily_logger->info("Replace completed");
        }
    });

    bot.getEvents().onCommand("help", [&bot, daily_logger](TgBot::Message::Ptr message)
    {
        daily_logger->info("Help command requested");

        bot.getApi().sendMessage(message->chat->id, "The bot just automatically replaces all stickers in chat "
                                                    "with corresponding smiles. It can be helpful for avoiding "
                                                    "sticker disaster in huge chats.");
    });

    try
    {
        std::cout << "Bot username: " << bot.getApi().getMe()->username << std::endl;
        TgBot::TgLongPoll longPoll(bot, 100, 10);
        while (true)
        {
            std::cout << "Long poll started\n";
            longPoll.start();
        }
    }
    catch (const TgBot::TgException& e)
    {
        std::cout << "Telegram bot exception: " << e.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}