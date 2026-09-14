#include "hash_syscalls.h"

returncode_t libtocksync_hash_yield_wait_for_done(void) {
  yield_waitfor_return_t ret;
  ret = yield_wait_for(DRIVER_NUM_HASH, 0);

  return tock_status_to_returncode(ret.data0);
}
