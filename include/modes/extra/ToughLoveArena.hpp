#ifndef _MODES_TOUGHLOVEARENA_HPP
#define _MODES_TOUGHLOVEARENA_HPP

#include "core/KeyboardMode.hpp"
#include "core/socd.hpp"
#include "core/state.hpp"

class ToughLoveArena : public KeyboardMode {
  public:
    ToughLoveArena(const GameModeConfig &config);

  private:
    void UpdateKeys(const InputState &inputs);
};

#endif
