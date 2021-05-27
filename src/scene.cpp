#include "../include/scene.hpp"

Scene::Scene(Vector3D const (&pos)[SIZE], Vector3D const (&scal)[SIZE], std::string const &name )
{
    unsigned int i;
    land_name = name;
    for(i=0;i<SIZE;++i)
    {
        flies[i].set_drone_pos(pos[i]);
        flies[i].set_scale_all(scal[i]);
    }
    land_name = name;
    active = 0;
}

bool Scene::choose_drone(unsigned int const &ch)
{
    if (ch>SIZE-1)
        return 0;
    active = ch;
    return 1;
}