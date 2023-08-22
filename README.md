# AED1_EP2
Segundo trabalho prático da disciplina de Algoritmos e Estruturas de Dados I

O objetivo do trabalho é implementar de forma correta e completa a função CopiaCompleta, que cria uma
cópia de uma ABB fornecida como entrada de modo que ela passe a ter a altura mínima possível para
aquela quantidade de elementos sem deixar de ser ABB.

A função recebe como entrada uma ABB apontada por *raiz, contendo chaves inteiras, e deve retornar o
ponteiro para uma nova ABB que seja cópia dela com altura mínima, sem modificar a árvore original.
A posição exata de cada elemento na árvore de resposta não é relevante, mas ela deve ser uma árvore ABB.
Ou seja, qualquer ABB de altura mínima que contenha exatamente as mesmas chaves de entrada é uma
resposta válida.

Note que a árvore fornecida não (necessariamente) é uma AVL, e que portanto o uso de rotações AVL não é
garantia de que a árvore possa ser transformada em uma árvore completa (que de resto não é o objetivo da
rotação AVL mesmo).

A função main() serve apenas para testes particulares.
