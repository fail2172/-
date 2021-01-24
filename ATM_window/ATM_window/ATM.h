#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>
#include <set>
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


using namespace std;


class Card {
protected:
	string bank_name, number_card, cardholder_name, validity;
public:
	Card();
	Card(int number);
	void set_bank_name(string tamp) { bank_name = tamp; }
	string get_bank_name() { return bank_name; }
	void set_number_card(string tamp) { number_card = tamp; }
	string get_number_card() { return number_card; }
	void set_cardholder_name(string tamp) { cardholder_name = tamp; }
	string get_cardholder_name() { return cardholder_name; }
	void set_validity(string tamp) { validity = tamp; }
	string get_validity() { return validity; }
};

class Card_in_base :public Card {
	string pincode;
	int cash;
public:
	Card_in_base();
	void set_pincode(string tamp) { pincode = tamp; }
	string get_pincode() { return pincode; }
	void set_cash(int score) { cash = score; }
	int& get_cash() { return cash; }
};

class Bank {
public:
	vector<Card_in_base> database;
	Bank();
	string get_bank_name(int position_of_card) { return database[position_of_card].get_bank_name(); }
	string get_number_card(int position_of_card) { return database[position_of_card].get_number_card(); }
	string get_cardholder_name(int position_of_card) { return database[position_of_card].get_cardholder_name(); }
	string get_validity(int position_of_card) { return database[position_of_card].get_validity(); }
	string get_pincode(int position_of_card) { return database[position_of_card].get_pincode(); }
	int& get_cash(int position_of_card) { return database[position_of_card].get_cash(); }
	int get_size_of_database() { return database.size(); }
};

class Session {
public:
	Bank tamplate_bank;
	Card tamplate_card;
	int position_of_card = 0;
	Session(Bank& bank, Card& card) {
		tamplate_bank = bank;
		tamplate_card = card;
	}
	void initialization();
	//void get_pincode(System::Windows::Forms::TextBox^ text, System::Windows::Forms::Button^ enter, char* pincode);
	void withdraw_money(int sum) { tamplate_bank.get_cash(position_of_card) -= sum; }
	int& put_money();
	void check_balanse();
	void end_of_session();
	string get_message(char* pincode);
	int get_cash() { return tamplate_bank.get_cash(position_of_card); }
	string get_bank_name() { return tamplate_bank.get_bank_name(position_of_card); }
	string get_number_card() { return tamplate_bank.get_number_card(position_of_card); }
	string get_cardholder_name() { return tamplate_bank.get_cardholder_name(position_of_card); }
};

class Error {
protected:
	string type_of_error;
	string massege = "";
public:
	Error() {}
	Error(const string error_massege) { massege = error_massege; }
	virtual string set_massege() = 0;
	virtual string set_type_error() = 0;
};

class Initialization_error :Error {
public:
	Initialization_error() {}
	Initialization_error(const string error_massege) :Error(error_massege)
	{
		type_of_error = "Initialization error:";
	}
	string set_massege() { return massege; }
	string set_type_error() { return type_of_error; }
};

class Enter_code_error :Error {
public:
	Enter_code_error() {}
	Enter_code_error(const string error_massege) :Error(error_massege)
	{
		type_of_error = "Enter code error:";
	}
	string set_massege() { return massege; }
	string set_type_error() { return type_of_error; }
};

class Cash_error :Error {
public:
	Cash_error() {}
	Cash_error(const string error_massege, int money) :Error(error_massege)
	{
		type_of_error = "Cash_error:";
	}
	string set_massege() { return massege; }
	string set_type_error() { return type_of_error; }
};

//class ATMScreen {
//protected:
//public:
//	~ATMScreen() { system("cls"); }
//};
//
//class Options :ATMScreen {
//public:
//	Options(Session& session) { processing(session); }
//	int display();
//	void processing(Session& session);
//	void withdraw_funds(Session& session);
//	void withdraw_funds_for_phone(Session& session);
//	void withdraw_funds_for_any_card(Session& session);
//};
//
//class Ñheck :ATMScreen {
//public:
//	Ñheck(Session& session) { print_a_check(session); }
//	int display();
//	void print_a_check(Session& session);
//};

template <class Temp_error>
class Error_screen :ATMScreen {
	Temp_error error;
public:
	Error_screen(Temp_error object) { error = object; display(); }
	void display();
};

class A {
public:
	void a(System::Windows::Forms::TextBox^ text) {
		text->Text = "Auf";
	}
};