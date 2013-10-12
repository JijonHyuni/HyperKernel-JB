/*
 * OMAP4 Power domains framework
 *
 * Copyright (C) 2009-2011 Texas Instruments, Inc.
 * Copyright (C) 2009-2011 Nokia Corporation
 *
 * Abhijit Pagare (abhijitpagare@ti.com)
 * Benoit Cousson (b-cousson@ti.com)
 * Paul Walmsley (paul@pwsan.com)
 *
 * This file is automatically generated from the OMAP hardware databases.
 * We respectfully ask that any modifications to this file be coordinated
 * with the public linux-omap@vger.kernel.org mailing list and the
 * authors above to ensure that the autogeneration scripts are kept
 * up-to-date with the file contents.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/init.h>

#include "powerdomain.h"

#include "prcm-common.h"
#include "prcm44xx.h"
#include "prm-regbits-44xx.h"
#include "prm44xx.h"
#include "prcm_mpu44xx.h"

/* core_44xx_pwrdm: CORE power domain */
static struct powerdomain core_44xx_pwrdm = {
	.name		  = "core_pwrdm",
	.voltdm		  = { .name = "core" },
	.prcm_offs	  = OMAP4430_PRM_CORE_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_RET_INA_ON,
	.pwrsts_logic_ret = PWRSTS_OFF_RET,
	.banks		  = 5,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_OFF,	/* core_nret_bank */
		[1] = PWRSTS_OFF_RET,	/* core_ocmram */
		[2] = PWRSTS_RET,	/* core_other_bank */
		[3] = PWRSTS_OFF_RET,	/* ducati_l2ram */
		[4] = PWRSTS_OFF_RET,	/* ducati_unicache */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* core_nret_bank */
		[1] = PWRSTS_OFF_RET,	/* core_ocmram */
		[2] = PWRSTS_ON,	/* core_other_bank */
		[3] = PWRSTS_ON,	/* ducati_l2ram */
		[4] = PWRSTS_ON,	/* ducati_unicache */
	},
	.flags		= PWRDM_HAS_LOWPOWERSTATECHANGE,
	.wakeup_lat = {
		[PWRDM_FUNC_PWRST_OFF] = UNSUP_STATE,
		[PWRDM_FUNC_PWRST_OSWR] = 600,
		[PWRDM_FUNC_PWRST_CSWR] = 300,
		[PWRDM_FUNC_PWRST_ON] = 0,
	},
};

/* gfx_44xx_pwrdm: 3D accelerator power domain */
static struct powerdomain gfx_44xx_pwrdm = {
	.name		  = "gfx_pwrdm",
	.voltdm		  = { .name = "core" },
	.prcm_offs	  = OMAP4430_PRM_GFX_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_OFF_INA_ON,
	.banks		  = 1,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_OFF,	/* gfx_mem */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* gfx_mem */
	},
	.flags		= PWRDM_HAS_LOWPOWERSTATECHANGE,
	.wakeup_lat = {
		[PWRDM_FUNC_PWRST_OFF] = 1000,
		[PWRDM_FUNC_PWRST_OSWR] = UNSUP_STATE,
		[PWRDM_FUNC_PWRST_CSWR] = UNSUP_STATE,
		[PWRDM_FUNC_PWRST_ON] = 0,
	},
};

/* abe_44xx_pwrdm: Audio back end power domain */
static struct powerdomain abe_44xx_pwrdm = {
	.name		  = "abe_pwrdm",
	.voltdm		  = { .name = "iva" },
	.prcm_offs	  = OMAP4430_PRM_ABE_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_OFF_RET_INA_ON,
	.banks		  = 2,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_RET,	/* aessmem */
		[1] = PWRSTS_OFF,	/* periphmem */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* aessmem */
		[1] = PWRSTS_ON,	/* periphmem */
	},
	.flags		= PWRDM_HAS_LOWPOWERSTATECHANGE,
	.wakeup_lat = {
		[PWRDM_FUNC_PWRST_OFF] = 1000,
		[PWRDM_FUNC_PWRST_OSWR] = 600,
		[PWRDM_FUNC_PWRST_CSWR] = 300,
		[PWRDM_FUNC_PWRST_ON] = 0,
	},
};

