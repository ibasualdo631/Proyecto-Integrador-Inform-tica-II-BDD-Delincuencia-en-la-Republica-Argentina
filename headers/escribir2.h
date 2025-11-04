#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "carga.h"

void limpiar_Archivo(char *nombreArchivo);
void escribir_datos_en_archivo_provincia(nodo *delitos);
void separar_por_anio(nodo *delitos);
void exportar_datos_csv_hechos_provincia(nodo *delitos);
void exportar_datos_csv_cantidad_hombres_mujeres(nodo *delitos);
void exportar_datos_csv_cantidad_delitos_anio(nodo *delitos);



