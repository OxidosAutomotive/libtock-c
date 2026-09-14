#pragma once

#include "../../tock.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DRIVER_NUM_HASH 0x40005

bool libtock_hash_driver_exists(void);

returncode_t libtock_hash_set_done_upcall(subscribe_upcall callback, void* opaque);

returncode_t libtock_hash_set_readonly_allow_input_buffer(uint8_t* buffer, uint32_t len);

returncode_t libtock_hash_set_readwrite_allow_output_buffer(uint8_t* buffer, uint32_t len);

returncode_t libtock_hash_command_start(uint8_t algo);

returncode_t libtocksync_hash_yield_wait_for_done(void);

#ifdef __cplusplus
}
#endif
