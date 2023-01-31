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
SDL.init(w=480,h=320)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(480*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 480
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



# create screen
screen = lv.obj()
screen.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_screen_main_main_default
style_screen_main_main_default = lv.style_t()
style_screen_main_main_default.init()
style_screen_main_main_default.set_bg_color(lv.color_make(0x1D,0x23,0x32))
style_screen_main_main_default.set_bg_opa(255)

# add style for screen
screen.add_style(style_screen_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create screen_imgbtn_1
screen_imgbtn_1 = lv.imgbtn(screen)
screen_imgbtn_1.set_pos(int(38),int(112))
screen_imgbtn_1.set_size(114,114)
screen_imgbtn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp1257269981.png','rb') as f:
        screen_imgbtn_1_imgReleased_data = f.read()
except:
    print('Could not open C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp1257269981.png')
    sys.exit()

screen_imgbtn_1_imgReleased = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_1_imgReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR},
  'data': screen_imgbtn_1_imgReleased_data
})
screen_imgbtn_1.set_src(lv.imgbtn.STATE.RELEASED, None, screen_imgbtn_1_imgReleased, None)

try:
    with open('C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp1257269981.png','rb') as f:
        screen_imgbtn_1_imgPressed_data = f.read()
except:
    print('Could not open C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp1257269981.png')
    sys.exit()

screen_imgbtn_1_imgPressed = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_1_imgPressed_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR},
  'data': screen_imgbtn_1_imgPressed_data
})
screen_imgbtn_1.set_src(lv.imgbtn.STATE.PRESSED, None, screen_imgbtn_1_imgPressed, None)


try:
    with open('C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp1257269981.png','rb') as f:
        screen_imgbtn_1_imgCheckedReleased_data = f.read()
except:
    print('Could not open C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp1257269981.png')
    sys.exit()

screen_imgbtn_1_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_1_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR},
  'data': screen_imgbtn_1_imgCheckedReleased_data
})
screen_imgbtn_1.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, screen_imgbtn_1_imgCheckedReleased, None)

try:
    with open('C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp1257269981.png','rb') as f:
        screen_imgbtn_1_imgCheckedPressed_data = f.read()
except:
    print('Could not open C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp1257269981.png')
    sys.exit()

screen_imgbtn_1_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_1_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR},
  'data': screen_imgbtn_1_imgCheckedPressed_data
})
screen_imgbtn_1.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, screen_imgbtn_1_imgCheckedPressed, None)

screen_imgbtn_1.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_screen_imgbtn_1_main_main_default
style_screen_imgbtn_1_main_main_default = lv.style_t()
style_screen_imgbtn_1_main_main_default.init()
style_screen_imgbtn_1_main_main_default.set_text_color(lv.color_make(0xee,0xe1,0xe1))
try:
    style_screen_imgbtn_1_main_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_screen_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_imgbtn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_imgbtn_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_imgbtn_1_main_main_default.set_img_recolor_opa(0)
style_screen_imgbtn_1_main_main_default.set_img_opa(255)

# add style for screen_imgbtn_1
screen_imgbtn_1.add_style(style_screen_imgbtn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_imgbtn_1_main_main_pressed
style_screen_imgbtn_1_main_main_pressed = lv.style_t()
style_screen_imgbtn_1_main_main_pressed.init()
style_screen_imgbtn_1_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_screen_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_screen_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_screen_imgbtn_1_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_screen_imgbtn_1_main_main_pressed.set_img_recolor_opa(0)
style_screen_imgbtn_1_main_main_pressed.set_img_opa(255)

# add style for screen_imgbtn_1
screen_imgbtn_1.add_style(style_screen_imgbtn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_screen_imgbtn_1_main_main_checked
style_screen_imgbtn_1_main_main_checked = lv.style_t()
style_screen_imgbtn_1_main_main_checked.init()
style_screen_imgbtn_1_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_screen_imgbtn_1_main_main_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_screen_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_16)
style_screen_imgbtn_1_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_screen_imgbtn_1_main_main_checked.set_img_recolor_opa(0)
style_screen_imgbtn_1_main_main_checked.set_img_opa(255)

# add style for screen_imgbtn_1
screen_imgbtn_1.add_style(style_screen_imgbtn_1_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create screen_imgbtn_2
screen_imgbtn_2 = lv.imgbtn(screen)
screen_imgbtn_2.set_pos(int(183),int(112))
screen_imgbtn_2.set_size(114,114)
screen_imgbtn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp751669586.png','rb') as f:
        screen_imgbtn_2_imgReleased_data = f.read()
except:
    print('Could not open C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp751669586.png')
    sys.exit()

screen_imgbtn_2_imgReleased = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_2_imgReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_imgbtn_2_imgReleased_data
})
screen_imgbtn_2.set_src(lv.imgbtn.STATE.RELEASED, None, screen_imgbtn_2_imgReleased, None)

