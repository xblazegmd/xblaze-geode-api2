# Xblaze's Geode API
## 3.0.0
- Update to Geode v6
- Integrate API directly into my mods (now it's not a geode mod anymore!)
- Rename `buildBodyString` to `bodyString`
- Add `requestGDServers` overload to direcly put the arguments as an `initializer_list`
- Remove helper `quickNotification` functions
    * `quickInfoNotification`, `quickWarningNotification`, `quickErrorNotification`... (and their thread safe variants)
- Make `formatResponse` return `StringMap` instead of `std::unordered_map`

## 2.1.0
- Remove deprecated functions
- Optimize `buildBodyString` and use `ZStringView` in certain functions (#2 by @Thyrocytes)
- Remove usage of `GameToolbox::doWeHaveInternet` in `doWeHaveInternet` (now exclusively checks with a web request)

## 2.0.0
- Remove Patreon badges and deprecate Patreon APIs (no one's even a member on my patreon so it's useless)
- Make `xblazeapi::BOOMLINGS` and `xblazeapi::SECRET` `std::string` instead of `std::string_view`
- Make `confirmYesNo` synchronous and deprecate async `confirmYesNo` and `confirmYesNoSync`
- Add "reverse" option in `confirmYesNo`
- Add more quick notification utils
- Small change in return type for `requestGDServers`

## 1.2.0
- Change badge fetching system to one that doesn't overwhelm my website (lol)
- Add web request utils

## 1.1.0
- Switch API endpoint to `xblaze.netlify.app`

## 1.0.1
- Fix unnecesary amount of requests to load Patreon badges

## 1.0.0
- Initial Release
