#include "comms/backend_init.hpp"
#include "config_defaults.hpp"
#include "core/CommunicationBackend.hpp"
#include "core/KeyboardMode.hpp"
#include "core/mode_selection.hpp"
#include "core/pinout.hpp"
#include "core/state.hpp"
#include "input/GpioButtonInput.hpp"
#include "reboot.hpp"
#include "stdlib.hpp"

#include <config.pb.h>

// clang-format off

const Config config = default_config;

/*
const Config config = {
    .default_backend = COMMS_BACKEND_DINPUT,
    .game_mode_configs_count = 5,
    .game_mode_configs = new GameModeConfig[5] {
        GameModeConfig {
            .mode_id = MODE_MELEE,
            .socd_pairs_count = 4,
            .socd_pairs = new SocdPair[4] {
                SocdPair { .button_dir1 = BTN_LF3, .button_dir2 = BTN_LF1, .socd_type = SOCD_2IP_NO_REAC },
                SocdPair { .button_dir1 = BTN_LF2, .button_dir2 = BTN_RF4, .socd_type = SOCD_2IP_NO_REAC },
                SocdPair { .button_dir1 = BTN_RT3, .button_dir2 = BTN_RT5, .socd_type = SOCD_2IP_NO_REAC },
                SocdPair { .button_dir1 = BTN_RT2, .button_dir2 = BTN_RT4, .socd_type = SOCD_2IP_NO_REAC },
            },
            .button_remapping_count = 0,
            .button_remapping = {},
            .activation_binding_count = 3,
            .activation_binding = new Button[3] { BTN_LT1, BTN_MB1, BTN_LF4 },
        },
        GameModeConfig {
            .mode_id = MODE_PROJECT_M,
            .socd_pairs_count = 4,
            .socd_pairs = new SocdPair[4] {
                SocdPair { .button_dir1 = BTN_LF3, .button_dir2 = BTN_LF1, .socd_type = SOCD_2IP_NO_REAC },
                SocdPair { .button_dir1 = BTN_LF2, .button_dir2 = BTN_RF4, .socd_type = SOCD_2IP_NO_REAC },
                SocdPair { .button_dir1 = BTN_RT3, .button_dir2 = BTN_RT5, .socd_type = SOCD_2IP_NO_REAC },
                SocdPair { .button_dir1 = BTN_RT2, .button_dir2 = BTN_RT4, .socd_type = SOCD_2IP_NO_REAC },
            },
            .button_remapping_count = 0,
            .button_remapping = {},
            .activation_binding_count = 3,
            .activation_binding = new Button[3] { BTN_LT1, BTN_MB1, BTN_LF3 },
        },
        GameModeConfig {
            .mode_id = MODE_ULTIMATE,
            .socd_pairs_count = 4,
            .socd_pairs = new SocdPair[4] {
                SocdPair { .button_dir1 = BTN_LF3, .button_dir2 = BTN_LF1, .socd_type = SOCD_2IP },
                SocdPair { .button_dir1 = BTN_LF2, .button_dir2 = BTN_RF4, .socd_type = SOCD_2IP },
                SocdPair { .button_dir1 = BTN_RT3, .button_dir2 = BTN_RT5, .socd_type = SOCD_2IP },
                SocdPair { .button_dir1 = BTN_RT2, .button_dir2 = BTN_RT4, .socd_type = SOCD_2IP },
            },
            .button_remapping_count = 0,
            .button_remapping = {},
            .activation_binding_count = 3,
            .activation_binding = new Button[3] { BTN_LT1, BTN_MB1, BTN_LF2 },
        },
        GameModeConfig {
            .mode_id = MODE_FGC,
            .socd_pairs_count = 2,
            .socd_pairs = new SocdPair[2] {
                SocdPair { .button_dir1 = BTN_LF3, .button_dir2 = BTN_LF1, .socd_type = SOCD_NEUTRAL },
                SocdPair { .button_dir1 = BTN_LT1, .button_dir2 = BTN_RT4, .socd_type = SOCD_NEUTRAL },
            },
            .button_remapping_count = 1,
            .button_remapping = new ButtonRemap[1] {
                ButtonRemap { .physical_button = BTN_RT4, .activates = BTN_LT1 },
            },
            .activation_binding_count = 3,
            .activation_binding = new Button[3] { BTN_LT1, BTN_MB1, BTN_LF1 },
        },
        GameModeConfig {
            .mode_id = MODE_KEYBOARD,
            .socd_pairs_count = 2,
            .socd_pairs = new SocdPair[2] {
                SocdPair { .button_dir1 = BTN_LF3, .button_dir2 = BTN_LF1, .socd_type = SOCD_2IP },
                SocdPair { .button_dir1 = BTN_LT1, .button_dir2 = BTN_RT4, .socd_type = SOCD_2IP },
            },
            .button_remapping_count = 0,
            .button_remapping = {},
            .activation_binding_count = 3,
            .activation_binding = new Button[3] { BTN_LT2, BTN_MB1, BTN_LF4 },
        },
    },
    .communication_backend_configs_count = 1,
    .communication_backend_configs = new CommunicationBackendConfig[1] {
        CommunicationBackendConfig {
            .backend_id = COMMS_BACKEND_DINPUT,
            .default_mode = MODE_MELEE,
            .activation_binding_count = 1,
            .activation_binding = new Button[1] { BTN_RF3 },
        },
    },
    .keyboard_modes_count = 1,
    .keyboard_modes = new KeyboardModeConfig[1] {
        KeyboardModeConfig {
            0,
            "Default",
            22,
            new ButtonToKeycodeMapping[22] {
                { BTN_LF4, HID_KEY_A },
                { BTN_LF3, HID_KEY_B },
                { BTN_LF2, HID_KEY_C },
                { BTN_LF1, HID_KEY_D },
                { BTN_LT1, HID_KEY_E },
                { BTN_LT2, HID_KEY_F },
                { BTN_MB3, HID_KEY_G },
                { BTN_MB1, HID_KEY_H },
                { BTN_MB2, HID_KEY_I },
                { BTN_RF5, HID_KEY_J },
                { BTN_RF6, HID_KEY_K },
                { BTN_RF7, HID_KEY_L },
                { BTN_RF8, HID_KEY_M },
                { BTN_RF1, HID_KEY_N },
                { BTN_RF2, HID_KEY_O },
                { BTN_RF3, HID_KEY_P },
                { BTN_RF4, HID_KEY_Q },
                { BTN_RT4, HID_KEY_R },
                { BTN_RT3, HID_KEY_S },
                { BTN_RT5, HID_KEY_T },
                { BTN_RT1, HID_KEY_U },
                { BTN_RT2, HID_KEY_V },
            },
        },
    },
};
*/

