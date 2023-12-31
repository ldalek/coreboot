/* SPDX-License-Identifier: GPL-2.0-only */

#include <mainboard/gpio.h>
#include <soc/gpio.h>

static const struct pad_config gpio_table[] = {
	/* ------- GPIO Group GPD ------- */
	PAD_CFG_NF(GPD0, UP_20K, PWROK, NF1), // PM_BATLOW#
	PAD_CFG_NF(GPD1, NATIVE, PWROK, NF1), // AC_PRESENT
	PAD_CFG_NF(GPD2, NONE, PWROK, NF1), // LAN_WAKEUP#
	PAD_CFG_NF(GPD3, UP_20K, PWROK, NF1), // PWR_BTN#
	PAD_CFG_NF(GPD4, NONE, PWROK, NF1), // SUSB#_PCH
	PAD_CFG_NF(GPD5, NONE, PWROK, NF1), // SUSC#_PCH
	PAD_CFG_NF(GPD6, NONE, PWROK, NF1), // SLP_A#
	PAD_CFG_GPO(GPD7, 0, PWROK), // GPD_7
	PAD_CFG_NF(GPD8, NONE, PWROK, NF1), // CNVI_SUSCLK
	PAD_CFG_NF(GPD9, NONE, PWROK, NF1), // SLP_WLAN#
	PAD_CFG_NF(GPD10, NONE, PWROK, NF1), // SLP_S5#
	PAD_CFG_NF(GPD11, NONE, PWROK, NF1), // LAN_DISABLE#
	_PAD_CFG_STRUCT(GPD12, 0x04000300, 0x0000), // TP_GPD12

	/* ------- GPIO Group GPP_A ------- */
	PAD_CFG_NF(GPP_A0, UP_20K, DEEP, NF1), // ESPI_IO0_EC
	PAD_CFG_NF(GPP_A1, UP_20K, DEEP, NF1), // ESPI_IO1_EC
	PAD_CFG_NF(GPP_A2, UP_20K, DEEP, NF1), // ESPI_IO2_EC
	PAD_CFG_NF(GPP_A3, UP_20K, DEEP, NF1), // ESPI_IO3_EC
	PAD_CFG_NF(GPP_A4, UP_20K, DEEP, NF1), // ESPI_CS_EC#
	PAD_CFG_NF(GPP_A5, DN_20K, DEEP, NF1), // ESPI_CLK_EC
	PAD_CFG_NF(GPP_A6, NONE, DEEP, NF1), // ESPI_RESET#
	PAD_CFG_NF(GPP_A7, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A8, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A9, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A10, UP_20K, DEEP, NF1), // SERIRQ_ESPI_ALERT0
	PAD_CFG_NF(GPP_A11, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A12, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_A13, UP_20K, DEEP, NF1),
	PAD_NC(GPP_A14, NONE),

	/* ------- GPIO Group GPP_B ------- */
	_PAD_CFG_STRUCT(GPP_B0, 0x40100100, 0x0000), // TPM_PIRQ#
	PAD_NC(GPP_B1, NONE), // 50k pull-upp to 3.3VA
	PAD_CFG_GPI(GPP_B2, NONE, DEEP), // CNVI_WAKE#
	PAD_CFG_GPO(GPP_B3, 1, DEEP), // BT_EN
	PAD_NC(GPP_B4, NONE),
	PAD_NC(GPP_B5, NONE), // Unpopulated pull-up and pull-down
	PAD_NC(GPP_B6, NONE),
	PAD_NC(GPP_B7, NONE),
	PAD_NC(GPP_B8, NONE),
	PAD_NC(GPP_B9, NONE),
	PAD_NC(GPP_B10, NONE),
	PAD_NC(GPP_B11, NONE), // Unpopulated jumper resistor to LAN_DISABLE#
	PAD_CFG_NF(GPP_B12, NONE, DEEP, NF1), // SLP_S0#
	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1), // PLT_RST#
	PAD_CFG_GPO(GPP_B14, 0, DEEP), // GPP_B14_SPKR
	PAD_CFG_GPI(GPP_B15, NONE, DEEP), // PS8461_SW_PCH
	PAD_NC(GPP_B16, NONE),
	PAD_NC(GPP_B17, NONE),
	PAD_CFG_NF(GPP_B18, NONE, RSMRST, NF1), // PCH_PMCALERT#
	PAD_CFG_GPO(GPP_B19, 1, DEEP), // PCH_WLAN_EN
	PAD_CFG_NF(GPP_B20, DN_20K, DEEP, NF1),
	_PAD_CFG_STRUCT(GPP_B21, 0x42880100, 0x0000), // GPP_B21_TBT_WAKE#
	PAD_CFG_GPO(GPP_B22, 1, DEEP), // LAN_PLT_RST#
	PAD_CFG_GPO(GPP_B23, 0, DEEP), // GPP_B23

	/* ------- GPIO Group GPP_C ------- */
	PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1), // SMB_CLK
	PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1), // SMB_DATA
	PAD_CFG_GPO(GPP_C2, 0, DEEP), // GPP_C2
	PAD_CFG_NF(GPP_C3, NONE, DEEP, NF3), // I2C2_SDA
	PAD_CFG_NF(GPP_C4, NONE, DEEP, NF3), // I2C2_SCL
	PAD_CFG_GPO(GPP_C5, 0, DEEP), // GPP_C5
	PAD_CFG_NF(GPP_C6, NONE, DEEP, NF2), // I2C3_SDA
	PAD_CFG_NF(GPP_C7, NONE, DEEP, NF2), // I2C3_SCL
	PAD_CFG_GPI(GPP_C8, NONE, DEEP), // TPM_DET
	PAD_NC(GPP_C9, NONE),
	PAD_CFG_GPO(GPP_C10, 1, DEEP), // M2_SSD1_PWR_EN
	PAD_CFG_GPO(GPP_C11, 1, DEEP), // M2_SSD2_PWR_EN
	PAD_NC(GPP_C12, NONE),
	PAD_NC(GPP_C13, NONE),
	PAD_NC(GPP_C14, NONE),
	PAD_NC(GPP_C15, NONE),
	PAD_CFG_NF(GPP_C16, NONE, DEEP, NF1), // I2C0_SDA_TP
	PAD_CFG_NF(GPP_C17, NONE, DEEP, NF1), // I2C0_SCL_TP
	PAD_CFG_NF(GPP_C18, NONE, DEEP, NF1), // PCH_I2C_SDA
	PAD_CFG_NF(GPP_C19, NONE, DEEP, NF1), // PCH_I2C_SCL
	// GPP_C20 (UART2_RXD) configured in bootblock
	// GPP_C21 (UART2_TXD) configured in bootblock
	PAD_NC(GPP_C22, NONE),
	PAD_NC(GPP_C23, NONE),

	/* ------- GPIO Group GPP_D ------- */
	PAD_NC(GPP_D0, NONE),
	PAD_NC(GPP_D1, NONE),
	PAD_NC(GPP_D2, NONE),
	PAD_NC(GPP_D3, NONE), // GFX_DETECT_STRAP
	PAD_NC(GPP_D4, NONE), // SML1_CLK
	PAD_CFG_GPO(GPP_D5, 1, DEEP), // CNVI_RF_RST#
	// GPP_D6 (XTAL_CLKREQ) configured by FSP
	PAD_NC(GPP_D7, NONE), // BT_PCMIN
	PAD_NC(GPP_D8, NONE), // BT_PCMCLK
	PAD_CFG_NF(GPP_D9, NATIVE, DEEP, NF1), // SML0_CLK
	PAD_CFG_NF(GPP_D10, NATIVE, DEEP, NF1), // SML0_DATA
	PAD_CFG_NF(GPP_D11, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_D12, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_D13, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_D14, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_D15, NATIVE, DEEP, NF1), // SML1_DATA
	PAD_CFG_NF(GPP_D16, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_D17, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_D18, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_D19, NATIVE, DEEP, NF1),
	PAD_CFG_NF(GPP_D20, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D21, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D22, NONE, DEEP, NF1),
	PAD_CFG_NF(GPP_D23, NONE, DEEP, NF1),

	/* ------- GPIO Group GPP_E ------- */
	PAD_NC(GPP_E0, NONE),
	PAD_NC(GPP_E1, NONE),
	PAD_NC(GPP_E2, NONE), // SWI#
	_PAD_CFG_STRUCT(GPP_E3, 0x42840101, 0x0000), // SMI#
	PAD_NC(GPP_E4, NONE),
	PAD_NC(GPP_E5, NONE),
	PAD_NC(GPP_E6, NONE),
	PAD_CFG_GPI_INT(GPP_E7, NONE, PLTRST, LEVEL), // TP_ATTN#
	PAD_CFG_NF(GPP_E8, NONE, DEEP, NF1), // SATA_LED#
	PAD_CFG_NF(GPP_E9, NONE, DEEP, NF1), // USB_OC#0
	PAD_CFG_NF(GPP_E10, NONE, DEEP, NF1), // USB_OC#1
	PAD_CFG_NF(GPP_E11, NONE, DEEP, NF1), // USB_OC#2
	PAD_CFG_NF(GPP_E12, NONE, DEEP, NF1), // USB_OC#3
	PAD_NC(GPP_E13, NONE),
	PAD_NC(GPP_E14, NONE),
	PAD_CFG_GPO(GPP_E15, 0, DEEP), // ROM_I2C_EN
	PAD_NC(GPP_E16, NONE),
	PAD_CFG_GPI(GPP_E17, DN_20K, DEEP), // SB_KBCRST#
	PAD_CFG_GPO(GPP_E18, 1, DEEP), // SB_BLON
	PAD_NC(GPP_E19, NONE),
	PAD_NC(GPP_E20, NONE),
	PAD_NC(GPP_E21, NONE),

	/* ------- GPIO Group GPP_F ------- */
	PAD_CFG_NF(GPP_F0, NONE, DEEP, NF2), // SATAGP3
	PAD_NC(GPP_F1, NONE),
	PAD_CFG_GPO(GPP_F2, 1, PLTRST), // GPP_F2_TBT_RST#
	PAD_CFG_GPO(GPP_F3, 1, PLTRST), // M2_SSD2_RST#
	PAD_CFG_GPO(GPP_F4, 1, PLTRST), // M2_SSD1_RST#
	PAD_CFG_NF(GPP_F5, NONE, DEEP, NF1), // SATA_DEVSLP3
	PAD_NC(GPP_F6, NONE),
	PAD_CFG_GPI(GPP_F7, NONE, PLTRST), // GPIO4_GC6_NVVDD_EN_R
	PAD_CFG_GPI(GPP_F8, NONE, DEEP), // GC6_FB_EN_PCH
	// GPP_F9 (DGPU_PWR_EN) configured in bootblock
	PAD_NC(GPP_F10, NONE), // GPP_F10
	PAD_NC(GPP_F11, NONE),
	PAD_NC(GPP_F12, NONE),
	PAD_NC(GPP_F13, NONE),
	PAD_CFG_NF(GPP_F14, NONE, DEEP, NF1), // Unpopulated jumper resistor to DGPU_PWR_EN
	PAD_CFG_GPI(GPP_F15, NONE, DEEP), // H_SKTOCC#
	PAD_NC(GPP_F16, NONE), // Test point T95
	PAD_CFG_GPI(GPP_F17, NONE, DEEP), // PLVDD_RST_EC
	PAD_CFG_GPO(GPP_F18, 0, PLTRST), // CCD_FW_WP#
	PAD_CFG_NF(GPP_F19, NONE, DEEP, NF1), // NB_ENAVDD
	PAD_CFG_NF(GPP_F20, NONE, DEEP, NF1), // BLON
	PAD_CFG_NF(GPP_F21, NONE, DEEP, NF1), // EDP_BRIGHTNESS
	PAD_NC(GPP_F22, NONE),
	PAD_NC(GPP_F23, NONE),

	/* ------- GPIO Group GPP_G ------- */
	PAD_CFG_GPI(GPP_G0, NONE, DEEP), // BOARD_ID1
	PAD_CFG_GPI(GPP_G1, NONE, DEEP), // BOARD_ID2
	PAD_CFG_NF(GPP_G2, DN_20K, DEEP, NF1), // Unpopulated 20k pull-down
	PAD_CFG_GPI(GPP_G3, NONE, DEEP), // BOARD_ID3
	PAD_CFG_GPI(GPP_G4, NONE, DEEP), // BOARD_ID4
	PAD_CFG_NF(GPP_G5, NONE, DEEP, NF1), // SLP_DRAM#
	PAD_CFG_GPI(GPP_G6, NONE, DEEP), // BOARD_ID5
	PAD_CFG_GPI(GPP_G7, NONE, DEEP), // MUX_CTRL_BIOS

	/* ------- GPIO Group GPP_H ------- */
	PAD_NC(GPP_H0, NONE), // GPP_H0
	PAD_CFG_GPI(GPP_H1, NONE, DEEP), // WLAN_WAKE#
	PAD_CFG_NF(GPP_H2, NONE, DEEP, NF1), // SSD2_CLKREQ#
	PAD_NC(GPP_H3, NONE),
	// GPP_H4 (SSD1_CLKREQ#) configured by FSP
	// GPP_H5 (WLAN_CLKREQ#) configured by FSP
	// GPP_H6 (CARD_CLKREQ#) configured by FSP
	// GPP_H7 (LAN_CLKREQ#) configured by FSP
	// GPP_H8 (PEG_CLKREQ#) configured by FSP
	// GPP_H9 (TBT_CLKREQ#) configured by FSP
	PAD_CFG_NF(GPP_H10, NONE, PLTRST, NF1), // GPP_H10_SML2CLK
	PAD_CFG_NF(GPP_H11, NONE, PLTRST, NF1), // GPP_H11_SML2DATA
	PAD_CFG_GPO(GPP_H12, 0, DEEP), // GPP_H12
	PAD_CFG_NF(GPP_H13, NONE, PLTRST, NF1), // GPP_H13_SML3CLK
	PAD_CFG_NF(GPP_H14, NONE, PLTRST, NF1), // GPP_H14_SML3DATA
	PAD_CFG_NF(GPP_H15, NONE, PLTRST, NF1), // GPP_H_15_SML3ALERT#
	PAD_CFG_NF(GPP_H16, NONE, PLTRST, NF1), // GPP_H16_SML4CLK
	PAD_CFG_GPO(GPP_H17, 1, PLTRST), // M2_WLAN_RST#
	PAD_CFG_GPO(GPP_H18, 0, DEEP), // GPP_H18
	PAD_NC(GPP_H19, NONE),
	PAD_NC(GPP_H20, NONE),
	PAD_CFG_GPO(GPP_H21, 0, DEEP), // TBT_MRESET_PCH
	PAD_CFG_GPO(GPP_H22, 0, DEEP), // CARD_RTD3_RST#
	PAD_NC(GPP_H23, NONE),

	/* ------- GPIO Group GPP_I ------- */
	PAD_CFG_GPI(GPP_I0, NONE, DEEP), // IN2_HPD
	PAD_CFG_NF(GPP_I1, NONE, DEEP, NF1), // DP_B_HPD
	_PAD_CFG_STRUCT(GPP_I2, 0x86800100, 0x0000), // GPU_DP_A_HPD
	PAD_CFG_NF(GPP_I3, NONE, DEEP, NF1), // DP_D_HPD
	_PAD_CFG_STRUCT(GPP_I4, 0x86800100, 0x0000), // HDMI_HPD
	PAD_CFG_GPO(GPP_I5, 1, PLTRST), // GPIO_TBT_RESET
	PAD_CFG_GPO(GPP_I6, 0, DEEP),
	PAD_NC(GPP_I7, NONE),
	PAD_CFG_GPO(GPP_I8, 0, DEEP),
	PAD_NC(GPP_I9, NONE),
	PAD_NC(GPP_I10, NONE),
	PAD_CFG_NF(GPP_I11, NONE, PLTRST, NF1), // USB_OC#4
	PAD_CFG_NF(GPP_I12, NONE, PLTRST, NF1), // USB_OC#5
	PAD_CFG_NF(GPP_I13, NONE, PLTRST, NF1), // EDP_MUX_I2C5_SDA
	PAD_CFG_NF(GPP_I14, NONE, PLTRST, NF1), // EDP_MUX_I2C5_SCL
	PAD_NC(GPP_I15, NONE),
	PAD_NC(GPP_I16, NONE),
	PAD_NC(GPP_I17, NONE),
	PAD_CFG_GPO(GPP_I18, 0, DEEP), // GPP_I18
	PAD_NC(GPP_I19, NONE),
	PAD_NC(GPP_I20, NONE),
	PAD_NC(GPP_I21, NONE),
	PAD_CFG_GPO(GPP_I22, 0, DEEP), // GPP_I22

	/* ------- GPIO Group GPP_J ------- */
	PAD_CFG_NF(GPP_J0, NONE, DEEP, NF1), // CNVI_GNSS_PA_BLANKING
	PAD_CFG_NF(GPP_J1, NONE, PLTRST, NF1), // CPU_C10_GATE#_EC
	PAD_CFG_NF(GPP_J2, NONE, DEEP, NF1), // CNVI_BRI_DT
	PAD_CFG_NF(GPP_J3, UP_20K, DEEP, NF1), // CNVI_BRI_RSP
	PAD_CFG_NF(GPP_J4, NONE, DEEP, NF1), // CNVI_RGI_DT
	PAD_CFG_NF(GPP_J5, UP_20K, DEEP, NF1), // CNVI_RGI_RSP
	PAD_CFG_NF(GPP_J6, NONE, DEEP, NF1), // CNVI_MFUART2_RXD
	PAD_CFG_NF(GPP_J7, NONE, DEEP, NF1), // CNVI_MFUART2_TXD
	PAD_NC(GPP_J8, NONE), // GPP_J8
	PAD_NC(GPP_J9, NONE), // Test point T93
	PAD_CFG_NF(GPP_J10, DN_20K, DEEP, NF1),
	PAD_CFG_NF(GPP_J11, DN_20K, DEEP, NF1),

	/* ------- GPIO Group GPP_K ------- */
	_PAD_CFG_STRUCT(GPP_K0, 0x42800100, 0x0000), // TBCIO_PLUG_EVENT#
	PAD_NC(GPP_K1, NONE),
	PAD_NC(GPP_K2, NONE),
	PAD_CFG_GPO(GPP_K3, 1, PLTRST), // TBT_RTD3_PWR_EN_R
	PAD_CFG_GPO(GPP_K4, 0, RSMRST), // TBT_FORCE_PWR_R
	PAD_NC(GPP_K5, NONE),
	PAD_CFG_NF(GPP_K6, UP_20K, DEEP, NF2), // Not in schematic
	PAD_CFG_NF(GPP_K7, DN_20K, DEEP, NF2), // Not in schematic
	PAD_CFG_NF(GPP_K8, NONE, DEEP, NF1), // VCCIN_AUX_VID0
	PAD_CFG_NF(GPP_K9, NONE, DEEP, NF1), // VCCIN_AUX_VID1
	PAD_CFG_NF(GPP_K10, UP_20K, DEEP, NF2), // Not in schematic
	PAD_NC(GPP_K11, NONE),

	/* ------- GPIO Group GPP_R ------- */
	PAD_CFG_NF(GPP_R0, NONE, DEEP, NF1), // HDA_BITCLK
	PAD_CFG_NF(GPP_R1, NATIVE, DEEP, NF1), // HDA_SYNC
	PAD_CFG_NF(GPP_R2, NATIVE, DEEP, NF1), // HDA_SDOUT
	PAD_CFG_NF(GPP_R3, NATIVE, DEEP, NF1), // HDA_SDIN0
	PAD_CFG_NF(GPP_R4, NONE, DEEP, NF1), // AZ_RST#_R
	PAD_NC(GPP_R5, NONE),
	PAD_NC(GPP_R6, NONE),
	PAD_NC(GPP_R7, NONE),
	PAD_CFG_GPI(GPP_R8, NONE, PLTRST), // DGPU_PWRGD_R
	PAD_CFG_NF(GPP_R9, NONE, DEEP, NF1), // PCH_EDP_HPD
	PAD_NC(GPP_R10, NONE),
	PAD_NC(GPP_R11, NONE),
	PAD_NC(GPP_R12, NONE),
	PAD_NC(GPP_R13, NONE),
	PAD_NC(GPP_R14, NONE),
	PAD_NC(GPP_R15, NONE),
	// GPP_R16 (DGPU_RST#_PCH) configured in bootblock
	PAD_NC(GPP_R17, NONE),
	PAD_NC(GPP_R18, NONE),
	PAD_NC(GPP_R19, NONE), // SCI#
	PAD_NC(GPP_R20, NONE),
	PAD_CFG_GPO(GPP_R21, 0, DEEP),

	/* ------- GPIO Group GPP_S ------- */
	PAD_NC(GPP_S0, NONE), // Test point T89
	PAD_NC(GPP_S1, NONE),
	PAD_NC(GPP_S2, NONE), // GPP_S2
	PAD_NC(GPP_S3, NONE),
	PAD_NC(GPP_S4, NONE),
	PAD_NC(GPP_S5, NONE),
	PAD_CFG_NF(GPP_S6, NONE, DEEP, NF2), // Unpopulated 33 ohm resistor to PCH_DMIC_CLK
	PAD_CFG_NF(GPP_S7, NONE, DEEP, NF2), // Unpopulated 33 ohm resistor to PCH_DMIC_DATA
};

void mainboard_configure_gpios(void)
{
	gpio_configure_pads(gpio_table, ARRAY_SIZE(gpio_table));
}
