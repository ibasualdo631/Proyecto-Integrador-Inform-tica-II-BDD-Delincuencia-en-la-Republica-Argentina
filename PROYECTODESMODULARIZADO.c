#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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


// Prototipos de funciones del módulo carga
void cargar_informacion(nodo **delitos);
void liberartodamemoria(nodo **delitos);
void limpiar_Archivo(char *nombreArchivo);
void escribir_encabezado(FILE *archivo, const char *tipo, int anios, char *str);
void escribir_archivo(nodo *aux, FILE *abrir);
void escribirdatosenarchivoprovincia(nodo *delitos);
void separarporanio(nodo *delitos);
void separaraniodelito(nodo *delitos);


int main() 
{
    printf("Iniciando programa...\n");
    int opcion = 0;
    char seguir = 's';
    nodo *delitos = NULL;
    

    setlocale(LC_ALL, "");

    do {
        printf("\n");
        printf("=============================================================================\n");
        printf(" || DELINCUENCIA EN LA REPUBLICA ARGENTINA                                 ||\n");
        printf("=============================================================================\n");
        printf(" || [1] CARGAR BDD                                                         ||\n");
        printf(" || [2] GENERAR Reporte por Provincia                                      ||\n");
        printf(" || [3] GENERAR Reporte de Delitos totales por Anio                        ||\n");
        printf(" || [4] GENERAR Reporte de Delitos totales por Anio y tipo de delito       ||\n");
        printf(" || [0] Salir                                                              ||\n");
        printf("=============================================================================\n");
        printf("   >>> Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) 
        {
            case 1:
                cargar_informacion(&delitos);
                break;
            case 2:
                if (delitos == NULL)
                {
                    printf("NO HAY DATOS EN LA LISTA\n");
                }
                else 
                {
                    limpiar_Archivo("provincias/datos_CABA.txt");
                    limpiar_Archivo("provincias/datos_BSAS.txt");
                    limpiar_Archivo("provincias/datos_CATAMARCA.txt");
                    limpiar_Archivo("provincias/datos_CORDOBA.txt");
                    limpiar_Archivo("provincias/datos_CHACO.txt");
                    limpiar_Archivo("provincias/datos_CORRIENTES.txt");
                    limpiar_Archivo("provincias/datos_CHUBUT.txt");
                    limpiar_Archivo("provincias/datos_ENTRERIOS.txt");
                    limpiar_Archivo("provincias/datos_FORMOSA.txt");
                    limpiar_Archivo("provincias/datos_JUJUY.txt");
                    limpiar_Archivo("provincias/datos_LAPAMPA.txt");
                    limpiar_Archivo("provincias/datos_LARIOJA.txt");
                    limpiar_Archivo("provincias/datos_MENDOZA.txt");
                    limpiar_Archivo("provincias/datos_MISIONES.txt");
                    limpiar_Archivo("provincias/datos_NEUQUEN.txt");
                    limpiar_Archivo("provincias/datos_RIONEGRO.txt");
                    limpiar_Archivo("provincias/datos_SALTA.txt");
                    limpiar_Archivo("provincias/datos_SANJUAN.txt");
                    limpiar_Archivo("provincias/datos_SANLUIS.txt");
                    limpiar_Archivo("provincias/datos_SANTACRUZ.txt");
                    limpiar_Archivo("provincias/datos_SANTAFE.txt");
                    limpiar_Archivo("provincias/datos_SANTIAGODELESTERO.txt");
                    limpiar_Archivo("provincias/datos_TUCUMAN.txt");
                    escribirdatosenarchivoprovincia(delitos);
                }
                break;
            case 3:
                if (delitos == NULL)
                {
                    printf("NO HAY DATOS EN LA LISTA\n");
                }
                else
                {
                    limpiar_Archivo("anos/DELITO2018.txt");
                    limpiar_Archivo("anos/DELITO2020.txt");
                    limpiar_Archivo("anos/DELITO2023.txt");
                    separarporanio(delitos);
                }
                break;
            case 4:
                if (delitos == NULL)
                {
                    printf("NO HAY DATOS EN LA LISTA\n");
                }
                else 
                {
                    limpiar_Archivo("delitos/Abusosexualagravado2018.txt");
                    limpiar_Archivo("delitos/Abusosexualsimple2018.txt");
                    limpiar_Archivo("delitos/Abusosexualconaccesocarnal2018.txt");
                    limpiar_Archivo("delitos/Ciberdelitossexualesvinculadosamenores2018.txt");
                    limpiar_Archivo("delitos/Delitoscontraelhonor2018.txt");
                    limpiar_Archivo("delitos/Homicidiosculpososporotroshechos2018.txt");
                    limpiar_Archivo("delitos/Homicidiosdolosos2018.txt");
                    limpiar_Archivo("delitos/Homicidiosdolososengradodetentativa2018.txt");
                    limpiar_Archivo("delitos/LesionesculposasenAccidentesViales2018.txt");
                    limpiar_Archivo("delitos/Lesionesculposasporotroshechos2018.txt");
                    limpiar_Archivo("delitos/Lesionesdolosas2018.txt");
                    limpiar_Archivo("delitos/Muertesenaccidentesviales2018.txt");
                    limpiar_Archivo("delitos/Otrosdelitoscontralaintegridadsexual2018.txt");
                    limpiar_Archivo("delitos/Otrosdelitoscontralalibertad2018.txt");
                    limpiar_Archivo("delitos/Otrosdelitoscontralaspersonas2018.txt");
                    limpiar_Archivo("delitos/Suicidios(consumados)2018.txt");
                    limpiar_Archivo("delitos/Tentativadeabusosexualconaccesocarnal2018.txt");
                    limpiar_Archivo("delitos/Tratadepersonasagravado2018.txt");
                    limpiar_Archivo("delitos/Tratadepersonassimple2018.txt");
                    limpiar_Archivo("delitos/Abusosexualagravado2020.txt");
                    limpiar_Archivo("delitos/Abusosexualsimple2020.txt");
                    limpiar_Archivo("delitos/Abusosexualconaccesocarnal2020.txt");
                    limpiar_Archivo("delitos/Ciberdelitossexualesvinculadosamenores2020.txt");
                    limpiar_Archivo("delitos/Delitoscontraelhonor2020.txt");
                    limpiar_Archivo("delitos/Homicidiosculpososporotroshechos2020.txt");
                    limpiar_Archivo("delitos/Homicidiosdolosos2020.txt");
                    limpiar_Archivo("delitos/Homicidiosdolososengradodetentativa2020.txt");
                    limpiar_Archivo("delitos/LesionesculposasenAccidentesViales2020.txt");
                    limpiar_Archivo("delitos/Lesionesculposasporotroshechos2020.txt");
                    limpiar_Archivo("delitos/Lesionesdolosas2020.txt");
                    limpiar_Archivo("delitos/Muertesenaccidentesviales2020.txt");
                    limpiar_Archivo("delitos/Otrosdelitoscontralaintegridadsexual2020.txt");
                    limpiar_Archivo("delitos/Otrosdelitoscontralalibertad2020.txt");
                    limpiar_Archivo("delitos/Otrosdelitoscontralaspersonas2020.txt");
                    limpiar_Archivo("delitos/Suicidios(consumados)2020.txt");
                    limpiar_Archivo("delitos/Tentativadeabusosexualconaccesocarnal2020.txt");
                    limpiar_Archivo("delitos/Tratadepersonasagravado2020.txt");
                    limpiar_Archivo("delitos/Tratadepersonassimple2020.txt");
                    limpiar_Archivo("delitos/Abusosexualagravado2023.txt");
                    limpiar_Archivo("delitos/Abusosexualsimple2023.txt");
                    limpiar_Archivo("delitos/Abusosexualconaccesocarnal2023.txt");
                    limpiar_Archivo("delitos/Ciberdelitossexualesvinculadosamenores2023.txt");
                    limpiar_Archivo("delitos/Delitoscontraelhonor2023.txt");
                    limpiar_Archivo("delitos/Homicidiosculpososporotroshechos2023.txt");
                    limpiar_Archivo("delitos/Homicidiosdolosos2023.txt");
                    limpiar_Archivo("delitos/Homicidiosdolososengradodetentativa2023.txt");
                    limpiar_Archivo("delitos/LesionesculposasenAccidentesViales2023.txt");
                    limpiar_Archivo("delitos/Lesionesculposasporotroshechos2023.txt");
                    limpiar_Archivo("delitos/Lesionesdolosas2023.txt");
                    limpiar_Archivo("delitos/Muertesenaccidentesviales2023.txt");
                    limpiar_Archivo("delitos/Otrosdelitoscontralaintegridadsexual2023.txt");
                    limpiar_Archivo("delitos/Otrosdelitoscontralalibertad2023.txt");
                    limpiar_Archivo("delitos/Otrosdelitoscontralaspersonas2023.txt");
                    limpiar_Archivo("delitos/Suicidios(consumados)2023.txt");
                    limpiar_Archivo("delitos/Tentativadeabusosexualconaccesocarnal2023.txt");
                    limpiar_Archivo("delitos/Tratadepersonasagravado2023.txt");
                    limpiar_Archivo("delitos/Tratadepersonassimple2023.txt");

                    separaraniodelito(delitos);
                }
                break;
            case 0:
                seguir = 'n';
                printf("\nSALIENDO DEL PROGRAMA...\n");
                break;
            default:
                printf("INGRESE UNA OPCION DEL MENU\n");
                break;
        }
    } while(seguir == 's');

    liberartodamemoria(&delitos);
    printf("Fin del programa, gracias por utilizarlo. :)\n");
    return 0;
}



// DEFINICION DE FUNCIONES

void cargar_informacion(nodo **delitos)
{
    FILE *archivo = NULL;

    char linea[1024]; // hacemos buffer LINEA con el fin de poder leer cada linea del archivo, con un tamanio de 1024 bytes para asegurarnos de que no haya errores, sin sacrificar rendimiento en el proceso.
    int cuenta_registros = 0; // tambien aniadimos un contador de registros para llevar la cuenta de registro leidos de forma exitosa.

    archivo = fopen("data/Basededatosoficial.txt", "r"); // lo abrimos en readd
    if(archivo == NULL)
    {
        printf("Lo sentimos, ocurrio un error al tratar de abrir el archivo.\n");
        return;
    }

    
    fgets(linea, 1024, archivo); // saltamos la linea del encabezado

   // aca arrancamos a hacer una lectura linea por linea hasta llegar al final del csv
    
    while (fgets(linea, 1024, archivo) != NULL) 
    {
        nodo *nuevo = (nodo *)malloc(sizeof(nodo)); // creamos el nuevo nodo dinámicamente
        if(nuevo == NULL)
        {
            printf("No queda mas espacio en la memoria\n");
            break;
        }
        
        char *token;

        // TOKEN: Interpretamos al token como la dirección de memoria donde comienza la cadena de texto de un campo. 
        // Gracias a este podemos recorrer la linea de texto char linea y extraer cada campo separado por comas.
        // Los tokens son toda la frase (campo)
        // El puntero a token es la manera de recorrer el token. 



        size_t longitudlinea = strlen(linea);
        if (longitudlinea > 0 && linea[longitudlinea - 1] == '\n') 
        {
            linea[longitudlinea - 1] = '\0'; 
        }


        
        const char delimitador[] = ";"; // defino como mi delimitador entre token y token la coma ";", porque en la bdd estan separados por comas
        
        // TOKEN/CAMPO 1: provincia_id

        token = strtok(linea, delimitador); // usamos  strtok pasandole la linea completa y el delimitador como parametros para obtener el primer token
        if (token == NULL)  // verifico si el campo esta vacio
        { 
            free(nuevo); // libero memoria reservada para no tenerla al pedo
            continue;  // evito los proximos 13 campos si el primero es nulo
        }
        nuevo->provincia_id = atoi(token); // si no es nulo, convierto el token a entero y lo asigno al campo provincia_id del nuevo nodo


        // TOKEN 2 : provincia_nombre
        // aca cambia la cosa porque es un string, no un entero

        token = strtok(NULL, delimitador); // pongo NULL y no linea ya que strtok continua desde donde se quedo en la linea anterior
        if (token == NULL) 
        { 
            free(nuevo);
            continue; 
        }
        strncpy(nuevo->provincia_nombre, token, sizeof(nuevo->provincia_nombre) - 1); // el -1 nos sirve para dejar espacio para el caracter nulo
        nuevo->provincia_nombre[sizeof(nuevo->provincia_nombre) - 1] = '\0'; // Asegurar el nulo para el siguiente campo

        
        // TOKEN 3: anio
        
        token = strtok(NULL, delimitador); // anio
        if (token == NULL) 
        { 
            free(nuevo);
            continue; 
        }
        nuevo->anio = atoi(token);


        // TOKEN 4: codigo_delito

        token = strtok(NULL, delimitador); // anio
        if (token == NULL) 
        { 
            free(nuevo);
            continue; 
        }
        nuevo->codigo_delito = atoi(token);

        
        // TOKEN 5: delito_nombre

        token = strtok(NULL, delimitador); // delito_nombre
        if (token == NULL) { free(nuevo); continue; }
        strncpy(nuevo->delito_nombre, token, sizeof(nuevo->delito_nombre) - 1);
        nuevo->delito_nombre[sizeof(nuevo->delito_nombre) - 1] = '\0'; 
        
        // TOKEN 6: cantidad_hechos
     
        token = strtok(NULL, delimitador); // anio
        if (token == NULL) 
        { 
            free(nuevo);
            continue; 
        }
        nuevo->cantidad_hechos = atoi(token);

        // TOKEN 7: cantidad_victimas
     
        token = strtok(NULL, delimitador); // anio
        if (token == NULL) 
        { 
            free(nuevo);
            continue; 
        }
        nuevo->cantidad_victimas = atoi(token);

        // TOKEN 8: cantidad_masculinos
     
        token = strtok(NULL, delimitador); // anio
        if (token == NULL) 
        { 
            free(nuevo);
            continue; 
        }
        nuevo->cantidad_masculinos = atoi(token);

        // TOKEN 9: cantidad_femeninos
     
        token = strtok(NULL, delimitador); // anio
        if (token == NULL) 
        { 
            free(nuevo);
            continue; 
        }
        nuevo->cantidad_femeninos= atoi(token);


        // TOKEN 10: cantidad_si
     
        token = strtok(NULL, delimitador); // anio
        if (token == NULL) 
        { 
            free(nuevo);
            continue; 
        }
        nuevo->cantidad_si = atoi(token);
    

        // una vez leidos y asignados todos los campos, vamos a insertar el nuevo nodo al final de la lista enlazada

        nuevo->sig = NULL;
        if(*delitos == NULL)
        {
          *delitos = nuevo;
        }
        else
        {
          nodo *aux = *delitos;
          while (aux->sig != NULL)
          {
             aux = aux->sig;
          }
          aux->sig = nuevo;
        }

        cuenta_registros++; // aumentamos en 1 la cuenta de registros/fila de datos

    } 

    fclose(archivo);
    printf("Archivo cargado exitosamente. Total de registros cargados: %d\n", cuenta_registros);
}


void liberartodamemoria(nodo **delitos)
{
    nodo *aux = *delitos;
    nodo *ant = NULL;
    while(aux != NULL)
    {
        ant = aux;
        aux = aux->sig;
        free(ant);
    }
    *delitos = NULL;
}


void limpiar_Archivo(char *nombreArchivo)
{
    FILE *f = fopen(nombreArchivo, "w"); // abre en modo escritura (borra contenido)
    if (f == NULL)
    {
        printf("No se pudo abrir %s para limpiar.\n", nombreArchivo);
        return;
    }
    fclose(f);
    printf("Archivo %s limpiado correctamente.\n", nombreArchivo);
}

// funcion escribir_encabezado, la usamos para generar el encabezado de cada archivo, tanto los de la carpeta delitos, como los de la carpeta provincias y anos.

void escribir_encabezado(FILE *archivo, const char *tipo, int anios, char *str) // pasamos puntero archivo y que se especifique acerca de cual se trata: Delit/Anio/Provincia, segun esto, coloca el encabezado correspondiente
{
    fprintf(archivo, "==================================================================================================================================================\n");
    if (strcmp(tipo, "ANIO") == 0)
        fprintf(archivo, "|                                  ESTADÍSTICAS DE DELITOS SEGÚN ANIO (%d)\n", anios);

    else if (strcmp(tipo, "PROVINCIA") == 0)
        fprintf(archivo, "|                                  ESTADÍSTICAS DE DELITOS POR PROVINCIA (%s)\n", str);

    else if (strcmp(tipo, "DELITO") == 0)
        fprintf(archivo, "|                                  ESTADÍSTICAS DETALLADAS POR TIPO DE DELITO (%s) EN EL ANIO (%d)\n", str, anios);

    fprintf(archivo, "==================================================================================================================================================\n");
    fprintf(archivo, "| IDProv | PROVINCIA           | ANIO  | CODDel | DELITO                                         | HECHOS | VICTIMAS | VicMASC | VicFEM | VicS/D |\n");
    fprintf(archivo, "==================================================================================================================================================\n");
}

// funcion escribir_archivo: Escribe los datos de un nodo en un archivo especifico.

void escribir_archivo(nodo *aux, FILE *abrir)
{

    fprintf(abrir, "|%-8d|%-21s|%-7d|%-8d|%-48s|%-8d|%-10d|%-9d|%-8d|%-8d|\n",
            aux->provincia_id,
            aux->provincia_nombre,
            aux->anio,
            aux->codigo_delito,
            aux->delito_nombre,
            aux->cantidad_hechos,
            aux->cantidad_victimas,
            aux->cantidad_masculinos,
            aux->cantidad_femeninos,
            aux->cantidad_si);
}

void escribirdatosenarchivoprovincia(nodo *delitos)
{
    nodo *aux = delitos;
    int id_prov = 0;
    FILE *abrir = NULL;
    int anios = 0;
    char str[40] = {0};
    while (aux != NULL)
    {
        id_prov = aux->provincia_id;
        long size;
        switch (id_prov)
        {
        case 1:
            abrir = fopen("provincias/datos_CABA.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "CABA");
            fseek(abrir, 0, SEEK_END); // me posiciono al final del archivo
            size = ftell(abrir);       // usio ftell para ver el tamaño del archivo

            if (size == 0) // si es 0, es decir, no hay nada escrito, procedemos a escribir el encabezado
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str); // le pasamos el parametro PROVINCIA, ya que estamos en la funcion que escribe datos por provincia.
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 2:
            abrir = fopen("provincias/datos_BSAS.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "BSAS");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 3:
            abrir = fopen("provincias/datos_CATAMARCA.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "CATAMARCA");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 4:
            abrir = fopen("provincias/datos_CORDOBA.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "CORDOBA");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 5:
            abrir = fopen("provincias/datos_CORRIENTES.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "CORRIENTES");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }

            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 6:
            abrir = fopen("provincias/datos_CHACO.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "CHACO");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 7:
            abrir = fopen("provincias/datos_CHUBUT.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "CHUBUT");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 8:
            abrir = fopen("provincias/datos_ENTRERIOS.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "ENTRE RIOS");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 9:
            abrir = fopen("provincias/datos_FORMOSA.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "FORMOSA");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 10:
            abrir = fopen("provincias/datos_JUJUY.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "JUJUY");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 11:
            abrir = fopen("provincias/datos_LAPAMPA.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "LA PAMPA");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 12:
            abrir = fopen("provincias/datos_LARIOJA.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "LA RIOJA");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 13:
            abrir = fopen("provincias/datos_MENDOZA.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "MENDOZA");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 14:
            abrir = fopen("provincias/datos_MISIONES.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "MISIONES");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 15:
            abrir = fopen("provincias/datos_NEUQUEN.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "NEUQUEN");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 16:
            abrir = fopen("provincias/datos_RIONEGRO.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "RIO NEGRO");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 17:
            abrir = fopen("provincias/datos_SALTA.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "SALTA");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 18:
            abrir = fopen("provincias/datos_SANJUAN.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "SAN JUAN");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 19:
            abrir = fopen("provincias/datos_SANLUIS.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "SAN LUIS");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 20:
            abrir = fopen("provincias/datos_SANTACRUZ.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "SANTA CRUZ");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 21:
            abrir = fopen("provincias/datos_SANTAFE.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "SANTA FE");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 22:
            abrir = fopen("provincias/datos_SANTIAGODELESTERO.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "SANTIAGO DEL ESTERO");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 23:
            abrir = fopen("provincias/datos_TUCUMAN.txt", "a");
            if (abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }

            strcpy(str, "TUCUMAN");
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "PROVINCIA", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;
        }
        aux = aux->sig;
    }
}
void separarporanio(nodo *delitos)
{
    FILE *abrir = NULL;
    nodo *aux = delitos;
    int anios = 0;
    char str[1] = {0};

    while (aux != NULL)
    {
        anios = aux->anio;
        long size;
        switch (anios)
        {
        case 2018:
            abrir = fopen("anos/DELITO2018.txt", "a");
            if (abrir == NULL)
            {
                printf("Error al tratar de abrir el archivo.\n");
                return;
            }
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "ANIO", anios, str);
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 2020:
            abrir = fopen("anos/DELITO2020.txt", "a");
            if (abrir == NULL)
            {
                printf("Error al tratar de abrir el archivo.\n");
                return;
            }
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "ANIO", anios, str);
            }

            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;

        case 2023:
            abrir = fopen("anos/DELITO2023.txt", "a");
            if (abrir == NULL)
            {
                printf("Error al tratar de abrir el archivo.\n");
                return;
            }
            fseek(abrir, 0, SEEK_END);
            size = ftell(abrir);
            if (size == 0)
            {
                escribir_encabezado(abrir, "ANIO", anios, str);
            }

            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;
        }
        aux = aux->sig;
    }
}

void separaraniodelito(nodo *delitos)
{
    FILE *abrir = NULL;
    nodo *aux = delitos;
    int id_del = 0, anios = 0;
    char str[60] = {0};
    while (aux != NULL)
    {
        anios = aux->anio;
        long size;
        switch (anios)
        {
        case 2018:
            id_del = aux->codigo_delito;

            switch (id_del)
            {
            case 1:
                abrir = fopen("delitos/Abusosexualagravado2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "ABUSO SEXUAL AGRAVADO");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 2:
                abrir = fopen("delitos/Abusosexualsimple2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "ABUSO SEXUAL SIMPLE");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 3:
                abrir = fopen("delitos/Abusosexualconaccesocarnal2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "ABUSO SEXUAL ACCESO CARNAL");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 4:
                abrir = fopen("delitos/Ciberdelitossexualesvinculadosamenores2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "CIBER DELITOS SEXUALES VINCULADOS A MENORES");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 5:
                abrir = fopen("delitos/Delitoscontraelhonor2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "DELITOS CONTRA EL HONOR");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 6:
                abrir = fopen("delitos/Homicidiosculpososporotroshechos2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "HOMICIDIOS CULPOSOS POR OTROS HECHOS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 7:
                abrir = fopen("delitos/Homicidiosdolosos2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "HOMICIDIOS DOLOSOS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 8:
                abrir = fopen("delitos/Homicidiosdolososengradodetentativa2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "HOMICIDIOS DOLOSOS EN GRADO TENTATIVA");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 9:
                abrir = fopen("delitos/LesionesculposasenAccidentesViales2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "LESIONES CULPOSAS EN ACCIDENTES VIALES");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 10:
                abrir = fopen("delitos/Lesionesculposasporotroshechos2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "LESIONES CULPOSAS POR OTRS HECHOS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 11:
                abrir = fopen("delitos/Lesionesdolosas2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "LESIONES DOLOSAS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 12:
                abrir = fopen("delitos/Muertesenaccidentesviales2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "MUERTES EN ACCIDENTES VIALES");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 13:
                abrir = fopen("delitos/Otrosdelitoscontralaintegridadsexual2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "OTROS DELITOS CONTRA LA INTEGRIDAD SEXUAL");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 14:
                abrir = fopen("delitos/Otrosdelitoscontralalibertad2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "OTROS DELITOS CONTRA LA LIBERTAD");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 15:
                abrir = fopen("delitos/Otrosdelitoscontralaspersonas2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "OTROS DELITOS CONTRA LAS PERSONAS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 16:
                abrir = fopen("delitos/Suicidios(consumados)2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "SUICIDIOS (CONSUMADOS)");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 17:
                abrir = fopen("delitos/Tentativadeabusosexualconaccesocarnal2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "TENTATIVA DE ABUSO SEXUAL CON ACCESO CARNAL");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 18:
                abrir = fopen("delitos/Tratadepersonasagravado2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "TRATA DE PERSONAS AGRAVADO");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 19:
                abrir = fopen("delitos/Tratadepersonassimple2018.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "TRATA DE PERSONA SIMPLE");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;
            }
            break;

        case 2020:
            id_del = aux->codigo_delito;
            switch (id_del)
            {
            case 1:
                abrir = fopen("delitos/Abusosexualagravado2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    
                    return;
                    
                }
                strcpy(str, "ABUSO SEXUAL AGRAVADO");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 2:
                abrir = fopen("delitos/Abusosexualsimple2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    
                    return;
                    
                }
                strcpy(str, "ABUSO SEXUAL SIMPLE");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 3:
                abrir = fopen("delitos/Abusosexualconaccesocarnal2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    
                    return;
                }
                strcpy(str, "ABUSO SEXUAL CON ACCESO CARNAL");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 4:
                abrir = fopen("delitos/Ciberdelitossexualesvinculadosamenores2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "CIBERDELITOS SEXUALES VINCULADOS A MENORES");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 5:
                abrir = fopen("delitos/Delitoscontraelhonor2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "DELITOS CONTRA EL HONOR");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 6:
                abrir = fopen("delitos/Homicidiosculpososporotroshechos2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "HOMICIDIOS CULPOSOS POR OTROS HECHOS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 7:
                abrir = fopen("delitos/Homicidiosdolosos2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "HOMICIDIOS DOLOSOS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 8:
                abrir = fopen("delitos/Homicidiosdolososengradodetentativa2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "HOMICIDIOS DOLOSOS EN GRADO DE TENTATIVA");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 9:
                abrir = fopen("delitos/LesionesculposasenAccidentesViales2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "LESIONES CULPOSAS EN ACCIDENTES VIALES");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 10:
                abrir = fopen("delitos/Lesionesculposasporotroshechos2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "LESIONES CULPOSAS POR OTROS HECHOS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 11:
                abrir = fopen("delitos/Lesionesdolosas2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "LESIONES DOLOSAS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 12:
                abrir = fopen("delitos/Muertesenaccidentesviales2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "MUERTES EN ACCIDENTES VIALES");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 13:
                abrir = fopen("delitos/Otrosdelitoscontralaintegridadsexual2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "OTROS DELITOS CONTRA LA INTEGRIDAD SEXUAL");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 14:
                abrir = fopen("delitos/Otrosdelitoscontralalibertad2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "OTROS DELITOS CONTRA LA LIBERTAD");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 15:
                abrir = fopen("delitos/Otrosdelitoscontralaspersonas2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "OTROS DELITOS CONTRA LAS PERSONAS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 16:
                abrir = fopen("delitos/Suicidios(consumados)2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "SUICIDIOS (CONSUMADOS)");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 17:
                abrir = fopen("delitos/Tentativadeabusosexualconaccesocarnal2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    
                    return;
                }
                strcpy(str, "TENTATIVA DE ABUSO SEXUAL CON ACCESO CARNAL");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 18:
                abrir = fopen("delitos/Tratadepersonasagravado2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "TRATA DE PERSONAS AGRAVADO");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 19:
                abrir = fopen("delitos/Tratadepersonassimple2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "TRATA DE PERSONAS SIMPLE");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;
            }
            break;








        case 2023:
            id_del = aux->codigo_delito;
            switch (id_del)
            {
            case 1:
                abrir = fopen("delitos/Abusosexualagravado2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }

                strcpy(str, "ABUSO SEXUAL AGRAVADO");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 2:
                abrir = fopen("delitos/Abusosexualsimple2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "ABUSO SEXUAL SIMPLE");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 3:
                abrir = fopen("delitos/Abusosexualconaccesocarnal2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "ABUSO SEXUAL CON ACCESO CARNAL");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 4:
                abrir = fopen("delitos/Ciberdelitossexualesvinculadosamenores2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "CIBERDELITOS SEXUALES VINCULADOS A MENORES");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 5:
                abrir = fopen("delitos/Delitoscontraelhonor2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "DELITOS CONTRA EL HONOR");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 6:
                abrir = fopen("delitos/Homicidiosculpososporotroshechos2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "HOMICIDIOS CULPOSOS POR OTROS HECHOS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 7:
                abrir = fopen("delitos/Homicidiosdolosos2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "HOMICIDIOS DOLOSOS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 8:
                abrir = fopen("delitos/Homicidiosdolososengradodetentativa2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "HOMICIDIOS DOLOSOS EN GRADO DE TENTATIVA");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 9:
                abrir = fopen("delitos/LesionesculposasenAccidentesViales2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "LESIONES CULPOSAS EN ACCIDENTES VIALES");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 10:
                abrir = fopen("delitos/Lesionesculposasporotroshechos2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "LESIONES CULPOSAS POR OTROS HECHOS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 11:
                abrir = fopen("delitos/Lesionesdolosas2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "LESIONES DOLOSAS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 12:
                abrir = fopen("delitos/Muertesenaccidentesviales2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "MUERTES EN ACCIDENTES VIALES");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 13:
                abrir = fopen("delitos/Otrosdelitoscontralaintegridadsexual2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "OTROS DELITOS CONTRA LA INTEGRIDAD SEXUAL");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 14:
                abrir = fopen("delitos/Otrosdelitoscontralalibertad2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "OTROS DELITROS CONTRA LA LIBERTAD");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 15:
                abrir = fopen("delitos/Otrosdelitoscontralaspersonas2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "OTROS DELITOS CONTRA LAS PERSONAS");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 16:
                abrir = fopen("delitos/Suicidios(consumados)2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "SUICIDIOS (CONSUMADOS)");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 17:
                abrir = fopen("delitos/Tentativadeabusosexualconaccesocarnal2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "TENTATIVA DE ABUSO SEXUAL CON ACCESO CARNAL");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 18:
                abrir = fopen("delitos/Tratadepersonasagravado2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "TRATA DE PERSONAS AGRAVADO");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribir_archivo(aux, abrir);
                fclose(abrir);
                break;

            case 19:
                abrir = fopen("delitos/Tratadepersonassimple2023.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                strcpy(str, "TRATA DE PERSONAS SIMPLE");
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
            }
            escribir_archivo(aux, abrir);
            fclose(abrir);
            break;
        }

        break;
    }
    aux = aux->sig;
}

