#pragma once
#include <fstream>
#include"block.hpp"

/*!
 * \file  prism.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej graniastoslup o podstawie o 6 wierzcholkach
 *  w przestrzeni trojwymiarowej
 *  
 *  \image html prism3D.png
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

/*!
 * \brief Wektor bedacy srodkiem symetrii wierzcholkow graniastoslupa szesciokatnego
 */
Vector3D centre;

/*!
 * \brief Tablica wektorow reprezentujacych punkty szczegolne graniastoslupa:
 *        Dwa punkty bedace przecieciami przekatnych dwoch przeciwleglych scian graniastoslupa
 */
Vector3D cuts[2];

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
 *     \post Zwraca dwanascie wiercholkow zadanych przez uzytkownika                                  
 */
Prism(double (&tovec)[2][6][3]);

/*!
 *  \brief Konstruktor parametryczny klasy Prism. Przeznaczony do konstrukcji prostopadloscianu
 *         razem z polami rodzica Block.                                                    
 *  Argumenty:                                                                
 *      \param[in] tab - tablica 2x6x3 typu double   
 *      \param[in] s_name - docelowo sample_name z klasy Block
 *      \param[in] f_name - docelowo final_name z klasy Block
 *      \param[in] vec - docelowo scale z klasy Block                                                     
 *  Zwraca:                                                                   
 *     \post Zwraca dwanascie wiercholkow zadanych przez uzytkownika, oraz pola klasy Block                                  
 */
Prism(double (&tovec)[2][6][3], const std::string &s_name, const std::string &f_name, const Vector3D &vec);

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

/*!
 *  \brief Sprawdza czy graniastoslup jest poprawnie zbudowany                                            
 *  Argumenty:                                                                                                                    
 *  Zwraca:                                                                   
 *     \retval true - jest poprawny
 *     \retval false - nie jest poprawny                                   
 */
bool check_pri();

/*!
 *  \brief Metoda zwracajaca do tablicy wektorow
 *         wektory "pionowe" graniastoslupa
 *         (czyli te ktore sa wzgledem siebie rownolegle
 *          i lacza ze soba wierzcholki podstaw)                                           
 *  Argumenty:  
 *      \param[in] vecs - tablica 6 wektorow na 6 kolejnych zwracanych
 *                        odcinkow zwracanych przez metode                                                                                                                  
 *  Zwraca:                                                                   
 *     \post przypisuje polom tablicy odpowiednie wektory graniastoslupa                                  
 */
void get_vec_ver(Vector3D (&vecs) [6]) const;

/*!
 *  \brief Metoda sprawdzajaca czy wektory zwrocone przez get_vec_ver()
 *         sa rowne                                                                                                                                                         
 *  Zwraca:                                                                   
 *     \retval true - jesli sa rowne
 *     \retval false - jesli nie sa rowne                                
 */
bool check_vec_ver() const;

/*!
 *  \brief Metoda zwracajaca do tablicy wektorow
 *         wektory "przeciwlegle" obydwoch podstaw graniastoslupa:
 *         Dla 2 podstaw -> 3 pary -> 2 wektory                                          
 *  Argumenty:  
 *      \param[in] vecs - tablica 2x3x2 wektorow na 12 kolejnych zwracanych
 *                        par odcinkow zwracanych przez metode                                                                                                                  
 *  Zwraca:                                                                   
 *     \post przypisuje polom tablicy odpowiednie wektory graniastoslupa                                  
 */
void get_vec_pairs(Vector3D (&vecs) [2][3][2]) const;

/*!
 *  \brief Metoda sprawdzajaca czy wektory zwrocone przez get_vec_opp()
 *         sa parami rowne. Ponadto sprawdza tez rownosc dla przeciwleglych
 *         podstaw graniastoslupa.                                                                                                                                                     
 *  Zwraca:                                                                   
 *     \retval true - jesli sa rowne
 *     \retval false - jesli nie sa rowne                                
 */
bool check_vec_pairs() const;

/*!
 *  \brief Metoda sprawdzajaca katy miedzy krawedziami "pionowymi"
 *          graniastoslupa sa prostopadle do podstaw.                                                                                                                                                 
 *  Zwraca:                                                                   
 *     \retval true - jesli sa prostopadle
 *     \retval false - jesli nie sa prostopadle                                
 */
bool check_vec_perp() const;

/*!
 *  \brief Metoda sprawdzajaca katy wewnetrzne podstaw
 *          graniastoslupa sa rowne 60 st.                                                                                                                                               
 *  Zwraca:                                                                   
 *     \retval true - jesli sa rowne
 *     \retval false - jesli nie sa rowne                                
 */
bool check_vec_basis() const;

/*!
 *  \brief Przeciazenie operatora == dla klasy Prism                                               
 *  Argumenty:                                                                
 *      \param[in] pri - porownywany Prism                                             
 *  Zwraca:
 *      \retval false - nie sa rowne, 
 *      \retval true - sa rowne                                                     
 */
bool operator == (const Prism &pri) const;

