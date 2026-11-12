#pragma once

#include <Geode/Result.hpp>
#include <Geode/utils/StringMap.hpp>

#include <arc/future/Future.hpp>
#include <initializer_list>
#include <string>
#include <string_view>
 
namespace xblazeapi {
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

    arc::Future<bool> doWeHaveInternet(const std::string& url = "http://connectivitycheck.gstatic.com/generate_204");
}
