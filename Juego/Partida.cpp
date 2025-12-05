#include "Partida.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <map>

// Constructor
Partida::Partida()
    : nivelActual(nullptr), nivelNumero(1), soles(150),
      zombisEliminados(0), gano(false), casaInvadida(false),
      zombisRestantes(0), turnoActual(0) {
    srand(time(nullptr));
}

// Destructor
Partida::~Partida() {
    if (nivelActual != nullptr) {
        delete nivelActual;
    }
}

// ... (solicitarNombre, inicializarNivel, mostrarHeader sin cambios) ...

void Partida::solicitarNombre() {
    cout << "===== DEFENSA DEL JARDIN =====\n\n";
    cout << "Ingrese nombre del jugador: ";
    cin >> nombreJugador;
}

void Partida::inicializarNivel(int numeroNivel) {
    if (nivelActual != nullptr) {
        delete nivelActual;
    }

    nivelActual = new Nivel(numeroNivel);
    nivelNumero = numeroNivel;
    mapa = Mapa(nivelActual->getFilas(), nivelActual->getColumnas());

    // SIEMPRE reiniciar soles a 150 en cada nivel
    soles = 150;
}

void Partida::mostrarHeader() {
    cout << "Turno: " << turnoActual
         << " | Soles: " << soles
         << " | Jugador: " << nombreJugador << "\n";
}

// Mostrar información de plantas y zombis
void Partida::mostrarInformacionEntidades() {
    // Verificar si hay zombis vivos
    bool hayZombisVivos = false;
    for (const auto& z : zombis) {
        if (z.vivo) {
            hayZombisVivos = true;
            break;
        }
    }

    // Solo mostrar si hay plantas o zombis vivos
    if (plantas.empty() && !hayZombisVivos) {
        return; // No mostrar nada si no hay entidades
    }

    cout << "\n--- INFORMACION DEL MAPA ---\n";

    // Mostrar plantas solo si hay plantas
    if (!plantas.empty()) {
        cout << "\nPlantas:\n";

        // Agrupar por tipo
        map<char, vector<const Planta*>> plantasPorTipo;
        for (const auto& planta : plantas) {
            plantasPorTipo[planta.simbolo].push_back(&planta);
        }

        for (const auto& par : plantasPorTipo) {
            if (par.first == 'G') {
                cout << "* Girasol(es): ";
            } else if (par.first == 'L') {
                cout << "* Lanzaguisante(s): ";
            }

            for (size_t i = 0; i < par.second.size(); i++) {
                const Planta* p = par.second[i];
                cout << "[" << (p->fila + 1) << "x" << (p->columna + 1)
                     << ", " << p->hp << " HP]";
                if (i < par.second.size() - 1) {
                    cout << ", ";
                }
            }
            cout << "\n";
        }
    }

    // Mostrar zombis solo si hay zombis vivos
    if (hayZombisVivos) {
        cout << "\nZombis:\n";
        cout << "* Zombi(s): ";

        bool primero = true;
        for (const auto& z : zombis) {
            if (z.vivo) {
                if (!primero) {
                    cout << ", ";
                }
                cout << "[" << (z.fila + 1) << "x" << (z.columna + 1)
                     << ", " << z.hp << " HP]";
                primero = false;
            }
        }
        cout << "\n";
    }

    cout << "\n";
}

// Mostrar estado completo
void Partida::mostrarEstadoCompleto() {
    cout << "\n__________ NIVEL " << nivelNumero << " __________\n";
    mostrarHeader();
    mapa.mostrarMapa();
    mostrarInformacionEntidades();
}

// ... (plantarPlanta y desplantarPlanta sin cambios significativos) ...

