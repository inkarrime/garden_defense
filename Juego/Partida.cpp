#include "Partida.h"
#include <iostream>
#include <fstream>
#include <ctime>

// Constructor
Partida::Partida()
    : oleadaActual(1), soles(150), hpCasa(200),
      zombisEliminados(0), gano(false) {}

// Destructor
Partida::~Partida() {}

// Ejecutar la partida completa
void Partida::jugar() {
    cout << "\n╔════════════════════════════════════════╗\n";
    cout << "║          NUEVA PARTIDA                 ║\n";
    cout << "╚════════════════════════════════════════╝\n";

    solicitarNombre();

    // Bucle de oleadas (por ahora simulado)
    while (oleadaActual <= 10 && hpCasa > 0) {
        cout << "\n╔════════════════════════════════════════╗\n";
        cout << "║        OLEADA " << oleadaActual << " de 10                 ║\n";
        cout << "╚════════════════════════════════════════╝\n";

        mostrarEstado();
        mapa.mostrarMapa();

        fasePreparacion();
        faseOleada();

        // Por ahora, avanzar directamente (simulación)
        oleadaActual++;

        cout << "\nPresione Enter para continuar a la siguiente oleada...";
        cin.get();
    }

    // Determinar resultado
    if (hpCasa > 0) {
        gano = true;
        cout << "\n╔════════════════════════════════════════╗\n";
        cout << "║            ¡VICTORIA! 🎉               ║\n";
        cout << "║  ¡Completaste todas las oleadas!       ║\n";
        cout << "╚════════════════════════════════════════╝\n";
    } else {
        gano = false;
        cout << "\n╔════════════════════════════════════════╗\n";
        cout << "║            DERROTA ☠️                   ║\n";
        cout << "║    Los zombis invadieron tu casa       ║\n";
        cout << "╚════════════════════════════════════════╝\n";
    }

    // Guardar estadísticas al terminar
    guardarEstadisticas();

    cout << "\nPresione Enter para volver al menu...";
    cin.get();
}

// Solicitar nombre del jugador
void Partida::solicitarNombre() {
    cout << "\nIngrese su nombre: ";
    getline(cin, nombreJugador);
}

// Fase de preparación (colocar plantas)
void Partida::fasePreparacion() {
    cout << "\n--- FASE DE PREPARACION ---\n";
    cout << "(Por implementar: colocar plantas)\n";

    // Simulación: dar más soles
    soles += 50;
}

// Fase de oleada (combate)
void Partida::faseOleada() {
    cout << "\n--- FASE DE COMBATE ---\n";
    cout << "(Por implementar: zombis atacan)\n";

    // Simulación: eliminar algunos zombis
    zombisEliminados += 5;
}

// Mostrar estado actual del juego
void Partida::mostrarEstado() {
    cout << "\nJugador: " << nombreJugador;
    cout << " | Soles: " << soles;
    cout << " | HP Casa: " << hpCasa;
    cout << " | Zombis eliminados: " << zombisEliminados << "\n";
}

// Guardar estadísticas en archivo
void Partida::guardarEstadisticas() {
    ofstream archivo("estadisticas.txt", ios::app);

    if (!archivo.is_open()) {
        cout << "\nError: No se pudo guardar las estadísticas.\n";
        return;
    }

    // Obtener fecha actual
    time_t ahora = time(nullptr);
    string fecha = ctime(&ahora);
    if (!fecha.empty() && fecha[fecha.length()-1] == '\n') {
        fecha.erase(fecha.length()-1);
    }

    // Calcular daño recibido
    int danioRecibido = 200 - hpCasa;

    // Guardar en formato CSV
    archivo << nombreJugador << ","
            << (gano ? "VICTORIA" : "DERROTA") << ","
            << (oleadaActual - 1) << ","
            << zombisEliminados << ","
            << soles << ","
            << danioRecibido << ","
            << fecha << "\n";

    archivo.close();

    cout << "\n✓ Estadísticas guardadas correctamente.\n";
}