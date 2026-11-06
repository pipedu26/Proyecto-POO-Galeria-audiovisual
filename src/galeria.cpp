#include "galeria.h"
#include <iostream>
#include <ctime>
using namespace std;

Galeria::Galeria() {
}

// ===================== METODOS DE APOYO (privados) =====================

// Devuelve el indice de la sala en el vector, o -1 si no existe
int Galeria::buscarIndiceSala(string nombreSala) {
    int indice = -1;
    unsigned int i = 0;

    while (i < salas.size() && indice == -1) {
        if (salas[i].getNombre() == nombreSala) {
            indice = i;
        }
        i++;
    }

    return indice;
}

// Devuelve el indice del visitante en el vector, o -1 si no existe
int Galeria::buscarIndiceVisitante(string idVisitante) {
    int indice = -1;
    unsigned int i = 0;

    while (i < visitantes.size() && indice == -1) {
        if (visitantes[i].getId() == idVisitante) {
            indice = i;
        }
        i++;
    }

    return indice;
}

// Busca en que sala esta instalada una exposicion.
// Devuelve el indice de la sala (o -1) y deja la posicion en fila y columna.
int Galeria::buscarSalaDeExposicion(string codigoExpo, int &fila, int &columna) {
    int indice = -1;
    unsigned int i = 0;

    while (i < salas.size() && indice == -1) {
        if (salas[i].buscarExposicion(codigoExpo, fila, columna)) {
            indice = i;
        }
        i++;
    }

    return indice;
}

// Fecha y hora actual del computador, en texto. Ej: 2026-11-05 22:40:15
string Galeria::obtenerFechaHora() {
    time_t ahora = time(0);
    char texto[20];
    strftime(texto, sizeof(texto), "%Y-%m-%d %H:%M:%S", localtime(&ahora));
    return string(texto);
}

// ============================ REGISTRO ============================

bool Galeria::registrarSala(Sala nuevaSala) {
    bool exito = false;

    if (buscarIndiceSala(nuevaSala.getNombre()) != -1) {
        cout << "Error: ya existe una sala llamada '" << nuevaSala.getNombre() << "'." << endl;
    } else if (nuevaSala.getFilas() <= 0 || nuevaSala.getColumnas() <= 0) {
        cout << "Error: las filas y columnas de la sala deben ser mayores que 0." << endl;
    } else if (nuevaSala.getPrecioIngreso() <= 0) {
        cout << "Error: el precio de ingreso debe ser mayor que 0." << endl;
    } else {
        salas.push_back(nuevaSala);
        exito = true;
        cout << "Sala '" << nuevaSala.getNombre() << "' registrada." << endl;
    }

    return exito;
}

bool Galeria::registrarVisitante(Visitante nuevoVisitante) {
    bool exito = false;

    if (buscarIndiceVisitante(nuevoVisitante.getId()) != -1) {
        cout << "Error: ya existe un visitante con identificacion " << nuevoVisitante.getId() << "." << endl;
    } else if (nuevoVisitante.getDineroDisponible() < 0) {
        cout << "Error: el dinero disponible no puede ser negativo." << endl;
    } else {
        visitantes.push_back(nuevoVisitante);
        exito = true;
        cout << "Visitante '" << nuevoVisitante.getNombre() << "' registrado." << endl;
    }

    return exito;
}

// ==================== DISTRIBUCION DE EXPOSICIONES ====================

