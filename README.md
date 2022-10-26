# Relatório MAC0214

Tempo em atividades: 32/100 horas
* Contests de 5 horas: 30/55 horas
* Contests de 2 horas: 2/20 horas
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

22/41 horas

### 04/09/22

Contest: [2017-2018 Northwestern European Regional Contest (NWERC 2017)](https://codeforces.com/gym/101623)
Tempo: 5 horas
Time: eu e Antônio.

Contest com 11 problemas e resolvemos 6 deles. Resolvi os problemas D e K:
O D consiste em ver de quantas maneiras corretas e incorretas é possível traduzir uma dada frase, a entrada também dá pares de palavras indicando se a tradução está correta e incorreta. A solução é bem ad-hoc.

O K pede para escolher distribuição dos jogadores nas chaves de um torneio de modo que um deles tenha a maior probabilidade de vencer, o problema pede apenas para imprimir essa probabilidade. Cada jogador tem um certo nível de dificuldade. A solução é gulosa e consiste em fazer com que o jogador que queremos que ganhe dispute com os mais fáceis. Calculamos cada estado do torneio com distribuições de probabilidades.

### 11/09/22

Contest: [2021 ICPC Southeastern Europe Regional Contest](https://codeforces.com/gym/103438)
Tempo: 5 horas
Time: eu e Antônio.

O contest tinha 14 problemas e resolvemos 7 deles. Resolvi o J e o N:
O J dá uma string com os caracteres ABC e pergunta se é possível decompô-la em substrings AB, AC e BC. Se é, é necessário imprimir uma decomposição. A solução foi um algoritmo guloso, mas tive dificuldade para chegar na solução correta. Uma característica dos algoritmos gulosos é a dificuldade de se provar a sua corretude, ainda mais durante a prova. Acredito que, para evitar submissões incorretas para esse tipo de problema, eu deveria testar melhor o meu código.

O N também tem uma solução gulosa, mas bem mais simples. O problema fornece uma quantidade inicial e uma quantidade objetivo para cada tamanho de papel e pergunta o número mínimo de cortes para se conseguir o objetivo.

### 17/09/22

Contest: Seletiva USP 2022
Tempo: 5 horas
Time: eu, Antônio e Thiago.

A prova ainda não está disponível em um site, também não tenho acesso às minhas soluções pois ela foi feita no BOCA, semelhante a maratona. Essa prova seleciona times para a participação na primeira fase da Maratona SBC de Programação. Nosso time ficou em primeiro lugar.

O problema B era de simulação mas tinha muitos detalhes pra levar em conta. Fiz parte dele e o Antônio continuou da parte que eu estava travado e conseguiu resolver o problema.

O problema I é de matemática. Minha solução passou mas depois da prova descobri que tinha uma mais eficiente. Também fiz alguma submissões incorretas que eu poderia evitar.

### 24/09/22

Contest: [Fase Zero da Maratona de Programação da SBC](https://www.beecrowd.com.br/judge/pt/challenges/contest/683)
Tempo: 5 horas
Time: eu, Antônio e Thiago.

Essa é a primeira edição da fase zero da maratona. A prova foi realizada na plataforma de problemas Beecrowd.

A prova foi realizada online e permitia o uso de três computadores, mas nosso time decidiu usar somente um para a escrita de código, para servir de prática para a prova real.

Resolvemos 9 dos 12 problemas da prova. Os primeiros problemas foram fáceis e então a maior dificuldade foi o uso de um único computador. Tivemos dificuldades na interpretação de alguns problemas.

Resolvi os problemas A, J e K:
O problema A consiste em calcular a média final dos alunos de uma univerisdade seguindo um determinado critério. O problema é fácil, com somente a leitura da entrada sendo não trivial.

O J também era um problema fácil, e sobre conversão do tempo em jogo de futebol.

O problema K foi um que eu tive bastante dificuldade de entender o que estava sendo pedido, mas depois de um tempo eu consegui. Ele pede para achar o piloto que teve o melhor tempo de volta em uma corrida de fórmula 1 segundo alguns critérios especificados no enunciado. Os tempos dos pilotos em todas as voltas são dados.

### 25/09/22

Contest: [Codeforces Round #823 (Div. 2)](https://codeforces.com/contest/1730)
Tempo: 2 horas
Individual.

Primeiro contest individual que eu faço em muito tempo. Tentarei fazer mais nos próximos dias para evitar atrasar no cronograma.

Foi um contest bem incomum, no qual o problema B teve menos acertos que o problema C.

O problema A é bem simples, apenas uma iteração do vetor de entrada é suficiente para resolvê-lo.

O problema B foi inicialmente muito familiar para mim, pois já resolvi outros parecidos. Em resumo, ele pedia o ponto de encontro em uma reta que minimizasse o tempo máximo que uma das n pessoas demoraria para chegar nesse ponto. Cada pessoa tinha um tempo para se arrumar e uma posição inicial. Inicialmente, tentei fazer uma busca ternária mas as submissões deram errado. Tive uma ideia de chegar na resposta mais diretamente e também falhou no mesmo caso de teste. Pulei o problema e só mais tarde no contest eu descobri que o problema era a precisão da resposta. O C++ imprimia algumas respostas em notação científica e isso fazia com que a precisão fosse menor que o necessário. Achei estranho que essa foi a primeira vez que tive problema com isso.

Considerei o problema C mais fácil que o B. Resolvi ele com um algoritmo guloso.

## Outubro

### 04/10

Contest: [2018 ACM-ICPC, Universidad Nacional de Colombia Programming Contest](https://codeforces.com/gym/101845)
Tempo: 5 horas
Time: eu, Cássio e João Guilherme.

O meu time original, formado por mim, pelo Antônio e pelo Thiago se desfez, pois Thiago não poderia participar da nacional em 2023. O Antônio foi para outro time e, como o Cássio e João Guilherme queriam participar da prova, decidi continuar no time para fazer a prova com eles. Decidi fazer esse contest com eles antes da prova para treinar.

Resolvemos 8 dos 13 problemas da prova, eu fiz o A, o F e o M.

Para o problema A, utilizei uma exponenciação de matriz. Tive dificuldade de modelar inicialmente com uma matriz pequena 5x5, então decidi fazer com uma 45x45 e mesmo assim.

O problema F é de fluxo e a solução é bem direta. Utilizei o template de Dinic que estava no caderno.

Já o problema M é de matemática, gastei mais tempo fazendo as contas no papel, pois o código é bem curto.
