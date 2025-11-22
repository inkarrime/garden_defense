#include "Juego.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <ctime>

using namespace std;

Juego::Juego()
    : ejecutando(true), nombreJugador(""), mapa(nullptr), archivo(nullptr),
      oleadaActual(0), oleadasTotales(10), soles(150),
      zombiesEliminados(0), enPartida(false) {
    srand(time(0)); // Inicializar semilla aleatoria
    archivo = new Archivo("historial.txt");
}

Juego::~Juego() {
    if (mapa != nullptr) {
        delete mapa;
        mapa = nullptr;
    }
    if (archivo != nullptr) {
        delete archivo;
        archivo = nullptr;
    }
}

void Juego::limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Juego::pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.get();
}

void Juego::pedirNombreJugador() {
    limpiarPantalla();
    cout << "\n===========================================\n";
    cout << "    NUEVA PARTIDA\n";
    cout << "===========================================\n\n";
    cout << "Ingrese su nombre: ";
    getline(cin, nombreJugador);
    cout << "\n¡Bienvenido, " << nombreJugador << "!" << endl;
    cout << "\n📜 REGLAS DEL JUEGO:" << endl;
    cout << "   • Defiende tu casa de 10 oleadas de zombies" << endl;
    cout << "   • Planta estrategicamente para detener a los zombies" << endl;
    cout << "   • Usa soles para comprar plantas" << endl;
    cout << "   • Si tu casa llega a 0 HP, pierdes" << endl;
    cout << "   • ¡Sobrevive todas las oleadas para ganar!" << endl;
    pausar();
}

void Juego::mostrarTiendasPlantas() {
    cout << "\n╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║                   TIENDA DE PLANTAS                    ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;
    cout << "\nSoles disponibles: " << soles << " ☀️\n" << endl;

    cout << "[1] 🌻 Girasol           Costo: 50   | Genera 25 soles cada 2 turnos" << endl;
    cout << "[2] 🌵 Cactus            Costo: 125  | Danio por contacto: 15 HP" << endl;
    cout << "[3] ❄️  Planta de Hielo   Costo: 150  | Ralentiza zombies cercanos" << endl;
    cout << "[4] 🧄 Ajo               Costo: 50   | Desvia zombies a otra fila" << endl;
    cout << "[5] 🍄 Seta Defensiva    Costo: 75   | Regenera 1 HP por turno" << endl;
    cout << "[6] 🌺 Flor de Aura      Costo: 100  | +10% danio a plantas cercanas" << endl;
    cout << "[0] Volver" << endl;
}

void Juego::plantarPlanta() {
    mostrarTiendasPlantas();

    int opcion;
    cout << "\nSeleccione planta a comprar: ";
    cin >> opcion;

    if (cin.fail() || opcion < 0 || opcion > 6) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "❌ Opcion invalida!" << endl;
        pausar();
        return;
    }

    if (opcion == 0) return;

    Planta* nuevaPlanta = nullptr;
    int costo = 0;

    switch(opcion) {
        case 1:
            costo = 50;
            if (soles >= costo) nuevaPlanta = new Girasol(0, 0);
            break;
        case 2:
            costo = 125;
            if (soles >= costo) nuevaPlanta = new Cactus(0, 0);
            break;
        case 3:
            costo = 150;
            if (soles >= costo) nuevaPlanta = new PlantaHielo(0, 0);
            break;
        case 4:
            costo = 50;
            if (soles >= costo) nuevaPlanta = new Ajo(0, 0);
            break;
        case 5:
            costo = 75;
            if (soles >= costo) nuevaPlanta = new SetaDefensiva(0, 0);
            break;
        case 6:
            costo = 100;
            if (soles >= costo) nuevaPlanta = new FlorAura(0, 0);
            break;
    }

    if (nuevaPlanta == nullptr) {
        cout << "❌ No tienes suficientes soles! (Necesitas: " << costo << ")" << endl;
        pausar();
        return;
    }

    // Pedir posicion
    int fila, columna;
    cout << "\nIngrese fila (1-5): ";
    cin >> fila;
    cout << "Ingrese columna (0-8): ";
    cin >> columna;

    fila--; // Ajustar a indice 0

    if (mapa->colocarPlanta(nuevaPlanta, fila, columna)) {
        soles -= costo;
        cout << "✅ Planta colocada! Soles restantes: " << soles << endl;
    } else {
        delete nuevaPlanta;
        cout << "❌ No se pudo colocar la planta" << endl;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    pausar();
}

