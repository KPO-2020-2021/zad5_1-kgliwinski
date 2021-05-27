#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include "drone.hpp"
#include "lacze_do_gnuplota.hpp"


constexpr int SIZE = 2;

/*!
 * \file  scene.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej scene,
 *         obslugujacej zapis do plikow i wytswietlanie w gnuplocie
 */

/*!
 *  \class Scene
 *  \brief Opisuje scene w 3D w ktorej poruszaja sie drony
 */
class Scene
{
private:

/*!
 * \brief Tablica dronow obslugiwanych w programie
 */
    Drone flies[SIZE];

/*!
 * \brief Nazwa pliku w ktorym zawarta jest plaszczyzna
 *         reprezentujaca podloze (ziemie) w Gnuplocie
 */
    std::string land_name;

public:

/*!
 * \brief Konstruktor paramereyczny klasy Scene
 *  Argumenty:
 *      \param[in] pos - tablica polozen dronow
 *      \param[in] scal - tablica skali dronow
 *      \param[in] name - nazwa pliku w ktorym opisana jest
 *                          plaszczyzna sceny
 *  Zwraca:
 *      \post Ustawia odpowiednie wartosci klasy, zadane przez uzytkownika
 */
Scene(Vector3D const (&pos)[SIZE],Vector3D const (&scal)[SIZE], std::string const &name);

void choose_drone();
};