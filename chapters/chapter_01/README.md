# Introdução

## Logarítimos
> "A que número `x` eu elevo `b` para chegar em `n`"

Logarítimos são o oposto de expoênciais. Leia-se: `log de x na base 2 é igual a n`. 
No expoêncial, leia-se: `b elevado a x é igual a n`.

_Obs: Na matemática, a base padrão é 2, então as vezes não é especificado a base na equaçaõ. Quando isso acontecer, entende-se que a base é 2._

|     logaritma     |  expoencial   |
| ----------------- | ------------- |
| `log b x = n`     | `bx = n`      |
| n = logaritmando  | n = potência  |
| b = base          | b = base      |
| x = logaritmo     | x = expoente  |

Para calcular o logarítmo, deve-se elevar a base por x. Logo: `log de 8 na base 2` pode ser representado por `2 elevado a 3`, pois `2 * 2 * 2 = 8`. Logo, a resposta para `log de 8 na base 2` é: `3`!

### Exemplos
- `log 81 na base 3`
    - 3 elevado a x = 81
    - fatorar o 81
        - 81 / 3 = 27
        - 27 / 3 = 9
        - 9 / 3 = 3
        - 3 / 3 = 1
    - 3 elevado a x é igual a 3 elevado a 4
    - `log de 81 na base 3 = 4`

- `log 32 na base 2`
    - 2 elevado a x = 32
    - multiplicar 2 por x vezes
        - 2 * 2 = 4
        - 4 * 2 = 8
        - 8 * 2 = 16
        - 16 * 2 = 32
        - 32 * 2 = 64
    - 2 elevado a x é igual a 2 elevado a 6
    - `log na base 2 de 32 = 6`

- `log de 1 na base 100`
    - 100 elevado a x = 1
    - qualquer número elevado a 0 é igual a 1
        - 100 elevaco a x = 1
        - x = 0
    - `log de 100 na base (1) = 0`

### Mais informações
- [Khan Academy](https://pt.khanacademy.org/math/algebra2/x2ec2f6f830c9fb89:logs/x2ec2f6f830c9fb89:log-intro/v/logarithms)

## Busca binária
Utiliza do principio de `dividir para conquistar`. É utilizada para fazer uma busca em uma `lista ordenada`, onde se divide a lista no meio e verifica se o elemento selecionado é o desejado. Se não for, verifica se o elemento selecionado é maior que o elemento desejado. Se for, ele "descarta" a metada menor que o elemento selecionado e refaz a busca partindo do elemento selecionado em diante. Caso for menor, descarta a metade a direita do numero selecionado e refaz a busca com a metade menor.

### Pseudocode
```
low = 0
high = length(list) - 1;

while (baixo <= alto) {
    mid = (baixo + alto) / 2;
    pick = list[mid];
    if (pick == item)
        return mid
    if (pick > item)
        high = mid - 1
    else 
        low = mid + 1;
}
return none;
```

### Exercícios
- Suponha que você tenha uma lista com 128 nomes e esteja fazendo uma pesquisa binária. Qual seria o número máximo de etapas que você levaria para encontrar o nome desejado?
    - 128 / 2
    - 64 / 2
    - 32 / 2
    - 16 / 2
    - 8 / 2
    - 4 / 2
    - 2 / 2
    - 1
    - `7 etapas`

- Suponha que você duplique o tamanho da lista. Qual seria o número máximo de etapas agora?
    - 256 / 2
    - 128 / 2
    - 64 / 2
    - 32 / 2
    - 16 / 2
    - 8 / 2
    - 4 / 2
    - 2 / 2
    - 1
    - `8 etapas`

## Tempo de execução
Comparamos a efeciência do algorítmo medindo o tempo máximo que ele demora para executar uma determinada tarefa.

Um algoritmo de busca por exemplo, se for implementado uma busca linear, o tempo máximo de execução seria proporcional a quantidade de dados nos quais desejamos buscar. 
Por exemplo, uma lista com 4 bilhões de números, com uma busca simples, precisaríamos de 4 bilhões de tentativas no pior dos casos. Isso é chamado de `tempo linear`.

Uma pesquisa binária, como descartamos uma metada da lista caso seja maior ou menor do que o ítem buscado, fazemos no máximo 32 comparações no pior dos casos. Por que 32? Por que `log de 4bilhões na base 2 = 32`. Logo, o algorítmo de busca binária é considerado um algorítmo de `tempo logarítmo`.

## Big O Notation
Notação utilizada para medir o tempo máximo de execução de um algorítmo. 

### Tempo de execução dos algoritmos cresce a taxas diferentes