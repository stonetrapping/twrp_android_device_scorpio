#!/bin/sh
# $1 - path to top of android build tree
# $2 path to /multirom/enc folder in installation zip

DEVICE_PATH="$1/device/xiaomi/scorpio"

RECOVERY_ROOT_PATH="${DEVICE_PATH}/recovery/root"
MROM_ENC_PATH="${DEVICE_PATH}/multirom/enc"


#recovery/root/firmware/image:
#   keymaste.b00  keymaste.b01  keymaste.b02  keymaste.b03  keymaste.b04  keymaste.b05  keymaste.b06  keymaste.mdt
mkdir -p "$2/firmware"
cp -a "${RECOVERY_ROOT_PATH}/firmware/"* "$2/firmware/"

# system/etc
mkdir -p "$2/system/etc"
cp -a "${RECOVERY_ROOT_PATH}/system/etc/"* "$2/system/etc/"

#recovery/root/vendor
#   note: libQSEEComAPI.so is fixed path dependant
mkdir -p "$2/vendor"
cp -a "${RECOVERY_ROOT_PATH}/vendor/"* "$2/vendor/"

# property service not running so it's going to fall back to default
cp -a "$2/vendor/lib64/hw/keystore.msm8996.so" "$2/vendor/lib64/hw/keystore.default.so"


# copy all libs & files
#    (we *could* "optimize this only copy libs/files not provided by the standard installer)
#    (but not all libs are built unless recovery was previously built, so copy everything we need)
cp -a "${MROM_ENC_PATH}/"* "$2/"

# linker (linker64 -> linker)
cp -a "${MROM_ENC_PATH}/linker64" "$2/linker"
