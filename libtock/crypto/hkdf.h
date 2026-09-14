#pragma once

#include "../tock.h"
#include "hash_types.h"

#ifdef __cplusplus
extern "C" {
#endif


bool libtock_hkdf_exists(void);

typedef void (*libtock_hkdf_callback_done)(returncode_t);

returncode_t libtock_hkdf_compute(libtock_hash_algorithm_t hash_algorithm,
                                  uint8_t* ikm_buffer, uint32_t ikm_length,
                                  uint8_t* salt_buffer, uint32_t salt_length,
                                  uint8_t* info_buffer, uint32_t info_length,
                                  uint8_t* prk_buffer, uint32_t prk_length,
                                  uint8_t* okm_buffer, uint32_t okm_length,
                                  libtock_hkdf_callback_done cb);

#ifdef __cplusplus
}
#endif
