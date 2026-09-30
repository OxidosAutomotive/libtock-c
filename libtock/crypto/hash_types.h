#pragma once

#include "../tock.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  LIBTOCK_MD5          = 0,
  LIBTOCK_SHA1         = 1,
  LIBTOCK_SHA224       = 2,
  LIBTOCK_SHA256       = 3,
  LIBTOCK_SHA384       = 4,
  LIBTOCK_SHA512       = 5,
  LIBTOCK_SHA512_224   = 6,
  LIBTOCK_SHA512_256   = 7,
  LIBTOCK_SHA3_224     = 8,
  LIBTOCK_SHA3_256     = 9,
  LIBTOCK_SHA3_384     = 10,
  LIBTOCK_SHA3_512     = 11,
  LIBTOCK_SHAKE128     = 12,
  LIBTOCK_SHAKE256     = 13,
  LIBTOCK_SM3          = 14,
} libtock_hash_algorithm_t;

#ifdef __cplusplus
}
#endif
