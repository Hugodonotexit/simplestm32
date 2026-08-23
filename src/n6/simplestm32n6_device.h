#pragma once

/**
 * @brief Device detection for STM32N6. Include this (not the raw
 * device-macro list) from any STM32N6-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_N6)`.
 */
#if defined(STM32N645xx) || defined(STM32N647xx) || defined(STM32N655xx) || defined(STM32N657xx)
#define SIMPLESTM32_N6
#endif
