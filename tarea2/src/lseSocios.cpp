
#include "../include/lseSocios.h"

struct rep_lseSocios {
	TSocio socio;
	rep_lseSocios* sig;
};

TLSESocios crearTLSESociosVacia(TSocio socio){
	TLSESocios nuevoLseSocios = new rep_lseSocios;
	nuevoLseSocios->socio = socio;
	nuevoLseSocios->sig = NULL;
	return nuevoLseSocios;
}

bool esVaciaTLSESocios(TLSESocios lseSocios){
	if (lseSocios == NULL){
		return true;
	}
	return false;
}

void imprimirTLSESocios(TLSESocios lseSocios){
	printf("Lista de Socios:\n");
	while (lseSocios != NULL){
		imprimirTSocio(lseSocios->socio);
		lseSocios = lseSocios->sig;
	}
}

void liberarTLSESocios(TLSESocios &lseSocios){
	while (lseSocios != NULL){
		TLSESocios aux = lseSocios;
		lseSocios = lseSocios->sig;
		liberarTSocio(aux->socio);
		delete aux;
	}
	lseSocios = NULL;
}

void insTLSESocios(TLSESocios &lseSocios, TSocio socio){
	TLSESocios nuevoNodo = new rep_lseSocios;
	nuevoNodo->socio = socio;
	nuevoNodo->sig = lseSocios;
	lseSocios = nuevoNodo;
}

void insertarTLSESocios(TLSESocios &lseSocios, TSocio socio){
	if (lseSocios == NULL || fechaAltaTSocio(socio) < fechaAltaTSocio(lseSocios->socio)){
		insTLSESocios(lseSocios, socio);
	} else {
		TLSESocios actual = lseSocios;
		while(actual->sig != NULL && fechaAltaTSocio(socio) >= fechaAltaTSocio(actual->sig->socio)){
			actual = actual->sig;
		}
		insTLSESocios(actual->sig, socio);
	}
}

bool existeSocioTLSESocios(TLSESocios lseSocios, int ci){
	while (lseSocios != NULL){
		if (ci == ciTSocio(lseSocios->socio)){
			return true;
		}
	}
	return false;
}

TSocio obtenerSocioTLSESocios(TLSESocios lseSocios, int ci){
	while (lseSocios != NULL){
		if (ci == ciTSocio(lseSocios->socio)){
			return lseSocios->socio;
			}
		lseSocios = lseSocios->sig;
		}
    return NULL;
}

TSocio obtenerNesimoTLSESocios(TLSESocios lseSocios, int n){
	if (lseSocios != NULL){
		for (int i = 1; i < n; i++){
			lseSocios = lseSocios->sig;
		}
		return lseSocios->socio;
	}
	return NULL;
}

nat cantidadTLSESocios(TLSESocios lseSocios){
	nat cant = 0;
	while (lseSocios != NULL){
		cant++;
		lseSocios = lseSocios->sig;
	}
	return 0;
}

void removerSocioTLSESocios(TLSESocios &lseSocios, int ci){
	if (ci == ciTSocio(lseSocios->socio)){
		TLSESocios aux =lseSocios;
		lseSocios = lseSocios->sig;
		liberarTSocio(aux->socio);
		delete aux;
	} else {
		TLSESocios actual = lseSocios;
		while (actual->sig != NULL && ci != ciTSocio(actual->sig->socio)){
			actual = actual->sig;
		}
		if (actual->sig != NULL){
			TLSESocios aux = actual->sig;
			actual->sig = actual->sig->sig;
			liberarTSocio(aux->socio);
			delete aux;
		}
	}
}