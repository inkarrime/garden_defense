#ifndef OLEADA_H
#define OLEADA_H

#include "../Entidades/Zombie.h"
#include "../Zombies/ZombieCasco.h"
#include "../Zombies/ZombieRapido.h"
#include "../Zombies/ZombieArdiente.h"
#include "../Zombies/ZombieCongelado.h"
#include "../Zombies/ZombieGordo.h"
#include "../Zombies/ZombieToxico.h"
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Oleada {
private:
    int numeroOleada;
    int cantidadZombies;
    vector<Zombie*> zombiesGenerados;

    void generarZombiesAleatorios();
    Zombie* crearZombieAleatorio(int fila);

public:
    Oleada(int numeroOleada);
    ~Oleada();

    void generar();
    vector<Zombie*> obtenerZombies();
    int obtenerNumero() const;
    int obtenerCantidadZombies() const;
    void mostrarInformacion() const;
};

#endif