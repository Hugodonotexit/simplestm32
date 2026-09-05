#pragma once

#include "simplestm32f1_device.h"

// Compiles to nothing when the whole simplestm32/src tree is added
// wholesale to a build targeting a different STM32 family.
#if defined(SIMPLESTM32_F1)

#include "../../vendor/cmsis_device_f1/Include/stm32f1xx.h"
#include "../base.h"

/**
 * @brief GPIO clock-enable adapter for STM32F1.
 *
 * Enables/disables the port's peripheral clock via RCC->APB2ENR on
 * construction/destruction, then delegates all pin register access
 * to GpioPin. Also manages AFIO's clock (AFIO->MAPR/MAPR2, peripheral pin
 * remapping) via afioRefCount: AFIO is a single MCU-wide peripheral, not
 * tied to any one port, so its clock is enabled when the first PinID is
 * constructed and disabled when the last one is destroyed -- safe for any
 * number of Pin* to overlap.
 */
class PinID : public GpioPin
{
private:
    uint16_t pinmask;
    static uint8_t afioRefCount;
public:
    /**
     * @param pinmask RCC_APB2ENR_IOPxEN bit for the target port.
     * @param id      Base pointer of the target GPIO port (e.g. GPIOA).
     */
    PinID(uint16_t pinmask, GPIO_TypeDef* id);

    /**
     * @brief Configure a pin's function via F1's CRL/CRH registers.
     *
     * Overrides GpioPin::setPinMode -- F1 has no MODER register. Each
     * PinMode enumerator already encodes the exact 4-bit CNF+MODE(+speed)
     * field, so this just writes it into the right nibble of CRL
     * (pins 0-7) or CRH (pins 8-15).
     * @param pin  Pin number within the port (0-15).
     * @param mode One of PIN.INPUT.*, PIN.OUTPUT2.*, PIN.OUTPUT10.*, PIN.OUTPUT50.*.
     */
    void setPinMode(uint8_t pin, PinMode mode);

    /**
     * @brief Select pull-up or pull-down for a pin, configuring it as a pull input.
     *
     * F1 has no PUPDR register: pull direction on an input pin is chosen by
     * that pin's ODR bit (set here via BSRR) while CNF=10/MODE=00. This
     * puts the pin into PIN.INPUT.PULL_INPUT mode itself, so it's a
     * complete, self-sufficient call -- no separate setPinMode needed first.
     * @param pin  Pin number within the port (0-15).
     * @param mode PIN.PULLUP or PIN.PULLDOWN.
     */
    void setPinPullMode(uint8_t pin, PinPullMode mode);

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

#endif // defined(SIMPLESTM32_F1)
