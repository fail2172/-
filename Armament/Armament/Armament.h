#pragma once
#include <iostream>
#include <string>

using namespace std;

class Armament {
protected:
    string manufacturer_country;
    string name_of_armament;
    int cost;
public:
    void get_manufacturer_country(string country);
    void get_name_of_armament(string name);
    void get_cost(int price);
    virtual void view() = 0;
};

class Ship {
protected:
    int displacement;
public:
    void get_displacement(int volume);
};

class Plan {
protected:
    double max_height;
    int max_speed;
public:
    void get_max_height(double height);
    void get_max_speed(int speed);
};

class Car {
protected:
    int number_of_wheels;
    double weght;
public:
    void get_number_of_wheels(int quntity);
    void get_weght(double mass);
};

class Technics:public Armament {
protected:
    int number_of_people;
    int fuel_quantity;
public:
    void get_number_of_people(int quantity);
    void get_fuel_quantity(int liter);
};

class Battle_ship :public Technics,public Ship {
public:
    void view();
};

class Battle_plan :public Technics, public Plan {
public:
    void view();
};

class Battle_car :public Technics, public Car {
public:
    void view();
};

class Firearm :virtual public Armament {
protected:
    double caliber;
    int ammunition;
    int weight_gramm;
    int starting_speed;
public:
    void get_caliber(double number);
    void get_ammunition(int quantity);
    void get_weight_gramm(int weight);
    void get_starting_speed(int speed);
};

class Assault_rifle :public Firearm {
    int rate_of_fire;
public:
    void get_rate_of_fire(int quantity);
    void view();
};

class Rifle :virtual public Firearm {
protected:
    int range_of_defeat;
public:
    void get_range_of_defeat(int range);
    void view();
};

namespace Explosive_device {
    class Grenade :virtual public Armament {
    protected:
        int affected_area;
    public:
        void view();
        void get_affected_area(int radius);
    };
}

class Grenade_launcher : Rifle, Explosive_device::Grenade {
public:
    Rifle::range_of_defeat;
    Rifle::get_range_of_defeat;
    Rifle::get_ammunition;
    Rifle::get_caliber;
    Rifle::get_weight_gramm;
    Rifle::get_starting_speed;
    Rifle::get_manufacturer_country;
    Rifle::get_name_of_armament;
    Rifle::get_cost;
    void view();
    void get_affected_area_of_grenade_launcher(int radius);
};