#pragma once

/**
 * @brief Device detection for STM32F1. Include this (not the raw
 * device-macro list) from any STM32F1-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_F1)`.
 */
#if defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
#define SIMPLESTM32_F1
#endif
