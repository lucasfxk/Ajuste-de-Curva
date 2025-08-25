# Trabalho de Ajuste de Curvas

## Introdução

Este documento detalha o segundo trabalho da disciplina de Algoritmos Numéricos focado no ajuste de curvas, especificamente para a determinação da idade de amostras utilizando o decaimento do Carbono-14. O objetivo principal é implementar um método de ajuste de curva que, a partir de dados de referência, calcule os coeficientes de uma função exponencial e, em seguida, utilize esses coeficientes para estimar a idade de uma nova amostra com base em sua quantidade de Carbono-14.

## Contexto do Trabalho

O trabalho baseia-se no princípio da datação por Carbono-14, um isótopo radioativo natural. A quantidade de Carbono-14 em um organismo vivo permanece constante, mas após a morte, essa quantidade diminui devido ao decaimento radioativo. A relação entre a idade de uma amostra (t) e a quantidade de Carbono-14 (N) é dada pela equação exponencial:

`N = β₀ * e^(β₁t)`

Onde:
- `N` é a quantidade de Carbono-14 na amostra.
- `t` é a idade da amostra em anos.
- `β₀` e `β₁` são os coeficientes a serem determinados.

Para linearizar essa equação e aplicar métodos de regressão linear, aplica-se o logaritmo natural em ambos os lados:

`ln(N) = ln(β₀) + β₁t`

Fazendo `Y = ln(N)`, `A = ln(β₀)` e `B = β₁`, a equação se torna uma forma linear:

`Y = A + Bt`

Este trabalho utiliza um conjunto de dados de referência (idade vs quantidade de Carbono-14) para determinar os coeficientes `A` e `B` (e consequentemente `β₀` e `β₁`) através de um sistema de equações lineares resolvido pelo método de Eliminação de Gauss.

## Estrutura do trabalho

O trabalho é composto pelos seguintes arquivos:

- `EliminacaoGauss.c`: implementação do algoritmo de Eliminação de Gauss.
- `EliminacaoGauss.h`: cabeçalho com a declaração da função de Eliminação de Gauss.
- `main.c`: programa principal que realiza o ajuste de curva e a estimativa da idade.
- `makefile`: script para a compilação do projeto.
- `carbono14.txt`: arquivo de dados de referência contendo a idade e a quantidade de Carbono-14.

### Descrição dos arquivos

#### `EliminacaoGauss.c`

Este arquivo contém a implementação da função `resolverEliminacaoGauss`, responsável por resolver um sistema de equações lineares utilizando o método de Eliminação de Gauss com pivoteamento parcial. Esta função é crucial para determinar os coeficientes `A` e `B` do modelo linearizado, que são essenciais para o ajuste de curva.

#### `EliminacaoGauss.h`

Este é o arquivo de cabeçalho para `EliminacaoGauss.c`. Ele declara a assinatura da função `resolverEliminacaoGauss`, permitindo que outros arquivos (como `main.c`) a utilizem.

#### `mainc.c`

O arquivo `main.c` é o coração do programa. Ele realiza as seguintes etapas: 

1. **Leitura dos dados**: lê os dados de idade e quantidade de Carbono-14 do arquivo `carbono14.txt`.
2. **Linearização**: transforma os dados de `N` para `ln(N)` para adequá-los ao modelo linear.
3. **Construção da matriz do sistema linear**: monta a matriz `X` e o vetor `Y` do sistema de equações lineares `X * coeficientes = Y`, onde `coeficientes` são `A` e `B`.
4. **Resolução do sistema**: chama a função `resolverEliminacaoGauss` para encontrar os valores de `A` e `B`.
5. **Cálculo da idade estimada**: utiliza os coeficientes `A` e `B` (e, por extensão, `β₀` e `β₁`) para estimar a idade de uma amostra com uma quantidade de Carbono-14 específica (definida como `QTD_CARB_N` no código).

#### `makefile`

O `makefile` é um script de automação de compilação. Ele define as regras para compilar os arquivos `.c` em objetos `.o` e, em seguida, linkar esses objetos para criar o executável final do programa. Simplifica o processo de compilação, garantindo que todas as dependências sejam tratadas corretamente.

#### `carbono14.txt`

Este arquivo de texto contém os dados de referência utilizados para o ajuste de curva. Cada linha do arquivo contém dois valores: a idade da amostra e a quantidade de Carbono-14 correspondente. Esses dados são lidos pelo `main.c` para construir o sistema linear.

## Como executar o trabalho

Para compilar e executar este trabalho em seu ambiente, siga os passos abaixo:

### 1. Pré-requisitos

Certifique-se de ter um compilador de linguagem de programação C (como GCC) instalado em seu sistema. Abaixo estão algumas instruções para os sistemas operacionais mais comuns:

*   **Windows**:
    *   Recomenda-se a instalação do [MinGW-w64](https://sourceforge.net/projects/mingw-w64/) ou [Cygwin](https://www.cygwin.com/). Ambos fornecem um ambiente de desenvolvimento GNU (incluindo GCC e Make) no Windows.
    *   Durante a instalação, certifique-se de selecionar os pacotes `gcc` e `make`.
    *   Adicione o diretório `bin` do MinGW/Cygwin ao seu PATH do sistema.

*   **Linux (Ubuntu/Debian)**:
    *   Abra um terminal e execute:
        ```bash
        sudo apt update
        sudo apt install build-essential manpages-dev
        ```
    *   O pacote `build-essential` inclui `gcc`, `g++` e `make`.

 *   **macOS**:
    *   Instale as ferramentas de linha de comando do Xcode. Abra um terminal e execute:
        ```bash
        xcode-select --install
        ```
    *   Isso instalará o GCC e o Make, entre outras ferramentas de desenvolvimento.

### 2. Download e extração

1. Baixe o arquivo `Ajuste-de-Curva-main.zip`.
2. Extraia o conteúdo do arquivo ZIP para um diretório de sua escolha. Você terá uma pasta chamada `Ajuste-de-Curva-main` contendo todos os arquivos do trabalho.

### 3. Navegar até o diretório do trabalho

Abra um terminal (ou `Git Bash`/`PowerShell` no Windows, `Terminal` no Linux/macOS) e navegue até o diretório onde você extraiu os arquivos. Por exemplo:

```bash
cd /caminho/para/Ajuste-de-Curva-main/Ajuste-de-Curva-main
```

### 4. Compilar o trabalho

No terminal, dentro do diretório do trabalho, execute o comando `make` (Linux):

```bash
make
```

No Windows, dentro do diretório do trabalho, executa o comando `mingw32-make.exe`

```bash
mingw32-make.exe
```

Estes comandos utilizará o `makefile` para compilar os arquivos `.c` e criar o executável. Se a compilação for bem-sucedida, um arquivo executável chamado `prog` será gerado no mesmo diretório.

### 4. Executar o programa

Após a compilação, você pode executar o programa passando o arquivo `carbono14.txt` como argumento:

```bash
./prog carbono14.txt
```

*   **No Windows**, dependendo do seu ambiente (MinGW/Cygwin), você pode precisar executar com `prog.exe carbono14.txt` ou `./prog.exe carbono14.txt`.

O programa irá processar os dados, calcular os coeficientes e exibir a idade estimada da amostra de Carbono-14 especificada no código.

**Observação**: O valor da quantidade de Carbono-14 para a qual a idade é estimada (`QTD_CARB_N`) está definido diretamente no arquivo `main.c`. Se você precisar estimar a idade para uma quantidade diferente, será necessário editar o arquivo `main.c` e recompilar o trabalho.
