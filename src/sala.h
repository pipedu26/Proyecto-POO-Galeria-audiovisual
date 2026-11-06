#ifndef SALA_H
#define SALA_H

#include <string>
#include <vector>
#include "exposicion.h"
using namespace std;

class Sala
{
    private:
        string nombre;
        string tipoExposicion;
        int filas;
        int columnas;
        double precioIngreso;
        string estadoSala;
        int totalIngresos;
        double totalRecaudado;
        // Cada casilla guarda una Exposicion. Si su codigo es "" la casilla esta vacia.
        vector<vector<Exposicion>> matrizExposiciones;

    public:
        Sala(string nombre, string tipoExposicion, int filas, int columnas, double precioIngreso);

        bool instalarExposicion(Exposicion expo, int fila, int columna);
        void actualizarEstado();
        bool retirarExpoPorCodigo(string codigo);
        bool buscarExposicion(string codigo, int &fila, int &columna);
        bool posicionValida(int fila, int columna);
        bool posicionLibre(int fila, int columna);
        bool buscarPrimeraPosicionLibre(int &fila, int &columna);
        Exposicion obtenerExposicion(int fila, int columna);
        int contarExposiciones();
        void registrarVisita();
        void mostrarDistribucion();

        string getNombre();
        string getEstado();
        string getTipoExposicion();
        int getFilas();
        int getColumnas();
        double getPrecioIngreso();
        void setPrecioIngreso(double nuevoPrecio);
        int getIngresosRecibidos();
        double getDineroRecaudado();
};

#endif // SALA_H
