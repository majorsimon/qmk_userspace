CONVERT_TO = promicro_rp2040
LTO_ENABLE = yes

SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
CONSOLE_ENABLE = no

MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
SPLIT_KEYBOARD = yes

RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
WS2812_DRIVER = vendor

ENCODER_ENABLE = yes
OLED_ENABLE = yes
WPM_ENABLE = yes

VIA_ENABLE = yes

ADOPT_LUNA = yes
ADOPT_XOMT = yes

SRC += rgb_matrix.c 
SRC += rgblight.c 
SRC += encoder.c 
SRC += luna.c
SRC += xomt.c 
SRC += oled.c 
