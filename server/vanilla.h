#ifndef VANILLA_SERVER_H
#define VANILLA_SERVER_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#define VANILLA_SUCCESS              0
#define VANILLA_ERROR               -1
#define VANILLA_READY               -2
#define VANILLA_INFO                -3
#define VANILLA_UNKNOWN_COMMAND     -4
#define VANILLA_INVALID_ARGUMENT    -5

enum VanillaGamepadButtons {
    VANILLA_BTN_A = 1,
    VANILLA_BTN_B,
    VANILLA_BTN_X,
    VANILLA_BTN_Y,
    VANILLA_BTN_L,
    VANILLA_BTN_R,
    VANILLA_BTN_ZL,
    VANILLA_BTN_ZR,
    VANILLA_BTN_MINUS,
    VANILLA_BTN_PLUS,
    VANILLA_BTN_HOME,
    VANILLA_BTN_L3,
    VANILLA_BTN_R3,
    VANILLA_BTN_LEFT,
    VANILLA_BTN_RIGHT,
    VANILLA_BTN_DOWN,
    VANILLA_BTN_UP
};

enum VanillaGamepadAxes {
    VANILLA_AXIS_L_X = 1,
    VANILLA_AXIS_L_Y,
    VANILLA_AXIS_R_X,
    VANILLA_AXIS_R_Y
};

enum VanillaEvent
{
    VANILLA_EVENT_VIDEO,
    VANILLA_EVENT_AUDIO
};

/**
 * Event handler used by caller to receive events
 */
typedef void (*vanilla_event_handler_t)(void *context, int event_type, const char *data, size_t data_size);

/**
 * Attempt to sync with the console
 */
int vanilla_sync_with_console(const char *wireless_interface, uint16_t code);  

/**
 * Attempt gameplay connection with console
 */
int vanilla_connect_to_console(const char *wireless_interface, vanilla_event_handler_t event_handler, void *context);

/**
 * Attempt to stop the current action
 * 
 * This can be called from another thread to safely exit a blocking call to vanilla_sync_with_console() or vanilla_connect_to_console().
 */
void vanilla_stop();

/**
 * Set digital button state
 */
void vanilla_set_button(int button_id, int pressed);

/**
 * Set analog axis state
 */
void vanilla_set_axis(int axis_id, float value);

#if defined(__cplusplus)
}
#endif

#endif // VANILLA_SERVER_H