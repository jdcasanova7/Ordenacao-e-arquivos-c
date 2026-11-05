# Ordenação e Arquivos em C

Programa em C que grava números em um arquivo de texto, lê esse arquivo, ordena os valores com o algoritmo escolhido pelo usuário e salva o resultado em outro arquivo.

Projeto feito como atividade da disciplina de programação (Atividade 03 - Ordenação e Arquivos), no primeiro semestre de Ciência da Computação.

## O que o programa faz

1. Pede a quantidade de números (de 2 até 100) e os próprios números.
2. Grava os números, na ordem em que foram digitados, no arquivo `dados.txt`.
3. Lê os números de volta a partir do arquivo `dados.txt`.
4. Pergunta qual algoritmo de ordenação usar:
   - Bubble Sort
   - Insertion Sort
   - Selection Sort
   - Merge Sort
   - Quick Sort
5. Grava os números ordenados no arquivo `ordenado.txt`.
6. Pergunta se o usuário quer alterar algum valor do arquivo `dados.txt`. Se sim, o programa atualiza o valor, ordena de novo com o mesmo algoritmo e atualiza o `ordenado.txt`.

## Estrutura do repositório

```
.
├── dados.c      código-fonte do programa
└── README.md    este arquivo
```

Os arquivos `dados.txt` e `ordenado.txt` são criados pelo próprio programa quando ele é executado.

## Como compilar e executar

### Pelo terminal (GCC)

```
gcc dados.c -o dados
./dados
```

No Windows, o executável é gerado como `dados.exe` e roda com `dados.exe`.

### Pelo Visual Studio

1. Crie um projeto do tipo Console App.
2. Remova o arquivo `Source.cpp` criado automaticamente.
3. Adicione o `dados.c` em Source Files, com Add > Existing Item.
4. Se aparecer aviso sobre `fopen`, coloque `#define _CRT_SECURE_NO_WARNINGS` na primeira linha do `dados.c`.
5. Execute com Ctrl + F5.

Os arquivos `dados.txt` e `ordenado.txt` ficam na mesma pasta do executável (normalmente a pasta `Debug`).

## Exemplo de uso

Entrada: 6 números (`5`, `3`, `9`, `1`, `7`, `2`) e Bubble Sort (opção 1).

Conteúdo do `dados.txt`:

```
5
3
9
1
7
2
```

Conteúdo do `ordenado.txt`:

```
1
2
3
5
7
9
```

Alterando a posição 1 para o valor 99 e usando Merge Sort, o `dados.txt` fica com `99 3 9 1 7 2` e o `ordenado.txt` fica com `1 2 3 7 9 99`.

## O que eu pratiquei neste projeto

- Leitura e escrita de arquivos de texto (`fopen`, `fscanf`, `fprintf`, `fclose`).
- Cinco algoritmos de ordenação, incluindo dois recursivos (Merge Sort e Quick Sort).
- Funções com vetores como parâmetro.
- Validação de entrada com `do { ... } while (...)`.

## Limitações

- O vetor aceita no máximo 100 números.
- Se o usuário digitar uma letra onde o programa espera um número, a validação não trata o erro.
