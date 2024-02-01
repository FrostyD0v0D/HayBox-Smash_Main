#ifndef _INPUT_GPIOBUTTONINPUT_HPP
#define _INPUT_GPIOBUTTONINPUT_HPP

#include "core/InputSource.hpp"
#include "core/state.hpp"
#include "stdlib.hpp"

#include <config.pb.h>

typedef struct {
    Button button;
    uint pin;
} GpioButtonMapping;

class GpioButtonInput : public InputSource {
  public:
    GpioButtonInput(const GpioButtonMapping *button_mappings, size_t button_count);
    InputScanSpeed ScanSpeed();
    void UpdateInputs(InputState &inputs);

  protected:
    const GpioButtonMapping *_button_mappings;
    size_t _button_count;

  private:
    virtual void UpdateButtonState(InputState &inputs, size_t button_mapping_index, bool pressed);
};

#endif