void Partida::plantarPlanta() {
    bool regresar = false;

    while (!regresar) {
        mostrarEstadoCompleto();

        cout << "\n--- ACCION: PLANTAR ---\n";
        cout << "1. Girasol [G] (50 soles) - 100 HP\n";
        cout << "2. Lanzaguisantes [L] (100 soles) - 100 HP\n";
        cout << "3. Regresar a las demas acciones\n\n";
        cout << "Seleccione planta: ";

        int tipoPlanta;
        cin >> tipoPlanta;

        if (tipoPlanta == 3) {
            regresar = true;
            continue;
        }

        if (tipoPlanta != 1 && tipoPlanta != 2) {
            cout << "\nTipo de planta invalido.\n";
            continue;
        }

        int costo = (tipoPlanta == 1) ? 50 : 100;
        char simbolo = (tipoPlanta == 1) ? 'G' : 'L';
        string nombre = (tipoPlanta == 1) ? "Girasol" : "Lanzaguisantes";

        if (soles < costo) {
            cout << "\nNo tienes suficientes soles!\n";
            continue;
        }

        mostrarEstadoCompleto();
        cout << "\n--- PLANTANDO: " << nombre << " ---\n\n";

        int fila, col;
        cout << "Fila (1-" << mapa.getFilas() << "): ";
        cin >> fila;
        cout << "Columna (1-" << mapa.getColumnas() << "): ";
        cin >> col;

        fila--;
        col--;

        if (mapa.colocarPlanta(fila, col, simbolo)) {
            soles -= costo;
            plantas.push_back(Planta(fila, col, simbolo, turnoActual));
            cout << "\n" << nombre << " plantado exitosamente!\n";
            regresar = true;
        } else {
            cout << "\nNo se pudo plantar (casilla ocupada o invalida).\n";
        }
    }
}

void Partida::desplantarPlanta() {
    if (!mapa.tienePlantas()) {
        mostrarEstadoCompleto();
        cout << "\n--- ACCION: DESPLANTAR ---\n";
        cout << "\nNo hay plantas plantadas para retirar.\n";
        cout << "Regresando al menu de acciones...\n";
        return;
    }

    bool regresar = false;

    while (!regresar) {
        mostrarEstadoCompleto();

        cout << "\n--- ACCION: DESPLANTAR ---\n";
        cout << "1. Eliminar una planta\n";
        cout << "2. Regresar a las demas acciones\n\n";
        cout << "Seleccione opcion: ";

        int opcion;
        cin >> opcion;

        if (opcion == 2) {
            regresar = true;
            continue;
        }

        if (opcion != 1) {
            cout << "\nOpcion invalida.\n";
            continue;
        }

        mostrarEstadoCompleto();
        cout << "\n--- ELIMINANDO PLANTA ---\n\n";

        int fila, col;
        cout << "Fila (1-" << mapa.getFilas() << "): ";
        cin >> fila;
        cout << "Columna (1-" << mapa.getColumnas() << "): ";
        cin >> col;

        fila--;
        col--;

        if (mapa.eliminarPlanta(fila, col)) {
            plantas.erase(
                remove_if(plantas.begin(), plantas.end(),
                    [fila, col](const Planta& p) {
                        return p.fila == fila && p.columna == col;
                    }),
                plantas.end()
            );

            cout << "\nPlanta eliminada exitosamente!\n";
            regresar = true;
        } else {
            cout << "\nNo hay planta en esa posicion o coordenadas invalidas.\n";
        }
    }
}

void Partida::faseAcciones() {
    bool comenzarTurno = false;

    while (!comenzarTurno) {
        mostrarEstadoCompleto();

        cout << "--- ACCIONES ---\n";
        cout << "1. Plantar\n";
        cout << "2. Desplantar\n";
        cout << "3. Comenzar turno\n\n";
        cout << "Seleccione una accion: ";

        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                plantarPlanta();
                break;
            case 2:
                desplantarPlanta();
                break;
            case 3:
                comenzarTurno = true;
                cout << "\nComenzando turno...\n";
                break;
            default:
                cout << "\nOpcion invalida.\n";
                break;
        }
    }
}

