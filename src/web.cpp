#include <XblazeAPI.hpp>

#include <Geode/utils/web.hpp>

using namespace geode::prelude;

namespace xblazeapi {
    arc::Future<bool> doWeHaveInternet(const std::string& url) {
        auto check = co_await web::WebRequest()
            .userAgent("GeometryDash/2.2091")
            .timeout(std::chrono::seconds(10))
            .get(url);
        co_return check.ok();
    }
}
