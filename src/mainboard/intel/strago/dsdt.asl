/* SPDX-License-Identifier: GPL-2.0-only */

#include <acpi/acpi.h>
DefinitionBlock(
	"dsdt.aml",
	"DSDT",
	ACPI_DSDT_REV_2,
	OEM_ID,
	ACPI_TABLE_CREATOR,
	0x20110725
)
{
	#include <acpi/dsdt_top.asl>
	#include <acpi/platform.asl>
	#include <acpi/globalnvs.asl>
	#include <cpu/intel/common/acpi/cpu.asl>

	Scope (\_SB) {
		Device (PCI0)
		{
			#include <acpi/southcluster.asl>
			#include <acpi/dptf/cpu.asl>
			#include <acpi/lpe.asl>
		}

		/* Dynamic Platform Thermal Framework */
		#include "acpi/dptf.asl"
	}
	Scope (\_SB.PCI0)
	{
		Device (RP03)
		{
			Name (_ADR, 0x001C0002)
			OperationRegion(RPXX, PCI_Config, 0x00, 0x10)

			/* Wifi Device */
			#include <soc/intel/common/acpi/wifi.asl>
		}
	}
	#include <southbridge/intel/common/acpi/sleepstates.asl>

	#include "acpi/mainboard.asl"
}
