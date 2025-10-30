#pragma once
#include <stdio.h>
#include <stdlib.h>

// Estructura principal
typedef struct nodo {
    int provincia_id;
    char provincia_nombre[25];
    int anio;
    int codigo_delito;
    char delito_nombre[45];
    int cantidad_hechos; 
    int cantidad_victimas;
    int cantidad_masculinos;
    int cantidad_femeninos;
    int cantidad_si;
    struct nodo *sig;
} nodo;

// Prototipos de funciones del módulo carga
void cargar_informacion(nodo **delitos);
void liberartodamemoria(nodo **delitos);
