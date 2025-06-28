/* src/kernel.c */

#include <stdlib.h>

#define VGA_COLUMNS_NUM 80
#define VGA_ROWS_NUM 25

#define ARRAY_SIZE(arr) ((int)sizeof(arr) / (int)sizeof((arr)[0]))

void __stack_chk_fail(void) {}

void _start_kernel(void) {
    _mm_setUp();

    volatile char *vga_buf = (char *)0xb8000;
    char* msg_old = (char*)malloc(3);
    msg_old[0] = ':';
    msg_old[1] = ')';
    msg_old[2] = '\0';

    char* msg = realloc(msg_old, 3);
    int i;

    for (i = 0; i < VGA_COLUMNS_NUM * VGA_ROWS_NUM * 2; i++)
        vga_buf[i] = '\0';

    for (i = 0; i < ARRAY_SIZE(msg) - 1; i++) {
        vga_buf[i * 2] = msg[i];
        vga_buf[i * 2 + 1] = 0x07; /* White on black */
    }
}
