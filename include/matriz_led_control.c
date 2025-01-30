#include "matriz_led_control.h"
#include <stdint.h>
#include "pico/stdlib.h"
#include <stdio.h>
#define NUM_PIXELS 25



//imprimir valor binário
void imprimir_binario(int num) 
{
 int i;
 for (i = 31; i >= 0; i--) {
  (num & (1 << i)) ? printf("1") : printf("0");
 }
}

uint32_t matrix_rgb(double b, double r, double g)
{
  unsigned char R, G, B;
  R = (unsigned char)(r * 255.0);
  G = (unsigned char)(g * 255.0);
  B = (unsigned char)(b * 255.0);
  return  (G << 24)| (R << 16) | (B << 8)|0xFF;
}


void desenho_pio(double *desenho, pio_t * meu_pio)
{
    uint32_t valor_led = 0;

    for (int16_t i = 0; i < NUM_PIXELS; i++) {
        valor_led = matrix_rgb(desenho[24-i], desenho[24-i], desenho[24-i]);
        pio_sm_put_blocking(pio0, 0, valor_led);
    }
    printf("clock set to %ld\n", clock_get_hz(clk_sys));
}

void desenho_pio_rgb(double *desenho, pio_t * meu_pio)
{
    uint32_t valor_led = 0;

    for (int16_t i = 0; i < NUM_PIXELS; i++) {
        valor_led = matrix_rgb(desenho[24-i]*meu_pio->b, desenho[24-i]*meu_pio->r, desenho[24-i]*meu_pio->g);
        pio_sm_put_blocking(meu_pio->pio, meu_pio->sm, valor_led);
    }
    printf("clock set to %ld\n", clock_get_hz(clk_sys));
}
