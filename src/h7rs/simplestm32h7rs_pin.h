#pragma once

#include "simplestm32h7rs_device.h"

// Compiles to nothing when the whole simplestm32/src tree is added
// wholesale to a build targeting a different STM32 family.
#if defined(SIMPLESTM32_H7RS)

#include "../../vendor/cmsis_device_h7rs/Include/stm32h7rsxx.h"
#include "../base.h"

/**
 * @brief GPIO clock-enable adapter for STM32H7RS.
 *
 * Enables/disables the port's peripheral clock via RCC->AHB4ENR on
 * construction/destruction, then delegates all pin register access
 * to GpioPin.
 */
class PinID : public GpioPin
{
private:
    uint16_t pinmask;
public:
    /**
     * @param pinmask RCC_AHB4ENR_GPIOxEN bit for the target port.
     * @param id      Base pointer of the target GPIO port (e.g. GPIOA).
     */
    PinID(uint16_t pinmask, GPIO_TypeDef* id);
    ~PinID();
};

#if defined(GPIOA)
/** GPIO port A. */
class PinA : public PinID
{
private:
    /* data */
public:
    /** Enables the GPIOA peripheral clock. */
    PinA();
    /** Disables the GPIOA peripheral clock. */
    ~PinA();
};
#endif

#if defined(GPIOB)
/** GPIO port B. */
class PinB : public PinID
{
private:
    /* data */
public:
    /** Enables the GPIOB peripheral clock. */
    PinB();
    /** Disables the GPIOB peripheral clock. */
    ~PinB();
};
#endif

#if defined(GPIOC)
/** GPIO port C. */
class PinC : public PinID
{
private:
    /* data */
public:
    /** Enables the GPIOC peripheral clock. */
    PinC();
    /** Disables the GPIOC peripheral clock. */
    ~PinC();
};
#endif

#if defined(GPIOD)
/** GPIO port D. */
class PinD : public PinID
{
private:
    /* data */
public:
    /** Enables the GPIOD peripheral clock. */
    PinD();
    /** Disables the GPIOD peripheral clock. */
    ~PinD();
};
#endif

#if defined(GPIOE)
/** GPIO port E. */
class PinE : public PinID
{
private:
    /* data */
public:
    /** Enables the GPIOE peripheral clock. */
    PinE();
    /** Disables the GPIOE peripheral clock. */
    ~PinE();
};
#endif

#if defined(GPIOF)
/** GPIO port F. */
class PinF : public PinID
{
private:
    /* data */
public:
    /** Enables the GPIOF peripheral clock. */
    PinF();
    /** Disables the GPIOF peripheral clock. */
    ~PinF();
};
#endif

#if defined(GPIOG)
/** GPIO port G. */
class PinG : public PinID
{
private:
    /* data */
public:
    /** Enables the GPIOG peripheral clock. */
    PinG();
    /** Disables the GPIOG peripheral clock. */
    ~PinG();
};
#endif

#if defined(GPIOH)
/** GPIO port H. */
class PinH : public PinID
{
private:
    /* data */
public:
    /** Enables the GPIOH peripheral clock. */
    PinH();
    /** Disables the GPIOH peripheral clock. */
    ~PinH();
};
#endif

#if defined(GPIOI)
/** GPIO port I. */
class PinI : public PinID
{
private:
    /* data */
public:
    /** Enables the GPIOI peripheral clock. */
    PinI();
    /** Disables the GPIOI peripheral clock. */
    ~PinI();
};
#endif

#if defined(GPIOJ)
/** GPIO port J. */
class PinJ : public PinID
{
private:
    /* data */
public:
    /** Enables the GPIOJ peripheral clock. */
    PinJ();
    /** Disables the GPIOJ peripheral clock. */
    ~PinJ();
};
#endif

#if defined(GPIOK)
/** GPIO port K. */
class PinK : public PinID
{
private:
    /* data */
public:
    /** Enables the GPIOK peripheral clock. */
    PinK();
    /** Disables the GPIOK peripheral clock. */
    ~PinK();
};
#endif

#endif // defined(SIMPLESTM32_H7RS)
