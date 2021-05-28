#include "../include/scene.hpp"

Scene::Scene(Vector3D const (&pos)[SIZE], Vector3D const (&scal_bod)[SIZE],Vector3D const (&scal_rot)[SIZE], std::string const &name )
{
    unsigned int i;
    land_name = name;
    for(i=0;i<SIZE;++i)
    {
        flies[i].set_drone_pos(pos[i]);
        flies[i].set_scale_all(scal_bod[i],scal_rot[i]);
    }
    land_name = name;
    active = 0;
}

bool Scene::check_scene() const
{
    unsigned int i;
    for(i=0;i<SIZE;++i)
    {
        if(!flies[i].check_dro())
            return 0;
    }
    return 1;
}

bool Scene::operator == (const Scene &sce) const
{
    unsigned int i;
    for(i=0;i<SIZE;++i)
    {
        if(!(flies[i] == sce.flies[i]))
            return 0;
    }
    if(!(land_name == sce.land_name))
        return 0;
    return 1;
}


bool Scene::choose_drone(unsigned int const &ch)
{
    if (ch>SIZE-1)
        return 0;
    active = ch;
    return 1;
}