### compilar
```sh
make # genera el ejecutable
```
### eliminar el ejecutable
```sh
make clean # elimina el ejecutable
```
### ejecutar
```sh
./ejemplo_semaforos # correr el programa
```
# Ejemplo de Semáforos en C

Este es un programa simple en C que demuestra el uso de semáforos en hilos para imprimir secuencias de caracteres en la pantalla.

## Descripción

El objetivo del programa es imprimir en la pantalla la secuencia "ABBCABBCABBC...ABBC" de forma infinita utilizando hilos y semáforos. Cada hilo imprime un carácter específico en la secuencia.

El programa utiliza tres hilos (`a`, `b`, `c`) y cuatro semáforos (`sem_a`, `sem_b`, `sem_c`, `sem_x`) para sincronizar la impresión de los caracteres en la pantalla.

## Compilación

Para compilar el programa, utiliza un compilador de C compatible (como `gcc`) y asegúrate de incluir la opción `-pthread` para habilitar el soporte de hilos de pthread:

