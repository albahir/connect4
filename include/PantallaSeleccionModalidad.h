#pragma once

#define PANTALLASELECCIONMODALIDAD_H
#include "GameState.h"
#include "Menu.h"
#include "Pantalla.h"

class PantallaSeleccionModalidad : public Pantalla {
public:
  PantallaSeleccionModalidad(GameState *globalState, float screenWidth,
                             float screenHeight);
  void dibujarPantalla(float screenWidth, float screenHeight) override;
  void actualizarPantalla() override;

private:
  Menu menu;
  GameState *globalState;
};
