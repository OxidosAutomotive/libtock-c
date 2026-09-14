#include <libtock/crypto/hash_types.h>
#include <libtock/tock.h>

#ifdef __cplusplus
extern "C" {
#endif

bool libtocksync_hash_exists(void);

// Compute a hash over `input_buffer` and store the hash in `hash_buffer`.
returncode_t libtocksync_hash_compute(libtock_hash_algorithm_t hash_algorithm,
                                      uint8_t* input_buffer, uint32_t input_length,
                                      uint8_t* output_buffer, uint32_t output_length);

#ifdef __cplusplus
}
#endif
