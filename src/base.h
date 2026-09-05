#pragma once
#include <stdint.h>


/** Logic level of a GPIO pin. */
enum PinState{
    PIN_LOW = 0,
    PIN_HIGH =1
};

#if !defined(SIMPLESTM32_F1)
/** Function of a GPIO pin, as programmed in the port's MODER register. */
enum PinMode{
    MODE_INPUT = 0,
    MODE_OUTPUT = 1,
    MODE_ALTERNATE = 2,
    MODE_ANALOG = 3
};

enum PinPullMode {
    MODE_FLOATING = 0,
    MODE_PULLUP = 1,
    MODE_PULLDOWN = 2,
};

/** Output driver type for a pin, as programmed in the port's OTYPER register. */
enum PinOutputType {
    TYPE_PUSH_PULL = 0,
    TYPE_OPEN_DRAIN = 1,
};

#else

enum PinMode : uint8_t {
    // --- Input configs (MODE must be 00) ---
    MODE_ANALOG_INPUT      = 0b0000,
    MODE_FLOATING_INPUT     = 0b0100,
    MODE_PULL_INPUT         = 0b1000,   // pull-up/down, direction set via ODR

    // --- Output configs ---
    MODE_GP_PUSH_PULL_10    = 0b0001,
    MODE_GP_OPEN_DRAIN_10   = 0b0101,
    MODE_AF_PUSH_PULL_10    = 0b1001,
    MODE_AF_OPEN_DRAIN_10   = 0b1101,

    MODE_GP_PUSH_PULL_2     = 0b0010,
    MODE_GP_OPEN_DRAIN_2    = 0b0110,
    MODE_AF_PUSH_PULL_2     = 0b1010,
    MODE_AF_OPEN_DRAIN_2    = 0b1110,

    MODE_GP_PUSH_PULL_50     = 0b0011,
    MODE_GP_OPEN_DRAIN_50    = 0b0111,
    MODE_AF_PUSH_PULL_50     = 0b1011,
    MODE_AF_OPEN_DRAIN_50    = 0b1111,
};

enum PinPullMode {
    MODE_PULLUP = 1,
    MODE_PULLDOWN = 0,
};

#endif



/**
 * @brief Named constants for PinState/PinMode, used via the global `pin` instance.
 *
 * Lets call sites read as `PIN.OUTPUT`, `pin.HIGH`, etc. instead of the
 * raw enumerator names.
 */
struct PinValues {
    static constexpr PinState LOW  = PIN_LOW;
    static constexpr PinState HIGH = PIN_HIGH;
    #if !defined(SIMPLESTM32_F1)
    static constexpr PinMode INPUT     = MODE_INPUT;
    static constexpr PinMode OUTPUT    = MODE_OUTPUT;
    static constexpr PinMode ALTERNATE = MODE_ALTERNATE;
    static constexpr PinMode ANALOG    = MODE_ANALOG;
    static constexpr PinPullMode PULLUP    = MODE_PULLUP;
    static constexpr PinPullMode PULLDOWN = MODE_PULLDOWN;
    static constexpr PinPullMode FLOATING    = MODE_FLOATING;
    static constexpr PinOutputType PUSH_PULL  = TYPE_PUSH_PULL;
    static constexpr PinOutputType OPEN_DRAIN = TYPE_OPEN_DRAIN;
    #else
    static constexpr PinPullMode PULLUP    = MODE_PULLUP;
    static constexpr PinPullMode PULLDOWN = MODE_PULLDOWN;
    struct INPUT {
        static constexpr PinMode ANALOG_INPUT     = MODE_ANALOG_INPUT;
        static constexpr PinMode FLOATING_INPUT    = MODE_FLOATING_INPUT;
        static constexpr PinMode PULL_INPUT = MODE_PULL_INPUT;
    };
    struct OUTPUT2 {
        static constexpr PinMode GP_PUSH_PULL = MODE_GP_PUSH_PULL_2;
        static constexpr PinMode GP_OPEN_DRAIN = MODE_GP_OPEN_DRAIN_2;
        static constexpr PinMode AF_PUSH_PULL = MODE_AF_PUSH_PULL_2;
        static constexpr PinMode AF_OPEN_DRAIN = MODE_AF_OPEN_DRAIN_2;
    };
    struct OUTPUT10 {
        static constexpr PinMode GP_PUSH_PULL = MODE_GP_PUSH_PULL_10;
        static constexpr PinMode GP_OPEN_DRAIN = MODE_GP_OPEN_DRAIN_10;
        static constexpr PinMode AF_PUSH_PULL = MODE_AF_PUSH_PULL_10;
        static constexpr PinMode AF_OPEN_DRAIN = MODE_AF_OPEN_DRAIN_10;
    };
    struct OUTPUT50 {
        static constexpr PinMode GP_PUSH_PULL = MODE_GP_PUSH_PULL_50;
        static constexpr PinMode GP_OPEN_DRAIN = MODE_GP_OPEN_DRAIN_50;
        static constexpr PinMode AF_PUSH_PULL = MODE_AF_PUSH_PULL_50;
        static constexpr PinMode AF_OPEN_DRAIN = MODE_AF_OPEN_DRAIN_50;
    };

