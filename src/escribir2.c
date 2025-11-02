#include "../include/escribir.h"
#include "../include/carga.h"
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char provincia_nombre[24]; // 24 provincias
    int total_hechos; // total x provincia
} Acumulador_Provincia; // defino estructura que mee va a servir como acumulador de delitos para cada provincia x individual


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

void escribir_datos_en_archivo_provincia(nodo *delitos)
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


void separar_por_anio(nodo *delitos)
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


void exportar_datos_csv_hechos_provincia(struct nodo *delitos, int opcion)
{
    FILE *abrir = NULL;

    Acumulador_Provincia acumulado[24]; // creo un vector con para guardar el total de cada provincia
    int contador_provincias = 0;




    struct nodo *aux = delitos;
    abrir = fopen("datos_graficos/1_delitosxprovincia.csv", "w");
    if(abrir == NULL)
    {
        printf("ERROR AL ABRIR EL ARCHIVO\n");
        return;
    }
    fprintf(abrir, "Provincia,Cantidad_Hechos\n");
    while(aux != NULL)
    {
        int provincia_encontrada = 0; // bandera
        
        // Buscar si la provincia ya está en nuestro array acumulador
        for(int i = 0; i < contador_provincias; i++)
        {
            
            if (strcmp(acumulado[i].provincia_nombre, aux->provincia_nombre) == 0) // comparo si ya me cruce con esa provincia
            {
                acumulado[i].total_hechos += aux->cantidad_hechos; // voy acumulando
                provincia_encontrada = 1; // levanto la bandera
                break;
            }
        }

        
        if (!provincia_encontrada && contador_provincias < 24) // en caso de no haber encontrado la provincia y hay espacio en el vector 
        {
            
            strcpy(acumulado[contador_provincias].provincia_nombre, aux->provincia_nombre); // Guardo el nombre de la nueva provincia en el acumulador
            acumulado[contador_provincias].total_hechos = aux->cantidad_hechos; // valor inicial
            contador_provincias++; // contador de provincias encontradas +1
        }
        
        aux = aux->sig; 
    }
    for(int i = 0; i < contador_provincias; i++) // escribo todos los acumuladores que guarde en mi vector dentro del archivo
    {
        fprintf(abrir, "%s,%d\n", acumulado[i].provincia_nombre, acumulado[i].total_hechos);
    }

    fclose(abrir);
    printf("Archivo '1_delitosxprovincia.csv' generado con totales por provincia exitosamente!.\n");
}


void exportar_datos_csv_cantidad_hombres_mujeres(struct nodo *delitos)
{
    FILE *abrir = NULL;
    struct nodo *aux = delitos;

    // contadores de cada año

    int cont_2018 = 0;
    int cont_2020 = 0;
    int cont_2023 = 0;

    while(aux != NULL)
    {
        if(aux->anio == 2018)
        {
            abrir = fopen("datos_graficos/2_Hombres_vs_Mujeres_2018", "a");
            if(abrir == NULL)
            {
                printf("Error al abrir el archivo.\n");
                return;
            }
            if(cont_2018 == 0)
            {
                fprintf(abrir, "Hombres,Mujeres\n");
                cont_2018=1;
            }
            fprintf(abrir, "%d,%d\n", aux->cantidad_masculinos, aux->cantidad_femeninos);
            fclose(abrir);
            abrir = NULL;
        }
        else if(aux->anio == 2020)
        {
            abrir = fopen("datos_graficos/2_Hombres_vs_Mujeres_2020", "a");
            if(abrir = NULL)
            {
                printf("Error al abrir el archivo.\n");
                return;
            }
            if(cont_2020 == 0)
            {
                fprintf(abrir, "Hombres,Mujeres\n");
                cont_2020=1;
            }
            fprintf(abrir, "%d,%d", aux->cantidad_masculinos, aux->cantidad_femeninos);
            fclose(abrir);
            abrir = NULL;
        }
        else
        {
            abrir = fopen("datos_graficos/2_Hombres_vs_Mujeres_2023", "a");
            if(abrir = NULL)
            {
                printf("Error al abrir el archivo.\n");
                return;
            }
            if(cont_2023 == 0)
            {
                fprintf(abrir, "Hombres,Mujeres\n");
                cont_2023=1;
            }
            fprintf(abrir, "%d,%d", aux->cantidad_masculinos, aux->cantidad_femeninos);
            fclose(abrir);
            abrir = NULL;
        }
        aux = aux->sig;
    }

    printf("Archivos '2_Hombres_vs_Mujeres_2018', '2_Hombres_vs_Mujeres_2020' y '2_Hombres_vs_Mujeres_2023' generados exitosamente!.\n");
}

