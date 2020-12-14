#pragma once
#include <iostream>

template <class ContextType>
class UnidirectionalNode {
public:
	ContextType context;
	std::shared_ptr<UnidirectionalNode<ContextType>> next_;
	UnidirectionalNode(ContextType element) :context(element) {}
	friend std::ostream& operator<<(std::ostream& out, const UnidirectionalNode<ContextType>& node) {
		out << node.context;
		return out;
	}
};

template <class ContextType>
class BidirectionalNode {
public:
	ContextType context;
	std::shared_ptr<BidirectionalNode<ContextType>> next_;
	std::shared_ptr<BidirectionalNode<ContextType>> prev_;
	BidirectionalNode(ContextType element) :context(element) {}
	friend std::ostream& operator<<(std::ostream& out, const BidirectionalNode<ContextType>& node) {
		out << node.context;
		return out;
	}
};

template <class ContextType>
class SinglyLinkedList {
public:
	std::shared_ptr<UnidirectionalNode<ContextType>> root_;
	void Push_back(ContextType context) {
		if (!root_) {
			UnidirectionalNode<ContextType> new_root(context);
			root_ = std::make_shared<UnidirectionalNode<ContextType>>(new_root);
		}
		else {
			std::shared_ptr<UnidirectionalNode<ContextType>> current_pointer = root_;
			while (current_pointer->next_) {
				current_pointer = current_pointer->next_;
			}
			UnidirectionalNode<ContextType> new_node(context);
			current_pointer->next_ = std::make_shared<UnidirectionalNode<ContextType>>(new_node);
		}
	}
	void Erase(ContextType context) {
		std::shared_ptr<UnidirectionalNode<ContextType>> parent_pointer;
		std::shared_ptr<UnidirectionalNode<ContextType>> current_pointer = root_;
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
	std::shared_ptr<BidirectionalNode<ContextType>> root_;
	void Push_back(ContextType context) {
		if (!root_) {
			BidirectionalNode<ContextType> new_root(context);
			root_ = std::make_shared<BidirectionalNode<ContextType>>(new_root);
		}
		else {
			std::shared_ptr<BidirectionalNode<ContextType>> current_pointer = root_;
			while (current_pointer.get()->next_) {
				current_pointer = current_pointer.get()->next_;
			}
			BidirectionalNode<ContextType> new_root(context);
			new_root.prev_ = current_pointer;
			current_pointer.get()->next_ = std::make_shared<BidirectionalNode<ContextType>>(new_root);
		}
	}
	void Push_front(ContextType context) {
		if (!root_) {
			BidirectionalNode<ContextType> new_root(context);
			root_ =  std::make_shared<BidirectionalNode<ContextType>>(new_root);
		}
		else {
			BidirectionalNode<ContextType> new_node(context);
			new_node.next_ = root_;
			root_->prev_ = std::make_shared<BidirectionalNode<ContextType>>(new_node);
			root_ = root_.get()->prev_;
		}
	}
	void Erase(ContextType context) {
		std::shared_ptr<BidirectionalNode<ContextType>> current_pointer = root_;
		while (current_pointer.get()->context != context && current_pointer.get()->next_) {
			current_pointer = current_pointer.get()->next_;
		}
		if (!current_pointer.get()->next_ && current_pointer.get()->context != context) return;

		if (current_pointer == root_) {
			root_ = current_pointer.get()->next_;
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
	std::shared_ptr<List<ContextType>> list;
public:
	Queue(List<ContextType> current_list) : list(std::make_shared<List<ContextType>>(current_list)) {}
	void Push(ContextType context){
		list.get()->Push_back(context);
	}
	ContextType Pop() {
		ContextType context = list.get()->root_->context;
		list.get()->Erase(list.get()->root_.get()->context);
		return context;
	}
	bool Empty() {
		if (list.get()->root_)return false;
		else return true;
	}
};