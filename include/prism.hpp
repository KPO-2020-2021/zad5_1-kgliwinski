#include"block.hpp"

/*!
 * \file  prism.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej graniastoslup o podstawie o 6 wierzcholkach
 *  w przestrzeni trojwymiarowej
 */

/*!
 *  \class Prism
 *  \brief Opisuje graniastoslup o dwunastu wierzcholkach w przestrzeni trojwymiarowej
 */
class Prism: public Block
{
private:
/*!
 * \brief Tablica wektorow reprezentujacych wierzchlki dwoch rownoleglych
 * podstaw graniastoslupa
 */
    Vector3D tops[2][6];

public:
/*!
 *  \brief Konstruktor bezparametryczny klasy Prism.
 *         Powstaly granistoslup ma podstawy "tworzace":
 *                                           
 *  Argumenty:                                                                
 *      Brak argumentow.                                                      
 *  Zwraca:                                                                   
 *     \post Zwraca dwanascie wiercholkow                                   
 */
Prism();

/*!
 *  \brief Konstruktor parametryczny klasy Prism.                                              
 *  Argumenty:                                                                
 *      \param[in] tab - tablica 2x6 typu Vector3D                                                      
 *  Zwraca:                                                                   
 *     \post Zwraca dwanascie wiercholkow zadanych przez uzytkownika                                  
 */
Prism(Vector3D const (&tab)[2][6]);

/*!
 *  \brief Konstruktor parametryczny klasy Prism. Przeznaczony do konstrukcji prostopadloscianu
 *         razem z polami rodzica Block.                                                    
 *  Argumenty:                                                                
 *      \param[in] tab - tablica 2x6 typu Vector3D   
 *      \param[in] s_name - docelowo sample_name z klasy Block
 *      \param[in] f_name - docelowo final_name z klasy Block
 *      \param[in] vec - docelowo scale z klasy Block                                                     
 *  Zwraca:                                                                   
 *     \post Zwraca dwanascie wiercholkow zadanych przez uzytkownika, oraz pola klasy Block                                  
 */
Prism(Vector3D const (&tab)[2][6], const std::string &s_name, const std::string &f_name, const Vector3D &vec);

/*!
 *  \brief Konstruktor parametryczny klasy Prism.                                              
 *  Argumenty:                                                                
 *      \param[in] tovec - tablica 2x6x3 typu double                                                     
 *  Zwraca:                                                                   
 *     \post Zwraca dwanascie wiercholkow zadanych przezuzytkownika                                  
 */
Prism(double (&tovec)[2][6][3]);

/*!
 *  \brief Metoda zwracajaca wierzcholki graniastoslupa do tablicy 2x6 Vector3D                                              
 *  Argumenty:                                                                
 *      \param[in] tab - tablica 2x6 typu Vector3D                                                     
 *  Zwraca:                                                                   
 *     \post Zwraca dwanascie wiercholkow przechowywanych w klasie Cuboid i przypisuje je do podanej tablicy                                  
 */
void get_pri(Vector3D (&tab)[2][6]) const;

/*!
 *  \brief Metoda zwracajaca wierzcholki graniastoslupa do tablicy 2x6x3 typu double                                           
 *  Argumenty:                                                                
 *      \param[in] tab - tablica 2x6x3 typu double                                                     
 *  Zwraca:                                                                   
 *     \post Zwraca dwanascie wiercholkow przechowywanych w klasie Cuboid i przypisuje je do podanej tablicy                                  
 */
void get_pri(double (&tab)[2][6][3]) const;
};


/*!
 *  \brief Przeciazenie operatora <<                                                 
 *  Argumenty:                                                                
 *      \param[in] out - strumien wyjsciowy,                                             
 *      \param[in] Pri - graniastoslup.                                                      
 */
std::ostream &operator<<(std::ostream &out,  Prism const &Pri);