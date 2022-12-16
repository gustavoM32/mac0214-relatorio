# Relatório MAC0214

Tempo em atividades: 89/100 horas
* Contests de 5 horas: 35/55 horas
* Contests de 2 horas: 12/20 horas
* Upsolving: 42/20 horas
* Revisão: 0/5 horas

## Agosto

5 horas.

### 28/08/22

* Contest: [2017-2018 ICPC Central Quarter Final of Northeastern European Regional Collegiate Programming Contest](https://codeforces.com/gym/102788)
* Tempo: 5 horas
* Time: eu, Antônio e Enrique

Um contest com 12 problemas, conseguimos resolver 10 deles. Resolvi os problemas C, H, I, J, K:
O C foi um problema bem interessante de gerar combinações de k a k entre n em ordem de modo que duas consecutivas sejam diferentes em apenas um número. Tive um pouco de dificuldade para otimizar a recursão nessa questão.

O H foi uma busca binária com dp.

O I consistia em apenas listar os divisores de um número.

O J precisou usar somas de prefixos pra calcular a soma em um intervalo rapidamente.

O K foi um problema muito legal de hanoi. Considerando que o hanoi é resolvido pelo algoritmo padrão (dado no enunciado), e dados vários estados diferentes de distribuições dos discos, encontrar aquele que está mais próximo da solução.

## Setembro

22 horas.

### 04/09/22

* Contest: [2017-2018 Northwestern European Regional Contest (NWERC 2017)](https://codeforces.com/gym/101623)
* Tempo: 5 horas
* Time: eu e Antônio.

Contest com 11 problemas e resolvemos 6 deles. Resolvi os problemas D e K:
O D consiste em ver de quantas maneiras corretas e incorretas é possível traduzir uma dada frase, a entrada também dá pares de palavras indicando se a tradução está correta e incorreta. A solução é bem ad-hoc.

O K pede para escolher distribuição dos jogadores nas chaves de um torneio de modo que um deles tenha a maior probabilidade de vencer, o problema pede apenas para imprimir essa probabilidade. Cada jogador tem um certo nível de dificuldade. A solução é gulosa e consiste em fazer com que o jogador que queremos que ganhe dispute com os mais fáceis. Calculamos cada estado do torneio com distribuições de probabilidades.

### 11/09/22

* Contest: [2021 ICPC Southeastern Europe Regional Contest](https://codeforces.com/gym/103438)
* Tempo: 5 horas
* Time: eu e Antônio.

O contest tinha 14 problemas e resolvemos 7 deles. Resolvi o J e o N:
O J dá uma string com os caracteres ABC e pergunta se é possível decompô-la em substrings AB, AC e BC. Se é, é necessário imprimir uma decomposição. A solução foi um algoritmo guloso, mas tive dificuldade para chegar na solução correta. Uma característica dos algoritmos gulosos é a dificuldade de se provar a sua corretude, ainda mais durante a prova. Acredito que, para evitar submissões incorretas para esse tipo de problema, eu deveria testar melhor o meu código.

O N também tem uma solução gulosa, mas bem mais simples. O problema fornece uma quantidade inicial e uma quantidade objetivo para cada tamanho de papel e pergunta o número mínimo de cortes para se conseguir o objetivo.

### 17/09/22

* Contest: Seletiva USP 2022
* Tempo: 5 horas
* Time: eu, Antônio e Thiago.

A prova ainda não está disponível em um site, também não tenho acesso às minhas soluções pois ela foi feita no BOCA, semelhante a maratona. Essa prova seleciona times para a participação na primeira fase da Maratona SBC de Programação. Nosso time ficou em primeiro lugar.

O problema B era de simulação mas tinha muitos detalhes pra levar em conta. Fiz parte dele e o Antônio continuou da parte que eu estava travado e conseguiu resolver o problema.

O problema I é de matemática. Minha solução passou mas depois da prova descobri que tinha uma mais eficiente. Também fiz alguma submissões incorretas que eu poderia evitar.

### 24/09/22

* Contest: [Fase Zero da Maratona de Programação da SBC](https://www.beecrowd.com.br/judge/pt/challenges/contest/683)
* Tempo: 5 horas
* Time: eu, Antônio e Thiago.

Essa é a primeira edição da fase zero da maratona. A prova foi realizada na plataforma de problemas Beecrowd.

A prova foi realizada online e permitia o uso de três computadores, mas nosso time decidiu usar somente um para a escrita de código, para servir de prática para a prova real.

Resolvemos 9 dos 12 problemas da prova. Os primeiros problemas foram fáceis e então a maior dificuldade foi o uso de um único computador. Tivemos dificuldades na interpretação de alguns problemas.

Resolvi os problemas A, J e K:
O problema A consiste em calcular a média final dos alunos de uma univerisdade seguindo um determinado critério. O problema é fácil, com somente a leitura da entrada sendo não trivial.

O J também era um problema fácil, e sobre conversão do tempo em jogo de futebol.

O problema K foi um que eu tive bastante dificuldade de entender o que estava sendo pedido, mas depois de um tempo eu consegui. Ele pede para achar o piloto que teve o melhor tempo de volta em uma corrida de fórmula 1 segundo alguns critérios especificados no enunciado. Os tempos dos pilotos em todas as voltas são dados.

### 25/09/22

* Contest: [Codeforces Round #823 (Div. 2)](https://codeforces.com/contest/1730)
* Tempo: 2 horas
Individual.

Primeiro contest individual que eu faço em muito tempo. Tentarei fazer mais nos próximos dias para evitar atrasar no cronograma.

Foi um contest bem incomum, no qual o problema B teve menos acertos que o problema C.

O problema A é bem simples, apenas uma iteração do vetor de entrada é suficiente para resolvê-lo.

O problema B foi inicialmente muito familiar para mim, pois já resolvi outros parecidos. Em resumo, ele pedia o ponto de encontro em uma reta que minimizasse o tempo máximo que uma das n pessoas demoraria para chegar nesse ponto. Cada pessoa tinha um tempo para se arrumar e uma posição inicial. Inicialmente, tentei fazer uma busca ternária mas as submissões deram errado. Tive uma ideia de chegar na resposta mais diretamente e também falhou no mesmo caso de teste. Pulei o problema e só mais tarde no contest eu descobri que o problema era a precisão da resposta. O C++ imprimia algumas respostas em notação científica e isso fazia com que a precisão fosse menor que o necessário. Achei estranho que essa foi a primeira vez que tive problema com isso.

Considerei o problema C mais fácil que o B. Resolvi ele com um algoritmo guloso.

## Outubro

14 horas.

### 04/10

* Contest: [2018 ACM-ICPC, Universidad Nacional de Colombia Programming Contest](https://codeforces.com/gym/101845)
* Tempo: 5 horas
* Time: eu, Cássio e João Guilherme.

O meu time original, formado por mim, pelo Antônio e pelo Thiago se desfez, pois Thiago não poderia participar da nacional em 2023. O Antônio foi para outro time e, como o Cássio e João Guilherme queriam participar da prova, decidi continuar no time para fazer a prova com eles. Decidi fazer esse contest com eles antes da prova para treinar.

Resolvemos 8 dos 13 problemas da prova, eu fiz o A, o F e o M.

Para o problema A, utilizei uma exponenciação de matriz. Tive dificuldade de modelar inicialmente com uma matriz pequena 5x5, então decidi fazer com uma 45x45 e mesmo assim.

O problema F é de fluxo e a solução é bem direta. Utilizei o template de Dinic que estava no caderno.

Já o problema M é de matemática, gastei mais tempo fazendo as contas no papel, pois o código é bem curto.

### 08/10

* Contest: [Maratona de Programação da SBC 2022 - primeira fase](http://maratona.sbc.org.br/resultados22/reports/problems/maratona.pdf)
* Tempo: 5 horas
* Time: eu, Cássio e João Guilherme.

Essa foi a prova oficial da primeira fase da Maratona de Programação da SBC. Fiz os problemas D, F e I.

O problema D é parecido com um que já fiz antes, mas acabei errado a primeira solução, que só corrigi depois.

O F eu fiquei muito tempo tentando pois tinha entendido errado, estava tentando resolver um problema mais complexo do que estava sendo pedido. O João Guilherme deu a sacada final no problema e eu a implementei.

O I era um problema muito fácil.

Fiquei o resto da prova tentando o problema N, mas não consegui. Faltou pensar na estrutura certa pra resolver o problema, fiquei muito tempo tentando procurar a estrutura certa pra ele.

Fizemos 6 dos 14 problemas.

### 26/10
Como o meu time se desfez e não irei fazer a nacional, decidi diminuir o tempo em contests de 5 horas e focar em contests de 2 horas e em resolver problemas individuais, focando naqueles de contests que eu já fiz.

### 27/10

* Upsolving
* Tempo: 1,5 horas

#### [1753B. Factorial Divisibility](https://codeforces.com/problemset/problem/1753/B)

Um problema de teoria dos números. Tive a ideia de combinar fatoriais pequenos para formar maiores, ou seja, utilizei um algoritmo guloso para resolver.

#### [1739D. Reset K Edges](https://codeforces.com/problemset/problem/1739/D)

Usei busca binária na resposta e depth first search nesse problema. Tive a ideia e implementei rapidamente, mas acabei gastando muito tempo debugando. Também acho que o código ficou muito lento, apesar de ter passado.

### 29/10

* Upsolving
* Tempo: 2,5 horas

#### [1674G. Remove Directed Edges](https://codeforces.com/problemset/problem/1674/G)

O problema é de grafos. Fiquei pensando por muito tempo e cheguei na conclusão que daria de remover cada arco que ou é o único que sai de um vértice ou é o único que incide sobre um vértice. Depois disso seria possível formar caminhos no grafo restante independente de como a remoção dos outros arcos se daria. Depois de ler o início do editorial consegui resolver o problema.

#### [1739C. Card Game](https://codeforces.com/problemset/problem/1739/C)

O problema envolve teoria dos jogos e combinatória. Depois de pensar nas estratégias que o jogadores podem escolher, é possível encontrar uma recorrência para chegar na resposta.

## Novembro

32,5 horas.

### 22/11

* Upsolving
* Tempo: 2 horas

#### [1753C. Wish I Knew How to Sort](https://codeforces.com/problemset/problem/1753/C)

Um problema de programação dinâmica e de esperança estatística. A modelagem da DP foi um pouco difícil, só consegui depois de ler o editorial.

### 23/11

* Upsolving
* Tempo: 6 horas

#### [1716C. Robot in a Hallway](https://codeforces.com/problemset/problem/1716/C)

Um problema bem complicado pra um C de um educational. Fiquei um bom tempo tentando e debugando, mas tive que ler o editorial pra resolver.

#### [748B. Santa Claus and Keyboard Check](https://codeforces.com/contest/748/problem/B)

Problema simples de strings, mas errei algumas vezes. Usei um map para registrar os pares de teclas trocadas, mas esqueci de dividir a contagem final por dois.

#### [540B. School Marks](https://codeforces.com/contest/540/problem/B)

Problema guloso simples sobre mediana, errei primeira submissão pois esqueci de limitar um dos loops.

#### [630E. A rectangle](https://codeforces.com/contest/630/problem/E)

O problema é relativamente simples e envolve matemática em um contexto de geometria. Tive problemas com o módulo de número negativos e não tinha percebido que a entrada que indica a configuração dos hexagonos.

#### [614D. Polyline](https://codeforces.com/contest/617/problem/D)

Um problema de geometria que precisa considerar diferentes casos, mas de simples implementação. Errei várias vezes por não considerar alguns casos.

### 26/11

* Upsolving
* Tempo: 5 horas

#### [612D. The Union of k-Segments](https://codeforces.com/contest/612/problem/D)

Problema de intervalos. Criei um vetor de pontos que indicam se um intervalo começa ou termina. Tive dificuldade no início pra modelar mas no fim o código ficou bem claro, sem bugs e passou na primeira tentativa.

#### [761D. Dasha and Very Difficult Problem](https://codeforces.com/contest/761/problem/D)

Usei um algoritmo guloso nesse problema, passei na primeira tentativa.

#### [659F. Polycarp and Hay](https://codeforces.com/contest/659/problem/F)

Foi muito interessante resolver esse problema. Usei o algoritmo union-find em uma matriz para construir uma outra que me ajudou a encontrar a solução. Também precisei fazer uma dfs pra imprimir a resposta final.

#### [1092E. Minimal Diameter Forest](https://codeforces.com/contest/1092/problem/E)

O problema envolve encontrar os diâmetros e os centros de árvores. Errei duas submissões por tentar deduzir o diâmetro final sem montar a árvore mas deu certo quando calculei ele depois de montá-la.

### 27/11

* Upsolving
* Tempo: 8,5 horas

Resolvi fazer o upsolving de problemas de contests que fiz em equipe, pois até agora estava tentando problemas de contests regulares do Codeforces.

### Pending

#### [101669I. Tetris](https://codeforces.com/gym/101669)
É um problema de implementação, um tipo que gosto bastante de tentar resolver. Eu tentei uma solução que testa tudo, mas ela tem dois problemas.

O primeiro é que ela não funciona para o segundo caso de teste e pode ter a ver com o que o problema define como uma peça não encaixar no tabuleiro. Depende se eu devo rotacionar ela antes ou depois de ela aparecer no tabuleiro.

O segundo é que ela demora demais pra alguns casos, deve ter algum jeito de otimizar que eu não vi ainda, mas não tenho certeza se a minha solução está indo ao caminho certo.

Não consegui resolver o problema e não encontrei um editorial para ele.

#### [G. Goguryeo and the Crown Prince](https://vjudge.net/contest/478186#problem/G)

O problema é de probabilidades com uma certa circularidade (o cálculo de uma probabilidade depende de seu próprio valor). Tentei várias coisas para resolvê-lo mas ainda não consegui passar.

Tentei usar programação dinâmica, fazer várias iterações de uma cadeia de Markov, incluindo exponenciação de matriz. Pela matriz que eu modelei ser muito grande, o problema não passou em tempo em várias submissões.

A solução deve ser algo com menor complexidade do que eu tentei, mas não encontrei um editorial para esse problema.

### 28/11

* Upsolving
* Tempo: 6,5 horas

#### [102392K. Stranded Robot](https://codeforces.com/gym/102392/problem/K)

Um problema de implementação que requer otimização de memória, pois envolve um espaço 3D de dimensões até 500x500x500. Fiz cada parte incrementalmente pra evitar bugs, mas o limite de memória foi passado no teste 17. Ainda tenho que otimizar o uso dela, mas acredito que a implementação esteja correta.

### 30/11

* Upsolving
* Tempo: 4,5 horas

#### [102392K. Stranded Robot](https://codeforces.com/gym/102392/problem/K)

Li o editorial do problema e vi que a ideia é alcançar a complexidade O(N^2) após a leitura da entrada. Consegui otimizar a memória o suficiente para não ultrapassar o limite, mas agora o problema está no tempo de execução. O meu algoritmo ainda é cúbico.

Esse é um problema extremamente difícil pra se fazer durante uma prova, porque envolve uma boa implementação sem bugs ao mesmo tempo que cobra uma otimização muito boa. Não é a toa que ninguém o passou na prova oficial. 

Tentarei limitar a complexidade cúbica à leitura do input na próxima tentativa.

## Dezembro

15,5 horas.

### 01/12

* Contest: [Educational Codeforces Round 138 (Rated for Div. 2)](https://codeforces.com/contest/1749)
* Tempo: 2 horas
Individual.

Tive um desempenho bom nesse contest considerando que faz tempo que eu não faço um. Resolvi 4 dos 6 problemas, não errei nenhuma submissão.

O problema A precisou de somente uma desigualdade para resolver.

O problema B possui uma solução gulosa, mas nem foi necessário implementar com um algoritmo guloso, bastou pegar o máximo de um vetor.

O problema C foi um que gastei mais tempo que o necessário. A entrada é pequena, mas tentei otimizar a solução de qualquer jeito. Não consegui, no fim implementei sem otimizar e passou.

O problema D usou um pouco de teoria dos números, achei legal resolvê-lo. Pareceu bem complicado no início, mas a solução é bem simples de entender.

### 02/12

* Contest: [Educational Codeforces Round 137 (Rated for Div. 2)](https://codeforces.com/contest/1743)
* Tempo: 2 horas
Individual.

Quase tive um desempenho muito bom nesse contest. Resolvi 4 dos 7 problemas e consegui resolver o E 10 minutos após o fim. Cometi alguns pequenos erros, principalmente no problema C.

O problema A é outro no qual é possível ignorar parte da entrada, a resposta é uma expressão simples.

O problema B também é bem simples, basta construir uma resposta que serve pra qualquer valor de n.

O problema C é relativamente simples, mas demorei pra chegar na melhor solução. Cometi erros por alterar o jeito de resolver mas esquecer de mudar todos os detalhes.

O problema D tem um estilo único, pois a entrada é gerada aleatoriamente. A princípio eu não encontrei um jeito de usar isso, mas depois de pensar na solução força bruta que eu entendi. A solução é teoricamente quadrática (o que iria estourar o limite de tempo), mas a chance da entrada fazer o algoritmo lendo é muito pequena.

O problema E usa programação dinâmica e eu demorei pra corrigir alguns bugs, então só resolvi deois do contest.

### 03/12

* Contest: [Educational Codeforces Round 135 (Rated for Div. 2)](https://codeforces.com/contest/1728)
* Tempo: 2 horas de contest + 0,5 horas de upsolving do D
Individual.

Tive um desempenho ruim nesse contest. Comecei mal porque mandei o arquivo errado no primeiro problema, gastei um tempo tentando achar um bug que não existia. Depois fiquei um bom tempo no problema D e descobri que entendi o problema errado.

O problema A foi somente encontrar o índice do elemento com maior valor em um vetor.

Para o problema B, foi necessário construir uma permutação específica.

O problema C eu resolvi em etapas, mas o editoral traz uma solução mais direta. De qualquer forma, ambas tem complexidade O(n log n).

O problema D consiste em definir o ganhador de um jogo. Durante a prova, eu perdi um detalhe muito importante: as letras são adicionados no início da string dos jogadores. Eu tentei resolver o problema no qual elas são adicionadas no final. Iniciei com um algoritmo guloso e depois troquei para programação dinâmica. Depois que eu percebi o erro de leitura, tentei adaptar o código e, por isso, esqueci alguns detalhes e não consegui enviar o problema antes do final da prova. Eu deveria ter lido o enunciado com mais atenção e, percebido o erro, deveria ter tentando iniciar a resolução do zero. Consegui resolver o problema depois da prova após adicionar dois métodos para cada jogador ao invés de fazer tudo em um só. Mesmo assim, a solução ficou mais complicada do que precisava.

### 08/12
* Contest: [Codeforces Round #836 (Div. 2)](https://codeforces.com/contest/1758)
* Tempo: 2 horas de contest + 4 horas de upsolving
Individual.

Resolvi o problema A rapidamente, mas acabei perdendo muito tempo no B. Depois de um tempo eu pulei para o problema C.

O problema C foi interessante, usei fatoração junto com um algoritmo guloso.

O problema D eu fiquei tentando até o final da prova. Ele tem uma estrutura semelhante ao B: encontrar n números tal que a uma igualdade seja satisfeita, com a diferença de que os números precisam ser distintos. Li o editorial para resolver, a solução na verdade é bem mais simples do que eu pensava.

O problema E eu não cheguei a ler durante a prova, mas quis tentar depois de ela terminar. É um problema que usa componentes conexas de um grafo, usei o algoritmo union find. Fiquei um bom tempo fazendo, mas não cheguei na resposta certa. Depois que eu li o editorial, tive que adaptar bem pouco do meu código. No entanto, ainda não estava passando. No fim eu descobri que eu errei uma variável no método union.

### 13/12
* Contest: [Educational Codeforces Round 139 (Rated for Div. 2)](https://codeforces.com/contest/1766)
* Tempo: 2 horas de contest + 1 hora de upsolving
Individual.

Resolvi 4 dos 6 problemas da prova.

Os três primeiros problemas foram bem simples de resolver.

O problema D envolveu fatoração. Eu fiz uma solução ineficiente no início por falta de atenção aos limites do problema. Mas depois eu fiz um crivo para fazer uma fatoração mais rápida e o problema passou.

Fiquei o restante do contest no problema E, mas a solução não funcionou para o caso 16. Continuei tentando por um tempo depois de acabar, mas ainda não consegui resolver. O problema ainda não tem editorial.


