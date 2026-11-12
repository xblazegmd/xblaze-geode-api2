#include <XblazeAPI.hpp>

namespace xblazeapi {
    void confirmYesNo(
        geode::ZStringView title,
        geode::ZStringView msg,
        geode::Function<void()> yesCb,
        geode::Function<void()> noCb,
        bool reverse
    ) {
        confirmYesNo(title, msg, "Yes", "No", std::move(yesCb), std::move(noCb), reverse);
    }

    void confirmYesNo(
        geode::ZStringView title,
        geode::ZStringView msg,
        geode::ZStringView yesBtn,
        geode::ZStringView noBtn,
        geode::Function<void()> yesCb,
        geode::Function<void()> noCb,
        bool reverse
    ) {
        auto btn1 = reverse ? yesBtn : noBtn;
        auto btn2 = reverse ? noBtn : yesBtn;
        geode::createQuickPopup(
            title, msg, btn1, btn2,
            [yesCb = std::move(yesCb), noCb = std::move(noCb), reverse](auto, bool btn2) mutable {
                bool yes = reverse ? !btn2 : btn2;
                if (yes) {
                    yesCb();
                } else {
                    noCb();
                }
            }
        );
    }
}
