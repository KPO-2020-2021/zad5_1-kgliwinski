#pragma once
#include "prism.hpp"
#include "cuboid.hpp"
#include "lacze_do_gnuplota.hpp"
#include <unistd.h>
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
 * \brief Zmienna reprezentujaca zwrot drona.
 *         Reprezentowana przez jednostkowy Vector,
 *         nie dopuszcza sie zwrotu pionowego.
 */
  Vector3D drone_orient;

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
 *     \post Inicjalizuje podstawowego drona                                  
 */
  Drone();
  /*!
 *  \brief Metoda uzywana przy konstruowania drona
 *          Ustawia rotory w ten sposob, ze srodek ich dolnej
 *          podstawy jest w tym samym punkcie co wierzcholki
 *          gornej podstawy body                                                                                                              
 *     \post Zmienia pozycje rotorow      = *this                            
 */
  void set_rotors_in_place();

  /*!
 *  \brief Przesuwa drona o zadany wektor w 3D                                           
 *      \param[in] trans - Vector3D                                                                                                                    
 *     \param[out] translated - Dron po operacji przesuniecia                                 
 */
  Drone translation(Vector3D const &tran) const;

  /*!
 *  \brief Metoda uzywana przy konstruowania drona
 *          przesuwa drona w ten sposob, ze Vector3D
 *          centre prostopadloscianu body pokrywa sie 
 *          z Vector3D pos                                                                                                                
 *     \returns translated - przesuniety dron                                 
 */
  Drone translation_to_pos() const;

  /*!
 *  \brief Metoda obracajaca dron o zadany kat w 3D wokol srodka figury                                      
 *      \param[in] mat - macierz obrotu                                                  
 *      \param[out] rotated - dron po przeprowadzonej rotacji                               
 */
  Drone rotation_around_cen(const Matrix3D &mat) const;

  /*!
 *  \brief Metoda skalujaca wszystkie elementy drona przez skale kazdego elementu                                                                                     
 *     \param[out] scaled - dron po operacji skalowania                              
 */
  Drone scale_dro() const;

  /*!
 *  \brief Przeciazenie operatora == dla klasy Drone                                              
 *      \param[in] dro - porownywany dron                                             
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
 *      \param[in] pos - wektor pozycji                                                     
 *     \post Ustawia pozycje drona (zadana przez uzytkownika)       
 *     \retval false - jesli wprowadzona pozycja jest bledna
 *     \retval true - jesli jest prawidlowa                          
 */
  bool set_drone_pos(Vector3D const &pos);

  /*!
 *  \brief Metoda ustawiajaca skale wszystkich elementow drona                                         
 *      \param[in] bod - skala korpusu
 *      \param[in] rot - skala rotorow                                               
 *     \post Ustawia skale korpusa i rotorow                                  
 */
  void set_scale_all(Vector3D const &bod, Vector3D const &rot);

  /*!
 *  \brief Metoda zwracajaca wszystkie elementy drona do odpowiednich zmiennych                                          
 *      \param[in] b - tu zwrocone bedzie body
 *      \param[in] rot - tu zostana zwrocone odpowiednio rotory
 *      \param[in] p - wektor pozycji                                                     
 *     \post Zwraca odpowiednio pola klasy Drone                                  
 */
  void get_dro(Cuboid &b, Prism (&rot)[4], Vector3D &p) const;

  /*!
 *  \brief Metoda sprawdzajaca budowe drona                                                                                          
 *     \retval true - dron odpowiednio zbudowany
 *     \retval false - dron blednie zbudowany                                 
 */
  bool check_dro() const;
  
  /*!
 *  \brief Metoda zwracajaca orientacje drona                                                                                         
 *     \return res - Zwracana orientacja                                 
 */
Vector3D get_orien() const;

/*!
 *  \brief Metoda sprawdzajaca orientacje drona                                                                                         
 *          Vector3D dron_orien musi byc jednostkowy, oraz miec skladowa z=0
 *     \retval true - odpowiednia orientacja
 *     \retval false - bledna orientacja                               
 */
  bool check_orien() const;

/*!
 *  \brief Metoda ustawiajaca nazwy plikow do zapisu dla drona
 *     \param[in] bod - tablica nazw plikow odpowiednio 0-sample_name, 1-final_name;
 *                      zawierajacych dane do korpusu drona
 *     \param[in] rots - analogiczna tablica co bod, dla rotorow drona                                                                                     
 *     \post Zmienia obiekt, przypisuje mu odpowiednie parametry                                 
 */
  void setup_filenames(std::string const (&bod)[2], std::string const (&rots)[4][2]);

/*!
 *  \brief Metoda ustawiajaca nazwy plikow w laczy do gnuplota (nazwy final!)
 *     \param[in] Lacze - lacze do ktorego wpisane zostana nazwy
 *     \pre Metoda wymaga zainicjowanych nazw elementow drona                                                                                    
 *     \post Zmienia lacze, przypisuje mu odpowiednie parametry                                 
 */
  bool set_filenames_gnuplot(PzG::LaczeDoGNUPlota &Lacze) const;

  /*!
 *  \brief Metoda zwracajaca nazwy plikow do zapisu dla drona
 *     \param[in] bod - tablica nazw plikow odpowiednio 0-sample_name, 1-final_name;
 *                      do ktorych zwracane sa nazwy
 *     \param[in] rots - analogiczna tablica co bod, dla rotorow drona                                                                                     
 *     \return przypisuje argumentom odpowiednie wartosci                                 
 */
  void get_filenames(std::string (&bod)[2], std::string (&rots)[4][2]) const;

/*!
 *  \brief Metoda rysujaca drona w gnuplocie. Przeznaczona do testow                                                                                    
 *     \post Wyswietla okienko gnuplota z wyrysowanym dronem                                 
 */
  void Print_to_gnuplot_drone() const;

/*!
 *  \brief Metoda zapisujaca parametry drona do plikow (do plikow final kazdego z elementow)                                                                                    
 *     \post Aktualizuje pliki z danymi                              
 */
  void Print_to_files_drone() const;

/*!
 *  \brief Metoda animujaca obrot rotorow i zapisujaca to w plikach.
 *          Metoda sluzy jako metoda pomocnicza, przy kazdej animacji (translacji czy 
 *          rotacji drona) rotory sie niezaleznie obracaja. Ta metoda to umozliwia.
 *     \pre Pliki musza byc odpowiednio skonfigurowane                                                                                
 *     \post Rotory sa obracane o kat 1 stopnia, zmieniany jest obiekt drona
 *            efekt rotacji zapisywnay jest w plikach
 */
  void Rotors_rotation_animation();

/*!
 *  \brief Metoda animujaca obrot drona i wyrysowujaca calosc w gnuplocie
 *     \pre Lacze musi byc odpowiednio skonfigurowane
 *     \param[in] Lacze - aktywne lacze do gnuplota
 *     \param[in] angle - kat obrotu w stopniach, obrot wykonuje sie wylacznie wokol osi z                                                                                 
 *     \post W oknie gnuplota wykonuje sie animacja obrotu drona                                 
 */
  void Drone_rotation_animation(PzG::LaczeDoGNUPlota Lacze, double const &angle);
};