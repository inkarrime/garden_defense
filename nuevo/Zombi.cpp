#include "Zombi.h"

// ==================== IMPLEMENTACIÓN ZOMBI ====================

// Constructor
Zombi::Zombi(string nombre, int hp, int danio, int velocidad, int fila, int columna, char simbolo)
    : Entidad(nombre, hp, fila, columna, simbolo), danio(danio), velocidad(velocidad), posicionInterna(0) {}

// Destructor
Zombi::~Zombi() {}

// Getters
int Zombi::getDanio() const {
    return danio;
}

int Zombi::getVelocidad() const {
    return velocidad;
}

int Zombi::getPosicionInterna() const {
    return posicionInterna;
}

// Método mover - 1 espacio por casilla
void Zombi::mover() {
    // Cada llamada a mover() avanza directamente a la siguiente columna
    columna--;
    cout << nombre << " avanza a columna " << columna << endl;
}

// Método atacar
void Zombi::atacar(Entidad* objetivo) {
    if(objetivo) {
        objetivo->recibirDanio(danio);
        cout << nombre << " ataca! Danio: " << danio << endl;
    }
}

// Override de mostrarInfo
void Zombi::mostrarInfo() const {
    Entidad::mostrarInfo();
    cout << " | Danio: " << danio << " | PosInterna: " << posicionInterna;
}

// ZOMBI BASICO

ZombiBasico::ZombiBasico(int fila, int columna)
    : Zombi("Zombi Basico", 100, 10, 1, fila, columna, 'Z') {}

ZombiBasico::~ZombiBasico() {}

// ==================== IMPLEMENTACIÓN ZOMBI CON CASCO ====================

ZombiCasco::ZombiCasco(int fila, int columna)
    : Zombi("Zombi Casco", 150, 12, 1, fila, columna, 'C'), armadura(100), tieneArmadura(true) {}

ZombiCasco::~ZombiCasco() {}

void ZombiCasco::recibirDanio(int danio) {
    if(tieneArmadura) {
        // La armadura absorbe el daño primero
        armadura -= danio;
        cout << nombre << " - Armadura absorbe " << danio << " de danio. Armadura restante: " << armadura << endl;

        if(armadura <= 0) {
            // Si la armadura se rompe, el daño sobrante va al HP
            int danioSobrante = -armadura;
            armadura = 0;
            tieneArmadura = false;
            hp -= danioSobrante;
            if(hp < 0) hp = 0;
            cout << "¡Armadura rota! " << danioSobrante << " de danio al HP. HP restante: " << hp << endl;
        }
    } else {
        // Sin armadura, daño directo al HP
        hp -= danio;
        if(hp < 0) hp = 0;
        cout << nombre << " recibe " << danio << " de danio. HP restante: " << hp << endl;
    }
}

int ZombiCasco::getArmadura() const {
    return armadura;
}

bool ZombiCasco::tieneArmaduraActiva() const {
    return tieneArmadura;
}