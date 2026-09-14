#pragma once

#include <libtock/crypto/syscalls/hash_syscalls.h>
#include <libtock/tock.h>

#ifdef __cplusplus
extern "C" {
#endif

returncode_t libtocksync_hash_yield_wait_for_done(void);

#ifdef __cplusplus
}
#endif
