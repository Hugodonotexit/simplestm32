#include "simplestm32.h"

#if !defined(SIMPLESTM32_F1)
void GpioPin::setPinMode(uint8_t pin, PinMode mode) {
    uint32_t bit_position = (uint32_t)pin * 2U;
    this->id->MODER &= ~(0x3U << bit_position);
    this->id->MODER |= ((uint32_t)mode << bit_position);
}

void GpioPin::setPinAF(uint8_t pin, uint8_t af) {
    uint32_t bit_position = (uint32_t)(pin % 8) * 4U;
    this->id->AFR[pin / 8] &= ~(0xFU << bit_position);
    this->id->AFR[pin / 8] |= ((uint32_t)af << bit_position);
}

void GpioPin::setPinOutputType(uint8_t pin, PinOutputType type) {
    this->id->OTYPER &= ~(1U << pin);
    this->id->OTYPER |= ((uint32_t)type << pin);
}
#endif

void GpioPin::writePin(uint8_t pin, PinState state) {
    if (state) {
        this->id->ODR |= (1U << pin);
    } else {
        this->id->ODR &= ~(1U << pin);
    }
}

PinState GpioPin::readPin(uint8_t pin) {
    return (this->id->IDR & (1U << pin)) ? PIN_HIGH : PIN_LOW;
}

void GpioPin::togglePin(uint8_t pin) {
    this->id->ODR ^= (1U << pin);
}

#if !defined(SIMPLESTM32_F1)
void GpioPin::setPinPullMode(uint8_t pin, PinPullMode mode) {
    uint32_t bit_position = (uint32_t)pin * 2U;
    this->id->PUPDR &= ~(0x3U << bit_position);
    this->id->PUPDR |= ((uint32_t)mode << bit_position);
}
#endif