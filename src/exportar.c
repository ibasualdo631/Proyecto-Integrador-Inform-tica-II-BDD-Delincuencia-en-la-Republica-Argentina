#include "../headers/escribir.h"
#include "../headers/escribir2.h"
#include "../headers/carga.h"
#include "../headers/exportar.h"
#include <locale.h>
#include <stdlib.h>
#include <string.h>




void exportar_datos_csv_hechos_provincia(nodo *delitos)
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


void exportar_datos_csv_cantidad_hombres_mujeres(nodo *delitos)
{
    FILE *abrir = NULL;
    struct nodo *aux = delitos;

    // acumuladores de cada año

    int hcont_2018 = 0, mcont_2018 = 0;
    int hcont_2020 = 0, mcont_2020 = 0;
    int hcont_2023 = 0, mcont_2023 = 0;
    ;

    while(aux != NULL)
    {
        if(aux->anio == 2018)
        {
          hcont_2018 = hcont_2018 + aux->cantidad_masculinos;
          mcont_2018 = mcont_2018 + aux->cantidad_femeninos;
        }
        else if(aux->anio == 2020)
        {
          hcont_2020 = hcont_2020 + aux->cantidad_masculinos;
          mcont_2020 = mcont_2020 + aux->cantidad_femeninos;
        }
        else
        {
            hcont_2023 = hcont_2023 + aux->cantidad_masculinos;
            mcont_2023 = mcont_2023 + aux->cantidad_femeninos;
        }
        aux = aux->sig;
    }
    
    // archivo general
    abrir = fopen("datos_graficos/2_Hombres_vs_Mujeres.csv", "w"); // w 
    if(abrir == NULL)
    {
        printf("Error al abrir el archivo '2_Hombres_vs_Mujeres.csv'\n");
        return;
    }
    fprintf(abrir, "Anio,Hombres,Mujeres\n");
    fprintf(abrir, "2018, %d,%d\n", hcont_2018, mcont_2018);
    fprintf(abrir, "2020, %d,%d\n", hcont_2020, mcont_2020);
    fprintf(abrir, "2023, %d,%d\n", hcont_2023, mcont_2023);
    
    fclose(abrir);
    abrir = NULL;

    printf("Archivo '2_Hombres_vs_Mujeres.csv' generado exitosamente!.\n");
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
    abrir = fopen("datos_graficos/3_Cantidad_hechos_anio.csv", "w");
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

void exportar_datos_csv_cantidad_delitos_especifico(nodo *delitos)
{
    FILE *abrir = NULL;

    if (delitos == NULL) 
    {

        printf("Error!. Todavia no se ha hecho la carga de delitos.");
        return;
    }


    struct acumulador abusosexualconaccesocarnal2018 = {0}, homicidiosdolosos2018 = {0}, suicidioconsumados2018 = {0}, tratadepersonassimple2018 = {0};
    struct acumulador abusosexualconaccesocarnal2020 = {0}, homicidiosdolosos2020 = {0}, suicidioconsumados2020 = {0}, tratadepersonassimple2020 = {0};
    struct acumulador abusosexualconaccesocarnal2023 = {0}, homicidiosdolosos2023 = {0}, suicidioconsumados2023 = {0}, tratadepersonassimple2023 = {0};

    nodo *aux = delitos;
    while (aux != NULL)
    {
        if (aux->anio == 2018)
        {
            if (aux->codigo_delito == 3) // estos son los codigos de c/ delito 
            {
                abusosexualconaccesocarnal2018.masc += aux->cantidad_masculinos;
                abusosexualconaccesocarnal2018.fem += aux->cantidad_femeninos;
                abusosexualconaccesocarnal2018.sindef += aux->cantidad_si;
            } else if (aux->codigo_delito == 7) 
            {
                homicidiosdolosos2018.masc += aux->cantidad_masculinos;
                homicidiosdolosos2018.fem += aux->cantidad_femeninos;
                homicidiosdolosos2018.sindef += aux->cantidad_si;
            } else if (aux->codigo_delito == 16) 
            {
                suicidioconsumados2018.masc += aux->cantidad_masculinos;
                suicidioconsumados2018.fem += aux->cantidad_femeninos;
                suicidioconsumados2018.sindef += aux->cantidad_si;
            } else if (aux->codigo_delito == 19) 
            
            {
                tratadepersonassimple2018.masc += aux->cantidad_masculinos;
                tratadepersonassimple2018.fem += aux->cantidad_femeninos;
                tratadepersonassimple2018.sindef += aux->cantidad_si;
            }
        }
        else if (aux->anio == 2020)
        {
            if (aux->codigo_delito == 3) {
                abusosexualconaccesocarnal2020.masc += aux->cantidad_masculinos;
                abusosexualconaccesocarnal2020.fem += aux->cantidad_femeninos;
                abusosexualconaccesocarnal2020.sindef += aux->cantidad_si;
            } else if (aux->codigo_delito == 7) {
                homicidiosdolosos2020.masc += aux->cantidad_masculinos;
                homicidiosdolosos2020.fem += aux->cantidad_femeninos;
                homicidiosdolosos2020.sindef += aux->cantidad_si;
            } else if (aux->codigo_delito == 16) {
                suicidioconsumados2020.masc += aux->cantidad_masculinos;
                suicidioconsumados2020.fem += aux->cantidad_femeninos;
                suicidioconsumados2020.sindef += aux->cantidad_si;
            } else if (aux->codigo_delito == 19) {
                tratadepersonassimple2020.masc += aux->cantidad_masculinos;
                tratadepersonassimple2020.fem += aux->cantidad_femeninos;
                tratadepersonassimple2020.sindef += aux->cantidad_si;
            }
        }
        else if (aux->anio == 2023)
        {
            if (aux->codigo_delito == 3) {
                abusosexualconaccesocarnal2023.masc += aux->cantidad_masculinos;
                abusosexualconaccesocarnal2023.fem += aux->cantidad_femeninos;
                abusosexualconaccesocarnal2023.sindef += aux->cantidad_si;
            } else if (aux->codigo_delito == 7) {
                homicidiosdolosos2023.masc += aux->cantidad_masculinos;
                homicidiosdolosos2023.fem += aux->cantidad_femeninos;
                homicidiosdolosos2023.sindef += aux->cantidad_si;
            } else if (aux->codigo_delito == 16) {
                suicidioconsumados2023.masc += aux->cantidad_masculinos;
                suicidioconsumados2023.fem += aux->cantidad_femeninos;
                suicidioconsumados2023.sindef += aux->cantidad_si;
            } else if (aux->codigo_delito == 19) {
                tratadepersonassimple2023.masc += aux->cantidad_masculinos;
                tratadepersonassimple2023.fem += aux->cantidad_femeninos;
                tratadepersonassimple2023.sindef += aux->cantidad_si;
            }
        }
        aux = aux->sig;
    }


    abrir = fopen("datos_graficos/4_Delitos_especificos.csv", "w");
    if(abrir == NULL)
    {
        printf("Error al abrir el archivo '4_Delitos_especificos.csv'\n");
        return;
    }

    fprintf(abrir, "Anio,Delito,Victimas_Masculinas,Victimas_Femeninas,Victimas_SI\n");
    fprintf(abrir, "2018,Abusosexualconaccesocarnal,%d,%d,%d\n", abusosexualconaccesocarnal2018.masc, abusosexualconaccesocarnal2018.fem, abusosexualconaccesocarnal2018.sindef);
    fprintf(abrir, "2018,Homicidiosdoloso,%d,%d,%d\n", homicidiosdolosos2018.masc, homicidiosdolosos2018.fem, homicidiosdolosos2018.sindef);
    fprintf(abrir, "2018,Suicidioconsumados,%d,%d,%d\n", suicidioconsumados2018.masc, suicidioconsumados2018.fem, suicidioconsumados2018.sindef);
    fprintf(abrir, "2018,Tratadepersonassimple,%d,%d,%d\n", tratadepersonassimple2018.masc, tratadepersonassimple2018.fem, tratadepersonassimple2018.sindef);
    fprintf(abrir,"\n");
    fprintf(abrir, "2020,Delito,Victimas_Masc,Victimas_Fem,Victimas_SI\n");
    fprintf(abrir, "2020,Abusosexualconaccesocarnal,%d,%d,%d\n", abusosexualconaccesocarnal2020.masc, abusosexualconaccesocarnal2020.fem, abusosexualconaccesocarnal2020.sindef);
    fprintf(abrir, "2020,Homicidiosdoloso,%d,%d,%d\n", homicidiosdolosos2020.masc, homicidiosdolosos2020.fem, homicidiosdolosos2020.sindef);
    fprintf(abrir, "2020,Suicidioconsumados,%d,%d,%d\n", suicidioconsumados2020.masc, suicidioconsumados2020.fem, suicidioconsumados2020.sindef);
    fprintf(abrir, "2020,Tratadepersonassimple,%d,%d,%d\n", tratadepersonassimple2020.masc, tratadepersonassimple2020.fem, tratadepersonassimple2020.sindef);
    fprintf(abrir,"\n");
    fprintf(abrir, "2023,Delito,Victimas_Masc,Victimas_Fem,Victimas_SI\n");
    fprintf(abrir, "2023,Abusosexualconaccesocarnal,%d,%d,%d\n", abusosexualconaccesocarnal2023.masc, abusosexualconaccesocarnal2023.fem, abusosexualconaccesocarnal2023.sindef);
    fprintf(abrir, "2023,Homicidiosdoloso,%d,%d,%d\n", homicidiosdolosos2023.masc, homicidiosdolosos2023.fem, homicidiosdolosos2023.sindef);
    fprintf(abrir, "2023,Suicidioconsumados,%d,%d,%d\n", suicidioconsumados2023.masc, suicidioconsumados2023.fem, suicidioconsumados2023.sindef);
    fprintf(abrir, "2023,Tratadepersonassimple,%d,%d,%d\n", tratadepersonassimple2023.masc, tratadepersonassimple2023.fem, tratadepersonassimple2023.sindef);
    
    printf("Archivo '4_Delitos_especificos.csv' creado con exito.!\n");
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

    FILE *f = NULL;
    
    f = fopen("datos_graficos/poblacion_Argentina2022.csv","w");

    if (f == NULL)
    {
        printf("Lo sentimos, no pudo crearse el archivo.");
        return;
    }

    fprintf(f,"Provincia,Poblacion\n");
    fprintf(f, "Provincia de Buenos Aires,17523996\n");
    fprintf(f, "Cordoba,3840905\n");
    fprintf(f, "Santa Fe,3544908\n");
    fprintf(f, "CABA,3121707\n");
    fprintf(f, "Mendoza,2043540\n");
    fprintf(f, "Tucuman,1731820\n");
    fprintf(f, "Salta,1440672\n");
    fprintf(f, "Entre Rios,1425578\n");
    fprintf(f, "Misiones,1278873\n");
    fprintf(f, "Corrientes,1212696\n");
    fprintf(f, "Chaco,1129606\n");
    fprintf(f, "Santiago del Estero,1060906\n");
    fprintf(f, "San Juan,822853\n");
    fprintf(f, "Jujuy,811611\n");
    fprintf(f, "Rio Negro,750768\n");
    fprintf(f, "Neuquen,710814\n");
    fprintf(f, "Formosa,607419\n");
    fprintf(f, "Chubut,592621\n");
    fprintf(f, "San Luis,542069\n");
    fprintf(f, "Catamarca,429562\n");
    fprintf(f, "La Rioja,383865\n");
    fprintf(f, "La Pampa,361859\n");
    fprintf(f, "Santa Cruz,337226\n");
    printf("\nSe cargo correctamente los datos en el archivo 'poblacion_Argentina2022.csv'");
    fclose(f);
}



void exportar_datos_csv_hechos_provincia_anio(nodo *delitos)
{
    
    int provincias = 23; // cantidad de provincias
    int id = 0;
    int id_aux = 0; 
    

    Acumulador_Provincia acumulado[23];
    nodo *aux = NULL; 

    
    // BUCLE X23 (externo)
    for(id = 1; id <= provincias; id++)
    {
        id_aux = id - 1; // utilizo un id auxiliar para poder meterme en la verdadera posicion del array    
        
        // inicializo el acumulador para esta provincia
        
        strcpy(acumulado[id_aux].provincia_nombre, "N/D"); 
        acumulado[id_aux].total_hechos_2018 = 0;
        acumulado[id_aux].total_hechos_2020 = 0;
        acumulado[id_aux].total_hechos_2023 = 0;

        
        aux = delitos;

        // BUCLE INTERNO (provincia x provincia)
        while(aux != NULL)
        {
            
            if (aux->provincia_id == id)
            {
                
                // verificador de si ya se ha asignado el nombre de la provincia

                if (strcmp(acumulado[id_aux].provincia_nombre, "N/D") == 0)
                {
                    strcpy(acumulado[id_aux].provincia_nombre, aux->provincia_nombre);
                }
            

                // vamos llenando c/ acumulador correspondiente a esa provincia
                if (aux->anio == 2018) 
                {
                    acumulado[id_aux].total_hechos_2018 += aux->cantidad_hechos;
                } else if (aux->anio == 2020) 
                {
                    acumulado[id_aux].total_hechos_2020 += aux->cantidad_hechos;
                } else if (aux->anio == 2023) 
                {
                    acumulado[id_aux].total_hechos_2023 += aux->cantidad_hechos;
                }
            }
            aux = aux->sig; // Siguiente nodo
        }
        // fin de una provincia, paso a buscar otra
    }
    

    // 2018
    FILE *abrir = NULL;
    abrir = fopen("datos_graficos/5_delitosxprovincia_por_anio_2018.csv", "w");
    if(abrir == NULL)
    {
        printf("ERROR AL ABRIR EL ARCHIVO 2018\n");
        return;
    }
    fprintf(abrir,"\n======== 2018 ========\n");
    fprintf(abrir, "Provincia,Hechos\n");
    for(int i = 0; i < provincias; i++)
    {
        fprintf(abrir, "%s,%d\n", 

            acumulado[i].provincia_nombre,
            acumulado[i].total_hechos_2018);
    }
    fprintf(abrir,"\n======================\n");
    printf("\nSe cargo correctamente los datos en el archivo '5_delitosxprovincia_por_anio_2018.csv'");
    fclose(abrir); // cerrando 2018


    // 2020
    abrir = NULL;
    abrir = fopen("datos_graficos/5_delitosxprovincia_por_anio_2020.csv", "w");
    if(abrir == NULL)
    {
        printf("ERROR AL ABRIR EL ARCHIVO 2020\n");
        return;
    }
    fprintf(abrir,"\n======== 2020 ========\n");
    fprintf(abrir, "Provincia,Hechos\n");
    for(int i = 0; i < provincias; i++)
    {
        fprintf(abrir, "%s,%d\n",acumulado[i].provincia_nombre,acumulado[i].total_hechos_2020);
    }
    fprintf(abrir,"\n======================\n");
    printf("\nSe cargo correctamente los datos en el archivo '5_delitosxprovincia_por_anio_2020.csv'");
    fclose(abrir); // cerrando 2020


    // 2023
    abrir = NULL;
    abrir = fopen("datos_graficos/5_delitosxprovincia_por_anio_2023.csv", "w");
    if(abrir == NULL)
    {
        printf("ERROR AL ABRIR EL ARCHIVO 2023\n");
        return;
    }
    fprintf(abrir,"\n======== 2023 ========\n");
    fprintf(abrir, "Provincia,Hechos\n");
    for(int i = 0; i < provincias; i++)
    {
        fprintf(abrir, "%s,%d\n",acumulado[i].provincia_nombre,acumulado[i].total_hechos_2023);
    }
    fprintf(abrir,"\n======================\n");
    printf("\nSe cargo correctamente los datos en el archivo '5_delitosxprovincia_por_anio_2023.csv'");
    fclose(abrir); // cerrando 2023


    // INCLUIMOS LA TASA DE CRIMINALIDAD
    


    int poblaciones[23] = 
    {
    3121707,  // 0: CABA
    17523996, // 1: Buenos Aires
    429562,   // 2: Catamarca
    3840905,  // 3: Cordoba
    1212696,  // 4: Corrientes
    1129606,  // 5: Chaco
    592621,   // 6: Chubut
    1425578,  // 7: Entre Rios
    607419,   // 8: Formosa
    811611,   // 9: Jujuy
    361859,   // 10: La Pampa
    383865,   // 11: La Rioja
    2043540,  // 12: Mendoza
    1278873,  // 13: Misiones
    710814,   // 14: Neuquen
    750768,   // 15: Rio Negro
    1440672,  // 16: Salta
    822853,   // 17: San Juan
    542069,   // 18: San Luis
    337226,   // 19: Santa Cruz
    3544908,  // 20: Santa Fe
    1060906,  // 21: Santiago del Estero
    1731820   // 22: Tucuman
};
    float criminalidad[23] = {0};

    abrir = fopen("datos_graficos/6_tasa_criminalidad.csv", "w");

    if(abrir == NULL)
    {
        printf("Lo sentimos, hubo un problema al abrir el archivo.");
        return;
    }
    
    char *locale_original = setlocale(LC_NUMERIC, NULL);
    setlocale(LC_NUMERIC, "C");

    fprintf(abrir, "Provincia,Tasa_Criminalidad\n");
    float tasa = 10000.0; 
    for(int i = 0  ; i<23 ; i++)
    {
        acumulado[i].total_hechos = acumulado[i].total_hechos_2018 + acumulado[i].total_hechos_2020 + acumulado[i].total_hechos_2023;
        criminalidad[i] = (((float)acumulado[i].total_hechos / (float)poblaciones[i]) * tasa);
        fprintf(abrir, "%s,%.2f\n", acumulado[i].provincia_nombre, criminalidad[i]);
    }
    
    fclose(abrir);
    abrir = NULL;
    printf("\nSe cargo correctamente los datos en el archivo '6_tasa_criminalidad.csv'");
}
  

    


