#pragma once

// Each family's *_device.h only checks macros -- no CMSIS include, no
// classes -- so including all 22 unconditionally here is cheap and safe.
// Whichever one matches your #define'd device defines its SIMPLESTM32_<FAM>
// macro; the chain below then only pulls in that one family's actual
// implementation.
#include "c0/simplestm32c0_device.h"
#include "f0/simplestm32f0_device.h"
#include "f1/simplestm32f1_device.h"
#include "f2/simplestm32f2_device.h"
#include "f3/simplestm32f3_device.h"
#include "f4/simplestm32f4_device.h"
#include "f7/simplestm32f7_device.h"
#include "g0/simplestm32g0_device.h"
#include "g4/simplestm32g4_device.h"
#include "h5/simplestm32h5_device.h"
#include "h7/simplestm32h7_device.h"
#include "h7rs/simplestm32h7rs_device.h"
#include "l0/simplestm32l0_device.h"
#include "l1/simplestm32l1_device.h"
#include "l4/simplestm32l4_device.h"
#include "l5/simplestm32l5_device.h"
#include "n6/simplestm32n6_device.h"
#include "u0/simplestm32u0_device.h"
#include "u5/simplestm32u5_device.h"
#include "wb/simplestm32wb_device.h"
#include "wba/simplestm32wba_device.h"
#include "wl/simplestm32wl_device.h"

#if defined(SIMPLESTM32_C0)
#include "c0/simplestm32c0.h"
#elif defined(SIMPLESTM32_F0)
#include "f0/simplestm32f0.h"
#elif defined(SIMPLESTM32_F1)
#include "f1/simplestm32f1.h"
#elif defined(SIMPLESTM32_F2)
#include "f2/simplestm32f2.h"
#elif defined(SIMPLESTM32_F3)
#include "f3/simplestm32f3.h"
#elif defined(SIMPLESTM32_F4)
#include "f4/simplestm32f4.h"
#elif defined(SIMPLESTM32_F7)
#include "f7/simplestm32f7.h"
#elif defined(SIMPLESTM32_G0)
#include "g0/simplestm32g0.h"
#elif defined(SIMPLESTM32_G4)
#include "g4/simplestm32g4.h"
#elif defined(SIMPLESTM32_H5)
#include "h5/simplestm32h5.h"
#elif defined(SIMPLESTM32_H7)
#include "h7/simplestm32h7.h"
#elif defined(SIMPLESTM32_H7RS)
#include "h7rs/simplestm32h7rs.h"
#elif defined(SIMPLESTM32_L0)
#include "l0/simplestm32l0.h"
#elif defined(SIMPLESTM32_L1)
#include "l1/simplestm32l1.h"
#elif defined(SIMPLESTM32_L4)
#include "l4/simplestm32l4.h"
#elif defined(SIMPLESTM32_L5)
#include "l5/simplestm32l5.h"
#elif defined(SIMPLESTM32_N6)
#include "n6/simplestm32n6.h"
#elif defined(SIMPLESTM32_U0)
#include "u0/simplestm32u0.h"
#elif defined(SIMPLESTM32_U5)
#include "u5/simplestm32u5.h"
#elif defined(SIMPLESTM32_WB)
#include "wb/simplestm32wb.h"
#elif defined(SIMPLESTM32_WBA)
#include "wba/simplestm32wba.h"
#elif defined(SIMPLESTM32_WL)
#include "wl/simplestm32wl.h"
#else
#error "Unsupported or undefined STM32 device. Please define the target STM32 device."
#endif
