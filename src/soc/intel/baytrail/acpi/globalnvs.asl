/* SPDX-License-Identifier: GPL-2.0-only */

/* Global Variables */

Field (GNVS, ByteAcc, NoLock, Preserve)
{
	/* Miscellaneous */
	,	16,	/* 0x00 - Operating System */
	SMIF,	 8,	/* 0x02 - SMI function */
	,	 8,	/* 0x03 - SMI function parameter */
	,	 8,	/* 0x04 - SMI function parameter */
	SCIF,	 8,	/* 0x05 - SCI function */
	,	 8,	/* 0x06 - SCI function parameter */
	,	 8,	/* 0x07 - SCI function parameter */
	,	 8,	/* 0x08 - Global Lock function for EC */
	,	 8,	/* 0x09 - Lock function parameter */
	,	 8,	/* 0x0a - Lock function parameter */
	P80D,	32,	/* 0x0b - Debug port (IO 0x80) value */
	LIDS,	 8,	/* 0x0f - LID state (open = 1) */
	,	 8,	/* 0x10 - Power State (AC = 1) */
	,	 8,	/* 0x11 - Processor count */
	TPMP,	 8,	/* 0x12 - TPM Present and Enabled */
	TLVL,	 8,	/* 0x13 - Throttle Level */
	PPCM,	 8,	/* 0x14 - Maximum P-state usable by OS */
	PM1I,	 32,	/* 0x15 - System Wake Source - PM1 Index */
	GPEI,	 32,	/* 0x19 - GPE Wake Source */

	/* Device Config */
	Offset (0x20),
	S5U0,	 8,	/* 0x20 - Enable USB0 in S5 */
	S5U1,	 8,	/* 0x21 - Enable USB1 in S5 */
	S3U0,	 8,	/* 0x22 - Enable USB0 in S3 */
	S3U1,	 8,	/* 0x23 - Enable USB1 in S3 */
	TACT,	 8,	/* 0x24 - Thermal Active trip point */
	TPSV,	 8,	/* 0x25 - Thermal Passive trip point */
	TCRT,	 8,	/* 0x26 - Thermal Critical trip point */
	DPTE,	 8,	/* 0x27 - Enable DPTF */

	/* Base addresses */
	Offset (0x30),
	,	 32,	/* 0x30 - CBMEM TOC */
	,	 32,	/* 0x34 - Top of Low Memory */
	,	 32,	/* 0x38 - coreboot mem console pointer */
}
