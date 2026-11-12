#pragma once

#include <Geode/Result.hpp>
#include <Geode/utils/StringMap.hpp>
#include <Geode/utils/ZStringView.hpp>

#include <arc/future/Future.hpp>
#include <initializer_list>
#include <string>
#include <string_view>
 
namespace xblazeapi {
    // GD Servers
    const std::string BOOMLINGS = "https://www.boomlings.com/database/";
    const std::string SECRET = "Wmfd2893gb7";

    using ServerResponse = geode::Result<std::string, int>;

    arc::Future<ServerResponse> requestGDServers(
        std::string_view endpoint,
        std::initializer_list<std::pair<std::string, std::string>> body,
        int timeout = 10
    );

    arc::Future<ServerResponse> requestGDServers(
        std::string_view endpoint,
        std::string_view body,
        int timeout = 10
    );

    geode::utils::StringMap<std::string> formatResponse(
        std::string_view response,
        std::string sep = ":"
    );

    // General web requests
    arc::Future<bool> doWeHaveInternet(const std::string& url = "http://connectivitycheck.gstatic.com/generate_204");

    std::string bodyString(std::initializer_list<std::pair<std::string, std::string>> body);

    // Yes/No popups
    void confirmYesNo(
        geode::ZStringView title,
        geode::ZStringView msg,
        geode::Function<void()> yesCb,
        geode::Function<void()> noCb = []{},
        bool reverse = false
    );

    void confirmYesNo(
        geode::ZStringView title,
        geode::ZStringView msg,
        geode::ZStringView yesBtn,
        geode::ZStringView noBtn,
        geode::Function<void()> yesCb,
        geode::Function<void()> noCb = []{},
        bool reverse = false
    );

    // Quick notifications
    geode::Notification* quickNotification(
        geode::ZStringView msg,
        geode::NotificationIcon icon = geode::NotificationIcon::None
    );

    void quickNotificationTS(
        geode::ZStringView msg,
        geode::NotificationIcon icon = geode::NotificationIcon::None
    );

    // Zzz
    arc::Future<> sleepSecs(int s);
    arc::Future<> sleepMillis(int ms);
}
