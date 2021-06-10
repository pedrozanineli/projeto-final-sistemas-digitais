## Projeto Final Sistemas Digitais

Link para o projeto no Tinkercad:


[![Tinkercad Badge](https://img.shields.io/badge/-Tinkercad-lightgrey?logo=autodesk&style=flat&logoColor=white&color=000880)](https://www.tinkercad.com/things/0cwSY3lfnwK-projeto-final)


O presente projeto foi desenvolvido como trabalho final da matéria de Sistemas Digitais, com a construção de uma roleta utilizada em jogos de sorteio. Para tanto, foi utilizada a plataforma Tinkercad, possibilitando a esquematização do diagrama elétrico e simulação do funcionamento de fato do projeto.

Como hardware, foi utilizado:

- 1 Arduino Uno R3;
- 1 Protoboard pequena;
- 1 Potenciômetro de 250KΩ;
- 4 Resistores (3 de 1KΩ e 1 de 220Ω);
- 2 Botões;
- 1 Fita de led NeoPixel Ring 24;
- 1 LCD 16x2;
- 1 Buzzer.

![alt text](https://github.com/pedrozanineli/projeto-final-sistemas-digitais/blob/main/hardware-projeto.png)

## Funcionamento

O sistema tem como ponto de partida o acionamento de uma mensagem no visor LCD, indicando as cores referidas por cada botão - isto é, verde na esquerda e vermelho na direita. Assim, o usuário pode dar um sinal de entrada, um "gatilho", iniciando a jogada. Nesse primeiro momento, a velocidade é alta e vai diminuindo com o tempo até finalmente parar, de forma que esse ponto de paragem é atribuído de maneira <strong>pseudo-aleatória</strong>.

Como cada led verde ocupará uma posição par e cada vermelho ocupará uma posição ímpar, torna-se possível a definição da vitória ou derrota de acordo com uma comparação entre essa característica e o módulo de 2 do inteiro pseudo-aleatório definido. Por fim, o visor irá indicar o resultado com "Ganhou!" ou "Perdeu!", juntamente de uma resposta sonora para cada um dos casos e o acendimento da cor do ponto de paragem.

Como último ponto, é importante notar que a aleatoriedade do número gerado não tem uma garantia de imprevisibilidade, visto que apenas aproxima algumas das características desses grupos. O importante cientista da computação John von Neumann inclusive afirma: "Qualquer um que considere métodos aritméticos para produzir dígitos está, certamente, cometendo um pecado". Assim, um próximo passo e oportunidade de melhoria é o melhor desenvolvimento do ponto final do funcionamento.
