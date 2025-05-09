/*
 * Copyright (c) 2017, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef _MSM_DRM_NOTIFY_H_
#define _MSM_DRM_NOTIFY_H_

#include <linux/notifier.h>

/* A hardware display blank change occurred */
#define MSM_DRM_EVENT_BLANK			0x01
/* A hardware display blank early change occurred */
#define MSM_DRM_EARLY_EVENT_BLANK		0x02

#ifdef CONFIG_MACH_XIAOMI_C3J
#define DRM_EARLY_EVENT_BLANK   0x01
#define DRM_EVENT_BLANK         0x02
#endif

enum {
	/* panel: power on */
	MSM_DRM_BLANK_UNBLANK,
#ifdef CONFIG_MACH_XIAOMI_F9S
	MSM_DRM_BLANK_LP1,
	MSM_DRM_BLANK_LP2,
	MSM_DRM_BLANK_STANDBY,
	MSM_DRM_BLANK_SUSPEND,
#endif
	/* panel: power off */
	MSM_DRM_BLANK_POWERDOWN,
};

#ifdef CONFIG_MACH_XIAOMI_C3J
enum {
	DRM_BLANK_UNBLANK = 0,
	DRM_BLANK_LP1,
	DRM_BLANK_LP2,
	DRM_BLANK_STANDBY,
	DRM_BLANK_SUSPEND,
	DRM_BLANK_POWERDOWN,
};
#endif

enum msm_drm_display_id {
	/* primary display */
	MSM_DRM_PRIMARY_DISPLAY,
	/* external display */
	MSM_DRM_EXTERNAL_DISPLAY,
	MSM_DRM_DISPLAY_MAX
};

struct msm_drm_notifier {
	enum msm_drm_display_id id;
	void *data;
};

#ifdef CONFIG_MACH_XIAOMI_C3J
struct drm_notify_data {
	bool is_primary;
	void *data;
};
#endif

int msm_drm_register_client(struct notifier_block *nb);
int msm_drm_unregister_client(struct notifier_block *nb);
#ifdef CONFIG_MACH_XIAOMI_F9S
int msm_drm_notifier_call_chain(unsigned long val, void *v);
#endif
#ifdef CONFIG_MACH_XIAOMI_C3J
int drm_register_client(struct notifier_block *nb);
int drm_unregister_client(struct notifier_block *nb);
int drm_notifier_call_chain(unsigned long val, void *v);
#endif

#endif
