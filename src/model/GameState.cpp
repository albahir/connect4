#include "../../include/GameState.h"
#include "../../include/Pantalla.h"
#include <iostream>
#include <vector>

GameState::GameState(std::vector<PartidaGuardada> memoryCard) {
  this->partidaActual = nullptr;
  this->modo = NINGUNO;
  this->modalidad = NINGUNA;
  this->pantallaActual = PANTALLA_PRINCIPAL;
  this->memoryCard = memoryCard;
}

void GameState::setPartidaActual(Partida *nuevaPartida) {
  this->partidaActual = nuevaPartida;
}

Partida *GameState::getPartidaActual() { return this->partidaActual; }

void GameState::setModoDeJuego(MODODEJUEGO modo) { this->modo = modo; };
MODODEJUEGO GameState::getModoDeJuego() { return this->modo; };

void GameState::setModalidad(MODALIDAD modalidad) {
  this->modalidad = modalidad;
};

MODALIDAD GameState::getModalidad() { return this->modalidad; };

void GameState::setPantallaActual(PANTALLA pantallaActual) {
  this->pantallaActual = pantallaActual;
};

void GameState::printSavedGames() {

  // std::cout << "Here brother!" << std::endl;

  // std::cout << "Size of memoryCard: " << this->memoryCard.size() <<
  // std::endl;

  int i = 1;

  for (PartidaGuardada partida : memoryCard) {

    std::cout << "Partida Guardada: " << i << std::endl;
    i++;
  }
}

GameState::PANTALLA GameState::getPantallaActual() {
  return this->pantallaActual;
};

void GameState::setSalirDelJuego(bool salir) { this->salirDelJuego = salir; };
bool GameState::getSalirDelJuego() { return this->salirDelJuego; };

std::vector<PartidaGuardada> GameState::getMemoryCard() {
  return this->memoryCard;
}

void GameState::pushMemoryCard(Partida *partidaAGuardar) {

  PartidaGuardada partida = PartidaGuardada(
      partidaAGuardar->getMarcador(), partidaAGuardar->getModoDeJuego(),
      partidaAGuardar->getModalidad(), partidaAGuardar->getTurno(),
      partidaAGuardar->getFinalizado(), partidaAGuardar->getParrilla());

  this->memoryCard.push_back(partida);

  PartidaGuardada::serializarPartida(this->memoryCard, "partidasConnect4");
}
