// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

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
std::string plane = "../datasets/tests/TEST_plane.dat";
std::string body[2][2];
std::string rot[2][4][2];
body[0][0] = "../datasets/tests/final/TEST_drone1_body_f.dat";
body[0][1] = "../datasets/tests/sample/TEST_drone1_body_s.dat";
rot[0][0][0] = "../datasets/tests/final/TEST_drone1_rotor_f1.dat";
rot[0][1][0] = "../datasets/tests/final/TEST_drone1_rotor_f2.dat";
rot[0][2][0] = "../datasets/tests/final/TEST_drone1_rotor_f3.dat";
rot[0][3][0] = "../datasets/tests/final/TEST_drone1_rotor_f4.dat";
rot[0][0][1] = "../datasets/tests/sample/TEST_drone1_rotor_s1.dat";
rot[0][1][1] = "../datasets/tests/sample/TEST_drone1_rotor_s2.dat";
rot[0][2][1] = "../datasets/tests/sample/TEST_drone1_rotor_s3.dat";
rot[0][3][1] = "../datasets/tests/sample/TEST_drone1_rotor_s4.dat";

body[1][0] = "../datasets/tests/final/TEST_drone2_body_f.dat";
body[1][1] = "../datasets/tests/sample/TEST_drone2_body_s.dat";
rot[1][0][0] = "../datasets/tests/final/TEST_drone2_rotor_f1.dat";
rot[1][1][0] = "../datasets/tests/final/TEST_drone2_rotor_f2.dat";
rot[1][2][0] = "../datasets/tests/final/TEST_drone2_rotor_f3.dat";
rot[1][3][0] = "../datasets/tests/final/TEST_drone2_rotor_f4.dat";
rot[1][0][1] = "../datasets/tests/sample/TEST_drone2_rotor_s1.dat";
rot[1][1][1] = "../datasets/tests/sample/TEST_drone2_rotor_s2.dat";
rot[1][2][1] = "../datasets/tests/sample/TEST_drone2_rotor_s3.dat";
rot[1][3][1] = "../datasets/tests/sample/TEST_drone2_rotor_s4.dat";

double positions[2][3] = {{20,20,5},{40,60,5}};
double scales_bod[2][3] = {{1,1,1},{1,1,1}};
double scales_rot[2][3] = {{1,1,1},{1,1,1}};
Vector3D pos[2],sca_bod[2],sca_rot[2];
for(i=0;i<2;++i)
{
  pos[i]=Vector3D(positions[i]);
  sca_bod[i]=Vector3D(scales_bod[i]);
  sca_rot[i]=Vector3D(scales_rot[i]);
}
Scene sc(pos,sca_bod,sca_rot,plane,body,rot);
PzG::LaczeDoGNUPlota Lacze;
Lacze = sc.init_gnuplot();
Lacze.Rysuj();*/

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
PzG::LaczeDoGNUPlota Lacze;
    Lacze.UstawZakresX(0, 200);
    Lacze.UstawZakresY(0, 200);
    Lacze.UstawZakresZ(0, 120);
    Lacze.ZmienTrybRys(PzG::TR_3D);
    a.set_filenames_gnuplot(Lacze);
Lacze.Rysuj();
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000, '\n');
  for(int i=0;i<100;++i)
  {
a.Drone_rotation_animation(Lacze, 60);
  }

Lacze.Rysuj();
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000, '\n');
}
