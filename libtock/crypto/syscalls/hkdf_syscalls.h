#pragma once

#include "../../tock.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DRIVER_NUM_HKDF 0x40007

bool libtock_hkdf_driver_exists(void);

returncode_t libtock_hkdf_set_done_upcall(subscribe_upcall callback, void* opaque);

// Contains salt buffer, it is optional, according to the algorithm.
returncode_t libtock_hkdf_set_readonly_allow_salt_buffer(uint8_t* buffer, uint32_t len);
returncode_t libtock_hkdf_set_readonly_allow_ikm_buffer(uint8_t* buffer, uint32_t len);
// Contains info buffer, it is optional, according to the algorithm.
returncode_t libtock_hkdf_set_readonly_allow_info_buffer(uint8_t* buffer, uint32_t len);

returncode_t libtock_hkdf_set_readwrite_allow_prk_buffer(uint8_t* buffer, uint32_t len);
returncode_t libtock_hkdf_set_readwrite_allow_okm_buffer(uint8_t* buffer, uint32_t len);

returncode_t libtock_hkdf_command_start(uint8_t algo);

returncode_t libtocksync_hkdf_yield_wait_for_done(void);

#ifdef __cplusplus
}
#endif
