
#ifndef EXPOSICION_H
#define EXPOSICION_H

#include <string>

class Exposicion
{
private:
    std::string codigo;
    std::string nombre;
    std::string autor;
    std::string tipo;
    std::string descripcion;

public:
    Exposicion(std::string codigo, std::string nombre,
               std::string autor, std::string tipo,
               std::string descripcion);

    std::string getCodigo();
    std::string getNombre();
    std::string getAutor();
    std::string getTipo();
    std::string getDescripcion();
};

#endif // EXPOSICION_H

