
#pragma once

#define PANTALLAHISTORIAL_H
#include "GameState.h"
#include "Menu.h"
#include "Pantalla.h"

class PantallaHistorial : public Pantalla {
public:
  PantallaHistorial(GameState *globalState, float screenWidth,
                    float screenHeight);
  void dibujarPantalla(float screenWidth, float screenHeight) override;
  void actualizarPantalla() override;

private:
  Menu menu;
  GameState *globalState;
  float screenWidth;
  float screenHeight;
};
