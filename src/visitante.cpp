
#include "visitante.h"
#include <iostream>

using namespace std;

// Constructor
Visitante::Visitante(string id, string nombre, double dineroDisponible)
{
    this->id = id;
    this->nombre = nombre;
    this->dineroDisponible = dineroDisponible;
}

// Consultar identificacion
string Visitante::getId()
{
    return id;
}

// Consultar nombre
string Visitante::getNombre()
{
    return nombre;
}

// Consultar dinero disponible
double Visitante::getDineroDisponible()
{
    return dineroDisponible;
}

// Cantidad total de ingresos = cantidad de visitas en el historial
int Visitante::getCantidadTotalIngresos()
{
    return historialVisitas.size();
}

// Dinero gastado = suma de lo que se pago en cada visita
double Visitante::getDineroGastado()
{
    double total = 0.0;
    for (int i = 0; i < (int)historialVisitas.size(); i++)
    {
        total += historialVisitas[i].getPrecioPagado();
    }
    return total;
}

// Realizar el pago de una entrada
bool Visitante::pagarEntrada(double precio)
{
    bool pagado = false;

    if (precio > 0 && dineroDisponible >= precio)
    {
        dineroDisponible -= precio;
        pagado = true;
    }

    return pagado;
}

// Agregar una visita al historial
void Visitante::agregarVisita(Visita visita)
{
    historialVisitas.push_back(visita);
}

// Consultar historial de visitas
vector<Visita> Visitante::consultarHistorial()
{
    return historialVisitas;
}

// Mostrar historial de visitas
void Visitante::mostrarHistorial()
{
    cout << "\n--- HISTORIAL DE VISITAS ---" << endl;
    cout << "Visitante: " << nombre << endl;
    cout << "Identificacion: " << id << endl;

    if (historialVisitas.empty())
    {
        cout << "No hay visitas registradas." << endl;
    }
    else
    {
        for (int i = 0; i < (int)historialVisitas.size(); i++)
        {
            cout << "\nVisita #" << i + 1 << endl;
            cout << "Sala: " << historialVisitas[i].getNombreSala() << endl;
            cout << "Fecha y hora: " << historialVisitas[i].getFechaHora() << endl;
            cout << "Precio pagado: $" << historialVisitas[i].getPrecioPagado() << endl;
        }
    }

    cout << "\nCantidad total de ingresos: " << getCantidadTotalIngresos() << endl;
    cout << "Dinero gastado: $" << getDineroGastado() << endl;
    cout << "Dinero disponible: $" << dineroDisponible << endl;
}
