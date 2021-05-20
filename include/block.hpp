#pragma once
#include <string>
#include "vector3D.hpp"
#include "matrix3D.hpp"

/*!
 * \file  block.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej bryle
 *  w przestrzeni trojwymiarowej
 */

/*!
 *  \class Block
 *  \brief Opisuje figure geometryczna w przestrzeni trojwymiarowej
 */
class Block
{
    protected:
    
/*!
 * \brief Nazwa pliku z wzorcowym opisem figury
 */
    std::string sample_name;
    
/*!
 * \brief Nazwa pliku z roboczym opisem figury
 */    
    std::string final_name;
/*!
 * \brief Vector3D ze skala dla danej fihury
 */
    Vector3D scale;
    
    public:

/*!
 * \brief Konstruktor bezparamereyczny klasy Block
 *          Ustawia sample_name i final_name na NULL oraz
 *          Vector3D scale na [1,1,1] (aby nie zmienial skali)
 */  
    Block();
/*!
 * \brief Konstruktor paramereyczny klasy Block
 *  Argumenty:
 *      \param[in] s_name - docelowo sample_name z klasy Block
 *      \param[in] f_name - docelowo final_name z klasy Block
 *      \param[in] vec - docelowo scale z klasy Block
 *  Zwraca:
 *      \post Ustawia nazwy na odpowiednie podane przez uzytkownika
 */
    Block(const std::string &s_name, const std::string &f_name, const Vector3D &vec);

/*!
 *  \brief Metoda zapisujaca do klasy nazwe pliku z wzorcowa bryla                                            
 *  Argumenty:                                                                
 *      \param[in] name - nazwa pliku                                                     
 *  Zwraca:                                                                   
 *     \post Zmiana sample_name na ta podana przez uzytkownika                               
 */
    void set_sample_name(const std::string &name);

/*!
 *  \brief Metoda zapisujaca do klasy nazwe pliku z finalna (robocza) bryla                                             
 *  Argumenty:                                                                
 *      \param[in] name - nazwa pliku                                                     
 *  Zwraca:                                                                   
 *     \post Zmiana final_name na ta podana przez uzytkownika                                
 */
    void set_final_name(const std::string &name);

/*!
 *  \brief Metoda zapisujaca do klasy wektor reprezentujacy skale                                            
 *  Argumenty:                                                                
 *      \param[in] vec - Vector3D zawierajacy skale                                                  
 *  Zwraca:                                                                   
 *     \post Zmiana skali na te podana przez uzytkownika                                
 */
    void set_scale(const Vector3D &vec);

/*!
 *  \brief Metoda zwracajaca nazwe pliku z wzorcowa bryla                                             
 *  Argumenty:                                                                
 *      brak                                                   
 *  Zwraca:                                                                   
 *     \return Zwraca nazwe pliku                              
 */
    std::string get_sample_name() const;

/*!
 *  \brief Metoda zwracajaca nazwe pliku z finalna (robocza) bryla                                             
 *  Argumenty:                                                                
 *      brak                                                    
 *  Zwraca:                                                                   
 *     \return Zwraca nazwe pliku                              
 */
    std::string get_final_name() const;

    /*!
 *  \brief Metoda zapisujaca do klasy wektor reprezentujacy skale                                            
 *  Argumenty:                                                                
 *       brak                                                 
 *  Zwraca:                                                                   
 *     \post Zmiana skali na te podana przez uzytkownika                                
 */
    Vector3D get_scale() const;
};