#include "Sala.h"
using namespace std;

Sala::Sala(string nombre, string tipoExposicion, int filas, int columnas, double precioIngreso) {
    this->nombre = nombre;
    this->tipoExposicion = tipoExposicion;
    this->filas = filas;
    this->columnas = columnas;
    this->precioIngreso = precioIngreso;
    this->estadoSala = "Activa"; 
    this->totalIngresos = 0.0;
    this->totalRecaudado = 0.0;
    
    this->matrizExposiciones = vector<vector<Exposicion>>(filas, vector<Exposicion>(columnas, Exposicion()));
}

bool Sala::instalarExposicion(Exposicion expo, int fila, int columna) {
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        matrizExposiciones[fila][columna] = expo;
        return true;
    }
    return false;
}

void Sala::actualizarEstado() {
}

bool Sala::retirarExpoPorCodigo(string codigo) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matrizExposiciones[i][j].getCodigo() == codigo) {
                matrizExposiciones[i][j] = Exposicion();
                return true;
            }
        }
    }
    return false;
}

bool Sala::buscarExposicion(string codigo) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matrizExposiciones[i][j].getCodigo() == codigo) {
                return true;
            }
        }
    }
    return false;
}

void Sala::registrarVisita() {
    totalIngresos += 1;
    totalRecaudado += precioIngreso;
}

string Sala::getEstado() {
    return estadoSala;
}

string Sala::getTipoExposicion() {
    return tipoExposicion;
}

double Sala::getPrecioIngreso() {
    return precioIngreso;
}

int Sala::getIngresosRecibidos() {
    return static_cast<int>(totalIngresos);
}

double Sala::getDineroRecaudado() {
    return totalRecaudado;
}
