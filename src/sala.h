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
        vector <Exposicion*> posiciones;
    
    public:
        Sala(string nombre, string tipoExposicion,int filas, int columnas, double precioIngreso);

        int calcularCapacidad();
        int calcularOcupacion();
        int calcularPosicionesDisponibles();
 

};

#endif // SALA_H

