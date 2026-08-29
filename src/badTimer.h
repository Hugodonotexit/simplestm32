#pragma once
#include <stdint.h>

/**
 * @brief NOP-loop busy-wait delays, scaled by SystemCoreClock at construction.
 *
 * "Bad" because it's not a hardware timer: an instance snapshots
 * SystemCoreClock once at construction, so it must be constructed after the
 * clock tree is configured, and a later clock change won't be reflected
 * until a new instance is created.
 */
class BadTimer
{
private:
    uint32_t coreClockHz;
public:
    BadTimer();

    /**
     * @brief Busy-wait for approximately `count` CPU cycles using NOPs.
     * @param count Number of no-op iterations to spin through; `volatile` prevents the loop from being optimized away.
     */
    void delay(volatile uint32_t count);

    /**
     * @brief Busy-wait for approximately `us` microseconds.
     * @param us Requested delay in microseconds.
     * @note Low precision: the iteration count is derived from the
     * SystemCoreClock snapshot taken at construction, assuming a fixed
     * CPU-cycle cost per delay() loop iteration and a clock of at least
     * 1 MHz, so actual timing drifts with optimization level, flash wait
     * states, and pipeline effects.
     */
    void delayUs(uint32_t us);

    /**
     * @brief Busy-wait for approximately `ms` milliseconds.
     * @param ms Requested delay in milliseconds.
     * @note Same low-precision caveat as delayUs() applies.
     */
    void delayMs(uint32_t ms);
};
