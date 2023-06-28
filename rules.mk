# Convert from Elite-C to standard RP2040.
CONVERT_TO = promicro_rp2040

# Ensure compatibility with the rp2040 bootloader.
BOOTLOADER = rp2040

CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
REPEAT_KEY_ENABLE = yes

SRC += swapper.c
SRC += features/achordion.c
