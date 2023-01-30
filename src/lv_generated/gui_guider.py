# Copyright 2022 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=460,h=320)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(460*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 460
disp_drv.ver_res = 320
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)


home = lv.obj()
home.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_home_main_main_default
style_home_main_main_default = lv.style_t()
style_home_main_main_default.init()
style_home_main_main_default.set_bg_color(lv.color_make(0x1d,0x23,0x32))
style_home_main_main_default.set_bg_opa(255)

# add style for home
home.add_style(style_home_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_imgbtn_engraving = lv.imgbtn(home)
home_imgbtn_engraving.set_pos(int(38),int(112))
home_imgbtn_engraving.set_size(109,109)
home_imgbtn_engraving.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp1087032325.png','rb') as f:
        home_imgbtn_engraving_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp1087032325.png')
    sys.exit()

home_imgbtn_engraving_imgReleased = lv.img_dsc_t({
  'data_size': len(home_imgbtn_engraving_imgReleased_data),
  'header': {'always_zero': 0, 'w': 109, 'h': 109, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtn_engraving_imgReleased_data
})
home_imgbtn_engraving.set_src(lv.imgbtn.STATE.RELEASED, home_imgbtn_engraving_imgReleased, None, None)





home_imgbtn_engraving.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_home_imgbtn_engraving_main_main_default
style_home_imgbtn_engraving_main_main_default = lv.style_t()
style_home_imgbtn_engraving_main_main_default.init()
style_home_imgbtn_engraving_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_imgbtn_engraving_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_imgbtn_engraving_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_imgbtn_engraving_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_imgbtn_engraving_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_imgbtn_engraving_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_imgbtn_engraving_main_main_default.set_img_recolor_opa(0)
style_home_imgbtn_engraving_main_main_default.set_img_opa(255)

# add style for home_imgbtn_engraving
home_imgbtn_engraving.add_style(style_home_imgbtn_engraving_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_home_imgbtn_engraving_main_main_pressed
style_home_imgbtn_engraving_main_main_pressed = lv.style_t()
style_home_imgbtn_engraving_main_main_pressed.init()
style_home_imgbtn_engraving_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtn_engraving_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_imgbtn_engraving_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_imgbtn_engraving_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_home_imgbtn_engraving_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_imgbtn_engraving_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtn_engraving_main_main_pressed.set_img_recolor_opa(0)
style_home_imgbtn_engraving_main_main_pressed.set_img_opa(255)

# add style for home_imgbtn_engraving
home_imgbtn_engraving.add_style(style_home_imgbtn_engraving_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_home_imgbtn_engraving_main_main_checked
style_home_imgbtn_engraving_main_main_checked = lv.style_t()
style_home_imgbtn_engraving_main_main_checked.init()
style_home_imgbtn_engraving_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtn_engraving_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_imgbtn_engraving_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_imgbtn_engraving_main_main_checked.set_text_font(lv.font_montserrat_16)
style_home_imgbtn_engraving_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_imgbtn_engraving_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtn_engraving_main_main_checked.set_img_recolor_opa(0)
style_home_imgbtn_engraving_main_main_checked.set_img_opa(255)

# add style for home_imgbtn_engraving
home_imgbtn_engraving.add_style(style_home_imgbtn_engraving_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

home_imgbtn_control = lv.imgbtn(home)
home_imgbtn_control.set_pos(int(183),int(112))
home_imgbtn_control.set_size(109,109)
home_imgbtn_control.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp965377737.png','rb') as f:
        home_imgbtn_control_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp965377737.png')
    sys.exit()

home_imgbtn_control_imgReleased = lv.img_dsc_t({
  'data_size': len(home_imgbtn_control_imgReleased_data),
  'header': {'always_zero': 0, 'w': 109, 'h': 109, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtn_control_imgReleased_data
})
home_imgbtn_control.set_src(lv.imgbtn.STATE.RELEASED, home_imgbtn_control_imgReleased, None, None)





home_imgbtn_control.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_home_imgbtn_control_main_main_default
style_home_imgbtn_control_main_main_default = lv.style_t()
style_home_imgbtn_control_main_main_default.init()
style_home_imgbtn_control_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_imgbtn_control_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_imgbtn_control_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_imgbtn_control_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_imgbtn_control_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_imgbtn_control_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_imgbtn_control_main_main_default.set_img_recolor_opa(0)
style_home_imgbtn_control_main_main_default.set_img_opa(255)

# add style for home_imgbtn_control
home_imgbtn_control.add_style(style_home_imgbtn_control_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_home_imgbtn_control_main_main_pressed
style_home_imgbtn_control_main_main_pressed = lv.style_t()
style_home_imgbtn_control_main_main_pressed.init()
style_home_imgbtn_control_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtn_control_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_imgbtn_control_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_imgbtn_control_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_home_imgbtn_control_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_imgbtn_control_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtn_control_main_main_pressed.set_img_recolor_opa(0)
style_home_imgbtn_control_main_main_pressed.set_img_opa(255)

# add style for home_imgbtn_control
home_imgbtn_control.add_style(style_home_imgbtn_control_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_home_imgbtn_control_main_main_checked
style_home_imgbtn_control_main_main_checked = lv.style_t()
style_home_imgbtn_control_main_main_checked.init()
style_home_imgbtn_control_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtn_control_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_imgbtn_control_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_imgbtn_control_main_main_checked.set_text_font(lv.font_montserrat_16)
style_home_imgbtn_control_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_imgbtn_control_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtn_control_main_main_checked.set_img_recolor_opa(0)
style_home_imgbtn_control_main_main_checked.set_img_opa(255)

# add style for home_imgbtn_control
home_imgbtn_control.add_style(style_home_imgbtn_control_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

home_imgbtn_tools = lv.imgbtn(home)
home_imgbtn_tools.set_pos(int(323.5),int(112))
home_imgbtn_tools.set_size(109,109)
home_imgbtn_tools.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1190590388.png','rb') as f:
        home_imgbtn_tools_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1190590388.png')
    sys.exit()

home_imgbtn_tools_imgReleased = lv.img_dsc_t({
  'data_size': len(home_imgbtn_tools_imgReleased_data),
  'header': {'always_zero': 0, 'w': 109, 'h': 109, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_imgbtn_tools_imgReleased_data
})
home_imgbtn_tools.set_src(lv.imgbtn.STATE.RELEASED, home_imgbtn_tools_imgReleased, None, None)





home_imgbtn_tools.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_home_imgbtn_tools_main_main_default
style_home_imgbtn_tools_main_main_default = lv.style_t()
style_home_imgbtn_tools_main_main_default.init()
style_home_imgbtn_tools_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_imgbtn_tools_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_imgbtn_tools_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_imgbtn_tools_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_imgbtn_tools_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_imgbtn_tools_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_imgbtn_tools_main_main_default.set_img_recolor_opa(0)
style_home_imgbtn_tools_main_main_default.set_img_opa(255)

# add style for home_imgbtn_tools
home_imgbtn_tools.add_style(style_home_imgbtn_tools_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_home_imgbtn_tools_main_main_pressed
style_home_imgbtn_tools_main_main_pressed = lv.style_t()
style_home_imgbtn_tools_main_main_pressed.init()
style_home_imgbtn_tools_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtn_tools_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_imgbtn_tools_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_imgbtn_tools_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_home_imgbtn_tools_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_imgbtn_tools_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtn_tools_main_main_pressed.set_img_recolor_opa(0)
style_home_imgbtn_tools_main_main_pressed.set_img_opa(255)

# add style for home_imgbtn_tools
home_imgbtn_tools.add_style(style_home_imgbtn_tools_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_home_imgbtn_tools_main_main_checked
style_home_imgbtn_tools_main_main_checked = lv.style_t()
style_home_imgbtn_tools_main_main_checked.init()
style_home_imgbtn_tools_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_imgbtn_tools_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_imgbtn_tools_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_imgbtn_tools_main_main_checked.set_text_font(lv.font_montserrat_16)
style_home_imgbtn_tools_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_imgbtn_tools_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_imgbtn_tools_main_main_checked.set_img_recolor_opa(0)
style_home_imgbtn_tools_main_main_checked.set_img_opa(255)

# add style for home_imgbtn_tools
home_imgbtn_tools.add_style(style_home_imgbtn_tools_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

home_label_1 = lv.label(home)
home_label_1.set_pos(int(24),int(239))
home_label_1.set_size(137,20)
home_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_1.set_text("Engraving")
home_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_1_main_main_default
style_home_label_1_main_main_default = lv.style_t()
style_home_label_1_main_main_default.init()
style_home_label_1_main_main_default.set_radius(0)
style_home_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_1_main_main_default.set_bg_opa(0)
style_home_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_home_label_1_main_main_default.set_text_font(lv.font_montserratMedium_15)
except AttributeError:
    try:
        style_home_label_1_main_main_default.set_text_font(lv.font_montserrat_15)
    except AttributeError:
        style_home_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_1_main_main_default.set_text_letter_space(2)
style_home_label_1_main_main_default.set_text_line_space(0)
style_home_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_1_main_main_default.set_pad_left(0)
style_home_label_1_main_main_default.set_pad_right(0)
style_home_label_1_main_main_default.set_pad_top(0)
style_home_label_1_main_main_default.set_pad_bottom(0)

# add style for home_label_1
home_label_1.add_style(style_home_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_3 = lv.label(home)
home_label_3.set_pos(int(328),int(238))
home_label_3.set_size(100,23)
home_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_3.set_text("Tools")
home_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_3_main_main_default
style_home_label_3_main_main_default = lv.style_t()
style_home_label_3_main_main_default.init()
style_home_label_3_main_main_default.set_radius(0)
style_home_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_3_main_main_default.set_bg_opa(0)
style_home_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_home_label_3_main_main_default.set_text_font(lv.font_montserratMedium_15)
except AttributeError:
    try:
        style_home_label_3_main_main_default.set_text_font(lv.font_montserrat_15)
    except AttributeError:
        style_home_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_3_main_main_default.set_text_letter_space(2)
style_home_label_3_main_main_default.set_text_line_space(0)
style_home_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_3_main_main_default.set_pad_left(0)
style_home_label_3_main_main_default.set_pad_right(0)
style_home_label_3_main_main_default.set_pad_top(0)
style_home_label_3_main_main_default.set_pad_bottom(0)

# add style for home_label_3
home_label_3.add_style(style_home_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_2 = lv.label(home)
home_label_2.set_pos(int(187.5),int(239))
home_label_2.set_size(100,22)
home_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_2.set_text("Control")
home_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_2_main_main_default
style_home_label_2_main_main_default = lv.style_t()
style_home_label_2_main_main_default.init()
style_home_label_2_main_main_default.set_radius(0)
style_home_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_2_main_main_default.set_bg_opa(0)
style_home_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_home_label_2_main_main_default.set_text_font(lv.font_montserratMedium_15)
except AttributeError:
    try:
        style_home_label_2_main_main_default.set_text_font(lv.font_montserrat_15)
    except AttributeError:
        style_home_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_2_main_main_default.set_text_letter_space(2)
style_home_label_2_main_main_default.set_text_line_space(0)
style_home_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_2_main_main_default.set_pad_left(0)
style_home_label_2_main_main_default.set_pad_right(0)
style_home_label_2_main_main_default.set_pad_top(0)
style_home_label_2_main_main_default.set_pad_bottom(0)

# add style for home_label_2
home_label_2.add_style(style_home_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_4 = lv.label(home)
home_label_4.set_pos(int(158),int(50))
home_label_4.set_size(170,35)
home_label_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_4.set_text("MakeGo")
home_label_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_4_main_main_default
style_home_label_4_main_main_default = lv.style_t()
style_home_label_4_main_main_default.init()
style_home_label_4_main_main_default.set_radius(0)
style_home_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_4_main_main_default.set_bg_opa(0)
style_home_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_home_label_4_main_main_default.set_text_font(lv.font_Acme_Regular_30)
except AttributeError:
    try:
        style_home_label_4_main_main_default.set_text_font(lv.font_montserrat_30)
    except AttributeError:
        style_home_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_4_main_main_default.set_text_letter_space(2)
style_home_label_4_main_main_default.set_text_line_space(0)
style_home_label_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_4_main_main_default.set_pad_left(0)
style_home_label_4_main_main_default.set_pad_right(0)
style_home_label_4_main_main_default.set_pad_top(0)
style_home_label_4_main_main_default.set_pad_bottom(0)

# add style for home_label_4
home_label_4.add_style(style_home_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

logo = lv.obj()
logo.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_logo_main_main_default
style_logo_main_main_default = lv.style_t()
style_logo_main_main_default.init()
style_logo_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_logo_main_main_default.set_bg_opa(0)

# add style for logo
logo.add_style(style_logo_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

logo_image_logo = lv.img(logo)
logo_image_logo.set_pos(int(0),int(0))
logo_image_logo.set_size(460,320)
logo_image_logo.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
logo_image_logo.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp1970917059.png','rb') as f:
        logo_image_logo_img_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp1970917059.png')
    sys.exit()

logo_image_logo_img = lv.img_dsc_t({
  'data_size': len(logo_image_logo_img_data),
  'header': {'always_zero': 0, 'w': 460, 'h': 320, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': logo_image_logo_img_data
})

logo_image_logo.set_src(logo_image_logo_img)
logo_image_logo.set_pivot(0,0)
logo_image_logo.set_angle(0)
# create style style_logo_image_logo_main_main_default
style_logo_image_logo_main_main_default = lv.style_t()
style_logo_image_logo_main_main_default.init()
style_logo_image_logo_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_logo_image_logo_main_main_default.set_img_recolor_opa(0)
style_logo_image_logo_main_main_default.set_img_opa(255)

# add style for logo_image_logo
logo_image_logo.add_style(style_logo_image_logo_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

engraving = lv.obj()
engraving.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_engraving_main_main_default
style_engraving_main_main_default = lv.style_t()
style_engraving_main_main_default.init()
style_engraving_main_main_default.set_bg_color(lv.color_make(0x1d,0x23,0x32))
style_engraving_main_main_default.set_bg_opa(255)

# add style for engraving
engraving.add_style(style_engraving_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

engraving_imgbtn_1 = lv.imgbtn(engraving)
engraving_imgbtn_1.set_pos(int(30),int(62))
engraving_imgbtn_1.set_size(184,184)
engraving_imgbtn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp244035533.png','rb') as f:
        engraving_imgbtn_1_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp244035533.png')
    sys.exit()

engraving_imgbtn_1_imgReleased = lv.img_dsc_t({
  'data_size': len(engraving_imgbtn_1_imgReleased_data),
  'header': {'always_zero': 0, 'w': 184, 'h': 184, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': engraving_imgbtn_1_imgReleased_data
})
engraving_imgbtn_1.set_src(lv.imgbtn.STATE.RELEASED, engraving_imgbtn_1_imgReleased, None, None)





engraving_imgbtn_1.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_engraving_imgbtn_1_main_main_default
style_engraving_imgbtn_1_main_main_default = lv.style_t()
style_engraving_imgbtn_1_main_main_default.init()
style_engraving_imgbtn_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_engraving_imgbtn_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_engraving_imgbtn_1_main_main_default.set_img_recolor_opa(0)
style_engraving_imgbtn_1_main_main_default.set_img_opa(255)

# add style for engraving_imgbtn_1
engraving_imgbtn_1.add_style(style_engraving_imgbtn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_engraving_imgbtn_1_main_main_pressed
style_engraving_imgbtn_1_main_main_pressed = lv.style_t()
style_engraving_imgbtn_1_main_main_pressed.init()
style_engraving_imgbtn_1_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_imgbtn_1_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_1_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_1_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_imgbtn_1_main_main_pressed.set_img_recolor_opa(0)
style_engraving_imgbtn_1_main_main_pressed.set_img_opa(255)

# add style for engraving_imgbtn_1
engraving_imgbtn_1.add_style(style_engraving_imgbtn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_engraving_imgbtn_1_main_main_checked
style_engraving_imgbtn_1_main_main_checked = lv.style_t()
style_engraving_imgbtn_1_main_main_checked.init()
style_engraving_imgbtn_1_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_imgbtn_1_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_1_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_1_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_imgbtn_1_main_main_checked.set_img_recolor_opa(0)
style_engraving_imgbtn_1_main_main_checked.set_img_opa(255)

# add style for engraving_imgbtn_1
engraving_imgbtn_1.add_style(style_engraving_imgbtn_1_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

engraving_imgbtn_2 = lv.imgbtn(engraving)
engraving_imgbtn_2.set_pos(int(255),int(82))
engraving_imgbtn_2.set_size(206,33)
engraving_imgbtn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1049473358.png','rb') as f:
        engraving_imgbtn_2_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1049473358.png')
    sys.exit()

engraving_imgbtn_2_imgReleased = lv.img_dsc_t({
  'data_size': len(engraving_imgbtn_2_imgReleased_data),
  'header': {'always_zero': 0, 'w': 206, 'h': 33, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': engraving_imgbtn_2_imgReleased_data
})
engraving_imgbtn_2.set_src(lv.imgbtn.STATE.RELEASED, engraving_imgbtn_2_imgReleased, None, None)





engraving_imgbtn_2.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_engraving_imgbtn_2_main_main_default
style_engraving_imgbtn_2_main_main_default = lv.style_t()
style_engraving_imgbtn_2_main_main_default.init()
style_engraving_imgbtn_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_engraving_imgbtn_2_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_engraving_imgbtn_2_main_main_default.set_img_recolor_opa(0)
style_engraving_imgbtn_2_main_main_default.set_img_opa(255)

# add style for engraving_imgbtn_2
engraving_imgbtn_2.add_style(style_engraving_imgbtn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_engraving_imgbtn_2_main_main_pressed
style_engraving_imgbtn_2_main_main_pressed = lv.style_t()
style_engraving_imgbtn_2_main_main_pressed.init()
style_engraving_imgbtn_2_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_imgbtn_2_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_2_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_2_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_imgbtn_2_main_main_pressed.set_img_recolor_opa(0)
style_engraving_imgbtn_2_main_main_pressed.set_img_opa(255)

# add style for engraving_imgbtn_2
engraving_imgbtn_2.add_style(style_engraving_imgbtn_2_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_engraving_imgbtn_2_main_main_checked
style_engraving_imgbtn_2_main_main_checked = lv.style_t()
style_engraving_imgbtn_2_main_main_checked.init()
style_engraving_imgbtn_2_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_imgbtn_2_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_2_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_2_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_imgbtn_2_main_main_checked.set_img_recolor_opa(0)
style_engraving_imgbtn_2_main_main_checked.set_img_opa(255)

# add style for engraving_imgbtn_2
engraving_imgbtn_2.add_style(style_engraving_imgbtn_2_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

engraving_imgbtn_3 = lv.imgbtn(engraving)
engraving_imgbtn_3.set_pos(int(255),int(137))
engraving_imgbtn_3.set_size(206,33)
engraving_imgbtn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-230075217.png','rb') as f:
        engraving_imgbtn_3_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-230075217.png')
    sys.exit()

engraving_imgbtn_3_imgReleased = lv.img_dsc_t({
  'data_size': len(engraving_imgbtn_3_imgReleased_data),
  'header': {'always_zero': 0, 'w': 206, 'h': 33, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': engraving_imgbtn_3_imgReleased_data
})
engraving_imgbtn_3.set_src(lv.imgbtn.STATE.RELEASED, engraving_imgbtn_3_imgReleased, None, None)





engraving_imgbtn_3.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_engraving_imgbtn_3_main_main_default
style_engraving_imgbtn_3_main_main_default = lv.style_t()
style_engraving_imgbtn_3_main_main_default.init()
style_engraving_imgbtn_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_engraving_imgbtn_3_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_engraving_imgbtn_3_main_main_default.set_img_recolor_opa(0)
style_engraving_imgbtn_3_main_main_default.set_img_opa(255)

# add style for engraving_imgbtn_3
engraving_imgbtn_3.add_style(style_engraving_imgbtn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_engraving_imgbtn_3_main_main_pressed
style_engraving_imgbtn_3_main_main_pressed = lv.style_t()
style_engraving_imgbtn_3_main_main_pressed.init()
style_engraving_imgbtn_3_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_imgbtn_3_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_3_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_3_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_imgbtn_3_main_main_pressed.set_img_recolor_opa(0)
style_engraving_imgbtn_3_main_main_pressed.set_img_opa(255)

# add style for engraving_imgbtn_3
engraving_imgbtn_3.add_style(style_engraving_imgbtn_3_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_engraving_imgbtn_3_main_main_checked
style_engraving_imgbtn_3_main_main_checked = lv.style_t()
style_engraving_imgbtn_3_main_main_checked.init()
style_engraving_imgbtn_3_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_imgbtn_3_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_3_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_3_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_imgbtn_3_main_main_checked.set_img_recolor_opa(0)
style_engraving_imgbtn_3_main_main_checked.set_img_opa(255)

# add style for engraving_imgbtn_3
engraving_imgbtn_3.add_style(style_engraving_imgbtn_3_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

engraving_imgbtn_4 = lv.imgbtn(engraving)
engraving_imgbtn_4.set_pos(int(255),int(191))
engraving_imgbtn_4.set_size(206,33)
engraving_imgbtn_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp2085665189.png','rb') as f:
        engraving_imgbtn_4_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp2085665189.png')
    sys.exit()

engraving_imgbtn_4_imgReleased = lv.img_dsc_t({
  'data_size': len(engraving_imgbtn_4_imgReleased_data),
  'header': {'always_zero': 0, 'w': 206, 'h': 33, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': engraving_imgbtn_4_imgReleased_data
})
engraving_imgbtn_4.set_src(lv.imgbtn.STATE.RELEASED, engraving_imgbtn_4_imgReleased, None, None)





engraving_imgbtn_4.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_engraving_imgbtn_4_main_main_default
style_engraving_imgbtn_4_main_main_default = lv.style_t()
style_engraving_imgbtn_4_main_main_default.init()
style_engraving_imgbtn_4_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_engraving_imgbtn_4_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_4_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_engraving_imgbtn_4_main_main_default.set_img_recolor_opa(0)
style_engraving_imgbtn_4_main_main_default.set_img_opa(255)

# add style for engraving_imgbtn_4
engraving_imgbtn_4.add_style(style_engraving_imgbtn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_engraving_imgbtn_4_main_main_pressed
style_engraving_imgbtn_4_main_main_pressed = lv.style_t()
style_engraving_imgbtn_4_main_main_pressed.init()
style_engraving_imgbtn_4_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_imgbtn_4_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_4_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_4_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_4_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_4_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_imgbtn_4_main_main_pressed.set_img_recolor_opa(0)
style_engraving_imgbtn_4_main_main_pressed.set_img_opa(255)

# add style for engraving_imgbtn_4
engraving_imgbtn_4.add_style(style_engraving_imgbtn_4_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_engraving_imgbtn_4_main_main_checked
style_engraving_imgbtn_4_main_main_checked = lv.style_t()
style_engraving_imgbtn_4_main_main_checked.init()
style_engraving_imgbtn_4_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_imgbtn_4_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_4_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_4_main_main_checked.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_4_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_4_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_imgbtn_4_main_main_checked.set_img_recolor_opa(0)
style_engraving_imgbtn_4_main_main_checked.set_img_opa(255)

# add style for engraving_imgbtn_4
engraving_imgbtn_4.add_style(style_engraving_imgbtn_4_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

engraving_imgbtn_5 = lv.imgbtn(engraving)
engraving_imgbtn_5.set_pos(int(270),int(240))
engraving_imgbtn_5.set_size(175,50)
engraving_imgbtn_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-187709146.png','rb') as f:
        engraving_imgbtn_5_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-187709146.png')
    sys.exit()

engraving_imgbtn_5_imgReleased = lv.img_dsc_t({
  'data_size': len(engraving_imgbtn_5_imgReleased_data),
  'header': {'always_zero': 0, 'w': 175, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': engraving_imgbtn_5_imgReleased_data
})
engraving_imgbtn_5.set_src(lv.imgbtn.STATE.RELEASED, engraving_imgbtn_5_imgReleased, None, None)





engraving_imgbtn_5.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_engraving_imgbtn_5_main_main_default
style_engraving_imgbtn_5_main_main_default = lv.style_t()
style_engraving_imgbtn_5_main_main_default.init()
style_engraving_imgbtn_5_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_engraving_imgbtn_5_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_5_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_engraving_imgbtn_5_main_main_default.set_img_recolor_opa(0)
style_engraving_imgbtn_5_main_main_default.set_img_opa(255)

# add style for engraving_imgbtn_5
engraving_imgbtn_5.add_style(style_engraving_imgbtn_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_engraving_imgbtn_5_main_main_pressed
style_engraving_imgbtn_5_main_main_pressed = lv.style_t()
style_engraving_imgbtn_5_main_main_pressed.init()
style_engraving_imgbtn_5_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_imgbtn_5_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_5_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_5_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_5_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_5_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_imgbtn_5_main_main_pressed.set_img_recolor_opa(0)
style_engraving_imgbtn_5_main_main_pressed.set_img_opa(255)

# add style for engraving_imgbtn_5
engraving_imgbtn_5.add_style(style_engraving_imgbtn_5_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_engraving_imgbtn_5_main_main_checked
style_engraving_imgbtn_5_main_main_checked = lv.style_t()
style_engraving_imgbtn_5_main_main_checked.init()
style_engraving_imgbtn_5_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_imgbtn_5_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_5_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_5_main_main_checked.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_5_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_5_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_imgbtn_5_main_main_checked.set_img_recolor_opa(0)
style_engraving_imgbtn_5_main_main_checked.set_img_opa(255)

# add style for engraving_imgbtn_5
engraving_imgbtn_5.add_style(style_engraving_imgbtn_5_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

engraving_img_1 = lv.img(engraving)
engraving_img_1.set_pos(int(103),int(12))
engraving_img_1.set_size(15,9)
engraving_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
engraving_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp1734889392.png','rb') as f:
        engraving_img_1_img_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp1734889392.png')
    sys.exit()

engraving_img_1_img = lv.img_dsc_t({
  'data_size': len(engraving_img_1_img_data),
  'header': {'always_zero': 0, 'w': 15, 'h': 9, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': engraving_img_1_img_data
})

engraving_img_1.set_src(engraving_img_1_img)
engraving_img_1.set_pivot(0,0)
engraving_img_1.set_angle(0)
# create style style_engraving_img_1_main_main_default
style_engraving_img_1_main_main_default = lv.style_t()
style_engraving_img_1_main_main_default.init()
style_engraving_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_engraving_img_1_main_main_default.set_img_recolor_opa(0)
style_engraving_img_1_main_main_default.set_img_opa(255)

# add style for engraving_img_1
engraving_img_1.add_style(style_engraving_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

engraving_imgbtn_6 = lv.imgbtn(engraving)
engraving_imgbtn_6.set_pos(int(420),int(17))
engraving_imgbtn_6.set_size(25,21)
engraving_imgbtn_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1962976602.png','rb') as f:
        engraving_imgbtn_6_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1962976602.png')
    sys.exit()

engraving_imgbtn_6_imgReleased = lv.img_dsc_t({
  'data_size': len(engraving_imgbtn_6_imgReleased_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 21, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': engraving_imgbtn_6_imgReleased_data
})
engraving_imgbtn_6.set_src(lv.imgbtn.STATE.RELEASED, engraving_imgbtn_6_imgReleased, None, None)





engraving_imgbtn_6.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_engraving_imgbtn_6_main_main_default
style_engraving_imgbtn_6_main_main_default = lv.style_t()
style_engraving_imgbtn_6_main_main_default.init()
style_engraving_imgbtn_6_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_engraving_imgbtn_6_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_6_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_engraving_imgbtn_6_main_main_default.set_img_recolor_opa(0)
style_engraving_imgbtn_6_main_main_default.set_img_opa(255)

# add style for engraving_imgbtn_6
engraving_imgbtn_6.add_style(style_engraving_imgbtn_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_engraving_imgbtn_6_main_main_pressed
style_engraving_imgbtn_6_main_main_pressed = lv.style_t()
style_engraving_imgbtn_6_main_main_pressed.init()
style_engraving_imgbtn_6_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_imgbtn_6_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_6_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_6_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_6_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_6_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_imgbtn_6_main_main_pressed.set_img_recolor_opa(0)
style_engraving_imgbtn_6_main_main_pressed.set_img_opa(255)

# add style for engraving_imgbtn_6
engraving_imgbtn_6.add_style(style_engraving_imgbtn_6_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_engraving_imgbtn_6_main_main_checked
style_engraving_imgbtn_6_main_main_checked = lv.style_t()
style_engraving_imgbtn_6_main_main_checked.init()
style_engraving_imgbtn_6_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_imgbtn_6_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_engraving_imgbtn_6_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_imgbtn_6_main_main_checked.set_text_font(lv.font_montserrat_16)
style_engraving_imgbtn_6_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_imgbtn_6_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_imgbtn_6_main_main_checked.set_img_recolor_opa(0)
style_engraving_imgbtn_6_main_main_checked.set_img_opa(255)

# add style for engraving_imgbtn_6
engraving_imgbtn_6.add_style(style_engraving_imgbtn_6_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

file_management = lv.obj()
file_management.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_file_management_main_main_default
style_file_management_main_main_default = lv.style_t()
style_file_management_main_main_default.init()
style_file_management_main_main_default.set_bg_color(lv.color_make(0x1d,0x23,0x32))
style_file_management_main_main_default.set_bg_opa(255)

# add style for file_management
file_management.add_style(style_file_management_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_1 = lv.label(file_management)
file_management_label_1.set_pos(int(12),int(28))
file_management_label_1.set_size(85,21)
file_management_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
file_management_label_1.set_text("File")
file_management_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_file_management_label_1_main_main_default
style_file_management_label_1_main_main_default = lv.style_t()
style_file_management_label_1_main_main_default.init()
style_file_management_label_1_main_main_default.set_radius(0)
style_file_management_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_file_management_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_file_management_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_file_management_label_1_main_main_default.set_bg_opa(0)
style_file_management_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_1_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_file_management_label_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_file_management_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_1_main_main_default.set_text_letter_space(2)
style_file_management_label_1_main_main_default.set_text_line_space(0)
style_file_management_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_file_management_label_1_main_main_default.set_pad_left(0)
style_file_management_label_1_main_main_default.set_pad_right(0)
style_file_management_label_1_main_main_default.set_pad_top(0)
style_file_management_label_1_main_main_default.set_pad_bottom(0)

# add style for file_management_label_1
file_management_label_1.add_style(style_file_management_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

incarving = lv.obj()
incarving.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_incarving_main_main_default
style_incarving_main_main_default = lv.style_t()
style_incarving_main_main_default.init()
style_incarving_main_main_default.set_bg_color(lv.color_make(0x1d,0x23,0x32))
style_incarving_main_main_default.set_bg_opa(255)

# add style for incarving
incarving.add_style(style_incarving_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

incarving_imgbtn_1 = lv.imgbtn(incarving)
incarving_imgbtn_1.set_pos(int(63),int(85))
incarving_imgbtn_1.set_size(150,150)
incarving_imgbtn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1416923807.png','rb') as f:
        incarving_imgbtn_1_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1416923807.png')
    sys.exit()

incarving_imgbtn_1_imgReleased = lv.img_dsc_t({
  'data_size': len(incarving_imgbtn_1_imgReleased_data),
  'header': {'always_zero': 0, 'w': 150, 'h': 150, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': incarving_imgbtn_1_imgReleased_data
})
incarving_imgbtn_1.set_src(lv.imgbtn.STATE.RELEASED, incarving_imgbtn_1_imgReleased, None, None)





incarving_imgbtn_1.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_incarving_imgbtn_1_main_main_default
style_incarving_imgbtn_1_main_main_default = lv.style_t()
style_incarving_imgbtn_1_main_main_default.init()
style_incarving_imgbtn_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_incarving_imgbtn_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_incarving_imgbtn_1_main_main_default.set_img_recolor_opa(0)
style_incarving_imgbtn_1_main_main_default.set_img_opa(255)

# add style for incarving_imgbtn_1
incarving_imgbtn_1.add_style(style_incarving_imgbtn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_incarving_imgbtn_1_main_main_pressed
style_incarving_imgbtn_1_main_main_pressed = lv.style_t()
style_incarving_imgbtn_1_main_main_pressed.init()
style_incarving_imgbtn_1_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_incarving_imgbtn_1_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_1_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_1_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_incarving_imgbtn_1_main_main_pressed.set_img_recolor_opa(0)
style_incarving_imgbtn_1_main_main_pressed.set_img_opa(255)

# add style for incarving_imgbtn_1
incarving_imgbtn_1.add_style(style_incarving_imgbtn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_incarving_imgbtn_1_main_main_checked
style_incarving_imgbtn_1_main_main_checked = lv.style_t()
style_incarving_imgbtn_1_main_main_checked.init()
style_incarving_imgbtn_1_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_incarving_imgbtn_1_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_1_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_1_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_incarving_imgbtn_1_main_main_checked.set_img_recolor_opa(0)
style_incarving_imgbtn_1_main_main_checked.set_img_opa(255)

# add style for incarving_imgbtn_1
incarving_imgbtn_1.add_style(style_incarving_imgbtn_1_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

incarving_imgbtn_2 = lv.imgbtn(incarving)
incarving_imgbtn_2.set_pos(int(254),int(62))
incarving_imgbtn_2.set_size(151,23)
incarving_imgbtn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-404790657.png','rb') as f:
        incarving_imgbtn_2_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-404790657.png')
    sys.exit()

incarving_imgbtn_2_imgReleased = lv.img_dsc_t({
  'data_size': len(incarving_imgbtn_2_imgReleased_data),
  'header': {'always_zero': 0, 'w': 151, 'h': 23, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': incarving_imgbtn_2_imgReleased_data
})
incarving_imgbtn_2.set_src(lv.imgbtn.STATE.RELEASED, incarving_imgbtn_2_imgReleased, None, None)





incarving_imgbtn_2.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_incarving_imgbtn_2_main_main_default
style_incarving_imgbtn_2_main_main_default = lv.style_t()
style_incarving_imgbtn_2_main_main_default.init()
style_incarving_imgbtn_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_incarving_imgbtn_2_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_incarving_imgbtn_2_main_main_default.set_img_recolor_opa(0)
style_incarving_imgbtn_2_main_main_default.set_img_opa(255)

# add style for incarving_imgbtn_2
incarving_imgbtn_2.add_style(style_incarving_imgbtn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_incarving_imgbtn_2_main_main_pressed
style_incarving_imgbtn_2_main_main_pressed = lv.style_t()
style_incarving_imgbtn_2_main_main_pressed.init()
style_incarving_imgbtn_2_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_incarving_imgbtn_2_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_2_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_2_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_incarving_imgbtn_2_main_main_pressed.set_img_recolor_opa(0)
style_incarving_imgbtn_2_main_main_pressed.set_img_opa(255)

# add style for incarving_imgbtn_2
incarving_imgbtn_2.add_style(style_incarving_imgbtn_2_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_incarving_imgbtn_2_main_main_checked
style_incarving_imgbtn_2_main_main_checked = lv.style_t()
style_incarving_imgbtn_2_main_main_checked.init()
style_incarving_imgbtn_2_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_incarving_imgbtn_2_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_2_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_2_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_incarving_imgbtn_2_main_main_checked.set_img_recolor_opa(0)
style_incarving_imgbtn_2_main_main_checked.set_img_opa(255)

# add style for incarving_imgbtn_2
incarving_imgbtn_2.add_style(style_incarving_imgbtn_2_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

incarving_imgbtn_3 = lv.imgbtn(incarving)
incarving_imgbtn_3.set_pos(int(260),int(132))
incarving_imgbtn_3.set_size(157,26)
incarving_imgbtn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp1726982318.png','rb') as f:
        incarving_imgbtn_3_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp1726982318.png')
    sys.exit()

incarving_imgbtn_3_imgReleased = lv.img_dsc_t({
  'data_size': len(incarving_imgbtn_3_imgReleased_data),
  'header': {'always_zero': 0, 'w': 157, 'h': 26, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': incarving_imgbtn_3_imgReleased_data
})
incarving_imgbtn_3.set_src(lv.imgbtn.STATE.RELEASED, incarving_imgbtn_3_imgReleased, None, None)





incarving_imgbtn_3.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_incarving_imgbtn_3_main_main_default
style_incarving_imgbtn_3_main_main_default = lv.style_t()
style_incarving_imgbtn_3_main_main_default.init()
style_incarving_imgbtn_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_incarving_imgbtn_3_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_incarving_imgbtn_3_main_main_default.set_img_recolor_opa(0)
style_incarving_imgbtn_3_main_main_default.set_img_opa(255)

# add style for incarving_imgbtn_3
incarving_imgbtn_3.add_style(style_incarving_imgbtn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_incarving_imgbtn_3_main_main_pressed
style_incarving_imgbtn_3_main_main_pressed = lv.style_t()
style_incarving_imgbtn_3_main_main_pressed.init()
style_incarving_imgbtn_3_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_incarving_imgbtn_3_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_3_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_3_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_incarving_imgbtn_3_main_main_pressed.set_img_recolor_opa(0)
style_incarving_imgbtn_3_main_main_pressed.set_img_opa(255)

# add style for incarving_imgbtn_3
incarving_imgbtn_3.add_style(style_incarving_imgbtn_3_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_incarving_imgbtn_3_main_main_checked
style_incarving_imgbtn_3_main_main_checked = lv.style_t()
style_incarving_imgbtn_3_main_main_checked.init()
style_incarving_imgbtn_3_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_incarving_imgbtn_3_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_3_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_3_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_incarving_imgbtn_3_main_main_checked.set_img_recolor_opa(0)
style_incarving_imgbtn_3_main_main_checked.set_img_opa(255)

# add style for incarving_imgbtn_3
incarving_imgbtn_3.add_style(style_incarving_imgbtn_3_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

incarving_imgbtn_4 = lv.imgbtn(incarving)
incarving_imgbtn_4.set_pos(int(263),int(189))
incarving_imgbtn_4.set_size(154,24)
incarving_imgbtn_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-425448353.png','rb') as f:
        incarving_imgbtn_4_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-425448353.png')
    sys.exit()

incarving_imgbtn_4_imgReleased = lv.img_dsc_t({
  'data_size': len(incarving_imgbtn_4_imgReleased_data),
  'header': {'always_zero': 0, 'w': 154, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': incarving_imgbtn_4_imgReleased_data
})
incarving_imgbtn_4.set_src(lv.imgbtn.STATE.RELEASED, incarving_imgbtn_4_imgReleased, None, None)





incarving_imgbtn_4.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_incarving_imgbtn_4_main_main_default
style_incarving_imgbtn_4_main_main_default = lv.style_t()
style_incarving_imgbtn_4_main_main_default.init()
style_incarving_imgbtn_4_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_incarving_imgbtn_4_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_4_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_incarving_imgbtn_4_main_main_default.set_img_recolor_opa(0)
style_incarving_imgbtn_4_main_main_default.set_img_opa(255)

# add style for incarving_imgbtn_4
incarving_imgbtn_4.add_style(style_incarving_imgbtn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_incarving_imgbtn_4_main_main_pressed
style_incarving_imgbtn_4_main_main_pressed = lv.style_t()
style_incarving_imgbtn_4_main_main_pressed.init()
style_incarving_imgbtn_4_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_incarving_imgbtn_4_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_4_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_4_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_4_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_4_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_incarving_imgbtn_4_main_main_pressed.set_img_recolor_opa(0)
style_incarving_imgbtn_4_main_main_pressed.set_img_opa(255)

# add style for incarving_imgbtn_4
incarving_imgbtn_4.add_style(style_incarving_imgbtn_4_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_incarving_imgbtn_4_main_main_checked
style_incarving_imgbtn_4_main_main_checked = lv.style_t()
style_incarving_imgbtn_4_main_main_checked.init()
style_incarving_imgbtn_4_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_incarving_imgbtn_4_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_4_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_4_main_main_checked.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_4_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_4_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_incarving_imgbtn_4_main_main_checked.set_img_recolor_opa(0)
style_incarving_imgbtn_4_main_main_checked.set_img_opa(255)

# add style for incarving_imgbtn_4
incarving_imgbtn_4.add_style(style_incarving_imgbtn_4_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

incarving_imgbtn_5 = lv.imgbtn(incarving)
incarving_imgbtn_5.set_pos(int(250),int(249))
incarving_imgbtn_5.set_size(150,32)
incarving_imgbtn_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp1252921535.png','rb') as f:
        incarving_imgbtn_5_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp1252921535.png')
    sys.exit()

incarving_imgbtn_5_imgReleased = lv.img_dsc_t({
  'data_size': len(incarving_imgbtn_5_imgReleased_data),
  'header': {'always_zero': 0, 'w': 150, 'h': 32, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': incarving_imgbtn_5_imgReleased_data
})
incarving_imgbtn_5.set_src(lv.imgbtn.STATE.RELEASED, incarving_imgbtn_5_imgReleased, None, None)





incarving_imgbtn_5.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_incarving_imgbtn_5_main_main_default
style_incarving_imgbtn_5_main_main_default = lv.style_t()
style_incarving_imgbtn_5_main_main_default.init()
style_incarving_imgbtn_5_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_incarving_imgbtn_5_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_5_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_incarving_imgbtn_5_main_main_default.set_img_recolor_opa(0)
style_incarving_imgbtn_5_main_main_default.set_img_opa(255)

# add style for incarving_imgbtn_5
incarving_imgbtn_5.add_style(style_incarving_imgbtn_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_incarving_imgbtn_5_main_main_pressed
style_incarving_imgbtn_5_main_main_pressed = lv.style_t()
style_incarving_imgbtn_5_main_main_pressed.init()
style_incarving_imgbtn_5_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_incarving_imgbtn_5_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_5_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_5_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_5_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_5_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_incarving_imgbtn_5_main_main_pressed.set_img_recolor_opa(0)
style_incarving_imgbtn_5_main_main_pressed.set_img_opa(255)

# add style for incarving_imgbtn_5
incarving_imgbtn_5.add_style(style_incarving_imgbtn_5_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_incarving_imgbtn_5_main_main_checked
style_incarving_imgbtn_5_main_main_checked = lv.style_t()
style_incarving_imgbtn_5_main_main_checked.init()
style_incarving_imgbtn_5_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_incarving_imgbtn_5_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_incarving_imgbtn_5_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_incarving_imgbtn_5_main_main_checked.set_text_font(lv.font_montserrat_16)
style_incarving_imgbtn_5_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_incarving_imgbtn_5_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_incarving_imgbtn_5_main_main_checked.set_img_recolor_opa(0)
style_incarving_imgbtn_5_main_main_checked.set_img_opa(255)

# add style for incarving_imgbtn_5
incarving_imgbtn_5.add_style(style_incarving_imgbtn_5_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

control = lv.obj()
control.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_control_main_main_default
style_control_main_main_default = lv.style_t()
style_control_main_main_default.init()
style_control_main_main_default.set_bg_color(lv.color_make(0x1d,0x23,0x32))
style_control_main_main_default.set_bg_opa(255)

# add style for control
control.add_style(style_control_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

control_imgbtn_1 = lv.imgbtn(control)
control_imgbtn_1.set_pos(int(30),int(62))
control_imgbtn_1.set_size(184,184)
control_imgbtn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp244035533.png','rb') as f:
        control_imgbtn_1_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp244035533.png')
    sys.exit()

control_imgbtn_1_imgReleased = lv.img_dsc_t({
  'data_size': len(control_imgbtn_1_imgReleased_data),
  'header': {'always_zero': 0, 'w': 184, 'h': 184, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': control_imgbtn_1_imgReleased_data
})
control_imgbtn_1.set_src(lv.imgbtn.STATE.RELEASED, control_imgbtn_1_imgReleased, None, None)





control_imgbtn_1.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_control_imgbtn_1_main_main_default
style_control_imgbtn_1_main_main_default = lv.style_t()
style_control_imgbtn_1_main_main_default.init()
style_control_imgbtn_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_control_imgbtn_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_control_imgbtn_1_main_main_default.set_img_recolor_opa(0)
style_control_imgbtn_1_main_main_default.set_img_opa(255)

# add style for control_imgbtn_1
control_imgbtn_1.add_style(style_control_imgbtn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_control_imgbtn_1_main_main_pressed
style_control_imgbtn_1_main_main_pressed = lv.style_t()
style_control_imgbtn_1_main_main_pressed.init()
style_control_imgbtn_1_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_control_imgbtn_1_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_1_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_1_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_control_imgbtn_1_main_main_pressed.set_img_recolor_opa(0)
style_control_imgbtn_1_main_main_pressed.set_img_opa(255)

# add style for control_imgbtn_1
control_imgbtn_1.add_style(style_control_imgbtn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_control_imgbtn_1_main_main_checked
style_control_imgbtn_1_main_main_checked = lv.style_t()
style_control_imgbtn_1_main_main_checked.init()
style_control_imgbtn_1_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_control_imgbtn_1_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_1_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_1_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_control_imgbtn_1_main_main_checked.set_img_recolor_opa(0)
style_control_imgbtn_1_main_main_checked.set_img_opa(255)

# add style for control_imgbtn_1
control_imgbtn_1.add_style(style_control_imgbtn_1_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

control_imgbtn_2 = lv.imgbtn(control)
control_imgbtn_2.set_pos(int(255),int(80))
control_imgbtn_2.set_size(206,33)
control_imgbtn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1097804054.png','rb') as f:
        control_imgbtn_2_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1097804054.png')
    sys.exit()

control_imgbtn_2_imgReleased = lv.img_dsc_t({
  'data_size': len(control_imgbtn_2_imgReleased_data),
  'header': {'always_zero': 0, 'w': 206, 'h': 33, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': control_imgbtn_2_imgReleased_data
})
control_imgbtn_2.set_src(lv.imgbtn.STATE.RELEASED, control_imgbtn_2_imgReleased, None, None)





control_imgbtn_2.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_control_imgbtn_2_main_main_default
style_control_imgbtn_2_main_main_default = lv.style_t()
style_control_imgbtn_2_main_main_default.init()
style_control_imgbtn_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_control_imgbtn_2_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_control_imgbtn_2_main_main_default.set_img_recolor_opa(0)
style_control_imgbtn_2_main_main_default.set_img_opa(255)

# add style for control_imgbtn_2
control_imgbtn_2.add_style(style_control_imgbtn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_control_imgbtn_2_main_main_pressed
style_control_imgbtn_2_main_main_pressed = lv.style_t()
style_control_imgbtn_2_main_main_pressed.init()
style_control_imgbtn_2_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_control_imgbtn_2_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_2_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_2_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_control_imgbtn_2_main_main_pressed.set_img_recolor_opa(0)
style_control_imgbtn_2_main_main_pressed.set_img_opa(255)

# add style for control_imgbtn_2
control_imgbtn_2.add_style(style_control_imgbtn_2_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_control_imgbtn_2_main_main_checked
style_control_imgbtn_2_main_main_checked = lv.style_t()
style_control_imgbtn_2_main_main_checked.init()
style_control_imgbtn_2_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_control_imgbtn_2_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_2_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_2_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_control_imgbtn_2_main_main_checked.set_img_recolor_opa(0)
style_control_imgbtn_2_main_main_checked.set_img_opa(255)

# add style for control_imgbtn_2
control_imgbtn_2.add_style(style_control_imgbtn_2_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

control_imgbtn_3 = lv.imgbtn(control)
control_imgbtn_3.set_pos(int(255),int(139))
control_imgbtn_3.set_size(206,33)
control_imgbtn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-230075217.png','rb') as f:
        control_imgbtn_3_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-230075217.png')
    sys.exit()

control_imgbtn_3_imgReleased = lv.img_dsc_t({
  'data_size': len(control_imgbtn_3_imgReleased_data),
  'header': {'always_zero': 0, 'w': 206, 'h': 33, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': control_imgbtn_3_imgReleased_data
})
control_imgbtn_3.set_src(lv.imgbtn.STATE.RELEASED, control_imgbtn_3_imgReleased, None, None)





control_imgbtn_3.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_control_imgbtn_3_main_main_default
style_control_imgbtn_3_main_main_default = lv.style_t()
style_control_imgbtn_3_main_main_default.init()
style_control_imgbtn_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_control_imgbtn_3_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_control_imgbtn_3_main_main_default.set_img_recolor_opa(0)
style_control_imgbtn_3_main_main_default.set_img_opa(255)

# add style for control_imgbtn_3
control_imgbtn_3.add_style(style_control_imgbtn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_control_imgbtn_3_main_main_pressed
style_control_imgbtn_3_main_main_pressed = lv.style_t()
style_control_imgbtn_3_main_main_pressed.init()
style_control_imgbtn_3_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_control_imgbtn_3_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_3_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_3_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_control_imgbtn_3_main_main_pressed.set_img_recolor_opa(0)
style_control_imgbtn_3_main_main_pressed.set_img_opa(255)

# add style for control_imgbtn_3
control_imgbtn_3.add_style(style_control_imgbtn_3_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_control_imgbtn_3_main_main_checked
style_control_imgbtn_3_main_main_checked = lv.style_t()
style_control_imgbtn_3_main_main_checked.init()
style_control_imgbtn_3_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_control_imgbtn_3_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_3_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_3_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_control_imgbtn_3_main_main_checked.set_img_recolor_opa(0)
style_control_imgbtn_3_main_main_checked.set_img_opa(255)

# add style for control_imgbtn_3
control_imgbtn_3.add_style(style_control_imgbtn_3_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

control_imgbtn_4 = lv.imgbtn(control)
control_imgbtn_4.set_pos(int(255),int(198))
control_imgbtn_4.set_size(206,33)
control_imgbtn_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp2085665189.png','rb') as f:
        control_imgbtn_4_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp2085665189.png')
    sys.exit()

control_imgbtn_4_imgReleased = lv.img_dsc_t({
  'data_size': len(control_imgbtn_4_imgReleased_data),
  'header': {'always_zero': 0, 'w': 206, 'h': 33, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': control_imgbtn_4_imgReleased_data
})
control_imgbtn_4.set_src(lv.imgbtn.STATE.RELEASED, control_imgbtn_4_imgReleased, None, None)





control_imgbtn_4.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_control_imgbtn_4_main_main_default
style_control_imgbtn_4_main_main_default = lv.style_t()
style_control_imgbtn_4_main_main_default.init()
style_control_imgbtn_4_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_control_imgbtn_4_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_4_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_control_imgbtn_4_main_main_default.set_img_recolor_opa(0)
style_control_imgbtn_4_main_main_default.set_img_opa(255)

# add style for control_imgbtn_4
control_imgbtn_4.add_style(style_control_imgbtn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_control_imgbtn_4_main_main_pressed
style_control_imgbtn_4_main_main_pressed = lv.style_t()
style_control_imgbtn_4_main_main_pressed.init()
style_control_imgbtn_4_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_control_imgbtn_4_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_4_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_4_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_4_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_4_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_control_imgbtn_4_main_main_pressed.set_img_recolor_opa(0)
style_control_imgbtn_4_main_main_pressed.set_img_opa(255)

# add style for control_imgbtn_4
control_imgbtn_4.add_style(style_control_imgbtn_4_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_control_imgbtn_4_main_main_checked
style_control_imgbtn_4_main_main_checked = lv.style_t()
style_control_imgbtn_4_main_main_checked.init()
style_control_imgbtn_4_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_control_imgbtn_4_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_4_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_4_main_main_checked.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_4_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_4_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_control_imgbtn_4_main_main_checked.set_img_recolor_opa(0)
style_control_imgbtn_4_main_main_checked.set_img_opa(255)

# add style for control_imgbtn_4
control_imgbtn_4.add_style(style_control_imgbtn_4_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

control_imgbtn_5 = lv.imgbtn(control)
control_imgbtn_5.set_pos(int(14),int(255))
control_imgbtn_5.set_size(222,38)
control_imgbtn_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp403738319.png','rb') as f:
        control_imgbtn_5_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp403738319.png')
    sys.exit()

control_imgbtn_5_imgReleased = lv.img_dsc_t({
  'data_size': len(control_imgbtn_5_imgReleased_data),
  'header': {'always_zero': 0, 'w': 222, 'h': 38, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': control_imgbtn_5_imgReleased_data
})
control_imgbtn_5.set_src(lv.imgbtn.STATE.RELEASED, control_imgbtn_5_imgReleased, None, None)





control_imgbtn_5.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_control_imgbtn_5_main_main_default
style_control_imgbtn_5_main_main_default = lv.style_t()
style_control_imgbtn_5_main_main_default.init()
style_control_imgbtn_5_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_control_imgbtn_5_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_5_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_control_imgbtn_5_main_main_default.set_img_recolor_opa(0)
style_control_imgbtn_5_main_main_default.set_img_opa(255)

# add style for control_imgbtn_5
control_imgbtn_5.add_style(style_control_imgbtn_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_control_imgbtn_5_main_main_pressed
style_control_imgbtn_5_main_main_pressed = lv.style_t()
style_control_imgbtn_5_main_main_pressed.init()
style_control_imgbtn_5_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_control_imgbtn_5_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_5_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_5_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_5_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_5_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_control_imgbtn_5_main_main_pressed.set_img_recolor_opa(0)
style_control_imgbtn_5_main_main_pressed.set_img_opa(255)

# add style for control_imgbtn_5
control_imgbtn_5.add_style(style_control_imgbtn_5_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_control_imgbtn_5_main_main_checked
style_control_imgbtn_5_main_main_checked = lv.style_t()
style_control_imgbtn_5_main_main_checked.init()
style_control_imgbtn_5_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_control_imgbtn_5_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_5_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_5_main_main_checked.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_5_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_5_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_control_imgbtn_5_main_main_checked.set_img_recolor_opa(0)
style_control_imgbtn_5_main_main_checked.set_img_opa(255)

# add style for control_imgbtn_5
control_imgbtn_5.add_style(style_control_imgbtn_5_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

control_img_1 = lv.img(control)
control_img_1.set_pos(int(255),int(256))
control_img_1.set_size(206,33)
control_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
control_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp1503689953.png','rb') as f:
        control_img_1_img_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp1503689953.png')
    sys.exit()

control_img_1_img = lv.img_dsc_t({
  'data_size': len(control_img_1_img_data),
  'header': {'always_zero': 0, 'w': 206, 'h': 33, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': control_img_1_img_data
})

control_img_1.set_src(control_img_1_img)
control_img_1.set_pivot(0,0)
control_img_1.set_angle(0)
# create style style_control_img_1_main_main_default
style_control_img_1_main_main_default = lv.style_t()
style_control_img_1_main_main_default.init()
style_control_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_control_img_1_main_main_default.set_img_recolor_opa(0)
style_control_img_1_main_main_default.set_img_opa(255)

# add style for control_img_1
control_img_1.add_style(style_control_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

control_imgbtn_6 = lv.imgbtn(control)
control_imgbtn_6.set_pos(int(420),int(17))
control_imgbtn_6.set_size(25,21)
control_imgbtn_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1962976602.png','rb') as f:
        control_imgbtn_6_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1962976602.png')
    sys.exit()

control_imgbtn_6_imgReleased = lv.img_dsc_t({
  'data_size': len(control_imgbtn_6_imgReleased_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 21, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': control_imgbtn_6_imgReleased_data
})
control_imgbtn_6.set_src(lv.imgbtn.STATE.RELEASED, control_imgbtn_6_imgReleased, None, None)





control_imgbtn_6.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_control_imgbtn_6_main_main_default
style_control_imgbtn_6_main_main_default = lv.style_t()
style_control_imgbtn_6_main_main_default.init()
style_control_imgbtn_6_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_control_imgbtn_6_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_6_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_control_imgbtn_6_main_main_default.set_img_recolor_opa(0)
style_control_imgbtn_6_main_main_default.set_img_opa(255)

# add style for control_imgbtn_6
control_imgbtn_6.add_style(style_control_imgbtn_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_control_imgbtn_6_main_main_pressed
style_control_imgbtn_6_main_main_pressed = lv.style_t()
style_control_imgbtn_6_main_main_pressed.init()
style_control_imgbtn_6_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_control_imgbtn_6_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_6_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_6_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_6_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_6_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_control_imgbtn_6_main_main_pressed.set_img_recolor_opa(0)
style_control_imgbtn_6_main_main_pressed.set_img_opa(255)

# add style for control_imgbtn_6
control_imgbtn_6.add_style(style_control_imgbtn_6_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_control_imgbtn_6_main_main_checked
style_control_imgbtn_6_main_main_checked = lv.style_t()
style_control_imgbtn_6_main_main_checked.init()
style_control_imgbtn_6_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_control_imgbtn_6_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_control_imgbtn_6_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_control_imgbtn_6_main_main_checked.set_text_font(lv.font_montserrat_16)
style_control_imgbtn_6_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_control_imgbtn_6_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_control_imgbtn_6_main_main_checked.set_img_recolor_opa(0)
style_control_imgbtn_6_main_main_checked.set_img_opa(255)

# add style for control_imgbtn_6
control_imgbtn_6.add_style(style_control_imgbtn_6_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool = lv.obj()
tool.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_tool_main_main_default
style_tool_main_main_default = lv.style_t()
style_tool_main_main_default.init()
style_tool_main_main_default.set_bg_color(lv.color_make(0x1d,0x23,0x32))
style_tool_main_main_default.set_bg_opa(255)

# add style for tool
tool.add_style(style_tool_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_imgbtn_1 = lv.imgbtn(tool)
tool_imgbtn_1.set_pos(int(99),int(112))
tool_imgbtn_1.set_size(114,114)
tool_imgbtn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1258557151.png','rb') as f:
        tool_imgbtn_1_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1258557151.png')
    sys.exit()

tool_imgbtn_1_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_1_imgReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_1_imgReleased_data
})
tool_imgbtn_1.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_1_imgReleased, None, None)





tool_imgbtn_1.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_1_main_main_default
style_tool_imgbtn_1_main_main_default = lv.style_t()
style_tool_imgbtn_1_main_main_default.init()
style_tool_imgbtn_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_1_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_1_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_1
tool_imgbtn_1.add_style(style_tool_imgbtn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_1_main_main_pressed
style_tool_imgbtn_1_main_main_pressed = lv.style_t()
style_tool_imgbtn_1_main_main_pressed.init()
style_tool_imgbtn_1_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_1_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_1_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_1_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_1_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_1_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_1
tool_imgbtn_1.add_style(style_tool_imgbtn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_1_main_main_checked
style_tool_imgbtn_1_main_main_checked = lv.style_t()
style_tool_imgbtn_1_main_main_checked.init()
style_tool_imgbtn_1_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_1_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_1_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_1_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_1_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_1_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_1
tool_imgbtn_1.add_style(style_tool_imgbtn_1_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_imgbtn_2 = lv.imgbtn(tool)
tool_imgbtn_2.set_pos(int(268),int(112))
tool_imgbtn_2.set_size(114,114)
tool_imgbtn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1745389368.png','rb') as f:
        tool_imgbtn_2_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1745389368.png')
    sys.exit()

tool_imgbtn_2_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_2_imgReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_2_imgReleased_data
})
tool_imgbtn_2.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_2_imgReleased, None, None)





tool_imgbtn_2.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_2_main_main_default
style_tool_imgbtn_2_main_main_default = lv.style_t()
style_tool_imgbtn_2_main_main_default.init()
style_tool_imgbtn_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_2_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_2_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_2_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_2
tool_imgbtn_2.add_style(style_tool_imgbtn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_2_main_main_pressed
style_tool_imgbtn_2_main_main_pressed = lv.style_t()
style_tool_imgbtn_2_main_main_pressed.init()
style_tool_imgbtn_2_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_2_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_2_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_2_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_2_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_2_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_2
tool_imgbtn_2.add_style(style_tool_imgbtn_2_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_2_main_main_checked
style_tool_imgbtn_2_main_main_checked = lv.style_t()
style_tool_imgbtn_2_main_main_checked.init()
style_tool_imgbtn_2_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_2_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_2_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_2_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_2_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_2_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_2
tool_imgbtn_2.add_style(style_tool_imgbtn_2_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_label_1 = lv.label(tool)
tool_label_1.set_pos(int(15),int(28))
tool_label_1.set_size(60,18)
tool_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_label_1.set_text("Tools")
tool_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_label_1_main_main_default
style_tool_label_1_main_main_default = lv.style_t()
style_tool_label_1_main_main_default.init()
style_tool_label_1_main_main_default.set_radius(0)
style_tool_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_label_1_main_main_default.set_bg_opa(0)
style_tool_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_tool_label_1_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_tool_label_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_tool_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_label_1_main_main_default.set_text_letter_space(2)
style_tool_label_1_main_main_default.set_text_line_space(0)
style_tool_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_label_1_main_main_default.set_pad_left(0)
style_tool_label_1_main_main_default.set_pad_right(0)
style_tool_label_1_main_main_default.set_pad_top(0)
style_tool_label_1_main_main_default.set_pad_bottom(0)

# add style for tool_label_1
tool_label_1.add_style(style_tool_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_imgbtn_3 = lv.imgbtn(tool)
tool_imgbtn_3.set_pos(int(420),int(17))
tool_imgbtn_3.set_size(25,21)
tool_imgbtn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1962976602.png','rb') as f:
        tool_imgbtn_3_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1962976602.png')
    sys.exit()

tool_imgbtn_3_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_3_imgReleased_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 21, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_3_imgReleased_data
})
tool_imgbtn_3.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_3_imgReleased, None, None)





tool_imgbtn_3.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_3_main_main_default
style_tool_imgbtn_3_main_main_default = lv.style_t()
style_tool_imgbtn_3_main_main_default.init()
style_tool_imgbtn_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_3_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_3_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_3_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_3
tool_imgbtn_3.add_style(style_tool_imgbtn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_3_main_main_pressed
style_tool_imgbtn_3_main_main_pressed = lv.style_t()
style_tool_imgbtn_3_main_main_pressed.init()
style_tool_imgbtn_3_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_3_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_3_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_3_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_3_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_3_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_3
tool_imgbtn_3.add_style(style_tool_imgbtn_3_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_3_main_main_checked
style_tool_imgbtn_3_main_main_checked = lv.style_t()
style_tool_imgbtn_3_main_main_checked.init()
style_tool_imgbtn_3_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_3_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_3_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_3_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_3_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_3_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_3
tool_imgbtn_3.add_style(style_tool_imgbtn_3_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_info = lv.obj()
tool_info.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_tool_info_main_main_default
style_tool_info_main_main_default = lv.style_t()
style_tool_info_main_main_default.init()
style_tool_info_main_main_default.set_bg_color(lv.color_make(0x1d,0x23,0x32))
style_tool_info_main_main_default.set_bg_opa(255)

# add style for tool_info
tool_info.add_style(style_tool_info_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_info_label_1 = lv.label(tool_info)
tool_info_label_1.set_pos(int(15),int(28))
tool_info_label_1.set_size(60,18)
tool_info_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_info_label_1.set_text("Info")
tool_info_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_info_label_1_main_main_default
style_tool_info_label_1_main_main_default = lv.style_t()
style_tool_info_label_1_main_main_default.init()
style_tool_info_label_1_main_main_default.set_radius(0)
style_tool_info_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_info_label_1_main_main_default.set_bg_opa(0)
style_tool_info_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_tool_info_label_1_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_tool_info_label_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_tool_info_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_info_label_1_main_main_default.set_text_letter_space(2)
style_tool_info_label_1_main_main_default.set_text_line_space(0)
style_tool_info_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_info_label_1_main_main_default.set_pad_left(0)
style_tool_info_label_1_main_main_default.set_pad_right(0)
style_tool_info_label_1_main_main_default.set_pad_top(0)
style_tool_info_label_1_main_main_default.set_pad_bottom(0)

# add style for tool_info_label_1
tool_info_label_1.add_style(style_tool_info_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_info_label_3 = lv.label(tool_info)
tool_info_label_3.set_pos(int(22),int(111))
tool_info_label_3.set_size(115,26)
tool_info_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_info_label_3.set_text("Machine Size：")
tool_info_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_info_label_3_main_main_default
style_tool_info_label_3_main_main_default = lv.style_t()
style_tool_info_label_3_main_main_default.init()
style_tool_info_label_3_main_main_default.set_radius(0)
style_tool_info_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_info_label_3_main_main_default.set_bg_opa(0)
style_tool_info_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_tool_info_label_3_main_main_default.set_text_font(lv.font_Acme_Regular_12)
except AttributeError:
    try:
        style_tool_info_label_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_info_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_info_label_3_main_main_default.set_text_letter_space(2)
style_tool_info_label_3_main_main_default.set_text_line_space(0)
style_tool_info_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_tool_info_label_3_main_main_default.set_pad_left(0)
style_tool_info_label_3_main_main_default.set_pad_right(0)
style_tool_info_label_3_main_main_default.set_pad_top(0)
style_tool_info_label_3_main_main_default.set_pad_bottom(0)

# add style for tool_info_label_3
tool_info_label_3.add_style(style_tool_info_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_info_label_7 = lv.label(tool_info)
tool_info_label_7.set_pos(int(22),int(236))
tool_info_label_7.set_size(100,32)
tool_info_label_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_info_label_7.set_text("default")
tool_info_label_7.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_info_label_7_main_main_default
style_tool_info_label_7_main_main_default = lv.style_t()
style_tool_info_label_7_main_main_default.init()
style_tool_info_label_7_main_main_default.set_radius(0)
style_tool_info_label_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_info_label_7_main_main_default.set_bg_opa(0)
style_tool_info_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_tool_info_label_7_main_main_default.set_text_font(lv.font_Acme_Regular_12)
except AttributeError:
    try:
        style_tool_info_label_7_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_info_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_info_label_7_main_main_default.set_text_letter_space(2)
style_tool_info_label_7_main_main_default.set_text_line_space(0)
style_tool_info_label_7_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_tool_info_label_7_main_main_default.set_pad_left(0)
style_tool_info_label_7_main_main_default.set_pad_right(0)
style_tool_info_label_7_main_main_default.set_pad_top(0)
style_tool_info_label_7_main_main_default.set_pad_bottom(0)

# add style for tool_info_label_7
tool_info_label_7.add_style(style_tool_info_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_info_label_6 = lv.label(tool_info)
tool_info_label_6.set_pos(int(22),int(204))
tool_info_label_6.set_size(100,32)
tool_info_label_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_info_label_6.set_text("E-mail：")
tool_info_label_6.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_info_label_6_main_main_default
style_tool_info_label_6_main_main_default = lv.style_t()
style_tool_info_label_6_main_main_default.init()
style_tool_info_label_6_main_main_default.set_radius(0)
style_tool_info_label_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_info_label_6_main_main_default.set_bg_opa(0)
style_tool_info_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_tool_info_label_6_main_main_default.set_text_font(lv.font_Acme_Regular_12)
except AttributeError:
    try:
        style_tool_info_label_6_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_info_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_info_label_6_main_main_default.set_text_letter_space(2)
style_tool_info_label_6_main_main_default.set_text_line_space(0)
style_tool_info_label_6_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_tool_info_label_6_main_main_default.set_pad_left(0)
style_tool_info_label_6_main_main_default.set_pad_right(0)
style_tool_info_label_6_main_main_default.set_pad_top(0)
style_tool_info_label_6_main_main_default.set_pad_bottom(0)

# add style for tool_info_label_6
tool_info_label_6.add_style(style_tool_info_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_info_label_5 = lv.label(tool_info)
tool_info_label_5.set_pos(int(22),int(175))
tool_info_label_5.set_size(76,26)
tool_info_label_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_info_label_5.set_text("IP：")
tool_info_label_5.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_info_label_5_main_main_default
style_tool_info_label_5_main_main_default = lv.style_t()
style_tool_info_label_5_main_main_default.init()
style_tool_info_label_5_main_main_default.set_radius(0)
style_tool_info_label_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_info_label_5_main_main_default.set_bg_opa(0)
style_tool_info_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_tool_info_label_5_main_main_default.set_text_font(lv.font_Acme_Regular_12)
except AttributeError:
    try:
        style_tool_info_label_5_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_info_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_info_label_5_main_main_default.set_text_letter_space(2)
style_tool_info_label_5_main_main_default.set_text_line_space(0)
style_tool_info_label_5_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_tool_info_label_5_main_main_default.set_pad_left(0)
style_tool_info_label_5_main_main_default.set_pad_right(0)
style_tool_info_label_5_main_main_default.set_pad_top(0)
style_tool_info_label_5_main_main_default.set_pad_bottom(0)

# add style for tool_info_label_5
tool_info_label_5.add_style(style_tool_info_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_info_label_4 = lv.label(tool_info)
tool_info_label_4.set_pos(int(22),int(143))
tool_info_label_4.set_size(100,32)
tool_info_label_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_info_label_4.set_text("Version：")
tool_info_label_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_info_label_4_main_main_default
style_tool_info_label_4_main_main_default = lv.style_t()
style_tool_info_label_4_main_main_default.init()
style_tool_info_label_4_main_main_default.set_radius(0)
style_tool_info_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_info_label_4_main_main_default.set_bg_opa(0)
style_tool_info_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_tool_info_label_4_main_main_default.set_text_font(lv.font_Acme_Regular_12)
except AttributeError:
    try:
        style_tool_info_label_4_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_info_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_info_label_4_main_main_default.set_text_letter_space(2)
style_tool_info_label_4_main_main_default.set_text_line_space(0)
style_tool_info_label_4_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_tool_info_label_4_main_main_default.set_pad_left(0)
style_tool_info_label_4_main_main_default.set_pad_right(0)
style_tool_info_label_4_main_main_default.set_pad_top(0)
style_tool_info_label_4_main_main_default.set_pad_bottom(0)

# add style for tool_info_label_4
tool_info_label_4.add_style(style_tool_info_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_info_label_2 = lv.label(tool_info)
tool_info_label_2.set_pos(int(15),int(81))
tool_info_label_2.set_size(131,16)
tool_info_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_info_label_2.set_text("Machine name：")
tool_info_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_info_label_2_main_main_default
style_tool_info_label_2_main_main_default = lv.style_t()
style_tool_info_label_2_main_main_default.init()
style_tool_info_label_2_main_main_default.set_radius(0)
style_tool_info_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_info_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_info_label_2_main_main_default.set_bg_opa(0)
style_tool_info_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_tool_info_label_2_main_main_default.set_text_font(lv.font_Acme_Regular_12)
except AttributeError:
    try:
        style_tool_info_label_2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_info_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_info_label_2_main_main_default.set_text_letter_space(2)
style_tool_info_label_2_main_main_default.set_text_line_space(0)
style_tool_info_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_tool_info_label_2_main_main_default.set_pad_left(0)
style_tool_info_label_2_main_main_default.set_pad_right(0)
style_tool_info_label_2_main_main_default.set_pad_top(0)
style_tool_info_label_2_main_main_default.set_pad_bottom(0)

# add style for tool_info_label_2
tool_info_label_2.add_style(style_tool_info_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_info_imgbtn_3 = lv.imgbtn(tool_info)
tool_info_imgbtn_3.set_pos(int(420),int(17))
tool_info_imgbtn_3.set_size(25,21)
tool_info_imgbtn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1962976602.png','rb') as f:
        tool_info_imgbtn_3_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1962976602.png')
    sys.exit()

tool_info_imgbtn_3_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_info_imgbtn_3_imgReleased_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 21, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_info_imgbtn_3_imgReleased_data
})
tool_info_imgbtn_3.set_src(lv.imgbtn.STATE.RELEASED, tool_info_imgbtn_3_imgReleased, None, None)





tool_info_imgbtn_3.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_info_imgbtn_3_main_main_default
style_tool_info_imgbtn_3_main_main_default = lv.style_t()
style_tool_info_imgbtn_3_main_main_default.init()
style_tool_info_imgbtn_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_info_imgbtn_3_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_info_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_info_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_info_imgbtn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_info_imgbtn_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_info_imgbtn_3_main_main_default.set_img_recolor_opa(0)
style_tool_info_imgbtn_3_main_main_default.set_img_opa(255)

# add style for tool_info_imgbtn_3
tool_info_imgbtn_3.add_style(style_tool_info_imgbtn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_info_imgbtn_3_main_main_pressed
style_tool_info_imgbtn_3_main_main_pressed = lv.style_t()
style_tool_info_imgbtn_3_main_main_pressed.init()
style_tool_info_imgbtn_3_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_info_imgbtn_3_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_info_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_info_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_info_imgbtn_3_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_info_imgbtn_3_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_info_imgbtn_3_main_main_pressed.set_img_recolor_opa(0)
style_tool_info_imgbtn_3_main_main_pressed.set_img_opa(255)

# add style for tool_info_imgbtn_3
tool_info_imgbtn_3.add_style(style_tool_info_imgbtn_3_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_info_imgbtn_3_main_main_checked
style_tool_info_imgbtn_3_main_main_checked = lv.style_t()
style_tool_info_imgbtn_3_main_main_checked.init()
style_tool_info_imgbtn_3_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_info_imgbtn_3_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_info_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_info_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_info_imgbtn_3_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_info_imgbtn_3_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_info_imgbtn_3_main_main_checked.set_img_recolor_opa(0)
style_tool_info_imgbtn_3_main_main_checked.set_img_opa(255)

# add style for tool_info_imgbtn_3
tool_info_imgbtn_3.add_style(style_tool_info_imgbtn_3_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_wifi = lv.obj()
tool_wifi.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_tool_wifi_main_main_default
style_tool_wifi_main_main_default = lv.style_t()
style_tool_wifi_main_main_default.init()
style_tool_wifi_main_main_default.set_bg_color(lv.color_make(0x1d,0x23,0x32))
style_tool_wifi_main_main_default.set_bg_opa(255)

# add style for tool_wifi
tool_wifi.add_style(style_tool_wifi_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_wifi_label_1 = lv.label(tool_wifi)
tool_wifi_label_1.set_pos(int(15),int(28))
tool_wifi_label_1.set_size(60,18)
tool_wifi_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_wifi_label_1.set_text("Wifi")
tool_wifi_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_wifi_label_1_main_main_default
style_tool_wifi_label_1_main_main_default = lv.style_t()
style_tool_wifi_label_1_main_main_default.init()
style_tool_wifi_label_1_main_main_default.set_radius(0)
style_tool_wifi_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_wifi_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_wifi_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_wifi_label_1_main_main_default.set_bg_opa(0)
style_tool_wifi_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_tool_wifi_label_1_main_main_default.set_text_font(lv.font_montserratMedium_18)
except AttributeError:
    try:
        style_tool_wifi_label_1_main_main_default.set_text_font(lv.font_montserrat_18)
    except AttributeError:
        style_tool_wifi_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_wifi_label_1_main_main_default.set_text_letter_space(2)
style_tool_wifi_label_1_main_main_default.set_text_line_space(0)
style_tool_wifi_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_wifi_label_1_main_main_default.set_pad_left(0)
style_tool_wifi_label_1_main_main_default.set_pad_right(0)
style_tool_wifi_label_1_main_main_default.set_pad_top(0)
style_tool_wifi_label_1_main_main_default.set_pad_bottom(0)

# add style for tool_wifi_label_1
tool_wifi_label_1.add_style(style_tool_wifi_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_wifi_imgbtn_3 = lv.imgbtn(tool_wifi)
tool_wifi_imgbtn_3.set_pos(int(420),int(17))
tool_wifi_imgbtn_3.set_size(25,21)
tool_wifi_imgbtn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1962976602.png','rb') as f:
        tool_wifi_imgbtn_3_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\NewLarseBoxUI\\generated\\mPythonImages\\mp-1962976602.png')
    sys.exit()

tool_wifi_imgbtn_3_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_wifi_imgbtn_3_imgReleased_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 21, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_wifi_imgbtn_3_imgReleased_data
})
tool_wifi_imgbtn_3.set_src(lv.imgbtn.STATE.RELEASED, tool_wifi_imgbtn_3_imgReleased, None, None)





tool_wifi_imgbtn_3.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_wifi_imgbtn_3_main_main_default
style_tool_wifi_imgbtn_3_main_main_default = lv.style_t()
style_tool_wifi_imgbtn_3_main_main_default.init()
style_tool_wifi_imgbtn_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_wifi_imgbtn_3_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_wifi_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_wifi_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_wifi_imgbtn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_wifi_imgbtn_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_wifi_imgbtn_3_main_main_default.set_img_recolor_opa(0)
style_tool_wifi_imgbtn_3_main_main_default.set_img_opa(255)

# add style for tool_wifi_imgbtn_3
tool_wifi_imgbtn_3.add_style(style_tool_wifi_imgbtn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_wifi_imgbtn_3_main_main_pressed
style_tool_wifi_imgbtn_3_main_main_pressed = lv.style_t()
style_tool_wifi_imgbtn_3_main_main_pressed.init()
style_tool_wifi_imgbtn_3_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_wifi_imgbtn_3_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_wifi_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_wifi_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_wifi_imgbtn_3_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_wifi_imgbtn_3_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_wifi_imgbtn_3_main_main_pressed.set_img_recolor_opa(0)
style_tool_wifi_imgbtn_3_main_main_pressed.set_img_opa(255)

# add style for tool_wifi_imgbtn_3
tool_wifi_imgbtn_3.add_style(style_tool_wifi_imgbtn_3_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_wifi_imgbtn_3_main_main_checked
style_tool_wifi_imgbtn_3_main_main_checked = lv.style_t()
style_tool_wifi_imgbtn_3_main_main_checked.init()
style_tool_wifi_imgbtn_3_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_wifi_imgbtn_3_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_wifi_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_wifi_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_wifi_imgbtn_3_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_wifi_imgbtn_3_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_wifi_imgbtn_3_main_main_checked.set_img_recolor_opa(0)
style_tool_wifi_imgbtn_3_main_main_checked.set_img_opa(255)

# add style for tool_wifi_imgbtn_3
tool_wifi_imgbtn_3.add_style(style_tool_wifi_imgbtn_3_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)







# content from custom.py

# Load the default screen
lv.scr_load(home)

while SDL.check():
    time.sleep_ms(5)
