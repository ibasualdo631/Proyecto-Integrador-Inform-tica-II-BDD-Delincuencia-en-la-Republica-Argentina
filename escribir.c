#include "escribir.h"
#include "carga.h"

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
                abrir = fopen("años/DELITO2018.txt", "a");
                if(abrir == NULL)
                {
                    printf("Error al tratar de abrir el archivo.\n");
                    return;
                }
                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;    

            case 2020:
            abrir = fopen("años/DELITO2020.txt", "a");
                if(abrir == NULL){
                    printf("Error al tratar de abrir el archivo.\n");
                    return;
                }

                //

                escribirarchivo(aux, abrir);
                fclose(abrir);
                break;

            case 2023:
            abrir = fopen("años/DELITO2023.txt", "a");
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