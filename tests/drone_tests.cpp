#include"../tests/doctest/doctest.h"
#include"../include/drone.hpp"
#include <ctime>
#include <unistd.h>

std::string gen_random(const int len) {
    
    std::string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    srand( (unsigned) time(NULL) * getpid());

    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    
    
    return tmp_s;
    
}

TEST_CASE("D 1.01: konstruktor bezparametryczny drona oraz operatora ==")
{
    Drone a;
    Drone b;

    CHECK (a==b);
}

TEST_CASE("D 1.02: konstruktor bezparametryczny drona oraz operatora == 1")
{
    Drone a;
    Drone b;
    double tab[3] = {1223,124312,4124};
    Vector3D tr(tab);
    a = a.translation(tr);
    b = b.translation(tr);
    CHECK (a==b);
}

TEST_CASE("D 1.03: konstruktor bezparametryczny drona oraz operatora == 2")
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

TEST_CASE("D 2.01: setup_files() check_files() 1")
{
    int i,j;
    std::string tmp = "a";
    std::string b[2], r[4][2];
    for(i=0;i<2;++i)
    {
        b[i] = tmp;
        for(j=0;j<4;++j)
        {
            r[j][i] = tmp;
        }
    }
    Drone dron;
    dron.setup_filenames(b, r);
    std::string b2[2], r2[4][2];
    dron.get_filenames(b2,r2);
    for(i=0;i<2;++i)
    {
        CHECK(b[i] == b2[i]);
        for(j=0;j<4;++j)
        {
            CHECK(r[j][i] == r2[j][i]);
        }
    }  
}

TEST_CASE("D 2.02: setup_files() check_files() 2")
{
    int i,j;
    std::string tmp = gen_random(12);
    std::string b[2], r[4][2];
    for(i=0;i<2;++i)
    {
        b[i] = tmp;
        for(j=0;j<4;++j)
        {
            r[j][i] = tmp;
        }
    }
    Drone dron;
    dron.setup_filenames(b, r);
    std::string b2[2], r2[4][2];
    dron.get_filenames(b2,r2);
    for(i=0;i<2;++i)
    {
        CHECK(b[i] == b2[i]);
        for(j=0;j<4;++j)
        {
            CHECK(r[j][i] == r2[j][i]);
        }
    }  
}