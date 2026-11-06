#include <iostream>
#include "galeria.h"
using namespace std;

// Imprime un titulo para separar cada prueba en la salida
void titulo(string texto) {
    cout << "\n==================================================" << endl;
    cout << texto << endl;
    cout << "==================================================" << endl;
}

int main() {
    Galeria galeria;

    // ---------------------------------------------------------------
    titulo("PRUEBA 1: Registro de salas");
    galeria.registrarSala(Sala("Sala VR", "Realidad virtual", 2, 2, 15000));
    galeria.registrarSala(Sala("Sala Juegos", "Videojuego", 2, 3, 10000));
    galeria.registrarSala(Sala("Sala Cortos", "Cortometraje", 1, 2, 8000));
    galeria.registrarSala(Sala("Sala VR 2", "Realidad virtual", 1, 3, 12000));
    cout << "\n-- Casos que deben fallar --" << endl;
    galeria.registrarSala(Sala("Sala VR", "Animacion", 2, 2, 5000));      // nombre repetido
    galeria.registrarSala(Sala("Sala Rara", "Animacion", 0, 3, 5000));    // 0 filas
    galeria.registrarSala(Sala("Sala Gratis", "Animacion", 2, 2, 0));     // precio 0
    cout << "Cantidad total de salas: " << galeria.getCantidadSalas() << endl;

    // ---------------------------------------------------------------
    titulo("PRUEBA 2: Registro de visitantes");
    galeria.registrarVisitante(Visitante("1001", "Ana", 50000));
    galeria.registrarVisitante(Visitante("1002", "Luis", 9000));
    cout << "\n-- Casos que deben fallar --" << endl;
    galeria.registrarVisitante(Visitante("1001", "Pedro", 20000));        // id repetido
    galeria.registrarVisitante(Visitante("1003", "Sofia", -100));         // dinero negativo

    // Exposiciones que se usan en las pruebas
    Exposicion vr01("VR01", "Viaje a Marte", "Equipo Orion", "Realidad virtual", "Recorrido por la superficie de Marte");
    Exposicion vr02("VR02", "Fondo del mar", "Laura Rios", "Realidad virtual", "Inmersion en un arrecife");
    Exposicion vr03("VR03", "Ciudad perdida", "Equipo Nova", "Realidad virtual", "Exploracion de ruinas");
    Exposicion vr04("VR04", "Vuelo libre", "Carlos Pena", "Realidad virtual", "Simulador de vuelo");
    Exposicion vr05("VR05", "Selva", "Equipo Verde", "Realidad virtual", "Paseo por el Amazonas");
    Exposicion vr06("VR06", "Espacio", "Equipo Orion", "Realidad virtual", "Estacion espacial");
    Exposicion vj01("VJ01", "Pixel Run", "Estudio 8bit", "Videojuego", "Juego de plataformas");
    Exposicion vj02("VJ02", "Laberinto", "Equipo Maze", "Videojuego", "Juego de puzzles");

    // ---------------------------------------------------------------
    titulo("PRUEBA 3: Estado inicial de las salas");
    galeria.mostrarSala("Sala VR");

    // ---------------------------------------------------------------
    titulo("PRUEBA 4: Instalar exposiciones (casos exitosos)");
    galeria.instalarExposicion(vr01, "Sala VR", 0, 0);
    galeria.mostrarSala("Sala VR");        // debe pasar a Disponible
    galeria.instalarExposicion(vj01, "Sala Juegos", 0, 0);
    galeria.instalarExposicion(vj02, "Sala Juegos", 1, 2);

    // ---------------------------------------------------------------
    titulo("PRUEBA 5: Instalar exposiciones (casos que deben fallar)");
    galeria.instalarExposicion(vr02, "Sala Inventada", 0, 0);   // sala no existe
    galeria.instalarExposicion(vr02, "Sala VR", 5, 5);          // fuera de limites
    galeria.instalarExposicion(vr02, "Sala VR", 0, 0);          // posicion ocupada
    galeria.instalarExposicion(vj01, "Sala VR", 0, 1);          // ya instalada en otro lugar
    galeria.instalarExposicion(Exposicion("VJ03", "Carreras", "Equipo Turbo", "Videojuego", "Juego de carreras"),
                               "Sala VR", 0, 1);                // tipo no coincide
    galeria.instalarExposicion(vr01, "Sala VR 2", 0, 0);        // VR01 ya esta en Sala VR
    galeria.mostrarSala("Sala VR");        // no debe haber cambiado

    // ---------------------------------------------------------------
    titulo("PRUEBA 6: Llenar una sala (debe pasar a Llena)");
    galeria.instalarExposicion(vr02, "Sala VR", 0, 1);
    galeria.instalarExposicion(vr03, "Sala VR", 1, 0);
    galeria.instalarExposicion(vr04, "Sala VR", 1, 1);
    galeria.mostrarSala("Sala VR");

    // ---------------------------------------------------------------
    titulo("PRUEBA 7: Consultar que hay en una posicion");
    galeria.consultarPosicion("Sala VR", 1, 0);
    galeria.consultarPosicion("Sala Juegos", 0, 1);     // vacia
    galeria.consultarPosicion("Sala Juegos", 9, 9);     // fuera de limites

    // ---------------------------------------------------------------
    titulo("PRUEBA 8: Localizar exposicion por codigo");
    galeria.localizarExposicion("VR03");
    galeria.localizarExposicion("VJ02");
    galeria.localizarExposicion("XX99");                // no existe

    // ---------------------------------------------------------------
    titulo("PRUEBA 9: Ingreso de visitantes (casos exitosos)");
    galeria.autorizarIngreso("1001", "Sala VR");
    galeria.autorizarIngreso("1001", "Sala VR");        // misma sala otra vez: paga de nuevo
    galeria.autorizarIngreso("1001", "Sala Juegos");

    // ---------------------------------------------------------------
    titulo("PRUEBA 10: Ingreso de visitantes (casos que deben fallar)");
    galeria.autorizarIngreso("9999", "Sala VR");        // visitante no registrado
    galeria.autorizarIngreso("1001", "Sala Inventada"); // sala no existe
    galeria.autorizarIngreso("1001", "Sala Cortos");    // sala en construccion
    galeria.autorizarIngreso("1002", "Sala VR");        // Luis no tiene dinero suficiente
    cout << "\nLuis no debe haber perdido dinero:" << endl;
    galeria.mostrarVisitante("1002");
    cout << "\nSala VR no debe haber cambiado sus estadisticas:" << endl;
    galeria.mostrarSala("Sala VR");

    // ---------------------------------------------------------------
    titulo("PRUEBA 11: Cambio de precio (solo afecta ingresos futuros)");
    galeria.cambiarPrecioSala("Sala Juegos", 5000);
    galeria.cambiarPrecioSala("Sala Juegos", -200);     // debe fallar
    galeria.cambiarPrecioSala("Sala Inventada", 5000);  // debe fallar
    galeria.autorizarIngreso("1002", "Sala Juegos");    // Luis ahora si puede pagar
    cout << "\nAna pago $10000 en Sala Juegos antes del cambio; su historial no debe cambiar:" << endl;
    galeria.mostrarVisitante("1001");
    galeria.mostrarSala("Sala Juegos");

    // ---------------------------------------------------------------
    titulo("PRUEBA 12: Traslado de exposiciones (caso exitoso)");
    galeria.trasladarExposicion("VR02", "Sala VR 2");
    galeria.mostrarSala("Sala VR");        // de Llena a Disponible
    galeria.mostrarSala("Sala VR 2");      // de En construccion a Disponible

    // ---------------------------------------------------------------
    titulo("PRUEBA 13: Traslado de exposiciones (casos que deben fallar)");
    galeria.trasladarExposicion("XX99", "Sala VR 2");       // exposicion no existe
    galeria.trasladarExposicion("VR01", "Sala Inventada");  // sala destino no existe
    galeria.trasladarExposicion("VR01", "Sala VR");         // ya esta en esa sala
    galeria.trasladarExposicion("VJ01", "Sala VR");         // tipo no coincide
    galeria.instalarExposicion(vr05, "Sala VR 2", 0, 1);
    galeria.instalarExposicion(vr06, "Sala VR 2", 0, 2);    // Sala VR 2 queda llena
    galeria.trasladarExposicion("VR01", "Sala VR 2");       // sin espacio
    cout << "\nVR01 debe seguir en su lugar original:" << endl;
    galeria.localizarExposicion("VR01");

    // ---------------------------------------------------------------
    titulo("PRUEBA 14: Retiro de exposiciones");
    galeria.retirarExposicion("VR01");
    galeria.retirarExposicion("XX99");                      // debe fallar
    galeria.retirarExposicion("VJ01");
    galeria.retirarExposicion("VJ02");                      // Sala Juegos vuelve a En construccion
    galeria.mostrarSala("Sala Juegos");
    galeria.autorizarIngreso("1001", "Sala Juegos");        // ya no recibe visitantes

    // ---------------------------------------------------------------
    titulo("PRUEBA 15: Consultas generales");
    cout << "Cantidad total de salas: " << galeria.getCantidadSalas() << endl;
    galeria.mostrarSalasPorTipo("Realidad virtual");
    galeria.mostrarSalasPorEstado("En construccion");
    galeria.mostrarSalasPorEstado("Disponible");
    galeria.mostrarSalasPorEstado("Llena");
    cout << "Cantidad total de exposiciones instaladas: " << galeria.getCantidadExposiciones() << endl;
    cout << "Exposiciones de tipo 'Realidad virtual': " << galeria.getCantidadExposicionesPorTipo("Realidad virtual") << endl;
    cout << "Exposiciones de tipo 'Videojuego': " << galeria.getCantidadExposicionesPorTipo("Videojuego") << endl;
    galeria.mostrarSalaConMasExposiciones();
    galeria.mostrarSalaConMasIngresos();
    galeria.mostrarSalaConMasRecaudo();
    cout << "Recaudo total de la galeria: $" << galeria.getRecaudoTotal() << endl;

    // ---------------------------------------------------------------
    titulo("PRUEBA 16: Informacion final de los visitantes");
    galeria.mostrarVisitante("1001");
    galeria.mostrarVisitante("1002");
    galeria.mostrarVisitante("5555");                      // no registrado

    return 0;
}
