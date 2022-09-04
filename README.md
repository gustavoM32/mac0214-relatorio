# Relatório MAC0214

Tempo em atividades: 10/100 horas
* Contests de 5 horas: 10/55 horas
* Contests de 2 horas: 0/20 horas
* Upsolving: 0/20 horas
* Revisão: 0/5 horas

## Agosto

5/5 horas

### 28/08/22

Contest: [2017-2018 ICPC Central Quarter Final of Northeastern European Regional Collegiate Programming Contest](https://codeforces.com/gym/102788)
Tempo: 5 horas
Time: eu, Antônio e Enrique

Um contest com 12 problemas, conseguimos resolver 10 deles. Resolvi os problemas C, H, I, J, K:
O C foi um problema bem interessante de gerar combinações de k a k entre n em ordem de modo que duas consecutivas sejam diferentes em apenas um número. Tive um pouco de dificuldade para otimizar a recursão nessa questão.

O H foi uma busca binária com dp.

O I consistia em apenas listar os divisores de um número.

O J precisou usar somas de prefixos pra calcular a soma em um intervalo rapidamente.

O K foi um problema muito legal de hanoi. Considerando que o hanoi é resolvido pelo algoritmo padrão (dado no enunciado), e dados vários estados diferentes de distribuições dos discos, encontrar aquele que está mais próximo da solução.

## Setembro

5/41 horas

### 04/09/22

Contest: [2017-2018 Northwestern European Regional Contest (NWERC 2017)](https://codeforces.com/gym/101623)
Tempo: 5 horas
Time: eu e Antônio.

Contest com 11 problemas e resolvemos 6 deles. Resolvi os problemas D e K:
O D consiste em ver de quantas maneiras corretas e incorretas é possível traduzir uma dada frase, a entrada também dá pares de palavras indicando se a tradução está correta e incorreta. A solução é bem ad-hoc.

O K pede para escolher distribuição dos jogadores nas chaves de um torneio de modo que um deles tenha a maior probabilidade de vencer, o problema pede apenas para imprimir essa probabilidade. Cada jogador tem um certo nível de dificuldade. A solução é gulosa e consiste em fazer com que o jogador que queremos que ganhe dispute com os mais fáceis. Calculamos cada estado do torneio com distribuições de probabilidades.