try:
    with open('C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp751669586.png','rb') as f:
        screen_imgbtn_2_imgPressed_data = f.read()
except:
    print('Could not open C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp751669586.png')
    sys.exit()

screen_imgbtn_2_imgPressed = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_2_imgPressed_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_imgbtn_2_imgPressed_data
})
screen_imgbtn_2.set_src(lv.imgbtn.STATE.PRESSED, None, screen_imgbtn_2_imgPressed, None)


try:
    with open('C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp751669586.png','rb') as f:
        screen_imgbtn_2_imgCheckedReleased_data = f.read()
except:
    print('Could not open C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp751669586.png')
    sys.exit()

screen_imgbtn_2_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_2_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_imgbtn_2_imgCheckedReleased_data
})
screen_imgbtn_2.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, screen_imgbtn_2_imgCheckedReleased, None)

try:
    with open('C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp751669586.png','rb') as f:
        screen_imgbtn_2_imgCheckedPressed_data = f.read()
except:
    print('Could not open C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp751669586.png')
    sys.exit()

screen_imgbtn_2_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_2_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_imgbtn_2_imgCheckedPressed_data
})
screen_imgbtn_2.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, screen_imgbtn_2_imgCheckedPressed, None)

screen_imgbtn_2.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_screen_imgbtn_2_main_main_default
style_screen_imgbtn_2_main_main_default = lv.style_t()
style_screen_imgbtn_2_main_main_default.init()
style_screen_imgbtn_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_imgbtn_2_main_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_screen_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_imgbtn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_imgbtn_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_imgbtn_2_main_main_default.set_img_recolor_opa(0)
style_screen_imgbtn_2_main_main_default.set_img_opa(255)

# add style for screen_imgbtn_2
screen_imgbtn_2.add_style(style_screen_imgbtn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_imgbtn_2_main_main_pressed
style_screen_imgbtn_2_main_main_pressed = lv.style_t()
style_screen_imgbtn_2_main_main_pressed.init()
style_screen_imgbtn_2_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_screen_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_screen_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_screen_imgbtn_2_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_screen_imgbtn_2_main_main_pressed.set_img_recolor_opa(0)
style_screen_imgbtn_2_main_main_pressed.set_img_opa(255)

# add style for screen_imgbtn_2
screen_imgbtn_2.add_style(style_screen_imgbtn_2_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_screen_imgbtn_2_main_main_checked
style_screen_imgbtn_2_main_main_checked = lv.style_t()
style_screen_imgbtn_2_main_main_checked.init()
style_screen_imgbtn_2_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_screen_imgbtn_2_main_main_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_screen_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_16)
style_screen_imgbtn_2_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_screen_imgbtn_2_main_main_checked.set_img_recolor_opa(0)
style_screen_imgbtn_2_main_main_checked.set_img_opa(255)

# add style for screen_imgbtn_2
screen_imgbtn_2.add_style(style_screen_imgbtn_2_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create screen_imgbtn_3
screen_imgbtn_3 = lv.imgbtn(screen)
screen_imgbtn_3.set_pos(int(328),int(112))
screen_imgbtn_3.set_size(114,114)
screen_imgbtn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp-1904199085.png','rb') as f:
        screen_imgbtn_3_imgReleased_data = f.read()
except:
    print('Could not open C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp-1904199085.png')
    sys.exit()

screen_imgbtn_3_imgReleased = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_3_imgReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_imgbtn_3_imgReleased_data
})
screen_imgbtn_3.set_src(lv.imgbtn.STATE.RELEASED, None, screen_imgbtn_3_imgReleased, None)

