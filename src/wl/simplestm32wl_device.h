#pragma once

/**
 * @brief Device detection for STM32WL. Include this (not the raw
 * device-macro list) from any STM32WL-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_WL)`.
 */
#if defined(STM32WL54xx) || defined(STM32WL55xx) || defined(STM32WLE4xx) || defined(STM32WLE5xx) || defined(STM32WL5Mxx)
#define SIMPLESTM32_WL
#endif
