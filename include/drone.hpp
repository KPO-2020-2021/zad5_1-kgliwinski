#pragma once
#include "prism.hpp"
#include "cuboid.hpp"

/*!
 * \file  drone.hpp
 *  
 *  \brief Plik zawiera definicję klasy reprezentujacej drona,
 *         budowanie i przemieszczanie go
 */

/*!
 *  \class Drone
 *  \brief Opisuje drona o prostopadlosciennym korpusie i 4 rotorach
 */
class Drone
{
private:
   /*!
 * \brief Zmienna reprezentujaca polozenie drona (dokladnie
 *         polozenie punktu centralnego prostopadloscianu body)
 */
   Vector3D drone_pos;

   /*!
 * \brief Tablica graniastoslupow szesciokatnych, 
 *        reprezentujaca rotory drona
 */
   Prism rotors[4];

   /*!
 * \brief Prostopadloscian reprezentujacy korpus drona
 */
   Cuboid body;

public:
   /*!
 *  \brief Konstruktor bezparametryczny klasy Drone.
 *         Powstaly dron jest skonstruowany z bezparametrycznych
 *          prostopadloscianu (body) oraz rotorow przeskalowanych
 *          10-krotnie (aby sie poprawnie wyswietlal) w poziomie i 
 *          5-krotnie w pionie (aby zachowac pewna poprawna skale)
 *                                           
 *  Argumenty:                                                                
 *      Brak argumentow.                                                      
 *  Zwraca:                                                                   
 *     \post Inicjalizuje podstawowego drona                                  
 */
   Drone();
   /*!
 *  \brief Metoda uzywana przy konstruowania drona
 *          Ustawia rotory w ten sposob, ze srodek ich dolnej
 *          podstawy jest w tym samym punkcie co wierzcholki
 *          gornej podstawy body
 *                                           
 *  Argumenty:                                                                
 *      Brak argumentow.                                                      
 *  Zwraca:                                                                   
 *     \post Zmienia pozycje rotorow                                  
 */
   void set_rotors_in_place();

   /*!
 *  \brief Przesuwa drona o zadany wektor w 3D
 *                                           
 *  Argumenty:                                                                
 *      \param[in] trans - Vector3D                                                     
 *  Zwraca:                                                                   
 *     \param[out] translated - Dron po operacji przesuniecia                                 
 */
   Drone translation(Vector3D const &tran) const;

   /*!
 *  \brief Metoda uzywana przy konstruowania drona
 *          przesuwa drona w ten sposob, ze Vector3D
 *          centre prostopadloscianu body pokrywa sie 
 *          z Vector3D pos
 *                                           
 *  Argumenty:                                                                
 *      Brak argumentow.                                                      
 *  Zwraca:                                                                   
 *     \returns translated - przesuniety dron                                 
 */
   Drone translation_to_pos() const;

   /*!
 *  \brief Metoda obracajaca dron o zadany kat w 3D wokol srodka figury                                      
 *  Argumenty:                                                                
 *      \param[in] mat - macierz obrotu                                                  
 *  Zwraca:                                                                   
 *     \param[out] rotated - dron po przeprowadzonej rotacji                               
 */
   Drone rotation_around_cen(const Matrix3D &mat) const;

   /*!
 *  \brief Przeciazenie operatora == dla klasy Drone                                              
 *  Argumenty:                                                                
 *      \param[in] dro - porownywany dron                                             
 *  Zwraca:
 *      \retval false - nie sa rowne, 
 *      \retval true - sa rowne                                                     
 */
   bool operator==(const Drone &dro) const;

/*!
 *  \brief Metoda ustawiajaca drone_pos   
 *  \pre Pozycja drona musi znajdowac sie nad plaszcyzna.
 *       Punktem referencji jest srodek prostopadloscianu body, wiec
 *       aby dron nie zapadal sie w podloze, minimalna wspolrzedna z polozenia
 *       nie moze nigdy byc mniejsza od polowy wysokosci prostopadloscianu                                       
 *  Argumenty:                                                                
 *      \param[in] pos - wektor pozycji                                                     
 *  Zwraca:                                                                   
 *     \post Ustawia pozycje drona (zadana przez uzytkownika)       
 *     \retval false - jesli wprowadzona pozycja jest bledna
 *     \retval true - jesli jest prawidlowa                          
 */
bool set_drone_pos(Vector3D const  &pos);

/*!
 *  \brief Metoda zwracajaca wszystkie elementy drona do odpowiednich zmiennych                                          
 *  Argumenty:                                                                
 *      \param[in] b - tu zwrocone bedzie body
 *      \param[in] rot - tu zostana zwrocone odpowiednio rotory
 *      \param[in] p - wektor pozycji                                                     
 *  Zwraca:                                                                   
 *     \post Zwraca odpowiednio pola klasy Drone                                  
 */
   void get_dro(Cuboid &b, Prism (&rot)[4], Vector3D &p) const;

/*!
 *  \brief Metoda ustawiajaca nazwy plikow do zapisu dla drona
 *  Argumenty:
 *     \param[in] bod - tablica nazw plikow odpowiednio 0-sample_name, 1-final_name;
 *                      zawierajacych dane do korpusu drona
 *     \param[in] rots - analogiczna tablica co bod, dla rotorow drona                                                                                     
 *  Zwraca:                                                                   
 *     \post Zmienia obiekt, przypisuje mu odpowiednie parametry                                 
 */
   void setup_filenames(std::string const (&bod)[2], std::string const (&rots)[4][2]);

/*!
 *  \brief Metoda zwracajaca nazwy plikow do zapisu dla drona
 *  Argumenty:
 *     \param[in] bod - tablica nazw plikow odpowiednio 0-sample_name, 1-final_name;
 *                      do ktorych zwracane sa nazwy
 *     \param[in] rots - analogiczna tablica co bod, dla rotorow drona                                                                                     
 *  Zwraca:                                                                   
 *     \return przypisuje argumentom odpowiednie wartosci                                 
 */
   void get_filenames(std::string (&bod)[2], std::string (&rots)[4][2]) const;
};