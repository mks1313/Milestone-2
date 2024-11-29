#include <stdio.h>
#include <unistd.h>

int main() {
    int id = fork();  // Crear un nuevo proceso y guardar el valor retornado en 'id'
    
    if (id == 0) {
        // Este bloque se ejecuta solo en el proceso hijo
        printf("Soy el proceso hijo, id = %d\n", id);
    } else if (id > 0) {
        // Este bloque se ejecuta solo en el proceso padre
        printf("Soy el proceso padre, id = %d (PID del hijo)\n", id);
    } else {
        // Si fork() falla, id será < 0
        printf("Error al crear el proceso hijo\n");
    }
    
    return 0;
}

