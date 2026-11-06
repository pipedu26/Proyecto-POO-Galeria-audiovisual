#include "sala.h"
#include <iostream>
using namespace std;

Sala::Sala(string nombre, string tipoExposicion, int filas, int columnas, double precioIngreso) {
    this->nombre = nombre;
    this->tipoExposicion = tipoExposicion;
    this->filas = filas;
    this->columnas = columnas;
    this->precioIngreso = precioIngreso;
    this->estadoSala = "En construccion";   // toda sala nueva empieza vacia
    this->totalIngresos = 0;
    this->totalRecaudado = 0.0;

    // Solo se crea la matriz si las dimensiones tienen sentido.
    // (Si no, la Galeria rechaza la sala al registrarla.)
    if (filas > 0 && columnas > 0) {
        this->matrizExposiciones = vector<vector<Exposicion>>(filas, vector<Exposicion>(columnas, Exposicion()));
    }
}

// La posicion esta dentro de los limites de la sala
bool Sala::posicionValida(int fila, int columna) {
    return fila >= 0 && fila < filas && columna >= 0 && columna < columnas;
}

// La posicion no tiene ninguna exposicion (codigo vacio)
bool Sala::posicionLibre(int fila, int columna) {
    return matrizExposiciones[fila][columna].getCodigo() == "";
}

bool Sala::instalarExposicion(Exposicion expo, int fila, int columna) {
    bool instalada = false;

    if (posicionValida(fila, columna) && posicionLibre(fila, columna)
        && expo.getTipo() == tipoExposicion) {
        matrizExposiciones[fila][columna] = expo;
        actualizarEstado();
        instalada = true;
    }

    return instalada;
}

// Cuenta cuantas posiciones estan ocupadas
int Sala::contarExposiciones() {
    int cantidad = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matrizExposiciones[i][j].getCodigo() != "") {
                cantidad++;
            }
        }
    }
    return cantidad;
}

// Recalcula el estado segun cuantas posiciones estan ocupadas
void Sala::actualizarEstado() {
    int ocupadas = contarExposiciones();

    if (ocupadas == 0) {
        estadoSala = "En construccion";
    } else if (ocupadas == filas * columnas) {
        estadoSala = "Llena";
    } else {
        estadoSala = "Disponible";
    }
}

bool Sala::retirarExpoPorCodigo(string codigo) {
    bool retirada = false;
    int fila, columna;

    if (buscarExposicion(codigo, fila, columna)) {
        matrizExposiciones[fila][columna] = Exposicion();   // la casilla queda vacia
        actualizarEstado();
        retirada = true;
    }

    return retirada;
}

// Busca una exposicion por codigo. Si la encuentra, devuelve true
// y deja en fila y columna la posicion donde esta.
bool Sala::buscarExposicion(string codigo, int &fila, int &columna) {
    bool encontrada = false;
    int i = 0;

    while (i < filas && !encontrada) {
        int j = 0;
        while (j < columnas && !encontrada) {
            if (codigo != "" && matrizExposiciones[i][j].getCodigo() == codigo) {
                encontrada = true;
                fila = i;
                columna = j;
            }
            j++;
        }
        i++;
    }

    return encontrada;
}

// Recorre por filas y, dentro de cada fila, por columnas.
// Devuelve la primera posicion libre que encuentre.
bool Sala::buscarPrimeraPosicionLibre(int &fila, int &columna) {
    bool encontrada = false;
    int i = 0;

    while (i < filas && !encontrada) {
        int j = 0;
        while (j < columnas && !encontrada) {
            if (posicionLibre(i, j)) {
                encontrada = true;
                fila = i;
                columna = j;
            }
            j++;
        }
        i++;
    }

    return encontrada;
}

// Devuelve lo que hay en la posicion (si esta vacia, devuelve una Exposicion con codigo "")
Exposicion Sala::obtenerExposicion(int fila, int columna) {
    return matrizExposiciones[fila][columna];
}

void Sala::registrarVisita() {
    totalIngresos += 1;
    totalRecaudado += precioIngreso;
}

// Muestra la matriz de la sala con el codigo de cada exposicion
void Sala::mostrarDistribucion() {
    cout << "Sala: " << nombre << " (" << tipoExposicion << ") - Estado: " << estadoSala << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (posicionLibre(i, j)) {
                cout << "[ ---- ] ";
            } else {
                cout << "[ " << matrizExposiciones[i][j].getCodigo() << " ] ";
            }
        }
        cout << endl;
    }
}

string Sala::getNombre() {
    return nombre;
}

string Sala::getEstado() {
    return estadoSala;
}

string Sala::getTipoExposicion() {
    return tipoExposicion;
}

int Sala::getFilas() {
    return filas;
}

int Sala::getColumnas() {
    return columnas;
}

double Sala::getPrecioIngreso() {
    return precioIngreso;
}

// Solo cambia el precio de los ingresos futuros.
// Lo ya recaudado y el historial de los visitantes no se tocan.
void Sala::setPrecioIngreso(double nuevoPrecio) {
    precioIngreso = nuevoPrecio;
}

int Sala::getIngresosRecibidos() {
    return totalIngresos;
}

double Sala::getDineroRecaudado() {
    return totalRecaudado;
}
