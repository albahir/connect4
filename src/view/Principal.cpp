#include "../../include/Principal.h"
#include "../../include/Pantalla.h"
#include "../../include/PantallaHistorial.h"
#include "../../include/PantallaJuego.h"
#include "../../include/PantallaPrincipal.h"
#include "../../include/PantallaSeleccionModalidad.h"
#include "../../include/PantallaSeleccionModo.h"
#include "raylib.h"
#include <iostream>

typedef struct LimitesBotonesPrincipal {
  Rectangle iniciarPartida;
  Rectangle PrimeroA4;
  Rectangle Acumulado;
  Rectangle JugadorVSJugador;
  Rectangle JugadorVSIa;
  Rectangle IaVSIa;
} LimitesBotonesPrincipal;

Principal::Principal(GameState *globalState) {
  this->globalState = globalState;
  this->partida = nullptr;
}

void Principal::IniciarPantallaPrincipal() {

  const int defaultWidth = 1024,
            defaultHeight =
                768; // Tamano de pantalla por defecto, necesitamos iniciar la
                     // ventana antes de poder obtener el tamano de la pantalla

  const char *gameTitle = "Conecta 4";
  const int fontSizePrincipal = 40;
  const float spacing = 5.5;

  // Comenzamos la ventana en pantalla completa
  // SetConfigFlags(FLAG_FULLSCREEN_MODE);
  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI);

  InitWindow(defaultWidth, defaultHeight, gameTitle);
  MaximizeWindow();

  /*
  SetConfigFlags(FLAG_WINDOW_UNDECORATED);
  SetConfigFlags(FLAG_WINDOW_TRANSPARENT);
  SetConfigFlags(FLAG_WINDOW_TOPMOST);
*/

  // Calcular medidas y posiciones basadas en la pantalla
  float monitorWidth = GetMonitorWidth(0);
  float monitorHeight = GetMonitorHeight(0);
  float screenWidth = GetScreenWidth();
  float screenHeight = GetScreenHeight();

  Pantalla *pantallaActual = nullptr;

  while (!WindowShouldClose() && !this->globalState->getSalirDelJuego()) {

    // Update
    switch (this->globalState->getPantallaActual()) {
    case GameState::PANTALLA_PRINCIPAL:
      pantallaActual =
          new PantallaPrincipal(globalState, screenWidth, screenHeight);
      break;
    case GameState::SELECCION_MODO:;
      pantallaActual =
          new PantallaSeleccionModo(globalState, screenWidth, screenHeight);
      break;
    case GameState::SELECCION_MODALIDAD:;
      pantallaActual = new PantallaSeleccionModalidad(globalState, screenWidth,
                                                      screenHeight);
      break;
    case GameState::PARTIDA:
      pantallaActual =
          new PantallaJuego(globalState, screenWidth, screenHeight);

      break;
    case GameState::PANTALLA_HISTORIAL:
      pantallaActual =
          new PantallaHistorial(globalState, screenWidth, screenHeight);

      break;
    }

    pantallaActual->actualizarPantalla();

    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw
    pantallaActual->dibujarPantalla(screenWidth, screenHeight);
    EndDrawing();
  }
}

void Principal::CerrarPantallaPrincipal() { CloseWindow(); }

void Principal::setPartida(Partida *partida) { this->partida = partida; }
