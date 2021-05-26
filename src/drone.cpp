#include"../include/drone.hpp"

Drone::Drone()
{
    int i;
    double tmp[3] = {10,10,10};
    drone_pos = Vector3D(tmp);
    body.set_scale(tmp);
    body = body.scale_cub();
    tmp[2] = 5;
    for (i=0;i<4;++i)
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
    for (i=0;i<4;++i)
    {
        rotors[i] = rotors[i].translation_of_lower_cen(tmp[1][i]);
    }
}

Drone Drone::translation(Vector3D const &tran) const
{
    Drone rotated;
    int i;
    rotated.body = body.translation(tran);
    for (i=0;i<4;++i)
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

bool Drone::operator == (const Drone &dro) const
{
    int i;
    if (!(body == dro.body))
        return 0;
    if (!(drone_pos == dro.drone_pos))
        return 0;
    for (i=0;i<4;++i)
    {
        if(!(rotors[i] == dro.rotors[i]))
            return 0;
    }
    return 1;
}

void Drone::get_dro(Cuboid &b, Prism (&rot)[4], Vector3D &p) const
{
    int i;
    b = body;
    for (i=0;i<4;++i)
    {
        rot[i] = rotors[i];
    }
    p = drone_pos;
}