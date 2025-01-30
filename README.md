# Projeto: Controle de LED RGB, Matriz de LEDs e Botões na BitDogLab (Raspberry Pi Pico W)

## Descrição
Este projeto implementa um sistema que combina o controle de LEDs RGB, uma matriz de LEDs e botões utilizando a placa BitDogLab, que possui uma Raspberry Pi Pico W integrada. As principais funcionalidades incluem a exibição de números de 0 a 9 em uma matriz de LEDs, o controle via botões físicos e a piscação de um LED RGB.

## Funcionalidades
1. O LED vermelho do LED RGB pisca continuamente 5 vezes por segundo.
2. O botão A incrementa o número exibido na matriz de LEDs a cada pressionamento.
3. O botão B decrementa o número exibido na matriz de LEDs a cada pressionamento.
4. Os LEDs WS2812 exibem os números de 0 a 9 de forma fixa ou com um estilo visual criativo.

## Requisitos do Projeto
1. **Uso de interrupções:** Todas as funcionalidades relacionadas aos botões utilizam rotinas de interrupção (IRQ).
2. **Debouncing:** Implementação de tratamento de bouncing dos botões via software.
3. **Controle de LEDs:** Uso de LEDs comuns e LEDs WS2812 para demonstrar diferentes métodos de controle.
4. **Organização do código:** O código está estruturado e comentado para facilitar o entendimento.

## Hardware Utilizado
- **BitDogLab** (baseada na Raspberry Pi Pico W)
- LED RGB
- Botões (dois, para incremento e decremento)
- Matriz de LEDs WS2812
- Resistores pull-up para os botões (internos ativados)

## Bibliotecas e Dependências
- `pico/stdlib.h` (funções básicas de entrada/saída)
- `hardware/pio.h` (controle de PIO para LEDs WS2812)
- `hardware/clocks.h` (configuração de clock do sistema)
- `hardware/uart.h` (comunicação serial, se necessário)
- `vetores_numeros.h` (vetores que representam os números na matriz de LEDs)
- `matriz_led_control.h` (funções de controle da matriz de LEDs)

## Estrutura do Código
### Definições Principais
- `RED_LED_RGB`: Pino do LED vermelho
- `BOTAO_A` e `BOTAO_B`: Pinos dos botões
- `OUT_PIN`: Pino de saída da matriz de LEDs

### Loop Principal
- Pisca o LED vermelho a uma frequência de 5 Hz.
- Verifica a necessidade de atualizar o número exibido na matriz de LEDs.

### Interrupções e Debouncing
- O código utiliza interrupções para detectar pressionamentos dos botões.
- Um tempo de debounce de 150ms é aplicado para evitar leituras erradas.

### Exibição de Números
- A matriz de LEDs exibe números de 0 a 9 com base no valor da variável `contador`.
- A função `realizar_troca()` é responsável por atualizar a matriz de LEDs conforme o número armazenado.

### Inicialização da PIO
- Configura o clock do sistema para 128 MHz.
- Carrega e inicializa o programa PIO para controle da matriz de LEDs.

## Como Executar o Projeto
1. Carregar o código na BitDogLab (Raspberry Pi Pico W).
2. Conectar os LEDs, botões e matriz conforme as definições de pinos.
3. Executar o código e testar as funcionalidades pressionando os botões.

## Melhorias Futuras
- Implementação de efeitos adicionais na matriz de LEDs.
- Suporte para múltiplos estilos de exibição de números.
- Controle de brilho da matriz de LEDs via PWM.
- Comunicação sem fio via Wi-Fi da Raspberry Pi Pico W para monitoramento remoto.

## Autor
**Jorge Palma**  
*Data: 30/01/2025*

