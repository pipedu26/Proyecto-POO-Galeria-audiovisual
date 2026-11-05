#ifndef SALA_H
#define SALA_H

#include <string>
#include <vector>
#include "Exposicion.h"
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
        double totalRecaudo;
        void actualizarEstado();  
        vector <Exposicion*> matrizExposiciones;
    
    public:
        Sala(string nombre, string tipoExposicion, int filas, int columnas, double precioIngreso);

        bool instalarExposicion(Exposicion expo, int fila, int columna); 
        void actualizarEstado();
        bool retirarExpoPorCodigo(string codigo);
        bool buscarExposicion(string codigo);
        void registrarVisita();
        string getEstado();
        string getTipoExposicion();
        double getPrecioIngreso();
        int getIngresosRecibidos();
        double getDineroRecaudado();
        
};

#endif // SALA_H

