#pragma once

#include <libtock/crypto/syscalls/hkdf_syscalls.h>
#include <libtock/tock.h>

#ifdef __cplusplus
extern "C" {
#endif

returncode_t libtocksync_hkdf_yield_wait_for_done(void);

#ifdef __cplusplus
}
#endif
