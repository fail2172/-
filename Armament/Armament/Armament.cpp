#include "Armament.h"

void Armament::get_manufacturer_country(string country)
{
    manufacturer_country = country;
}

void Armament::get_name_of_armament(string name)
{
    name_of_armament = name;
}

void Armament::get_cost(int price)
{
    cost = price;
}

void Technics::get_number_of_people(int quantity)
{
    number_of_people = quantity;
}

void Technics::get_fuel_quantity(int liter)
{
    fuel_quantity = liter;
}

void Ship::get_displacement(int volume)
{
    displacement = volume;
}

void Battle_ship::view()
{
    setlocale(LC_ALL, "ru");
    cout << "Боевой корабль\n";
    cout << "Наименование : " << name_of_armament << endl;
    cout << "Страна производитель : " << manufacturer_country << endl;
    cout << "Водоизмещение (т) : " << displacement << endl;
    cout << "Экипаж : " << number_of_people << endl;
    cout << "Запас топлива (т) : " << fuel_quantity << endl;
    cout << "Стоимость $ : " << cost << endl;
}

void Plan::get_max_height(double height)
{
    max_height = height;
}

void Plan::get_max_speed(int speed)
{
    max_speed = speed;
}

void Battle_plan::view()
{
    setlocale(LC_ALL, "ru");
    cout << "Боевой самолёт\n";
    cout << "Наименование : " << name_of_armament << endl;
    cout << "Страна производитель : " << manufacturer_country << endl;
    cout << "Максимальная высота (км) : " << max_height << endl;
    cout << "Максимальная скорость (км/ч) : " << max_speed << endl;
    cout << "Экипаж : " << number_of_people << endl;
    cout << "Запас топлива (кг) : " << fuel_quantity << endl;
    cout << "Стоимость $ : " << cost << endl;
}

void Car::get_number_of_wheels(int quntity)
{
    number_of_wheels = quntity;
}

void Car::get_weght(double mass)
{
    weght = mass;
}

void Battle_car::view()
{
    setlocale(LC_ALL, "ru");
    cout << "Броне-автомобиль\n";
    cout << "Наименование : " << name_of_armament << endl;
    cout << "Страна производитель : " << manufacturer_country << endl;
    cout << "Количество колёс : " << number_of_wheels << endl;
    cout << "Масса (т) : " << weght << endl;
    cout << "Экипаж : " << number_of_people << endl;
    cout << "Запас топлива (л) : " << fuel_quantity << endl;
    cout << "Стоимость $ : " << cost << endl;
}


void Firearm::get_caliber(double number)
{
    caliber = number;
}

void Firearm::get_ammunition(int quantity)
{
    ammunition = quantity;
}

void Firearm::get_weight_gramm(int weight)
{
    weight_gramm = weight;
}

void Firearm::get_starting_speed(int speed)
{
    starting_speed = speed;
}

void Assault_rifle::get_rate_of_fire(int quantity)
{
    rate_of_fire = quantity;
}

void Assault_rifle::view()
{
    setlocale(LC_ALL, "ru");
    cout << "Автомат\n";
    cout << "Наименование : " << name_of_armament << endl;
    cout << "Страна производитель : " << manufacturer_country << endl;
    cout << "Калибр (мм) : " << caliber << endl;
    cout << "Скорострельность (выстр/мин) : " << rate_of_fire << endl;
    cout << "Начальная скорость пули (м/с) : " << starting_speed << endl;
    cout << "Размер магазина : " << ammunition << endl;
    cout << "Масса (гр) : " << weight_gramm << endl;
    cout << "Стоимость $ : " << cost << endl;
}

void Rifle::get_range_of_defeat(int range)
{
    range_of_defeat = range;
}

void Rifle::view()
{
    setlocale(LC_ALL, "ru");
    cout << "Винтовка\n";
    cout << "Наименование : " << name_of_armament << endl;
    cout << "Страна производитель : " << manufacturer_country << endl;
    cout << "Калибр (мм) : " << caliber << endl;
    cout << "Максимальная дальность поражения (км) : " << range_of_defeat << endl;
    cout << "Начальная скорость пули (м/с) : " << starting_speed << endl;
    cout << "Размер магазина : " << ammunition << endl;
    cout << "Масса (гр) : " << weight_gramm << endl;
    cout << "Стоимость $ : " << cost << endl;
}

void Explosive_device::Grenade::view()
{
    setlocale(LC_ALL, "ru");
    cout << "Граната\n";
    cout << "Наименование : " << name_of_armament << endl;
    cout << "Страна производитель : " << manufacturer_country << endl;
    cout << "Радиус разлёта осколков (м) : " << affected_area << endl;
    cout << "Стоимость $ : " << cost << endl;
}

void Explosive_device::Grenade::get_affected_area(int radius)
{
    affected_area = radius;
}

void Grenade_launcher::view()
{
    setlocale(LC_ALL, "ru");
    cout << "Гранатомёт\n";
    cout << "Наименование : " << name_of_armament << endl;
    cout << "Страна производитель : " << manufacturer_country << endl;
    cout << "Калибр (мм) : " << caliber << endl;
    cout << "Максимальная дальность поражения (км) : " << range_of_defeat << endl;
    cout << "Радиус разлёта осколков (м) : " << affected_area << endl;
    cout << "Начальная скорость снаряда (м/с) : " << starting_speed << endl;
    cout << "Размер магазина : " << ammunition << endl;
    cout << "Масса (гр) : " << weight_gramm << endl;
    cout << "Стоимость $ : " << cost << endl;
}

void Grenade_launcher::get_affected_area_of_grenade_launcher(int radius)
{
    get_affected_area(radius);
}
