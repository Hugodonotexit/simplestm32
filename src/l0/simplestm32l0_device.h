#pragma once

/**
 * @brief Device detection for STM32L0. Include this (not the raw
 * device-macro list) from any STM32L0-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_L0)`.
 */
#if defined(STM32L010x4) || defined(STM32L010x6) || defined(STM32L010x8) || defined(STM32L010xB) || defined(STM32L011xx) || defined(STM32L021xx) || defined(STM32L031xx) || defined(STM32L041xx) || defined(STM32L051xx) || defined(STM32L052xx) || defined(STM32L053xx) || defined(STM32L062xx) || defined(STM32L063xx) || defined(STM32L071xx) || defined(STM32L072xx) || defined(STM32L073xx) || defined(STM32L081xx) || defined(STM32L082xx) || defined(STM32L083xx)
#define SIMPLESTM32_L0
#endif
