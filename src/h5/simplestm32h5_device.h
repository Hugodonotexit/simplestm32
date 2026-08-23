#pragma once

/**
 * @brief Device detection for STM32H5. Include this (not the raw
 * device-macro list) from any STM32H5-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_H5)`.
 */
#if defined(STM32H503xx) || defined(STM32H523xx) || defined(STM32H533xx) || defined(STM32H562xx) || defined(STM32H563xx) || defined(STM32H573xx) || defined(STM32H5E4xx) || defined(STM32H5E5xx) || defined(STM32H5F4xx) || defined(STM32H5F5xx)
#define SIMPLESTM32_H5
#endif
