#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "ili9341.h"
#include "gfx.h"
#include "DisplayTest.h"
#include "lvgl/lvgl.h"
#include "hardware/adc.h"

#include "lvgl/examples/porting/lv_port_disp.h"
#include "lib/out/gui_guider.h"
#include "lib/out/events_init.h"
lv_ui guider_ui;

static void lv_ex_label(void)
{
	static char* github_addr = "https://gitee.com/WRS0923";
	lv_obj_t * label = lv_label_create(lv_scr_act());
    //lv_label_set_recolor(label, true);
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
    lv_obj_set_width(label, 120);
    lv_label_set_text_fmt(label, "#ff0000 Gitee: %s#", github_addr);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 10);
	
    lv_obj_t * label2 = lv_label_create(lv_scr_act());
    //lv_label_set_recolor(label2, true);
    lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
    lv_obj_set_width(label2, 120);
    lv_label_set_text_fmt(label2, "#ff0000 Hello# #0000ff world !123456789#");
    lv_obj_align(label2, LV_ALIGN_CENTER, 0, -10);
}



void lv_example_get_started_1(void)
{
    lv_obj_t * btn = lv_btn_create(lv_scr_act());     /*Add a button the current screen*/
    lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
    lv_obj_set_size(btn, 120, 50);                          /*Set its size*/
    //lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);           /*Assign a callback to the button*/
    lv_obj_t * label = lv_label_create(btn);          /*Add a label to the button*/
    lv_label_set_text(label, "Button");                     /*Set the labels text*/
    lv_obj_center(label); 
}

static void lv_100ask_widget_test_init(void);

static void lv_100ask_widget_test_init(void)
{
   
}

#define COMMODORE64 1

int main()
{
    stdio_init_all();
    InitializeDisplay(0xFFFF);
    //LCD_setPins(TFT_DC, TFT_CS, TFT_RST, TFT_SCLK, TFT_MOSI);
    //LCD_initDisplay();
    //LCD_setRotation(TFT_ROTATION);
    lv_init();
    lv_port_disp_init();
    setup_ui(&guider_ui);
    events_init(&guider_ui);
    adc_init();
    // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(26);
    lv_100ask_widget_test_init();
    //lv_ex_label();
    //lv_example_get_started_1();
    while (true)
    {
        sleep_ms(5);   /*Sleep for 5 millisecond*/
        lv_task_handler();
        lv_tick_inc(5);      /*Tell LVGL that 5 milliseconds were elapsed*/
        //lv_example_get_started_1();
    }
    
/*
#ifdef COMMODORE64
    InitializeDisplay(FOREGROUND);
    Commodore64();
#else
    InitializeDisplay(BACKGROUND);
    Terminal();
#endif

*/


    return 0;
}

void printLine(uint16_t line, const char *str)
{
    int len = strlen(str);
    GFX_setCursor(INDENT * 2, INDENT + line * LINE_HEIGHT);
    GFX_printf(str);
    GFX_flush();
}

void InitializeDisplay(uint16_t color)
{
    // Initialize display
    puts("Initializing display...");
    LCD_setPins(TFT_DC, TFT_CS, TFT_RST, TFT_SCLK, TFT_MOSI);
    LCD_initDisplay();
    LCD_setRotation(TFT_ROTATION);
    GFX_createFramebuf();
    GFX_setClearColor(color);
    GFX_setTextBack(BACKGROUND);
    GFX_setTextColor(FOREGROUND);
    GFX_clearScreen();
}

// This displays a fake Commodore 64 screen
void Commodore64()
{
    // Initialize GFX
    puts("Initializing graphics...");
    GFX_fillRect(MARGIN * 2, MARGIN, GFX_getWidth() - MARGIN * 4, GFX_getHeight() - MARGIN * 2, BACKGROUND);
    GFX_flush();

    // Draw some text
    puts("Writing...");
    uint16_t line = 0;
    printLine(line++, "    **** COMMODORE 64 BASIC V2 ****");
    printLine(line++, " 64K RAM SYSTEM  38911 BASIC BYTES FREE");
    printLine(line++, "READY.");
    printLine(line++, "LOAD\"*\",8,1");
    printLine(line++, "SEARCHING FOR *");
    printLine(line++, "LOADING");
    printLine(line++, "READY.");
    printLine(line++, "RUN");
    printLine(line++, "HELLO WORLD");

    while (true)
    {
        puts("Ping...");
        GFX_fillRect(INDENT * 2, INDENT + line * LINE_HEIGHT, 6, 8, BACKGROUND);
        GFX_flush();
        sleep_ms(500);

        GFX_fillRect(INDENT * 2, INDENT + line * LINE_HEIGHT, 6, 8, FOREGROUND);
        GFX_flush();
        sleep_ms(500);
    }
}

// This displays a scrolling terminal
void Terminal()
{
    int currentLine = 0;

    int w = GFX_getWidth();
    int h = GFX_getHeight();

    GFX_printf("Screen size: %d x %d\n", w, h);
    currentLine++;
    GFX_flush();

    for (int i = 1; i < 32; i++)
    {
        currentLine++;
        if (currentLine * LINE_HEIGHT > h)
        {
            GFX_scrollUp(LINE_HEIGHT);
            GFX_setCursor(0, h - LINE_HEIGHT);
            currentLine--;
        }
        GFX_printf("Line %d\n", i);
        GFX_flush();
        sleep_ms(DELAY);
    }
}
