#pragma once

/**
 * @brief Device detection for STM32U0. Include this (not the raw
 * device-macro list) from any STM32U0-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_U0)`.
 */
#if defined(STM32U031xx) || defined(STM32U073xx) || defined(STM32U083xx)
#define SIMPLESTM32_U0
#endif
