# MCU name

MCU          = atmega32u4
ARCH         = AVR8
BOARD        = LEONARDO
F_CPU        = 16000000
F_USB        = $(F_CPU)
BOOTLOADER = caterina


# Build Options
#   change yes to no to disable

MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
RGBLIGHT_ENABLE = yes        # Enable keyboard RGB underglow
SPLIT_KEYBOARD = yes
TAP_DANCE_ENABLE = yes
POINTING_DEVICE_ENABLE = yes
UNICODE_ENABLE = yes


SRC += trackball.c
