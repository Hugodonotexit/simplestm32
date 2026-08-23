#pragma once

/**
 * @brief Device detection for STM32L5. Include this (not the raw
 * device-macro list) from any STM32L5-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_L5)`.
 */
#if defined(STM32L552xx) || defined(STM32L562xx)
#define SIMPLESTM32_L5
#endif
