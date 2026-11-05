#include "Galeria.h"

Galeria::Galeria() {
}

bool Galeria::registrarSala(Sala nuevaSala) {
    bool exito = true;
    
    salas.push_back(nuevaSala);
    
    return exito;
}

bool Galeria::registrarVisitante(Visitante nuevoVisitante) {
    bool exito = true;
    
    visitantes.push_back(nuevoVisitante);
    
    return exito;
}

bool Galeria::instalarExposicion(Exposicion expo, std::string nombreSala, int fila, int columna) {
    bool instalado = false;
    bool salaEncontrada = false;
    unsigned int i = 0;
    
    while (i < salas.size() && !salaEncontrada) {
        if (salas[i].getNombre() == nombreSala) {
            salaEncontrada = true;
            instalado = salas[i].instalarExposicion(expo, fila, columna);
        }
        i++;
    }
    
    return instalado;
}

bool Galeria::retirarExposicion(std::string codigoExpo) {
    bool retirado = false;
    unsigned int i = 0;
    
    while (i < salas.size() && !retirado) {
        if (salas[i].retirarExpoPorCodigo(codigoExpo)) {
            retirado = true;
        }
        i++;
    }
    
    return retirado;
}

bool Galeria::transladarExposicion(std::string codigoExpo, std::string nombreSalaDestino) {
    bool transladado = false;
    bool encontradaEnOrigen = false;
    bool salaDestinoLista = false;
 
    unsigned int i = 0;
    while (i < salas.size() && (!encontradaEnOrigen || !salaDestinoLista)) {
 
        i++;
    }

    return transladado;
}
bool Galeria::autorizarIngreso(std::string idVisitante, std::string nombreSala) {
    bool autorizado = false;
    bool visitanteEncontrado = false;
    unsigned int i = 0;

    while (i < visitantes.size() && !visitanteEncontrado) {
        if (visitantes[i].getId() == idVisitante) {
            visitanteEncontrado = true;
            
      
            autorizado = true; 
        }
        i++;
    }
    
    return autorizado;
}
