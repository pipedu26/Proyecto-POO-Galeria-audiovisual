
#include "exposicion.h"
using namespace std;

Exposicion::Exposicion()
{
    this->codigo = "";
    this->nombre = "";
    this->autor = "";
    this->tipo = "";
    this->descripcion = "";
}

Exposicion::Exposicion(string codigo, string nombre,
                       string autor, string tipo,
                       string descripcion)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->autor = autor;
    this->tipo = tipo;
    this->descripcion = descripcion;
}

string Exposicion::getCodigo()
{
    return codigo;
}

string Exposicion::getNombre()
{
    return nombre;
}

string Exposicion::getAutor()
{
    return autor;
}

string Exposicion::getTipo()
{
    return tipo;
}

string Exposicion::getDescripcion()
{
    return descripcion;
}