void Partida::habilidadGirasol(const Planta& planta) {
    int turnosDesdePlantado = turnoActual - planta.turnoPlantado;

    if (turnosDesdePlantado > 0 && turnosDesdePlantado % 2 == 0) {
        soles += 25;
        cout << "Girasol en [" << (planta.fila + 1) << "x" << (planta.columna + 1)
             << "] genero 25 soles! (+25 soles)\n";
    }
}

void Partida::habilidadLanzaguisantes(Planta& planta) {
    Zombi* zombiMasCercano = nullptr;
    int distanciaMinima = 999;

    for (auto& zombi : zombis) {
        if (zombi.vivo && zombi.fila == planta.fila && zombi.columna > planta.columna) {
            int distancia = zombi.columna - planta.columna;
            if (distancia < distanciaMinima) {
                distanciaMinima = distancia;
                zombiMasCercano = &zombi;
            }
        }
    }

    if (zombiMasCercano != nullptr) {
        zombiMasCercano->hp -= 25;

        cout << "Lanzaguisantes en [" << (planta.fila + 1) << "x" << (planta.columna + 1)
             << "] ataca al zombi en [" << (zombiMasCercano->fila + 1) << "x"
             << (zombiMasCercano->columna + 1) << "]! (-25 HP)\n";

        if (zombiMasCercano->hp <= 0) {
            zombiMasCercano->vivo = false;
            cout << "¡Zombi eliminado en [" << (zombiMasCercano->fila + 1)
                 << "x" << (zombiMasCercano->columna + 1) << "]!\n";
        }
    }
}

// Ejecutar habilidades de todas las plantas
void Partida::ejecutarHabilidadesPlantas() {
    if (plantas.empty()) {
        return;
    }

    // Primero verificar si hay alguna habilidad que se va a ejecutar
    bool hayHabilidades = false;

    for (const auto& planta : plantas) {
        if (planta.simbolo == 'G') {
            int turnosDesdePlantado = turnoActual - planta.turnoPlantado;
            if (turnosDesdePlantado > 0 && turnosDesdePlantado % 2 == 0) {
                hayHabilidades = true;
                break;
            }
        } else if (planta.simbolo == 'L') {
            // Verificar si hay zombis en la fila
            for (const auto& zombi : zombis) {
                if (zombi.vivo && zombi.fila == planta.fila && zombi.columna > planta.columna) {
                    hayHabilidades = true;
                    break;
                }
            }
            if (hayHabilidades) break;
        }
    }

    // Solo mostrar título si hay habilidades
    if (hayHabilidades) {
        cout << "\n--- Habilidades de las plantas ---\n";
    }

    for (auto& planta : plantas) {
        if (planta.simbolo == 'G') {
            habilidadGirasol(planta);
        } else if (planta.simbolo == 'L') {
            habilidadLanzaguisantes(planta);
        }
    }
}

// NUEVO: Zombis atacan plantas
// NUEVO: Zombis atacan plantas
void Partida::zombisAtacan() {
    if (plantas.empty() || zombis.empty()) {
        return;
    }

    // Primero verificar si algún zombi está en la misma posición que una planta
    bool hayAtaques = false;
    for (const auto& zombi : zombis) {
        if (!zombi.vivo) continue;

        for (const auto& planta : plantas) {
            if (planta.fila == zombi.fila && planta.columna == zombi.columna) {
                hayAtaques = true;
                break;
            }
        }
        if (hayAtaques) break;
    }

    // Solo mostrar título si hay ataques
    if (hayAtaques) {
        cout << "\n--- Zombis atacan ---\n";
    }

    for (auto& zombi : zombis) {
        if (!zombi.vivo) continue;

        // Buscar si hay una planta en la posición del zombi
        for (auto& planta : plantas) {
            if (planta.fila == zombi.fila && planta.columna == zombi.columna) {
                // El zombi ataca la planta
                planta.hp -= zombi.danio;

                cout << "Zombi en [" << (zombi.fila + 1) << "x" << (zombi.columna + 1)
                     << "] ataca planta! (-" << zombi.danio << " HP, "
                     << planta.hp << " HP restante)\n";

                // Si la planta muere
                if (planta.hp <= 0) {
                    cout << "¡Planta en [" << (planta.fila + 1) << "x" << (planta.columna + 1)
                         << "] ha sido destruida!\n";
                    mapa.eliminarPlanta(planta.fila, planta.columna);
                }

                break;
            }
        }
    }

    // Eliminar plantas muertas
    plantas.erase(
        remove_if(plantas.begin(), plantas.end(),
                 [](const Planta& p) { return p.hp <= 0; }),
        plantas.end()
    );
}

