
#include "Exposicion.h"

Exposicion::Exposicion(std::string codigo, std::string nombre,
                       std::string autor, std::string tipo,
                       std::string descripcion)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->autor = autor;
    this->tipo = tipo;
    this->descripcion = descripcion;
}

std::string Exposicion::getCodigo()
{
    return codigo;
}

std::string Exposicion::getNombre()
{
    return nombre;
}

std::string Exposicion::getAutor()
{
    return autor;
}

std::string Exposicion::getTipo()
{
    return tipo;
}

std::string Exposicion::getDescripcion()
{
    return descripcion;
}

