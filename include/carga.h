#pragma once
#include <stdio.h>
#include <stdlib.h>

// Estructura principal
typedef struct nodo 
{
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

 struct acumulador
    {
        int cant;
        int masc;
        int fem;
        int sindef;
    };


// Prototipos de funciones del módulo carga

void cargar_informacion(nodo **delitos);
void liberar_toda_memoria(nodo **delitos);
void acumulador_delitos_mostrar(nodo *delitos);
void acumulador_delitos_principales_mostrar(nodo *delitos);