void Partida::generarNuevosZombis() {
    if (zombisRestantes <= 0) {
        return;
    }

    int cantidadAGenerar = (zombisRestantes == 1) ? 1 : (rand() % 2 + 1);

    if (cantidadAGenerar > zombisRestantes) {
        cantidadAGenerar = zombisRestantes;
    }

    cout << "\n¡Aparecen " << cantidadAGenerar << " zombi(s)!\n";

    for (int i = 0; i < cantidadAGenerar; i++) {
        int filaAleatoria = rand() % mapa.getFilas();
        int columnaInicial = mapa.getColumnas() - 1;

        zombis.push_back(Zombi(filaAleatoria, columnaInicial));
        zombisRestantes--;

        cout << "Zombi aparece en fila " << (filaAleatoria + 1) << "\n";
    }
}

void Partida::actualizarMapaZombis() {
    for (int i = 0; i < mapa.getFilas(); i++) {
        for (int j = 0; j < mapa.getColumnas(); j++) {
            if (mapa.getCasilla(i, j) == 'Z') {
                mapa.eliminarZombi(i, j);
            }
        }
    }

    for (const auto& zombi : zombis) {
        if (zombi.vivo && zombi.columna >= 0) {
            mapa.colocarZombi(zombi.fila, zombi.columna, zombi.simbolo);
        }
    }
}

// Mover zombis una casilla hacia la izquierda
void Partida::moverZombis() {
    if (zombis.empty()) {
        return;
    }

    // Verificar si hay zombis que se van a mover
    bool hayMovimientos = false;
    for (const auto& zombi : zombis) {
        if (!zombi.vivo) continue;

        // Verificar si hay una planta en la casilla actual
        bool hayPlanta = false;
        for (const auto& planta : plantas) {
            if (planta.fila == zombi.fila && planta.columna == zombi.columna) {
                hayPlanta = true;
                break;
            }
        }

        if (!hayPlanta) {
            hayMovimientos = true;
            break;
        }
    }

    // Solo mostrar título si hay movimientos
    if (hayMovimientos) {
        cout << "\n--- Movimiento de zombis ---\n";
    }

    for (auto& zombi : zombis) {
        if (!zombi.vivo) continue;

        // Verificar si hay una planta en la casilla actual
        bool hayPlanta = false;
        for (const auto& planta : plantas) {
            if (planta.fila == zombi.fila && planta.columna == zombi.columna) {
                hayPlanta = true;
                break;
            }
        }

        if (!hayPlanta) {
            // No hay planta, el zombi avanza
            zombi.columna--;

            if (zombi.columna < 0) {
                cout << "\n¡UN ZOMBI HA LLEGADO A LA CASA en la fila "
                     << (zombi.fila + 1) << "!\n";
                casaInvadida = true;
                return;
            } else {
                cout << "Zombi avanza a [" << (zombi.fila + 1) << "x" << (zombi.columna + 1) << "]\n";
            }
        }
        // Si hay planta, el zombi no se mueve (ya está comiendo) y no imprime nada
    }

    actualizarMapaZombis();
}

