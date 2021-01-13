#ifndef __RISCV32_REG_H__
#define __RISCV32_REG_H__

#include "common.h"

#define PC_START (0x80000000u + IMAGE_START)

typedef struct {
  struct {
    rtlreg_t _32;
  } gpr[32];

  vaddr_t pc;

  union {
    struct {
      uint32_t ppn       :22;
      uint32_t asid      : 9;
      uint32_t mode      : 1;
    };
    uint32_t val;
  }satp;

  union {
    uint32_t val;
  }sepc;

  union{
    struct {
      uint32_t      : 1;
      uint32_t SIE  : 1;
      uint32_t      : 2;
      uint32_t UPIE : 1;
      uint32_t SPIE : 1;
      uint32_t      : 2;
      uint32_t SPP  : 1;
      uint32_t      : 4;
      uint32_t FS   : 2;
      uint32_t XS   : 2;
      uint32_t      : 1;
      uint32_t SUM  : 1;
      uint32_t MXR  : 1;
      uint32_t      :11;
      uint32_t SD   : 1;
    };
    uint32_t val;
  } sstatus;

  union {
    uint32_t val;
  }scause;

  union {
    uint32_t val;
  }stvec;

  bool INTR;

} CPU_state;

static inline int check_reg_index(int index) {
  assert(index >= 0 && index < 32);
  return index;
}

#define reg_l(index) (cpu.gpr[check_reg_index(index)]._32)

static inline const char* reg_name(int index, int width) {
  extern const char* regsl[];
  assert(index >= 0 && index < 32);
  return regsl[index];
}

#endif
