#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "../include/carga.h"
#include "../include/escribir.h"

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
                    limpiarArchivo("provincias/datos_CABA.txt");
                    limpiarArchivo("provincias/datos_BSAS.txt");
                    limpiarArchivo("provincias/datos_CATAMARCA.txt");
                    limpiarArchivo("provincias/datos_CORDOBA.txt");
                    limpiarArchivo("provincias/datos_CHACO.txt");
                    limpiarArchivo("provincias/datos_CORRIENTES.txt");
                    limpiarArchivo("provincias/datos_CHUBUT.txt");
                    limpiarArchivo("provincias/datos_ENTRERIOS.txt");
                    limpiarArchivo("provincias/datos_FORMOSA.txt");
                    limpiarArchivo("provincias/datos_JUJUY.txt");
                    limpiarArchivo("provincias/datos_LAPAMPA.txt");
                    limpiarArchivo("provincias/datos_LARIOJA.txt");
                    limpiarArchivo("provincias/datos_MENDOZA.txt");
                    limpiarArchivo("provincias/datos_MISIONES.txt");
                    limpiarArchivo("provincias/datos_NEUQUEN.txt");
                    limpiarArchivo("provincias/datos_RIONEGRO.txt");
                    limpiarArchivo("provincias/datos_SALTA.txt");
                    limpiarArchivo("provincias/datos_SANJUAN.txt");
                    limpiarArchivo("provincias/datos_SANLUIS.txt");
                    limpiarArchivo("provincias/datos_SANTACRUZ.txt");
                    limpiarArchivo("provincias/datos_SANTAFE.txt");
                    limpiarArchivo("provincias/datos_SANTIAGODELESTERO.txt");
                    limpiarArchivo("provincias/datos_TUCUMAN.txt");
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
                    limpiarArchivo("anos/DELITO2018.txt");
                    limpiarArchivo("anos/DELITO2020.txt");
                    limpiarArchivo("anos/DELITO2023.txt");
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
                    limpiarArchivo("delitos/Abusosexualagravado2018.txt");
                    limpiarArchivo("delitos/Abusosexualsimple2018.txt");
                    limpiarArchivo("delitos/Abusosexualconaccesocarnal2018.txt");
                    limpiarArchivo("delitos/Ciberdelitossexualesvinculadosamenores2018.txt");
                    limpiarArchivo("delitos/Delitoscontraelhonor2018.txt");
                    limpiarArchivo("delitos/Homicidiosculpososporotroshechos2018.txt");
                    limpiarArchivo("delitos/Homicidiosdolosos2018.txt");
                    limpiarArchivo("delitos/Homicidiosdolososengradodetentativa2018.txt");
                    limpiarArchivo("delitos/LesionesculposasenAccidentesViales2018.txt");
                    limpiarArchivo("delitos/Lesionesculposasporotroshechos2018.txt");
                    limpiarArchivo("delitos/Lesionesdolosas2018.txt");
                    limpiarArchivo("delitos/Muertesenaccidentesviales2018.txt");
                    limpiarArchivo("delitos/Otrosdelitoscontralaintegridadsexual2018.txt");
                    limpiarArchivo("delitos/Otrosdelitoscontralalibertad2018.txt");
                    limpiarArchivo("delitos/Otrosdelitoscontralaspersonas2018.txt");
                    limpiarArchivo("delitos/Suicidios(consumados)2018.txt");
                    limpiarArchivo("delitos/Tentativadeabusosexualconaccesocarnal2018.txt");
                    limpiarArchivo("delitos/Tratadepersonasagravado2018.txt");
                    limpiarArchivo("delitos/Tratadepersonassimple2018.txt");
                    limpiarArchivo("delitos/Abusosexualagravado2020.txt");
                    limpiarArchivo("delitos/Abusosexualsimple2020.txt");
                    limpiarArchivo("delitos/Abusosexualconaccesocarnal2020.txt");
                    limpiarArchivo("delitos/Ciberdelitossexualesvinculadosamenores2020.txt");
                    limpiarArchivo("delitos/Delitoscontraelhonor2020.txt");
                    limpiarArchivo("delitos/Homicidiosculpososporotroshechos2020.txt");
                    limpiarArchivo("delitos/Homicidiosdolosos2020.txt");
                    limpiarArchivo("delitos/Homicidiosdolososengradodetentativa2020.txt");
                    limpiarArchivo("delitos/LesionesculposasenAccidentesViales2020.txt");
                    limpiarArchivo("delitos/Lesionesculposasporotroshechos2020.txt");
                    limpiarArchivo("delitos/Lesionesdolosas2020.txt");
                    limpiarArchivo("delitos/Muertesenaccidentesviales2020.txt");
                    limpiarArchivo("delitos/Otrosdelitoscontralaintegridadsexual2020.txt");
                    limpiarArchivo("delitos/Otrosdelitoscontralalibertad2020.txt");
                    limpiarArchivo("delitos/Otrosdelitoscontralaspersonas2020.txt");
                    limpiarArchivo("delitos/Suicidios(consumados)2020.txt");
                    limpiarArchivo("delitos/Tentativadeabusosexualconaccesocarnal2020.txt");
                    limpiarArchivo("delitos/Tratadepersonasagravado2020.txt");
                    limpiarArchivo("delitos/Tratadepersonassimple2020.txt");
                    limpiarArchivo("delitos/Abusosexualagravado2023.txt");
                    limpiarArchivo("delitos/Abusosexualsimple2023.txt");
                    limpiarArchivo("delitos/Abusosexualconaccesocarnal2023.txt");
                    limpiarArchivo("delitos/Ciberdelitossexualesvinculadosamenores2023.txt");
                    limpiarArchivo("delitos/Delitoscontraelhonor2023.txt");
                    limpiarArchivo("delitos/Homicidiosculpososporotroshechos2023.txt");
                    limpiarArchivo("delitos/Homicidiosdolosos2023.txt");
                    limpiarArchivo("delitos/Homicidiosdolososengradodetentativa2023.txt");
                    limpiarArchivo("delitos/LesionesculposasenAccidentesViales2023.txt");
                    limpiarArchivo("delitos/Lesionesculposasporotroshechos2023.txt");
                    limpiarArchivo("delitos/Lesionesdolosas2023.txt");
                    limpiarArchivo("delitos/Muertesenaccidentesviales2023.txt");
                    limpiarArchivo("delitos/Otrosdelitoscontralaintegridadsexual2023.txt");
                    limpiarArchivo("delitos/Otrosdelitoscontralalibertad2023.txt");
                    limpiarArchivo("delitos/Otrosdelitoscontralaspersonas2023.txt");
                    limpiarArchivo("delitos/Suicidios(consumados)2023.txt");
                    limpiarArchivo("delitos/Tentativadeabusosexualconaccesocarnal2023.txt");
                    limpiarArchivo("delitos/Tratadepersonasagravado2023.txt");
                    limpiarArchivo("delitos/Tratadepersonassimple2023.txt");

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
