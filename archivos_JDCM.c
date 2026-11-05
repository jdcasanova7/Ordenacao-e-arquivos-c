#include <stdio.h>

// Funcao pra organizar em Bubble Sort
void bubble_sort(int vetor[], int quantidade) {
    int i, j, auxiliar;

    for (i = 0; i < quantidade - 1; i++) {

        for (j = 0; j < quantidade - i - 1; j++) {

            // Se o numero for maior que o proximo, troca de posicao
            if (vetor[j] > vetor[j + 1]) {

                auxiliar = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = auxiliar;

            }

        }

    }

}

// Funcao pra organizar em Insertion Sort
void insertion_sort(int vetor[], int quantidade) {
    int i, j, chave;

    for (i = 1; i < quantidade; i++) {

        // Guarda o numero que vai ser colocado no lugar certo
        chave = vetor[i];
        j = i - 1;

        // Empurra pra direita os numeros que sao maiores que a chave
        while (j >= 0 && vetor[j] > chave) {

            vetor[j + 1] = vetor[j];
            j = j - 1;

        }

        vetor[j + 1] = chave;

    }

}

// Funcao pra organizar em Selection Sort
void selection_sort(int vetor[], int quantidade) {
    int i, j, posicao_menor, auxiliar;

    for (i = 0; i < quantidade - 1; i++) {

        // Pensa que o menor numero esta na posicao i
        posicao_menor = i;

        for (j = i + 1; j < quantidade; j++) {

            if (vetor[j] < vetor[posicao_menor]) {

                posicao_menor = j;

            }

        }

        // Troca o menor numero encontrado com a posicao i
        auxiliar = vetor[i];
        vetor[i] = vetor[posicao_menor];
        vetor[posicao_menor] = auxiliar;

    }

}

// Junta duas partes que ja estao ordenadas (usada no Merge Sort)
void junta(int vetor[], int inicio, int meio, int fim) {
    int temporario[100];
    int i, j, k;

    i = inicio;
    j = meio + 1;
    k = 0;

    // Compara as duas partes e guarda o menor numero no temporario
    while (i <= meio && j <= fim) {

        if (vetor[i] <= vetor[j]) {

            temporario[k] = vetor[i];
            i = i + 1;

        } else {

            temporario[k] = vetor[j];
            j = j + 1;

        }

        k = k + 1;

    }

    // Copia o que sobrou da primeira parte
    while (i <= meio) {

        temporario[k] = vetor[i];
        i = i + 1;
        k = k + 1;

    }

    // Copia o que sobrou da segunda parte
    while (j <= fim) {

        temporario[k] = vetor[j];
        j = j + 1;
        k = k + 1;

    }

    // Devolve os numeros ordenados para o vetor original
    for (i = 0; i < k; i++) {

        vetor[inicio + i] = temporario[i];

    }

}

// Funcao pra organizar em Merge Sort (divide ao meio e junta ordenando)
void merge_sort(int vetor[], int inicio, int fim) {
    int meio;

    if (inicio < fim) {

        meio = (inicio + fim) / 2;

        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
        junta(vetor, inicio, meio, fim);

    }

}

// Funcao pra organizar em Quick Sort (usa o numero do meio como pivo)
void quick_sort(int vetor[], int esquerda, int direita) {
    int i, j, pivo, auxiliar;

    i = esquerda;
    j = direita;
    pivo = vetor[(esquerda + direita) / 2];

    while (i <= j) {

        // Procura na esquerda um numero maior ou igual ao pivo
        while (vetor[i] < pivo) {

            i = i + 1;

        }

        // Procura na direita um numero menor ou igual ao pivo
        while (vetor[j] > pivo) {

            j = j - 1;

        }

        // Troca os dois numeros de lugar
        if (i <= j) {

            auxiliar = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = auxiliar;

            i = i + 1;
            j = j - 1;

        }

    }

    // Repete o processo para a parte da esquerda e da direita
    if (esquerda < j) {

        quick_sort(vetor, esquerda, j);

    }

    if (i < direita) {

        quick_sort(vetor, i, direita);

    }

}

// Escolhe qual ordenacao usar de acordo com o tipo escolhido
void ordenar(int vetor[], int quantidade, int tipo_ordenacao) {

    if (tipo_ordenacao == 1) {

        bubble_sort(vetor, quantidade);

    }

    if (tipo_ordenacao == 2) {

        insertion_sort(vetor, quantidade);

    }

    if (tipo_ordenacao == 3) {

        selection_sort(vetor, quantidade);

    }

    if (tipo_ordenacao == 4) {

        merge_sort(vetor, 0, quantidade - 1);

    }

    if (tipo_ordenacao == 5) {

        quick_sort(vetor, 0, quantidade - 1);

    }

}

// Grava os numeros em um arquivo de texto, um numero por linha
void gravar_arquivo(char nome_arquivo[], int vetor[], int quantidade) {
    int i;

    // W = Write
    FILE *arquivo = fopen(nome_arquivo, "w");

    if (arquivo == NULL) {

        printf("Erro ao criar o arquivo %s!\n", nome_arquivo);
        return;

    }

    for (i = 0; i < quantidade; i++) {

        fprintf(arquivo, "%d\n", vetor[i]);

    }

    fclose(arquivo);

}

