add_library(generated
	gui_guider.c
	events_init.c
)

target_include_directories(generated PUBLIC
	.
)

target_link_libraries(generated pico_stdlib hardware_spi hardware_dma lvgl)