void Juego::eliminarPlantaMapa() {
    int fila, columna;
    cout << "\nIngrese fila (1-5): ";
    cin >> fila;
    cout << "Ingrese columna (0-8): ";
    cin >> columna;

    fila--; // Ajustar a indice 0

    mapa->eliminarPlanta(fila, columna);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    pausar();
}

void Juego::menuPreparacion() {
    int opcion;

    do {
        mapa->mostrar(oleadaActual, soles);

        cout << "\nSeleccione una accion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(opcion) {
            case 1:
                plantarPlanta();
                break;
            case 2:
                eliminarPlantaMapa();
                break;
            case 3:
                return; // Iniciar oleada
            case 4:
                enPartida = false;
                return;
            default:
                cout << "❌ Opcion invalida!" << endl;
                pausar();
        }

    } while(opcion != 3 && opcion != 4);
}

void Juego::fasePreparacion() {
    cout << "\n╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║              📋 FASE DE PREPARACION 📋                 ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;
    cout << "\nColoca tus plantas estrategicamente antes de la oleada" << endl;
    pausar();

    menuPreparacion();
}

void Juego::iniciarOleada() {
    oleadaActual++;

    Oleada oleada(oleadaActual);
    oleada.generar();
    pausar();

    // Agregar zombies al mapa
    vector<Zombie*> zombies = oleada.obtenerZombies();
    for (size_t i = 0; i < zombies.size(); i++) {
        mapa->agregarZombie(zombies[i]);
    }

    cout << "\n🚨 ¡LA OLEADA HA COMENZADO! 🚨" << endl;
    pausar();
}

void Juego::ejecutarTurno() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║                  ⚔️  TURNO EN CURSO ⚔️                  ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;

    // Turno de plantas
    mapa->turnosPlantas(soles);

    // Turno de zombies
    mapa->turnosZombies();

    // Procesar colisiones
    mapa->procesarColisiones();

    // Limpiar muertos
    int zombiesAntes = mapa->contarZombiesVivos();
    mapa->limpiarMuertos();
    int zombiesDespues = mapa->contarZombiesVivos();
    zombiesEliminados += (zombiesAntes - zombiesDespues);

    pausar();
}

void Juego::verificarEstadoJuego() {
    if (mapa->casaDestruida()) {
        mostrarDerrota();
        enPartida = false;
    } else if (mapa->todosZombiesMuertos()) {
        if (oleadaActual >= oleadasTotales) {
            mostrarVictoria();
            enPartida = false;
        } else {
            cout << "\n";
            cout << "╔════════════════════════════════════════════════════════╗" << endl;
            cout << "║           ✅ OLEADA " << setw(2) << oleadaActual << " COMPLETADA! ✅            ║" << endl;
            cout << "╚════════════════════════════════════════════════════════╝" << endl;
            cout << "\nSoles ganados: +50 ☀️" << endl;
            soles += 50;
            pausar();
        }
    }
}

void Juego::faseCombate() {
    while (enPartida && !mapa->todosZombiesMuertos() && !mapa->casaDestruida()) {
        mapa->mostrar(oleadaActual, soles);
        ejecutarTurno();
        verificarEstadoJuego();
    }
}

void Juego::mostrarVictoria() {
    limpiarPantalla();
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║                                                        ║" << endl;
    cout << "║          🎉🎉🎉 ¡VICTORIA! 🎉🎉🎉                       ║" << endl;
    cout << "║                                                        ║" << endl;
    cout << "║     ¡Has defendido el jardin exitosamente!            ║" << endl;
    cout << "║                                                        ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;

    cout << "\n📊 ESTADISTICAS FINALES:" << endl;
    cout << "   Jugador: " << nombreJugador << endl;
    cout << "   Oleadas completadas: " << oleadaActual << "/" << oleadasTotales << endl;
    cout << "   Zombies eliminados: " << zombiesEliminados << endl;
    cout << "   Soles restantes: " << soles << endl;
    cout << "   HP Casa: " << mapa->obtenerHPCasa() << endl;

    guardarEstadisticas(true);
    pausar();
}

