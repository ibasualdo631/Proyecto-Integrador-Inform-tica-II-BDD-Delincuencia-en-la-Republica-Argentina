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
void liberartodamemoria(nodo **delitos)
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
