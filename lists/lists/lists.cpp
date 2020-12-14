#include "Header.h"
#include <string>

int main()
{
	SinglyLinkedList<int> first_list;
	first_list.Push_back(1);
	first_list.Push_back(2);
	first_list.Push_back(3);
	first_list.Push_back(4);
	first_list.Push_back(5);

	std::shared_ptr<UnidirectionalNode<int>> first_list_pointer = first_list.root_;
	while (first_list_pointer) {
		std::cout << first_list_pointer.get()->context<<" ";
		first_list_pointer = first_list_pointer.get()->next_;
	}

	first_list.Erase(1);
	first_list.Erase(4);

	std::cout << "\n";

	DoublyLinkedList<double> second_list;
	second_list.Push_back(1.5);
	second_list.Push_back(2.9);
	second_list.Push_back(3.1);
	second_list.Push_front(0.09);
	second_list.Push_front(0.99);

	std::shared_ptr<BidirectionalNode<double>> second_list_pointer = second_list.root_;

	while (second_list_pointer) {
		std::cout << second_list_pointer.get()->context << " ";
		second_list_pointer = second_list_pointer.get()->next_;
	}
	std::cout << "\n";

	Queue<SinglyLinkedList, int> first_queue(first_list);
	while (!first_queue.Empty()) {
		std::cout << first_queue.Pop() << " ";
	}std::cout << "\n";

	Queue<DoublyLinkedList, double> second_queue(second_list);
	while (!second_queue.Empty()) {
		std::cout << second_queue.Pop() << " ";
	}std::cout << "\n";

	return 0;
}