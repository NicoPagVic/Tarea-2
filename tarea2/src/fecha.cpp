#include "../include/fecha.h"

struct rep_fecha {
    /************ Parte 2.1 ************/
    /*Escriba el código a continuación */
    nat dia, mes, anio;
    /****** Fin de parte Parte 2.1 *****/
};

TFecha crearTFecha(nat dia, nat mes, nat anio) {
    /************ Parte 3.1 ************/
    /*Escriba el código a continuación */
    TFecha nuevaFecha = new rep_fecha;
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;
    /****** Fin de parte Parte 3.1 *****/
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha) {
    /************ Parte 3.3 ************/
    /*Escriba el código a continuación */
    if (fecha != NULL){
        delete fecha;
    fecha = NULL;
    }
    
    /****** Fin de parte Parte 3.3 *****/
}
void imprimirTFecha(TFecha fecha) {
    /************ Parte 3.5 ************/
    /*Escriba el código a continuación */
    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);

    /****** Fin de parte Parte 3.5 *****/
}

TFecha copiarTFecha(TFecha fecha) {
    /************ Parte 3.9 ************/
    /*Escriba el código a continuación */
    /*Recuerde que las funciones auxiliares
     deben declararse antes de ser utilizadas*/
    TFecha copia = new rep_fecha;
    copia->dia = fecha->dia;
    copia->mes = fecha->mes;
    copia->anio = fecha->anio;
 
    return copia;
    /****** Fin de parte Parte 3.9 *****/
}
    /************ Implementacion de funciones Auxiliares ************/
bool esBisiesto(nat anio){
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

nat diasMes(nat mes, nat anio) {
    if (mes == 2) {
        if (esBisiesto(anio))
            return 29;
         else 
            return 28;
        }

    else if (mes <= 7) {
        if (mes % 2 == 1)
            return 31;
        else
            return 30;
    }

    else if (mes % 2 == 0) {
            return 31; }
        else {
            return 30;
    }
    
}

void aumentarTFecha(TFecha &fecha, nat dias) {
    /************ Parte 3.10 ************/
    /*Escriba el código a continuación */
    fecha->dia += dias;
    while (fecha->dia > diasMes(fecha->mes, fecha->anio)) {
        fecha->dia -= diasMes(fecha->mes, fecha->anio);
        fecha->mes++;
        if (fecha->mes > 12) {
            fecha->mes = 1;
            fecha->anio++;
        }
    }
    /****** Fin de parte Parte 3.10 *****/
}

int compararTFechas(TFecha fecha1, TFecha fecha2) {
    /************ Parte 3.11 ************/
    /*Escriba el código a continuación */
    /*Comp de Años*/
    if (fecha1->anio > fecha2->anio) {
        return 1; // fecha1 es más reciente
    } else if (fecha1->anio < fecha2->anio) {
        return -1; } // fecha1 es más antigua
    /*Comp de Meses*/
    if (fecha1->mes > fecha2->mes) {
        return 1;
    } else if (fecha1->mes < fecha2->mes) {
        return -1; }

    /*comp de Dias*/
    if (fecha1->dia > fecha2->dia) {
        return 1;
    } else if (fecha1->dia < fecha2->dia) {
        return -1; }


        return 0;

    /****** Fin de parte Parte 3.11 *****/
}
