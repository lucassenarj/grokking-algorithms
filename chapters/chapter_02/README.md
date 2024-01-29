# Capítulo 02: Ordenação por seleção
_Inicio: 27/01/2024, Fim: 29/01/2014_

## Como funciona a memória
> O computador parece com um grande conjunto de gavetas, e cada gaveta tem seu endereço.

Cada vez que quer armazenar um item na memória, você pede ao computador um pouco de espaço e ele te dá um endereço no qual você pode armazenar o seu ítem.

## Arrays e listas encadeadas
### Array
Array armazena um conjunto de dados do mesmo tipo, contiguamente (um do lado do outro) na memória. Seu tamanho é definido na inicialização do mesmo. Logo, se a lista estiver com todos os seus indexes ocupados, não é possível armazenar nenhum outro dado na lista. Uma solução para esse problema, seria solicitar ao computador um novo espaço na memória, de maior tamanho, e copiar todos os dados já existenta na lista para a nova lista, e no fim, adicionar o elemento desejado no indice disponível. Caso um tenha a necessidade de adicionar mais um ítem, será necessário repetir o processo de solicitação de novo espaço, copiar os itens da lista para a nova, e somente então adicionar o elemento.

### Lista encadeada
Diferente do array, uma lista encadeada não tem tamanho definido. Com isso, não precisa reservar um espaço grande logo de inicio na memória para os elementos. Na lista encadeada, cada elemento contém uma referência para o endereço de memória de se encontra o próximo elemento da lista.

### Array vs lista encadeadas
Num array, sabemos exatamente onde esta cada item na lista, com isso, podemos acessa-lo de maneira rápida e direta. Já a lista encadeada, só sabemos onde esta o primeiro ítem da lista. Com isso, para navegar até o último item, precisamos percorrer toda a lista para então descobrir qual o último ítem.

### Terminologia
Posição do elemento em um array é chamado de **índice**.

### Inserindo algo no meio da lista
Para adicionar um elemento no meio de uma lista, basta alterar o endereço para qual o elemento anterior esta apontando.

### Deleções
Para remover um elemento na lista, basta fazer o elemento anterior apontar para o elemento seguinte ao qual você deseja remover. 

### Tempo de execução:
|           | Array | Listas |
| --------- | ----- | ------ |
| Leitura   | O(1)  | O(n)   |
| Inserção  | O(n)  | O(1)   |
| Remoção   | O(n)  | O(1)   |

- _O(N) = tempo de execução linear_
- _O(1) = tempo de execução constante_

### Obs:
Para a lista ter o tempo de insersão e remoção `O(1)` (constante), é necessário acessar instantaneamente o elemento a ser realizada a operação. É uma prática comum acompanhar o primeiro e o último item de uma lista encadeada para que o tempo de execução para deleta-los seja **O(1)**.

## Ordenação por seleção
O algoritmo de ordenação por seleção, também conhecido em inglês como `Selection Sort`, consiste em pegar o ítem de maior valor de uma lista não ordenada e coloca-lo na primeira posição de uma na lista. Depois, repetir o processo com o ítem restante de maior valor na lista inicial.

Para encontrar o elemento de maior valor da lista, precisamos percorrer toda a lista. Isso tem tempo de execução `O(n)`. Então você tem uma operação com tempo de execução `O(n)` e precisa repetir essa operação `n` vezes. Sua notação BigO é: `O(n x n)` ou `O(n²)` _(n ao quadrado)_.

### Exemplo de código.
- Buscar menor elemento em um array:
    - [get_smallest](./examples/get_smallest.c)
- Usando a função para escrever a ordenação por seleção:
    - [seletion_sort](./examples/selection_sort.c)