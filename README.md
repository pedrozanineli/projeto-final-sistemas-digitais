# Projeto Final Sistemas Digitais

## 1.Introdução

O objetivo do projeto foi a construção de um sistema capaz de simular uma roleta utilizada em jogos com sorteio. Para isso, foi utilizada a plataforma Tinkercad para esquematizar o diagrama elétrico e simular o funcionamento efetivo do projeto.

## 2.Lista de Materiais

- 1 Arduíno Uno R3
- 1 Protoboard pequena
- 1 Potenciômetro de 250KΩ
- 4 Resistores (3 de 1KΩ e 1 de 220Ω)
- 2 Botões
- 1 Fita de led NeoPixel Ring 24
- 1 LCD 16x2
- 1 Buzzer

## 3.Funcionamento

O sistema inicializa com uma mensagem no LCD indicando cor a que os botões se referem. O gatilho para o inicio do "giro" da roleta é o pressionamento de um dos botões (simbolizando a escolha da cor). A roleta gira inicialmente mais rápido e, gradualmente, decai sua velocidade até finalmente parar. Após a parada, é anunciado "Ganhou!" ou "Perdeu!" no LCD, uma musica toca através do buzzer e a roleta se completa com a cor que foi resultado do "giro" até que um dos botões novamente seja apertado, reiniciando o processo.

## 4.Diagrama Elétrico
![alt text](https://github.com/pedrozanineli/projeto-final-sistemas-digitais/blob/main/hardware-projeto.png)

## 5. Simulação

A simulação pode ser feita na plataforma do Tinkercad através do seguinte link:

## 6.Conclusão
