#include "prism.hpp"
#include "cuboid.hpp"

/*!
 * \file  drone.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej drona,
 *         budowanie i przemieszczanie go
 */

class Drone
{
/*!
 * \brief Zmienna reprezentujaca polozenie drona
 */
    Vector3D pos;

/*!
 * \brief Tablica graniastoslupow szesciokatnych, 
 *        reprezentujaca rotory drona
 */
    Prism rotors[4];

/*!
 * \brief Prostopadloscian reprezentujacy korpus drona
 */
    Cuboid body;
};