# Capítulo 03: Recursão
_Inicio: 30/01/2024, Fim: 31/01/2014_

## Recursão
> _"Os loops podem melhorar o desempenho do seu programa. A recursão melhora o desempenho do seu programador. Escolha o que for mais importante para a sua situação."_ - Leigh Caldwell (Stack overflow)

### Pseudocódigos
#### Abordagem simples
- Monte uma pilha com as caixas que serão analisadas
- Pegue uma caixa e olhe o que tem dentro dela
- Se você encontrar outra caixa detro dela, adicione-a a um novo monte para ser verificada mais tarde
- Se você encontrar uma chave, terminou
- Repita

```
def procure_pela_chave(caixa_principal):
    # monta uma pilha com as caixas que serão analisadas
    pilha = main_box.crie_uma_pilha_para_busca()

    # enquanto houver caixas na pilha
    while pilha is not vazia:
        # pegue uma caixa
        caixa = pilha.pegue_caixa()

        for item in caixa:
            # se encontrar outra caixa
            if item.e_uma_caixa():
                # adiciona item a pilha de caixas a serem analisadas
                pilha.append(item)

            # se encontrar uma chave
            if item.e_uma_chave():
                // terminou
                print "achei a chave!"
```

#### Abordagem recursiva
- Olhe o que tem dentro da caixa
- Se encontrar outra caixa, volte para o passo acima
- Se encontrar outra chave, terminou

```
def procure_pela_chave(caixa):
    # Olhe o que tem dentro da caixa
    for item in caixa:

        # Se encontrar outra caixa
        if item.e_uma_caixa():
            # repita todo o processo
            procure_pela_chave(item)

        # Se encontrar outra chave
        if item.e_uma_chave():
            # terminou
            print "achei a chave!"
```



### Caso-base e caso recursivo
Toda função recursiva tem duas partes: o `caso-base` e o `caso recursivo`. O **caso-base** é quando a função não chama a si mesma novamente, de forma que o programa não se torna um loop infinito. O **caso recursivo** é quando a função chama a si mesma.

```
void regressive(int i) {
    printf("%d\n", i);

    // base-case
    if (i <= 1) {
        return;
    }

    // recursive case
    regressive(i-1);
}
```

## A pilha (stack)
- Call Stack

É uma estrutura de dados, onde se utiliza o conceito `L.I.F.O` _(Last In, Firt Out)_, onde existe uma lista de objetos, onde um objeto se sobrepõe ao outro. É possível manipular essa lista apenas utilizando duas funções: `push` para inserir um ítem no topo dessa lista, e `pop` para remover o item do topo da lista.

### Pilha de chamada
Um computador, implementa internamente a estrutuda da pilha para fazer o **pilha de chamada**, ou do inglês `call-stack`. Ele utiliza essa estrutura para administrar a execução das funções. 

Quando uma função é executada, os parâmetros referentes a execução da função são armazenados na memória como um elemento da pilha. Quando uma função chama uma outra função, é adicionado um elemento na pilha, contendo os valores referentes a execução dessa nova função. 

Quando essa nova função terminar de executar, esse elemento é removido da pilha, e com isso o computador tem acesso aos valores que estavam sendo utilizados pela função anterior. Após a execução da função inicial, ela é removida da pilha e com isso todos os dados referentes a ela podem ser removidos da memória.

### Pilha da chamada com recursão
As funções recursivas também utilizam a pilha de chamada! A função `fatorial(5)` por exemplo. Sabemos que `5!` = __5 * 4 * 3 * 2 * 1__. Podemos representar o **5!** como `5 * 4!`. **4!** podemos representar por `4 * 3!` e assim até chegarmos em `1!`, que sabemos que é `1`. Logo, se `i` for igual a `1`, chegamos no nosso caso base e retornamos o valor de 1;

#### Pseudocódigo
```
int factorial(int i)
{
    // base-case
    if (i == 1) {
        return 1;
    }

    // recursive case
    return i * factorial(i-1);
}
```

#### Desvantagens
Como vimos anterior, toda vez que chamamos uma função, o computador aloca espaço na memória para os dados atuais da nossa função, e os adiciona em uma pilha. Conforme adicionamos itens nessa pilha com chamadas recursivas mais e mais memória do computador vai sendo alocado para os dados necessário para as funções. 

Com isso, podemos causar um problema chamado `stack overflow`, onde estamos usando mais espaço de memória do que o sistema operacional destinou para nosso uso. Duas soluções para caso isso aconteça, são:
- Reescrever o código utilizando loops
- Utilizar o conceito de `tail recursion` _(recursão de cauda)_. É considerado uma função `tail recursive`, uma função que chama a sí própria e essa chamada recursiva é a última ação da função.