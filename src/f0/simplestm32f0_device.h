#pragma once

/**
 * @brief Device detection for STM32F0. Include this (not the raw
 * device-macro list) from any STM32F0-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_F0)`.
 */
#if defined(STM32F030x6) || defined(STM32F030x8) || defined(STM32F030xC) || defined(STM32F031x6) || defined(STM32F038xx) || defined(STM32F042x6) || defined(STM32F048xx) || defined(STM32F051x8) || defined(STM32F058xx) || defined(STM32F070x6) || defined(STM32F070xB) || defined(STM32F071xB) || defined(STM32F072xB) || defined(STM32F078xx) || defined(STM32F091xC) || defined(STM32F098xx)
#define SIMPLESTM32_F0
#endif
