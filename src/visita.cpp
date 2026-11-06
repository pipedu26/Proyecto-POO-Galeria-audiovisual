#include "visita.h"
using namespace std;

Visita::Visita() {
    this->nombreSala = "";
    this->precioPagado = 0.0;
    this->fechaHora = "";
}

Visita::Visita(string nombreSala, double precioPagado, string fechaHora) {
    this->nombreSala = nombreSala;
    this->precioPagado = precioPagado;
    this->fechaHora = fechaHora;
}

string Visita::getNombreSala() {
    return nombreSala;
}

double Visita::getPrecioPagado() {
    return precioPagado;
}

string Visita::getFechaHora() {
    return fechaHora;
}
