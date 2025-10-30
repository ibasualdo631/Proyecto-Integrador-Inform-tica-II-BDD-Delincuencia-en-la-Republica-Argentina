#include "../include/escribir.h"
#include "../include/carga.h"

// funcion escribirarchivo: Escribe los datos de un nodo en un archivo especifico.

void escribirarchivo(nodo *aux, FILE *abrir)
{
    
  fprintf(abrir, "|%-2d|%-20s|%-5d|%-3d|%-48s|%-6d|%-6d|%-6d|%-6d|%-5d|\n",
            aux->provincia_id,
            aux->provincia_nombre,
            aux->anio,
            aux->codigo_delito,
            aux->delito_nombre,
            aux->cantidad_hechos,
            aux->cantidad_victimas,
            aux->cantidad_masculinos,
            aux->cantidad_femeninos, 
            aux->cantidad_si
            ); 
}
void escribirdatosenarchivoprovincia(nodo *delitos)
{
    nodo *aux = delitos;
    int id_prov=0;
    FILE *abrir = NULL;
    while(aux != NULL)
    {
        id_prov = aux->provincia_id;
        switch (id_prov)
        {
        case 1:
            abrir = fopen("provincias/datos_CABA.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 2:
            abrir = fopen("provincias/datos_BSAS.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 3:
            abrir = fopen("provincias/datos_CATAMARCA.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 4:
            abrir = fopen("provincias/datos_CORDOBA.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 5:
            abrir = fopen("provincias/datos_CORRIENTES.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 6:
            abrir = fopen("provincias/datos_CHACO.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 7:
            abrir = fopen("provincias/datos_CHUBUT.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 8:
            abrir = fopen("provincias/datos_ENTRERIOS.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 9:
            abrir = fopen("provincias/datos_FORMOSA.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 10:
            abrir = fopen("provincias/datos_JUJUY.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 11:
            abrir = fopen("provincias/datos_LAPAMPA.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 12:
            abrir = fopen("provincias/datos_LARIOJA.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 13:
            abrir = fopen("provincias/datos_MENDOZA.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 14:
            abrir = fopen("provincias/datos_MISIONES.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 15:
            abrir = fopen("provincias/datos_NEUQUEN.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 16:
            abrir = fopen("provincias/datos_RIONEGRO.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 17:
            abrir = fopen("provincias/datos_SALTA.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 18:
            abrir = fopen("provincias/datos_SANJUANB.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;
            
            case 19:
            abrir = fopen("provincias/datos_SANLUIS.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 20:
            abrir = fopen("provincias/datos_SANTACRUZ.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 21:
            abrir = fopen("provincias/datos_SANTAFE.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;

            case 22:
            abrir = fopen("provincias/datos_SANTIAGODELESTERO.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
            }
            escribirarchivo(aux, abrir);
            fclose(abrir);
            break;
            
            case 23:
            abrir = fopen("provincias/datos_TUCUMAN.txt", "a");
            if(abrir == NULL)
            {
                printf("ERORR AL ABRIR EL ARCHIVO\n");
                return;
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
    while(aux != NULL)
    {
        anios = aux->anio;
        switch(anios)
        {
            case 2018:
                abrir = fopen("anos/DELITO2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("Error al tratar de abrir el archivo.\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;    

            case 2020:
            abrir = fopen("anos/DELITO2020.txt", "a");
                if(abrir == NULL){
                    printf("Error al tratar de abrir el archivo.\n");
                    return;
                }

                //

                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 2023:
            abrir = fopen("anos/DELITO2023.txt", "a");
                if(abrir == NULL){
                    printf("Error al tratar de abrir el archivo.\n");
                    return;
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
    int id_del=0, anios = 0;
    while(aux != NULL)
    {
        anios = aux->anio;
        switch (anios)
        {
        case 2018:
            id_del = aux->codigo_delito;
            switch (id_del)
            {
                case 1:
                abrir = fopen("delitos/Abusosexualagravado2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 2:
                abrir = fopen("delitos/Abusosexualsimple2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 3:
                abrir = fopen("delitos/Abusosexualconaccesocarnal2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 4:
                abrir = fopen("delitos/Ciberdelitossexualesvinculadosamenores2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 5:
                abrir = fopen("delitos/Delitoscontraelhonor2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 6:
                abrir = fopen("delitos/Homicidiosculpososporotroshechos2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 7:
                abrir = fopen("delitos/Homicidiosdolosos2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 8:
                abrir = fopen("delitos/Homicidiosdolososengradodetentativa2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 9:
                abrir = fopen("delitos/LesionesculposasenAccidentesViales2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 10:
                abrir = fopen("delitos/Lesionesculposasporotroshechos2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 11:
                abrir = fopen("delitos/Lesionesdolosas2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 12:
                abrir = fopen("delitos/Muertesenaccidentesviales2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 13:
                abrir = fopen("delitos/Otrosdelitoscontralaintegridadsexual2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 14:
                abrir = fopen("delitos/Otrosdelitoscontralalibertad2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 15:
                abrir = fopen("delitos/Otrosdelitoscontralaspersonas2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 16:
                abrir = fopen("delitos/Suicidios(consumados)2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 17:
                abrir = fopen("delitos/Tentativadeabusosexualconaccesocarnal2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 18:
                abrir = fopen("delitos/Tratadepersonasagravado2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 19:
                abrir = fopen("delitos/Tratadepersonassimple2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
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
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 2:
                abrir = fopen("delitos/Abusosexualsimple2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 3:
                abrir = fopen("delitos/Abusosexualconaccesocarnal2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 4:
                abrir = fopen("delitos/Ciberdelitossexualesvinculadosamenores2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 5:
                abrir = fopen("delitos/Delitoscontraelhonor2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 6:
                abrir = fopen("delitos/Homicidiosculpososporotroshechos2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 7:
                abrir = fopen("delitos/Homicidiosdolosos2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 8:
                abrir = fopen("delitos/Homicidiosdolososengradodetentativa2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 9:
                abrir = fopen("delitos/LesionesculposasenAccidentesViales2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 10:
                abrir = fopen("delitos/Lesionesculposasporotroshechos2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 11:
                abrir = fopen("delitos/Lesionesdolosas2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 12:
                abrir = fopen("delitos/Muertesenaccidentesviales2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 13:
                abrir = fopen("delitos/Otrosdelitoscontralaintegridadsexual2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 14:
                abrir = fopen("delitos/Otrosdelitoscontralalibertad2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 15:
                abrir = fopen("delitos/Otrosdelitoscontralaspersonas2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 16:
                abrir = fopen("delitos/Suicidios(consumados)2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 17:
                abrir = fopen("delitos/Tentativadeabusosexualconaccesocarnal2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 18:
                abrir = fopen("delitos/Tratadepersonasagravado2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 19:
                abrir = fopen("delitos/Tratadepersonassimple2020.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
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
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 2:
                abrir = fopen("delitos/Abusosexualsimple2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 3:
                abrir = fopen("delitos/Abusosexualconaccesocarnal2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 4:
                abrir = fopen("delitos/Ciberdelitossexualesvinculadosamenores2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 5:
                abrir = fopen("delitos/Delitoscontraelhonor2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 6:
                abrir = fopen("delitos/Homicidiosculpososporotroshechos2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 7:
                abrir = fopen("delitos/Homicidiosdolosos2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 8:
                abrir = fopen("delitos/Homicidiosdolososengradodetentativa2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 9:
                abrir = fopen("delitos/LesionesculposasenAccidentesViales2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 10:
                abrir = fopen("delitos/Lesionesculposasporotroshechos2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 11:
                abrir = fopen("delitos/Lesionesdolosas2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 12:
                abrir = fopen("delitos/Muertesenaccidentesviales2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 13:
                abrir = fopen("delitos/Otrosdelitoscontralaintegridadsexual2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 14:
                abrir = fopen("delitos/Otrosdelitoscontralalibertad2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 15:
                abrir = fopen("delitos/Otrosdelitoscontralaspersonas2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 16:
                abrir = fopen("delitos/Suicidios(consumados)2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 17:
                abrir = fopen("delitos/Tentativadeabusosexualconaccesocarnal2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 18:
                abrir = fopen("delitos/Tratadepersonasagravado2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

                case 19:
                abrir = fopen("delitos/Tratadepersonassimple2023.txt", "a");
                if(abrir == NULL)
                {
                    printf("ERROR AL ABRIR EL ARCHIVO\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;
                
            }

            
            break;
        }
        aux = aux->sig;
    }
}


int graficar_torta_anio_por_tipo(const base_t *db, int anio,
                                 const char *salida_png, size_t max_slices)
{
    if (!db || !salida_png) return APP_ERR_ARG;

    /* 1) Agregación por tipo (sumando todas las provincias) */
    agg_t *vec = NULL;
    size_t n=0, cap=0;

    for (size_t i=0; i<db->len; ++i) {
        if (extraer_anio(db->items[i].fecha) != anio) continue;
        if (db->items[i].cantidad <= 0) continue;

        /* buscar tipo existente */
        size_t k;
        for (k=0; k<n; ++k) {
            if (strcmp(vec[k].tipo, db->items[i].tipo)==0) break;
        }
        if (k==n) {
            if (n==cap) {
                size_t ncap = cap? cap*2 : 32;
                agg_t *tmp = (agg_t*)realloc(vec, ncap*sizeof *tmp);
                if (!tmp) { free(vec); return APP_ERR_MEM; }
                vec=tmp; cap=ncap;
            }
            strncpy(vec[n].tipo, db->items[i].tipo, sizeof(vec[n].tipo)-1);
            vec[n].tipo[sizeof(vec[n].tipo)-1]='\0';
            vec[n].total = 0;
            n++;
        }
        vec[k].total += db->items[i].cantidad;
    }

    if (n==0) {
        free(vec);
        fprintf(stderr, "No hay datos para el año %d.\n", anio);
        return APP_ERR_FMT;
    }

    /* 2) Ordenar desc y aplicar top-N con “Otros” si corresponde */
    qsort(vec, n, sizeof *vec, cmp_desc);

    long total_global = 0;
    for (size_t i=0; i<n; ++i) total_global += vec[i].total;

    size_t m = n;
    if (max_slices > 0 && n > max_slices) {
        long otros = 0;
        for (size_t i=max_slices-1; i<n; ++i) {
            if (i==max_slices-1) continue;  // reservamos la última para "Otros"
            otros += vec[i].total;
        }
        /* compactar: dejar top (max_slices-1) y la última como "Otros" */
        m = max_slices;
        vec[max_slices-1].total = otros;
        strncpy(vec[max_slices-1].tipo, "Otros", sizeof(vec[max_slices-1].tipo)-1);
        vec[max_slices-1].tipo[sizeof(vec[max_slices-1].tipo)-1] = '\0';
    }

    /* 3) Dibujar torta con gnuplot */
    FILE *gp = popen("gnuplot -persistent", "w");
    if (!gp) { free(vec); return APP_ERR_IO; }

    fprintf(gp, "set terminal pngcairo size 1000,800\n");
    fprintf(gp, "set output '%s'\n", salida_png);
    fprintf(gp, "set title 'Distribucion por tipo de delito - %d (todas las provincias)'\n", anio);
    fprintf(gp, "unset key\n");
    fprintf(gp, "set size square\n");
    fprintf(gp, "set xrange [-1.1:1.1]\n");
    fprintf(gp, "set yrange [-1.1:1.1]\n");
    fprintf(gp, "set style fill solid 1.0 border -1\n");

    const char *colores[] = {
        "#1f77b4","#ff7f0e","#2ca02c","#d62728","#9467bd",
        "#8c564b","#e377c2","#7f7f7f","#bcbd22","#17becf",
        "#393b79","#637939","#8c6d31","#843c39","#7b4173"
    };
    size_t ncol = sizeof(colores)/sizeof(colores[0]);

    double inicio = 0.0;
    const double PI = 3.14159265358979323846;
    double radio_label = 0.78;

    for (size_t i=0; i<m; ++i) {
        double pct = (double)vec[i].total / (double)total_global;
        double ang = pct * 360.0;
        double fin = inicio + ang;

        fprintf(gp,
            "set object %zu circle at 0,0 size 1 arc [%.10f:%.10f] fillcolor rgb '%s'\n",
            i+1, inicio, fin, colores[i % ncol]);

        /* etiqueta centrada en la porción */
        double mid = inicio + ang/2.0;
        double x = radio_label * cos(mid * PI/180.0);
        double y = radio_label * sin(mid * PI/180.0);

        char safe_tipo[256];
        escape_label(vec[i].tipo, safe_tipo, sizeof(safe_tipo));
        fprintf(gp,
            "set label %zu '%s\\n%.1f%%%%' at %.6f,%.6f center tc rgb 'black'\n",
            i+1, safe_tipo, pct*100.0, x, y);

        inicio = fin;
    }

    fprintf(gp, "plot NaN notitle\n");
    fflush(gp);
    pclose(gp);

    free(vec);
    return APP_OK;
}


int graficar_tortas_2018_2020_2023(const base_t *db, const char *outdir, size_t max_slices) {
    if (!db || !outdir) return APP_ERR_ARG;

    char out2018[512], out2020[512], out2023[512];
    snprintf(out2018, sizeof out2018, "%s/torta_2018_tipos.png", outdir);
    snprintf(out2020, sizeof out2020, "%s/torta_2020_tipos.png", outdir);
    snprintf(out2023, sizeof out2023, "%s/torta_2023_tipos.png", outdir);

    int rc = graficar_torta_anio_por_tipo(db, 2018, out2018, max_slices);
    if (rc != APP_OK) return rc;

    rc = graficar_torta_anio_por_tipo(db, 2020, out2020, max_slices);
    if (rc != APP_OK) return rc;

    rc = graficar_torta_anio_por_tipo(db, 2023, out2023, max_slices);
    if (rc != APP_OK) return rc;

    return APP_OK;
}