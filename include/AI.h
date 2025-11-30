#pragma once

#define AI_H
#include "Jugador.h"

class AI {
public:
  AI();
  void colocarFicha(int fila, int columna);
  int calcularJugada(ESTADO_SLOT (*parrilla)[7]);
};
