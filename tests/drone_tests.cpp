#include"../tests/doctest/doctest.h"
#include"../include/drone.hpp"

TEST_CASE("P 1.01: konstruktor bezparametryczny drona oraz operatora ==")
{
    Drone a;
    Drone b;

    CHECK (a==b);
}

TEST_CASE("P 1.02: konstruktor bezparametryczny drona oraz operatora == 1")
{
    Drone a;
    Drone b;
    double tab[3] = {1223,124312,4124};
    Vector3D tr(tab);
    a = a.translation(tr);
    b = b.translation(tr);
    CHECK (a==b);
}

TEST_CASE("P 1.03: konstruktor bezparametryczny drona oraz operatora == 2")
{
    Drone a;
    Drone b;
    double tab[3] = {1223,124312,4124};
    Vector3D tr(tab);
    a = a.translation(tr);
    tab[0] = -12414;
    tr = Vector3D(tab);
    b = b.translation(tr);
    CHECK (!(a==b));
}