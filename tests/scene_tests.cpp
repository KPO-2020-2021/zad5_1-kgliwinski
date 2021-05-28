#include"../tests/doctest/doctest.h"
#include"../include/scene.hpp"

TEST_CASE("D 1.01: konstruktor parametryczny sceny, przeciazenie == 1")
{
    double pos[3] = {1,2,3};
    double sca[3] = {10,10,10};
    Vector3D posi[2], scal[2];
    int i;
    for(i=0;i<2;++i)
    {
        posi[i] = Vector3D(pos);
        scal[i] = Vector3D(sca);
    }
    Scene a(posi,scal,scal,"123");
    Scene b(posi,scal,scal,"123");
    CHECK (a == b);
}

TEST_CASE("D 1.02: konstruktor parametryczny sceny, przeciazenie == 2")
{
    double pos[3] = {14124,124124,124124};
    double sca[3] = {10,10,10};
    Vector3D posi[2], scal[2];
    int i;
    for(i=0;i<2;++i)
    {
        posi[i] = Vector3D(pos);
        scal[i] = Vector3D(sca);
    }
    Scene a(posi,scal,scal,"123");
    Scene b(posi,scal,scal,"123");
    b.choose_drone(1);
    CHECK (a == b);
}

TEST_CASE("D 1.03: konstruktor parametryczny sceny, przeciazenie == 3")
{
    double pos[3] = {14124,124124,124124};
    double sca[2][3] = {{10,10,10},{11,11,11}};
    Vector3D posi[2], scal[2];
    int i;
    for(i=0;i<2;++i)
    {
        posi[i] = Vector3D(pos);
        scal[i] = Vector3D(sca[i]);
    }
    Scene a(posi,scal,scal,"123");
    Scene b(posi,scal,scal,"123124");
    CHECK (!(a == b));
}