try:
    with open('C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp-1904199085.png','rb') as f:
        screen_imgbtn_3_imgPressed_data = f.read()
except:
    print('Could not open C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp-1904199085.png')
    sys.exit()

screen_imgbtn_3_imgPressed = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_3_imgPressed_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_imgbtn_3_imgPressed_data
})
screen_imgbtn_3.set_src(lv.imgbtn.STATE.PRESSED, None, screen_imgbtn_3_imgPressed, None)


try:
    with open('C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp-1904199085.png','rb') as f:
        screen_imgbtn_3_imgCheckedReleased_data = f.read()
except:
    print('Could not open C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp-1904199085.png')
    sys.exit()

screen_imgbtn_3_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_3_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_imgbtn_3_imgCheckedReleased_data
})
screen_imgbtn_3.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, screen_imgbtn_3_imgCheckedReleased, None)

try:
    with open('C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp-1904199085.png','rb') as f:
        screen_imgbtn_3_imgCheckedPressed_data = f.read()
except:
    print('Could not open C:\\Users\\12250\\Desktop\\DDD\\WZMK\\generated\\mPythonImages\\mp-1904199085.png')
    sys.exit()

screen_imgbtn_3_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(screen_imgbtn_3_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': screen_imgbtn_3_imgCheckedPressed_data
})
screen_imgbtn_3.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, screen_imgbtn_3_imgCheckedPressed, None)

screen_imgbtn_3.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_screen_imgbtn_3_main_main_default
style_screen_imgbtn_3_main_main_default = lv.style_t()
style_screen_imgbtn_3_main_main_default.init()
style_screen_imgbtn_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_screen_imgbtn_3_main_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_screen_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_imgbtn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_imgbtn_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_screen_imgbtn_3_main_main_default.set_img_recolor_opa(0)
style_screen_imgbtn_3_main_main_default.set_img_opa(255)

