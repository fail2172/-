#include "Header.h"

int main()
{
	SinglyLinkedList<int> first_list;
	first_list.Push_back(1);
	first_list.Push_back(2);
	first_list.Push_back(3);
	first_list.Push_back(4);
	first_list.Push_back(5);

	for (size_t i = 0; i < first_list.Size(); ++i) {
		std::cout << first_list[i] << " ";
	}std::cout << "\n";

	first_list.Erase(1);
	first_list.Erase(4);

	for (size_t i = 0; i < first_list.Size(); ++i) {
		std::cout << first_list[i] << " ";
	}std::cout << "\n";

	DoublyLinkedList<double> second_list;
	second_list.Push_back(1.5);
	second_list.Push_back(2.9);
	second_list.Push_back(3.1);
	second_list.Push_front(0.09);
	second_list.Push_front(0.99);

	for (size_t i = 0; i < second_list.Size(); ++i) {
		std::cout << second_list[i] << " ";
	}std::cout << "\n";

	second_list.Erase(0.99);
	second_list.Erase(3.1);

	if (second_list.Search_element(0.09)) {
		for (size_t i = 0; i < second_list.Size(); ++i) {
			std::cout << second_list[i] << " ";
		}
	}std::cout << "\n";

	Queue<SinglyLinkedList, const char*> first_queue;

	first_queue.Push("Hellow ");
	first_queue.Push("world");
	first_queue.Push("!!!");

	while (!first_queue.Empty()) {
		std::cout << first_queue.Back() << " ";
	}std::cout << "\n";

	Queue<DoublyLinkedList, char> second_queue;

	second_queue.Push('A');
	second_queue.Push('B');
	second_queue.Push('C');
	second_queue.Push('D');

	while (!second_queue.Empty()) {
		std::cout << second_queue.Back() << " ";
	}std::cout << "\n";

	return 0;
}