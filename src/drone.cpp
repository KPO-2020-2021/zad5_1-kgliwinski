#include "../include/drone.hpp"

Drone::Drone()
{
    int i;
    double tmp[3] = {10, 10, 10};
    drone_pos = Vector3D(tmp);
    body.set_scale(tmp);
    body = body.scale_cub();
    tmp[2] = 5;
    for (i = 0; i < 4; ++i)
    {
        rotors[i].set_scale(tmp);
        rotors[i] = rotors[i].scale_pri();
    }
    set_rotors_in_place();
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
    Drone rotated;
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
    Drone translated;
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
    Drone rotated;
    rotated.body = body.rotation_around_cen(mat);
    rotated.set_rotors_in_place();
    return rotated;
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

bool Drone::set_drone_pos(Vector3D const  &pos)
{
    if (pos[2]<body.get_height()*0.5)
        return 0;
    drone_pos = pos;
    return 1;
}