bool Galeria::instalarExposicion(Exposicion expo, string nombreSala, int fila, int columna) {
    bool instalado = false;
    int filaActual, columnaActual;
    int indiceSala = buscarIndiceSala(nombreSala);

    // Primero se valida todo. Solo si todo esta bien se instala.
    if (expo.getCodigo() == "") {
        cout << "Error: la exposicion no tiene codigo." << endl;
    } else if (indiceSala == -1) {
        cout << "Error: la sala '" << nombreSala << "' no existe." << endl;
    } else if (buscarSalaDeExposicion(expo.getCodigo(), filaActual, columnaActual) != -1) {
        cout << "Error: la exposicion " << expo.getCodigo() << " ya esta instalada en otro lugar de la galeria." << endl;
    } else if (!salas[indiceSala].posicionValida(fila, columna)) {
        cout << "Error: la posicion (" << fila << ", " << columna << ") esta fuera de los limites de la sala." << endl;
    } else if (!salas[indiceSala].posicionLibre(fila, columna)) {
        cout << "Error: la posicion (" << fila << ", " << columna << ") ya esta ocupada." << endl;
    } else if (expo.getTipo() != salas[indiceSala].getTipoExposicion()) {
        cout << "Error: la exposicion es de tipo '" << expo.getTipo() << "' y la sala solo recibe '"
             << salas[indiceSala].getTipoExposicion() << "'." << endl;
    } else {
        instalado = salas[indiceSala].instalarExposicion(expo, fila, columna);
        cout << "Exposicion " << expo.getCodigo() << " instalada en '" << nombreSala
             << "' posicion (" << fila << ", " << columna << ")." << endl;
    }

    return instalado;
}

bool Galeria::retirarExposicion(string codigoExpo) {
    bool retirado = false;
    unsigned int i = 0;

    while (i < salas.size() && !retirado) {
        if (salas[i].retirarExpoPorCodigo(codigoExpo)) {
            retirado = true;
            cout << "Exposicion " << codigoExpo << " retirada de '" << salas[i].getNombre() << "'." << endl;
        }
        i++;
    }

    if (!retirado) {
        cout << "Error: no hay ninguna exposicion instalada con el codigo " << codigoExpo << "." << endl;
    }

    return retirado;
}

bool Galeria::trasladarExposicion(string codigoExpo, string nombreSalaDestino) {
    bool trasladado = false;
    int filaOrigen, columnaOrigen;
    int filaDestino, columnaDestino;
    int indiceOrigen = buscarSalaDeExposicion(codigoExpo, filaOrigen, columnaOrigen);
    int indiceDestino = buscarIndiceSala(nombreSalaDestino);

    // Primero se comprueba que el traslado se pueda completar.
    if (indiceOrigen == -1) {
        cout << "Error: no hay ninguna exposicion instalada con el codigo " << codigoExpo << "." << endl;
    } else if (indiceDestino == -1) {
        cout << "Error: la sala destino '" << nombreSalaDestino << "' no existe." << endl;
    } else if (indiceOrigen == indiceDestino) {
        cout << "Error: la exposicion " << codigoExpo << " ya esta en la sala '" << nombreSalaDestino << "'." << endl;
    } else {
        Exposicion expo = salas[indiceOrigen].obtenerExposicion(filaOrigen, columnaOrigen);

        if (expo.getTipo() != salas[indiceDestino].getTipoExposicion()) {
            cout << "Error: la sala '" << nombreSalaDestino << "' solo recibe '"
                 << salas[indiceDestino].getTipoExposicion() << "' y la exposicion es '" << expo.getTipo() << "'." << endl;
        } else if (!salas[indiceDestino].buscarPrimeraPosicionLibre(filaDestino, columnaDestino)) {
            cout << "Error: la sala '" << nombreSalaDestino << "' no tiene posiciones disponibles." << endl;
        } else {
            // Todo se puede hacer: ahora si se modifica la distribucion.
            salas[indiceOrigen].retirarExpoPorCodigo(codigoExpo);
            salas[indiceDestino].instalarExposicion(expo, filaDestino, columnaDestino);
            trasladado = true;
            cout << "Exposicion " << codigoExpo << " trasladada de '" << salas[indiceOrigen].getNombre()
                 << "' a '" << nombreSalaDestino << "' posicion (" << filaDestino << ", " << columnaDestino << ")." << endl;
        }
    }

    return trasladado;
}

// ======================= VISITANTES Y PRECIOS =======================

