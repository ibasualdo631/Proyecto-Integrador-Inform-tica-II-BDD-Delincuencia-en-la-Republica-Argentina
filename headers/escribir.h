#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "carga.h"


void escribir_encabezado(FILE *archivo, const char *tipo, int anios, char *str);
void escribir_archivo(nodo *aux, FILE *abrir);
void separar_anio_delito(nodo *delitos);

