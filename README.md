# algoritmos-ordenacao-c

# Algoritmos de Ordenação e Manipulação de Arquivos em C

Projeto desenvolvido como atividade avaliativa para a disciplina de Algoritmos e Pensamento Computacional. O objetivo principal é unir conceitos de manipulação de arquivos em disco com os principais algoritmos de ordenação estudados.

## Funcionalidades

O programa conta com um menu interativo executado em loop que permite:
1. **Gerar Dados Desordenados:** Cria e grava automaticamente um arquivo (`dados.txt`) contendo 10 números inteiros aleatórios.
2. **Leitura e Ordenação:** Lê os dados do arquivo de entrada e permite ao usuário escolher qual algoritmo utilizar para ordenar o vetor.
3. **Persistência de Resultados:** Grava os valores ordenados em um novo arquivo (`ordenado.txt`), identificando o algoritmo que foi utilizado.
4. **Alteração Dinâmica:** Permite escolher um índice do vetor, alterar o seu valor diretamente no arquivo de entrada e disparar uma nova reordenação imediata.

![Menu Interativo do Programa](menu.png)


## Algoritmos de Ordenação Implementados

O sistema traz a implementação manual de 5 dos principais métodos de ordenação da literatura:
*  **Bubble Sort**
*  **Insertion Sort**
*  **Selection Sort**
*  **Merge Sort**
*  **Quick Sort**

##  Estrutura do Repositório

* `main.c`: Código-fonte principal com o menu e as lógicas de ordenação/arquivos.
* `dados.txt`: Arquivo de texto que armazena os valores de entrada gerados.
* `ordenado.txt`: Arquivo de texto gerado após o processo de ordenação com o resultado final.

##  Como Executar o Projeto

1. Baixe o arquivo `main.c`.
2. Compile o código utilizando um compilador C (como GCC) ou utilize um ambiente integrado como o VS Code ou OnlineGDB.
3. Execute o programa e utilize as opções numéricas do menu para interagir com os arquivos de texto.
