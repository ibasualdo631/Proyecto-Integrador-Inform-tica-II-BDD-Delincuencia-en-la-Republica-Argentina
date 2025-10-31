#include "../include/escribir.h"
#include "../include/carga.h"
#include <stdlib.h>
#include <string.h>

void limpiarArchivo(char *nombreArchivo)
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

// funcion escribirarchivo: Escribe los datos de un nodo en un archivo especifico.

void escribirarchivo(nodo *aux, FILE *abrir)
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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

            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
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

            escribirarchivo(aux, abrir);
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

            escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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

                escribirarchivo(aux, abrir);
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
                    strcpy(str, "ABUSO SEXUAL AGRAVADO");
                }

                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 2:
                abrir = fopen("delitos/Abusosexualsimple2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                    strcpy(str, "ABUSO SEXUAL SIMPLE");
                }

                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }

                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 3:
                abrir = fopen("delitos/Abusosexualconaccesocarnal2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "ABUSO SEXUAL CON ACCESO CARNAL");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 4:
                abrir = fopen("delitos/Ciberdelitossexualesvinculadosamenores2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "CIBERDELITOS SEXUALES VINCULADOS A MENORES");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 5:
                abrir = fopen("delitos/Delitoscontraelhonor2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "DELITOS CONTRA EL HONOR");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 6:
                abrir = fopen("delitos/Homicidiosculpososporotroshechos2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "HOMICIDIOS CULPOSOS POR OTROS HECHOS");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 7:
                abrir = fopen("delitos/Homicidiosdolosos2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "HOMICIDIOS DOLOSOS");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 8:
                abrir = fopen("delitos/Homicidiosdolososengradodetentativa2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "HOMICIDIOS DOLOSOS EN GRADO DE TENTATIVA");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 9:
                abrir = fopen("delitos/LesionesculposasenAccidentesViales2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "LESIONES CULPOSAS EN ACCIDENTES VIALES");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 10:
                abrir = fopen("delitos/Lesionesculposasporotroshechos2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "LESIONES CULPOSAS POR OTROS HECHOS");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 11:
                abrir = fopen("delitos/Lesionesdolosas2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "LESIONES DOLOSAS");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 12:
                abrir = fopen("delitos/Muertesenaccidentesviales2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "MUERTES EN ACCIDENTES VIALES");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 13:
                abrir = fopen("delitos/Otrosdelitoscontralaintegridadsexual2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "OTROS DELITOS CONTRA LA INTEGRIDAD SEXUAL");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 14:
                abrir = fopen("delitos/Otrosdelitoscontralalibertad2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "OTROS DELITOS CONTRA LA LIBERTAD");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 15:
                abrir = fopen("delitos/Otrosdelitoscontralaspersonas2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "OTROS DELITOS CONTRA LAS PERSONAS");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 16:
                abrir = fopen("delitos/Suicidios(consumados)2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "SUICIDIOS (CONSUMADOS)");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 17:
                abrir = fopen("delitos/Tentativadeabusosexualconaccesocarnal2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "TENTATIVA DE ABUSO SEXUAL CON ACCESO CARNAL");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 18:
                abrir = fopen("delitos/Tratadepersonasagravado2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "TRATA DE PERSONAS AGRAVADO");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 19:
                abrir = fopen("delitos/Tratadepersonassimple2020.txt", "a");
                if (abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");

                    strcpy(str, "TRATA DE PERSONAS SIMPLE");
                    return;
                }
                fseek(abrir, 0, SEEK_END);
                size = ftell(abrir);
                if (size == 0)
                {
                    escribir_encabezado(abrir, "DELITO", anios, str);
                }
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
                escribirarchivo(aux, abrir);
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
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;
        }

        break;
    }
    aux = aux->sig;
}
