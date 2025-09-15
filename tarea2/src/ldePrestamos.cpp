#include "../include/ldePrestamos.h"

struct nodoDoble{
    TPrestamo prestamo;
    nodoDoble* sig;
    nodoDoble* ant;
};

struct rep_ldePrestamos {
    nodoDoble* primero;
    nodoDoble* ultimo;
    nat cantidad;;
};

TLDEPrestamos crearTLDEPrestamosVacia(){
    TLDEPrestamos nuevoTLDEPrestamos = new rep_ldePrestamos;
    nuevoTLDEPrestamos->primero = NULL;
    nuevoTLDEPrestamos->ultimo = NULL;
    nuevoTLDEPrestamos->cantidad = 0;
    return nuevoTLDEPrestamos;
}

void insertarTLDEPrestamos(TLDEPrestamos &ldePrestamos, TPrestamo prestamo){
    if (ldePrestamos->primero == NULL) {
        nodoDoble* nuevoNodo = new nodoDoble;
        nodoDoble* actual = ldePrestamos->primero;
        nuevoNodo->prestamo = prestamo;
        nuevoNodo->sig = NULL;
        nuevoNodo->ant = NULL;
        ldePrestamos->primero = nuevoNodo;
        ldePrestamos->ultimo = nuevoNodo;
        ldePrestamos->cantidad++;
    } else {
        nodoDoble* nuevoNodo = new nodoDoble;
        nodoDoble* actual = ldePrestamos->primero;
        nuevoNodo->prestamo = prestamo;
        nuevoNodo->sig = NULL;
        nuevoNodo->ant = NULL;
        while (actual != NULL && fechaRetiroTPrestamo(actual->prestamo) <= fechaRetiroTPrestamo(prestamo)) {
            actual = actual->sig;
        }
        if (actual == ldePrestamos->primero) {
            nuevoNodo->sig = ldePrestamos->primero;
            ldePrestamos->primero->ant = nuevoNodo;
            ldePrestamos->primero = nuevoNodo;
        } else if (actual == NULL) {
            nuevoNodo->ant = ldePrestamos->ultimo;
            ldePrestamos->ultimo->sig = nuevoNodo;
            ldePrestamos->ultimo = nuevoNodo;
        } else {
            nuevoNodo->sig = actual;
            nuevoNodo->ant = actual->ant;
            actual->ant->sig = nuevoNodo;
            actual->ant = nuevoNodo;
        }
        ldePrestamos->cantidad++;
    }
}

void liberarTLDEPrestamos(TLDEPrestamos &ldePrestamos){
    nodoDoble* actual = ldePrestamos->primero;
    while (actual != NULL) {
        nodoDoble* siguiente = actual->sig;
        liberarTPrestamo(actual->prestamo);
        delete actual;
        actual = siguiente;
    }
}

void imprimirTLDEPrestamos(TLDEPrestamos ldePrestamos){
    printf("LDE Préstamos:\n");
    nodoDoble* actual = ldePrestamos->primero;
    while (actual != NULL) {
        imprimirTPrestamo(actual->prestamo);
        actual = actual->sig;
    }
}

void imprimirInvertidoTLDEPrestamos(TLDEPrestamos ldePrestamos){
    printf("LDE Préstamos:\n");
    nodoDoble* actual = ldePrestamos->ultimo;
    while (actual != NULL) {
        imprimirTPrestamo(actual->prestamo);
        actual = actual->ant;
    }
}

nat cantidadTLDEPrestamos(TLDEPrestamos ldePrestamos){
    if (ldePrestamos != NULL) {
        return ldePrestamos->cantidad;
    }
    return 0;
}

TPrestamo obtenerPrimeroTLDEPrestamos(TLDEPrestamos ldePrestamos){
    if (ldePrestamos != NULL && ldePrestamos->primero != NULL) {
        return ldePrestamos->primero->prestamo;
    }
    return NULL;
}

TPrestamo obtenerUltimoTLDEPrestamos(TLDEPrestamos ldePrestamos){
    if (ldePrestamos != NULL && ldePrestamos->ultimo != NULL) {
        return ldePrestamos->ultimo->prestamo;
    }
    return NULL;
}

TPrestamo obtenerNesimoTLDEPrestamos(TLDEPrestamos &ldePrestamos, int n){
    if (ldePrestamos != NULL && n > 0 && n <= ldePrestamos->cantidad) {
        nodoDoble* actual = ldePrestamos->primero;
        for (int i = 1; i < n; i++) {
            actual = actual->sig;
        }
        return actual->prestamo;
    }
    return NULL;
}

// criterio = 0 -> prestamos retornados
// criterio = 1 -> prestamos no retornados
TLDEPrestamos filtrarPrestamosTLDEPrestamos(TLDEPrestamos &ldePrestamos, int criterio){
    TLDEPrestamos nuevaLDE = crearTLDEPrestamosVacia();
    nodoDoble* actual = ldePrestamos->primero;
    while (actual != NULL) {
        if ((criterio == 0 && fueRetornadoTPrestamo(actual->prestamo)) || 
            (criterio == 1 && !fueRetornadoTPrestamo(actual->prestamo))) {
            TPrestamo prestamoCopia = copiarTPrestamo(actual->prestamo);
            insertarTLDEPrestamos(nuevaLDE, prestamoCopia);
        }
        actual = actual->sig;
    }
    return nuevaLDE;
}
