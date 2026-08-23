#pragma once

/**
 * @brief Device detection for STM32G0. Include this (not the raw
 * device-macro list) from any STM32G0-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_G0)`.
 */
#if defined(STM32G030xx) || defined(STM32G031xx) || defined(STM32G041xx) || defined(STM32G050xx) || defined(STM32G051xx) || defined(STM32G061xx) || defined(STM32G070xx) || defined(STM32G071xx) || defined(STM32G081xx) || defined(STM32G0B0xx) || defined(STM32G0B1xx) || defined(STM32G0C1xx)
#define SIMPLESTM32_G0
#endif