/* dss_44xx_pwrdm: Display subsystem power domain */
static struct powerdomain dss_44xx_pwrdm = {
	.name		  = "dss_pwrdm",
	.voltdm		  = { .name = "core" },
	.prcm_offs	  = OMAP4430_PRM_DSS_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_OFF_RET_INA_ON,
	.banks		  = 1,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_OFF,	/* dss_mem */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* dss_mem */
	},
	.flags		= PWRDM_HAS_LOWPOWERSTATECHANGE,
	.wakeup_lat = {
		[PWRDM_FUNC_PWRST_OFF] = 1000,
		[PWRDM_FUNC_PWRST_OSWR] = UNSUP_STATE,
		[PWRDM_FUNC_PWRST_CSWR] = 300,
		[PWRDM_FUNC_PWRST_ON] = 0,
	},
};

/* tesla_44xx_pwrdm: Tesla processor power domain */
static struct powerdomain tesla_44xx_pwrdm = {
	.name		  = "tesla_pwrdm",
	.voltdm		  = { .name = "iva" },
	.prcm_offs	  = OMAP4430_PRM_TESLA_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_OFF_RET_INA_ON,
	.pwrsts_logic_ret = PWRSTS_OFF_RET,
	.banks		  = 3,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_RET,	/* tesla_edma */
		[1] = PWRSTS_OFF_RET,	/* tesla_l1 */
		[2] = PWRSTS_OFF_RET,	/* tesla_l2 */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* tesla_edma */
		[1] = PWRSTS_ON,	/* tesla_l1 */
		[2] = PWRSTS_ON,	/* tesla_l2 */
	},
	.flags		= PWRDM_HAS_LOWPOWERSTATECHANGE,
	.wakeup_lat = {
		[PWRDM_FUNC_PWRST_OFF] = 1000,
		[PWRDM_FUNC_PWRST_OSWR] = 600,
		[PWRDM_FUNC_PWRST_CSWR] = 300,
		[PWRDM_FUNC_PWRST_ON] = 0,
	},
};

/* wkup_44xx_pwrdm: Wake-up power domain */
static struct powerdomain wkup_44xx_pwrdm = {
	.name		  = "wkup_pwrdm",
	.voltdm		  = { .name = "wakeup" },
	.prcm_offs	  = OMAP4430_PRM_WKUP_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_ON,
	.banks		  = 1,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_OFF,	/* wkup_bank */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* wkup_bank */
	},
};

/* cpu0_44xx_pwrdm: MPU0 processor and Neon coprocessor power domain */
static struct powerdomain cpu0_44xx_pwrdm = {
	.name		  = "cpu0_pwrdm",
	.voltdm		  = { .name = "mpu" },
	.prcm_offs	  = OMAP4430_PRCM_MPU_CPU0_INST,
	.prcm_partition	  = OMAP4430_PRCM_MPU_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_OFF_RET_INA_ON,
	.pwrsts_logic_ret = PWRSTS_OFF_RET,
	.banks		  = 1,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_OFF_RET,	/* cpu0_l1 */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* cpu0_l1 */
	},
	.wakeup_lat = {
		[PWRDM_FUNC_PWRST_OFF] = 1000,
		[PWRDM_FUNC_PWRST_OSWR] = 600,
		[PWRDM_FUNC_PWRST_CSWR] = 300,
		[PWRDM_FUNC_PWRST_ON] = 0,
	},
};

/* cpu1_44xx_pwrdm: MPU1 processor and Neon coprocessor power domain */
static struct powerdomain cpu1_44xx_pwrdm = {
	.name		  = "cpu1_pwrdm",
	.voltdm		  = { .name = "mpu" },
	.prcm_offs	  = OMAP4430_PRCM_MPU_CPU1_INST,
	.prcm_partition	  = OMAP4430_PRCM_MPU_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_OFF_RET_INA_ON,
	.pwrsts_logic_ret = PWRSTS_OFF_RET,
	.banks		  = 1,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_OFF_RET,	/* cpu1_l1 */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* cpu1_l1 */
	},
	.wakeup_lat = {
		[PWRDM_FUNC_PWRST_OFF] = 1000,
		[PWRDM_FUNC_PWRST_OSWR] = 600,
		[PWRDM_FUNC_PWRST_CSWR] = 300,
		[PWRDM_FUNC_PWRST_ON] = 0,
	},
};

