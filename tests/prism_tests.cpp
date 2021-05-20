#include "../tests/doctest/doctest.h"
#include "prism.hpp"

TEST_CASE("P 1.01: konstruktor bezparametryczny prostopadloscianu i przeciazenie operatora <<")
{
     //double tab[2][2] = {{3,1}};
     Prism a;
     std::ostringstream out;
     out << a; //
     std::ostringstream out2;
     out2 << "Wierzcholek A1: \n"
          << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ -0.5000000000 ]\n\n";
     out2 << "Wierzcholek B1: \n"
          << "[ 0.5000000000 ]\n[ 0.8660254038 ]\n[ -0.5000000000 ]\n\n";
     out2 << "Wierzcholek C1: \n"
          << "[ -0.5000000000 ]\n[ 0.8660254038 ]\n[ -0.5000000000 ]\n\n";
     out2 << "Wierzcholek D1: \n"
          << "[ -1.0000000000 ]\n[ 0.0000000000 ]\n[ -0.5000000000 ]\n\n";
     out2 << "Wierzcholek E1: \n"
          << "[ -0.5000000000 ]\n[ -0.8660254038 ]\n[ -0.5000000000 ]\n\n";
     out2 << "Wierzcholek F1: \n"
          << "[ 0.5000000000 ]\n[ -0.8660254038 ]\n[ -0.5000000000 ]\n\n";
     out2 << "Wierzcholek A2: \n"
          << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
     out2 << "Wierzcholek B2: \n"
          << "[ 0.5000000000 ]\n[ 0.8660254038 ]\n[ 0.5000000000 ]\n\n";
     out2 << "Wierzcholek C2: \n"
          << "[ -0.5000000000 ]\n[ 0.8660254038 ]\n[ 0.5000000000 ]\n\n";
     out2 << "Wierzcholek D2: \n"
          << "[ -1.0000000000 ]\n[ 0.0000000000 ]\n[ 0.5000000000 ]\n\n";
     out2 << "Wierzcholek E2: \n"
          << "[ -0.5000000000 ]\n[ -0.8660254038 ]\n[ 0.5000000000 ]\n\n";
     out2 << "Wierzcholek F2: \n"
          << "[ 0.5000000000 ]\n[ -0.8660254038 ]\n[ 0.5000000000 ]\n\n";

     CHECK(out.str() == out2.str());
}

TEST_CASE("P 1.02: konstruktor parametryczny graniastoslupa (przeciazenie z double) i przeciazenie operatora <<")
{
     int i, j, k;
     double tab[2][6][3];
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; ++j)
          {
               for (k = 0; k < 3; ++k)
               {
                    tab[i][j][k] = 1.0;
               }
          }
     }
     Prism a(tab);
     std::ostringstream out;
     out << a; //
     std::ostringstream out2;
     out2 << "Wierzcholek A1: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek B1: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek C1: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek D1: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek E1: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek F1: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek A2: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek B2: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek C2: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek D2: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek E2: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     out2 << "Wierzcholek F2: \n"
          << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
     CHECK(out.str() == out2.str());
}

TEST_CASE("P 1.03: konstruktor parametryczny graniastoslupa (przeciazenie z vector) i przeciazenie operatora <<")
{
     int i, j;
     double tab_vec[3] = {1, 2, 3};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     Prism a(tab);
     std::ostringstream out;
     out << a; //
     std::ostringstream out2;
     out2 << "Wierzcholek A1: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek B1: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek C1: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek D1: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek E1: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek F1: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek A2: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek B2: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek C2: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek D2: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek E2: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     out2 << "Wierzcholek F2: \n"
          << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
     CHECK(out.str() == out2.str());
}

TEST_CASE("P 1.04: konstruktor parametryczny graniastoslupa (przeciazenie z vector) i przeciazenie operatora << neg")
{
     int i, j;
     double tab_vec[3] = {-1, -2, -3};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     Prism a(tab);
     std::ostringstream out;
     out << a; //
     std::ostringstream out2;
     out2 << "Wierzcholek A1: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek B1: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek C1: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek D1: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek E1: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek F1: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek A2: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek B2: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek C2: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek D2: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek E2: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     out2 << "Wierzcholek F2: \n"
          << "[ -1.0000000000 ]\n[ -2.0000000000 ]\n[ -3.0000000000 ]\n\n";
     CHECK(out.str() == out2.str());
}

