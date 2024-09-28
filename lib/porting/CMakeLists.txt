add_library(porting
	lv_port_disp.c
)

target_include_directories(porting PUBLIC
	.
)

target_link_libraries(porting pico_stdlib hardware_spi hardware_dma lvgl ili9341)