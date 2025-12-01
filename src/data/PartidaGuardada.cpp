#include "../../include/PartidaGuardada.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <raylib.h>
#include <string>
#include <vector>

PartidaGuardada::PartidaGuardada(Marcador marcador, MODODEJUEGO modo,
                                 MODALIDAD modalidad, int turno,
                                 bool juegoFinalizado,
                                 ESTADO_SLOT (*tablero)[7])
    : marcador(marcador), modo(modo), modalidad(modalidad), turno(turno),
      juegoFinalizado(juegoFinalizado) {

  // Recreamos el arreglo en la partida guardada para obtener una copia
  for (int i = 0; i < 6; i++) {

    for (int j = 0; j < 7; j++) {
      this->parrilla[i][j] = tablero[i][j];
    }
  }
};

void PartidaGuardada::serializarPartida(
    std::vector<PartidaGuardada> &memoryCard,
    const std::string &nombreArchivo) {

  std::cout << "SERIALIZING!" << std::endl;
  std::ofstream file(nombreArchivo, std::ios::binary);

  if (file.is_open()) {

    size_t cantidadObjetos = memoryCard.size();

    file.write(reinterpret_cast<const char *>(&cantidadObjetos),
               sizeof(cantidadObjetos));

    for (const PartidaGuardada &partida : memoryCard) {
      file.write(reinterpret_cast<const char *>(&partida.marcador),
                 sizeof(partida.marcador));
      file.write(reinterpret_cast<const char *>(&partida.modo),
                 sizeof(partida.modo));
      file.write(reinterpret_cast<const char *>(&partida.modalidad),
                 sizeof(partida.modalidad));
      file.write(reinterpret_cast<const char *>(&partida.turno),
                 sizeof(partida.turno));
      file.write(reinterpret_cast<const char *>(&partida.juegoFinalizado),
                 sizeof(partida.juegoFinalizado));

      file.write(reinterpret_cast<const char *>(partida.parrilla),
                 6 * 7 * sizeof(ESTADO_SLOT));
    }

    file.close();
  } else {
    std::cerr << "Error: No se pudo abrir el archivo para grabar." << std::endl;
  }
}

std::vector<PartidaGuardada>
PartidaGuardada::deserializarPartida(const std::string &nombreArchivo) {

  std::vector<PartidaGuardada> memoryCard;

  std::cout << "YEs sir" << std::endl;

  std::ifstream file(nombreArchivo, std::ios::binary);
  if (!file.is_open()) {
    return memoryCard;
    throw std::runtime_error("No se pudo abrir el archivo para lectura: " +
                             nombreArchivo);
  }

  // Read the number of saved games
  size_t cantidadObjetos;
  file.read(reinterpret_cast<char *>(&cantidadObjetos),
            sizeof(cantidadObjetos));

  // Read each game
  for (size_t i = 0; i < cantidadObjetos; ++i) {
    // Read basic data members
    Marcador marcador;
    MODODEJUEGO modo;
    MODALIDAD modalidad;
    int turno;
    bool juegoFinalizado;
    ESTADO_SLOT tablero[6][7];

    file.read(reinterpret_cast<char *>(&marcador), sizeof(marcador));
    file.read(reinterpret_cast<char *>(&modo), sizeof(modo));
    file.read(reinterpret_cast<char *>(&modalidad), sizeof(modalidad));
    file.read(reinterpret_cast<char *>(&turno), sizeof(turno));
    file.read(reinterpret_cast<char *>(&juegoFinalizado),
              sizeof(juegoFinalizado));

    // Read the 2D array (6x7 board)
    file.read(reinterpret_cast<char *>(tablero), 6 * 7 * sizeof(ESTADO_SLOT));

    // Create PartidaGuardada object and add to vector
    memoryCard.emplace_back(marcador, modo, modalidad, turno, juegoFinalizado,
                            tablero);
  }

  file.close();
  return memoryCard;
}

Marcador PartidaGuardada::getMarcador() { return this->marcador; }