TEST_CASE("P 1.05: konstruktor parametryczny graniastoslupa (przeciazenie z vector) i przeciazenie operatora << smol")
{
     int i, j;
     double tab_vec[3] = {-0.0000000001, -0.0000000002, -0.0000000003};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     Prism a(tab);
     std::ostringstream out;
     out << a; //
     std::ostringstream out2;
     out2 << "Wierzcholek A1: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek B1: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek C1: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek D1: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek E1: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek F1: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek A2: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek B2: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek C2: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek D2: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek E2: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     out2 << "Wierzcholek F2: \n"
          << "[ -0.0000000001 ]\n[ -0.0000000002 ]\n[ -0.0000000003 ]\n\n";
     CHECK(out.str() == out2.str());
}

TEST_CASE("P 1.08: konstruktor parametryczny graniastoslupa (przeciazenie z vector) z przypisaniem pol klasy Block")
{
     int i, j;
     double tab_vec[3] = {1, 2, 3};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     std::string s = "sname";
     std::string f = "fname";
     Vector3D vec;
     Prism a(tab, s, f, vec);

     CHECK(a.get_sample_name() == "sname");
     CHECK(a.get_final_name() == "fname");
     CHECK(a.get_scale() == vec);
}

TEST_CASE("P 1.09: konstruktor parametryczny graniastoslupa (przeciazenie z vector) z przypisaniem pol klasy Block")
{
     int i, j;
     double tab_vec[3] = {1, 2, 3};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     std::string s = "sname123";
     std::string f = "fname123";
     Vector3D vec(tab[0][0]);
     Prism a(tab, s, f, vec);

     CHECK(a.get_sample_name() == "sname123");
     CHECK(a.get_final_name() == "fname123");
     CHECK(a.get_scale() == vec);
}

TEST_CASE("P 1.10: Prism przeciazenie operatora ==")
{

     Prism a,b;

     CHECK(a==b);
}

TEST_CASE("P 1.11: Prism przeciazenie operatora == 2")
{
     int i;
     double iter[6][3] = {{2, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5},
                         {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
     Vector3D tops[2][6];
     for (i = 0; i < 6; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 0.5;
        tops[1][i] = Vector3D(iter[i]);
    }
     Prism a(tops),b(tops);

     CHECK(a==b);
}

TEST_CASE("P 1.12: Prism przeciazenie operatora == 3 smol")
{
     int i;
     double iter[6][3] = {{0.0000002, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.0000000005}, {-0.0000000005, sqrt(3) * 0.000000005, -0.00000005}, {-1, 0, -0.5},
                         {-0.5, -sqrt(3) * 0.000000005, -0.000000005}, {0.5, -sqrt(3) * 0.00000005, -0.0000000005}};
     Vector3D tops[2][6];
     for (i = 0; i < 6; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 0.5;
        tops[1][i] = Vector3D(iter[i]);
    }
     Prism a(tops),b(tops);

     CHECK(a==b);
}

TEST_CASE("P 2.01: get_pri przeciazenie dla Vector3D ")
{
     int i, j;
     double tab_vec[3] = {1, 2, 3};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     Prism a(tab);
     Vector3D res[2][6];

     a.get_pri(res);
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; j++)
          {
               CHECK(res[i][j] == tab[i][j]);
          }
     }
}

TEST_CASE("P 2.02: get_pri przeciazenie dla Vector3D neg")
{
     int i, j;
     double tab_vec[3] = {-1, -2, -3};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     Prism a(tab);
     Vector3D res[2][6];

     a.get_pri(res);
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; j++)
          {
               CHECK(res[i][j] == tab[i][j]);
          }
     }
}

TEST_CASE("P 2.03: get_pri przeciazenie dla Vector3D smol")
{
     int i, j;
     double tab_vec[3] = {-0.0000000001, -0.0000000002, -0.0000000003};
     Vector3D tab[2][6];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               tab[i][j] = Vector3D(tab_vec);
          }
     }
     Prism a(tab);
     Vector3D res[2][6];

     a.get_pri(res);
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; j++)
          {
               CHECK(res[i][j] == tab[i][j]);
          }
     }
}

TEST_CASE("P 2.04: get_pri przeciazenie dla double ")
{
     int i, j, k;
     double tab[2][6][3];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               for (k = 0; k < 3; ++k)
               {
                    tab[i][j][k] = k + 1;
               }
          }
     }
     Prism a(tab);
     double res[2][6][3];

     a.get_pri(res);
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; j++)
          {
               for (k = 0; k < 3; ++k)
               {
                    CHECK(res[i][j][k] == tab[i][j][k]);
               }
          }
     }
}

