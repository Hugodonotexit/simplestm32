#pragma once

/**
 * @brief Device detection for STM32H7. Include this (not the raw
 * device-macro list) from any STM32H7-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_H7)`.
 */
#if defined(STM32H723xx) || defined(STM32H725xx) || defined(STM32H730xx) || defined(STM32H730xxQ) || defined(STM32H733xx) || defined(STM32H735xx) || defined(STM32H742xx) || defined(STM32H743xx) || defined(STM32H750xx) || defined(STM32H753xx) || defined(STM32H7A3xx) || defined(STM32H7A3xxQ) || defined(STM32H7B0xx) || defined(STM32H7B0xxQ) || defined(STM32H7B3xx) || defined(STM32H7B3xxQ)
#define SIMPLESTM32_H7
#endif
