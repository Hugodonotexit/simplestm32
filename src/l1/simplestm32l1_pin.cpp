#include "simplestm32l1_pin.h"

#if defined(SIMPLESTM32_L1)

PinID::PinID(uint16_t pinmask, GPIO_TypeDef* id) : GpioPin(id), pinmask(pinmask) {
    RCC->AHBENR |= pinmask;
}

PinID::~PinID() {
    RCC->AHBENR &= ~pinmask;
}

#if defined(GPIOA)
PinA::PinA() : PinID(RCC_AHBENR_GPIOAEN, GPIOA) {
}

PinA::~PinA() {
}
#endif

#if defined(GPIOB)
PinB::PinB() : PinID(RCC_AHBENR_GPIOBEN, GPIOB) {
}

PinB::~PinB() {
}
#endif

#if defined(GPIOC)
PinC::PinC() : PinID(RCC_AHBENR_GPIOCEN, GPIOC) {
}

PinC::~PinC() {
}
#endif

#if defined(GPIOD)
PinD::PinD() : PinID(RCC_AHBENR_GPIODEN, GPIOD) {
}

PinD::~PinD() {
}
#endif

#if defined(GPIOE)
PinE::PinE() : PinID(RCC_AHBENR_GPIOEEN, GPIOE) {
}

PinE::~PinE() {
}
#endif

#if defined(GPIOF)
PinF::PinF() : PinID(RCC_AHBENR_GPIOFEN, GPIOF) {
}

PinF::~PinF() {
}
#endif

#if defined(GPIOG)
PinG::PinG() : PinID(RCC_AHBENR_GPIOGEN, GPIOG) {
}

PinG::~PinG() {
}
#endif

#if defined(GPIOH)
PinH::PinH() : PinID(RCC_AHBENR_GPIOHEN, GPIOH) {
}

PinH::~PinH() {
}
#endif

#if defined(GPIOI)
PinI::PinI() : PinID(RCC_AHBENR_GPIOIEN, GPIOI) {
}

PinI::~PinI() {
}
#endif

#if defined(GPIOJ)
PinJ::PinJ() : PinID(RCC_AHBENR_GPIOJEN, GPIOJ) {
}

PinJ::~PinJ() {
}
#endif

#if defined(GPIOK)
PinK::PinK() : PinID(RCC_AHBENR_GPIOKEN, GPIOK) {
}

PinK::~PinK() {
}
#endif

#endif // defined(SIMPLESTM32_L1)