# add style for screen_imgbtn_3
screen_imgbtn_3.add_style(style_screen_imgbtn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_screen_imgbtn_3_main_main_pressed
style_screen_imgbtn_3_main_main_pressed = lv.style_t()
style_screen_imgbtn_3_main_main_pressed.init()
style_screen_imgbtn_3_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_screen_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_screen_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_screen_imgbtn_3_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_screen_imgbtn_3_main_main_pressed.set_img_recolor_opa(0)
style_screen_imgbtn_3_main_main_pressed.set_img_opa(255)

# add style for screen_imgbtn_3
screen_imgbtn_3.add_style(style_screen_imgbtn_3_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_screen_imgbtn_3_main_main_checked
style_screen_imgbtn_3_main_main_checked = lv.style_t()
style_screen_imgbtn_3_main_main_checked.init()
style_screen_imgbtn_3_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_screen_imgbtn_3_main_main_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_screen_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_screen_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_16)
style_screen_imgbtn_3_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_screen_imgbtn_3_main_main_checked.set_img_recolor_opa(0)
style_screen_imgbtn_3_main_main_checked.set_img_opa(255)

# add style for screen_imgbtn_3
screen_imgbtn_3.add_style(style_screen_imgbtn_3_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create screen_label_1
screen_label_1 = lv.label(screen)
screen_label_1.set_pos(int(38),int(226))
screen_label_1.set_size(114,32)
screen_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_1.set_text("Engraving")
screen_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_1_main_main_default
style_screen_label_1_main_main_default = lv.style_t()
style_screen_label_1_main_main_default.init()
style_screen_label_1_main_main_default.set_radius(0)
style_screen_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_label_1_main_main_default.set_bg_opa(0)
style_screen_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen_label_1_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_screen_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_1_main_main_default.set_text_letter_space(2)
style_screen_label_1_main_main_default.set_text_line_space(0)
style_screen_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_1_main_main_default.set_pad_left(0)
style_screen_label_1_main_main_default.set_pad_right(0)
style_screen_label_1_main_main_default.set_pad_top(8)
style_screen_label_1_main_main_default.set_pad_bottom(0)

# add style for screen_label_1
screen_label_1.add_style(style_screen_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create screen_label_2
screen_label_2 = lv.label(screen)
screen_label_2.set_pos(int(183),int(226))
screen_label_2.set_size(114,32)
screen_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_2.set_text("Control")
screen_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_2_main_main_default
style_screen_label_2_main_main_default = lv.style_t()
style_screen_label_2_main_main_default.init()
style_screen_label_2_main_main_default.set_radius(0)
style_screen_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_label_2_main_main_default.set_bg_opa(0)
style_screen_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen_label_2_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_screen_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_2_main_main_default.set_text_letter_space(2)
style_screen_label_2_main_main_default.set_text_line_space(0)
style_screen_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_2_main_main_default.set_pad_left(0)
style_screen_label_2_main_main_default.set_pad_right(0)
style_screen_label_2_main_main_default.set_pad_top(8)
style_screen_label_2_main_main_default.set_pad_bottom(0)

# add style for screen_label_2
screen_label_2.add_style(style_screen_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create screen_label_3
screen_label_3 = lv.label(screen)
screen_label_3.set_pos(int(328),int(226))
screen_label_3.set_size(114,32)
screen_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_label_3.set_text("Tool")
screen_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_screen_label_3_main_main_default
style_screen_label_3_main_main_default = lv.style_t()
style_screen_label_3_main_main_default.init()
style_screen_label_3_main_main_default.set_radius(0)
style_screen_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_screen_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_screen_label_3_main_main_default.set_bg_opa(0)
style_screen_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_screen_label_3_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_screen_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_screen_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_screen_label_3_main_main_default.set_text_letter_space(2)
style_screen_label_3_main_main_default.set_text_line_space(0)
style_screen_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_screen_label_3_main_main_default.set_pad_left(0)
style_screen_label_3_main_main_default.set_pad_right(0)
style_screen_label_3_main_main_default.set_pad_top(8)
style_screen_label_3_main_main_default.set_pad_bottom(0)

# add style for screen_label_3
screen_label_3.add_style(style_screen_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create Engraving
Engraving = lv.obj()
Engraving.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_engraving_main_main_default
style_engraving_main_main_default = lv.style_t()
style_engraving_main_main_default.init()
style_engraving_main_main_default.set_bg_color(lv.color_make(0x1D,0x23,0x32))
style_engraving_main_main_default.set_bg_opa(255)

# add style for Engraving
Engraving.add_style(style_engraving_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create Engraving_btn_1
Engraving_btn_1 = lv.btn(Engraving)
Engraving_btn_1.set_pos(int(252),int(80))
Engraving_btn_1.set_size(212,37)
Engraving_btn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Engraving_btn_1_label = lv.label(Engraving_btn_1)
Engraving_btn_1_label.set_text("Frame")
Engraving_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
Engraving_btn_1_label.align(lv.ALIGN.CENTER,0,0)
# create style style_engraving_btn_1_main_main_default
style_engraving_btn_1_main_main_default = lv.style_t()
style_engraving_btn_1_main_main_default.init()
style_engraving_btn_1_main_main_default.set_radius(20)
style_engraving_btn_1_main_main_default.set_bg_color(lv.color_make(0x20,0x27,0x3A))
style_engraving_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_btn_1_main_main_default.set_bg_opa(255)
style_engraving_btn_1_main_main_default.set_border_color(lv.color_make(0xFF,0x57,0x00))
style_engraving_btn_1_main_main_default.set_border_width(1)
style_engraving_btn_1_main_main_default.set_border_opa(255)
style_engraving_btn_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_btn_1_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_btn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_btn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for Engraving_btn_1
Engraving_btn_1.add_style(style_engraving_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create Engraving_btn_2
Engraving_btn_2 = lv.btn(Engraving)
Engraving_btn_2.set_pos(int(252),int(134))
Engraving_btn_2.set_size(212,37)
Engraving_btn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Engraving_btn_2_label = lv.label(Engraving_btn_2)
Engraving_btn_2_label.set_text("Home")
Engraving_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
Engraving_btn_2_label.align(lv.ALIGN.CENTER,0,0)
# create style style_engraving_btn_2_main_main_default
style_engraving_btn_2_main_main_default = lv.style_t()
style_engraving_btn_2_main_main_default.init()
style_engraving_btn_2_main_main_default.set_radius(20)
style_engraving_btn_2_main_main_default.set_bg_color(lv.color_make(0x20,0x27,0x3A))
style_engraving_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_btn_2_main_main_default.set_bg_opa(255)
style_engraving_btn_2_main_main_default.set_border_color(lv.color_make(0xFF,0x57,0x00))
style_engraving_btn_2_main_main_default.set_border_width(1)
style_engraving_btn_2_main_main_default.set_border_opa(255)
style_engraving_btn_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_btn_2_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_btn_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_btn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_btn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for Engraving_btn_2
Engraving_btn_2.add_style(style_engraving_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create Engraving_btn_3
Engraving_btn_3 = lv.btn(Engraving)
Engraving_btn_3.set_pos(int(252),int(188))
Engraving_btn_3.set_size(212,37)
Engraving_btn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Engraving_btn_3_label = lv.label(Engraving_btn_3)
Engraving_btn_3_label.set_text("Position")
Engraving_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
Engraving_btn_3_label.align(lv.ALIGN.CENTER,0,0)
# create style style_engraving_btn_3_main_main_default
style_engraving_btn_3_main_main_default = lv.style_t()
style_engraving_btn_3_main_main_default.init()
style_engraving_btn_3_main_main_default.set_radius(20)
style_engraving_btn_3_main_main_default.set_bg_color(lv.color_make(0x20,0x27,0x3A))
style_engraving_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_btn_3_main_main_default.set_bg_opa(255)
style_engraving_btn_3_main_main_default.set_border_color(lv.color_make(0xFF,0x57,0x00))
style_engraving_btn_3_main_main_default.set_border_width(1)
style_engraving_btn_3_main_main_default.set_border_opa(255)
style_engraving_btn_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_btn_3_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_btn_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_btn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_btn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for Engraving_btn_3
Engraving_btn_3.add_style(style_engraving_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create Engraving_btn_4
Engraving_btn_4 = lv.btn(Engraving)
Engraving_btn_4.set_pos(int(270),int(240))
Engraving_btn_4.set_size(175,50)
Engraving_btn_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Engraving_btn_4_label = lv.label(Engraving_btn_4)
Engraving_btn_4_label.set_text("Start")
Engraving_btn_4.set_style_pad_all(0, lv.STATE.DEFAULT)
Engraving_btn_4_label.align(lv.ALIGN.CENTER,0,0)
# create style style_engraving_btn_4_main_main_default
style_engraving_btn_4_main_main_default = lv.style_t()
style_engraving_btn_4_main_main_default.init()
style_engraving_btn_4_main_main_default.set_radius(25)
style_engraving_btn_4_main_main_default.set_bg_color(lv.color_make(0x20,0x27,0x3A))
style_engraving_btn_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_btn_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_btn_4_main_main_default.set_bg_opa(255)
style_engraving_btn_4_main_main_default.set_border_color(lv.color_make(0xff,0x57,0x00))
style_engraving_btn_4_main_main_default.set_border_width(2)
style_engraving_btn_4_main_main_default.set_border_opa(255)
style_engraving_btn_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_btn_4_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_btn_4_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_btn_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_btn_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for Engraving_btn_4
Engraving_btn_4.add_style(style_engraving_btn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create Engraving_label_1
Engraving_label_1 = lv.label(Engraving)
Engraving_label_1.set_pos(int(10),int(22))
Engraving_label_1.set_size(135,33)
Engraving_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Engraving_label_1.set_text("Engraving-")
Engraving_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_engraving_label_1_main_main_default
style_engraving_label_1_main_main_default = lv.style_t()
style_engraving_label_1_main_main_default.init()
style_engraving_label_1_main_main_default.set_radius(0)
style_engraving_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_label_1_main_main_default.set_bg_opa(0)
style_engraving_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_label_1_main_main_default.set_text_font(lv.font_montserratMedium_20)
except AttributeError:
    try:
        style_engraving_label_1_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_engraving_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_label_1_main_main_default.set_text_letter_space(2)
style_engraving_label_1_main_main_default.set_text_line_space(0)
style_engraving_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_engraving_label_1_main_main_default.set_pad_left(0)
style_engraving_label_1_main_main_default.set_pad_right(0)
style_engraving_label_1_main_main_default.set_pad_top(8)
style_engraving_label_1_main_main_default.set_pad_bottom(0)

# add style for Engraving_label_1
Engraving_label_1.add_style(style_engraving_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create Engraving_label_2
Engraving_label_2 = lv.label(Engraving)
Engraving_label_2.set_pos(int(141),int(26))
Engraving_label_2.set_size(110,25)
Engraving_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Engraving_label_2.set_text("Filename")
Engraving_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_engraving_label_2_main_main_default
style_engraving_label_2_main_main_default = lv.style_t()
style_engraving_label_2_main_main_default.init()
style_engraving_label_2_main_main_default.set_radius(0)
style_engraving_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_label_2_main_main_default.set_bg_opa(0)
style_engraving_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_label_2_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_label_2_main_main_default.set_text_letter_space(2)
style_engraving_label_2_main_main_default.set_text_line_space(0)
style_engraving_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_engraving_label_2_main_main_default.set_pad_left(0)
style_engraving_label_2_main_main_default.set_pad_right(0)
style_engraving_label_2_main_main_default.set_pad_top(8)
style_engraving_label_2_main_main_default.set_pad_bottom(0)

# add style for Engraving_label_2
Engraving_label_2.add_style(style_engraving_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create Engraving_btn_5
Engraving_btn_5 = lv.btn(Engraving)
Engraving_btn_5.set_pos(int(364),int(13))
Engraving_btn_5.set_size(100,50)
Engraving_btn_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Engraving_btn_5_label = lv.label(Engraving_btn_5)
Engraving_btn_5_label.set_text("Back")
Engraving_btn_5.set_style_pad_all(0, lv.STATE.DEFAULT)
Engraving_btn_5_label.align(lv.ALIGN.CENTER,0,0)
# create style style_engraving_btn_5_main_main_default
style_engraving_btn_5_main_main_default = lv.style_t()
style_engraving_btn_5_main_main_default.init()
style_engraving_btn_5_main_main_default.set_radius(20)
style_engraving_btn_5_main_main_default.set_bg_color(lv.color_make(0x20,0x27,0x3A))
style_engraving_btn_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_btn_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_btn_5_main_main_default.set_bg_opa(255)
style_engraving_btn_5_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_btn_5_main_main_default.set_border_width(1)
style_engraving_btn_5_main_main_default.set_border_opa(255)
style_engraving_btn_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_btn_5_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_btn_5_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_btn_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_btn_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for Engraving_btn_5
Engraving_btn_5.add_style(style_engraving_btn_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)



def screen_imgbtn_1_released_1_event_cb(e,Engraving):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Engraving, lv.SCR_LOAD_ANIM.OVER_LEFT, 100, 100, False)
screen_imgbtn_1.add_event_cb(lambda e: screen_imgbtn_1_released_1_event_cb(e,Engraving), lv.EVENT.RELEASED, None)


def Engraving_btn_5_released_1_event_cb(e,screen):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(screen, lv.SCR_LOAD_ANIM.OVER_RIGHT, 100, 100, False)
Engraving_btn_5.add_event_cb(lambda e: Engraving_btn_5_released_1_event_cb(e,screen), lv.EVENT.RELEASED, None)



# content from custom.py

# Load the default screen
lv.scr_load(screen)

while SDL.check():
    time.sleep_ms(5)
