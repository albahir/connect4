#include "../../include/PantallaHistorial.h"
#include <raylib.h>
#include <vector>

typedef struct {
  Rectangle btnVolver;
  Rectangle btnPartidaGuardada;
} BtnsMenuHistorial;

PantallaHistorial::PantallaHistorial(GameState *globalState, float screenWidth,
                                     float screenHeight)
    : globalState(globalState), screenWidth(screenWidth),
      screenHeight(screenHeight) {

  BtnsMenuHistorial btns = {
      // Volver al menu principal
      {.x = 10, .y = 50, .width = 150, .height = 60},
      // Boton para cargar partida guardada
      {.x = screenWidth / 10 * 6,
       .y = screenHeight / 2 + 100,
       .width = 340,
       .height = 60},
  };

  this->menu.agregarBoton(Boton(btns.btnVolver, "Volver", BLUE, [this]() {
    this->globalState->setPantallaActual(GameState::PANTALLA_PRINCIPAL);
  }));
}

void PantallaHistorial::dibujarPantalla(float screenWidth, float screenHeight) {

  static const float fontSize = 60;
  static Font defaultFont = GetFontDefault();
  static const char *gameTitle = "Historial de Partidas";
  static const float spacing = 3.5f;

  Vector2 titleWidth =
      (MeasureTextEx(defaultFont, gameTitle, fontSize, spacing));
  int titleLocationX = (screenWidth - titleWidth.x) / 2;
  int titleLocationY = screenHeight / 12;

  // Dibujando titulos y subtitulos de menu
  DrawTextEx(defaultFont, gameTitle,
             {(float)titleLocationX, (float)titleLocationY}, fontSize, spacing,
             DARKGRAY);

  this->menu.dibujarBotones();
}

void PantallaHistorial::actualizarPantalla() { this->menu.btnListeners(); }
