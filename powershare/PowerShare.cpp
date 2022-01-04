/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "PowerShareService"

#include "PowerShare.h"
#include <hidl/HidlTransportSupport.h>
#include <fstream>

namespace vendor {
namespace lineage {
namespace powershare {
namespace V1_0 {
namespace implementation {

// Methods from ::vendor::lineage::powershare::V1_0::IPowerShare follow.

PowerShare::PowerShare() {
    mWlcService = IWirelessCharger::getService();
}

Return<bool> PowerShare::isEnabled() {
    int8_t useless = 0;
    RtxStatusInfo rtxInfoBundle;
    auto hidl_callback = [&useless, &rtxInfoBundle] (int8_t b, RtxStatusInfo rtxStatusInfo) {
      useless = b;
      rtxInfoBundle = rtxStatusInfo;
    };
    mWlcService->getRtxInformation(hidl_callback);
    return rtxInfoBundle.mode == rtxModeType::ACTIVE;
}

Return<bool> PowerShare::setEnabled(bool enable) {
    mWlcService->setRtxMode(enable);
    return isEnabled();
}

Return<uint32_t> PowerShare::getMinBattery() {
    return 10;
}

Return<uint32_t> PowerShare::setMinBattery(uint32_t) {
    return getMinBattery();
}


}  // namespace implementation
}  // namespace V1_0
}  // namespace powershare
}  // namespace lineage
}  // namespace vendor