/*!
 *  \brief Metoda przesuwajaca graniastoslup o zadany wektor w 3D                                            
 *  Argumenty:                                                                
 *      \param[in] trans - Vector3D                                                     
 *  Zwraca:                                                                   
 *     \param[out] translated - graniastoslup po operacji przesuniecia                                
 */
Prism translation(Vector3D const &tran) const;

/*!
 *  \brief Metoda przesuwajaca graniastoslup o zadany wektor w 3D w taki sposob,
 *          ze srodek jego dolnej podstawy pokrywa sie z pewnym (zadanym) punktem.
 *         Metoda przydatna glownie w konstruowaniu drona                                         
 *  Argumenty:                                                                
 *      \param[in] pt - Vector3D reprezentujacy punkt, w ktorym po translacji
 *                         ma sie znalezc srodek dolnej podstawy graniastoslupa                                                 
 *  Zwraca:                                                                   
 *     \param[out] translated - graniastoslup po operacji przesuniecia                                
 */
Prism translation_of_lower_cen(Vector3D const &pt) const;

/*!
 *  \brief Metoda przesuwajaca graniastoslup do srodka ukladu wspolrzednych
 *         (tak, ze srodek graniastoslupa pokrywa sie z (0,0,0))                                            
 *  Argumenty:                                                                                                               
 *  Zwraca:                                                                   
 *     \param[out] translated - graniastoslup po operacji przesuniecia                                
 */
Prism translation_to_O() const;

/*!
 *  \brief Metoda obracajaca graniastoslup o zadany kat w 3D wokol srodka figury                                      
 *  Argumenty:                                                                
 *      \param[in] mat - macierz obrotu                                                  
 *  Zwraca:                                                                   
 *     \param[out] rotated - graniastoslup po operacji rotacji                               
 */
Prism rotation_around_cen(Matrix3D const &mat) const;


/*!
 *  \brief Metoda zwracajaca punkt centralny (czyli taki, ktorego odleglosci
 *         do kazdego wierzcholka sa rowne) graniastoslupa. Zgodnie z geometria
 *         graniastoslupa, lezy on na przecieciu jego przekatnych lub w polowie
 *         jednej z przekatnych, z czego korzysta ta metoda. Zwracana wartosc jest
 *         w globalnym ukladzie odniesienia.                                          
 *  Argumenty:                                                                
 *      brak                                                    
 *  Zwraca:                                                                   
 *     \return point - Vector3D wskazujacy ze srodka ukladu wspolrzednych
 *                     na punkt centralny graniastoslupa                              
 */

Vector3D centre_point() const;

/*!
 *  \brief Metoda zwracajaca punkty specjalne graniastoslupa : cuts (czyli
 *         te ktore sa przecieciami przekatnych dwoch przeciwleglych
 *         podstaw graniastoslupa) oraz punkt centre                                     
 *  Argumenty:                                                                
 *      \param[in] vecs - tablica wektorow do ktorych program zwroci wartosci                                                    
 *  Zwraca:                                                                   
 *     \post - metoda ustawia wartosci w polach tablicy
 *     \return - metoda zwraca punkt centre                         
 */
Vector3D special_points(Vector3D (&vecs)[2]) const;

/*!
 *  \brief Metoda wypisania odpowiednich wierzcholkow do pliku
 *         zgodnie z zaproponowanym sposobem zadaniu dron                            
 *  Argumenty:                                                                
 *      \param[in] out - strumien wyjsciowy,                                                                                                
 */
void print_prism_3D(std::ostream &out) const;

/*!
 *  \brief Metoda wczytywania odpowiednich wierzcholkow z pliku wzorcowego
 *         zgodnie z zaproponowanym sposobem zadaniu dron.
 *         Przypisuje wczytane wierzcholki do graniastoslupa.                         
 *  Zwraca:
 *      \param[out] pri - wczytwany graniastoslup                                                                                                 
 */
Prism Prism_From_Sample() const;

/*!
 * Zapis wspolrzednych graniastoslupa do pliku
 * \param[in] filename - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * Zwraca:
 *      \retval true - gdy operacja zapisu powiodła się,
 *      \retval false - w przypadku przeciwnym.
 */
    bool Prism_To_File(const std::string &filename) const;

/*!
 *  \brief Metoda skalujaca o wektor scale bedacy
 *         czlonkiem klasy block                         
 *  
 *   \return zwraca zeskalowany graniastoslup                                                                                               
 */
Prism scale_pri() const;

/*!
 *  \brief Metoda skalujaca o wektor scal podany na wejsciu                         
 *  Argumenty:                                                                
 *      \param[in] scal - wektor o ktory chcemy skalowac,    
 *  
 *      \return zwraca zeskalowany graniastoslup                                                                                              
 */
Prism scale_pri(Vector3D const &scal) const;
};


/*!
 *  \brief Przeciazenie operatora <<                                                 
 *  Argumenty:                                                                
 *      \param[in] out - strumien wyjsciowy,                                             
 *      \param[in] Pri - graniastoslup.                                                      
 */
std::ostream &operator<<(std::ostream &out,  Prism const &Pri);