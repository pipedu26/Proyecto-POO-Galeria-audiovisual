
#ifndef EXPOSICION_H
#define EXPOSICION_H

#include <string>
using namespace std;

class Exposicion
{
private:
    string codigo;
    string nombre;
    string autor;
    string tipo;
    string descripcion;

public:
    Exposicion(string codigo, string nombre,
               string autor, string tipo,
               string descripcion);

    string getCodigo();
    string getNombre();
    string getAutor();
    string getTipo();
    string getDescripcion();
};

#endif // EXPOSICION_H