    INPUT INPUT;
    OUTPUT2 OUTPUT2;
    OUTPUT10 OUTPUT10;
    OUTPUT50 OUTPUT50;

    #endif
};
inline constexpr PinValues PIN{};

/**
 * @brief Register-level GPIO pin operations, shared by every STM32 family.
 *
 * Operates only on a GPIO_TypeDef* (MODER/ODR/IDR), so this class is
 * portable as-is across families -- only peripheral clock gating differs
 * per family, which is handled by each family's PinID subclass instead.
 */
class GpioPin
{
protected:
    GPIO_TypeDef* id;
    GpioPin(GPIO_TypeDef* id) : id(id) {}
public:
    /**
     * @brief Configure a pin's function (input, output, alternate function, analog).
     * @param pin  Pin number within the port (0-15).
     * @param mode One of PIN.INPUT / PIN.OUTPUT / PIN.ALTERNATE / PIN.ANALOG.
     */
    void setPinMode(uint8_t pin, PinMode mode);

    #if !defined(SIMPLESTM32_F1)
    /**
     * @brief Select the alternate function routed to a pin via AFR.
     * @param pin Pin number within the port (0-15).
     * @param af  Alternate function number (0-15, i.e. AF0-AF15); see the datasheet's alternate function table. The pin must already be set to PIN.ALTERNATE mode.
     */
    void setPinAF(uint8_t pin, uint8_t af);

    /**
     * @brief Select push-pull or open-drain output for a pin via OTYPER.
     * @param pin  Pin number within the port (0-15).
     * @param type PIN.PUSH_PULL or PIN.OPEN_DRAIN.
     */
    void setPinOutputType(uint8_t pin, PinOutputType type);
    #endif

    /**
     * @brief Drive a pin high or low. The pin must already be set to output mode.
     * @param pin   Pin number within the port (0-15).
     * @param state pin.high or pin.low.
     */
    void writePin(uint8_t pin, PinState state);

    /**
     * @brief Read a pin's current logic level.
     * @param pin Pin number within the port (0-15).
     * @return pin.high or pin.low.
     */
    PinState readPin(uint8_t pin);

    /**
     * @brief Flip a pin's output level (high becomes low, low becomes high).
     * @param pin Pin number within the port (0-15).
     */
    void togglePin(uint8_t pin);

    /**
     * @brief Enable or disable a pin's internal pull-up/pull-down resistor via PUPDR.
     * @param pin  Pin number within the port (0-15).
     * @param mode PIN.FLOATING (no pull), PIN.PULLUP, or PIN.PULLDOWN.
     */
    void setPinPullMode(uint8_t pin, PinPullMode mode);
};
