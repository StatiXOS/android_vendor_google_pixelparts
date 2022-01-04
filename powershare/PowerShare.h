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

#ifndef VENDOR_LINEAGE_POWERSHARE_V1_0_POWERSHARE_H
#define VENDOR_LINEAGE_POWERSHARE_V1_0_POWERSHARE_H

#include <vendor/google/wireless_charger/1.2/IWirelessCharger.h>
#include <vendor/google/wireless_charger/1.2/types.h>
#include <vendor/lineage/powershare/1.0/IPowerShare.h>

namespace vendor {
namespace lineage {
namespace powershare {
namespace V1_0 {
namespace implementation {

using ::android::sp;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::vendor::google::wireless_charger::V1_2::IWirelessCharger;
using google::wireless_charger::V1_2::RtxStatusInfo;
using google::wireless_charger::V1_2::rtxModeType;

class PowerShare : public IPowerShare {
  public:
    PowerShare();
    Return<bool> isEnabled() override;
    Return<bool> setEnabled(bool enable) override;
    Return<uint32_t> getMinBattery() override;
    Return<uint32_t> setMinBattery(uint32_t minBattery) override;

  private:
    sp<IWirelessCharger> mWlcService;
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace powershare
}  // namespace lineage
}  // namespace vendor

#endif  // VENDOR_LINEAGE_POWERSHARE_V1_0_POWERSHARE_H
