#pragma once

/**
 * @brief Device detection for STM32G4. Include this (not the raw
 * device-macro list) from any STM32G4-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_G4)`.
 */
#if defined(STM32G414xx) || defined(STM32G431xx) || defined(STM32G441xx) || defined(STM32G471xx) || defined(STM32G473xx) || defined(STM32G474xx) || defined(STM32G483xx) || defined(STM32G484xx) || defined(STM32G491xx) || defined(STM32G4A1xx) || defined(STM32GBK1CB)
#define SIMPLESTM32_G4
#endif
