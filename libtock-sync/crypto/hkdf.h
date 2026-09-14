#include <libtock/crypto/hash_types.h>
#include <libtock/tock.h>

#include "syscalls/hkdf_syscalls.h"

#ifdef __cplusplus
extern "C" {
#endif

bool libtocksync_hkdf_exists(void);

returncode_t libtocksync_hkdf_compute(libtock_hash_algorithm_t hash_algorithm,
                                      uint8_t* ikm_buffer, uint32_t ikm_length,
                                      uint8_t* salt_buffer, uint32_t salt_length,
                                      uint8_t* info_buffer, uint32_t info_length,
                                      uint8_t* prk_buffer, uint32_t prk_length,
                                      uint8_t* okm_buffer, uint32_t okm_length);

#ifdef __cplusplus
}
#endif