/* emu_44xx_pwrdm: Emulation power domain */
static struct powerdomain emu_44xx_pwrdm = {
	.name		  = "emu_pwrdm",
	.voltdm		  = { .name = "wakeup" },
	.prcm_offs	  = OMAP4430_PRM_EMU_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.banks		  = 1,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_OFF,	/* emu_bank */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* emu_bank */
	},
};

/* mpu_44xx_pwrdm: Modena processor and the Neon coprocessor power domain */
static struct powerdomain mpu_443x_pwrdm = {
	.name		  = "mpu_pwrdm",
	.voltdm		  = { .name = "mpu" },
	.prcm_offs	  = OMAP4430_PRM_MPU_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP443X),
	.pwrsts		  = PWRSTS_OFF_RET_INA_ON,
	.pwrsts_logic_ret = PWRSTS_OFF_RET,
	.banks		  = 3,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_OFF_RET,	/* mpu_l1 */
		[1] = PWRSTS_OFF_RET,	/* mpu_l2 */
		[2] = PWRSTS_RET,	/* mpu_ram */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* mpu_l1 */
		[1] = PWRSTS_ON,	/* mpu_l2 */
		[2] = PWRSTS_ON,	/* mpu_ram */
	},
	.wakeup_lat = {
		[PWRDM_FUNC_PWRST_OFF] = 1000,
		[PWRDM_FUNC_PWRST_OSWR] = 600,
		[PWRDM_FUNC_PWRST_CSWR] = 300,
		[PWRDM_FUNC_PWRST_ON] = 0,
	},
};

static struct powerdomain mpu_446x_pwrdm = {
	.name		  = "mpu_pwrdm",
	.voltdm		  = { .name = "mpu" },
	.prcm_offs	  = OMAP4430_PRM_MPU_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP446X),
	.pwrsts		  = PWRSTS_RET_INA_ON,
	.pwrsts_logic_ret = PWRSTS_OFF_RET,
	.banks		  = 2,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_OFF_RET,	/* mpu_l2 */
		[1] = PWRSTS_RET,	/* mpu_ram */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* mpu_l2 */
		[1] = PWRSTS_ON,	/* mpu_ram */
	},
	.wakeup_lat = {
		[PWRDM_FUNC_PWRST_OFF] = 1000,
		[PWRDM_FUNC_PWRST_OSWR] = 600,
		[PWRDM_FUNC_PWRST_CSWR] = 300,
		[PWRDM_FUNC_PWRST_ON] = 0,
	},
};

/* ivahd_44xx_pwrdm: IVA-HD power domain */
static struct powerdomain ivahd_44xx_pwrdm = {
	.name		  = "ivahd_pwrdm",
	.voltdm		  = { .name = "iva" },
	.prcm_offs	  = OMAP4430_PRM_IVAHD_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_OFF_RET_INA_ON,
	.banks		  = 4,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_OFF,	/* hwa_mem */
		[1] = PWRSTS_OFF_RET,	/* sl2_mem */
		[2] = PWRSTS_OFF_RET,	/* tcm1_mem */
		[3] = PWRSTS_OFF_RET,	/* tcm2_mem */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* hwa_mem */
		[1] = PWRSTS_ON,	/* sl2_mem */
		[2] = PWRSTS_ON,	/* tcm1_mem */
		[3] = PWRSTS_ON,	/* tcm2_mem */
	},
	.flags		= PWRDM_HAS_LOWPOWERSTATECHANGE,
	.wakeup_lat = {
		[PWRDM_FUNC_PWRST_OFF] = 1000,
		[PWRDM_FUNC_PWRST_OSWR] = UNSUP_STATE,
		[PWRDM_FUNC_PWRST_CSWR] = 300,
		[PWRDM_FUNC_PWRST_ON] = 0,
	},
};

/* cam_44xx_pwrdm: Camera subsystem power domain */
static struct powerdomain cam_44xx_pwrdm = {
	.name		  = "cam_pwrdm",
	.voltdm		  = { .name = "core" },
	.prcm_offs	  = OMAP4430_PRM_CAM_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_OFF_INA_ON,
	.banks		  = 1,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_OFF,	/* cam_mem */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* cam_mem */
	},
	.flags		= PWRDM_HAS_LOWPOWERSTATECHANGE,
	.wakeup_lat = {
		[PWRDM_FUNC_PWRST_OFF] = 1000,
		[PWRDM_FUNC_PWRST_OSWR] = UNSUP_STATE,
		[PWRDM_FUNC_PWRST_CSWR] = UNSUP_STATE,
		[PWRDM_FUNC_PWRST_ON] = 0,
	},
};

