#include <iostream>
#include <fstream>
#include "Armament.h"

using namespace std;


void get_from_file(Assault_rifle& ak74, Rifle& m24, Explosive_device::Grenade& f1, Battle_ship& bismarck, Battle_plan& i16, Battle_car& lb23, Grenade_launcher& rpg7) {
    ifstream file("Sourse.txt");
    string temp;
    //Assault_rifle
    file >> temp;
    ak74.get_name_of_armament(temp);
    file >> temp;
    ak74.get_manufacturer_country(temp);
    file >> temp;
    ak74.get_caliber(stod(temp));
    file >> temp;
    ak74.get_rate_of_fire(stod(temp));
    file >> temp;
    ak74.get_starting_speed(stod(temp));
    file >> temp;
    ak74.get_ammunition(stod(temp));
    file >> temp;
    ak74.get_weight_gramm(stod(temp));
    file >> temp;
    ak74.get_cost(stod(temp));
    //Rifle
    file >> temp;
    m24.get_name_of_armament(temp);
    file >> temp;
    m24.get_manufacturer_country(temp);
    file >> temp;
    m24.get_caliber(stod(temp));
    file >> temp;
    m24.get_range_of_defeat(stod(temp));
    file >> temp;
    m24.get_starting_speed(stod(temp));
    file >> temp;
    m24.get_ammunition(stod(temp));
    file >> temp;
    m24.get_weight_gramm(stod(temp));
    file >> temp;
    m24.get_cost(stod(temp));
    //Grenade
    file >> temp;
    f1.get_name_of_armament(temp);
    file >> temp;
    f1.get_manufacturer_country(temp);
    file >> temp;
    f1.get_affected_area(stod(temp));
    file >> temp;
    f1.get_cost(stod(temp));
    //Battle_ship
    file >> temp;
    bismarck.get_name_of_armament(temp);
    file >> temp;
    bismarck.get_manufacturer_country(temp);
    file >> temp;
    bismarck.get_displacement(stod(temp));
    file >> temp;
    bismarck.get_number_of_people(stod(temp));
    file >> temp;
    bismarck.get_fuel_quantity(stod(temp));
    file >> temp;
    bismarck.get_cost(stod(temp));
    //Battle_plan
    file >> temp;
    i16.get_name_of_armament(temp);
    file >> temp;
    i16.get_manufacturer_country(temp);
    file >> temp;
    i16.get_max_height(stod(temp));
    file >> temp;
    i16.get_max_speed(stod(temp));
    file >> temp;
    i16.get_number_of_people(stod(temp));
    file >> temp;
    i16.get_fuel_quantity(stod(temp));
    file >> temp;
    i16.get_cost(stod(temp));
    //Battle_car
    file >> temp;
    lb23.get_name_of_armament(temp);
    file >> temp;
    lb23.get_manufacturer_country(temp);
    file >> temp;
    lb23.get_number_of_wheels(stod(temp));
    file >> temp;
    lb23.get_weght(stod(temp));
    file >> temp;
    lb23.get_number_of_people(stod(temp));
    file >> temp;
    lb23.get_fuel_quantity(stod(temp));
    file >> temp;
    lb23.get_cost(stod(temp));
    //Grenade_launcher
    file >> temp;
    rpg7.get_name_of_armament(temp);
    file >> temp;
    rpg7.get_manufacturer_country(temp);
    file >> temp;
    rpg7.get_caliber(stod(temp));
    file >> temp;
    rpg7.get_range_of_defeat(stod(temp));
    file >> temp;
    rpg7.get_affected_area_of_grenade_launcher(stod(temp));
    file >> temp;
    rpg7.get_starting_speed(stod(temp));
    file >> temp;
    rpg7.get_ammunition(stod(temp));
    file >> temp;
    rpg7.get_weight_gramm(stod(temp));
    file >> temp;
    rpg7.get_cost(stod(temp));
}

int main()
{
    using namespace Explosive_device;
    Armament* pointer;
    Assault_rifle ak74;
    Rifle m24;
    Grenade f1;
    Battle_ship bismarck;
    Battle_plan i16;
    Battle_car lb23;
    Grenade_launcher rpg7;
    get_from_file(ak74, m24, f1, bismarck, i16, lb23, rpg7);
    ak74.view();
    cout << "---------------------------\n";

    pointer = &m24;
    pointer->view();
    cout << "---------------------------\n";

    f1.view();
    cout << "---------------------------\n";

    pointer = &bismarck;
    pointer->view();
    cout << "---------------------------\n";

    i16.view();
    cout << "---------------------------\n";

    pointer = &lb23;
    pointer->view();
    cout << "---------------------------\n";

    rpg7.view();

    return 0;
   

}

