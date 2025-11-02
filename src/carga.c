#include "../include/carga.h"
#include "../include/escribir.h"
#include <string.h>



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

void acumulador_delitos_mostrar(nodo *delitos)
{
    struct  nodo *aux = delitos;
    struct acumulador d2018={0};
    struct acumulador d2020={0};    
    struct acumulador d2023={0};
  
    while(aux != NULL)
    {
        if(aux->anio == 2018)
        {
            d2018.cant = d2018.cant + aux->cantidad_hechos;
            d2018.masc = d2018.masc + aux->cantidad_masculinos;
            d2018.fem = d2018.fem + aux->cantidad_femeninos;
            d2018.sindef = d2018.sindef + aux->cantidad_si;
        }
        else if(aux->anio == 2020)
        {
            d2020.cant = d2020.cant + aux->cantidad_hechos;
            d2020.masc = d2020.masc + aux->cantidad_masculinos;
            d2020.fem = d2020.fem + aux->cantidad_femeninos;
            d2020.sindef = d2020.sindef + aux->cantidad_si;
        }
        else
        {
            d2023.cant = d2023.cant + aux->cantidad_hechos;
            d2023.masc = d2023.masc + aux->cantidad_masculinos;
            d2023.fem = d2023.fem + aux->cantidad_femeninos;
            d2023.sindef = d2023.sindef + aux->cantidad_si;
        }
        aux = aux->sig;        
    }
    printf("=============================================================================\n");
    printf("|           CANTIDAD DE HECHOS GENERAL EN CADA ANIO (2018, 2020, 2023)       |\n");
    printf("=============================================================================\n");
    printf("Anio 2018:\n");
    printf("| CANTIDAD DE HECHOS: %d\n", d2018.cant);
    printf("| VICTIMAS MASCULINAS: %d\n", d2018.masc);
    printf("| VICTIMAS FEMENINAS: %d\n", d2018.fem);
    printf("| VICTIMAS SIN DEFINIR: %d\n", d2018.sindef);
    printf("=============================================================================\n");
    printf("\nAnio 2020:\n");
    printf("| CANTIDAD DE HECHOS: %d\n", d2020.cant);
    printf("| VICTIMAS MASCULINAS: %d\n", d2020.masc);
    printf("| VICTIMAS FEMENINAS: %d\n", d2020.fem);
    printf("| VICTIMAS SIN DEFINIR: %d\n", d2020.sindef);
    printf("=============================================================================\n");
    printf("\nAnio 2023:\n");
    printf("| CANTIDAD DE HECHOS: %d\n", d2023.cant);
    printf("| VICTIMAS MASCULINAS: %d\n", d2023.masc);
    printf("| VICTIMAS FEMENINAS: %d\n", d2023.fem);
    printf("| VICTIMAS SIN DEFINIR: %d\n", d2023.sindef);
    printf("=============================================================================\n");
}

