#include "hmac_syscalls.h"

#define TOCK_HMAC_KEY_BUF 0
#define TOCK_HMAC_INPUT_BUF 1

#define TOCK_HMAC_OUTPUT_BUF 0

#define TOCK_HMAC_COMPUTE 1

#define TOCK_HMAC_DONE_CB 0

bool libtock_hmac_driver_exists(void) {
  return driver_exists(DRIVER_NUM_HMAC);
}

returncode_t libtock_hmac_set_done_upcall(subscribe_upcall callback, void* opaque) {
  subscribe_return_t sval = subscribe(DRIVER_NUM_HMAC, TOCK_HMAC_DONE_CB, callback, opaque);
  return tock_subscribe_return_to_returncode(sval);
}

returncode_t libtock_hmac_set_readonly_allow_input_buffer(uint8_t* buffer, uint32_t len) {
  allow_ro_return_t aval = allow_readonly(DRIVER_NUM_HMAC, TOCK_HMAC_INPUT_BUF, (void*) buffer, len);
  return tock_allow_ro_return_to_returncode(aval);
}

returncode_t libtock_hmac_set_readonly_allow_key_buffer(uint8_t* buffer, uint32_t len) {
  allow_ro_return_t aval = allow_readonly(DRIVER_NUM_HMAC, TOCK_HMAC_KEY_BUF, (void*) buffer, len);
  return tock_allow_ro_return_to_returncode(aval);
}

returncode_t libtock_hmac_set_readwrite_allow_output_buffer(uint8_t* buffer, uint32_t len) {
  allow_rw_return_t aval = allow_readwrite(DRIVER_NUM_HMAC, TOCK_HMAC_OUTPUT_BUF, (void*) buffer, len);
  return tock_allow_rw_return_to_returncode(aval);
}

returncode_t libtock_hmac_command_start(uint8_t algo) {
  syscall_return_t cval = command(DRIVER_NUM_HMAC, TOCK_HMAC_COMPUTE, algo, 0);
  return tock_command_return_novalue_to_returncode(cval);
}

returncode_t libtocksync_hmac_yield_wait_for_done(void) {
  yield_waitfor_return_t ret;
  ret = yield_wait_for(DRIVER_NUM_HMAC, TOCK_HMAC_DONE_CB);

  return tock_status_to_returncode(ret.data0);
}
