/*
 * Copyright (C) 2016 Socionext Inc.
 *   Author: Masahiro Yamada <yamada.masahiro@socionext.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __MATSUSHITA_COMMON_H__
#define __MATSUSHITA_COMMON_H__

#define MATSU_SD_CMD			0x000	/* command */
#define   MATSU_SD_CMD_NOSTOP		BIT(14)	/* No automatic CMD12 issue */
#define   MATSU_SD_CMD_MULTI		BIT(13)	/* multiple block transfer */
#define   MATSU_SD_CMD_RD		BIT(12)	/* 1: read, 0: write */
#define   MATSU_SD_CMD_DATA		BIT(11)	/* data transfer */
#define   MATSU_SD_CMD_APP		BIT(6)	/* ACMD preceded by CMD55 */
#define   MATSU_SD_CMD_NORMAL		(0 << 8)/* auto-detect of resp-type */
#define   MATSU_SD_CMD_RSP_NONE		(3 << 8)/* response: none */
#define   MATSU_SD_CMD_RSP_R1		(4 << 8)/* response: R1, R5, R6, R7 */
#define   MATSU_SD_CMD_RSP_R1B		(5 << 8)/* response: R1b, R5b */
#define   MATSU_SD_CMD_RSP_R2		(6 << 8)/* response: R2 */
#define   MATSU_SD_CMD_RSP_R3		(7 << 8)/* response: R3, R4 */
#define MATSU_SD_ARG			0x008	/* command argument */
#define MATSU_SD_STOP			0x010	/* stop action control */
#define   MATSU_SD_STOP_SEC		BIT(8)	/* use sector count */
#define   MATSU_SD_STOP_STP		BIT(0)	/* issue CMD12 */
#define MATSU_SD_SECCNT			0x014	/* sector counter */
#define MATSU_SD_RSP10			0x018	/* response[39:8] */
#define MATSU_SD_RSP32			0x020	/* response[71:40] */
#define MATSU_SD_RSP54			0x028	/* response[103:72] */
#define MATSU_SD_RSP76			0x030	/* response[127:104] */
#define MATSU_SD_INFO1			0x038	/* IRQ status 1 */
#define   MATSU_SD_INFO1_CD		BIT(5)	/* state of card detect */
#define   MATSU_SD_INFO1_INSERT		BIT(4)	/* card inserted */
#define   MATSU_SD_INFO1_REMOVE		BIT(3)	/* card removed */
#define   MATSU_SD_INFO1_CMP		BIT(2)	/* data complete */
#define   MATSU_SD_INFO1_RSP		BIT(0)	/* response complete */
#define MATSU_SD_INFO2			0x03c	/* IRQ status 2 */
#define   MATSU_SD_INFO2_ERR_ILA	BIT(15)	/* illegal access err */
#define   MATSU_SD_INFO2_CBSY		BIT(14)	/* command busy */
#define   MATSU_SD_INFO2_SCLKDIVEN	BIT(13)	/* command setting reg ena */
#define   MATSU_SD_INFO2_BWE		BIT(9)	/* write buffer ready */
#define   MATSU_SD_INFO2_BRE		BIT(8)	/* read buffer ready */
#define   MATSU_SD_INFO2_DAT0		BIT(7)	/* SDDAT0 */
#define   MATSU_SD_INFO2_ERR_RTO	BIT(6)	/* response time out */
#define   MATSU_SD_INFO2_ERR_ILR	BIT(5)	/* illegal read err */
#define   MATSU_SD_INFO2_ERR_ILW	BIT(4)	/* illegal write err */
#define   MATSU_SD_INFO2_ERR_TO		BIT(3)	/* time out error */
#define   MATSU_SD_INFO2_ERR_END	BIT(2)	/* END bit error */
#define   MATSU_SD_INFO2_ERR_CRC	BIT(1)	/* CRC error */
#define   MATSU_SD_INFO2_ERR_IDX	BIT(0)	/* cmd index error */
#define MATSU_SD_INFO1_MASK		0x040
#define MATSU_SD_INFO2_MASK		0x044
#define MATSU_SD_CLKCTL			0x048	/* clock divisor */
#define   MATSU_SD_CLKCTL_DIV_MASK	0x104ff
#define   MATSU_SD_CLKCTL_DIV1024	BIT(16)	/* SDCLK = CLK / 1024 */
#define   MATSU_SD_CLKCTL_DIV512	BIT(7)	/* SDCLK = CLK / 512 */
#define   MATSU_SD_CLKCTL_DIV256	BIT(6)	/* SDCLK = CLK / 256 */
#define   MATSU_SD_CLKCTL_DIV128	BIT(5)	/* SDCLK = CLK / 128 */
#define   MATSU_SD_CLKCTL_DIV64		BIT(4)	/* SDCLK = CLK / 64 */
#define   MATSU_SD_CLKCTL_DIV32		BIT(3)	/* SDCLK = CLK / 32 */
#define   MATSU_SD_CLKCTL_DIV16		BIT(2)	/* SDCLK = CLK / 16 */
#define   MATSU_SD_CLKCTL_DIV8		BIT(1)	/* SDCLK = CLK / 8 */
#define   MATSU_SD_CLKCTL_DIV4		BIT(0)	/* SDCLK = CLK / 4 */
#define   MATSU_SD_CLKCTL_DIV2		0	/* SDCLK = CLK / 2 */
#define   MATSU_SD_CLKCTL_DIV1		BIT(10)	/* SDCLK = CLK */
#define   MATSU_SD_CLKCTL_RCAR_DIV1	0xff	/* SDCLK = CLK (RCar ver.) */
#define   MATSU_SD_CLKCTL_OFFEN		BIT(9)	/* stop SDCLK when unused */
#define   MATSU_SD_CLKCTL_SCLKEN	BIT(8)	/* SDCLK output enable */
#define MATSU_SD_SIZE			0x04c	/* block size */
#define MATSU_SD_OPTION			0x050
#define   MATSU_SD_OPTION_WIDTH_MASK	(5 << 13)
#define   MATSU_SD_OPTION_WIDTH_1	(4 << 13)
#define   MATSU_SD_OPTION_WIDTH_4	(0 << 13)
#define   MATSU_SD_OPTION_WIDTH_8	(1 << 13)
#define MATSU_SD_BUF			0x060	/* read/write buffer */
#define MATSU_SD_EXTMODE		0x1b0
#define   MATSU_SD_EXTMODE_DMA_EN	BIT(1)	/* transfer 1: DMA, 0: pio */
#define MATSU_SD_SOFT_RST		0x1c0
#define MATSU_SD_SOFT_RST_RSTX		BIT(0)	/* reset deassert */
#define MATSU_SD_VERSION		0x1c4	/* version register */
#define MATSU_SD_VERSION_IP		0xff	/* IP version */
#define MATSU_SD_HOST_MODE		0x1c8
#define MATSU_SD_IF_MODE		0x1cc
#define   MATSU_SD_IF_MODE_DDR		BIT(0)	/* DDR mode */
#define MATSU_SD_VOLT			0x1e4	/* voltage switch */
#define   MATSU_SD_VOLT_MASK		(3 << 0)
#define   MATSU_SD_VOLT_OFF		(0 << 0)
#define   MATSU_SD_VOLT_330		(1 << 0)/* 3.3V signal */
#define   MATSU_SD_VOLT_180		(2 << 0)/* 1.8V signal */
#define MATSU_SD_DMA_MODE		0x410
#define   MATSU_SD_DMA_MODE_DIR_RD	BIT(16)	/* 1: from device, 0: to dev */
#define   MATSU_SD_DMA_MODE_ADDR_INC	BIT(0)	/* 1: address inc, 0: fixed */
#define MATSU_SD_DMA_CTL		0x414
#define   MATSU_SD_DMA_CTL_START	BIT(0)	/* start DMA (auto cleared) */
#define MATSU_SD_DMA_RST		0x418
#define   MATSU_SD_DMA_RST_RD		BIT(9)
#define   MATSU_SD_DMA_RST_WR		BIT(8)
#define MATSU_SD_DMA_INFO1		0x420
#define   MATSU_SD_DMA_INFO1_END_RD2	BIT(20)	/* DMA from device is complete (uniphier) */
#define   MATSU_SD_DMA_INFO1_END_RD	BIT(17)	/* DMA from device is complete (renesas) */
#define   MATSU_SD_DMA_INFO1_END_WR	BIT(16)	/* DMA to device is complete */
#define MATSU_SD_DMA_INFO1_MASK		0x424
#define MATSU_SD_DMA_INFO2		0x428
#define   MATSU_SD_DMA_INFO2_ERR_RD	BIT(17)
#define   MATSU_SD_DMA_INFO2_ERR_WR	BIT(16)
#define MATSU_SD_DMA_INFO2_MASK		0x42c
#define MATSU_SD_DMA_ADDR_L		0x440
#define MATSU_SD_DMA_ADDR_H		0x444

