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
public:
	std::shared_ptr<Node<ContextType>> root_;
	void Push_back(ContextType context) {
		if (!root_) {
			Node<ContextType> new_root(context);
			root_ = std::make_shared<Node<ContextType>>(new_root);
		}
		else {
			std::shared_ptr<Node<ContextType>> current_pointer = root_;
			while (current_pointer->next_) {
				current_pointer = current_pointer->next_;
			}
			Node<ContextType> new_node(context);
			current_pointer->next_ = std::make_shared<Node<ContextType>>(new_node);
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
		}
		else {
			parent_pointer.get()->next_ = current_pointer.get()->next_;
			current_pointer.~shared_ptr();
		}
	}
};

template <class ContextType>
class DoublyLinkedList :public SinglyLinkedList<ContextType> {
public:
	std::shared_ptr<Node<ContextType>> tail_;
	std::shared_ptr<Node<ContextType>> root_;
	void Push_back(ContextType context) {
		if (!root_) {
			Node<ContextType> new_root(context);
			root_ = tail_ = std::make_shared<Node<ContextType>>(new_root);
		}
		else {
			Node<ContextType> new_node(context);
			new_node.prev_ = tail_;
			tail_->next_ = std::make_shared<Node<ContextType>>(new_node);
			tail_ = tail_->next_;
		}
	}
	void Push_front(ContextType context) {
		if (!root_) {
			Node<ContextType> new_root(context);
			root_ = tail_ = std::make_shared<Node<ContextType>>(new_root);
		}
		else {
			Node<ContextType> new_node(context);
			new_node.next_ = root_;
			root_->prev_ = std::make_shared<Node<ContextType>>(new_node);
			root_ = root_.get()->prev_;
		}
	}
	void Erase(ContextType context) {
		std::shared_ptr<Node<ContextType>> current_pointer = root_;
		while (current_pointer.get()->context != context && current_pointer.get()->next_) {
			current_pointer = current_pointer.get()->next_;
		}
		if (!current_pointer.get()->next_ && current_pointer.get()->context != context) return;

		if (current_pointer == root_ && !current_pointer.get()->next_) { root_.~shared_ptr(); }

		if (current_pointer == root_) {
			root_ = current_pointer.get()->next_;
			root_.get()->prev_.~shared_ptr();
			current_pointer.~shared_ptr();
		}
		else {
			current_pointer.get()->prev_->next_ = current_pointer.get()->next_;
			current_pointer.get()->next_->prev_ = current_pointer.get()->prev_;
			current_pointer.~shared_ptr();
		}
	}
};


template <template<class> class List, class ContextType>
class Queue {
	List<ContextType> list;
public:
	void Push(ContextType context){
		list.Push_back(context);
	}
	ContextType Pop() {
		ContextType context = list.root_->context;
		list.Erase(list.root_.get()->context);
		return context;
	}
	bool Empty() {
		if (list.root_)return false;
		else return true;
	}
};