## Projeto Final Sistemas Digitais

O presente projeto foi desenvolvido como trabalho final da matéria de Sistemas Digitiais, com a construção de uma roleta utilizada em jogos de sorteio. Para tanto, foi utilizada a plataforma Tinkercad, possibilitando a esquematização do diagrama elétrico e simulação do funcionamento de fato do projeto.

Como hardware, a seguinte lista foi utilizada:

- 1 Arduíno Uno R3;
- 1 Protoboard pequena;
- 1 Potenciômetro de 250KΩ;
- 4 Resistores (3 de 1KΩ e 1 de 220Ω);
- 2 Botões;
- 1 Fita de led NeoPixel Ring 24;
- 1 LCD 16x2;
- 1 Buzzer.

![alt text](https://github.com/pedrozanineli/projeto-final-sistemas-digitais/blob/main/hardware-projeto.png)

## Funcionamento

O sistema tem como ponto de partida o acionamento de uma mensagem no visor LCD, indicando as cores referidas por cada botão - isto é, verde na esquerda e vermelho na direita. Assim, o usuário pode dar um sinal de entrada, um "gatilho", iniciando a jogada. Nesse primeiro momento, a velocidade é alta e vai diminuindo com o tempo até finalmente parar, de forma que esse ponto de paragem é atribuído de <strong>maneira aleatória</strong>.

Como cada led verde ocupará uma posição par e cada vermelho ocupará uma posição ímpar, torna-se possível a definição da vitória ou derrota de acordo com uma comparação entre essa característica e o módulo de 2 do inteiro aleatório definido. Por fim, o visor irá indicar o resultado com "Ganhou!" ou "Perdeu!", juntamente de uma resposta sonora para cada um dos casos e o acendimento da cor do ponto de paragem.

Mudar link do projeto quando for enviar - deixar o link que funcionará por mais tempo
https://www.tinkercad.com/things/0cwSY3lfnwK-projeto-final/editel?sharecode=2o_n-4D3_C1sNqj1uVgDDtlZ-7cvu519FyxNYPYB3Lc

## 4. Diagrama Elétrico

## 6.Conclusão
