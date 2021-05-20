#include "../include/menu_cub.hpp"

Menu_cub::Menu_cub()
{
    open = 1;
}

void Menu_cub::init_menu(Vector3D (&tab)[2][4])
{
    Cuboid cub(tab);
    assert(cub);
    char n;
    show_menu();
    while (open)
    {
        std::cout << "Twoj wybor? (m - menu) > ";
        std::cin >> n;
        std::cout << "\n";
        switch_menu(n, cub);
    }
}

bool Menu_cub::assert(Cuboid const &cub)
{
    print_side_len(cub);

    if (cub.check_vec_opp())
        std::cout << "Przecwilegle boki sa rownolegle\n\n";
    if (cub.check_vec_perp())
    {
        std::cout << "Boki wychodzace z dwoch przeciwleglych wierzcholkow,\n";
        std::cout << "sa wzgledem siebie prostopadle\n\n";
    }
    if (!cub.check_cub())
    {
        std::cerr << "Blednie zainicjowany prostokat\n";
        open = 0;
        return 0;
    }
    return 1;
}

void Menu_cub::print_side_len(Cuboid const &cub) const
{
    double lens[3][2];
    cub.get_vec_len(lens);

    if (abs(lens[0][0] == lens[0][1]) <=0.00000000001)
        std::cout << "\nDluzsze przeciwlegle boki sa sobie rowne\n";
    else
        std::cout << "\n !!! Dluzsze przeciwlegle boki nie sa sobie rowne\n";

    std::cout << "Dlugosc pierwszego boku: " << lens[0][0] << "\n";
    std::cout << "Dlugosc trzeciego boku: " << lens[0][1] << "\n";

    if (abs(lens[1][0] - lens[1][1])<=0.00000000001)
        std::cout << "\nKrotsze przeciwlegle boki sa sobie rowne\n";
    else
        std::cout << "\n !!! Krotsze przeciwlegle boki nie sa sobie rowne\n";

    std::cout << "Dlugosc pierwszego boku: " << lens[1][0] << "\n";
    std::cout << "Dlugosc trzeciego boku: " << lens[1][1] << "\n";
    if (abs(lens[2][0] - lens[2][1]) <=0.00000000001)
        std::cout << "\nPoprzeczne przeciwlegle boki sa sobie rowne\n";
    else
        std::cout << "\n !!! Poprzeczne przeciwlegle boki nie sa sobie rowne\n";
    std::cout << "Dlugosc pierwszego boku: " << lens[2][0] << "\n";
    std::cout << "Dlugosc trzeciego boku: " << lens[2][1] << "\n\n";
}

void Menu_cub::switch_menu(const char &oper, Cuboid &cub)
{
    int times, iter;
    switch (oper)
    {
    case 'o':
    {
        std::cout << "   Podaj sekwencje oznaczen oraz katy obrotu w stopniach. Wejscie typu 'axis angle'\n";
        std::cout << "   !!! Aby zakonczyc wczytywanie wpisz: '. 1' !!!\n";
        switch_rotation();
        std::cout << "Ile razy powtorzyc operacjie? > ";
        std::cin >> times;
        for (iter = 0; iter < times; ++iter)
        {
            cub = cub.rotation(rot_mat);
        }
        Print_to_gnuplot(cub);
        assert(cub);
        break;
    }

    case 't':
    {
        cub = cub.rotation(rot_mat);
        Print_to_gnuplot(cub);
        break;
    }

    case 'r':
    {
        std::cout << rot_mat << "\n";
        break;
    }

    case 'p':
    {
        Vector3D tran;
        std::cout << "O jaki wektor chcesz przesunac figure? Wejscie typu: 'x y z' > ";
        std::cin >> tran;
        cub = cub.translation(tran);
        Print_to_gnuplot(cub);
        break;
    }

    case 'w':
    {
        std::cout << cub;
        break;
    }

    case 's':
    {
        print_side_len(cub);
        break;
    }

    case 'm':
    {
        show_menu();
        break;
    }

    case 'k':
    {
        std::cout << "Koniec dzialania programu\n";
        open = 0;
        break;
    }
    default:
    {
        std::cout << "Bledna opcja\n"
                  << std::endl;
        break;
    }

    case 'h':
    {
        Matrix4D mat;
        double a,b,g;
        Vector3D trans;
        std::cout<<"Podaj katy alpha, beta, gamma > ";
        std::cin>>a>>b>>g;
        std::cout<<"Podaj wartosci wektora translacji. Wejscie typu: 'x y z' > ";
        std::cin>>trans;

        mat.rotate_and_translate(a,b,g,trans);
        std::cout<<mat<<std::endl;
    }
    }
}

void Menu_cub::switch_rotation()
{
    rot_mat = Matrix3D();
    Matrix3D tmp;
    double angle;
    char axis;
    std::cin.ignore(1000000, '\n');
    std::cin >> axis >> angle;
    while (axis != '.')
    {
        switch (axis)
        {
        case 'x':
        {
            rot_mat = tmp.rotation_matrix(angle, 'x') * rot_mat;
            break;
        }
        case 'y':
        {
            rot_mat = tmp.rotation_matrix(angle, 'y') * rot_mat;
            break;
        }
        case 'z':
        {
            rot_mat = tmp.rotation_matrix(angle, 'z') * rot_mat;
            break;
        }
        default:
        {
            std::cerr << "Bledne oznaczenie osi. Dopuszczalne znaki to: x y z\n Sprobuj jeszcze raz\n";
        }
        }
        std::cin.ignore(1000000, '\n');
        std::cin >> axis >> angle;
    }
}

void Menu_cub::show_menu()
{
    std::cout << "  o - obrot bryly o zadana sekwencje katow\n";
    std::cout << "  t - powtorzenie poprzedniego obrotu\n";
    std::cout << "  r - wyswietlenie macierzy rotacji\n";
    std::cout << "  p - przesuniecie prostokata o zadany wektor\n";
    std::cout << "  w - wyswietlenie wspolrzednych wierzcholkow\n";
    std::cout << "  s - sprawdzenie dlugosci przeciwleglych bokow\n";
    std::cout << "  m - wyswietl menu\n";
    std::cout << "  h - MODYFIKACJA: tworzenie i wyswietlanie lacznej macierzy obrotu i translacji\n";
    std::cout << "  k - koniec dzialania programu\n\n";
}

bool Menu_cub::CuboidToFile(const char *filename, Cuboid const &cub)
{
    std::ofstream filestrm;

    filestrm.open(filename);
    if (!filestrm.is_open())
    {
        std::cerr << ":(  Operacja otwarcia do zapisu \"" << filename << "\"" << std::endl
                  << ":(  nie powiodla sie." << std::endl;
        return false;
    }
    std::ostringstream out;
    cub.print_cuboid_weird(filestrm);

    filestrm.close();
    return !filestrm.fail();
}

void Menu_cub::Print_to_gnuplot(Cuboid const &cub)
{
    PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji

    Lacze.DodajNazwePliku("../datasets/cuboid.dat", PzG::SR_Ciagly);

    Lacze.DodajNazwePliku("../datasets/cuboid.dat", PzG::SR_Punktowy);

    Lacze.ZmienTrybRys(PzG::TR_3D);
    cub.print_cuboid_weird(std::cout);
    if (!this->CuboidToFile("../datasets/cuboid.dat", cub))
        std::cerr << "ERROR" << std::endl;
    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000, '\n');
}
