#pragma once

/**
 * @brief Device detection for STM32F2. Include this (not the raw
 * device-macro list) from any STM32F2-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_F2)`.
 */
#if defined(STM32F205xx) || defined(STM32F207xx) || defined(STM32F215xx) || defined(STM32F217xx)
#define SIMPLESTM32_F2
#endif
