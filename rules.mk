# Convert from Elite-C to standard RP2040.
CONVERT_TO = promicro_rp2040

# Ensure compatibility with the rp2040 bootloader.
BOOTLOADER = rp2040

CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes

# Easy definition of combos.
VPATH +=  keyboards/gboards/

SRC += features/achordion.c
SRC += features/custom_shift_keys.c
