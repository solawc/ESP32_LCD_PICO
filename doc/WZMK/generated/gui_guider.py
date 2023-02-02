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



# create logo_page
logo_page = lv.obj()
logo_page.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_logo_page_main_main_default
style_logo_page_main_main_default = lv.style_t()
style_logo_page_main_main_default.init()
style_logo_page_main_main_default.set_bg_color(lv.color_make(0xFF,0xFF,0xFf))
style_logo_page_main_main_default.set_bg_opa(255)

# add style for logo_page
logo_page.add_style(style_logo_page_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create logo_page_logo_label
logo_page_logo_label = lv.label(logo_page)
logo_page_logo_label.set_pos(int(155),int(133))
logo_page_logo_label.set_size(186,45)
logo_page_logo_label.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
logo_page_logo_label.set_text("MakeGo")
logo_page_logo_label.set_long_mode(lv.label.LONG.WRAP)
# create style style_logo_page_logo_label_main_main_default
style_logo_page_logo_label_main_main_default = lv.style_t()
style_logo_page_logo_label_main_main_default.init()
style_logo_page_logo_label_main_main_default.set_radius(0)
style_logo_page_logo_label_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_logo_page_logo_label_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_logo_page_logo_label_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_logo_page_logo_label_main_main_default.set_bg_opa(255)
style_logo_page_logo_label_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_logo_page_logo_label_main_main_default.set_text_font(lv.font_montserratMedium_20)
except AttributeError:
    try:
        style_logo_page_logo_label_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_logo_page_logo_label_main_main_default.set_text_font(lv.font_montserrat_16)
style_logo_page_logo_label_main_main_default.set_text_letter_space(2)
style_logo_page_logo_label_main_main_default.set_text_line_space(0)
style_logo_page_logo_label_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_logo_page_logo_label_main_main_default.set_pad_left(0)
style_logo_page_logo_label_main_main_default.set_pad_right(0)
style_logo_page_logo_label_main_main_default.set_pad_top(8)
style_logo_page_logo_label_main_main_default.set_pad_bottom(0)

# add style for logo_page_logo_label
logo_page_logo_label.add_style(style_logo_page_logo_label_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create main_page
main_page = lv.obj()
main_page.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_main_page_main_main_default
style_main_page_main_main_default = lv.style_t()
style_main_page_main_main_default.init()
style_main_page_main_main_default.set_bg_color(lv.color_make(0x1D,0x23,0x32))
style_main_page_main_main_default.set_bg_opa(255)

# add style for main_page
main_page.add_style(style_main_page_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create main_page_imgbtn_1
main_page_imgbtn_1 = lv.imgbtn(main_page)
main_page_imgbtn_1.set_pos(int(38),int(112))
main_page_imgbtn_1.set_size(114,114)
main_page_imgbtn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp793593209.png','rb') as f:
        main_page_imgbtn_1_imgReleased_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp793593209.png')
    sys.exit()

main_page_imgbtn_1_imgReleased = lv.img_dsc_t({
  'data_size': len(main_page_imgbtn_1_imgReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR},
  'data': main_page_imgbtn_1_imgReleased_data
})
main_page_imgbtn_1.set_src(lv.imgbtn.STATE.RELEASED, None, main_page_imgbtn_1_imgReleased, None)

try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp793593209.png','rb') as f:
        main_page_imgbtn_1_imgPressed_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp793593209.png')
    sys.exit()

main_page_imgbtn_1_imgPressed = lv.img_dsc_t({
  'data_size': len(main_page_imgbtn_1_imgPressed_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR},
  'data': main_page_imgbtn_1_imgPressed_data
})
main_page_imgbtn_1.set_src(lv.imgbtn.STATE.PRESSED, None, main_page_imgbtn_1_imgPressed, None)


try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp793593209.png','rb') as f:
        main_page_imgbtn_1_imgCheckedReleased_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp793593209.png')
    sys.exit()

main_page_imgbtn_1_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(main_page_imgbtn_1_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR},
  'data': main_page_imgbtn_1_imgCheckedReleased_data
})
main_page_imgbtn_1.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, main_page_imgbtn_1_imgCheckedReleased, None)

try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp793593209.png','rb') as f:
        main_page_imgbtn_1_imgCheckedPressed_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp793593209.png')
    sys.exit()

main_page_imgbtn_1_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(main_page_imgbtn_1_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR},
  'data': main_page_imgbtn_1_imgCheckedPressed_data
})
main_page_imgbtn_1.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, main_page_imgbtn_1_imgCheckedPressed, None)

