#include "simplestm32f1_pin.h"

#if defined(SIMPLESTM32_F1)

PinID::PinID(uint16_t pinmask, GPIO_TypeDef* id) : GpioPin(id), pinmask(pinmask) {
    RCC->APB2ENR |= pinmask;
}

void PinID::setPinMode(uint8_t pin, PinMode mode) {
    uint32_t shift = (uint32_t)(pin % 8U) * 4U;
    volatile uint32_t* reg = (pin < 8U) ? &this->id->CRL : &this->id->CRH;
    *reg = (*reg & ~(0xFU << shift)) | ((uint32_t)mode << shift);
}

PinID::~PinID() {
    RCC->APB2ENR &= ~pinmask;
}

#if defined(GPIOA)
PinA::PinA() : PinID(RCC_APB2ENR_IOPAEN, GPIOA) {
}

PinA::~PinA() {
}
#endif

#if defined(GPIOB)
PinB::PinB() : PinID(RCC_APB2ENR_IOPBEN, GPIOB) {
}

PinB::~PinB() {
}
#endif

#if defined(GPIOC)
PinC::PinC() : PinID(RCC_APB2ENR_IOPCEN, GPIOC) {
}

PinC::~PinC() {
}
#endif

#if defined(GPIOD)
PinD::PinD() : PinID(RCC_APB2ENR_IOPDEN, GPIOD) {
}

PinD::~PinD() {
}
#endif

#if defined(GPIOE)
PinE::PinE() : PinID(RCC_APB2ENR_IOPEEN, GPIOE) {
}

PinE::~PinE() {
}
#endif

#if defined(GPIOF)
PinF::PinF() : PinID(RCC_APB2ENR_IOPFEN, GPIOF) {
}

PinF::~PinF() {
}
#endif

#if defined(GPIOG)
PinG::PinG() : PinID(RCC_APB2ENR_IOPGEN, GPIOG) {
}

PinG::~PinG() {
}
#endif

#if defined(GPIOH)
PinH::PinH() : PinID(RCC_APB2ENR_IOPHEN, GPIOH) {
}

PinH::~PinH() {
}
#endif

#if defined(GPIOI)
PinI::PinI() : PinID(RCC_APB2ENR_IOPIEN, GPIOI) {
}

PinI::~PinI() {
}
#endif

#if defined(GPIOJ)
PinJ::PinJ() : PinID(RCC_APB2ENR_IOPJEN, GPIOJ) {
}

PinJ::~PinJ() {
}
#endif

#if defined(GPIOK)
PinK::PinK() : PinID(RCC_APB2ENR_IOPKEN, GPIOK) {
}

PinK::~PinK() {
}
#endif

#endif // defined(SIMPLESTM32_F1)