void acumulador_delitos_principales_mostrar(nodo *delitos)
{
    struct nodo *aux = delitos;
    struct acumulador abusosexualconaccesocarnal2018={0};
    struct acumulador homicidiosdolosos2018={0};
    struct acumulador suicidioconsumados2018={0};
    struct acumulador tratadepersonassimple2018={0};
    struct acumulador abusosexualconaccesocarnal2020={0};
    struct acumulador homicidiosdolosos2020={0};
    struct acumulador suicidioconsumados2020={0};
    struct acumulador tratadepersonassimple2020={0};
    struct acumulador abusosexualconaccesocarnal2023={0};
    struct acumulador homicidiosdolosos2023={0};
    struct acumulador suicidioconsumados2023={0};
    struct acumulador tratadepersonassimple2023={0};
    int anios;

    while (aux != NULL)
    {
        anios = aux->anio;
        switch (anios)
        {
        case 2018:
            if (strcmp(aux->delito_nombre, "Abusos sexuales con acceso carnal (violacion") == 0)
            {
                abusosexualconaccesocarnal2018.cant = abusosexualconaccesocarnal2018.cant + aux->cantidad_hechos;
                abusosexualconaccesocarnal2018.masc = abusosexualconaccesocarnal2018.masc + aux->cantidad_masculinos;
                abusosexualconaccesocarnal2018.fem = abusosexualconaccesocarnal2018.fem + aux->cantidad_femeninos;
                abusosexualconaccesocarnal2018.sindef = abusosexualconaccesocarnal2018.sindef + aux->cantidad_si;
            }
            else if (strcmp(aux->delito_nombre, "Homicidios dolosos") == 0)
            {
                homicidiosdolosos2018.cant = homicidiosdolosos2018.cant + aux->cantidad_hechos;
                homicidiosdolosos2018.masc = homicidiosdolosos2018.masc + aux->cantidad_masculinos;
                homicidiosdolosos2018.fem = homicidiosdolosos2018.fem + aux->cantidad_femeninos;
                homicidiosdolosos2018.sindef = homicidiosdolosos2018.sindef + aux->cantidad_si;
            }
            else if (strcmp(aux->delito_nombre, "Suicidios (consumados)") == 0)
            {
                suicidioconsumados2018.cant = suicidioconsumados2018.cant + aux->cantidad_hechos;
                suicidioconsumados2018.masc = suicidioconsumados2018.masc + aux->cantidad_masculinos;
                suicidioconsumados2018.fem = suicidioconsumados2018.fem + aux->cantidad_femeninos;
                suicidioconsumados2018.sindef = suicidioconsumados2018.sindef + aux->cantidad_si;
            }
            else if (strcmp(aux->delito_nombre, "Trata de personas simple") == 0)
            {
                tratadepersonassimple2018.cant = tratadepersonassimple2018.cant + aux->cantidad_hechos;
                tratadepersonassimple2018.masc = tratadepersonassimple2018.masc + aux->cantidad_masculinos;
                tratadepersonassimple2018.fem = tratadepersonassimple2018.fem + aux->cantidad_femeninos;
                tratadepersonassimple2018.sindef = tratadepersonassimple2018.sindef + aux->cantidad_si;
            }
            break;
        case 2020:
        if (strcmp(aux->delito_nombre, "Abusos sexuales con acceso carnal (violacion") == 0)
            {
               abusosexualconaccesocarnal2020.cant = abusosexualconaccesocarnal2020.cant + aux->cantidad_hechos;
                abusosexualconaccesocarnal2020.masc = abusosexualconaccesocarnal2020.masc + aux->cantidad_masculinos;
                abusosexualconaccesocarnal2020.fem = abusosexualconaccesocarnal2020.fem + aux->cantidad_femeninos;
                abusosexualconaccesocarnal2020.sindef = abusosexualconaccesocarnal2020.sindef + aux->cantidad_si;
            }
            else if (strcmp(aux->delito_nombre, "Homicidios dolosos") == 0)
            {
                homicidiosdolosos2020.cant = homicidiosdolosos2020.cant + aux->cantidad_hechos;
                homicidiosdolosos2020.masc = homicidiosdolosos2020.masc + aux->cantidad_masculinos;
                homicidiosdolosos2020.fem = homicidiosdolosos2020.fem + aux->cantidad_femeninos;
                homicidiosdolosos2020.sindef = homicidiosdolosos2020.sindef + aux->cantidad_si;
            }
            else if (strcmp(aux->delito_nombre, "Suicidios (consumados)") == 0)
            {
                suicidioconsumados2020.cant = suicidioconsumados2020.cant + aux->cantidad_hechos;
                suicidioconsumados2020.masc = suicidioconsumados2020.masc + aux->cantidad_masculinos;
                suicidioconsumados2020.fem = suicidioconsumados2020.fem + aux->cantidad_femeninos;
                suicidioconsumados2020.sindef = suicidioconsumados2020.sindef + aux->cantidad_si;
            }
            else if (strcmp(aux->delito_nombre, "Trata de personas simple") == 0)
            {
                tratadepersonassimple2020.cant = tratadepersonassimple2020.cant + aux->cantidad_hechos;
                tratadepersonassimple2020.masc = tratadepersonassimple2020.masc + aux->cantidad_masculinos;
                tratadepersonassimple2020.fem = tratadepersonassimple2020.fem + aux->cantidad_femeninos;
                tratadepersonassimple2020.sindef = tratadepersonassimple2020.sindef + aux->cantidad_si;
            }
            break;
        case 2023:
            if (strcmp(aux->delito_nombre, "Abusos sexuales con acceso carnal (violacion") == 0)
            {
                abusosexualconaccesocarnal2023.cant = abusosexualconaccesocarnal2023.cant + aux->cantidad_hechos;
                abusosexualconaccesocarnal2023.masc = abusosexualconaccesocarnal2023.masc + aux->cantidad_masculinos;
                abusosexualconaccesocarnal2023.fem = abusosexualconaccesocarnal2023.fem + aux->cantidad_femeninos;
                abusosexualconaccesocarnal2023.sindef = abusosexualconaccesocarnal2023.sindef + aux->cantidad_si;
            }
            else if (strcmp(aux->delito_nombre, "Homicidios dolosos") == 0)
            {
                homicidiosdolosos2023.cant = homicidiosdolosos2023.cant + aux->cantidad_hechos;
                homicidiosdolosos2023.masc = homicidiosdolosos2023.masc + aux->cantidad_masculinos;
                homicidiosdolosos2023.fem = homicidiosdolosos2023.fem + aux->cantidad_femeninos;
                homicidiosdolosos2023.sindef = homicidiosdolosos2023.sindef + aux->cantidad_si;
            }
            else if (strcmp(aux->delito_nombre, "Suicidios (consumados)") == 0)
            {
                suicidioconsumados2023.cant = suicidioconsumados2023.cant + aux->cantidad_hechos;
                suicidioconsumados2023.masc = suicidioconsumados2023.masc + aux->cantidad_masculinos;
                suicidioconsumados2023.fem = suicidioconsumados2023.fem + aux->cantidad_femeninos;
                suicidioconsumados2023.sindef = suicidioconsumados2023.sindef + aux->cantidad_si;
            }
            else if (strcmp(aux->delito_nombre, "Trata de personas simple") == 0)
            {
                tratadepersonassimple2023.cant = tratadepersonassimple2023.cant + aux->cantidad_hechos;
                tratadepersonassimple2023.masc = tratadepersonassimple2023.masc + aux->cantidad_masculinos;
                tratadepersonassimple2023.fem = tratadepersonassimple2023.fem + aux->cantidad_femeninos;
                tratadepersonassimple2023.sindef = tratadepersonassimple2023.sindef + aux->cantidad_si;
            }
            break;
        }
        aux = aux->sig;
    }
    
    printf("----------CANTIDAD DE DELITOS ESPECIFICOS EN SU RESPECTIVO ANIO----------\n");
    
    printf("-----2018-----\n");

    printf("---ABUSO SEXUAL CON ACCESO CARNAL---\n");
    printf("CANTIDAD DE HECHOS: %d\n", abusosexualconaccesocarnal2018.cant);
    printf("VICTIMAS MASCULINAS: %d\n", abusosexualconaccesocarnal2018.masc);
    printf("VICTIMAS FEMENINAS: %d\n", abusosexualconaccesocarnal2018.fem);
    printf("VICTIMAS SIN DEFINIR: %d\n", abusosexualconaccesocarnal2018.sindef);
    
    printf("\n---HOMICIDIOS DOLOSOS---\n");
    printf("CANTIDAD DE HECHOS: %d\n", homicidiosdolosos2018.cant);
    printf("VICTIMAS MASCULINAS: %d\n", homicidiosdolosos2018.masc);
    printf("VICTIMAS FEMENINAS: %d\n", homicidiosdolosos2018.fem);
    printf("VICTIMAS SIN DEFINIR: %d\n", homicidiosdolosos2018.sindef);
    
    printf("\n---SUICIDIO (CONSUMADO)---\n");
    printf("CANTIDAD DE HECHOS: %d\n", suicidioconsumados2018.cant);
    printf("VICTIMAS MASCULINAS: %d\n", suicidioconsumados2018.masc);
    printf("VICTIMAS FEMENINAS: %d\n", suicidioconsumados2018.fem);
    printf("VICTIMAS SIN DEFINIR: %d\n", suicidioconsumados2018.sindef);
    
    printf("\n---TRATA DE PERSONAS SIMPLE---\n");
    printf("CANTIDAD DE HECHOS: %d\n", tratadepersonassimple2018.cant);
    printf("VICTIMAS MASCULINAS: %d\n", tratadepersonassimple2018.masc);
    printf("VICTIMAS FEMENINAS: %d\n", tratadepersonassimple2018.fem);
    printf("VICTIMAS SIN DEFINIR: %d\n", tratadepersonassimple2018.sindef);
    
    printf("\n-----2020-----\n");
    
    printf("---ABUSO SEXUAL CON ACCESO CARNAL---\n");
    printf("CANTIDAD DE HECHOS: %d\n", abusosexualconaccesocarnal2020.cant);
    printf("VICTIMAS MASCULINAS: %d\n", abusosexualconaccesocarnal2020.masc);
    printf("VICTIMAS FEMENINAS: %d\n", abusosexualconaccesocarnal2020.fem);
    printf("VICTIMAS SIN DEFINIR: %d\n", abusosexualconaccesocarnal2020.sindef);
    
    printf("\n---HOMICIDIOS DOLOSOS---\n");
    printf("CANTIDAD DE HECHOS: %d\n", homicidiosdolosos2020.cant);
    printf("VICTIMAS MASCULINAS: %d\n", homicidiosdolosos2020.masc);
    printf("VICTIMAS FEMENINAS: %d\n", homicidiosdolosos2020.fem);
    printf("VICTIMAS SIN DEFINIR: %d\n", homicidiosdolosos2020.sindef);

    printf("\n---SUICIDIO (CONSUMADO)---\n");
    printf("CANTIDAD DE HECHOS: %d\n", suicidioconsumados2020.cant);
    printf("VICTIMAS MASCULINAS: %d\n", suicidioconsumados2020.masc);
    printf("VICTIMAS FEMENINAS: %d\n", suicidioconsumados2020.fem);
    printf("VICTIMAS SIN DEFINIR: %d\n", suicidioconsumados2020.sindef);
    
    printf("\n---TRATA DE PERSONAS SIMPLE---\n");
    printf("CANTIDAD DE HECHOS: %d\n", tratadepersonassimple2020.cant);
    printf("VICTIMAS MASCULINAS: %d\n", tratadepersonassimple2020.masc);
    printf("VICTIMAS FEMENINAS: %d\n", tratadepersonassimple2020.fem);
    printf("VICTIMAS SIN DEFINIR: %d\n", tratadepersonassimple2020.sindef);
    
    printf("-----2023-----\n");
    
    printf("---ABUSO SEXUAL CON ACCESO CARNAL---\n");
    printf("CANTIDAD DE HECHOS: %d\n", abusosexualconaccesocarnal2023.cant);
    printf("VICTIMAS MASCULINAS: %d\n", abusosexualconaccesocarnal2023.masc);
    printf("VICTIMAS FEMENINAS: %d\n", abusosexualconaccesocarnal2023.fem);
    printf("VICTIMAS SIN DEFINIR: %d\n", abusosexualconaccesocarnal2023.sindef);
    
    printf("\n---HOMICIDIOS DOLOSOS---\n");
    printf("CANTIDAD DE HECHOS: %d\n", homicidiosdolosos2023.cant);
    printf("VICTIMAS MASCULINAS: %d\n", homicidiosdolosos2023.masc);
    printf("VICTIMAS FEMENINAS: %d\n", homicidiosdolosos2023.fem);
    printf("VICTIMAS SIN DEFINIR: %d\n", homicidiosdolosos2023.sindef);
    
    printf("\n---SUICIDIO (CONSUMADO)---\n");
    printf("CANTIDAD DE HECHOS: %d\n", suicidioconsumados2023.cant);
    printf("VICTIMAS MASCULINAS: %d\n", suicidioconsumados2023.masc);
    printf("VICTIMAS FEMENINAS: %d\n", suicidioconsumados2023.fem);
    printf("VICTIMAS SIN DEFINIR: %d\n", suicidioconsumados2023.sindef);
    
    printf("\n---TRATA DE PERSONAS SIMPLE---\n");
    printf("CANTIDAD DE HECHOS: %d\n", tratadepersonassimple2023.cant);
    printf("VICTIMAS MASCULINAS: %d\n", tratadepersonassimple2023.masc);
    printf("VICTIMAS FEMENINAS: %d\n", tratadepersonassimple2023.fem);
    printf("VICTIMAS SIN DEFINIR: %d\n", tratadepersonassimple2023.sindef);

}



void liberar_toda_memoria(nodo **delitos)
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