bool Galeria::autorizarIngreso(string idVisitante, string nombreSala) {
    bool autorizado = false;
    int indiceVisitante = buscarIndiceVisitante(idVisitante);
    int indiceSala = buscarIndiceSala(nombreSala);

    // Primero se valida todo, sin cambiar nada.
    if (indiceVisitante == -1) {
        cout << "Error: el visitante con identificacion " << idVisitante << " no esta registrado." << endl;
    } else if (indiceSala == -1) {
        cout << "Error: la sala '" << nombreSala << "' no existe." << endl;
    } else if (salas[indiceSala].getEstado() == "En construccion") {
        cout << "Error: la sala '" << nombreSala << "' esta en construccion y no recibe visitantes." << endl;
    } else if (visitantes[indiceVisitante].getDineroDisponible() < salas[indiceSala].getPrecioIngreso()) {
        cout << "Error: " << visitantes[indiceVisitante].getNombre() << " no tiene dinero suficiente. Tiene $"
             << visitantes[indiceVisitante].getDineroDisponible() << " y la entrada cuesta $"
             << salas[indiceSala].getPrecioIngreso() << "." << endl;
    } else {
        // Todo esta bien: se hacen los 4 pasos del ingreso.
        double precio = salas[indiceSala].getPrecioIngreso();

        visitantes[indiceVisitante].pagarEntrada(precio);                 // 1. cobrar
        Visita nuevaVisita(nombreSala, precio, obtenerFechaHora());
        visitantes[indiceVisitante].agregarVisita(nuevaVisita);           // 2. historial
        salas[indiceSala].registrarVisita();                              // 3 y 4. ingresos y recaudo

        autorizado = true;
        cout << "Ingreso autorizado: " << visitantes[indiceVisitante].getNombre() << " entro a '"
             << nombreSala << "' y pago $" << precio << "." << endl;
    }

    return autorizado;
}

bool Galeria::cambiarPrecioSala(string nombreSala, double nuevoPrecio) {
    bool cambiado = false;
    int indiceSala = buscarIndiceSala(nombreSala);

    if (indiceSala == -1) {
        cout << "Error: la sala '" << nombreSala << "' no existe." << endl;
    } else if (nuevoPrecio <= 0) {
        cout << "Error: el precio debe ser mayor que 0." << endl;
    } else {
        salas[indiceSala].setPrecioIngreso(nuevoPrecio);
        cambiado = true;
        cout << "Nuevo precio de '" << nombreSala << "': $" << nuevoPrecio << endl;
    }

    return cambiado;
}

// ============================ CONSULTAS ============================

int Galeria::getCantidadSalas() {
    return salas.size();
}

void Galeria::mostrarSalasPorTipo(string tipo) {
    int cantidad = 0;
    cout << "Salas de tipo '" << tipo << "':" << endl;

    for (unsigned int i = 0; i < salas.size(); i++) {
        if (salas[i].getTipoExposicion() == tipo) {
            cout << "  - " << salas[i].getNombre() << " (" << salas[i].getEstado() << ")" << endl;
            cantidad++;
        }
    }

    cout << "  Total: " << cantidad << endl;
}

void Galeria::mostrarSalasPorEstado(string estado) {
    int cantidad = 0;
    cout << "Salas en estado '" << estado << "':" << endl;

    for (unsigned int i = 0; i < salas.size(); i++) {
        if (salas[i].getEstado() == estado) {
            cout << "  - " << salas[i].getNombre() << endl;
            cantidad++;
        }
    }

    cout << "  Total: " << cantidad << endl;
}

int Galeria::getCantidadExposiciones() {
    int total = 0;
    for (unsigned int i = 0; i < salas.size(); i++) {
        total += salas[i].contarExposiciones();
    }
    return total;
}

// Como cada sala tiene un solo tipo, basta con sumar las salas de ese tipo
int Galeria::getCantidadExposicionesPorTipo(string tipo) {
    int total = 0;
    for (unsigned int i = 0; i < salas.size(); i++) {
        if (salas[i].getTipoExposicion() == tipo) {
            total += salas[i].contarExposiciones();
        }
    }
    return total;
}

void Galeria::mostrarSalaConMasExposiciones() {
    if (salas.empty()) {
        cout << "No hay salas registradas." << endl;
    } else {
        int mayor = 0;
        for (unsigned int i = 1; i < salas.size(); i++) {
            if (salas[i].contarExposiciones() > salas[mayor].contarExposiciones()) {
                mayor = i;
            }
        }
        cout << "Sala con mas exposiciones: " << salas[mayor].getNombre()
             << " (" << salas[mayor].contarExposiciones() << ")" << endl;
    }
}

