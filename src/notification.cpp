#include <XblazeAPI.hpp>

#include <Geode/ui/Notification.hpp>

using namespace geode::prelude;

namespace xblazeapi {
    geode::Notification* quickNotification(
        geode::ZStringView msg,
        geode::NotificationIcon icon
    ) {
        auto ret = Notification::create(msg, icon);
        ret->show();
        return ret;
    }

    void quickNotificationTS(
        geode::ZStringView msg,
        geode::NotificationIcon icon
    ) {
        geode::queueInMainThread([msg, icon] {
            quickNotification(msg, icon);
        });
    }
}
