#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class ATM;
class ATMsession;

class Card {
	friend ATM;
	friend ATMsession;
protected:
	string bank_name, number_card, cardholder_name, validity;
public:
	Card();
	Card(int number);
	void set_bank_name(string tamp) { bank_name = tamp; }
	void set_number_card(string tamp) { number_card = tamp; }
	void set_cardholder_name(string tamp) { cardholder_name = tamp; }
	void set_validity(string tamp) { validity = tamp; }
};

class Card_in_base :public Card {
	friend ATM;
	string pincode;
	int cash;
public:
	Card_in_base();
	void set_pincode(string tamp) { pincode = tamp; }
	string get_pincode() { return pincode; }
	void set_cash(int score) { cash = score; }
	int& get_cash() { return cash; }
};


class ATM {
	friend ATMsession;
	int sys_num_card = 0;
	vector<Card_in_base> database;
	Card current_card;
public:

	ATM();
	void insert_card(Card card);

	void withdraw_money(int sum) { tamplate_bank.get_cash(position_of_card) -= sum; }
	int& put_money();
	void check_balanse();
	void end_of_session();
	int get_cash() { return tamplate_bank.get_cash(position_of_card); }

	class ATMscreen {
	public:
		ATMscreen() {}
		void clear_display() { system("cls"); }
	};


};

class ATMsession {
	friend ATM;
	ATM atm;
public:
	ATMsession(ATM curr_atm);
	void initialization();
	void get_pincode();
};

class Error {
protected:
	string type_of_error;
	string message = "";
public:
	Error(){}
	Error(const string error_message) { message = error_message; }
	virtual string set_message() = 0;
	virtual string set_type_error() = 0;
};

class Initialization_error :Error {
public:
	Initialization_error(){}
	Initialization_error(const string error_message) :Error(error_message)
	{
		type_of_error = "Initialization error:";
	}
	string set_message() { return message; }
	string set_type_error() { return type_of_error; }
};

class Enter_code_error :Error {
public:
	Enter_code_error(){}
	Enter_code_error(const string error_message) :Error(error_message)
	{
		type_of_error = "Enter code error:";
	}
	string set_message() { return message; }
	string set_type_error() { return type_of_error; }
};

class Cash_error :Error {
public:
	Cash_error(){}
	Cash_error(const string error_message,int money) :Error(error_message)
	{
		type_of_error = "Cash_error:";
	}
	string set_message() { return message; }
	string set_type_error() { return type_of_error; }
};

class Screen {
protected:
public:
	~Screen() { system("cls"); }
};

class Options :Screen {
public:
	Options(ATM& session) { processing(session); }
	int display();
	void processing(ATM& session);
	void withdraw_funds(ATM& session);
	void withdraw_funds_for_phone(ATM& session);
	void withdraw_funds_for_any_card(ATM& session);
};

class Ñheck :Screen {
public:
	Ñheck(ATM& session) { print_a_check(session); }
	int display();
	void print_a_check(ATM& session);
};

template <class Temp_error>
class Error_screen:Screen {
	Temp_error error;
public:
	Error_screen(Temp_error object) { error = object; display(); }
	void display();
};