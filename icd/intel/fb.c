/*
 * XGL
 *
 * Copyright (C) 2014 LunarG, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

#include "dev.h"
#include "obj.h"
#include "fb.h"

XGL_RESULT intel_fb_create(struct intel_dev *dev,
                           const XGL_FRAMEBUFFER_CREATE_INFO* info,
                           struct intel_framebuffer ** fb_ret)
{
    struct intel_framebuffer *fb;
    fb = (struct intel_framebuffer *) intel_base_create(dev, sizeof(*fb),
            dev->base.dbg, XGL_DBG_OBJECT_FRAMEBUFFER, info, 0);
    if (!fb)
        return XGL_ERROR_OUT_OF_MEMORY;
    //todo

    *fb_ret = fb;

    return XGL_SUCCESS;

}

XGL_RESULT intel_rp_create(struct intel_dev *dev,
                           const XGL_RENDER_PASS_CREATE_INFO* info,
                           struct intel_render_pass** rp_ret)
{
    struct intel_render_pass *rp;
    rp = (struct intel_render_pass *) intel_base_create(dev, sizeof(*rp),
            dev->base.dbg, XGL_DBG_OBJECT_RENDER_PASS, info, 0);
    if (!rp)
        return XGL_ERROR_OUT_OF_MEMORY;
    //todo

    *rp_ret = rp;

    return XGL_SUCCESS;
}

XGL_RESULT XGLAPI intelCreateFramebuffer(
    XGL_DEVICE                                  device,
    const XGL_FRAMEBUFFER_CREATE_INFO*          info,
    XGL_FRAMEBUFFER*                            fb_ret)
{
    struct intel_dev *dev = intel_dev(device);

    return intel_fb_create(dev, info, (struct intel_framebuffer **) fb_ret);
}


XGL_RESULT XGLAPI intelCreateRenderPass(
    XGL_DEVICE                                  device,
    const XGL_RENDER_PASS_CREATE_INFO*          info,
    XGL_RENDER_PASS*                            rp_ret)
{
    struct intel_dev *dev = intel_dev(device);

    return intel_rp_create(dev, info, (struct intel_render_pass **) rp_ret);
}