main_page_imgbtn_1.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_main_page_imgbtn_1_main_main_default
style_main_page_imgbtn_1_main_main_default = lv.style_t()
style_main_page_imgbtn_1_main_main_default.init()
style_main_page_imgbtn_1_main_main_default.set_text_color(lv.color_make(0xee,0xe1,0xe1))
try:
    style_main_page_imgbtn_1_main_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_main_page_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_main_page_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_main_page_imgbtn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_main_page_imgbtn_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_main_page_imgbtn_1_main_main_default.set_img_recolor_opa(0)
style_main_page_imgbtn_1_main_main_default.set_img_opa(255)

# add style for main_page_imgbtn_1
main_page_imgbtn_1.add_style(style_main_page_imgbtn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_main_page_imgbtn_1_main_main_pressed
style_main_page_imgbtn_1_main_main_pressed = lv.style_t()
style_main_page_imgbtn_1_main_main_pressed.init()
style_main_page_imgbtn_1_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_main_page_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_main_page_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_main_page_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_main_page_imgbtn_1_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_main_page_imgbtn_1_main_main_pressed.set_img_recolor_opa(0)
style_main_page_imgbtn_1_main_main_pressed.set_img_opa(255)

# add style for main_page_imgbtn_1
main_page_imgbtn_1.add_style(style_main_page_imgbtn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_main_page_imgbtn_1_main_main_checked
style_main_page_imgbtn_1_main_main_checked = lv.style_t()
style_main_page_imgbtn_1_main_main_checked.init()
style_main_page_imgbtn_1_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_main_page_imgbtn_1_main_main_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_main_page_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_main_page_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_16)
style_main_page_imgbtn_1_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_main_page_imgbtn_1_main_main_checked.set_img_recolor_opa(0)
style_main_page_imgbtn_1_main_main_checked.set_img_opa(255)

# add style for main_page_imgbtn_1
main_page_imgbtn_1.add_style(style_main_page_imgbtn_1_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create main_page_imgbtn_2
main_page_imgbtn_2 = lv.imgbtn(main_page)
main_page_imgbtn_2.set_pos(int(183),int(112))
main_page_imgbtn_2.set_size(114,114)
main_page_imgbtn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp-1950106130.png','rb') as f:
        main_page_imgbtn_2_imgReleased_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp-1950106130.png')
    sys.exit()

main_page_imgbtn_2_imgReleased = lv.img_dsc_t({
  'data_size': len(main_page_imgbtn_2_imgReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': main_page_imgbtn_2_imgReleased_data
})
main_page_imgbtn_2.set_src(lv.imgbtn.STATE.RELEASED, None, main_page_imgbtn_2_imgReleased, None)

try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp-1950106130.png','rb') as f:
        main_page_imgbtn_2_imgPressed_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp-1950106130.png')
    sys.exit()

main_page_imgbtn_2_imgPressed = lv.img_dsc_t({
  'data_size': len(main_page_imgbtn_2_imgPressed_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': main_page_imgbtn_2_imgPressed_data
})
main_page_imgbtn_2.set_src(lv.imgbtn.STATE.PRESSED, None, main_page_imgbtn_2_imgPressed, None)


try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp-1950106130.png','rb') as f:
        main_page_imgbtn_2_imgCheckedReleased_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp-1950106130.png')
    sys.exit()

main_page_imgbtn_2_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(main_page_imgbtn_2_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': main_page_imgbtn_2_imgCheckedReleased_data
})
main_page_imgbtn_2.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, main_page_imgbtn_2_imgCheckedReleased, None)

try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp-1950106130.png','rb') as f:
        main_page_imgbtn_2_imgCheckedPressed_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp-1950106130.png')
    sys.exit()

main_page_imgbtn_2_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(main_page_imgbtn_2_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': main_page_imgbtn_2_imgCheckedPressed_data
})
main_page_imgbtn_2.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, main_page_imgbtn_2_imgCheckedPressed, None)

main_page_imgbtn_2.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_main_page_imgbtn_2_main_main_default
style_main_page_imgbtn_2_main_main_default = lv.style_t()
style_main_page_imgbtn_2_main_main_default.init()
style_main_page_imgbtn_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_main_page_imgbtn_2_main_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_main_page_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_main_page_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_main_page_imgbtn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_main_page_imgbtn_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_main_page_imgbtn_2_main_main_default.set_img_recolor_opa(0)
style_main_page_imgbtn_2_main_main_default.set_img_opa(255)