// Fase de oleada (combate)
void Partida::faseOleada() {
    cout << "\n========== TURNO DE COMBATE ==========\n";

    zombisRestantes = nivelActual->getZombisPorOleada();
    zombis.clear();
    turnoActual = 0;

    cout << "\n¡Aparece 1 zombi!\n";
    int filaAleatoria = rand() % mapa.getFilas();
    int columnaInicial = mapa.getColumnas() - 1;
    zombis.push_back(Zombi(filaAleatoria, columnaInicial));
    zombisRestantes--;
    cout << "Zombi aparece en fila " << (filaAleatoria + 1) << "\n";

    actualizarMapaZombis();
    mostrarEstadoCompleto();

    int zombisEliminadosEsteNivel = 0;

    while ((zombisRestantes > 0 || !zombis.empty()) && !casaInvadida) {
        turnoActual++;
        // ELIMINADO: cout << "\n========================================\n";
        // ELIMINADO: cout << "--- Turno de combate " << turnoActual << " ---\n";
        // ELIMINADO: cout << "========================================\n";

        faseAcciones();
        ejecutarHabilidadesPlantas();
        zombisAtacan();
        moverZombis();

        if (casaInvadida) {
            break;
        }

        mostrarEstadoCompleto();

        int zombisAntesDeEliminar = zombis.size();
        zombis.erase(
            remove_if(zombis.begin(), zombis.end(),
                     [](const Zombi& z) { return !z.vivo; }),
            zombis.end()
        );
        int zombisEliminadosEsteTurno = zombisAntesDeEliminar - zombis.size();
        zombisEliminadosEsteNivel += zombisEliminadosEsteTurno;

        if (zombisEliminadosEsteTurno > 0 && zombisRestantes > 0) {
            generarNuevosZombis();
            actualizarMapaZombis();
        }

        if (zombis.empty() && zombisRestantes == 0) {
            cout << "\n------- ¡NIVEL " << nivelNumero << " SUPERADO! -------\n";
            cout << "Todos los zombis fueron detenidos\n";
            break;
        }

        if (turnoActual > 100) {
            cout << "\nLimite de turnos alcanzado.\n";
            break;
        }
    }

    zombisEliminados += zombisEliminadosEsteNivel;
    cout << "\n"; // Línea en blanco al final
}

// Ejecutar la partida completa
void Partida::jugar() {
    solicitarNombre();

    for (nivelNumero = 1; nivelNumero <= 10 && !casaInvadida; nivelNumero++) {
        inicializarNivel(nivelNumero);

        faseAcciones();
        faseOleada();

        // Verificar si la casa fue invadida
        if (casaInvadida) {
            break;
        }

        // Limpiar para el siguiente nivel
        zombis.clear();
        plantas.clear();

        // Si no es el último nivel, pausar antes de continuar
        if (nivelNumero < 10) {
            cout << "Presione Enter para pasar al siguiente nivel...";

            // Limpiar buffer y esperar Enter
            cin.ignore(1000, '\n');
            cin.get();
        }
    }

    if (!casaInvadida && nivelNumero > 10) {
        gano = true;
        cout << "\n╔════════════════════════════════════════╗\n";
        cout << "║            VICTORIA!                   ║\n";
        cout << "║  Completaste todos los niveles!        ║\n";
        cout << "╚════════════════════════════════════════╝\n";
    } else {
        gano = false;
        cout << "\n╔════════════════════════════════════════╗\n";
        cout << "║            DERROTA                     ║\n";
        cout << "║    Los zombis invadieron tu casa!      ║\n";
        cout << "╚════════════════════════════════════════╝\n";
    }

    guardarEstadisticas();
}

void Partida::guardarEstadisticas() {
    ofstream archivo("stats.txt", ios::app);

    if (!archivo.is_open()) {
        cout << "\nError: No se pudo guardar las estadisticas.\n";
        return;
    }

    time_t ahora = time(nullptr);
    string fecha = ctime(&ahora);
    if (!fecha.empty() && fecha[fecha.length()-1] == '\n') {
        fecha.erase(fecha.length()-1);
    }

    archivo << nombreJugador << ","
            << (gano ? "VICTORIA" : "DERROTA") << ","
            << (nivelNumero - 1) << ","
            << zombisEliminados << ","
            << soles << ","
            << fecha << "\n";

    archivo.close();
    cout << "\nEstadisticas guardadas correctamente.\n";
}