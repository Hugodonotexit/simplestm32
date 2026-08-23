#pragma once

/**
 * @brief Device detection for STM32F7. Include this (not the raw
 * device-macro list) from any STM32F7-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_F7)`.
 */
#if defined(STM32F722xx) || defined(STM32F723xx) || defined(STM32F730xx) || defined(STM32F732xx) || defined(STM32F733xx) || defined(STM32F745xx) || defined(STM32F746xx) || defined(STM32F750xx) || defined(STM32F756xx) || defined(STM32F765xx) || defined(STM32F767xx) || defined(STM32F769xx) || defined(STM32F777xx) || defined(STM32F779xx)
#define SIMPLESTM32_F7
#endif