// clang-format on

const GpioButtonMapping button_mappings[] = {
    {BTN_LF4,  6 },
    { BTN_LF3, 4 },
    { BTN_LF2, 0 },
    { BTN_LF1, 1 },

    { BTN_LT1, 14},
    { BTN_LT2, 16},

    { BTN_MB3, 2 },
    { BTN_MB1, 3 },
    { BTN_MB2, 5 },

    { BTN_RT3, A2},
    { BTN_RT4, A3},
    { BTN_RT2, 15},
    { BTN_RT1, A5},
    { BTN_RT5, A4},

    { BTN_RF1, 10},
    { BTN_RF2, 11},
    { BTN_RF3, 13},
    { BTN_RF4, A1},

    { BTN_RF5, 7 },
    { BTN_RF6, 9 },
    { BTN_RF7, 12},
    { BTN_RF8, A0},
};
const size_t button_count = sizeof(button_mappings) / sizeof(GpioButtonMapping);

const Pinout pinout = {
    .joybus_data = 8,
    .mux = -1,
    .nunchuk_detect = -1,
    .nunchuk_sda = -1,
    .nunchuk_scl = -1,
};

CommunicationBackend **backends = nullptr;
size_t backend_count;
KeyboardMode *current_kb_mode = nullptr;

void setup() {
    static InputState inputs;

    // Create GPIO input source and use it to read button states for checking button holds.
    static GpioButtonInput gpio_input(button_mappings, button_count);
    gpio_input.UpdateInputs(inputs);

    if (inputs.mb1) {
        Serial.begin(115200);
        reboot_bootloader();
    }

    // Create array of input sources to be used.
    static InputSource *input_sources[] = { &gpio_input };
    size_t input_source_count = sizeof(input_sources) / sizeof(InputSource *);

    backend_count =
        initialize_backends(backends, inputs, input_sources, input_source_count, config, pinout);

    setup_mode_activation_bindings(config.game_mode_configs, config.game_mode_configs_count);
}

void loop() {
    select_mode(
        backends[0],
        config.game_mode_configs,
        config.game_mode_configs_count,
        config.keyboard_modes,
        config.keyboard_modes_count
    );

    for (size_t i = 0; i < backend_count; i++) {
        backends[i]->SendReport();
    }

    if (current_kb_mode != nullptr) {
        current_kb_mode->SendReport(backends[0]->GetInputs());
    }
}
