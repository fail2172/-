#pragma once
using namespace std;
class LongInt {
	vector<int> number;
	bool minus;
public:
	//Суммирование LongInt + LongInt и LongInt + int
	LongInt operator+(const LongInt& other);
	LongInt operator+(int number) {
		LongInt temp;
		temp = number;
		return *this + temp;
	}
	LongInt operator+=(const LongInt& other) { return *this = *this + other; }
	LongInt operator+=(int number) { return *this = *this + number; }

	//Вычитание LongInt - LongInt и LongInt - int
	LongInt operator-(const LongInt& other);
	LongInt operator-(int number) {
		LongInt temp;
		temp = number;
		return *this - temp;
	}
	LongInt operator-=(const LongInt& other) { return *this = *this - other; }
	LongInt operator-=(int number) { return *this = *this - number; }

	//Произведение LongInt * LongInt и LongInt * int
	LongInt operator*(const LongInt& other);
	LongInt operator*(const int number) {
		LongInt temp;
		temp = number;
		return *this * temp;
	}
	LongInt operator*=(const LongInt& other) { return *this = *this * other; }
	LongInt operator*=(const int number) { return *this = *this * number; }

	//Деление LongInt / LongInt и LongInt / int
	LongInt operator/(const int& other) {
		vector <int> a = this->number;
		int b = abs(other);
		string st_a, st_b;
		vec_to_string(a, st_a);
		string result;
		int i = 0;
		int temp = st_a[i];
		while (temp < b) {
			i++;
			temp = temp * 10 + (st_a[i]);
		}
		while (st_a.size() > i) {
			result += (temp / b);
			i++;
			temp = (temp % b) * 10 + st_a[i];
		}
		vector <int> resultat;
		string_to_vec(result, resultat);
		LongInt res;
		if (this->minus == true && other > 0) {
			res.minus = true;
		}
		else if (this->minus == false && other < 0) {
			res.minus = true;
		}
		res.number = resultat;
		return res;
	}
	LongInt operator/=(const int& other) { return *this = *this / other; }

	//Инкремент и декремент
	LongInt operator++(int notused);
	LongInt operator++();
	LongInt operator--(int notused);
	LongInt operator--();

	//Присваивание LongInt = LongInt и LongInt = int
	LongInt operator=(int& value);
	LongInt operator=(const int& value);
	LongInt operator=(LongInt obj);

	//Операторы сравнения ==, >, <, <=, >=
	bool operator==(LongInt& other);
	bool operator==(int number) {
		LongInt temp;
		temp = number;
		return *this == temp;
	}
	bool operator <(const LongInt& other);
	bool operator <=(LongInt& other) { return *this == other || *this < other; }
	bool operator >(const LongInt& other);
	bool operator >=(LongInt& other) { return *this == other || *this > other; }

	//Функции вывода
	friend ostream& operator<<(ostream& out, LongInt obj);
	friend istream& operator>>(istream& in, LongInt& obj);
};
void increment_plus(vector<int>& obj);
void increment_minus(vector<int>& obj);