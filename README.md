# Projeto Final da Cadeira de Estrutura de Dados - UFRGS

Alunos: Eduarda Guterres, Bernardo Gehlen e Rodrigo Vanzelotti

Projeto: Contruir o de tabuleiro Jogo da Vida

O projeto é separado em 3 estruturas e em 4 principais tipos de arquivos, tirando a main. Temos as estruturas:
    
- Roleta, que é uma Lista Encadeada Circular.
- Jogador, que é uma Lista Encadeada Circular.
- Tabuleiro, que é uma Lista Encadeada Dupla.

Alem das estruturas, que possuem seus proprios arquivos, temos o arquivo jogo, onde se encontra todas as principais funções para que o jogo opere. Nesse arquivo há funçoes que fazem criação das estruturas para que o jogo funcione, checagens e chamadas das outras estruturas e do menu.

## O Tabuleiro:

A estrutura do tabuleiro foi pensada para atender as principais funcionalidades do jogo. Temos que a estrutura das informações do nodo se dá da seguinte forma:

    {numeroDaCasa, TipoDeCasa, TextoDaCasa, Dinheiro, AndaCasa, QuantasCasa, MembrosDaFamilia}

 - numeroDaCasa: Representa o id da casa.

 - TipoDeCasa: Diz qual é o tipo de casa do nodo em questao. Pode-se ter 4 tipos de casa: 
   - tipo 1: São as casas de profissão, elas dão uma profissão para o jogador em questão. É necessário que ele tenha uma profissão definida para que ele possa ganhar seu salário no dia do Pagamento.
   - tipo 2: São os tipos de casas em que o jogador pode tanto perder quanto ganhar dinheiro.
   - tipo 3: São as casas do Dia do Pagamento. Nelas o jogador receberá o seu salário. Não é necessário parar em uma casa do Dia do Pagamento para receber o salario, se um jogador passar por ela ele automaticamente ganha seu salario. Caso algum jogador cai na casa do dia do pagamento sem possuir alguma profissão seu salario passará a ser automaticamente R$ 16.000.
   - tipo 5: Sao as casas em que a familia aumenta. Pode aumentar tanto 1 quanto 2 pessoas na familia dependendo da casa. O numero de membros na familia se torna dinheiro no final do jogo. 
  
- TextoDaCasa: Possui o texto de cada Casa.
- Dinheiro: Essa info é para caso a casa seja do tipo 2, Perde/Ganha Dinheiro. Nela contem o valor que será perdido ou recebido pelo jogado.
- AndaCasa: Dependendo da casa em que o jogador cai, podendo ser tanto do tipo 1 quando do tipo 2, pode ser que ele tenha que andar ou retroceder um numero X de casas. Logo, aqui temos se a casa em questão possui esse tipo de operação, caso seja necessário andar casas 1, caso contrário seu valor é 0.
- QuantasCasa: Aqui se diz o numero de casas em que o jogador retrocederá ou avançará.
- MembrosDaFamilia: Caso caia em uma casa do tipo 5, o valor de MembrosDaFamilia será diferente de 0, podendo assumir tanto o valor de 1 quanto de 2, há depender do texto da casa.

Com essas informações é possivel contruir inumeros outros tipos de casas para o tabuleiro. Contudo ele deverá ter sempre 80 casas para seu funcionamento.

## A Roleta
A roleta informa a quantidade de numeros que o jogador terá que andar de casas, com isso, ela é randomica. Além disso, para que desse um pouco mais de sensação que a roleta realmente está girando, foi escolhido o numero 21 para a funcao randomica. Com isso, a roleta gira mais de uma vez, dependendo do numero em que foi sorteado. Assim, a roleta foi construida com uma lista Encadeada Circular.

## O Jogador
Os jogadores possuem a estrutura lista Encadeada Circular, para que seja mais entuitivo o sistema de vez em cada rodada. Assim, quando acaba a vez de um jogador passa-se para o proximo e assim em diante até o final do jogo. 

O jogo foi desenhado para que seja jogado contra o computador. Com isso temos sistemas em que possuem um sleep para que se tenha a sensação de que o computador está jogando. Para os usuarios, temos o pause que é utilizado para que ele tenha interação com o computador, como tambem, para que ele possa sozinho determinar quando já terminou de ler e quer realizar sua jogada.

O jogador, como o tabuleiro, possui uma estrutura de suas informações que se dá da seguinte forma:

    {numJogador, posicao, salario, dinheiro, familia}

- NumJogador: É a id do jogador. O usuario sempre será o jogador 1 e o computador o 2.
- Posicao: Diz em que lugar do tabuleiro o jogador está.
- Salario: Mostra o valor do salario do jogador, que depende de sua profissão.
- Dinheiro: Mostra o quanto de dinheiro o jogador tem, todos os jogadores começam com R$ 10.000.
- Familia: Mostra quantas pessoas possui a familia. No inicio do jogo esse valor é 1 que representa o proprio jogador. Quando há um novo membro na familia esse valor é mudado.

## Fim de Jogo 

O jogo pode acabar de duas maneiras, pela posição de um jogador ou pelo dinheiro:

- Fim por posição: Nesse caso o jogo acaba quando o primeiro jogador passar por todas as casas, ou seja, quando ele passar da casa 80. Quando isso ocorre, se verifica quando membros o jogador possui na sua familia, que sao transformados em dinheiro multiplicando-se por 5000. E depois é somado com o valor total que ele possui no campo dinheiro.
- Fim por dinheiro: Acontece quando algum jogador chega a menos de zero no campo do dinheiro. Com isso, automaticamente o outro jogador ganha.