/* l3init_44xx_pwrdm: L3 initators pheripherals power domain  */
static struct powerdomain l3init_44xx_pwrdm = {
	.name		  = "l3init_pwrdm",
	.voltdm		  = { .name = "core" },
	.prcm_offs	  = OMAP4430_PRM_L3INIT_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_RET_INA_ON,
	.pwrsts_logic_ret = PWRSTS_OFF_RET,
	.banks		  = 1,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_OFF,	/* l3init_bank1 */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* l3init_bank1 */
	},
	.flags		= PWRDM_HAS_LOWPOWERSTATECHANGE | PWRDM_HAS_HDWR_SAR,
	.wakeup_lat = {
		[PWRDM_FUNC_PWRST_OFF] = 1000,
		[PWRDM_FUNC_PWRST_OSWR] = 600,
		[PWRDM_FUNC_PWRST_CSWR] = 300,
		[PWRDM_FUNC_PWRST_ON] = 0,
	},
};

/* l4per_44xx_pwrdm: Target peripherals power domain */
static struct powerdomain l4per_44xx_pwrdm = {
	.name		  = "l4per_pwrdm",
	.voltdm		  = { .name = "core" },
	.prcm_offs	  = OMAP4430_PRM_L4PER_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_RET_INA_ON,
	.pwrsts_logic_ret = PWRSTS_OFF_RET,
	.banks		  = 2,
	.pwrsts_mem_ret	= {
		[0] = PWRSTS_OFF,	/* nonretained_bank */
		[1] = PWRSTS_RET,	/* retained_bank */
	},
	.pwrsts_mem_on	= {
		[0] = PWRSTS_ON,	/* nonretained_bank */
		[1] = PWRSTS_ON,	/* retained_bank */
	},
	.flags		= PWRDM_HAS_LOWPOWERSTATECHANGE,
	.wakeup_lat = {
		[PWRDM_FUNC_PWRST_OFF] = UNSUP_STATE,
		[PWRDM_FUNC_PWRST_OSWR] = 600,
		[PWRDM_FUNC_PWRST_CSWR] = 300,
		[PWRDM_FUNC_PWRST_ON] = 0,
	},
};

/*
 * always_on_core_44xx_pwrdm: Always ON logic that sits in VDD_CORE voltage
 * domain
 */
static struct powerdomain always_on_core_44xx_pwrdm = {
	.name		  = "always_on_core_pwrdm",
	.voltdm		  = { .name = "core" },
	.prcm_offs	  = OMAP4430_PRM_ALWAYS_ON_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_ON,
};

/* cefuse_44xx_pwrdm: Customer efuse controller power domain */
static struct powerdomain cefuse_44xx_pwrdm = {
	.name		  = "cefuse_pwrdm",
	.voltdm		  = { .name = "core" },
	.prcm_offs	  = OMAP4430_PRM_CEFUSE_INST,
	.prcm_partition	  = OMAP4430_PRM_PARTITION,
	.omap_chip	  = OMAP_CHIP_INIT(CHIP_IS_OMAP44XX),
	.pwrsts		  = PWRSTS_OFF_INA_ON,
};

/*
 * The following power domains are not under SW control
 *
 * always_on_iva
 * always_on_mpu
 * stdefuse
 */

/* As powerdomains are added or removed above, this list must also be changed */
static struct powerdomain *powerdomains_omap44xx[] __initdata = {
	&core_44xx_pwrdm,
	&gfx_44xx_pwrdm,
	&abe_44xx_pwrdm,
	&dss_44xx_pwrdm,
	&tesla_44xx_pwrdm,
	&wkup_44xx_pwrdm,
	&cpu0_44xx_pwrdm,
	&cpu1_44xx_pwrdm,
	&emu_44xx_pwrdm,
	&mpu_443x_pwrdm,
	&mpu_446x_pwrdm,
	&ivahd_44xx_pwrdm,
	&cam_44xx_pwrdm,
	&l3init_44xx_pwrdm,
	&l4per_44xx_pwrdm,
	&always_on_core_44xx_pwrdm,
	&cefuse_44xx_pwrdm,
	NULL
};

void __init omap44xx_powerdomains_init(void)
{
	pwrdm_init(powerdomains_omap44xx, &omap4_pwrdm_operations);
}
