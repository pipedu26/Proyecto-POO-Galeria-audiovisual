#ifndef GALERIA_H
#define GALERIA_H

#include <vector>
#include <string>
#include "Sala.h"
#include "Visitante.h"
#include "Exposicion.h"

class Galeria {
private:
    std::vector<Sala> salas;
    std::vector<Visitante> visitantes;

public:
    Galeria();

    bool registrarSala(Sala nuevaSala);
    bool registrarVisitante(Visitante nuevoVisitante);
    bool instalarExposicion(Exposicion expo, std::string nombreSala, int fila, int columna);
    bool retirarExposicion(std::string codigoExpo);
    bool transladarExposicion(std::string codigoExpo, std::string nombreSalaDestino);
    bool autorizarIngreso(std::string idVisitante, std::string nombreSala);
};

#endif // GALERIA_H
