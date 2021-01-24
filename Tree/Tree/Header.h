#pragma once
#include <iostream>

class Tree {
	class Node {
	public:
		Node(void* object) :value(object) {}
		void* value;
		std::shared_ptr<Node> right_;
		std::shared_ptr<Node> left_;
	};
public:
	std::shared_ptr<Node> root_;
	void Insert(void* object, std::shared_ptr<Node>& curr_addres) {
		if (!curr_addres) {
			Node added_node(object);
			curr_addres = std::make_shared<Node>(added_node);
		}
		else {
			if (curr_addres.get()->value > object)Insert(object, curr_addres.get()->left_);
			if (curr_addres.get()->value < object)Insert(object, curr_addres.get()->right_);
		}
	}
};