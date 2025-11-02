#include "../include/escribir.h"
#include "../include/carga.h"
#include <stdlib.h>
#include <string.h>


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