void Galeria::mostrarSalaConMasIngresos() {
    if (salas.empty()) {
        cout << "No hay salas registradas." << endl;
    } else {
        int mayor = 0;
        for (unsigned int i = 1; i < salas.size(); i++) {
            if (salas[i].getIngresosRecibidos() > salas[mayor].getIngresosRecibidos()) {
                mayor = i;
            }
        }
        cout << "Sala con mas ingresos: " << salas[mayor].getNombre()
             << " (" << salas[mayor].getIngresosRecibidos() << " ingresos)" << endl;
    }
}

void Galeria::mostrarSalaConMasRecaudo() {
    if (salas.empty()) {
        cout << "No hay salas registradas." << endl;
    } else {
        int mayor = 0;
        for (unsigned int i = 1; i < salas.size(); i++) {
            if (salas[i].getDineroRecaudado() > salas[mayor].getDineroRecaudado()) {
                mayor = i;
            }
        }
        cout << "Sala con mas recaudo: " << salas[mayor].getNombre()
             << " ($" << salas[mayor].getDineroRecaudado() << ")" << endl;
    }
}

double Galeria::getRecaudoTotal() {
    double total = 0.0;
    for (unsigned int i = 0; i < salas.size(); i++) {
        total += salas[i].getDineroRecaudado();
    }
    return total;
}

void Galeria::localizarExposicion(string codigoExpo) {
    int fila, columna;
    int indiceSala = buscarSalaDeExposicion(codigoExpo, fila, columna);

    if (indiceSala == -1) {
        cout << "No hay ninguna exposicion instalada con el codigo " << codigoExpo << "." << endl;
    } else {
        Exposicion expo = salas[indiceSala].obtenerExposicion(fila, columna);
        int numeroPosicion = fila * salas[indiceSala].getColumnas() + columna + 1;
        cout << "La exposicion " << codigoExpo << " (" << expo.getNombre() << ") esta en la sala '"
             << salas[indiceSala].getNombre() << "', fila " << fila << ", columna " << columna
             << " (posicion numero " << numeroPosicion << ")." << endl;
    }
}

void Galeria::consultarPosicion(string nombreSala, int fila, int columna) {
    int indiceSala = buscarIndiceSala(nombreSala);

    if (indiceSala == -1) {
        cout << "Error: la sala '" << nombreSala << "' no existe." << endl;
    } else if (!salas[indiceSala].posicionValida(fila, columna)) {
        cout << "Error: la posicion (" << fila << ", " << columna << ") esta fuera de los limites de la sala." << endl;
    } else if (salas[indiceSala].posicionLibre(fila, columna)) {
        cout << "La posicion (" << fila << ", " << columna << ") de '" << nombreSala << "' esta vacia." << endl;
    } else {
        Exposicion expo = salas[indiceSala].obtenerExposicion(fila, columna);
        cout << "En '" << nombreSala << "' posicion (" << fila << ", " << columna << ") esta:" << endl;
        cout << "  Codigo: " << expo.getCodigo() << endl;
        cout << "  Nombre: " << expo.getNombre() << endl;
        cout << "  Autor: " << expo.getAutor() << endl;
        cout << "  Tipo: " << expo.getTipo() << endl;
        cout << "  Descripcion: " << expo.getDescripcion() << endl;
    }
}

void Galeria::mostrarSala(string nombreSala) {
    int indiceSala = buscarIndiceSala(nombreSala);

    if (indiceSala == -1) {
        cout << "Error: la sala '" << nombreSala << "' no existe." << endl;
    } else {
        salas[indiceSala].mostrarDistribucion();
        cout << "Precio actual: $" << salas[indiceSala].getPrecioIngreso()
             << " | Ingresos: " << salas[indiceSala].getIngresosRecibidos()
             << " | Recaudo: $" << salas[indiceSala].getDineroRecaudado() << endl;
    }
}

void Galeria::mostrarVisitante(string idVisitante) {
    int indiceVisitante = buscarIndiceVisitante(idVisitante);

    if (indiceVisitante == -1) {
        cout << "Error: el visitante con identificacion " << idVisitante << " no esta registrado." << endl;
    } else {
        visitantes[indiceVisitante].mostrarHistorial();
    }
}
