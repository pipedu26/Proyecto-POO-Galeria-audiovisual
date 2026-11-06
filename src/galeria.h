#ifndef GALERIA_H
#define GALERIA_H

#include <vector>
#include <string>
#include "sala.h"
#include "visitante.h"
#include "exposicion.h"

class Galeria {
private:
    std::vector<Sala> salas;
    std::vector<Visitante> visitantes;

    // Metodos de apoyo: devuelven la posicion en el vector, o -1 si no existe
    int buscarIndiceSala(std::string nombreSala);
    int buscarIndiceVisitante(std::string idVisitante);
    int buscarSalaDeExposicion(std::string codigoExpo, int &fila, int &columna);
    std::string obtenerFechaHora();

public:
    Galeria();

    // Registro
    bool registrarSala(Sala nuevaSala);
    bool registrarVisitante(Visitante nuevoVisitante);

    // Distribucion de exposiciones
    bool instalarExposicion(Exposicion expo, std::string nombreSala, int fila, int columna);
    bool retirarExposicion(std::string codigoExpo);
    bool trasladarExposicion(std::string codigoExpo, std::string nombreSalaDestino);

    // Visitantes y precios
    bool autorizarIngreso(std::string idVisitante, std::string nombreSala);
    bool cambiarPrecioSala(std::string nombreSala, double nuevoPrecio);

    // Consultas
    int getCantidadSalas();
    void mostrarSalasPorTipo(std::string tipo);
    void mostrarSalasPorEstado(std::string estado);
    int getCantidadExposiciones();
    int getCantidadExposicionesPorTipo(std::string tipo);
    void mostrarSalaConMasExposiciones();
    void mostrarSalaConMasIngresos();
    void mostrarSalaConMasRecaudo();
    double getRecaudoTotal();
    void localizarExposicion(std::string codigoExpo);
    void consultarPosicion(std::string nombreSala, int fila, int columna);
    void mostrarSala(std::string nombreSala);
    void mostrarVisitante(std::string idVisitante);
};

#endif // GALERIA_H
