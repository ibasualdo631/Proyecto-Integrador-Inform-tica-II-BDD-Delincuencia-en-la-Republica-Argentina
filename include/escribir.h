#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "carga.h"

void limpiarArchivo(char *nombreArchivo);
void escribir_encabezado(FILE *archivo, const char *tipo, int anios, char *str);
void escribirarchivo(nodo *aux, FILE *abrir);
void escribirdatosenarchivoprovincia(nodo *delitos);
void separarporanio(nodo *delitos);
void separaraniodelito(nodo *delitos);

    
