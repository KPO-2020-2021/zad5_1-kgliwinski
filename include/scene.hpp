#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include "drone.hpp"
#include "lacze_do_gnuplota.hpp"


constexpr unsigned int SIZE = 2;

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
 * \brief Wskaznik na aktywnego drona. Wartosc koresponduje z ta
 *          z tablicy flies (drony sa numerowane w zakresie 0 , 1 , ... , (SIZE-1))
 */

    unsigned int active;

/*!
 * \brief Nazwa pliku w ktorym zawarta jest plaszczyzna
 *         reprezentujaca podloze (ziemie) w Gnuplocie
 */
    std::string land_name;

public:

/*!
 * \brief Konstruktor paramereyczny klasy Scene
 *    
 *      \param[in] pos - tablica polozen dronow
 *      \param[in] scal_bod - tablica skali korpusow dronow
 *      \param[in] scal_rot - tablica skali rotorow dronow
 *      \param[in] name - nazwa pliku w ktorym opisana jest
 *                          plaszczyzna sceny
 *     
 *      \post Ustawia odpowiednie wartosci klasy, zadane przez uzytkownika
 */
Scene(Vector3D const (&pos)[SIZE], Vector3D const (&scal_bod)[SIZE],Vector3D const (&scal_rot)[SIZE], std::string const &name );

/*!
 * \brief Metoda sprawdzajaca poprawnosc inicjacji sceny
 *     
 *      \retval true - scena poprawnie zainicjowana
 *      \retval false - scena blednie zainicjowana
 */
bool check_scene() const;

/*!
 *  \brief Przeciazenie operatora == dla klasy Scene    
 *          \b{Parametr active jest pomijany}                                         
 *                                                                    
 *      \param[in] pri - porownywana scena                                            
 *     
 *      \retval false - nie sa rowne, 
 *      \retval true - sa rowne                                                     
 */
bool operator == (const Scene &sce) const;


/*!
 * \brief Metoda pozwalajaca na wybor aktywnego drona
 *    
 *      \param[in] ch - nowo wybrany dron
 *     
 *      \post Wybiera aktywnego drona (wartosc klasy active)
 *      \retval false - jesli zadana wartosc jest spoza zakresu
 *      \retval true - jesli zadana wartosc jest poprawna
 */
bool choose_drone(unsigned int const &ch);

/*!
 * \brief Metoda inicjalizujaca lacze do gnuplota
 *
 *  \post Powstaje w pelni skonfigurowane lacze, ktore 
 *          moze byc uzyte do rysowanie calej sceny
 */
PzG::LaczeDoGNUPlota init_gnuplot();
};