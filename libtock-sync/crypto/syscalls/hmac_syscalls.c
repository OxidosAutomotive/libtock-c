#include "hmac_syscalls.h"

returncode_t libtocksync_hmac_yield_wait_for_done(void) {
  yield_waitfor_return_t ret;
  ret = yield_wait_for(HMAC_DRIVER_NUMBER, HMAC_DONE);

  return tock_status_to_returncode(ret.data0);
}
