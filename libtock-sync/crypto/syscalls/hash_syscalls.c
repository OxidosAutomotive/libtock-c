#include "hash_syscalls.h"

returncode_t libtocksync_hash_yield_wait_for_done(void) {
  yield_waitfor_return_t ret;
  ret = yield_wait_for(HASH_DRIVER_NUMBER, HASH_DONE);

  return tock_status_to_returncode(ret.data0);
}
