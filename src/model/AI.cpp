#include "../../include/AI.h"
#include "../../include/Jugador.h"

AI::AI() {}

// Retorna columna en la cual jugara
int AI::calcularJugada(ESTADO_SLOT (*parrilla)[7]) {

  int colCandidata = -1;
  int fuerzaDeColCadidata = -1;
  int fuerzaDeColActual = 0;

  static const int filas = 6;
  static const int columnas = 7;

  // Horizontal
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas - 3; j++) {

      if (parrilla[i][j] == ESTADO_SLOT::VACIO) {

        // Verificamos si el juegador contrario gana
        if (parrilla[i][j + 1] == ESTADO_SLOT::JUGADOR1 &&
            parrilla[i][j + 2] == ESTADO_SLOT::JUGADOR1 &&
            parrilla[i][j + 3] == ESTADO_SLOT::JUGADOR1) {
          colCandidata = j;
          return colCandidata;
        }

        if (parrilla[i][j + 1] == ESTADO_SLOT::JUGADOR2)
          fuerzaDeColActual += 1;

        if (parrilla[i][j + 1] == ESTADO_SLOT::JUGADOR2 &&
            parrilla[i][j + 2] == ESTADO_SLOT::JUGADOR2)
          fuerzaDeColActual += 1;

        if (parrilla[i][j + 1] == ESTADO_SLOT::JUGADOR2 &&
            parrilla[i][j + 2] == ESTADO_SLOT::JUGADOR2 &&
            parrilla[i][j + 3] == ESTADO_SLOT::JUGADOR2)
          fuerzaDeColActual += 7;
      }
      if (fuerzaDeColActual == 9)
        return j;

      if (fuerzaDeColActual > fuerzaDeColCadidata) {
        colCandidata = j;
        fuerzaDeColCadidata = fuerzaDeColActual;
        fuerzaDeColActual = 0;
      }
    }
  }
  // Vertical
  for (int i = 0; i < filas - 3; i++) {
    for (int j = 0; j < columnas; j++) {
      if (parrilla[i][j] == ESTADO_SLOT::VACIO) {

        if (parrilla[i + 1][j] == ESTADO_SLOT::JUGADOR1 &&
            parrilla[i + 2][j] == ESTADO_SLOT::JUGADOR1 &&
            parrilla[i + 3][j] == ESTADO_SLOT::JUGADOR1) {
          return j;
        }

        if (parrilla[i + 1][j] == ESTADO_SLOT::JUGADOR2)
          fuerzaDeColActual += 1;

        if (parrilla[i + 1][j] == ESTADO_SLOT::JUGADOR2 &&
            parrilla[i + 2][j] == ESTADO_SLOT::JUGADOR2)
          fuerzaDeColActual += 1;

        if (parrilla[i + 1][j] == ESTADO_SLOT::JUGADOR2 &&
            parrilla[i + 2][j] == ESTADO_SLOT::JUGADOR2 &&
            parrilla[i + 3][j] == ESTADO_SLOT::JUGADOR2)
          fuerzaDeColActual += 5;
      }
      if (fuerzaDeColActual == 9)
        return j;

      if (fuerzaDeColActual > fuerzaDeColCadidata) {
        colCandidata = j;
        fuerzaDeColCadidata = fuerzaDeColActual;
        fuerzaDeColActual = 0;
      }
    }
  }
  // Diagonal \ (Descendente)
  for (int i = 0; i < filas - 3; i++) {
    for (int j = 0; j < columnas - 3; j++) {
      if (parrilla[i][j] == ESTADO_SLOT::VACIO) {

        if (parrilla[i + 1][j + 1] == ESTADO_SLOT::JUGADOR1 &&
            parrilla[i + 2][j + 2] == ESTADO_SLOT::JUGADOR1 &&
            parrilla[i + 3][j + 3] == ESTADO_SLOT::JUGADOR1) {
          return j;
        }

        if (parrilla[i + 1][j + 1] == ESTADO_SLOT::JUGADOR2)
          fuerzaDeColActual += 1;

        if (parrilla[i + 1][j + 1] == ESTADO_SLOT::JUGADOR2 &&
            parrilla[i + 2][j + 2] == ESTADO_SLOT::JUGADOR2)
          fuerzaDeColActual += 1;

        if (parrilla[i + 1][j + 1] == ESTADO_SLOT::JUGADOR2 &&
            parrilla[i + 2][j + 2] == ESTADO_SLOT::JUGADOR2 &&
            parrilla[i + 3][j + 3] == ESTADO_SLOT::JUGADOR2)
          fuerzaDeColActual += 5;
      }
      if (fuerzaDeColActual == 9)
        return j;

      if (fuerzaDeColActual > fuerzaDeColCadidata) {
        colCandidata = j;
        fuerzaDeColCadidata = fuerzaDeColActual;
        fuerzaDeColActual = 0;
      }
    }
  }
  // Diagonal / (Ascendente)
  for (int i = 3; i < filas; i++) {
    for (int j = 0; j < columnas - 3; j++) {
      if (parrilla[i][j] == ESTADO_SLOT::VACIO) {

        if (parrilla[i - 1][j + 1] == ESTADO_SLOT::JUGADOR1 &&
            parrilla[i - 2][j + 2] == ESTADO_SLOT::JUGADOR1 &&
            parrilla[i - 3][j + 3] == ESTADO_SLOT::JUGADOR1) {
          return j;
        }

        if (parrilla[i - 1][j + 1] == ESTADO_SLOT::JUGADOR2)
          fuerzaDeColActual += 1;

        if (parrilla[i - 1][j + 1] == ESTADO_SLOT::JUGADOR2 &&
            parrilla[i - 2][j + 2] == ESTADO_SLOT::JUGADOR2)
          fuerzaDeColActual += 1;

        if (parrilla[i - 1][j + 1] == ESTADO_SLOT::JUGADOR2 &&
            parrilla[i - 2][j + 2] == ESTADO_SLOT::JUGADOR2 &&
            parrilla[i - 3][j + 3] == ESTADO_SLOT::JUGADOR2)
          fuerzaDeColActual += 5;
      }
      if (fuerzaDeColActual == 9)
        return j;

      if (fuerzaDeColActual > fuerzaDeColCadidata) {
        colCandidata = j;
        fuerzaDeColCadidata = fuerzaDeColActual;
        fuerzaDeColActual = 0;
      }
    }
  }

  return colCandidata;
}
