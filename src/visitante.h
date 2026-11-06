
#ifndef VISITANTE_H
#define VISITANTE_H

#include <string>
#include <vector>
#include "visita.h"

using namespace std;

class Visitante
{
private:
    string id;
    string nombre;
    double dineroDisponible;
    vector<Visita> historialVisitas;

public:
    Visitante(string id, string nombre, double dineroDisponible);

    string getId();
    string getNombre();
    double getDineroDisponible();
    int getCantidadTotalIngresos();
    double getDineroGastado();

    bool pagarEntrada(double precio);

    void agregarVisita(Visita visita);

    void mostrarHistorial();

    vector<Visita> consultarHistorial();
};

#endif // VISITANTE_H
