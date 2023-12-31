## SPDX-License-Identifier: GPL-2.0-or-later

bootblock-y += gpio.c
romstage-y += gpio.c

bootblock-y += early_init.c
romstage-y += early_init.c
ramstage-$(CONFIG_MAINBOARD_USE_LIBGFXINIT) += gma-mainboard.ads