TEST_CASE("P 2.05: get_pri przeciazenie dla double small")
{
     int i, j, k;
     double tab[2][6][3];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               for (k = 0; k < 3; ++k)
               {
                    tab[i][j][k] = 0.0000000001 * (k + 1);
               }
          }
     }
     Prism a(tab);
     double res[2][6][3];

     a.get_pri(res);
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; j++)
          {
               for (k = 0; k < 3; ++k)
               {
                    CHECK(res[i][j][k] == tab[i][j][k]);
               }
          }
     }
}
TEST_CASE("P 2.06: get_pri przeciazenie dla double neg ")
{
     int i, j, k;
     double tab[2][6][3];
     for (i = 0; i < 2; i++)
     {
          for (j = 0; j < 6; j++)
          {
               for (k = 0; k < 3; ++k)
               {
                    tab[i][j][k] = -1 * (k + 1);
               }
          }
     }
     Prism a(tab);
     double res[2][6][3];

     a.get_pri(res);
     for (i = 0; i < 2; ++i)
     {
          for (j = 0; j < 6; j++)
          {
               for (k = 0; k < 3; ++k)
               {
                    CHECK(res[i][j][k] == tab[i][j][k]);
               }
          }
     }
}
TEST_CASE("P 3.01: Prism::translation() 1")
{
     int i, j;
     double tab[3] = {1, 1, 1};
     Vector3D tran(tab);
     Prism a;
     a = a.translation(tran);
     double iter[6][3] = {{1, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
     for (i = 0; i < 6; ++i)
     {
          for (j = 0; j < 3; ++j)
          {
               iter[i][j]+=1;
          }
     }
     Vector3D tops[2][6];
     for (i = 0; i < 6; ++i)
     {

          tops[0][i] = Vector3D(iter[i]);
          iter[i][2] = 1.5;
          tops[1][i] = Vector3D(iter[i]);
     }
     Prism res(tops);
     CHECK (a == res);
}

TEST_CASE("P 3.02: Prism::translation() 2 neg")
{
     int i, j;
     double tab[3] = {-1, -2, -3};
     Vector3D tran(tab);
     Prism a;
     a = a.translation(tran);
     double iter[6][3] = {{1, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
     for (i = 0; i < 6; ++i)
     {
          for (j = 0; j < 3; ++j)
          {
               iter[i][j]-=(j+1);
          }
     }
     Vector3D tops[2][6];
     for (i = 0; i < 6; ++i)
     {

          tops[0][i] = Vector3D(iter[i]);
          iter[i][2] = -2.5;
          tops[1][i] = Vector3D(iter[i]);
     }
     Prism res(tops);
     CHECK (a == res);
}

TEST_CASE("P 3.03: Prism::translation() 3 smol")
{
     int i, j;
     double tab[3] = {0.00000001, 0.00000001, 0.00000001};
     Vector3D tran(tab);
     Prism a;
     a = a.translation(tran);
     double iter[6][3] = {{1, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
     for (i = 0; i < 6; ++i)
     {
          for (j = 0; j < 3; ++j)
          {
               iter[i][j]+=0.00000001;
          }
     }
     Vector3D tops[2][6];
     for (i = 0; i < 6; ++i)
     {

          tops[0][i] = Vector3D(iter[i]);
          iter[i][2] = 0.50000001;
          tops[1][i] = Vector3D(iter[i]);
     }
     Prism res(tops);
     CHECK (a == res);
}

TEST_CASE("P 4.01: Prism::centre_point() 1")
{
     Prism a;
     Vector3D cen = a.centre_point();
     double tab[3] = {0, 0, 0};
     Vector3D res(tab);
     CHECK(cen == res);
}

TEST_CASE("P 4.02: Prism::centre_point() 2")
{
     Prism a;
     double tab[3] = {1, 1, 1};
     Vector3D tran(tab);
     a = a.translation(tran);
     Vector3D res = a.centre_point();
     CHECK(tran == res);
}

TEST_CASE("P 4.03: Prism::centre_point() 3")
{
     Prism a;
     double tab[3] = {1, 21, -111};
     Vector3D tran(tab);
     a = a.translation(tran);
     Vector3D res = a.centre_point();
     CHECK(tran == res);
}

TEST_CASE("P 4.04: Prism::centre_point() 4")
{
     Prism a;
     double tab[3] = {0.000001, 0.000021, -1234111};
     Vector3D tran(tab);
     a = a.translation(tran);
     Vector3D res = a.centre_point();
     CHECK(tran == res);
}
