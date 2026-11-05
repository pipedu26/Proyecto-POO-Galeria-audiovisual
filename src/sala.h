#ifndef SALA_H
#define SALA_H

#include <string>
#include <vector>
using namespace std;

class Sala
{
    public:
        Sala(std::string nombre, std::string tipoExposicion,int filas, int columnas, double precioIngreso);

        int calcularCapacidad();
        int calcularOcupacion();
        int calcularPosicionesDisponibles();


    private:
        string nombre;
        string tipoExposicion;
        int filas;
        int columnas;
        double precioIngreso;

        vector <Exposicion*> posiciones;
        int totalIngresos;
        double totalRecaudo;
        void actualizarEstado();    

};

#endif // SALA_H

