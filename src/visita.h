#ifndef VISITA_H
#define VISITA_H

#include <string>

class Visita {
    private:
        string nombreSala;
        double precioPagado;
        string fechaHora;

    public:
        Visita();
        Visita(string nombreSala, double precioPagado, string fechaHora);

        string getNombreSala();
        double getPrecioPagado();
        string getFechaHora();
};

#endif
