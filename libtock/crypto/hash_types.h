#pragma once

#include "../tock.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  LIBTOCK_MD5 = 0,
  LIBTOCK_SHA1 = 1,
  LIBTOCK_SHA224 = 2,
  LIBTOCK_SHA256 = 3,
  LIBTOCK_SHA384 = 4,
  LIBTOCK_SHA512 = 5,
  LIBTOCK_SHA512_224 = 6,
  LIBTOCK_SHA512_256 = 7,
} libtock_hash_algorithm_t;

#ifdef __cplusplus
}
#endif