/* alignment required by the DMA engine of this controller */
#define MATSU_SD_DMA_MINALIGN		0x10

struct matsu_sd_plat {
	struct mmc_config		cfg;
	struct mmc			mmc;
};

struct matsu_sd_priv {
	void __iomem			*regbase;
	unsigned long			mclk;
	unsigned int			version;
	u32				caps;
#define MATSU_SD_CAP_NONREMOVABLE	BIT(0)	/* Nonremovable e.g. eMMC */
#define MATSU_SD_CAP_DMA_INTERNAL	BIT(1)	/* have internal DMA engine */
#define MATSU_SD_CAP_DIV1024		BIT(2)	/* divisor 1024 is available */
#define MATSU_SD_CAP_64BIT		BIT(3)	/* Controller is 64bit */
#define MATSU_SD_CAP_16BIT		BIT(4)	/* Controller is 16bit */
#define MATSU_SD_CAP_RCAR_GEN2		BIT(5)	/* Renesas RCar version of IP */
#define MATSU_SD_CAP_RCAR_GEN3		BIT(6)	/* Renesas RCar version of IP */
#define MATSU_SD_CAP_RCAR_UHS		BIT(7)	/* Renesas RCar UHS/SDR modes */
#define MATSU_SD_CAP_RCAR		\
	(MATSU_SD_CAP_RCAR_GEN2 | MATSU_SD_CAP_RCAR_GEN3)
#ifdef CONFIG_DM_REGULATOR
	struct udevice *vqmmc_dev;
#endif
};

int matsu_sd_send_cmd(struct udevice *dev, struct mmc_cmd *cmd,
		      struct mmc_data *data);
int matsu_sd_set_ios(struct udevice *dev);
int matsu_sd_get_cd(struct udevice *dev);

int matsu_sd_bind(struct udevice *dev);
int matsu_sd_probe(struct udevice *dev, u32 quirks);

u32 matsu_sd_readl(struct matsu_sd_priv *priv, unsigned int reg);
void matsu_sd_writel(struct matsu_sd_priv *priv,
		     u32 val, unsigned int reg);

#endif /* __MATSUSHITA_COMMON_H__ */
