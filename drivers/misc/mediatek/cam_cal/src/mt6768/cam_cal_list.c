/*
 * Copyright (C) 2018 MediaTek Inc.
 * Copyright (C) 2021 XiaoMi, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */
#include <linux/kernel.h>
#include "cam_cal_list.h"
#include "eeprom_i2c_common_driver.h"
#include "eeprom_i2c_custom_driver.h"
#include "kd_imgsensor.h"
#ifdef GC02M1_MIPI_RAW
//extern gc02m1_read_otp_info();
extern unsigned int gc02m1_read_otp_info(struct i2c_client *client,
	unsigned int addr,
	unsigned char *data,
	unsigned int size);
#endif
#ifdef GC02M1_SUNNY_MIPI_RAW
extern unsigned int gc02m1_sunny_read_otp_info(struct i2c_client *client,
	unsigned int addr,
	unsigned char *data,
	unsigned int size);
#endif

#ifdef CONFIG_TARGET_PRODUCT_LANCELOTCOMMON
#if defined(OV8856_QTECH_FRONT_MIPI_RAW)
extern unsigned int ov8856_qtech_front_read_otp_info(struct i2c_client *client, unsigned int addr, unsigned char *data, unsigned int size);
#endif
#endif

struct stCAM_CAL_LIST_STRUCT g_camCalList[] = {
	/*Below is commom sensor */
#ifdef CONFIG_TARGET_PRODUCT_LANCELOTCOMMON
	{OV13B10_OFILM_SENSOR_ID, 0xA2, Common_read_region},
	{OV13B10_QTECH_SENSOR_ID, 0xA2, Common_read_region},
	{S5K3L6_QTECH_SENSOR_ID, 0xA2, Common_read_region},
	{S5K4H7YX_OFILM_FRONT_SENSOR_ID, 0xA0, Common_read_region},
	{S5K4H7YX_OFILM_ULTRA_SENSOR_ID, 0xA8, Common_read_region},
	{OV8856_QTECH_ULTRA_SENSOR_ID, 0xA8, Common_read_region},
	{OV8856_QTECH_FRONT_SENSOR_ID, 0x6C, ov8856_qtech_front_read_otp_info},
	{GC5035_OFILM_SENSOR_ID, 0xA4, Common_read_region},
	{GC5035_QTECH_SENSOR_ID, 0xA4, Common_read_region},
#endif
	{IMX519_SENSOR_ID, 0xA0, Common_read_region},
	{S5K2T7SP_SENSOR_ID, 0xA4, Common_read_region},
	{IMX338_SENSOR_ID, 0xA0, Common_read_region},
	{S5K4E6_SENSOR_ID, 0xA8, Common_read_region},
	{IMX386_SENSOR_ID, 0xA0, Common_read_region},
	{S5K3M3_SENSOR_ID, 0xA0, Common_read_region},
	{S5K2L7_SENSOR_ID, 0xA0, Common_read_region},
	{IMX398_SENSOR_ID, 0xA0, Common_read_region},
	{IMX350_SENSOR_ID, 0xA0, Common_read_region},
	{IMX318_SENSOR_ID, 0xA0, Common_read_region},
	{IMX386_MONO_SENSOR_ID, 0xA0, Common_read_region},
	/*B+B. No Cal data for main2 OV8856*/
	{S5K2P7_SENSOR_ID, 0xA0, Common_read_region},
#ifdef CONFIG_TARGET_PRODUCT_MERLINCOMMON
	{S5KGM1SP_SENSOR_ID, 0xA0, Common_read_region},
	{S5KGM1SP_SUNNY_SENSOR_ID, 0xA0, Common_read_region},
	{OV13B10_SENSOR_ID, 0xA2, Common_read_region},
	{OV13B10_SUNNY_SENSOR_ID, 0xA2, Common_read_region},
	{S5K4H7YX_SENSOR_ID, 0xA2, Common_read_region},
	{S5K4H7YX_SUNNY_SENSOR_ID, 0xA2, Common_read_region},
	{OV2680_SUNNY_SENSOR_ID, 0xA0, Common_read_region},
	{OV2180_SENSOR_ID, 0xA4, Common_read_region},
	{OV2180_SUNNY_SENSOR_ID, 0xA4, Common_read_region},
	{GC02M1_MACRO_SENSOR_ID, 0xA0, Common_read_region},
	{GC02M1_MACRO_SUNNY_SENSOR_ID, 0xA0, Common_read_region},
	{S5KGM1SP_SENSOR_INDIA_ID, 0xA0, Common_read_region},
	{S5KGM1SP_SUNNY_SENSOR_INDIA_ID, 0xA0, Common_read_region},
	{OV13B10_SENSOR_INDIA_ID, 0xA2, Common_read_region},
	{OV13B10_SUNNY_SENSOR_INDIA_ID, 0xA2, Common_read_region},
	{S5K4H7YX_SENSOR_INDIA_ID, 0xA2, Common_read_region},
	{S5K4H7YX_SUNNY_SENSOR_INDIA_ID, 0xA2, Common_read_region},
	{OV2680_SUNNY_SENSOR_INDIA_ID, 0xA0, Common_read_region},
	{OV2180_SENSOR_INDIA_ID, 0xA4, Common_read_region},
	{OV2180_SUNNY_SENSOR_INDIA_ID, 0xA4, Common_read_region},
	{GC02M1_MACRO_SENSOR_INDIA_ID, 0xA0, Common_read_region},
	{GC02M1_MACRO_SUNNY_SENSOR_INDIA_ID, 0xA0, Common_read_region},
#ifdef GC02M1_MIPI_RAW
	{GC02M1_SENSOR_ID, 0x6E, gc02m1_read_otp_info},
	{GC02M1_SENSOR_INDIA_ID, 0x6E, gc02m1_read_otp_info},
#endif
#ifdef GC02M1_SUNNY_MIPI_RAW
	{GC02M1_SUNNY_SENSOR_ID, 0x6E, gc02m1_sunny_read_otp_info},
	{GC02M1_SUNNY_SENSOR_INDIA_ID, 0x6E, gc02m1_sunny_read_otp_info},
#endif
#endif
#ifdef SUPPORT_S5K4H7
	{S5K4H7_SENSOR_ID, 0xA0, zte_s5k4h7_read_region},
	{S5K4H7SUB_SENSOR_ID, 0xA0, zte_s5k4h7_sub_read_region},
#endif
	/*  ADD before this line */
	{0, 0, 0}       /*end of list */
};

unsigned int cam_cal_get_sensor_list(
	struct stCAM_CAL_LIST_STRUCT **ppCamcalList)
{
	if (ppCamcalList == NULL)
		return 1;

	*ppCamcalList = &g_camCalList[0];
	return 0;
}


