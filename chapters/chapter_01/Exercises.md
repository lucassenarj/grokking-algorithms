# Exercícios

## Tempo execução:
Forneça o tempo de execução para cada um dos casos a seguir em termos de notação Big O.

### Você tem um nome e deseja encontrar o número de telefone para esse nome em uma agenda telefônica
<details>
<summary>Resposta</summary>
Big O = O(log n)
</details>

### Você tem um número de telefone e deseja encontrar o dono dele em uma agenda telefônica.
> Dica: Deve procurar pela agenda inteira!

<details>
<summary>Resposta</summary>
Big O = O(n)
</details>

### Você quer ler o número de cada pessoa da agenda telefônica.
<details>
<summary>Resposta</summary>
Big O = O(n)
</details>

### Você quer ler os números apenas dos nomes que começam com A
<details>
<summary>Resposta</summary>
Big O = O(n)

Você pode pensar: “Só estou fazendo isso para 1 dentre 26 caracteres, portanto o tempo de execução deve ser O(n/26).” Uma regra simples é a de ignorar números que são somados, subtraídos, multiplicados ou divididos. Nenhum desses são tempos de execução Big O: O(n + 26), O(n - 26), O(n * 26), O(n / 26). Eles são todos o mesmo que O(n)! Por quê? Se você está com dúvidas, vá para “Notação Big O revisada”, no Capítulo 4, e leia a parte sobre constantes na notação Big O (uma constante é apenas um número; 26 era a constante desta questão).
</details>

## Caixeiro Viajante (Traveler Salesman)

