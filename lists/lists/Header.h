#pragma once
#include <iostream>

template <class ContextType>
class Node {
public:
	ContextType context;
	std::shared_ptr<Node<ContextType>> next_;
	std::shared_ptr<Node<ContextType>> prev_;
	Node(ContextType element) :context(element) {}

	friend std::ostream& operator<<(std::ostream& out, const Node<ContextType>& node) {
		out << node.context;
		return out;
	}
};

template <class ContextType>
class SinglyLinkedList {
protected:
	std::shared_ptr<Node<ContextType>> root_;
	size_t list_size_ = 0;
public:
	void Push_back(ContextType context) {
		if (!root_) {
			Node<ContextType> new_root(context);
			root_ = std::make_shared<Node<ContextType>>(new_root);
			++list_size_;
		}
		else {
			std::shared_ptr<Node<ContextType>> current_pointer = root_;
			while (current_pointer->next_) {
				current_pointer = current_pointer->next_;
			}
			Node<ContextType> new_node(context);
			current_pointer->next_ = std::make_shared<Node<ContextType>>(new_node);
			++list_size_;
		}
	}
	void Erase(ContextType context) {
		std::shared_ptr<Node<ContextType>> parent_pointer;
		std::shared_ptr<Node<ContextType>> current_pointer = root_;
		while (current_pointer.get()->context != context && current_pointer.get()->next_) {
			parent_pointer = current_pointer;
			current_pointer = current_pointer.get()->next_;
		}
		if (!current_pointer.get()->next_ && current_pointer.get()->context != context) return;

		if (current_pointer == root_) {
			root_ = current_pointer.get()->next_;
			current_pointer.~shared_ptr();
			--list_size_;
		}
		else {
			parent_pointer.get()->next_ = current_pointer.get()->next_;
			current_pointer.~shared_ptr();
			--list_size_;
		}
	}
	bool Search_element(ContextType element) {
		std::shared_ptr<Node<ContextType>> current_pointer = root_;
		while (current_pointer.get()->next_) {
			if (current_pointer.get()->context == element)return true;
			current_pointer = current_pointer.get()->next_;
		}
		if (current_pointer.get()->context == element)return true;
		return false;
	}
	bool Empty() { 
		if (!list_size_)return true;
		else return false;
	}
	size_t Size() { return list_size_; }

	Node<ContextType>& operator[](size_t number) {
		std::shared_ptr<Node<ContextType>> current_pointer = root_;
		for (size_t i = 0; i < number; ++i) {
			current_pointer = current_pointer.get()->next_;
		}
		return *current_pointer;
	}
};

template <class ContextType>
class DoublyLinkedList :public SinglyLinkedList<ContextType> {
	std::shared_ptr<Node<ContextType>> tail;
public:
	void Push_back(ContextType context) {
		if (!SinglyLinkedList<ContextType>::root_) {
			Node<ContextType> new_root(context);
			SinglyLinkedList<ContextType>::root_ = tail = std::make_shared<Node<ContextType>>(new_root);
			++SinglyLinkedList<ContextType>::list_size_;
		}
		else {
			Node<ContextType> new_node(context);
			new_node.prev_ = tail;
			tail->next_ = std::make_shared<Node<ContextType>>(new_node);
			tail = tail->next_;
			++SinglyLinkedList<ContextType>::list_size_;
		}
	}
	void Push_front(ContextType context) {
		if (!SinglyLinkedList<ContextType>::root_) {
			Node<ContextType> new_root(context);
			SinglyLinkedList<ContextType>::root_ = tail = std::make_shared<Node<ContextType>>(new_root);
			++SinglyLinkedList<ContextType>::list_size_;
		}
		else {
			Node<ContextType> new_node(context);
			new_node.next_ = SinglyLinkedList<ContextType>::root_;
			SinglyLinkedList<ContextType>::root_->prev_ = std::make_shared<Node<ContextType>>(new_node);
			SinglyLinkedList<ContextType>::root_ = SinglyLinkedList<ContextType>::root_->prev_;
			++SinglyLinkedList<ContextType>::list_size_;
		}
	}
};


template <template<class> class List, class Context>
class Queue {
	List<Context> list;
public:
	void Push(Context context){
		list.Push_back(context);
	}
	Context Back() {
		Context context = list[0].context;
		list.Erase(list[0].context);
		return context;
	}
	bool Empty() {
		return list.Empty();
	}
	int Size() { return list.size(); }
};