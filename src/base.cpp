#include "simplestm32.h"

void GpioPin::setPinMode(uint8_t pin, PinMode mode) {
    uint32_t bit_position = (uint32_t)pin * 2U;
    this->id->MODER &= ~(0x3U << bit_position);
    this->id->MODER |= ((uint32_t)mode << bit_position);
}

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
