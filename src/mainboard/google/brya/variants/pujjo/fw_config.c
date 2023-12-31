/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <baseboard/gpio.h>
#include <baseboard/variants.h>
#include <console/console.h>
#include <fw_config.h>

static const struct pad_config lte_disable_pads[] = {
	/* A8  : WWAN_RF_DISABLE_ODL */
	PAD_NC(GPP_A8, NONE),
	/* A12 : WWAN_PCIE_WAKE_ODL */
	PAD_NC(GPP_A12, NONE),
	/* D5  : SRCCLKREQ0# ==> WWAN_CLKREQ_ODL */
	PAD_NC(GPP_D5, NONE),
	/* D6  : WWAN_EN */
	PAD_NC(GPP_D6, NONE),
	/* D15  : EN_PP2800_WCAM_X ==> WWAN_SAR_DETECT_2_ODL */
	PAD_NC(GPP_D15, NONE),
	/* F12 : WWAN_RST_L */
	PAD_NC_LOCK(GPP_F12, NONE, LOCK_CONFIG),
	/* H19 : SOC_I2C_SUB_INT_ODL */
	PAD_NC(GPP_H19, NONE),
	/* H21  : WCAM_MCLK_R ==> WWAN_PERST_L */
	PAD_NC_LOCK(GPP_H21, NONE, LOCK_CONFIG),
	/* H23 : WWAN_SAR_DETECT_ODL */
	PAD_NC(GPP_H23, NONE),
};

static const struct pad_config sd_disable_pads[] = {
	/* D8  : SD_CLKREQ_ODL */
	PAD_NC(GPP_D8, NONE),
	/* H12 : SD_PERST_L */
	PAD_NC_LOCK(GPP_H12, NONE, LOCK_CONFIG),
	/* H13 : EN_PP3300_SD_X */
	PAD_NC_LOCK(GPP_H13, NONE, LOCK_CONFIG),
};

static const struct pad_config stylus_disable_pads[] = {
	/* F13 : SOC_PEN_DETECT_R_ODL */
	PAD_NC_LOCK(GPP_F13, NONE, LOCK_CONFIG),
	/* F15 : SOC_PEN_DETECT_ODL */
	PAD_NC_LOCK(GPP_F15, NONE, LOCK_CONFIG),
};

void fw_config_gpio_padbased_override(struct pad_config *padbased_table)
{
	if (fw_config_probe(FW_CONFIG(LTE, LTE_ABSENT)) && fw_config_probe(FW_CONFIG(WWAN_5G, WWAN_5G_ABSENT))
	&& fw_config_probe(FW_CONFIG(LTE_EM060, LTE_EM060_ABSENT))) {
		printk(BIOS_INFO, "Disable LTE-related GPIO pins.\n");
		gpio_padbased_override(padbased_table, lte_disable_pads,
						ARRAY_SIZE(lte_disable_pads));
	}

	if (fw_config_probe(FW_CONFIG(SD_CARD, SD_ABSENT))) {
		printk(BIOS_INFO, "Disable SD card GPIO pins.\n");
		gpio_padbased_override(padbased_table, sd_disable_pads,
						ARRAY_SIZE(sd_disable_pads));
	}

	if (fw_config_probe(FW_CONFIG(STYLUS, STYLUS_ABSENT))) {
		printk(BIOS_INFO, "Disable Stylus GPIO pins.\n");
		gpio_padbased_override(padbased_table, stylus_disable_pads,
						ARRAY_SIZE(stylus_disable_pads));
	}
}