// Le os numeros do arquivo dados.txt e devolve quantos numeros foram lidos
int ler_arquivo(int vetor[]) {
    int quantidade;

    quantidade = 0;

    // R = Read
    FILE *arquivo = fopen("dados.txt", "r");

    if (arquivo == NULL) {

        printf("Erro ao abrir o arquivo dados.txt!\n");
        return 0;

    }

    // Le um numero de cada vez ate o arquivo acabar
    while (quantidade < 100 && fscanf(arquivo, "%d", &vetor[quantidade]) == 1) {

        quantidade = quantidade + 1;

    }

    fclose(arquivo);

    return quantidade;
}

// Chamando procedimento principal
int main() {
    int numeros[100];
    int quantidade, i, tipo_ordenacao, quer_alterar, posicao, novo_valor;

    // Solicita a quantidade de numeros:
    do {

        printf("Quantidade de numeros a serem ordenados (de 2 ate 100): ");
        scanf("%d", &quantidade);

        if (quantidade < 2 || quantidade > 100) {

            printf("Quantidade invalida!\n");
            printf("Tente novamente\n");

        }

    }   while (quantidade < 2 || quantidade > 100);

    // Leitura dos numeros:
    printf("\nDigite os %d numeros:\n", quantidade);

    for (i = 0; i < quantidade; i++) {

        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);

    }

    // Gravacao no primeiro arquivo de texto - "dados.txt":
    gravar_arquivo("dados.txt", numeros, quantidade);
    printf("\nArquivo 'dados.txt' criado com sucesso!\n");

    // Leitura dos numeros que estao dentro do arquivo "dados.txt":
    quantidade = ler_arquivo(numeros);

    if (quantidade == 0) {

        printf("Nao foi possivel ler os numeros. O programa sera encerrado.\n");
        return 1;

    }

    printf("Foram lidos %d numeros do arquivo 'dados.txt'\n", quantidade);

    // Escolha do tipo de ordenacao:
    do {

        printf("\nEscolha o tipo de ordenacao:\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Insertion Sort\n");
        printf("3 - Selection Sort\n");
        printf("4 - Merge Sort\n");
        printf("5 - Quick Sort\n");
        printf("Opcao: ");
        scanf("%d", &tipo_ordenacao);

        if (tipo_ordenacao < 1 || tipo_ordenacao > 5) {

            printf("Opcao invalida!\n");
            printf("Tente novamente\n");

        }

    }   while (tipo_ordenacao < 1 || tipo_ordenacao > 5);

    // Chamando a funcao do ordenador
    ordenar(numeros, quantidade, tipo_ordenacao);

    // Gravacao no segundo arquivo de texto - "ordenado.txt":
    gravar_arquivo("ordenado.txt", numeros, quantidade);
    printf("\nArquivo 'ordenado.txt' criado com sucesso!\n");

    // Pergunta se o usuario quer alterar algum valor:
    do {

        printf("\nDeseja alterar um valor do arquivo 'dados.txt'? (1 - Sim / 2 - Nao): ");
        scanf("%d", &quer_alterar);

        if (quer_alterar != 1 && quer_alterar != 2) {

            printf("Opcao invalida!\n");
            printf("Tente novamente\n");

        }

    }   while (quer_alterar != 1 && quer_alterar != 2);

    if (quer_alterar == 1) {

        // Le o arquivo "dados.txt" de novo, pois ele ainda esta desordenado
        quantidade = ler_arquivo(numeros);

        printf("\nValores atuais do arquivo 'dados.txt':\n");

        for (i = 0; i < quantidade; i++) {

            printf("Posicao %d: %d\n", i + 1, numeros[i]);

        }

        // Pede a posicao que sera alterada:
        do {

            printf("\nQual posicao voce deseja alterar? (de 1 ate %d): ", quantidade);
            scanf("%d", &posicao);

            if (posicao < 1 || posicao > quantidade) {

                printf("Posicao invalida!\n");
                printf("Tente novamente\n");

            }

        }   while (posicao < 1 || posicao > quantidade);

        printf("Digite o novo valor: ");
        scanf("%d", &novo_valor);

        // O vetor comeca na posicao 0, por isso usamos posicao - 1
        numeros[posicao - 1] = novo_valor;

        // Grava o valor novo no arquivo "dados.txt"
        gravar_arquivo("dados.txt", numeros, quantidade);
        printf("\nArquivo 'dados.txt' atualizado com sucesso!\n");

        // Ordena de novo, com o mesmo tipo escolhido antes
        ordenar(numeros, quantidade, tipo_ordenacao);

        // Grava o resultado no arquivo "ordenado.txt"
        gravar_arquivo("ordenado.txt", numeros, quantidade);
        printf("Arquivo 'ordenado.txt' atualizado com sucesso!\n");

    }

    printf("\nAte logo\n");

    return 0;
}
