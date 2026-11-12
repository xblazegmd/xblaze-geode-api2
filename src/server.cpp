#include <XblazeAPI.hpp>

#include <Geode/Geode.hpp>
#include <Geode/utils/general.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/utils/string.hpp>
#include <Geode/utils/StringMap.hpp>

#include <arc/prelude.hpp>
#include <fmt/compile.h>

using namespace geode::prelude;

namespace xblazeapi {
    arc::Future<ServerResponse> requestGDServers(
        std::string_view endpoint,
        std::initializer_list<std::pair<std::string, std::string>> body,
        int timeout
    ) {
        fmt::memory_buffer buf;
        for (const auto& [k, v] : body) {
            fmt::format_to(std::back_inserter(buf), FMT_COMPILE("{}={}&"), k, v);
        }
        buf.resize(buf.size() - 1);
        return requestGDServers(endpoint, {buf.data(), buf.size()}, timeout);
    }

    arc::Future<ServerResponse> requestGDServers(
        std::string_view endpoint,
        std::string_view body,
        int timeout
    ) {
        auto req = web::WebRequest()
            .userAgent("")
            .bodyString(body)
            .timeout(std::chrono::seconds(10)); // TODO: Use asp::time instead

        auto res = co_await req.post(fmt::format("{}{}", BOOMLINGS, endpoint));
        if (!res.ok()) {
            co_return Err(res.code());
        }

        auto str = res.string();
        if (str.isErr()) {
            co_return Err(0);
        }

        auto ret = std::move(str).unwrap();
        auto num = utils::numFromString<int>(ret);
        if (num.isOk() && num.unwrap() < 0) {
            co_return Err(num.unwrap());
        }

        co_return Ok(ret);
    }

    StringMap<std::string> formatResponse(
        std::string_view response,
        std::string sep
    ) {
        auto pieces = string::split(response, sep);
        StringMap<std::string> ret;
        ret.reserve(pieces.size() / 2);
        for (size_t i = 0; i < pieces.size(); i += 2) {
            ret.emplace(pieces[i], pieces[i+1]);
        }
        return ret;
    }
}
