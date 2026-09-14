#pragma once

#include "../tock.h"
#include "hash_types.h"

#ifdef __cplusplus
extern "C" {
#endif

bool libtock_hash_exists(void);

// Function signature for hash callback.
//
// - `arg1` (`returncode_t`): Status from computing the hash.
typedef void (*libtock_hash_callback_done)(returncode_t);


returncode_t libtock_hash_compute(libtock_hash_algorithm_t hash_type,
                                  uint8_t* input_buffer, uint32_t input_length,
                                  uint8_t* output_buffer, uint32_t output_length,
                                  libtock_hash_callback_done cb);

#ifdef __cplusplus
}
#endif
