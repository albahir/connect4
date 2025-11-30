#pragma once

#include "Partida.h"
#define PRINCIPAL_H
#include "GameState.h"

#include "raylib.h"

class Principal {
public:
  Principal(GameState *globalState);
  void IniciarPantallaPrincipal();
  void CerrarPantallaPrincipal();

  // Setters
  void setPartida(Partida *partida);

private:
  GameState *globalState;
  Partida *partida;
};
