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

    if (abs(lens[0][0] - lens[0][1]) <= 0.00000000001)
        std::cout << "\nDluzsze przeciwlegle boki sa sobie rowne\n";
    else
        std::cout << "\n !!! Dluzsze przeciwlegle boki nie sa sobie rowne\n";

    std::cout << "Dlugosc pierwszego boku: " << lens[0][0] << "\n";
    std::cout << "Dlugosc trzeciego boku: " << lens[0][1] << "\n";

    if (abs(lens[1][0] - lens[1][1]) <= 0.00000000001)
        std::cout << "\nKrotsze przeciwlegle boki sa sobie rowne\n";
    else
        std::cout << "\n !!! Krotsze przeciwlegle boki nie sa sobie rowne\n";

    std::cout << "Dlugosc pierwszego boku: " << lens[1][0] << "\n";
    std::cout << "Dlugosc trzeciego boku: " << lens[1][1] << "\n";
    if (abs(lens[2][0] - lens[2][1]) <= 0.00000000001)
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

    case 'z':
    {
        Vector3D ref;
        ref = cub.centre_point();
        std::cout << " Srodek prostopadloscianu przed obrotem: " << ref << "\n";
        std::cout << "   Podaj sekwencje oznaczen oraz katy obrotu w stopniach. Wejscie typu 'axis angle'\n";
        std::cout << "   !!! Aby zakonczyc wczytywanie wpisz: '. 1' !!!\n";
        Matrix3D rot_mat;
        rot_mat = switch_rotation();
        std::cout << "Ile razy powtorzyc operacje? > ";
        std::cin >> times;
        for (iter = 0; iter < times; ++iter)
        {
            ref = cub.centre_point();
            cub = cub.rotation_around_cen(rot_mat);
        }
        Print_to_gnuplot(cub);
        assert(cub);
        ref = cub.centre_point();
        std::cout << " Srodek prostopadloscianu po obrocie: " << ref << "\n";
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

    case 'g':
    {
        int i;
        Vector3D top[2][6];
        double iter[6][3] = {{100, 0, -50}, {50, sqrt(3) * 50, -50}, {-50, sqrt(3) * 50, -50}, {-100, 0, -50}, {-50, -sqrt(3) * 50, -50}, {50, -sqrt(3) * 50, -50}};
        for (i = 0; i < 6; ++i)
        {
            top[0][i] = Vector3D(iter[i]);
            iter[i][2] = 50;
            top[1][i] = Vector3D(iter[i]);
        }
        Prism pri(top);
        Print_to_gnuplot(pri);
        break;
    }

    case 'a':
    {
        int i;
        Vector3D top[2][6];
        double iter[6][3] = {{100, 0, -50}, {50, sqrt(3) * 50, -50}, {-50, sqrt(3) * 50, -50}, {-100, 0, -50}, {-50, -sqrt(3) * 50, -50}, {50, -sqrt(3) * 50, -50}};
        for (i = 0; i < 6; ++i)
        {
            top[0][i] = Vector3D(iter[i]);
            iter[i][2] = 50;
            top[1][i] = Vector3D(iter[i]);
        }
        Prism pri(top);
        Print_to_gnuplot_animation(pri);
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
        double a, b, g;
        Vector3D trans;
        std::cout << "Podaj katy alpha, beta, gamma > ";
        std::cin >> a >> b >> g;
        std::cout << "Podaj wartosci wektora translacji. Wejscie typu: 'x y z' > ";
        std::cin >> trans;

        mat.rotate_and_translate(a, b, g, trans);
        std::cout << mat << std::endl;
    }
    }
}

Matrix3D Menu_cub::switch_rotation()
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
    return rot_mat;
}

void Menu_cub::show_menu()
{
    std::cout << "  o - obrot bryly o zadana sekwencje katow\n";
    std::cout << "  z - obrot bryly o zadana sekwencje katow wokol jej srodka\n";
    std::cout << "  t - powtorzenie poprzedniego obrotu\n";
    std::cout << "  r - wyswietlenie macierzy rotacji\n";
    std::cout << "  p - przesuniecie prostokata o zadany wektor\n";
    std::cout << "  w - wyswietlenie wspolrzednych wierzcholkow\n";
    std::cout << "  s - sprawdzenie dlugosci przeciwleglych bokow\n";
    std::cout << "  m - wyswietl menu\n";
    std::cout << "  h - MODYFIKACJA: tworzenie i wyswietlanie lacznej macierzy obrotu i translacji\n";
    std::cout << "  g - wyswietl graniastoslup\n";
    std::cout << "  a - animacja obrotu\n";
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
    cub.print_cuboid_3D(filestrm);

    filestrm.close();
    return !filestrm.fail();
}

void Menu_cub::Print_to_gnuplot(Cuboid const &cub)
{
    PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji

    Lacze.DodajNazwePliku("../datasets/cuboid.dat", PzG::SR_Ciagly);

    Lacze.DodajNazwePliku("../datasets/cuboid.dat", PzG::SR_Punktowy);

    Lacze.ZmienTrybRys(PzG::TR_3D);
    cub.print_cuboid_3D(std::cout);
    if (!this->CuboidToFile("../datasets/cuboid.dat", cub))
        std::cerr << "ERROR" << std::endl;
    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000, '\n');
}

bool Menu_cub::PrismToFile(const char *filename, Prism const &pri)
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
    pri.print_prism_3D(filestrm);

    filestrm.close();
    return !filestrm.fail();
}

void Menu_cub::Print_to_gnuplot(Prism const &pri)
{
    PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji

    Lacze.DodajNazwePliku("../datasets/prism.dat", PzG::SR_Ciagly);

    Lacze.DodajNazwePliku("../datasets/prism.dat", PzG::SR_Punktowy);

    Lacze.ZmienTrybRys(PzG::TR_3D);
    pri.print_prism_3D(std::cout);
    if (!this->PrismToFile("../datasets/prism.dat", pri))
        std::cerr << "ERROR" << std::endl;
    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000, '\n');
}

void Menu_cub::Print_to_gnuplot_animation(Prism  &pri)
{
    PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji

    Lacze.DodajNazwePliku("../datasets/prism.dat", PzG::SR_Ciagly);

    Lacze.DodajNazwePliku("../datasets/prism.dat", PzG::SR_Punktowy);

    Lacze.ZmienTrybRys(PzG::TR_3D);
    pri.print_prism_3D(std::cout);
    Matrix3D mat;
    mat = mat.rotation_matrix(0.1, 'x');
    mat = mat.rotation_matrix(0.1, 'y') * mat;
    int i;
    for (i=0;i<1000000;++i)
    {
        if (!this->PrismToFile("../datasets/prism.dat", pri))
            std::cerr << "ERROR" << std::endl;
        usleep(1000); // 0.1 ms
        Lacze.Rysuj();
        pri = pri.rotation_around_cen(mat);
    }
    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000, '\n');
}