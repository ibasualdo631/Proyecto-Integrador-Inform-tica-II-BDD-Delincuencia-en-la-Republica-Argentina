#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "../headers/carga.h"
#include "../headers/escribir.h"
#include "../headers/escribir2.h"
#include "../headers/exportar.h"

int main()
{
    printf("Iniciando programa...\n");
    int opcion = 0;
    char seguir_main = 's';
    nodo *delitos = NULL;

    setlocale(LC_ALL, "");

    do
    {
        printf("\n");
        printf("=============================================================================\n");
        printf(" || DELINCUENCIA EN LA REPUBLICA ARGENTINA                                 ||\n");
        printf("=============================================================================\n");
        printf(" || [1] CARGAR BDD                                                         ||\n");
        printf(" || [2] GENERAR Reporte por Provincia                                      ||\n");
        printf(" || [3] GENERAR Reporte de Delitos totales por Anio                        ||\n");
        printf(" || [4] GENERAR Reporte de Delitos totales por Anio y tipo de delito       ||\n");
        printf(" || [5] HERRAMIENTA Generacion de datos Estadisticos (pre-graficos)        ||\n");
        printf(" || [6] MOSTRAR Cantidad de poblacion de c/provincia (p/graficar)          ||\n");
        printf(" || [7] MOSTRAR Cantidad de hechos, victimas por ANIO (General)            ||\n");
        printf(" || [8] MOSTRAR Cantidad de hechos, victimas por ANIO (Delito especifico)  ||\n");
        printf(" || [0] Salir                                                              ||\n");
        printf("=============================================================================\n");
        printf("   >>> Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            cargar_informacion(&delitos);
            break;
        case 2:
            if (delitos == NULL)
            {
                printf("LOS DELITOS AUN NO ESTAN CARGADOS\n");
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
                escribir_datos_en_archivo_provincia(delitos);
            }
            break;
        case 3:
            if (delitos == NULL)
            {
                printf("LOS DELITOS AUN NO ESTAN CARGADOS\n");
            }
            else
            {
                limpiar_Archivo("anos/DELITO2018.txt");
                limpiar_Archivo("anos/DELITO2020.txt");
                limpiar_Archivo("anos/DELITO2023.txt");
                separar_por_anio(delitos);
            }
            break;
        case 4:
            if (delitos == NULL)
            {
                printf("LOS DELITOS AUN NO ESTAN CARGADOS\n");
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

                separar_anio_delito(delitos);
            }
            break;

        case 5:
            if (delitos == NULL)
            {
                printf("LOS DELITOS AUN NO ESTAN CARGADOS\n");
            }
            else
            {
                int opcion=0;

                do
                {
                    printf("\n");
                    printf("=============================================================================\n");
                    printf(" || HERRAMIENTA Generacion de datos Estadisticos (pre-graficos)            ||\n");
                    printf("=============================================================================\n");
                    printf(" || [1] Comparativa +/- Cantidad de Delitos c/Provincia (general)          ||\n"); // 1 grafico de barras, compara todos los delitos en los 3 años de c/provincia
                    printf(" || [2] Comparativa Hombres vs Mujeres por Anio                            ||\n"); // 3 graficos torta, 1/p/c año. C/grafico contiene la comparacion entre el total de victimas hombres de ese año vs la cantidad de victimas mujeres en ese año
                    printf(" || [3] Comparativa Cantidad de delitos x Anio                             ||\n"); // 1 grafico torta 3 paneles 1 p/c año. C/panel tiene la cantidad de delitos totales de ese año
                    printf(" || [4] Comparativa Delitos Especificos x Anio                             ||\n");
                    printf(" || [5] Comparativa +/- Cantidad de Delitos c/Provincia (x anio)           ||\n"); 
                    printf(" || [0] Volver al menu principal                                           ||\n");
                    printf("=============================================================================\n");
                    printf("   >>> Seleccione una opcion: ");
                    scanf("%d", &opcion);

                    switch (opcion)
                    {
                    case 1:
                        limpiar_Archivo("datos_graficos/1_delitosxprovincia.csv");
                        exportar_datos_csv_hechos_provincia(delitos);    
                        break;
                    case 2:
                        limpiar_Archivo("datos_graficos/2_Hombres_vs_Mujeres.csv");
                        exportar_datos_csv_cantidad_hombres_mujeres(delitos);
                        break;
                    case 3:
                        limpiar_Archivo("datos_graficos/3_Cantidad_hechos_anio.csv");
                        exportar_datos_csv_cantidad_delitos_anio(delitos);
                        break;
                    case 4:
                        limpiar_Archivo("datos_graficos/4_Delitos_especificos.csv");
                        exportar_datos_csv_cantidad_delitos_especifico(delitos);
                        break;
                    case 5:
                        limpiar_Archivo("datos_graficos/5_delitosxprovincia_por_anio_2018.csv");
                        limpiar_Archivo("datos_graficos/5_delitosxprovincia_por_anio_2020.csv");
                        limpiar_Archivo("datos_graficos/5_delitosxprovincia_por_anio_2023.csv");
                        limpiar_Archivo("datos_graficos/6_tasa_criminalidad.csv");
                        exportar_datos_csv_hechos_provincia_anio(delitos);
                        break;
                    case 0:
                        printf("\nVolviendo al Menu...\n");
                        break;
                    default:
                        printf("INGRESE UNA OPCION VALIDA\n");
                        break;
                    }

                } while (opcion != 0);
            }
            break;

        case 6:
            limpiar_Archivo("datos_graficos/poblacion_Argentina2022.csv");
            menu_poblaciones();
            break;

        case 7:
            if(delitos == NULL)
            {
                printf("Lo sentimos, los delitos aun no se han cargado.\n");
            }
            else
            {
                acumulador_delitos_mostrar(delitos);
            }
            break;

        
        case 8:
            if(delitos == NULL)
            {
                printf("Lo sentimos, los delitos aun no se han cargado.\n");
            }
            else
            {
                acumulador_delitos_principales_mostrar(delitos);
            }
            break;
        
        
        }

    } while (seguir_main == 's');
    
    
    
    printf("Fin del programa, gracias por utizarlo");
    liberar_toda_memoria(&delitos);

}
