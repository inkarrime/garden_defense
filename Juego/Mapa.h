#ifndef MAPA_H
#define MAPA_H

#include "../Entidades/Entidad.h"
#include "../Entidades/Planta.h"
#include "../Entidades/Zombie.h"
#include "../Plantas/Girasol.h"
#include "../Plantas/Cactus.h"
#include "../Plantas/PlantaHielo.h"
#include "../Plantas/Ajo.h"
#include "../Plantas/SetaDefensiva.h"
#include "../Plantas/FlorAura.h"
#include "../Zombies/ZombieCasco.h"
#include "../Zombies/ZombieRapido.h"
#include "../Zombies/ZombieArdiente.h"
#include "../Zombies/ZombieCongelado.h"
#include "../Zombies/ZombieGordo.h"
#include "../Zombies/ZombieToxico.h"
#include <vector>
#include <iomanip>

using namespace std;

class Mapa {
private:
    static const int FILAS = 5;
    static const int COLUMNAS = 9;

    Planta* plantas[FILAS][COLUMNAS];
    vector<Zombie*> zombies;
    int hpCasa;
    int hpMaxCasa;

    void limpiarPantalla();
    void mostrarBorde();
    void mostrarEncabezado(int oleada, int soles);
    void mostrarCuadricula();
    void mostrarAcciones();

public:
    Mapa();
    ~Mapa();

    // Metodos principales
    void mostrar(int oleada, int soles);
    bool colocarPlanta(Planta* planta, int fila, int columna);
    bool eliminarPlanta(int fila, int columna);
    void agregarZombie(Zombie* zombie);

    // Gestion de turnos
    void turnosPlantas(int& soles);
    void turnosZombies();
    void procesarColisiones();
    void limpiarMuertos();

    // Validaciones
    bool posicionValida(int fila, int columna) const;
    bool casillaVacia(int fila, int columna) const;
    Planta* obtenerPlanta(int fila, int columna) const;

    // Estado del juego
    int obtenerHPCasa() const;
    bool casaDestruida() const;
    bool todosZombiesMuertos() const;
    int contarZombiesVivos() const;
    void daniarCasa(int danio);
};

#endif