void Juego::mostrarDerrota() {
    limpiarPantalla();
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║                                                        ║" << endl;
    cout << "║              💀 DERROTA 💀                             ║" << endl;
    cout << "║                                                        ║" << endl;
    cout << "║     Los zombies han invadido tu jardin...             ║" << endl;
    cout << "║                                                        ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;

    cout << "\n📊 ESTADISTICAS FINALES:" << endl;
    cout << "   Jugador: " << nombreJugador << endl;
    cout << "   Oleadas completadas: " << oleadaActual - 1 << "/" << oleadasTotales << endl;
    cout << "   Zombies eliminados: " << zombiesEliminados << endl;
    cout << "   Soles recolectados: " << soles << endl;

    guardarEstadisticas(false);
    pausar();
}

void Juego::guardarEstadisticas(bool victoria) {
    int oleadasCompletadasFinal = victoria ? oleadaActual : oleadaActual - 1;

    Estadisticas stats(nombreJugador, victoria, oleadasCompletadasFinal,
                      oleadasTotales, zombiesEliminados, soles, mapa->obtenerHPCasa());

    archivo->guardarEstadistica(stats);
}

void Juego::jugar() {
    pedirNombreJugador();

    // Inicializar nuevo mapa
    if (mapa != nullptr) {
        delete mapa;
    }
    mapa = new Mapa();

    // Reiniciar variables
    oleadaActual = 0;
    soles = 150;
    zombiesEliminados = 0;
    enPartida = true;

    // Bucle principal del juego
    while (enPartida && oleadaActual < oleadasTotales) {
        // Fase de preparacion
        fasePreparacion();

        if (!enPartida) break; // Si el jugador salio al menu

        // Iniciar oleada
        iniciarOleada();

        // Fase de combate
        faseCombate();

        // Verificar si gano o perdio
        verificarEstadoJuego();
    }
}

void Juego::verEstadisticas() {
    limpiarPantalla();

    int opcion;
    do {
        cout << "\n===========================================\n";
        cout << "    ESTADISTICAS\n";
        cout << "===========================================\n\n";
        cout << "1. Ver Historial Completo\n";
        cout << "2. Ver Top 10 Jugadores\n";
        cout << "3. Ver Mejor Puntuacion\n";
        cout << "4. Total de Partidas\n";
        cout << "5. Volver\n\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(opcion) {
            case 1:
                limpiarPantalla();
                archivo->mostrarHistorial();
                pausar();
                limpiarPantalla();
                break;
            case 2:
                limpiarPantalla();
                archivo->mostrarTop10();
                pausar();
                limpiarPantalla();
                break;
            case 3: {
                limpiarPantalla();
                Estadisticas mejor = archivo->obtenerMejorPuntuacion();
                if (mejor.obtenerPuntosTotales() > 0) {
                    cout << "\n🏆 MEJOR PUNTUACION 🏆\n" << endl;
                    mejor.mostrar();
                } else {
                    cout << "\n(No hay partidas registradas)\n" << endl;
                }
                pausar();
                limpiarPantalla();
                break;
            }
            case 4:
                limpiarPantalla();
                cout << "\n📊 Total de partidas jugadas: " << archivo->contarPartidas() << endl;
                pausar();
                limpiarPantalla();
                break;
            case 5:
                return;
            default:
                cout << "❌ Opcion invalida!" << endl;
                pausar();
                limpiarPantalla();
        }

    } while(opcion != 5);
}

void Juego::salir() {
    cout << "\n¡Gracias por jugar Defensa del Jardin!" << endl;
    cout << "Hasta pronto, " << nombreJugador << "!\n" << endl;
    ejecutando = false;
}

void Juego::iniciar() {
    while (ejecutando) {
        int opcion = menu.obtenerSeleccion();

        switch (opcion) {
            case 1:
                jugar();
                break;
            case 2:
                verEstadisticas();
                break;
            case 3:
                salir();
                break;
        }
    }
}