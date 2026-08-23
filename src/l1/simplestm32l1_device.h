#pragma once

/**
 * @brief Device detection for STM32L1. Include this (not the raw
 * device-macro list) from any STM32L1-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_L1)`.
 */
#if defined(STM32L100xB) || defined(STM32L100xBA) || defined(STM32L100xC) || defined(STM32L151xB) || defined(STM32L151xBA) || defined(STM32L151xC) || defined(STM32L151xCA) || defined(STM32L151xD) || defined(STM32L151xDx) || defined(STM32L151xE) || defined(STM32L152xB) || defined(STM32L152xBA) || defined(STM32L152xC) || defined(STM32L152xCA) || defined(STM32L152xD) || defined(STM32L152xDx) || defined(STM32L152xE) || defined(STM32L162xC) || defined(STM32L162xCA) || defined(STM32L162xD) || defined(STM32L162xDx) || defined(STM32L162xE)
#define SIMPLESTM32_L1
#endif
