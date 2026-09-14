#include "hkdf_syscalls.h"

#define TOCK_HKDF_SALT_BUF 0
#define TOCK_HKDF_IKM_BUF 1
#define TOCK_HKDF_INFO_BUF 2

#define TOCK_HKDF_PRK_BUF 0
#define TOCK_HKDF_OKM_BUF 1

#define TOCK_HKDF_COMPUTE 1

#define TOCK_HKDF_DONE_CB 0

bool libtock_hkdf_driver_exists(void) {
  return driver_exists(DRIVER_NUM_HKDF);
}

returncode_t libtock_hkdf_set_done_upcall(subscribe_upcall callback, void* opaque) {
  subscribe_return_t sval = subscribe(DRIVER_NUM_HKDF, TOCK_HKDF_DONE_CB, callback, opaque);
  return tock_subscribe_return_to_returncode(sval);
}

returncode_t libtock_hkdf_set_readonly_allow_ikm_buffer(uint8_t *buffer, uint32_t len) {
    allow_ro_return_t aval = allow_readonly(DRIVER_NUM_HKDF, TOCK_HKDF_IKM_BUF, (void*) buffer, len);
    return tock_allow_ro_return_to_returncode(aval);
}

returncode_t libtock_hkdf_set_readonly_allow_salt_buffer(uint8_t *buffer, uint32_t len) {
    allow_ro_return_t aval = allow_readonly(DRIVER_NUM_HKDF, TOCK_HKDF_SALT_BUF, (void*) buffer, len);
    return tock_allow_ro_return_to_returncode(aval);
}

returncode_t libtock_hkdf_set_readonly_allow_info_buffer(uint8_t *buffer, uint32_t len) {
    allow_ro_return_t aval = allow_readonly(DRIVER_NUM_HKDF, TOCK_HKDF_INFO_BUF, (void*) buffer, len);
    return tock_allow_ro_return_to_returncode(aval);
}

returncode_t libtock_hkdf_set_readwrite_allow_prk_buffer(uint8_t* buffer, uint32_t len) {
  allow_rw_return_t aval = allow_readwrite(DRIVER_NUM_HKDF, TOCK_HKDF_PRK_BUF, (void*) buffer, len);
  return tock_allow_rw_return_to_returncode(aval);
}

returncode_t libtock_hkdf_set_readwrite_allow_okm_buffer(uint8_t* buffer, uint32_t len) {
  allow_rw_return_t aval = allow_readwrite(DRIVER_NUM_HKDF, TOCK_HKDF_OKM_BUF, (void*) buffer, len);
  return tock_allow_rw_return_to_returncode(aval);
}

returncode_t libtock_hkdf_command_start(uint8_t algo) {
  syscall_return_t cval = command(DRIVER_NUM_HKDF, TOCK_HKDF_COMPUTE, algo, 0);
  return tock_command_return_novalue_to_returncode(cval);
}

returncode_t libtocksync_hkdf_yield_wait_for_done(void) {
  yield_waitfor_return_t ret;
  ret = yield_wait_for(DRIVER_NUM_HKDF, TOCK_HKDF_DONE_CB);

  return tock_status_to_returncode(ret.data0);
}
