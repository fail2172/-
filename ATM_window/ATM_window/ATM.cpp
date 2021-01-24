#include "ATM.h"
#include "MyForm.h"
#include <stdio.h>
#include <windows.h>

using namespace ATMwindow;
Card::Card()
{
    bank_name = number_card = cardholder_name = validity = "";
}

Card::Card(int number)
{
    string file_of_card = "Card_", temp;
    file_of_card += number + '0';
    file_of_card += ".txt";
    ifstream input(file_of_card);
    int count = 0;
    getline(input, bank_name);
    getline(input, number_card);
    getline(input, cardholder_name);
    getline(input, validity);
    input.close();
}

Card_in_base::Card_in_base()
{
    pincode = "";
    cash = 0;
}

Bank::Bank() {
    ifstream input("Database.txt");
    string tamp;
    while (getline(input, tamp)) {
        if (tamp == "//") {
            Card_in_base tamplate_card;
            getline(input, tamp);
            tamplate_card.set_bank_name(tamp);
            getline(input, tamp);
            tamplate_card.set_number_card(tamp);
            getline(input, tamp);
            tamplate_card.set_cardholder_name(tamp);
            getline(input, tamp);
            tamplate_card.set_validity(tamp);
            getline(input, tamp);
            tamplate_card.set_pincode(tamp);
            getline(input, tamp);
            tamplate_card.set_cash(atoi(tamp.c_str()));
            database.push_back(tamplate_card);
        }
    }
    input.close();
}

void Session::initialization()
{
    for (; position_of_card < tamplate_bank.get_size_of_database(); position_of_card++)
        if (tamplate_bank.get_bank_name(position_of_card) == tamplate_card.get_bank_name() &&
            tamplate_bank.get_number_card(position_of_card) == tamplate_card.get_number_card() &&
            tamplate_bank.get_cardholder_name(position_of_card) == tamplate_card.get_cardholder_name() &&
            tamplate_bank.get_validity(position_of_card) == tamplate_card.get_validity())break;

    if (position_of_card == tamplate_bank.get_size_of_database())throw Initialization_error("Карта не найдена");
}

string Session::get_message(char* pincode)
{
    return string();
}

int& Session::put_money()
{
    cout << "Введите номер карты\n";
    string number_of_card;
    cin >> number_of_card;
    int position_of_seconde_card = 0;

    for (; position_of_seconde_card < tamplate_bank.get_size_of_database(); position_of_seconde_card++)
        if (tamplate_bank.get_number_card(position_of_seconde_card) == number_of_card)break;

    if (position_of_seconde_card == tamplate_bank.get_size_of_database())throw Initialization_error("Карта не найдена");

    return tamplate_bank.get_cash(position_of_seconde_card);
}

void Session::check_balanse()
{
    cout << "Банк : " << tamplate_bank.get_bank_name(position_of_card) << endl;
    cout << "Номер карты : " << tamplate_bank.get_number_card(position_of_card) << endl;
    cout << "Имя пользователь : " << tamplate_bank.get_cardholder_name(position_of_card) << endl;
    cout << "Баланс : " << tamplate_bank.get_cash(position_of_card) << endl;
}

void Session::end_of_session()
{
    ofstream output("Database.txt");
    for (int i = 0; i < tamplate_bank.get_size_of_database(); i++) {
        output << "//\n";
        output << tamplate_bank.get_bank_name(i) << endl;
        output << tamplate_bank.get_number_card(i) << endl;
        output << tamplate_bank.get_cardholder_name(i) << endl;
        output << tamplate_bank.get_validity(i) << endl;
        output << tamplate_bank.get_pincode(i) << endl;
        output << tamplate_bank.get_cash(i) << endl;
    }
    output.close();
}

template<class Temp_error>
inline void Error_screen<Temp_error>::display()
{
    cout << error.set_type_error() << endl;
    cout << error.set_massege() << endl;
    puts("\nНажмите любую клавишу чтобы продолжить...");
}