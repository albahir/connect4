#pragma once

#define JUGADOR_H

#include "EstadoSlot.h"
#include <raylib.h>

class Jugador {
public:
  Jugador();
  //~Jugador() = default;
  void colocarFicha(int fila, int columna);
  int calcularJugada(ESTADO_SLOT (*parrilla)[7]);

private:
  Color colorFicha;
};