# add style for main_page_imgbtn_2
main_page_imgbtn_2.add_style(style_main_page_imgbtn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_main_page_imgbtn_2_main_main_pressed
style_main_page_imgbtn_2_main_main_pressed = lv.style_t()
style_main_page_imgbtn_2_main_main_pressed.init()
style_main_page_imgbtn_2_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_main_page_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_main_page_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_main_page_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_main_page_imgbtn_2_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_main_page_imgbtn_2_main_main_pressed.set_img_recolor_opa(0)
style_main_page_imgbtn_2_main_main_pressed.set_img_opa(255)

# add style for main_page_imgbtn_2
main_page_imgbtn_2.add_style(style_main_page_imgbtn_2_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_main_page_imgbtn_2_main_main_checked
style_main_page_imgbtn_2_main_main_checked = lv.style_t()
style_main_page_imgbtn_2_main_main_checked.init()
style_main_page_imgbtn_2_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_main_page_imgbtn_2_main_main_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_main_page_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_main_page_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_16)
style_main_page_imgbtn_2_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_main_page_imgbtn_2_main_main_checked.set_img_recolor_opa(0)
style_main_page_imgbtn_2_main_main_checked.set_img_opa(255)

# add style for main_page_imgbtn_2
main_page_imgbtn_2.add_style(style_main_page_imgbtn_2_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create main_page_imgbtn_3
main_page_imgbtn_3 = lv.imgbtn(main_page)
main_page_imgbtn_3.set_pos(int(328),int(112))
main_page_imgbtn_3.set_size(114,114)
main_page_imgbtn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp901690167.png','rb') as f:
        main_page_imgbtn_3_imgReleased_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp901690167.png')
    sys.exit()

main_page_imgbtn_3_imgReleased = lv.img_dsc_t({
  'data_size': len(main_page_imgbtn_3_imgReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': main_page_imgbtn_3_imgReleased_data
})
main_page_imgbtn_3.set_src(lv.imgbtn.STATE.RELEASED, None, main_page_imgbtn_3_imgReleased, None)

try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp901690167.png','rb') as f:
        main_page_imgbtn_3_imgPressed_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp901690167.png')
    sys.exit()

main_page_imgbtn_3_imgPressed = lv.img_dsc_t({
  'data_size': len(main_page_imgbtn_3_imgPressed_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': main_page_imgbtn_3_imgPressed_data
})
main_page_imgbtn_3.set_src(lv.imgbtn.STATE.PRESSED, None, main_page_imgbtn_3_imgPressed, None)


try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp901690167.png','rb') as f:
        main_page_imgbtn_3_imgCheckedReleased_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp901690167.png')
    sys.exit()

main_page_imgbtn_3_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(main_page_imgbtn_3_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': main_page_imgbtn_3_imgCheckedReleased_data
})
main_page_imgbtn_3.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, None, main_page_imgbtn_3_imgCheckedReleased, None)

try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp901690167.png','rb') as f:
        main_page_imgbtn_3_imgCheckedPressed_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp901690167.png')
    sys.exit()

main_page_imgbtn_3_imgCheckedPressed = lv.img_dsc_t({
  'data_size': len(main_page_imgbtn_3_imgCheckedPressed_data),
  'header': {'always_zero': 0, 'w': 114, 'h': 114, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': main_page_imgbtn_3_imgCheckedPressed_data
})
main_page_imgbtn_3.set_src(lv.imgbtn.STATE.CHECKED_PRESSED, None, main_page_imgbtn_3_imgCheckedPressed, None)

main_page_imgbtn_3.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_main_page_imgbtn_3_main_main_default
style_main_page_imgbtn_3_main_main_default = lv.style_t()
style_main_page_imgbtn_3_main_main_default.init()
style_main_page_imgbtn_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_main_page_imgbtn_3_main_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_main_page_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_main_page_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_main_page_imgbtn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_main_page_imgbtn_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_main_page_imgbtn_3_main_main_default.set_img_recolor_opa(0)
style_main_page_imgbtn_3_main_main_default.set_img_opa(255)

# add style for main_page_imgbtn_3
main_page_imgbtn_3.add_style(style_main_page_imgbtn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_main_page_imgbtn_3_main_main_pressed
style_main_page_imgbtn_3_main_main_pressed = lv.style_t()
style_main_page_imgbtn_3_main_main_pressed.init()
style_main_page_imgbtn_3_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_main_page_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_main_page_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_main_page_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_main_page_imgbtn_3_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_main_page_imgbtn_3_main_main_pressed.set_img_recolor_opa(0)
style_main_page_imgbtn_3_main_main_pressed.set_img_opa(255)

# add style for main_page_imgbtn_3
main_page_imgbtn_3.add_style(style_main_page_imgbtn_3_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_main_page_imgbtn_3_main_main_checked
style_main_page_imgbtn_3_main_main_checked = lv.style_t()
style_main_page_imgbtn_3_main_main_checked.init()
style_main_page_imgbtn_3_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_main_page_imgbtn_3_main_main_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_main_page_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_main_page_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_16)
style_main_page_imgbtn_3_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_main_page_imgbtn_3_main_main_checked.set_img_recolor_opa(0)
style_main_page_imgbtn_3_main_main_checked.set_img_opa(255)

# add style for main_page_imgbtn_3
main_page_imgbtn_3.add_style(style_main_page_imgbtn_3_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create main_page_label_1
main_page_label_1 = lv.label(main_page)
main_page_label_1.set_pos(int(38),int(226))
main_page_label_1.set_size(114,32)
main_page_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
main_page_label_1.set_text("Engraving")
main_page_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_main_page_label_1_main_main_default
style_main_page_label_1_main_main_default = lv.style_t()
style_main_page_label_1_main_main_default.init()
style_main_page_label_1_main_main_default.set_radius(0)
style_main_page_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_main_page_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_main_page_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_main_page_label_1_main_main_default.set_bg_opa(0)
style_main_page_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_main_page_label_1_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_main_page_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_main_page_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_main_page_label_1_main_main_default.set_text_letter_space(2)
style_main_page_label_1_main_main_default.set_text_line_space(0)
style_main_page_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_main_page_label_1_main_main_default.set_pad_left(0)
style_main_page_label_1_main_main_default.set_pad_right(0)
style_main_page_label_1_main_main_default.set_pad_top(8)
style_main_page_label_1_main_main_default.set_pad_bottom(0)

# add style for main_page_label_1
main_page_label_1.add_style(style_main_page_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create main_page_label_2
main_page_label_2 = lv.label(main_page)
main_page_label_2.set_pos(int(183),int(226))
main_page_label_2.set_size(114,32)
main_page_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
main_page_label_2.set_text("Control")
main_page_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_main_page_label_2_main_main_default
style_main_page_label_2_main_main_default = lv.style_t()
style_main_page_label_2_main_main_default.init()
style_main_page_label_2_main_main_default.set_radius(0)
style_main_page_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_main_page_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_main_page_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_main_page_label_2_main_main_default.set_bg_opa(0)
style_main_page_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_main_page_label_2_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_main_page_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_main_page_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_main_page_label_2_main_main_default.set_text_letter_space(2)
style_main_page_label_2_main_main_default.set_text_line_space(0)
style_main_page_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_main_page_label_2_main_main_default.set_pad_left(0)
style_main_page_label_2_main_main_default.set_pad_right(0)
style_main_page_label_2_main_main_default.set_pad_top(8)
style_main_page_label_2_main_main_default.set_pad_bottom(0)

# add style for main_page_label_2
main_page_label_2.add_style(style_main_page_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create main_page_label_3
main_page_label_3 = lv.label(main_page)
main_page_label_3.set_pos(int(328),int(226))
main_page_label_3.set_size(114,32)
main_page_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
main_page_label_3.set_text("Tool")
main_page_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_main_page_label_3_main_main_default
style_main_page_label_3_main_main_default = lv.style_t()
style_main_page_label_3_main_main_default.init()
style_main_page_label_3_main_main_default.set_radius(0)
style_main_page_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_main_page_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_main_page_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_main_page_label_3_main_main_default.set_bg_opa(0)
style_main_page_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_main_page_label_3_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_main_page_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_main_page_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_main_page_label_3_main_main_default.set_text_letter_space(2)
style_main_page_label_3_main_main_default.set_text_line_space(0)
style_main_page_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_main_page_label_3_main_main_default.set_pad_left(0)
style_main_page_label_3_main_main_default.set_pad_right(0)
style_main_page_label_3_main_main_default.set_pad_top(8)
style_main_page_label_3_main_main_default.set_pad_bottom(0)

# add style for main_page_label_3
main_page_label_3.add_style(style_main_page_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create engraving_page
engraving_page = lv.obj()
engraving_page.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_engraving_page_main_main_default
style_engraving_page_main_main_default = lv.style_t()
style_engraving_page_main_main_default.init()
style_engraving_page_main_main_default.set_bg_color(lv.color_make(0x1D,0x23,0x32))
style_engraving_page_main_main_default.set_bg_opa(255)

# add style for engraving_page
engraving_page.add_style(style_engraving_page_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create engraving_page_btn_frame
engraving_page_btn_frame = lv.btn(engraving_page)
engraving_page_btn_frame.set_pos(int(252),int(80))
engraving_page_btn_frame.set_size(212,37)
engraving_page_btn_frame.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
engraving_page_btn_frame_label = lv.label(engraving_page_btn_frame)
engraving_page_btn_frame_label.set_text("Frame")
engraving_page_btn_frame.set_style_pad_all(0, lv.STATE.DEFAULT)
engraving_page_btn_frame_label.align(lv.ALIGN.CENTER,0,0)
# create style style_engraving_page_btn_frame_main_main_default
style_engraving_page_btn_frame_main_main_default = lv.style_t()
style_engraving_page_btn_frame_main_main_default.init()
style_engraving_page_btn_frame_main_main_default.set_radius(20)
style_engraving_page_btn_frame_main_main_default.set_bg_color(lv.color_make(0x20,0x27,0x3A))
style_engraving_page_btn_frame_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_frame_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_page_btn_frame_main_main_default.set_bg_opa(255)
style_engraving_page_btn_frame_main_main_default.set_border_color(lv.color_make(0xFF,0x57,0x00))
style_engraving_page_btn_frame_main_main_default.set_border_width(1)
style_engraving_page_btn_frame_main_main_default.set_border_opa(255)
style_engraving_page_btn_frame_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_page_btn_frame_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_page_btn_frame_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_page_btn_frame_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_page_btn_frame_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for engraving_page_btn_frame
engraving_page_btn_frame.add_style(style_engraving_page_btn_frame_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create engraving_page_btn_home
engraving_page_btn_home = lv.btn(engraving_page)
engraving_page_btn_home.set_pos(int(252),int(134))
engraving_page_btn_home.set_size(212,37)
engraving_page_btn_home.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
engraving_page_btn_home_label = lv.label(engraving_page_btn_home)
engraving_page_btn_home_label.set_text("Home")
engraving_page_btn_home.set_style_pad_all(0, lv.STATE.DEFAULT)
engraving_page_btn_home_label.align(lv.ALIGN.CENTER,0,0)
# create style style_engraving_page_btn_home_main_main_default
style_engraving_page_btn_home_main_main_default = lv.style_t()
style_engraving_page_btn_home_main_main_default.init()
style_engraving_page_btn_home_main_main_default.set_radius(20)
style_engraving_page_btn_home_main_main_default.set_bg_color(lv.color_make(0x20,0x27,0x3A))
style_engraving_page_btn_home_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_home_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_page_btn_home_main_main_default.set_bg_opa(255)
style_engraving_page_btn_home_main_main_default.set_border_color(lv.color_make(0xFF,0x57,0x00))
style_engraving_page_btn_home_main_main_default.set_border_width(1)
style_engraving_page_btn_home_main_main_default.set_border_opa(255)
style_engraving_page_btn_home_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_page_btn_home_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_page_btn_home_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_page_btn_home_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_page_btn_home_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for engraving_page_btn_home
engraving_page_btn_home.add_style(style_engraving_page_btn_home_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create engraving_page_btn_position
engraving_page_btn_position = lv.btn(engraving_page)
engraving_page_btn_position.set_pos(int(252),int(188))
engraving_page_btn_position.set_size(212,37)
engraving_page_btn_position.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
engraving_page_btn_position_label = lv.label(engraving_page_btn_position)
engraving_page_btn_position_label.set_text("Position")
engraving_page_btn_position.set_style_pad_all(0, lv.STATE.DEFAULT)
engraving_page_btn_position_label.align(lv.ALIGN.CENTER,0,0)
# create style style_engraving_page_btn_position_main_main_default
style_engraving_page_btn_position_main_main_default = lv.style_t()
style_engraving_page_btn_position_main_main_default.init()
style_engraving_page_btn_position_main_main_default.set_radius(20)
style_engraving_page_btn_position_main_main_default.set_bg_color(lv.color_make(0x20,0x27,0x3A))
style_engraving_page_btn_position_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_position_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_page_btn_position_main_main_default.set_bg_opa(255)
style_engraving_page_btn_position_main_main_default.set_border_color(lv.color_make(0xFF,0x57,0x00))
style_engraving_page_btn_position_main_main_default.set_border_width(1)
style_engraving_page_btn_position_main_main_default.set_border_opa(255)
style_engraving_page_btn_position_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_page_btn_position_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_page_btn_position_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_page_btn_position_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_page_btn_position_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for engraving_page_btn_position
engraving_page_btn_position.add_style(style_engraving_page_btn_position_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create engraving_page_btn_start
engraving_page_btn_start = lv.btn(engraving_page)
engraving_page_btn_start.set_pos(int(270),int(240))
engraving_page_btn_start.set_size(175,50)
engraving_page_btn_start.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
engraving_page_btn_start_label = lv.label(engraving_page_btn_start)
engraving_page_btn_start_label.set_text("Start")
engraving_page_btn_start.set_style_pad_all(0, lv.STATE.DEFAULT)
engraving_page_btn_start_label.align(lv.ALIGN.CENTER,0,0)
# create style style_engraving_page_btn_start_main_main_default
style_engraving_page_btn_start_main_main_default = lv.style_t()
style_engraving_page_btn_start_main_main_default.init()
style_engraving_page_btn_start_main_main_default.set_radius(25)
style_engraving_page_btn_start_main_main_default.set_bg_color(lv.color_make(0x20,0x27,0x3A))
style_engraving_page_btn_start_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_start_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_page_btn_start_main_main_default.set_bg_opa(255)
style_engraving_page_btn_start_main_main_default.set_border_color(lv.color_make(0xff,0x57,0x00))
style_engraving_page_btn_start_main_main_default.set_border_width(2)
style_engraving_page_btn_start_main_main_default.set_border_opa(255)
style_engraving_page_btn_start_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_page_btn_start_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_page_btn_start_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_page_btn_start_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_page_btn_start_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for engraving_page_btn_start
engraving_page_btn_start.add_style(style_engraving_page_btn_start_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create engraving_page_label_1
engraving_page_label_1 = lv.label(engraving_page)
engraving_page_label_1.set_pos(int(10),int(22))
engraving_page_label_1.set_size(135,33)
engraving_page_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
engraving_page_label_1.set_text("Engraving-")
engraving_page_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_engraving_page_label_1_main_main_default
style_engraving_page_label_1_main_main_default = lv.style_t()
style_engraving_page_label_1_main_main_default.init()
style_engraving_page_label_1_main_main_default.set_radius(0)
style_engraving_page_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_page_label_1_main_main_default.set_bg_opa(0)
style_engraving_page_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_page_label_1_main_main_default.set_text_font(lv.font_montserratMedium_20)
except AttributeError:
    try:
        style_engraving_page_label_1_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_engraving_page_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_page_label_1_main_main_default.set_text_letter_space(2)
style_engraving_page_label_1_main_main_default.set_text_line_space(0)
style_engraving_page_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_engraving_page_label_1_main_main_default.set_pad_left(0)
style_engraving_page_label_1_main_main_default.set_pad_right(0)
style_engraving_page_label_1_main_main_default.set_pad_top(8)
style_engraving_page_label_1_main_main_default.set_pad_bottom(0)

# add style for engraving_page_label_1
engraving_page_label_1.add_style(style_engraving_page_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create engraving_page_label_2
engraving_page_label_2 = lv.label(engraving_page)
engraving_page_label_2.set_pos(int(141),int(26))
engraving_page_label_2.set_size(110,25)
engraving_page_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
engraving_page_label_2.set_text("Filename")
engraving_page_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_engraving_page_label_2_main_main_default
style_engraving_page_label_2_main_main_default = lv.style_t()
style_engraving_page_label_2_main_main_default.init()
style_engraving_page_label_2_main_main_default.set_radius(0)
style_engraving_page_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_page_label_2_main_main_default.set_bg_opa(0)
style_engraving_page_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_page_label_2_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_page_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_page_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_page_label_2_main_main_default.set_text_letter_space(2)
style_engraving_page_label_2_main_main_default.set_text_line_space(0)
style_engraving_page_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.LEFT)
style_engraving_page_label_2_main_main_default.set_pad_left(0)
style_engraving_page_label_2_main_main_default.set_pad_right(0)
style_engraving_page_label_2_main_main_default.set_pad_top(8)
style_engraving_page_label_2_main_main_default.set_pad_bottom(0)

# add style for engraving_page_label_2
engraving_page_label_2.add_style(style_engraving_page_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create engraving_page_btn_back
engraving_page_btn_back = lv.btn(engraving_page)
engraving_page_btn_back.set_pos(int(364),int(13))
engraving_page_btn_back.set_size(100,50)
engraving_page_btn_back.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
engraving_page_btn_back_label = lv.label(engraving_page_btn_back)
engraving_page_btn_back_label.set_text("Back")
engraving_page_btn_back.set_style_pad_all(0, lv.STATE.DEFAULT)
engraving_page_btn_back_label.align(lv.ALIGN.CENTER,0,0)
# create style style_engraving_page_btn_back_main_main_default
style_engraving_page_btn_back_main_main_default = lv.style_t()
style_engraving_page_btn_back_main_main_default.init()
style_engraving_page_btn_back_main_main_default.set_radius(20)
style_engraving_page_btn_back_main_main_default.set_bg_color(lv.color_make(0x20,0x27,0x3A))
style_engraving_page_btn_back_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_back_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_page_btn_back_main_main_default.set_bg_opa(255)
style_engraving_page_btn_back_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_back_main_main_default.set_border_width(1)
style_engraving_page_btn_back_main_main_default.set_border_opa(255)
style_engraving_page_btn_back_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_page_btn_back_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_page_btn_back_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_page_btn_back_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_page_btn_back_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for engraving_page_btn_back
engraving_page_btn_back.add_style(style_engraving_page_btn_back_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create engraving_page_img_1
engraving_page_img_1 = lv.img(engraving_page)
engraving_page_img_1.set_pos(int(30),int(62))
engraving_page_img_1.set_size(184,185)
engraving_page_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
engraving_page_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp411342652.png','rb') as f:
        engraving_page_img_1_img_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp411342652.png')
    sys.exit()

engraving_page_img_1_img = lv.img_dsc_t({
  'data_size': len(engraving_page_img_1_img_data),
  'header': {'always_zero': 0, 'w': 184, 'h': 185, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': engraving_page_img_1_img_data
})

engraving_page_img_1.set_src(engraving_page_img_1_img)
engraving_page_img_1.set_pivot(50,50)
engraving_page_img_1.set_angle(0)
# create style style_engraving_page_img_1_main_main_default
style_engraving_page_img_1_main_main_default = lv.style_t()
style_engraving_page_img_1_main_main_default.init()
style_engraving_page_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_engraving_page_img_1_main_main_default.set_img_recolor_opa(0)
style_engraving_page_img_1_main_main_default.set_img_opa(255)

# add style for engraving_page_img_1
engraving_page_img_1.add_style(style_engraving_page_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create engraving_page_imgbtn_1
engraving_page_imgbtn_1 = lv.imgbtn(engraving_page)
engraving_page_imgbtn_1.set_pos(int(11),int(262))
engraving_page_imgbtn_1.set_size(222,38)
engraving_page_imgbtn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp1030699549.png','rb') as f:
        engraving_page_imgbtn_1_imgReleased_data = f.read()
except:
    print('Could not open E:\\Project_git\\myProject\\ESP32_LCD_PICO\\doc\\WZMK\\generated\\mPythonImages\\mp1030699549.png')
    sys.exit()

engraving_page_imgbtn_1_imgReleased = lv.img_dsc_t({
  'data_size': len(engraving_page_imgbtn_1_imgReleased_data),
  'header': {'always_zero': 0, 'w': 222, 'h': 38, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': engraving_page_imgbtn_1_imgReleased_data
})
engraving_page_imgbtn_1.set_src(lv.imgbtn.STATE.RELEASED, None, engraving_page_imgbtn_1_imgReleased, None)





engraving_page_imgbtn_1.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_engraving_page_imgbtn_1_main_main_default
style_engraving_page_imgbtn_1_main_main_default = lv.style_t()
style_engraving_page_imgbtn_1_main_main_default.init()
style_engraving_page_imgbtn_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_engraving_page_imgbtn_1_main_main_default.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_engraving_page_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_page_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_page_imgbtn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_engraving_page_imgbtn_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_engraving_page_imgbtn_1_main_main_default.set_img_recolor_opa(0)
style_engraving_page_imgbtn_1_main_main_default.set_img_opa(255)

# add style for engraving_page_imgbtn_1
engraving_page_imgbtn_1.add_style(style_engraving_page_imgbtn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_engraving_page_imgbtn_1_main_main_pressed
style_engraving_page_imgbtn_1_main_main_pressed = lv.style_t()
style_engraving_page_imgbtn_1_main_main_pressed.init()
style_engraving_page_imgbtn_1_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_page_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_engraving_page_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_page_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_engraving_page_imgbtn_1_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_page_imgbtn_1_main_main_pressed.set_img_recolor_opa(0)
style_engraving_page_imgbtn_1_main_main_pressed.set_img_opa(255)

# add style for engraving_page_imgbtn_1
engraving_page_imgbtn_1.add_style(style_engraving_page_imgbtn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_engraving_page_imgbtn_1_main_main_checked
style_engraving_page_imgbtn_1_main_main_checked = lv.style_t()
style_engraving_page_imgbtn_1_main_main_checked.init()
style_engraving_page_imgbtn_1_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_engraving_page_imgbtn_1_main_main_checked.set_text_font(lv.font_montserratMedium_12)
except AttributeError:
    try:
        style_engraving_page_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_engraving_page_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_16)
style_engraving_page_imgbtn_1_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_engraving_page_imgbtn_1_main_main_checked.set_img_recolor_opa(0)
style_engraving_page_imgbtn_1_main_main_checked.set_img_opa(255)

# add style for engraving_page_imgbtn_1
engraving_page_imgbtn_1.add_style(style_engraving_page_imgbtn_1_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)


# create engraving_page_btn_6
engraving_page_btn_6 = lv.btn(engraving_page)
engraving_page_btn_6.set_pos(int(75),int(70))
engraving_page_btn_6.set_size(95,47)
engraving_page_btn_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_engraving_page_btn_6_main_main_default
style_engraving_page_btn_6_main_main_default = lv.style_t()
style_engraving_page_btn_6_main_main_default.init()
style_engraving_page_btn_6_main_main_default.set_radius(5)
style_engraving_page_btn_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_page_btn_6_main_main_default.set_bg_opa(0)
style_engraving_page_btn_6_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_6_main_main_default.set_border_width(0)
style_engraving_page_btn_6_main_main_default.set_border_opa(255)
style_engraving_page_btn_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_page_btn_6_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_page_btn_6_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_page_btn_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_page_btn_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for engraving_page_btn_6
engraving_page_btn_6.add_style(style_engraving_page_btn_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create engraving_page_btn_7
engraving_page_btn_7 = lv.btn(engraving_page)
engraving_page_btn_7.set_pos(int(75),int(196))
engraving_page_btn_7.set_size(95,47)
engraving_page_btn_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_engraving_page_btn_7_main_main_default
style_engraving_page_btn_7_main_main_default = lv.style_t()
style_engraving_page_btn_7_main_main_default.init()
style_engraving_page_btn_7_main_main_default.set_radius(5)
style_engraving_page_btn_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_page_btn_7_main_main_default.set_bg_opa(0)
style_engraving_page_btn_7_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_7_main_main_default.set_border_width(0)
style_engraving_page_btn_7_main_main_default.set_border_opa(255)
style_engraving_page_btn_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_page_btn_7_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_page_btn_7_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_page_btn_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_page_btn_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for engraving_page_btn_7
engraving_page_btn_7.add_style(style_engraving_page_btn_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create engraving_page_btn_8
engraving_page_btn_8 = lv.btn(engraving_page)
engraving_page_btn_8.set_pos(int(30),int(127))
engraving_page_btn_8.set_size(55,66)
engraving_page_btn_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_engraving_page_btn_8_main_main_default
style_engraving_page_btn_8_main_main_default = lv.style_t()
style_engraving_page_btn_8_main_main_default.init()
style_engraving_page_btn_8_main_main_default.set_radius(5)
style_engraving_page_btn_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_page_btn_8_main_main_default.set_bg_opa(0)
style_engraving_page_btn_8_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_8_main_main_default.set_border_width(0)
style_engraving_page_btn_8_main_main_default.set_border_opa(255)
style_engraving_page_btn_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_page_btn_8_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_page_btn_8_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_page_btn_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_page_btn_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for engraving_page_btn_8
engraving_page_btn_8.add_style(style_engraving_page_btn_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)


# create engraving_page_btn_9
engraving_page_btn_9 = lv.btn(engraving_page)
engraving_page_btn_9.set_pos(int(157),int(127))
engraving_page_btn_9.set_size(53,61)
engraving_page_btn_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_engraving_page_btn_9_main_main_default
style_engraving_page_btn_9_main_main_default = lv.style_t()
style_engraving_page_btn_9_main_main_default.init()
style_engraving_page_btn_9_main_main_default.set_radius(5)
style_engraving_page_btn_9_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_9_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_engraving_page_btn_9_main_main_default.set_bg_opa(0)
style_engraving_page_btn_9_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_engraving_page_btn_9_main_main_default.set_border_width(0)
style_engraving_page_btn_9_main_main_default.set_border_opa(255)
style_engraving_page_btn_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_engraving_page_btn_9_main_main_default.set_text_font(lv.font_montserratMedium_16)
except AttributeError:
    try:
        style_engraving_page_btn_9_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_engraving_page_btn_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_engraving_page_btn_9_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for engraving_page_btn_9
engraving_page_btn_9.add_style(style_engraving_page_btn_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)



def engraving_page_btn_back_released_1_event_cb(e,main_page):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(main_page, lv.SCR_LOAD_ANIM.OVER_RIGHT, 100, 100, False)
engraving_page_btn_back.add_event_cb(lambda e: engraving_page_btn_back_released_1_event_cb(e,main_page), lv.EVENT.RELEASED, None)


def logo_page_pressed_1_event_cb(e,main_page):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(main_page, lv.SCR_LOAD_ANIM.NONE, 100, 100, False)
logo_page.add_event_cb(lambda e: logo_page_pressed_1_event_cb(e,main_page), lv.EVENT.PRESSED, None)


def main_page_imgbtn_1_released_1_event_cb(e,engraving_page):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(engraving_page, lv.SCR_LOAD_ANIM.OVER_LEFT, 100, 100, False)
main_page_imgbtn_1.add_event_cb(lambda e: main_page_imgbtn_1_released_1_event_cb(e,engraving_page), lv.EVENT.RELEASED, None)



# content from custom.py

# Load the default screen
lv.scr_load(logo_page)

while SDL.check():
    time.sleep_ms(5)
