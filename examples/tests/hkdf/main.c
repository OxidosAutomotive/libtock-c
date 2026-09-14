#include <stdio.h>

#include <libtock-sync/crypto/hkdf.h>
#include <libtock/interface/console.h>

#define IKM_LEN 22
#define SALT_LEN 13
#define INFO_LEN 10
#define PRK_LEN 32
#define OKM_BUFFER 42

uint8_t ikm_buf[IKM_LEN] = {0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b};
uint8_t salt_buf[SALT_LEN] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c};
uint8_t info_buf[INFO_LEN] = {0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9};
uint8_t prk_buf[PRK_LEN];
uint8_t okm_buf[OKM_BUFFER];
uint8_t correct_buf[OKM_BUFFER] = {0x3c, 0xb2, 0x5f, 0x25, 0xfa, 0xac, 0xd5, 0x7a, 0x90, 0x43, 0x4f, 0x64, 0xd0, 0x36, 0x2f, 0x2a, 0x2d, 0x2d, 0x0a, 0x90, 0xcf, 0x1a, 0x5a, 0x4c, 0x5d, 0xb0, 0x2d, 0x56, 0xec, 0xc4, 0xc5, 0xbf, 0x34, 0x00, 0x72, 0x08, 0xd5, 0xb8, 0x87, 0x18, 0x58, 0x65};

int main(void) {
  returncode_t ret;
  printf("[TEST] HKDF\r\n");

  if (!libtocksync_hkdf_exists()) {
    printf("No hkdf driver.\n");
    return -2;
  }

  ret = libtocksync_hkdf_compute(LIBTOCK_SHA256, ikm_buf, sizeof(ikm_buf) / sizeof(uint8_t),
                                   salt_buf, sizeof(salt_buf) / sizeof(uint8_t),
                                   info_buf, sizeof(info_buf) / sizeof(uint8_t),
                                   prk_buf, sizeof(prk_buf) / sizeof(uint8_t),
                                   okm_buf, sizeof(okm_buf) / sizeof(uint8_t));
  if (ret != RETURNCODE_SUCCESS) {
    printf("Unable to compute HKDF.\n");
    return -1;
  }
  printf("HKDF computation finished.\n");

  printf("Correct: ");
  for (int i = 0; i < OKM_BUFFER; i++) {
    printf("%02x", correct_buf[i]);
  }
  printf("\n");

  bool match = true;
  printf("Got    : ");
  for (int i = 0; i < OKM_BUFFER; i++) {
    if (correct_buf[i] != dest_buf[i]) {
      match = false;
    }

    printf("%02x", dest_buf[i]);
  }
  printf("\n");

  if (match) {
    printf("HKDF computation correct.\n");
  } else {
    printf("ERROR! HKDF computation incorrect.\n");
  }

  return 0;
}
