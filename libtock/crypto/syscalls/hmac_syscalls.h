#pragma once

#include "../../tock.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DRIVER_NUM_HMAC 0x40003

bool libtock_hmac_driver_exists(void);

returncode_t libtock_hmac_set_done_upcall(subscribe_upcall callback, void* opaque);

returncode_t libtock_hmac_set_readonly_allow_key_buffer(uint8_t* buffer, uint32_t len);

returncode_t libtock_hmac_set_readonly_allow_input_buffer(uint8_t* buffer, uint32_t len);

returncode_t libtock_hmac_set_readwrite_allow_output_buffer(uint8_t* buffer, uint32_t len);

returncode_t libtock_hmac_command_start(uint8_t algo);

#ifdef __cplusplus
}
#endif
