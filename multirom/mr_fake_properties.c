#include <stdlib.h>

// Additional properties needed for decryption support
// which are provided by fake_properties.c since the property
// service isnt running during multirom

const char *mr_fake_properties[][2] =
{
    //{property, value}
    { "sys.keymaster.loaded", "true" },               // used by keystore.msm8996.so / keystore.default.so
    { "ro.boot.bootdevice", "624000.ufshc" },         // used by libcryptfs_hw.so
    { "ro.crypto.state", "encrypted" },               // used by libcryptfs.so
    { NULL, NULL}
};
