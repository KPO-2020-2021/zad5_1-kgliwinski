#include "cuboid.hpp"

Cuboid::Cuboid()
{
    int i;
    double iter[4][3] = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}};
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 1;
        tops[1][i] = Vector3D(iter[i]);
    }
    centre = this->special_points(cuts); //ustawia centre point i cuts
}

Cuboid::Cuboid(Vector3D const (&tab)[2][4])
{
    int i;
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = tab[0][i];
        tops[1][i] = tab[1][i];
    }
    centre = this->special_points(cuts); //ustawia centre point i cuts
}

Cuboid::Cuboid(Vector3D const (&tab)[2][4], const std::string &s_name, const std::string &f_name, const Vector3D &vec) 
: Block(s_name, f_name, vec)
{
    int i;
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = tab[0][i];
        tops[1][i] = tab[1][i];
    }
    centre = this->special_points(cuts); //ustawia centre point i cuts
}

Cuboid::Cuboid(double (&tovec)[2][4][3])
{
    int i, j;
    Vector3D tab[2][4];
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            tab[0][i] = Vector3D(tovec[0][i]);
            tab[1][i] = Vector3D(tovec[1][i]);
        }
    }
    for (i = 0; i < 4; ++i)
    {
        tops[0][i] = tab[0][i];
        tops[1][i] = tab[1][i];
    }
}

bool Cuboid::check_cub() const
{
    if (!(check_vec_opp() && check_vec_perp() && check_vec_len()))
        return 0;
    return 1;
}

void Cuboid::get_vec_opp(Vector3D (&vecs)[3][2]) const
{
    vecs[0][0] = tops[0][1] - tops[0][0];
    vecs[0][1] = tops[1][2] - tops[1][3];

    vecs[1][0] = tops[1][1] - tops[0][1];
    vecs[1][1] = tops[1][3] - tops[0][3];

    vecs[2][0] = tops[0][3] - tops[0][0];
    vecs[2][1] = tops[1][2] - tops[1][1];
}

bool Cuboid::check_vec_opp() const
{
    int i;
    Vector3D opp[3][2];
    this->get_vec_opp(opp);
    for (i = 0; i < 3; ++i)
    {
        if (!(opp[i][0] == opp[i][1]))
            return 0;
    }
    return 1;
}

bool Cuboid::check_vec_len() const
{
    int i, j;
    Vector3D opp[3][2];
    this->get_vec_opp(opp);
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            if (opp[i][j].get_len() == 0)
                return 0;
        }
    }
    return 1;
}

void Cuboid::get_vec_len(double (&tab)[3][2]) const
{
    int i;
    Vector3D opp[3][2];
    this->get_vec_opp(opp);
    for (i = 0; i < 3; ++i)
    {
            tab[i][0] = opp[i][0].get_len();
            tab[i][1] = opp[i][1].get_len();
    }
    if (tab[0]<tab[1]){
        double tmp[2]={tab[0][0],tab[0][1]};
        tab[0][0]=tab[1][0];
        tab[0][1]=tab[1][1];
        tab[1][0]=tmp[1];
        tab[1][1]=tmp[0];
    }

}

void Cuboid::get_vec_perp(Vector3D (&vecs)[2][3]) const
{
    vecs[0][0] = tops[0][2] - tops[0][1];
    vecs[0][1] = tops[1][1] - tops[0][1];
    vecs[0][2] = tops[0][0] - tops[0][1];

    vecs[1][0] = tops[1][0] - tops[1][3];
    vecs[1][1] = tops[0][3] - tops[1][3];
    vecs[1][2] = tops[1][2] - tops[1][3];
}

bool Cuboid::check_vec_perp() const
{
    int i;
    Vector3D vecs[2][3];
    this->get_vec_perp(vecs);
    for (i = 0; i < 2; ++i)
    {
        if (!(vecs[i][0].scalar_prod(vecs[i][1]) <= 0.0000000001))
            return 0;
        if (!(vecs[i][0].scalar_prod(vecs[i][2]) <= 0.0000000001))
            return 0;
        if (!(vecs[i][1].scalar_prod(vecs[i][2]) <= 0.0000000001))
            return 0;
    }
    return 1;
}

std::ostream &operator<<(std::ostream &out, Cuboid const &Cub)
{
    out.precision(10);
    Vector3D vecs[2][4];
    Cub.get_cub(vecs);
    out << "Wierzcholek A: " << std::endl
        << vecs[0][0] << std::endl;
    out << "Wierzcholek B: " << std::endl
        << vecs[0][1] << std::endl;
    out << "Wierzcholek C: " << std::endl
        << vecs[0][2] << std::endl;
    out << "Wierzcholek D: " << std::endl
        << vecs[0][3] << std::endl;
    out << "Wierzcholek E: " << std::endl
        << vecs[1][0] << std::endl;
    out << "Wierzcholek F: " << std::endl
        << vecs[1][1] << std::endl;
    out << "Wierzcholek G: " << std::endl
        << vecs[1][2] << std::endl;
    out << "Wierzcholek H: " << std::endl
        << vecs[1][3] << std::endl;

    return out;
}

