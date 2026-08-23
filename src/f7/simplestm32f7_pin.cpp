#include "simplestm32f7_pin.h"

#if defined(SIMPLESTM32_F7)

PinID::PinID(uint16_t pinmask, GPIO_TypeDef* id) : GpioPin(id), pinmask(pinmask) {
    RCC->AHB1ENR |= pinmask;
}

PinID::~PinID() {
    RCC->AHB1ENR &= ~pinmask;
}

#if defined(GPIOA)
PinA::PinA() : PinID(RCC_AHB1ENR_GPIOAEN, GPIOA) {
}

PinA::~PinA() {
}
#endif

#if defined(GPIOB)
PinB::PinB() : PinID(RCC_AHB1ENR_GPIOBEN, GPIOB) {
}

PinB::~PinB() {
}
#endif

#if defined(GPIOC)
PinC::PinC() : PinID(RCC_AHB1ENR_GPIOCEN, GPIOC) {
}

PinC::~PinC() {
}
#endif

#if defined(GPIOD)
PinD::PinD() : PinID(RCC_AHB1ENR_GPIODEN, GPIOD) {
}

PinD::~PinD() {
}
#endif

#if defined(GPIOE)
PinE::PinE() : PinID(RCC_AHB1ENR_GPIOEEN, GPIOE) {
}

PinE::~PinE() {
}
#endif

#if defined(GPIOF)
PinF::PinF() : PinID(RCC_AHB1ENR_GPIOFEN, GPIOF) {
}

PinF::~PinF() {
}
#endif

#if defined(GPIOG)
PinG::PinG() : PinID(RCC_AHB1ENR_GPIOGEN, GPIOG) {
}

PinG::~PinG() {
}
#endif

#if defined(GPIOH)
PinH::PinH() : PinID(RCC_AHB1ENR_GPIOHEN, GPIOH) {
}

PinH::~PinH() {
}
#endif

#if defined(GPIOI)
PinI::PinI() : PinID(RCC_AHB1ENR_GPIOIEN, GPIOI) {
}

PinI::~PinI() {
}
#endif

#if defined(GPIOJ)
PinJ::PinJ() : PinID(RCC_AHB1ENR_GPIOJEN, GPIOJ) {
}

PinJ::~PinJ() {
}
#endif

#if defined(GPIOK)
PinK::PinK() : PinID(RCC_AHB1ENR_GPIOKEN, GPIOK) {
}

PinK::~PinK() {
}
#endif

#endif // defined(SIMPLESTM32_F7)
