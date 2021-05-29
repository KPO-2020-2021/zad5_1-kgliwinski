// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif


#include "../include/cuboid.hpp"
#include "../include/prism.hpp"
#include"../include/matrix2D.hpp"
#include"../include/matrix4D.hpp"
#include"../include/vector2D.hpp"
#include "../include/menu_cub.hpp"
#include "scene.hpp"
#include "exampleConfig.h"




int main()
{
  std::cout << "C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR
            << "."
            << PROJECT_VERSION_MINOR
            << "."
            << PROJECT_VERSION_PATCH
            << "."
            << PROJECT_VERSION_TWEAK
            << std::endl;
/*
  int i;
  Menu_cub menu;

  double iter1[4][3] = {{0, 0, 0}, {50, 0, 0}, {50, 50, 0} , {0, 50, 0}};
  double iter2[4][3] = {{0, 0, 100}, {50, 0, 100}, {50, 50, 100} , {0, 50, 100}};

  Vector3D tops[2][4];
  for (i = 0; i < 4; ++i)
  {
    tops[0][i] = Vector3D(iter1[i]);
    tops[1][i] = Vector3D(iter2[i]);
  }
  Cuboid cub(tops);
  menu.init_menu(tops);

     Prism a;
     a.set_sample_name("../tests/test_datasets/test_cub.dat");
     a.Prism_To_File(a.get_sample_name());

     Prism b;
     b = a.Prism_From_Sample();
     std::cout<<a<<std::endl;
     std::cout<<b<<std::endl;
     if (a==b)
      std::cout<<"Gituwa"<<std::endl;
    else std::cout<<":(((((((((";
*/

Drone a;
std::string body[2];
std::string rot[4][2];
body[0] = "../datasets/tests/TEST_drone_body_f.dat";
body[1] = "../datasets/tests/TEST_drone_body_s.dat";
rot[0][0] = "../datasets/tests/TEST_drone_rotor_f1.dat";
rot[1][0] = "../datasets/tests/TEST_drone_rotor_f2.dat";
rot[2][0] = "../datasets/tests/TEST_drone_rotor_f3.dat";
rot[3][0] = "../datasets/tests/TEST_drone_rotor_f4.dat";
rot[0][1] = "../datasets/tests/TEST_drone_rotor_s1.dat";
rot[1][1] = "../datasets/tests/TEST_drone_rotor_s2.dat";
rot[2][1] = "../datasets/tests/TEST_drone_rotor_s3.dat";
rot[3][1] = "../datasets/tests/TEST_drone_rotor_s4.dat";
a.setup_filenames(body,rot);

double tab[3] = {50,50,10};
Vector3D pos(tab);
a.set_drone_pos(pos);
a = a.translation_to_pos();
a.Print_to_gnuplot_drone();
}
