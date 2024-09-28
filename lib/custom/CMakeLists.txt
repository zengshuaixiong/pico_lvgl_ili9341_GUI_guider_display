add_library(custom
	custom.c
)

target_include_directories(custom PUBLIC
	.
)

target_link_libraries(custom pico_stdlib hardware_spi hardware_dma lvgl)
