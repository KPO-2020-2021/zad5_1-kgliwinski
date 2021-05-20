#include"block.hpp"

/*!
 * \file  cuboid.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej prostopadloscian
 *  w przestrzeni trojwymiarowej
 */


/*!
 *  \class Cuboid
 *  \brief Opisuje prostopadloscian w przestrzeni trojwymiarowej
 */
class Cuboid: public Block{
private:
/*!
 * \brief Tablica wektorow reprezentujacych wierzchlki dwoch rownoleglych
 * podstaw prostopadloscianu
 */
Vector3D tops[2][4];

public:

/*!
 *  \brief Konstruktor bezparametryczny klasy Cuboid.
 *          Powstaly prostopadloscian ma dwa prostokaty "tworzace":
 *          p1 = [0][0] = (0,0,0), [0][1] =  (1,0,0), [0][2] = (1,1,0), [0][3] = (0,1,0)      
 *          p2 = [1][0] = (0,0,1), [1][1] =  (1,0,1), [1][2] = (1,1,1), [1][3] = (0,1,1)                                            
 *  Argumenty:                                                                
 *      Brak argumentow.                                                      
 *  Zwraca:                                                                   
 *     \post Zwraca osiem wiercholkow                                   
 */
Cuboid();

/*!
 *  \brief Konstruktor parametryczny klasy Cuboid.                                              
 *  Argumenty:                                                                
 *      \param[in] tab - tablica 2x4 typu Vector3D                                                      
 *  Zwraca:                                                                   
 *     \post Zwraca osiem wiercholkow zadanych przez program                                  
 */
Cuboid(Vector3D const (&tab)[2][4]);

/*!
 *  \brief Konstruktor parametryczny klasy Cuboid. Przeznaczony do konstrukcji prostopadloscianu
 *         razem z polami rodzica Block                                           
 *  Argumenty:                                                                
 *      \param[in] tab - tablica 2x4 typu Vector3D 
 *      \param[in] s_name - docelowo sample_name z klasy Block
 *      \param[in] f_name - docelowo final_name z klasy Block
 *      \param[in] vec - docelowo scale z klasy Block                                                
 *  Zwraca:                                                                   
 *     \post Zwraca osiem wiercholkow zadanych przez program, oraz pola klasy Block                                 
 */
Cuboid(Vector3D const (&tab)[2][4], const std::string &s_name, const std::string &f_name, const Vector3D &vec);

/*!
 *  \brief Konstruktor parametryczny klasy Cuboid.                                              
 *  Argumenty:                                                                
 *      \param[in] tovec - tablica 2x4x3 typu double                                                     
 *  Zwraca:                                                                   
 *     \post Zwraca osiem wiercholkow zadanych przez program                                  
 */
Cuboid(double (&tovec)[2][4][3]);

/*!
 *  \brief Sprawdza czy prostopadloscian jest poprawnie zbudowany                                            
 *  Argumenty:                                                                                                                    
 *  Zwraca:                                                                   
 *     \retval true - jest zgodny
 *     \retval false - nie jest zgodny                                   
 */
bool check_cub() const;

/*!
 *  \brief Zwraca do tablicy 3x2 wektory reprezentujace
 *              przeciwne boki prostopadloscianu                                           
 *  Argumenty:  
 *      \param[in] vecs - tablica 3x2 typu Vector3D do ktorej
 *                        program zwraca boki                                                                                                                
 *  Zwraca:                                                                   
 *     brak                                 
 */
void get_vec_opp(Vector3D (&vecs)[3][2]) const;

/*!
 *  \brief Sprawdza czy wektory tworzace przeciwne boki prostopadloscianu
 *          sa rowne                                          
 *  Argumenty:
 *       brak                                                                                                       
 *  Zwraca:                                                                   
 *     \retval true - sa rowne
 *     \retval false - nie sa rowne                                  
 */
bool check_vec_opp() const;

/*!
 *  \brief Sprawdza czy dlugosci wektory tworzace przeciwne boki prostopadloscianu
 *          maja poprawne wartosci (nie sa rowne 0)                                          
 *  Argumenty:
 *       brak                                                                                                       
 *  Zwraca:                                                                   
 *     \retval true - maja poprawne wartosci
 *     \retval false - nie maja poprawnych wartosci                                  
 */
bool check_vec_len() const;

/*!
 *  \brief Zapisuje do tablicy tab w kolejnosci:
 *          1.dluzsze przeciwlegle boki
 *          2.krotsze przeciwlegle boki
 *          3.poprzeczne przeciwlegle boki
 *         Wartosci dlugosci tych bokow                                      
 *  Argumenty:
 *       \param[in] tab - tablica x3 do ktorej zapisza sie wartosci                                                                                                       
 *  Zwraca:                                                                                                  
 */
void get_vec_len(double (&tab)[3][2]) const;

/*!
 *  \brief Zwraca do tablicy 2x3 wektory reprezentujace
 *          boki przy wierzcholkach [0][1] (do vecs[0])
 *          i [1][3] (do vecs[1]) prostopadloscianu                                         
 *  Argumenty:  
 *      \param[in] vecs - tablica 2x3 typu Vector3D do ktorej
 *                        program zwraca boki                                                                                                                
 *  Zwraca:                                                                   
 *     brak                                 
 */
void get_vec_perp(Vector3D (&vecs)[2][3]) const;

/*!
 *  \brief Sprawdza czy wektory tworzace niektore konkretne boki prostokata
            (glownie te przy wierzcholkach) sa prostopadle                                   
 *  Argumenty:        
 *         brak                                                                                                            
 *  Zwraca:                                                                   
 *     \retval true - sa prostopadle
 *     \retval false - nie sa prostopadle                                 
 */
bool check_vec_perp() const;

/*!
 *  \brief Metoda zwracajaca wierzcholki prostopadloscianu do Vector3D                                              
 *  Argumenty:                                                                
 *      \param[in] tab - tablica 2x4 typu Vector3D                                                     
 *  Zwraca:                                                                   
 *     \post Zwraca osiem wiercholkow przechowywanych w klasie Cuboid i przypisuje je do podanej tablicy                                  
 */
void get_cub(Vector3D (&tab)[2][4]) const;

/*!
 *  \brief Metoda zwracajaca wierzcholki prostopadloscianu do tablicy                                             
 *  Argumenty:                                                                
 *      \param[in] tab - tablica 2x4x3 typu double                                                   
 *  Zwraca:                                                                   
 *     \post Zwraca osiem wiercholkow przechowywanych w klasie Cuboid i przypisuje je do podanej tablicy                                  
 */
void get_cub(double (&tab)[2][4][3]) const;

/*!
 *  \brief Przeciazenie operatora == dla klasy Cuboid                                                
 *  Argumenty:                                                                
 *      \param[in] cub - porownywany Cuboid                                             
 *  Zwraca:
 *      \retval false - nie sa rowne, 
 *      \retval true - sa rowne                                                     
 */
bool operator == (const Cuboid &cub) const;

/*!
 *  \brief Metoda przesuwajaca prostopadloscian o zadany kat w 3D                                            
 *  Argumenty:                                                                
 *      \param[in] trans - Vector3D                                                     
 *  Zwraca:                                                                   
 *     \param[out] translated - prostopadloscian po operacji przesuniecia                                
 */
Cuboid translation(Vector3D const &tran) const;

/*!
 *  \brief Metoda obracajaca prostopadloscian o zadany kat w 3D                                            
 *  Argumenty:                                                                
 *      \param[in] mat - macierz obrotu                                                     
 *  Zwraca:                                                                   
 *     \param[out] rotated - prostopadloscian po operacji rotacji                               
 */
Cuboid rotation(Matrix3D const &mat) const;

/*!
 *  \brief Metoda wypisania odpowiednich wierzcholkow do pliku                                                
 *  Argumenty:                                                                
 *      \param[in] out - strumien wyjsciowy,                                                                                                
 */
void print_cuboid(std::ostream &out) const;

/*!
 *  \brief Metoda wypisania odpowiednich wierzcholkow do pliku
 *         zgodnie z (dziwnym) sposobem jaki zaproponowano w zadaniu                              
 *  Argumenty:                                                                
 *      \param[in] out - strumien wyjsciowy,                                                                                                
 */
void print_cuboid_weird(std::ostream &out) const;
};

/*!
 *  \brief Przeciazenie operatora <<                                                 
 *  Argumenty:                                                                
 *      \param[in] out - strumien wyjsciowy,                                             
 *      \param[in] Cub - prostopadloscian.                                                      
 */
std::ostream &operator<<(std::ostream &out,  Cuboid const &Cub); //przeciazenie wyjscia