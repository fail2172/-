#include "ATM.h"

int main() {
	setlocale(LC_ALL, "ru");
	int number_of_card = 0;
	while (true) {
		try {
			cout << "Вставте карту:\n";
			cin >> number_of_card;
			Card card(number_of_card);
			ATM session();
			session.get_pincode();
			session.initialization();
			Options options(session);
			session.end_of_session();
		}
		catch (Initialization_error error) {
			Error_screen<Initialization_error> error_screen(error);
		}
		catch (Enter_code_error error) {
			Error_screen<Enter_code_error> error_screen(error);
		}
	}
	return 0;
}