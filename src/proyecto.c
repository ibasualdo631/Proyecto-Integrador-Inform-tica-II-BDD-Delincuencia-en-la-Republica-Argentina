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
        printf(" || [5] GENERAR graficos TORTA de        ||\n");
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
                    separaraniodelito(delitos);
                }
                break;
            case 5:
                if (delitos == NULL)
                {
                    printf("NO HAY DATOS EN LA LISTA\n");
                }
                else
                {
                    if (graficar_tortas_2018_2020_2023(&db, "data", 8) == APP_OK) 
                    {
                        puts("Graficos generados correctamente:");
                        puts("   data/torta_2018_tipos.png");
                        puts("   data/torta_2020_tipos.png");
                        puts("   data/torta_2023_tipos.png");
                    } 
                    else 
                    {
                        puts("Error al generar los graficos.");
                    }
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
