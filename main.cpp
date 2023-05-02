#include <stdio.h>


typedef struct {
    char *nombre;
    int edad;
} Persona;

int setNombre(Persona *persona, char *nombre){
    persona->nombre = nombre;
    return 0;
}

int setEdad(Persona *persona, int edad){
    persona->edad = edad;
    return 0;
}

int toString(Persona *persona){
    printf("%s %d anios",persona->nombre,persona->edad);
    return 0;
}

typedef struct {
    Persona *personas[2];
    int contador;
} Registro;

Registro crearRegistro(){
    Registro reg;
    reg.contador = 0;
    return reg;
}

int agregarPersona(Registro *reg,Persona *persona){
   reg->personas[reg->contador] = persona;
   reg->contador++;
   return 0;
}

int main(){
    Persona p1;
    setNombre(&p1, "Juan");
    setEdad(&p1, 26);
    Persona p2;
    setNombre(&p2, "Luis");
    setEdad(&p2, 29);
    Registro registro = crearRegistro();
    agregarPersona(&registro,&p1);
    agregarPersona(&registro,&p2);
    for (int i = 0; i < registro.contador; i++){
        printf("%d. ",i+1);
        toString(registro.personas[i]);
        printf("\n");
    }

    return 0;
}
