#pragma once

/**
 * @brief Device detection for STM32F4. Include this (not the raw
 * device-macro list) from any STM32F4-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_F4)`.
 */
#if defined(STM32F401xC) || defined(STM32F401xE) || defined(STM32F405xx) || defined(STM32F407xx) || defined(STM32F410Cx) || defined(STM32F410Rx) || defined(STM32F410Tx) || defined(STM32F411xE) || defined(STM32F412Cx) || defined(STM32F412Rx) || defined(STM32F412Vx) || defined(STM32F412Zx) || defined(STM32F413xx) || defined(STM32F415xx) || defined(STM32F417xx) || defined(STM32F423xx) || defined(STM32F427xx) || defined(STM32F429xx) || defined(STM32F437xx) || defined(STM32F439xx) || defined(STM32F446xx) || defined(STM32F469xx) || defined(STM32F479xx)
#define SIMPLESTM32_F4
#endif
