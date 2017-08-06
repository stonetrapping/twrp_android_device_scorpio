#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
    // FrameBuffers
    "/sys/class/graphics/fb0",

    // Storage devices
    "/sys/dev/block*",
    "/sys/module/ufshcd",
    "/sys/block/sda",
    "/sys/block/sde",
    "/sys/block/sdf",

    // Internal storage
    "/dev/block/bootdevice/by-name/*",
    "/sys/devices/soc/624000.ufshc",

    "/sys/devices/soc/624000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda14", // cache
    "/sys/devices/soc/624000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda12", // persist
    "/sys/devices/soc/624000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda1",  // ssd
    "/sys/devices/soc/624000.ufshc/host0/target0:0:0/0:0:0:0/block/sda/sda15", // userdata

    "/sys/devices/soc/624000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde36", // boot
    "/sys/devices/soc/624000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde17", // keymaster
    "/sys/devices/soc/624000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde18", // keymasterbak
    "/sys/devices/soc/624000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde35", // modem
    "/sys/devices/soc/624000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde39", // system
    "/sys/devices/soc/624000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde11", // rpm
    "/sys/devices/soc/624000.ufshc/host0/target0:0:0/0:0:0:4/block/sde/sde12", // rpmbak

    "/sys/devices/soc/624000.ufshc/host0/target0:0:0/0:0:0:5/block/sde/sdf3", // modemst1
    "/sys/devices/soc/624000.ufshc/host0/target0:0:0/0:0:0:5/block/sde/sdf5", // modemst2

    // Devices
    "/sys/bus*",
    "/sys/bus/mmc",
    "/sys/bus/mmc/drivers/mmcblk",
    "/sys/devices*",
    "/sys/devices/virtual/mem/null",
    "/sys/devices/virtual/misc/fuse",

    // Inputs
    "/sys/class/input/event*",
    "/sys/class/input/input*",
    "/sys/class/misc/uinput",
    "/sys/class/tty/ptmx",
    "/sys/devices/soc/soc:gpio_keys/input*",
    "/sys/devices/virtual/input*",
    "/sys/devices/virtual/misc/uinput",
    "/sys/devices/soc/75ba000.i2c/i2c-12/12-004a/input",

    // ADB
    "/sys/devices/virtual/tty/ptmx",
    "/sys/bus/usb",
    "/sys/bus/usb-serial",
    "/sys/class/android_usb/android0/f_adb",
    "/sys/class/misc/android_adb",
    "/sys/devices/virtual/misc/mtp_usb",

    // USB
    "/sys/bus/usb",
    "/sys/bus/platform/drivers/xhci-hcd*",
    "/sys/devices/soc/6a00000.ssusb/6a00000.dwc3",

    // Encryption
    "/sys/devices/virtual/icesdcc/icesdcc",
    "/sys/devices/virtual/misc/device-mapper",
    "/sys/devices/virtual/misc/ion",
    "/sys/devices/virtual/qseecom/qseecom",

    // Logging
    "/sys/devices/virtual/pmsg/pmsg0",
    "/sys/devices/virtual/mem/kmsg",

    NULL
};
