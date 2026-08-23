#pragma once

/**
 * @brief Device detection for STM32H7RS. Include this (not the raw
 * device-macro list) from any STM32H7RS-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_H7RS)`.
 */
#if defined(STM32H7R3xx) || defined(STM32H7R7xx) || defined(STM32H7S3xx) || defined(STM32H7S7xx)
#define SIMPLESTM32_H7RS
#endif
