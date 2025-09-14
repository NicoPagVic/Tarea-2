
#include "../include/prestamo.h"

struct rep_prestamo {
  TSocio socio;
  TLibro libro;
  TFecha fechaRetiro;
  TFecha fechaDevolucion;  
};

TPrestamo crearTPrestamo(TSocio socio, TLibro libro, TFecha fechaRetiro){
  TPrestamo nuevoPrestamo = new rep_prestamo;
  nuevoPrestamo->socio = socio;
  nuevoPrestamo->libro = libro;
  nuevoPrestamo->fechaRetiro = fechaRetiro;
  nuevoPrestamo->fechaDevolucion = NULL;
  return nuevoPrestamo;
}
 
void imprimirTPrestamo(TPrestamo prestamo){
  printf("Préstamo de libro %s a %s %s.\n", tituloTLibro(prestamo->libro), nombreTSocio(prestamo->socio), apellidoTSocio(prestamo->socio));
  imprimirTFecha(prestamo->fechaRetiro);
  if (prestamo->fechaDevolucion != NULL) {
    imprimirTFecha(prestamo->fechaDevolucion);
  } else {
    printf("No retornado\n");
  }
}

void liberarTPrestamo(TPrestamo &prestamo){
  if (prestamo != NULL){
    liberarTSocio(prestamo->socio);
    liberarTLibro(prestamo->libro);
    liberarTFecha(prestamo->fechaRetiro);
    liberarTFecha(prestamo->fechaDevolucion);
    delete prestamo;
    prestamo = NULL;
  }
}

TSocio socioTPrestamo(TPrestamo prestamo){
  if (prestamo != NULL) {
    return prestamo->socio;
  }
  return NULL;
}
 
TFecha fechaRetiroTPrestamo(TPrestamo prestamo){
  if (prestamo != NULL) {
    return prestamo->fechaRetiro;
  }
  return NULL;
}

TFecha fechaDevolucionTPrestamo(TPrestamo prestamo){
  if (prestamo != NULL) {
    return prestamo->fechaDevolucion;
  }
  return NULL;
}

TLibro libroTPrestamo(TPrestamo prestamo){
  if (prestamo != NULL) {
    return prestamo->libro;
  }
  return NULL;
}

bool fueRetornadoTPrestamo(TPrestamo prestamo){
  if (prestamo != NULL && prestamo->fechaDevolucion != NULL) {
    return true;
  }
  return false;
}

void actualizarFechaDevolucionTPrestamo(TPrestamo prestamo, TFecha fechaDevolucion){
  if (prestamo != NULL) {
    if (prestamo->fechaDevolucion != NULL){
      liberarTFecha(prestamo->fechaDevolucion);
    } 
      prestamo->fechaDevolucion = fechaDevolucion;
  }
}


TPrestamo copiarTPrestamo(TPrestamo prestamo){
  if (prestamo != NULL) {
    TPrestamo copia = new rep_prestamo;
    copia->socio = prestamo->socio;
    copia->libro = prestamo->libro;
    copia->fechaRetiro = prestamo->fechaRetiro;
    if (prestamo->fechaDevolucion != NULL) {
      copia->fechaDevolucion = prestamo->fechaDevolucion;
    } 
    else {
      copia->fechaDevolucion = NULL; 
    }
  return NULL;
  }
}