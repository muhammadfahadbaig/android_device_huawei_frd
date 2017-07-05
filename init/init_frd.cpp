/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <fstream>
#include <string>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_hi3650.h"

void init_target_properties()
{
    std::ifstream fin;
    std::string buf;

    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET) {
	return;
    }

    fin.open("/sys/firmware/devicetree/base/hisi,product_name");
    while (getline(fin, buf))
        if ((buf.find("FRD-L02") != std::string::npos) || (buf.find("FRD-L04") != std::string::npos) || (buf.find("FRD-L09") != std::string::npos) || (buf.find("FRD-L14") != std::string::npos) || (buf.find("FRD-L19") != std::string::npos) || (buf.find("FRD-AL00") != std::string::npos) || (buf.find("FRD-AL10") != std::string::npos))
            break;
    fin.close();

    if (buf.find("FRD-L02") != std::string::npos) {
        property_set("ro.product.model", "FRD-L02");
        property_set("ro.config.client_number", "1");
        property_set("ro.config.modem_number", "1");
        property_set("ro.config.hw_dsda", "false");
        property_set("persist.dsds.enabled", "false");
        property_set("persist.radio.nv_match_by_card", "2");
        property_set("rild.libargs", "-m modem0");
        property_set("rild.libpath", "/vendor/lib64/libbalong-ril.so");
        property_set("persist.radio.modem.cap", "8999D");
        property_set("ro.telephony.default_network", "9");
        property_set("ro.config.full_network_support", "false");
        property_set("ro.config.default_commril_mode", "ULG_MODE");
        property_set("ro.build.description", "FRD-L02-user 7.0 HUAWEIFRD-L02 C675B310 release-keys");
        property_set("ro.build.fingerprint", "HONOR/FRD-L02/HWFRD:7.0/HUAWEIFRD-L02/C675B310:user/release-keys");
    }
    else if (buf.find("FRD-L04") != std::string::npos) {
        property_set("ro.product.model", "FRD-L04");
        property_set("ro.config.client_number", "1");
        property_set("ro.config.modem_number", "1");
        property_set("ro.config.hw_dsda", "false");
        property_set("persist.dsds.enabled", "false");
        property_set("persist.radio.nv_match_by_card", "2");
        property_set("rild.libargs", "-m modem0");
        property_set("rild.libpath", "/vendor/lib64/libbalong-ril.so");
        property_set("persist.radio.modem.cap", "8999D");
        property_set("ro.telephony.default_network", "9");
        property_set("ro.config.full_network_support", "false");
        property_set("ro.config.default_commril_mode", "ULG_MODE");
        property_set("ro.build.description", "FRD-L04-user 7.0 HUAWEIFRD-L04 C567B360 release-keys");
        property_set("ro.build.fingerprint", "HONOR/FRD-L04/HWFRD:7.0/HUAWEIFRD-L04/C567B360:user/release-keys");	
    }
    else if (buf.find("FRD-L09") != std::string::npos) {
        property_set("ro.product.model", "FRD-L09");
        property_set("ro.config.client_number", "5");
        property_set("ro.config.modem_number", "2");
        property_set("ro.config.hw_dsda", "true");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsda");
        property_set("ro.config.hw_device_mode", "ulg_mode");
        property_set("rild.libargs", "-m modem0");
        property_set("rild.libargs1", "-m modem1");
        property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("rild.libpath", "/vendor/lib64/libbalong-ril.so");
        property_set("rild.libpath1", "/vendor/lib64/libbalong-ril-1.so");
        property_set("persist.radio.modem.cap", "8999D");
        property_set("ro.telephony.default_network", "9");
        property_set("ro.config.full_network_support", "false");
        property_set("ro.config.default_commril_mode", "ULG_MODE");
        property_set("ro.build.description", "FRD-L09-user 7.0 HUAWEIFRD-L09 C432B380 release-keys");
        property_set("ro.build.fingerprint", "HONOR/FRD-L09/HWFRD:7.0/HUAWEIFRD-L09/C432B380:user/release-keys");
    }
    else if (buf.find("FRD-L14") != std::string::npos) {
        property_set("ro.product.model", "FRD-L14");
        property_set("ro.config.client_number", "1");
        property_set("ro.config.modem_number", "1");
        property_set("ro.config.hw_dsda", "false");
        property_set("persist.dsds.enabled", "false");
        property_set("persist.radio.nv_match_by_card", "2");
        property_set("rild.libargs", "-m modem0");
        property_set("rild.libpath", "/vendor/lib64/libbalong-ril.so");
        property_set("persist.radio.modem.cap", "8999D");
        property_set("ro.telephony.default_network", "9");
        property_set("ro.config.full_network_support", "false");
        property_set("ro.config.default_commril_mode", "ULG_MODE");
        property_set("ro.build.description", "FRD-L14-user 7.0 HUAWEIFRD-L14 C567B360 release-keys");
        property_set("ro.build.fingerprint", "HONOR/FRD-L14/HWFRD:7.0/HUAWEIFRD-L14/C567B360:user/release-keys");
    }
    else if (buf.find("FRD-L19") != std::string::npos) {
        property_set("ro.product.model", "FRD-L19");
        property_set("ro.config.client_number", "5");
        property_set("ro.config.modem_number", "2");
        property_set("ro.config.hw_dsda", "true");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsda");
        property_set("ro.config.hw_device_mode", "ulg_mode");
        property_set("rild.libargs", "-m modem0");
        property_set("rild.libargs1", "-m modem1");
        property_set("ro.config.dsds_mode", "umts_gsm");
        property_set("rild.libpath", "/vendor/lib64/libbalong-ril.so");
        property_set("rild.libpath1", "/vendor/lib64/libbalong-ril-1.so");
        property_set("persist.radio.modem.cap", "8999D");
        property_set("ro.telephony.default_network", "9");
        property_set("ro.config.full_network_support", "false");
        property_set("ro.config.default_commril_mode", "ULG_MODE");
        property_set("ro.build.description", "FRD-L19-user 7.0 HUAWEIFRD-L19 C432B380 release-keys");
        property_set("ro.build.fingerprint", "HONOR/FRD-L19/HWFRD:7.0/HUAWEIFRD-L19/C432B380:user/release-keys");
    }
    else if (buf.find("FRD-AL00") != std::string::npos) {
        property_set("ro.product.model", "FRD-AL00");
        property_set("ro.radio.vsim_support", "true");
        property_set("ro.config.client_number", "5");
        property_set("ro.config.modem_number", "4");
        property_set("ro.config.hw_dsda", "true");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsda");
        property_set("ro.config.hw_device_mode", "clg_mode");
        property_set("rild.libargs", "-d /dev/viacomm_cmux");
        property_set("rild.libargs1", "-m modem0");
        property_set("rild.libargs2", "-m modem1");
        property_set("rild.libargs3", "-m modem2");
        property_set("ro.config.dsds_mode", "cdma_gsm");
        property_set("ro.config.default_commril_mode", "CLG_MODE");
        property_set("ro.telephony.default_network", "8");
        property_set("ro.config.full_network_support", "true");
        property_set("persist.radio.modem.cap", "899BD");
        property_set("rild.libpath", "/vendor/lib64/libvia-ril.so");
        property_set("rild.libpath1", "/vendor/lib64/libbalong-ril.so");
        property_set("rild.libpath2", "/vendor/lib64/libbalong-ril-1.so");
        property_set("rild.libpath3", "/vendor/lib64/libbalong-ril-2.so");
        property_set("ro.build.description", "FRD-AL00-user 7.0 HUAWEIFRD-AL00 C00B666 release-keys");
        property_set("ro.build.fingerprint", "honor/FRD-AL00/HWFRD:7.0/HUAWEIFRD-AL00/C00B666:user/release-keys");
    }
    else if (buf.find("FRD-AL10") != std::string::npos) {
        property_set("ro.product.model", "FRD-AL10");
        property_set("ro.radio.vsim_support", "true");
        property_set("ro.config.client_number", "5");
        property_set("ro.config.modem_number", "4");
        property_set("ro.config.hw_dsda", "true");
        property_set("persist.dsds.enabled", "true");
        property_set("persist.radio.multisim.config", "dsda");
        property_set("ro.config.hw_device_mode", "clg_mode");
        property_set("rild.libargs", "-d /dev/viacomm_cmux");
        property_set("rild.libargs1", "-m modem0");
        property_set("rild.libargs2", "-m modem1");
        property_set("rild.libargs3", "-m modem2");
        property_set("ro.config.dsds_mode", "cdma_gsm");
        property_set("ro.config.default_commril_mode", "CLG_MODE");
        property_set("ro.telephony.default_network", "8");
        property_set("ro.config.full_network_support", "true");
        property_set("persist.radio.modem.cap", "899BD");
        property_set("rild.libpath", "/vendor/lib64/libvia-ril.so");
        property_set("rild.libpath1", "/vendor/lib64/libbalong-ril.so");
        property_set("rild.libpath2", "/vendor/lib64/libbalong-ril-1.so");
        property_set("rild.libpath3", "/vendor/lib64/libbalong-ril-2.so");
        property_set("ro.build.description", "FRD-AL10-user 7.0 HUAWEIFRD-AL10 C00B387 release-keys");
        property_set("ro.build.fingerprint", "honor/FRD-AL10/HWFRD:7.0/HUAWEIFRD-AL10/C00B387:user/release-keys");
    }
    else {
	property_set("ro.product.model", "UNKNOWN");
    }
}
