# Push Swap

Este proyecto implementa un algoritmo para ordenar una lista de números utilizando dos pilas (stacks) y un conjunto limitado de operaciones. El objetivo es ordenar los números con la menor cantidad de movimientos posible.

## Descripción

El `push_swap` es un programa que toma una lista de números pasados como parámetros y los ordena usando dos pilas (`stack a` y `stack b`). Solo se permiten ciertos movimientos para manipular los elementos en las pilas, lo que hace que la optimización del algoritmo sea crucial.

### Operaciones Disponibles

El programa soporta las siguientes operaciones:

- `sa` : **swap a** - Intercambia los dos primeros elementos en `stack a`. No hace nada si hay uno o menos elementos.
- `sb` : **swap b** - Intercambia los dos primeros elementos en `stack b`. No hace nada si hay uno o menos elementos.
- `ss` : **swap a** y **swap b** - Intercambia los dos primeros elementos en ambos stacks al mismo tiempo.
- `pa` : **push a** - Toma el primer elemento de `stack b` y lo coloca encima de `stack a`. No hace nada si `stack b` está vacío.
- `pb` : **push b** - Toma el primer elemento de `stack a` y lo coloca encima de `stack b`. No hace nada si `stack a` está vacío.
- `ra` : **rotate a** - Desplaza todos los elementos de `stack a` una posición hacia arriba, de modo que el primer elemento se convierte en el último.
- `rb` : **rotate b** - Desplaza todos los elementos de `stack b` una posición hacia arriba, de modo que el primer elemento se convierte en el último.
- `rr` : **rotate a** y **rotate b** - Realiza un `ra` y `rb` al mismo tiempo.
- `rra` : **reverse rotate a** - Desplaza todos los elementos de `stack a` una posición hacia abajo, de modo que el último elemento se convierte en el primero.
- `rrb` : **reverse rotate b** - Desplaza todos los elementos de `stack b` una posición hacia abajo, de modo que el último elemento se convierte en el primero.
- `rrr` : **reverse rotate a** y **reverse rotate b** - Realiza un `rra` y `rrb` al mismo tiempo.

### Estructura de Datos

Las pilas se implementan utilizando listas enlazadas, lo que permite un acceso eficiente a los elementos y facilita la implementación de las operaciones descritas.

## Instalación

Este proyecto incluye un `Makefile` que simplifica la compilación. Asegúrate de tener `make` instalado en tu sistema. Luego, puedes compilar el proyecto con el siguiente comando:
<br>`make`.
Esto generará un ejecutable llamado push_swap.

Para limpiar los archivos objeto generados durante la compilación, puedes usar:
<br>`make clean`<br>
Uso
Una vez compilado, puedes ejecutar el programa push_swap con una lista de números como argumentos:

```
./push_swap 4 67 3 87 23
```
El programa imprimirá una secuencia de operaciones que ordenará la lista de números dada.

Ejemplo
Supongamos que deseas ordenar la lista 4 67 3 87 23:

```
$> ./push_swap 4 67 3 87 23
$> pb
pb
ra
ra
sa
pa
pa
```
Este es un ejemplo de una secuencia de operaciones que ordenará la lista en stack a.
