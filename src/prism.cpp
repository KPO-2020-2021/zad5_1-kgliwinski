#include "../include/prism.hpp"

Prism::Prism()
{
    int i;
    double iter[6][3] = {{1, 0, -0.5}, {0.5, sqrt(3) * 0.5, -0.5}, {-0.5, sqrt(3) * 0.5, -0.5}, {-1, 0, -0.5}, {-0.5, -sqrt(3) * 0.5, -0.5}, {0.5, -sqrt(3) * 0.5, -0.5}};
    for (i = 0; i < 6; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 0.5;
        tops[1][i] = Vector3D(iter[i]);
    }
    centre = this->special_points(cuts); //ustawienie centrum i specjalnych punktow
}

Prism::Prism(Vector3D const (&tab)[2][6])
{
    int i;
    for (i = 0; i < 6; ++i)
    {
        tops[0][i] = tab[0][i];
        tops[1][i] = tab[1][i];
    }
    centre = this->special_points(cuts); //ustawienie centrum i specjalnych punktow
}

Prism::Prism(Vector3D const (&tab)[2][6], const std::string &s_name, const std::string &f_name, const Vector3D &vec)
    : Block(s_name, f_name, vec)
{
    int i;
    for (i = 0; i < 6; ++i)
    {
        tops[0][i] = tab[0][i];
        tops[1][i] = tab[1][i];
    }
    centre = this->special_points(cuts); //ustawienie centrum i specjalnych punktow
}

Prism::Prism(double (&tovec)[2][6][3])
{
    int i, j;
    Vector3D tab[2][6];
    for (i = 0; i < 6; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            tab[0][i] = Vector3D(tovec[0][i]);
            tab[1][i] = Vector3D(tovec[1][i]);
        }
    }
    for (i = 0; i < 6; ++i)
    {
        tops[0][i] = tab[0][i];
        tops[1][i] = tab[1][i];
    }
    centre = this->special_points(cuts); //ustawienie centrum i specjalnych punktow
}
Prism::Prism(double (&tovec)[2][6][3], const std::string &s_name, const std::string &f_name, const Vector3D &vec)
    : Block(s_name, f_name, vec)
{
    int i, j;
    Vector3D tab[2][6];
    for (i = 0; i < 6; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            tab[0][i] = Vector3D(tovec[0][i]);
            tab[1][i] = Vector3D(tovec[1][i]);
        }
    }
    for (i = 0; i < 6; ++i)
    {
        tops[0][i] = tab[0][i];
        tops[1][i] = tab[1][i];
    }
    centre = this->special_points(cuts); //ustawienie centrum i specjalnych punktow
}

void Prism::get_pri(Vector3D (&tab)[2][6]) const
{
    int i;
    for (i = 0; i < 6; ++i)
    {
        tab[0][i] = tops[0][i];
        tab[1][i] = tops[1][i];
    }
}

void Prism::get_pri(double (&tab)[2][6][3]) const
{
    int i, j;
    for (i = 0; i < 6; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            tab[0][i][j] = tops[0][i][j];
            tab[1][i][j] = tops[1][i][j];
        }
    }
}

bool Prism::operator==(const Prism &pri) const
{
    int i, j;
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 6; ++j)
        {
            if (!(tops[i][j] == pri.tops[i][j]))
                return 0;
        }
    }
    return 1;
}

std::ostream &operator<<(std::ostream &out, Prism const &Pri)
{
    out.precision(10);
    Vector3D vecs[2][6];
    Pri.get_pri(vecs);
    out << "Wierzcholek A1: " << std::endl
        << vecs[0][0] << std::endl;
    out << "Wierzcholek B1: " << std::endl
        << vecs[0][1] << std::endl;
    out << "Wierzcholek C1: " << std::endl
        << vecs[0][2] << std::endl;
    out << "Wierzcholek D1: " << std::endl
        << vecs[0][3] << std::endl;
    out << "Wierzcholek E1: " << std::endl
        << vecs[0][4] << std::endl;
    out << "Wierzcholek F1: " << std::endl
        << vecs[0][5] << std::endl;
    out << "Wierzcholek A2: " << std::endl
        << vecs[1][0] << std::endl;
    out << "Wierzcholek B2: " << std::endl
        << vecs[1][1] << std::endl;
    out << "Wierzcholek C2: " << std::endl
        << vecs[1][2] << std::endl;
    out << "Wierzcholek D2: " << std::endl
        << vecs[1][3] << std::endl;
    out << "Wierzcholek E2: " << std::endl
        << vecs[1][4] << std::endl;
    out << "Wierzcholek F2: " << std::endl
        << vecs[1][5] << std::endl;
    return out;
}