void exportar_datos_csv_cantidad_delitos_anio(nodo *delitos)
{
    FILE *abrir = NULL;
    struct nodo *aux = delitos;
    int hechos2018=0, hechos2020=0, hechos2023=0;

    while(aux != NULL)
    {
        if(aux->anio == 2018)
        {
            hechos2018 = hechos2018 + aux->cantidad_hechos;
        }
        else if(aux->anio == 2020)
        {
             hechos2020 = hechos2020 + aux->cantidad_hechos;
        }
        else
        {
             hechos2023 = hechos2023 + aux->cantidad_hechos;
        }
        aux = aux->sig;
    }
    abrir = fopen("datos_graficos/3_Cantidad_hechos_anio.csv", "a");
    if(abrir == NULL)
    {
        printf("Error al abrir el archivo '3_Cantidad_hechos_anio.csv'.\n");
        return;
    }
    fprintf(abrir, "Anio,Cantidad_hechos\n");
    fprintf(abrir, "2018,%d\n", hechos2018);
    fprintf(abrir, "2020,%d\n", hechos2020);
    fprintf(abrir, "2023,%d\n", hechos2023);
    printf("Archivo '3_Cantidad_hechos_anio.csv' creado con exito.\n");
    fclose(abrir);
    abrir = NULL;
}

void menu_poblaciones()
{
    printf("\n");
    printf("================================================================\n");
    printf(" ||        POBLACION TOTAL C/Provincia (Censo 2022)            ||\n");
    printf("================================================================\n");
    printf(" || Provincia de Buenos Aires: 17.523.996                      ||\n");
    printf(" || Cordoba: 3.840.905                                         ||\n");
    printf(" || Santa Fe: 3.544.908                                        ||\n");
    printf(" || CABA: 3.121.707                                            ||\n");
    printf(" || Mendoza: 2.043.540                                         ||\n");
    printf(" || Tucuman: 1.731.820                                         ||\n");
    printf(" || Salta: 1.440.672                                           ||\n");
    printf(" || Entre Rios: 1.425.578                                      ||\n");
    printf(" || Misiones: 1.278.873                                        ||\n");
    printf(" || Corrientes: 1.212.696                                      ||\n");
    printf(" || Chaco: 1.129.606                                           ||\n");
    printf(" || Santiago del Estero: 1.060.906                             ||\n");
    printf(" || San Juan: 822.853                                          ||\n");
    printf(" || Jujuy: 811.611                                             ||\n");
    printf(" || Rio Negro: 750.768                                         ||\n");
    printf(" || Neuquen: 710.814                                           ||\n");
    printf(" || Formosa: 607.419                                           ||\n");
    printf(" || Chubut: 592.621                                            ||\n");
    printf(" || San Luis: 542.069                                          ||\n");
    printf(" || Catamarca: 429.562                                         ||\n");
    printf(" || La Rioja: 383.865                                          ||\n");
    printf(" || La Pampa: 361.859                                          ||\n");
    printf(" || Santa Cruz: 337.226                                        ||\n");
    printf("==============================================================\n");
    printf(" Formula Tasa: | ( Total de Delitos / Poblacion Total) * 100.000 | (tomando como referencia 100.000 habitantes).\n");
}