#include "../include/scene.hpp"

Scene::Scene(Vector3D const (&pos)[SIZE], Vector3D const (&scal_bod)[SIZE],Vector3D const (&scal_rot)[SIZE], std::string const &name, 
        std::string const (&names_bod)[SIZE][2],std::string const (&names_rot)[SIZE][4][2])
{
    unsigned int i;
    land_name = name;
    for(i=0;i<SIZE;++i)
    {
        flies[i].set_drone_pos(pos[i]);
        flies[i].set_scale_all(scal_bod[i],scal_rot[i]);
        flies[i] = flies[i].scale_dro();
        flies[i] = flies[i].translation_to_pos();
        flies[i].setup_filenames(names_bod[i],names_rot[i]);
        flies[i].set_rotors_in_place();
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

PzG::LaczeDoGNUPlota Scene::init_gnuplot() const
{
    unsigned int i;
    PzG::LaczeDoGNUPlota Lacze;
    for(i=0;i<SIZE;++i)
    {
        flies[i].set_filenames_gnuplot(Lacze);
    }
    Lacze.UstawZakresX(0, 200);
    Lacze.UstawZakresY(0, 200);
    Lacze.UstawZakresZ(0, 120);
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.Rysuj();
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000, '\n');
    return Lacze;
}