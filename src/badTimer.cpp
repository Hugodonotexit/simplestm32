#include "simplestm32.h"
#include "badTimer.h"

// Approximate CPU-cycle cost of one delay() loop iteration (test + decrement
// + branch + nop); used only to scale requested delays by SystemCoreClock,
// so it doesn't need to be exact.
static constexpr uint32_t BASIC_DELAY_LOOP_CYCLES = 4;

BadTimer::BadTimer() : coreClockHz(SystemCoreClock) {}

void BadTimer::delay(volatile uint32_t count) {
    while (count--) {
        __asm__ volatile("nop");
    }
}

void BadTimer::delayUs(uint32_t us) {
    delay((coreClockHz / 1000000UL) * us / BASIC_DELAY_LOOP_CYCLES);
}

void BadTimer::delayMs(uint32_t ms) {
    delayUs(ms * 1000UL);
}
