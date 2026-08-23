#pragma once

/**
 * @brief Device detection for STM32U5. Include this (not the raw
 * device-macro list) from any STM32U5-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_U5)`.
 */
#if defined(STM32U535xx) || defined(STM32U545xx) || defined(STM32U575xx) || defined(STM32U585xx) || defined(STM32U595xx) || defined(STM32U599xx) || defined(STM32U5A5xx) || defined(STM32U5A9xx) || defined(STM32U5F7xx) || defined(STM32U5F9xx) || defined(STM32U5G7xx) || defined(STM32U5G9xx)
#define SIMPLESTM32_U5
#endif
