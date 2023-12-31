## SPDX-License-Identifier: GPL-2.0-only

SPD_SOURCES  = empty                            # 0b0000
SPD_SOURCES += samsung_dimm_K4E8E324EB-EGCF     # 0b0001
SPD_SOURCES += hynix_dimm_H9CCNNN8GTALAR-NUD    # 0b0010
SPD_SOURCES += samsung_dimm_K4E6E304EB-EGCF     # 0b0011
SPD_SOURCES += hynix_dimm_H9CCNNNBJTALAR-NUD    # 0b0100
SPD_SOURCES += samsung_dimm_K4EBE304EC-EGCG     # 0b0101
SPD_SOURCES += hynix_dimm_H9CCNNNCLGALAR-NUD    # 0b0110
SPD_SOURCES += micron_dimm_MT52L512M32D2PF-107  # 0b0111
SPD_SOURCES += micron_dimm_MT52L1G32D4PG-107    # 0b1000
SPD_SOURCES += micron_dimm_MT52L256M32D1PF-107  # 0b1001
SPD_SOURCES += samsung_dimm_K4E6E304EC-EGCF     # 0b1010
SPD_SOURCES += samsung_dimm_K4EBE304EC-EGCF     # 0b1011
SPD_SOURCES += nayna_dimm_NT6CL256T32CM-H1      # 0b1100
SPD_SOURCES += samsung_dimm_K4E6E304ED-EGCG     # 0b1101
SPD_SOURCES += samsung_dimm_K4EBE304ED-EGCG     # 0b1110

bootblock-y += gpio.c

romstage-y += memory.c

ramstage-y += gpio.c
ramstage-y += nhlt.c
ramstage-y += mainboard.c
