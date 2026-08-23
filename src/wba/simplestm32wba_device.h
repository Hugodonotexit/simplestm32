#pragma once

/**
 * @brief Device detection for STM32WBA. Include this (not the raw
 * device-macro list) from any STM32WBA-specific file, and guard its
 * content on `#if defined(SIMPLESTM32_WBA)`.
 */
#if defined(STM32WBA20xx) || defined(STM32WBA23xx) || defined(STM32WBA25xx) || defined(STM32WBA50xx) || defined(STM32WBA52xx) || defined(STM32WBA54xx) || defined(STM32WBA55xx) || defined(STM32WBA5Mxx) || defined(STM32WBA62xx) || defined(STM32WBA63xx) || defined(STM32WBA64xx) || defined(STM32WBA65xx) || defined(STM32WBA6Mxx)
#define SIMPLESTM32_WBA
#endif
