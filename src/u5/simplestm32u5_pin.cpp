#include "simplestm32u5_pin.h"

#if defined(SIMPLESTM32_U5)

PinID::PinID(uint16_t pinmask, GPIO_TypeDef* id) : GpioPin(id), pinmask(pinmask) {
    RCC->AHB2ENR1 |= pinmask;
}

PinID::~PinID() {
    RCC->AHB2ENR1 &= ~pinmask;
}

#if defined(GPIOA)
PinA::PinA() : PinID(RCC_AHB2ENR1_GPIOAEN, GPIOA) {
}

PinA::~PinA() {
}
#endif

#if defined(GPIOB)
PinB::PinB() : PinID(RCC_AHB2ENR1_GPIOBEN, GPIOB) {
}

PinB::~PinB() {
}
#endif

#if defined(GPIOC)
PinC::PinC() : PinID(RCC_AHB2ENR1_GPIOCEN, GPIOC) {
}

PinC::~PinC() {
}
#endif

#if defined(GPIOD)
PinD::PinD() : PinID(RCC_AHB2ENR1_GPIODEN, GPIOD) {
}

PinD::~PinD() {
}
#endif

#if defined(GPIOE)
PinE::PinE() : PinID(RCC_AHB2ENR1_GPIOEEN, GPIOE) {
}

PinE::~PinE() {
}
#endif

#if defined(GPIOF)
PinF::PinF() : PinID(RCC_AHB2ENR1_GPIOFEN, GPIOF) {
}

PinF::~PinF() {
}
#endif

#if defined(GPIOG)
PinG::PinG() : PinID(RCC_AHB2ENR1_GPIOGEN, GPIOG) {
}

PinG::~PinG() {
}
#endif

#if defined(GPIOH)
PinH::PinH() : PinID(RCC_AHB2ENR1_GPIOHEN, GPIOH) {
}

PinH::~PinH() {
}
#endif

#if defined(GPIOI)
PinI::PinI() : PinID(RCC_AHB2ENR1_GPIOIEN, GPIOI) {
}

PinI::~PinI() {
}
#endif

#if defined(GPIOJ)
PinJ::PinJ() : PinID(RCC_AHB2ENR1_GPIOJEN, GPIOJ) {
}

PinJ::~PinJ() {
}
#endif

#if defined(GPIOK)
PinK::PinK() : PinID(RCC_AHB2ENR1_GPIOKEN, GPIOK) {
}

PinK::~PinK() {
}
#endif

#endif // defined(SIMPLESTM32_U5)
