#include "simplestm32l0_pin.h"

#if defined(SIMPLESTM32_L0)

PinID::PinID(uint16_t pinmask, GPIO_TypeDef* id) : GpioPin(id), pinmask(pinmask) {
    RCC->IOPENR |= pinmask;
}

PinID::~PinID() {
    RCC->IOPENR &= ~pinmask;
}

#if defined(GPIOA)
PinA::PinA() : PinID(RCC_IOPENR_IOPAEN, GPIOA) {
}

PinA::~PinA() {
}
#endif

#if defined(GPIOB)
PinB::PinB() : PinID(RCC_IOPENR_IOPBEN, GPIOB) {
}

PinB::~PinB() {
}
#endif

#if defined(GPIOC)
PinC::PinC() : PinID(RCC_IOPENR_IOPCEN, GPIOC) {
}

PinC::~PinC() {
}
#endif

#if defined(GPIOD)
PinD::PinD() : PinID(RCC_IOPENR_IOPDEN, GPIOD) {
}

PinD::~PinD() {
}
#endif

#if defined(GPIOE)
PinE::PinE() : PinID(RCC_IOPENR_IOPEEN, GPIOE) {
}

PinE::~PinE() {
}
#endif

#if defined(GPIOF)
PinF::PinF() : PinID(RCC_IOPENR_IOPFEN, GPIOF) {
}

PinF::~PinF() {
}
#endif

#if defined(GPIOG)
PinG::PinG() : PinID(RCC_IOPENR_IOPGEN, GPIOG) {
}

PinG::~PinG() {
}
#endif

#if defined(GPIOH)
PinH::PinH() : PinID(RCC_IOPENR_IOPHEN, GPIOH) {
}

PinH::~PinH() {
}
#endif

#if defined(GPIOI)
PinI::PinI() : PinID(RCC_IOPENR_IOPIEN, GPIOI) {
}

PinI::~PinI() {
}
#endif

#if defined(GPIOJ)
PinJ::PinJ() : PinID(RCC_IOPENR_IOPJEN, GPIOJ) {
}

PinJ::~PinJ() {
}
#endif

#if defined(GPIOK)
PinK::PinK() : PinID(RCC_IOPENR_IOPKEN, GPIOK) {
}

PinK::~PinK() {
}
#endif

#endif // defined(SIMPLESTM32_L0)
