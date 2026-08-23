#pragma once

/**
 * @brief Device detection for STM32WB. Include this (not the raw
 * device-macro list) from any STM32WB-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_WB)`.
 */
#if defined(STM32WB10xx) || defined(STM32WB15xx) || defined(STM32WB1Mxx) || defined(STM32WB30xx) || defined(STM32WB35xx) || defined(STM32WB50xx) || defined(STM32WB55xx) || defined(STM32WB5Mxx)
#define SIMPLESTM32_WB
#endif
