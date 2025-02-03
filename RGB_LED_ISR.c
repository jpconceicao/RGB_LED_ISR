/* 
* Feita por:     Jorge Palma 
* Data:          30/01/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/uart.h"

#include "vetores_numeros.h"
#include "include/matriz_led_control.h"

#define RED_LED_RGB 13

// Definições para os botões
#define BOTAO_A 5
#define BOTAO_B 6

// Definições para a matriz de leds RGB
#define OUT_PIN 7

static volatile uint8_t contador = 0;
static volatile bool trocar_numero = false;
static volatile uint32_t ultimo_tempo = 0; // Armazena o tempo do último evento (em microssegundos)

pio_t meu_pio = {
    .pio = pio0,       
    .ok = false,       
    .i = 0,              
    .r = 0.0,          
    .g = 0.0,          
    .b = 0.0, 
    .sm = 0          
};

// Escopo das funções
void realizar_troca();
static void gpio_irq_handler(uint gpio, uint32_t events);


int main()
{
    init_pio_routine(&meu_pio, OUT_PIN);

    gpio_init(RED_LED_RGB);                 
    gpio_set_dir(RED_LED_RGB, GPIO_OUT);    
    
    gpio_init(BOTAO_A);
    gpio_set_dir(BOTAO_A, GPIO_IN);        
    gpio_pull_up(BOTAO_A);
    gpio_init(BOTAO_B);
    gpio_set_dir(BOTAO_B, GPIO_IN);        
    gpio_pull_up(BOTAO_B);  

    // gpio_set_irq_enabled_with_callback(botao_pin, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BOTAO_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    desenho_pio(numero_0, &meu_pio);
    
    while(1)
    {
        // Lógica para o LED piscar 5 vezes a cada 1 segundo
        gpio_put(RED_LED_RGB, 1);
        sleep_ms(100);            
        gpio_put(RED_LED_RGB, 0); //
        sleep_ms(100);

        if (trocar_numero)
        {
            realizar_troca();
            trocar_numero = false;
        }
    }

    return 0;
}

void gpio_irq_handler(uint gpio, uint32_t events)
{
    // Aplicando debouncing na interrupção
    uint32_t tempo_atual = to_us_since_boot(get_absolute_time());

    if (tempo_atual - ultimo_tempo > 220000) // 220 ms de debouncing
    {
        ultimo_tempo = tempo_atual;
        trocar_numero = true;

        if (gpio == BOTAO_A)
        {
            if (contador < 9)
            {
                contador++;
                printf("Contador: %d\n", contador);
            }
        }

        if (gpio == BOTAO_B)
        {
            if (contador > 0)
            {
                contador--;
                printf("Contador: %d\n", contador);
            }
        }
    }
}

void realizar_troca()
{
    switch(contador)
    {
        case 0:
            desenho_pio(numero_0, &meu_pio);
            break;

        case 1:
            desenho_pio(numero_1, &meu_pio);
            break;

        case 2:
            desenho_pio(numero_2, &meu_pio);
            break;

        case 3:
            desenho_pio(numero_3, &meu_pio);
            break;

        case 4:
            desenho_pio(numero_4, &meu_pio);
            break;

        case 5:
            desenho_pio(numero_5, &meu_pio);
            break;

        case 6:
            desenho_pio(numero_6, &meu_pio);
            break;

        case 7:
            desenho_pio(numero_7, &meu_pio);
            break;

        case 8:
            desenho_pio(numero_8, &meu_pio);
            break;

        case 9:
            desenho_pio(numero_9, &meu_pio);
            break;
    
        default:
            desenho_pio(numero_0, &meu_pio);
            break;
    }
}