Prism Prism::translation(Vector3D const &tran) const
{
    Prism translated;
    int i, j;
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 6; ++j)
        {
            translated.tops[i][j] = tops[i][j] + tran;
        }
    }
    return translated;
}

Prism Prism::translation_to_O() const
{
    Prism translated;
    int i, j;
    Vector3D tran = centre*(-1);
    for (i = 0; i < 2; ++i)
    {
        translated.cuts[i] = cuts[i] +tran;
        for (j = 0; j < 6; ++j)
        {
            translated.tops[i][j] = tops[i][j] + tran;
        }
    }
    translated.centre = centre +tran;
    return translated;
}

Prism Prism::rotation_around_cen(Matrix3D const &mat) const
{
    int i, j;
    Prism rotated;
    rotated = this->translation_to_O();

    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            rotated.tops[i][j] = mat.apply_matrix_to_rotation(rotated.tops[i][j]);
        }
    }
    rotated = rotated.translation(centre);
    return rotated;
}

Vector3D Prism::centre_point() const
{
    Vector3D diag;
    diag = tops[1][3] - tops[0][0];
    Vector3D point;
    point = tops[0][0] + diag * 0.5;
    return point;
}

Vector3D Prism::special_points(Vector3D (&vecs)[2]) const
{
    Vector3D cen = this->centre_point();
    Vector3D side = tops[1][0] - tops[0][0];
    side = side * 0.5;
    vecs[0] = cen - side;
    vecs[1] = cen + side;
    return cen;
}

void Prism::print_prism_3D(std::ostream &out) const
{
    double top[2][6][3];
    double cut[2][3];

    int i, j, k;
    for (i = 0; i < 2; ++i)
    {
        cuts[i].get_vec(cut[i]);
        for (j = 0; j < 6; ++j)
        {
            for (k = 0; k < 3; ++k)
            {
                tops[i][j].get_vec(top[i][j]);
            }
        }
    }
    out.precision(10);
    for (j = 0; j < 6; ++j)
    {
        for (k = 0; k < 3; ++k)
        {
            out << std::setw(10) << std::fixed << std::setprecision(10) << cut[1][k] << " ";
        }
        out << std::setw(10) << std::fixed << std::setprecision(10) << "\n";
        for (k = 0; k < 3; ++k)
        {
            out << std::setw(10) << std::fixed << std::setprecision(10) << top[1][j][k] << " ";
        }
        out << std::setw(10) << std::fixed << std::setprecision(10) << "\n";
        for (k = 0; k < 3; ++k)
        {
            out << std::setw(10) << std::fixed << std::setprecision(10) << top[0][j][k] << " ";
        }
        out << std::setw(10) << std::fixed << std::setprecision(10) << "\n";
        for (k = 0; k < 3; ++k)
        {
            out << std::setw(10) << std::fixed << std::setprecision(10) << cut[0][k] << " ";
        }
        out << std::setw(10) << std::fixed << std::setprecision(10) << "\n\n";
    }
        for (k = 0; k < 3; ++k)
        {
            out << std::setw(10) << std::fixed << std::setprecision(10) << cut[1][k] << " ";
        }
        out << std::setw(10) << std::fixed << std::setprecision(10) << "\n";
        for (k = 0; k < 3; ++k)
        {
            out << std::setw(10) << std::fixed << std::setprecision(10) << top[1][0][k] << " ";
        }
        out << std::setw(10) << std::fixed << std::setprecision(10) << "\n";
        for (k = 0; k < 3; ++k)
        {
            out << std::setw(10) << std::fixed << std::setprecision(10) << top[0][0][k] << " ";
        }
        out << std::setw(10) << std::fixed << std::setprecision(10) << "\n";
        for (k = 0; k < 3; ++k)
        {
            out << std::setw(10) << std::fixed << std::setprecision(10) << cut[0][k] << " ";
        }
        out << std::setw(10) << std::fixed << std::setprecision(10) << "\n\n";
}

Prism Prism::scale_pri() const
{
    int i,j;
    Prism res;
    res = this->translation_to_O();
    for (i=0;i<2;++i)
    {
        res.cuts[i] = res.cuts[i].scale_vec(scale);
        for(j=0;j<6;++j)
        {   
            res.tops[i][j] = res.tops[i][j].scale_vec(scale);
        }
    }
    res.centre = res.centre.scale_vec(scale);
    return res;
}


Prism Prism::scale_pri(Vector3D const &scal) const
{
    int i,j;
    Prism res;
    res = this->translation_to_O();
    for (i=0;i<2;++i)
    {
        res.cuts[i] = res.cuts[i].scale_vec(scal);
        for(j=0;j<6;++j)
        {   
            res.tops[i][j] = res.tops[i][j].scale_vec(scal);
        }
    }
    res.centre = res.centre.scale_vec(scal);
    return res;
}