void Cuboid::get_cub(Vector3D (&tab)[2][4]) const
{
    int i;
    for (i = 0; i < 4; ++i)
    {
        tab[0][i] = tops[0][i];
        tab[1][i] = tops[1][i];
    }
}

void Cuboid::get_cub(double (&tab)[2][4][3]) const
{
    int i, j;
    for (i = 0; i < 4; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            tab[0][i][j] = tops[0][i][j];
            tab[1][i][j] = tops[1][i][j];
        }
    }
}

bool Cuboid::operator==(const Cuboid &cub) const
{
    int i, j;
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            if (!(tops[i][j] == cub.tops[i][j]))
                return 0;
        }
    }
    return 1;
}

Cuboid Cuboid::translation(Vector3D const &tran) const
{
    int i, j;
    Cuboid translated;

    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            translated.tops[i][j] = tops[i][j] + tran;
        }
    }
    return translated;
}

Cuboid Cuboid::rotation(Matrix3D const &mat) const
{
    int i, j;
    Cuboid rotated;
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            rotated.tops[i][j] = mat.apply_matrix_to_rotation(tops[i][j]);
        }
    }
    return rotated;
}

Cuboid Cuboid::rotation_around_cen(Matrix3D const &mat) const
{
    int i,j;
    Cuboid rotated;
    Vector3D ref = this->centre_point();
    Vector3D neg_ref = ref*(-1);
    for (i = 0; i < 2; ++i)
    {
        for (j = 0; j < 4; ++j)
        {
            rotated.tops[i][j] = tops[i][j] + neg_ref;
            rotated.tops[i][j] = mat.apply_matrix_to_rotation(rotated.tops[i][j]);
        }
    }
    rotated = rotated.translation(ref);
    return rotated;
}

Vector3D Cuboid::centre_point() const
{
    Vector3D diag;
    diag = tops[1][2] - tops[0][0];
    Vector3D point;
    point = tops[0][0] + diag*0.5;
    return point;
}

Vector3D Cuboid::special_points(Vector3D (&vecs)[2]) const
{
    Vector3D cen = this->centre_point();
    Vector3D side = tops[0][1] - tops[0][0];
    side = side * 0.5;
    vecs[0] = cen - side;
    vecs[1] = cen + side;
    return cen;
}

void Cuboid::print_cuboid(std::ostream &out) const
{
    int i,j,k;
    out.precision(10);
    double vecs[2][4][3];
    this->get_cub(vecs);
    for (i=0;i<2;++i){
        for (j=0;j<4;++j){
            for (k=0;k<3; ++k){
                out << std::setw(10) << std::fixed << std::setprecision(10) << vecs[i][j][k] << " ";
            }
            if(j==1 || j==3)
                    out<<std::endl;
            out<<std::endl;
        }
    }
    for (i=0;i<1;++i){
        for (j=0;j<2;++j){
            for (k=0;k<3; ++k){
                out << std::setw(10) << std::fixed << std::setprecision(10) << vecs[i][j][k] << " ";
            }
            out<<std::endl;
        }
    }
}

void Cuboid::print_cuboid_weird(std::ostream &out) const
{
    Vector3D vec[8];
    double tab[2][4][3];
    int i,j,k;
    tops[0][0].get_vec(tab[0][0]); //W1
    tops[0][1].get_vec(tab[0][1]); //W2
    tops[0][3].get_vec(tab[0][2]); //W3
    tops[0][2].get_vec(tab[0][3]); //W4
    tops[1][3].get_vec(tab[1][0]); //W5
    tops[1][2].get_vec(tab[1][1]); //W6
    tops[1][0].get_vec(tab[1][2]); //W7
    tops[1][1].get_vec(tab[1][3]);;//W8
    
    out.precision(10);
    for (i=0;i<2;++i){
        for (j=0;j<4;++j){
            for (k=0;k<3; ++k){
                out << std::setw(10) << std::fixed << std::setprecision(10) << tab[i][j][k] << " ";
            }
            if(j==1 || j==3)
                    out<<std::endl;
            out<<std::endl;
        }
    }
    for (i=0;i<1;++i){
        for (j=0;j<2;++j){
            for (k=0;k<3; ++k){
                out << std::setw(10) << std::fixed << std::setprecision(10) << tab[i][j][k] << " ";
            }
            out<<std::endl;
        }
    }
}