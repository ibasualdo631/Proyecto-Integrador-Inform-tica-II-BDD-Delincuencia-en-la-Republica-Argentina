#include <stdlib.h>
#include <string.h>
#include "../include/escribir.h"
#include "../include/escribir2.h"
#include "../include/carga.h"

typedef struct 
{
    char provincia_nombre[24]; 
    int total_hechos; // total x provincia (funcion 1)
    int total_hechos_2018; // (funcion 5)
    int total_hechos_2020; // (funcion 5)
    int total_hechos_2023; // (funcion 5)
} Acumulador_Provincia; // defino estructura que mee va a servir como acumulador de delitos para cada provincia x individual

void exportar_datos_csv_hechos_provincia(nodo *delitos);
void exportar_datos_csv_cantidad_hombres_mujeres(nodo *delitos);
void exportar_datos_csv_cantidad_delitos_anio(nodo *delitos);
void exportar_datos_csv_cantidad_delitos_especifico(nodo *delitos);
void exportar_datos_csv_hechos_provincia_x_anio(nodo *delitos);
void menu_poblaciones();