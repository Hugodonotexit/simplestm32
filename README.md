# simplestm32

A minimal C++ GPIO interface for STM32 microcontrollers — no STM32CubeMX, no HAL, no code generator. Just include a header, construct a pin, and use it.

> **Version: alpha.** The API, file layout, and supported-family list can all still change. GPIO is the only peripheral covered so far.

## Why

STM32CubeMX + HAL gets you a lot of generated code and configuration for what is, most of the time, a handful of register writes. `simplestm32` is the opposite bet: a small, readable C++ wrapper directly over the CMSIS device headers, with no generator step and no config files to keep in sync with your code.

## Example

```cpp
#include "simplestm32.h"

int main(void)
{
    PinA pa;                        // enables the GPIOA clock
    pa.setPinMode(5, PIN.OUTPUT);   // PA5 as output

    for (;;) {
        pa.togglePin(5);
    }
}
```

`PinA`'s constructor enables the port's peripheral clock; its destructor disables it. No `HAL_Init()`, no `MX_GPIO_Init()`, no `.ioc` file.

## Using it in a project

1. Define your target device macro (e.g. `STM32C031xx`), the same one the CMSIS device header expects.
2. Add `simplestm32/src` to your include path **and** recursively to your sources (every `.cpp` under it).
3. `#include "simplestm32.h"`.

No need to cherry-pick which family's `.cpp` files to add: every family's `_pin.h`/`_pin.cpp` is guarded on that family, so the 21 families that don't match your target compile down to nothing — only the one matching your `#define` produces any code. So `file(GLOB_RECURSE ...)` (or your build system's equivalent) over `simplestm32/src` just works, same as [`stmenv1/CMakeLists.txt`](../stmenv1/CMakeLists.txt) does it.

## Architecture

- **`base.h` / `base.cpp`** — `GpioPin`, the portable part. Pure register operations (`setPinMode`, `writePin`, `readPin`, `togglePin`) on a `GPIO_TypeDef*`. `writePin`/`readPin`/`togglePin` (via `ODR`/`IDR`) are identical across every family, F1 included, so they never need porting. `setPinMode` is the exception — it's `MODER`-based, which F1 doesn't have; see the F1 note below.
- **`<family>/simplestm32<family>_device.h`** — the *only* place a family's raw device-macro list (`STM32F401xC`, `STM32F407xx`, ...) lives. It does nothing but check those macros and, if they match, define `SIMPLESTM32_<FAMILY>` and `SIMPLESTM32_DEVICE_MATCHED` — no CMSIS include, no classes, so it's always safe to include from anywhere. Every other family-specific file — `_pin.h` today, a future `_uart.h`/`_timer.h` — includes this and guards on the short derived macro instead of repeating the device list. A new device variant in an existing family only ever touches this one file.
- **`<family>/simplestm32<family>_pin.h/.cpp`** — `PinID`, the family-specific clock-gating piece: enabling/disabling the port's peripheral clock in its constructor/destructor. The RCC register and bit-name prefix differ per family (see table below).
- **`PinA` … `PinK`** — one thin subclass of `PinID` per GPIO port, each wrapped in `#if defined(GPIOx)` so only the ports that actually exist on the specific chip you're building for get compiled in. This also means a `PinA` object anywhere always means "port A on whatever chip you're targeting."
- **`simplestm32.h`** — includes every family's `_device.h` (cheap — see above), errors out if none matched, then includes only the matching family's actual implementation. Adding a whole new family is the only thing that touches this file.

## Supported families

Every family below has a generated `PinID`/`PinA`..`PinK` implementation, using the peripheral clock-enable register verified against the vendored CMSIS device headers:

| Family | Clock register | Bit name |
|---|---|---|
| C0, G0, U0 | `RCC->IOPENR` | `GPIOxEN` |
| L0 | `RCC->IOPENR` | `IOPxEN` |
| F0, F3, L1 | `RCC->AHBENR` | `GPIOxEN` |
| F1 | `RCC->APB2ENR` | `IOPxEN` |
| F2, F4, F7 | `RCC->AHB1ENR` | `GPIOxEN` |
| G4, H5, L4, L5, WB, WBA, WL | `RCC->AHB2ENR` | `GPIOxEN` |
| U5 | `RCC->AHB2ENR1` | `GPIOxEN` |
| H7, H7RS, N6 | `RCC->AHB4ENR` | `GPIOxEN` |

**Only STM32C0 has been built and run** (via [`stmenv1/`](../stmenv1), see below) — the rest compile against the correct registers but haven't been hardware- or simulator-tested yet.

**STM32F1** uses the older `CRL`/`CRH` GPIO peripheral instead of `MODER`, so it doesn't share the common `PinMode` enum or `GpioPin::setPinMode`. `base.h` compiles a completely different `PinMode` for F1: each enumerator's value *is* the 4-bit CNF+MODE(+speed) field written directly into `CRL`/`CRH`, exposed via nested constants — `PIN.INPUT.*`, `PIN.OUTPUT2.*`, `PIN.OUTPUT10.*`, `PIN.OUTPUT50.*` (grouped by output speed) — and `f1/simplestm32f1_pin.cpp` provides its own `PinID::setPinMode` override that packs the value into the right nibble of `CRL` (pins 0–7) or `CRH` (pins 8–15). `writePin`/`readPin`/`togglePin` are unaffected, since F1 has the same `ODR`/`IDR` registers as every other family.

## Testing

The [`stmenv1/`](../stmenv1) folder at the repository root is a CMake project targeting a NUCLEO-C031C6 board, wired up to build this library and run it under [Wokwi](https://wokwi.com)'s STM32 simulator. It's the closest thing this repo has to a test suite right now — there's no unit test framework, since almost everything here talks directly to hardware registers.

## Known limitations

- GPIO only — no UART, SPI, I2C, timers, or clock configuration yet.
- No dedicated pull-up/down API on any family yet. MODER-style families have no `PUPDR` wrapper; F1 needs `setPinMode(pin, PIN.INPUT.PULL_INPUT)` followed by `writePin(pin, HIGH/LOW)` to pick pull-up vs. pull-down via `ODR`, since F1 has no separate pull register at all.
- No package/install target; consumed by pointing your own build at `src/`.
- No semantic versioning yet — this is alpha, expect breaking changes.

## License

MIT — see [LICENSE](LICENSE).
