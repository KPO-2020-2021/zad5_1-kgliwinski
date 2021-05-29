#include "../include/drone.hpp"

Drone::Drone()
{
    int i;
    double tmp[3] = {17, 20, 5};
    drone_pos = Vector3D(tmp);
    body.set_scale(tmp);
    body = body.scale_cub();
    tmp[0] = 6;
    tmp[1] = 6;
    tmp[2] = 6;
    for (i = 0; i < 4; ++i)
    {
        rotors[i].set_scale(tmp);
        rotors[i] = rotors[i].scale_pri();
    }
    set_rotors_in_place();
    double tab[3] = {1, 0, 0};
    drone_orient = Vector3D(tab);
    Matrix3D mat;
    mat = mat.rotation_matrix(90, 'z');
    *this = rotation_around_cen(mat);
}

void Drone::set_rotors_in_place()
{
    int i;
    Vector3D tmp[2][4];
    body.get_cub(tmp);
    for (i = 0; i < 4; ++i)
    {
        rotors[i] = rotors[i].translation_of_lower_cen(tmp[1][i]);
    }
}

Drone Drone::translation(Vector3D const &tran) const
{
    Drone rotated = *this;
    int i;
    rotated.body = body.translation(tran);
    for (i = 0; i < 4; ++i)
    {
        rotated.rotors[i] = rotors[i].translation(tran);
    }
    return rotated;
}

Drone Drone::translation_to_pos() const
{
    Drone translated = *this;
    Vector3D tran = drone_pos - body.centre_point();
    translated = this->translation(tran);
    return translated;
}

bool Drone::operator==(const Drone &dro) const
{
    int i;
    if (!(body == dro.body))
        return 0;
    if (!(drone_pos == dro.drone_pos))
        return 0;
    for (i = 0; i < 4; ++i)
    {
        if (!(rotors[i] == dro.rotors[i]))
            return 0;
    }
    return 1;
}

void Drone::get_dro(Cuboid &b, Prism (&rot)[4], Vector3D &p) const
{
    int i;
    b = body;
    for (i = 0; i < 4; ++i)
    {
        rot[i] = rotors[i];
    }
    p = drone_pos;
}

Drone Drone::rotation_around_cen(const Matrix3D &mat) const
{
    int i;
    Drone rotated = *this;
    rotated.body = body.rotation_around_cen(mat);
    for (i = 0; i < 4; ++i)
    {
        rotated.rotors[i] = rotors[i].rotation_around_cen(mat);
    }
    rotated.drone_orient = mat * drone_orient;
    rotated.set_rotors_in_place();
    return rotated;
}

Drone Drone::scale_dro() const
{
    Drone scaled = *this;
    int i;
    scaled.body = body.scale_cub();
    for (i = 0; i < 4; ++i)
    {
        scaled.rotors[i] = rotors[i].scale_pri();
    }
    return scaled;
}

void Drone::setup_filenames(std::string const (&bod)[2], std::string const (&rots)[4][2])
{
    int i;
    body.set_sample_name(bod[0]);
    body.set_final_name(bod[1]);
    for (i = 0; i < 4; ++i)
    {
        rotors[i].set_sample_name(rots[i][0]);
        rotors[i].set_final_name(rots[i][1]);
    }
}

bool Drone::set_filenames_gnuplot(PzG::LaczeDoGNUPlota &Lacze) const
{
    int i;
    if (body.get_final_name() == "")
        return 0;
    body.Cuboid_To_File(body.get_final_name());
    Lacze.DodajNazwePliku(body.get_final_name().c_str(), PzG::SR_Ciagly);
    for (i = 0; i < 4; ++i)
    {
        if (rotors[i].get_final_name() == "")
            return 0;
        Lacze.DodajNazwePliku(rotors[i].get_final_name().c_str(), PzG::SR_Ciagly);
        rotors[i].Prism_To_File(rotors[i].get_final_name());
    }
    return 1;
}

void Drone::get_filenames(std::string (&bod)[2], std::string (&rots)[4][2]) const
{
    int i;
    bod[0] = body.get_sample_name();
    bod[1] = body.get_final_name();
    for (i = 0; i < 4; ++i)
    {
        rots[i][0] = rotors[i].get_sample_name();
        rots[i][1] = rotors[i].get_final_name();
    }
}

bool Drone::set_drone_pos(Vector3D const &pos)
{
    if (pos[2] < body.get_height() * 0.5)
        return 0;
    drone_pos = pos;
    return 1;
}

void Drone::set_scale_all(Vector3D const &bod, Vector3D const &rot)
{
    int i;
    body.set_scale(bod);
    for (i = 0; i < 4; ++i)
    {
        rotors[i].set_scale(rot);
    }
}

bool Drone::check_dro() const
{
    int i;
    if (!body.check_cub())
        return 0;
    for (i = 0; i < 4; ++i)
    {
        if (!rotors[i].check_pri())
            return 0;
    }
    if (!check_orien())
        return 0;
    return 1;
}

Vector3D Drone::get_orien() const
{
    Vector3D res;
    res = drone_orient;
    return res;
}

bool Drone::check_orien() const
{
    if (!(abs(drone_orient.get_len() - 1) <= 0.00000001))
        return 0;
    return 1;
}

void Drone::Print_to_gnuplot_drone() const
{
    int i;
    PzG::LaczeDoGNUPlota Lacze;
    body.Cuboid_To_File(body.get_sample_name());
    Lacze.DodajNazwePliku(body.get_sample_name().c_str(), PzG::SR_Ciagly);
    for (i = 0; i < 4; ++i)
    {
        Lacze.DodajNazwePliku(rotors[i].get_sample_name().c_str(), PzG::SR_Ciagly);
        rotors[i].Prism_To_File(rotors[i].get_sample_name());
    }
    Lacze.UstawZakresX(0, 200);
    Lacze.UstawZakresY(0, 200);
    Lacze.UstawZakresZ(0, 120);
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.Rysuj();
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000, '\n');
}

void Drone::Print_to_files_drone() const
{
    int i;
    body.Cuboid_To_File(body.get_final_name());
    for (i = 0; i < 4; ++i)
    {
        rotors[i].Prism_To_File(rotors[i].get_final_name());
    }
}

void Drone::Rotors_rotation_animation()
{
    Matrix3D mat_pos, mat_neg;
    mat_pos = mat_pos.rotation_matrix(1,'z');
    mat_neg = mat_neg.rotation_matrix(-1,'z');
    rotors[0] = rotors[0].rotation_around_cen(mat_pos);
    rotors[1] = rotors[1].rotation_around_cen(mat_neg);
    rotors[2] = rotors[2].rotation_around_cen(mat_neg);
    rotors[3] = rotors[3].rotation_around_cen(mat_pos);
    Print_to_files_drone();
}

void Drone::Drone_rotation_animation(PzG::LaczeDoGNUPlota Lacze, double const &angle)
{
    int i;
    double theta = angle * 0.01;
    Matrix3D mat = mat.rotation_matrix(theta, 'z');
    for (i = 0; i < 100; ++i)
    {
        *this = rotation_around_cen(mat);
        Print_to_files_drone();
        Rotors_rotation_animation();
        usleep(10000); // 0.1 ms
        Lacze.Rysuj();
    }
    //std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    //std::cin.ignore(100000, '\n');
}
