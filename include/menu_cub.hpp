#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "cuboid.hpp"
#include "prism.hpp"
#include "lacze_do_gnuplota.hpp"
#include "matrix4D.hpp"

/*!
 * \file  menu_cub.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej menu obslugi
 *         menu dla obrotow 3D
 */

/*!
 *  \class Menu_cub
 *  \brief Opisuje menu dla obrotow 3D
 */
class Menu_cub
{
private:
    /*!
 * \brief Zmienna mowiaca czy menu jest aktywne
 */
    bool open;

    /*!
 * \brief Macierz obrotu, ma sluzyc do zapisu i uzycia
 *        Macierz pozostanie w pamieci, dopoki uzytkownik
 *        nie zacznie definiowac nowej (nie zacznie wpisywac
 *        osi i katow
 */
    Matrix3D rot_mat;

public:
/*!
 * \brief Konstruktor bezparametryczny menu
 */
    Menu_cub();
/*!
 *  \brief Inicjuje menu
 *  Argumenty:
 *      \param[in] - tablica Vector3D 2x4
 */
    void init_menu(Vector3D (&tab)[2][4]);

/*!
 *  \brief Sprawdza i wyswietla wszelkie asercje odnosnie prostopadloscianu
 *  Argumenty:
 *      \param[in] cub - sprawdzany prostopadloscian
 */
    bool assert(Cuboid const &cub);

/*!
 * \brief Obsluguje wybor menu
 *  Argumenty:
 *      \param[in] oper - operator switch'a
 *      \param[in] cub - wyswietlany prostopadloscian
 */
    void switch_menu(const char &oper, Cuboid &cub);
/*!
 * \brief Obsluguje skladanie rotacji obrotu
 */
    Matrix3D switch_rotation();

/*!
 * \brief Wyswietla informacje o bokach figury na standardowym wyjsciu
 *  Argumenty:
 *      \param[in] cub - wyswietlany prostopadloscian
 */
    void print_side_len(Cuboid const &cub) const;

/*!
 * \brief Wyswietla menu
 */
void show_menu();

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] filename - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] cub - wyswietlany prostopadloscian
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
    bool CuboidToFile(const char *filename, Cuboid const &cub);

/*!
 * \brief Wyswietla prostopadloscian w GNUplocie
 *  Argumenty:
 *      \param[in] cub - wyswietlany prostopadloscian
 */
    void Print_to_gnuplot(Cuboid const &cub);

/*!
 * \brief Wyswietla graniastoslup w GNUplocie
 *  Argumenty:
 *      \param[in] pri - wyswietlany graniastoslup
 */
    void Print_to_gnuplot(Prism const &pri);

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] filename - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] pri - wyswietlany graniastoslup
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
    bool PrismToFile(const char *filename, Prism const &pri);
};