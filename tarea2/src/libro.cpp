#include "../include/libro.h"

struct rep_libro {
    int isbn;
    char titulo[MAX_TITULO];
    char nombreAutor[MAX_NOMBRE_AUTOR];
    char apellidoAutor[MAX_APELLIDO_AUTOR];
    char descripcion[MAX_DESCRIPCION];
    int idGeneroLibro;
    TFecha fechaEdicion;
};

// Crea y retorna un elemento de tipo TLibro con los valores dados
TLibro crearTLibro(int isbn, const char titulo[MAX_TITULO], const char nombreAutor[MAX_NOMBRE_AUTOR], const char apellidoAutor[MAX_APELLIDO_AUTOR], const char descripcion[MAX_DESCRIPCION], int idGeneroLibro, TFecha fechaEdicion){
    TLibro nuevoLibro = new rep_libro;
    nuevoLibro->isbn = isbn;
    strcpy(nuevoLibro->titulo, titulo);
    strcpy(nuevoLibro->nombreAutor, nombreAutor);
    strcpy(nuevoLibro->apellidoAutor, apellidoAutor);
    strcpy(nuevoLibro->descripcion, descripcion);
    nuevoLibro->idGeneroLibro = idGeneroLibro;
    nuevoLibro->fechaEdicion = copiarTFecha(fechaEdicion);
    liberarTFecha(fechaEdicion);
    return nuevoLibro;
}

// Libera la memoria asignada para el libro 'l'
// Debe liberar también la memoria de la fecha asociada
void liberarTLibro(TLibro &l){
    if(l!= NULL){
        if(l->fechaEdicion !=NULL){
            liberarTFecha(l->fechaEdicion);
        }
        delete l;
        l = NULL;
    }
}

// Retorna el isbn del libro 'l'
int isbnTLibro(TLibro l){
    if (l != NULL) {
        return l->isbn;
    }
    return 0;
}

// Retorna el titulo del libro 'l'
// El titulo retornado comparte memoria con el parámetro. 
char* tituloTLibro(TLibro l){
        return l->titulo;
    
}

// Retorna la descripción del libro 'l'
// La descripción retornada comparte memoria con el parámetro. 
char* descripcionTLibro(TLibro l){
    if (l != NULL) {
        return l->descripcion;
    }
    return NULL; 
}

// Retorna el nombre del autor del libro 'l'
// El nombre retornado comparte memoria con el parámetro. 
char* nombreAutorTLibro(TLibro l){
    if (l != NULL) {
        return l->nombreAutor;
    }
    return NULL;
}

// Retorna el apellido del autor del libro 'l'
// El apellido retornado comparte memoria con el parámetro. 
char* apellidoAutorTLibro(TLibro l){
    if (l != NULL) {
        return l->apellidoAutor;
    }
    return NULL;
}

// Retorna el id del género del libro 'l'
int idGeneroTLibro(TLibro l){
    if (l != NULL) {
        return l->idGeneroLibro;
    }
    return 0;
}

// Retorna la fecha de edición del libro 'l'.
// La fecha retornada comparte memoria con el parámetro. 
TFecha fechaEdicionTLibro(TLibro l){
    if (l != NULL) {
        return l->fechaEdicion;
    }
    return NULL;
}

// Imprime la información del libro 'l' en el siguiente formato:
// Libro <isbn> 
// Título: <título>
// Autor: <nombre autor> <apellido autor>
// Descripción: <descripcion>
// Género: <id género>
// Fecha de edición: <fecha de edición>
void imprimirTLibro(TLibro l){
    if(l == NULL) return;
    printf("Libro %d\n", l->isbn);
    printf("Título: %s\n", l->titulo);
    printf("Autor: %s %s\n", l->nombreAutor, l->apellidoAutor);
    printf("Descripción: %s\n", l->descripcion);
    printf("Género: %d\n", l->idGeneroLibro);
    printf("Fecha de edición: ");
    imprimirTFecha(l->fechaEdicion);    
}

// Retorna una copia del libro 'l' que no comparte memoria con el parámetro.
TLibro copiarTLibro(TLibro l){ 
    if (l == NULL) return NULL;
    TLibro copia = new rep_libro;
    copia->isbn = l->isbn;       
    strcpy(copia->titulo , l->titulo);
    strcpy(copia->nombreAutor , l->nombreAutor);
    strcpy(copia->apellidoAutor , l->apellidoAutor);
    strcpy(copia->descripcion , l->descripcion);
    copia->idGeneroLibro = l->idGeneroLibro;
    copia->fechaEdicion =copiarTFecha(l->fechaEdicion);;
    return copia;
}
