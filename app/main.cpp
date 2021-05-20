// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif


#include "../include/cuboid.hpp"
#include "../include/prism.hpp"
#include "../include/menu_cub.hpp"
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


}
