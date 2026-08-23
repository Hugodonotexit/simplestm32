#pragma once

/**
 * @brief Device detection for STM32F3. Include this (not the raw
 * device-macro list) from any STM32F3-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_F3)`.
 */
#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F302xC) || defined(STM32F302xE) || defined(STM32F303x8) || defined(STM32F303xC) || defined(STM32F303xE) || defined(STM32F318xx) || defined(STM32F328xx) || defined(STM32F334x8) || defined(STM32F358xx) || defined(STM32F373xC) || defined(STM32F378xx) || defined(STM32F398xx)
#define SIMPLESTM32_F3
#endif
