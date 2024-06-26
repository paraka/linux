/*
 * Copyright 2024 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 */

#ifndef __DC_VPG_H__
#define __DC_VPG_H__

struct dc_context;
struct dc_info_packet;

struct vpg;

struct vpg_funcs {
	void (*update_generic_info_packet)(
		struct vpg *vpg,
		uint32_t packet_index,
		const struct dc_info_packet *info_packet,
		bool immediate_update);

	void (*vpg_poweron)(
		struct vpg *vpg);

	void (*vpg_powerdown)(
		struct vpg *vpg);
};

struct vpg {
	const struct vpg_funcs *funcs;
	struct dc_context *ctx;
	int inst;
};

#endif /* DC_INC_VPG_H_ */