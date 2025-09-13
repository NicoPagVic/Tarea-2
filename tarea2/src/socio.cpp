#include "../include/socio.h"

struct GeneroFav{
    int generoFavorito[MAX_GENEROS_FAVORITOS];
    int tope;
};

struct rep_socio {
    int ci;
    char nombre[MAX_NOMBRE_SOCIO];
    char apellido[MAX_APELLIDO_SOCIO];
    int generoFavorito[MAX_GENEROS_FAVORITOS];
    TFecha fechaAlta;
    GeneroFav GF;
};
 
TSocio crearTSocio(int ci, const char nombre[MAX_NOMBRE_SOCIO], const char apellido[MAX_APELLIDO_SOCIO], nat diaAlta, nat mesAlta, nat anioAlta){
    TSocio nuevoSocio; new rep_socio;
    nuevoSocio->ci = ci;    
    strcpy(nuevoSocio->nombre, nombre);
    strcpy(nuevoSocio->apellido, apellido);
    nuevoSocio->fechaAlta = crearTFecha(diaAlta, mesAlta, anioAlta);
    nuevoSocio->GF.tope = 0;
    for (int i = 0; i < MAX_GENEROS_FAVORITOS; i++){
        nuevoSocio->GF.generoFavorito[i] = 0;
    }
    return nuevoSocio;
}

void imprimirTSocio(TSocio socio){
    printf("socio %d: %s %s\n", socio->ci, socio->nombre, socio->apellido);
    printf("Fecha de alta: ");
    imprimirTFecha(socio->fechaAlta);
    printf("Generos favoritos: ");
    for (int i = 0; i < MAX_GENEROS_FAVORITOS; i++){
        if (socio->GF.generoFavorito[i] != 0){
            printf("%d ", socio->GF.generoFavorito[i]);
        }
    }
    printf("\n");
}

void liberarTSocio(TSocio &socio){
    if (socio != NULL){
        delete socio;
        socio = NULL;
    }
}

int ciTSocio(TSocio socio){
    if (socio != NULL) {
        return socio->ci;
    }
    return 0;
}

char* nombreTSocio(TSocio socio){
    if (socio != NULL) {
        return socio->nombre;
    }
    return NULL;
}

char* apellidoTSocio(TSocio socio){
    if (socio != NULL) {
        return socio->apellido;
    }
    return NULL;
}

TFecha fechaAltaTSocio(TSocio socio){
    if (socio != NULL) {
        return socio->fechaAlta;
    }
    return NULL;
}

void agregarGeneroFavoritoTSocio(TSocio &socio, int idGenero){
    for (int i = 0; i < MAX_GENEROS_FAVORITOS; i++){
        if (socio->GF.generoFavorito[i] == 0){
            socio->GF.generoFavorito[i] = idGenero;
            socio->GF.tope++;
            break;
        }
    }
}

bool tieneGeneroFavoritoTSocio(TSocio socio, int idGenero){
    for (int i = 0; i < MAX_GENEROS_FAVORITOS; i++){
        if (socio->GF.generoFavorito[i] == idGenero){
            return true;
        }
    }
    return false;
}

int cantidadGenerosFavoritosTSocio(TSocio socio){
    if (socio->GF.tope <= MAX_GENEROS_FAVORITOS){
        return socio->GF.tope;
    }
    return 0;
}

TSocio copiarTSocio(TSocio socio){
    if (socio != NULL){
        TSocio copia = new rep_socio;
        copia->ci = socio->ci;
        strcpy(copia->nombre, socio->nombre);
        strcpy(copia->apellido, socio->apellido);
        copia->fechaAlta = copiarTFecha(socio->fechaAlta);
        copia->GF.tope = socio->GF.tope;
        for (int i = 0; i < MAX_GENEROS_FAVORITOS; i++){
            copia->GF.generoFavorito[i] = socio->GF.generoFavorito[i];
        }
        return copia;
    }
    return NULL;
}
