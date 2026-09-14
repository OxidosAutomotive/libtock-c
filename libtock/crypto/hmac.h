#pragma once

#include "../tock.h"
#include "hash_types.h"

#ifdef __cplusplus
extern "C" {
#endif

bool libtock_hmac_exists(void);

// Function signature for hash callback.
//
// - `arg1` (`returncode_t`): Status from computing the hash.
typedef void (*libtock_hmac_callback_done)(returncode_t);

returncode_t libtock_hmac_compute(libtock_hash_algorithm_t hash_algorithm,
                                  uint8_t* key_buffer, uint32_t key_length,
                                  uint8_t* input_buffer, uint32_t input_length,
                                  uint8_t* output_buffer, uint32_t output_length,
                                  libtock_hmac_callback_done cb);

#ifdef __cplusplus
}
#endif
