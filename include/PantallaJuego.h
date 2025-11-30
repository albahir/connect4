#pragma once

#define PANTALLAJUEGO_H
#include "GameState.h"
#include "Menu.h"
#include "Pantalla.h"
#include "Partida.h"

class PantallaJuego : public Pantalla {
public:
  PantallaJuego(GameState *globalState, float screenWidth, float screenHeight);
  PantallaJuego(float screenWidth, float screenHeight);
  void dibujarPantalla(float screenWidth, float screenHeight) override;
  void actualizarPantalla() override;
  void mostrarGanador();

private:
  Menu menu;
  GameState *globalState;
  bool ganador;
  float screenWidth;
  float screenHeight;
};
