#pragma once

/**
 * @brief Device detection for STM32C0. Include this (not the raw
 * device-macro list) from any STM32C0-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_C0)`.
 */
#if defined(STM32C011xx) || defined(STM32C031xx) || defined(STM32C051xx) || defined(STM32C071xx) || defined(STM32C091xx) || defined(STM32C092xx)
#define SIMPLESTM32_C0
#endif
