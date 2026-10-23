#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Necessário para gerar números aleatórios

// REQUISITO 1: Cria e grava o arquivo original com dados desordenados
void criarArquivoDados(const char *arquivo) {
    FILE *fp = fopen(arquivo, "w");
    if (fp == NULL) {
        printf("Erro ao criar o arquivo %s.\n", arquivo);
        return;
    }

    int quantidade = 10; // Quantidade padrão de números
    srand(time(NULL));   // Inicializa o gerador de números aleatórios

    for (int i = 0; i < quantidade; i++) {
        int num = rand() % 100; // Gera números aleatórios de 0 a 99
        fprintf(fp, "%d ", num);
    }
    fprintf(fp, "\n");

    fclose(fp);
    printf("Arquivo '%s' criado com sucesso com valores desordenados!\n", arquivo);
}

// REQUISITO 2: Lê os dados do arquivo para o vetor
int lerNumeros(const char *arquivo, int v[], int max) {
    FILE *fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo %s. Certifique-se de que ele foi criado (Opcao 1).\n", arquivo);
        return -1;
    }

    int n = 0;
    while (n < max && fscanf(fp, "%d", &v[n]) == 1) {
        n++;
    }

    fclose(fp);
    return n;
}

// REQUISITO 4: Grava o resultado ordenado em um novo arquivo
void gravarResultado(const char *arquivo, int v[], int n, const char *algoritmo) {
    FILE *fp = fopen(arquivo, "w");
    if (fp == NULL) {
        printf("Erro ao criar o arquivo de resultado.\n");
        return;
    }

    fprintf(fp, "Algoritmo usado: %s\n", algoritmo);
    fprintf(fp, "Numeros ordenados: ");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", v[i]);
    }
    fprintf(fp, "\n");

    fclose(fp);
    printf("Resultado salvo com sucesso em '%s'\n", arquivo);
}

// Métodos de ordenação mantidos do seu colega
void bubblesort(int v[], int n) {
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void insertionSort(int v[], int n) {
    int i, j, chave;
    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

void selectionSort(int v[], int n) { 
    int i, j, min, aux; 
    for (i = 0; i < n - 1; i++) { 
        min = i;
        for (j = i + 1; j < n; j++) { 
            if (v[j] < v[min]) min = j; 
        } 
        aux = v[i]; 
        v[i] = v[min]; 
        v[min] = aux; 
    } 
} 

void merge(int v[], int inicio, int meio, int fim) { 
    int i = inicio, j = meio + 1, k = 0; 
    int aux[fim - inicio + 1]; 
 
    while (i <= meio && j <= fim) { 
        if (v[i] <= v[j]) aux[k++] = v[i++]; 
        else aux[k++] = v[j++]; 
    } 
 
    while (i <= meio) aux[k++] = v[i++]; 
    while (j <= fim) aux[k++] = v[j++];  
    for (i = inicio, k = 0; i <= fim; i++, k++) 
        v[i] = aux[k]; 
} 
 
void mergeSort(int v[], int inicio, int fim) { 
    if (inicio < fim) { 
        int meio = (inicio + fim) / 2; 
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    } 
} 

void quickSort(int v[], int inicio, int fim) { 
    int i = inicio, j = fim, pivo = v[(inicio + fim) / 2], aux; 
     
    while (i <= j) { 
        while (v[i] < pivo) i++; 
        while (v[j] > pivo) j--; 
        if (i <= j) { 
            aux = v[i]; 
            v[i] = v[j]; 
            v[j] = aux; 
            i++; 
            j--; 
        } 
    } 
    if (inicio < j) quickSort(v, inicio, j); 
    if (i < fim) quickSort(v, i, fim); 
} 

// Função auxiliar para aplicar a ordenação escolhida pelo usuário
void executarOrdenacao(int v[], int n) {
    int escolha;
    const char *nomeAlgoritmo = "Nenhum";

    printf("\nEscolha o algoritmo de ordenacao:\n");
    printf("[1] Bubble Sort\n[2] Insertion Sort\n[3] Selection Sort\n[4] Merge Sort\n[5] Quick Sort\nOpcao: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: 
            bubblesort(v, n);        
            nomeAlgoritmo = "Bubble Sort";    
            break;
        case 2: 
            insertionSort(v, n);    
            nomeAlgoritmo = "Insertion Sort"; 
            break;
        case 3: 
            selectionSort(v, n);     
            nomeAlgoritmo = "Selection Sort"; 
            break;
        case 4: 
            mergeSort(v, 0, n - 1);  
            nomeAlgoritmo = "Merge Sort";     
            break;
        case 5: 
            quickSort(v, 0, n - 1);  
            nomeAlgoritmo = "Quick Sort";     
            break;
        default:
            printf("Opcao invalida. Ordenacao cancelada.\n");
            return;
    }

    printf("Numeros ordenados na memória: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    // Salva automaticamente no arquivo de saída exigido pelo professor
    gravarResultado("ordenado.txt", v, n, nomeAlgoritmo);
}

// REQUISITO 5: Altera um valor específico diretamente no arquivo original
void alterarValorNoArquivo(const char *arquivo) {
    int v[1000];
    int n = lerNumeros(arquivo, v, 1000);
    if (n <= 0) return;

    printf("\nValores atuais no arquivo original:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d]: %d  ", i, v[i]);
    }
    printf("\n");

    int indice, novoValor;
    printf("Digite o indice do valor que deseja alterar (0 a %d): ", n - 1);
    scanf("%d", &indice);

    if (indice < 0 || indice >= n) {
        printf("Indice invalido!\n");
        return;
    }

    printf("Digite o novo valor: ");
    scanf("%d", &novoValor);

    v[indice] = novoValor;

    // Reescreve o arquivo original modificado
    FILE *fp = fopen(arquivo, "w");
    if (fp == NULL) {
        printf("Erro ao atualizar o arquivo.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", v[i]);
    }
    fprintf(fp, "\n");
    fclose(fp);

    printf("Valor alterado no arquivo com sucesso!\n");

    // Reordena imediatamente após a modificação como pedido na regra 5
    executarOrdenacao(v, n);
}

int main() {
    int v[1000];
    int n = 0;
    int opcaoMenu;
    const char *nomeEntrada = "dados.txt";

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("[1] Criar arquivo de dados original (dados.txt)\n");
        printf("[2] Ler dados e Ordenar (Salva em ordenado.txt)\n");
        printf("[3] Alterar um valor no arquivo e Reordenar\n");
        printf("[0] Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu) {
            case 1:
                criarArquivoDados(nomeEntrada);
                break;
            case 2:
                n = lerNumeros(nomeEntrada, v, 1000);
                if (n > 0) {
                    executarOrdenacao(v, n);
                }
                break;
            case 3:
                alterarValorNoArquivo(nomeEntrada);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcaoMenu != 0);

    return 0;
}
