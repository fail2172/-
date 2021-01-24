#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Error {
protected:
	string type_error;
	string massege;
public:
	string get_massege() { return massege; }
};
class Note_found_error :public Error {
public:
	Note_found_error(string new_massege) {
		type_error = "note found error";
		massege = new_massege;
	}
};
class Access_error :public Error {
public:
	Access_error(string new_massege) {
		type_error = "access error";
		massege = new_massege;
	}
};
class System_error :public Error {
public:
	System_error(string new_massege) {
		type_error = "system error";
		massege = new_massege;
	}
};

namespace graph_sistem {
	class Vertex;

	ostream& operator<<(ostream& out, Vertex& pvertex);
	ostream& operator<<(ostream& out, const Vertex& pvertex);

	class Edge {
	public:
		pair<Vertex*, Vertex*> edge;
		Edge() { edge = { NULL,NULL }; }
		Edge(Vertex* first_vertex, Vertex* second_vertex) : edge(make_pair(first_vertex, second_vertex)) { }
		friend ostream& operator<<(ostream& out, Edge& pedge) {
			out << *pedge.edge.first << " " << *pedge.edge.second;
			return out;
		}
		friend ostream& operator<<(ostream& out, Edge* pedge) {
			out << *(pedge->edge.first) << " " << *(pedge->edge.second);
			return out;
		}
		friend ostream& operator<<(ostream& out, const Edge& pedge) {
			out << *pedge.edge.first << " " << *pedge.edge.second;
			return out;
		}
	};

	class Vertex {
	public:
		string id;
		vector<bool> edge;
		vector<Vertex*> adjacent_vertex;
		vector <Edge> incidental_edge;
		Vertex() :id("") {}
		Vertex(string name_of_vertex) :id(name_of_vertex) {
			adjacent_vertex = { NULL,NULL };
			incidental_edge.resize(2, Edge());
		}

		friend ostream& operator<<(ostream& out, Vertex& pvertex) {
			if (pvertex.id == "")throw Access_error("Going beyond the vector");
			out << pvertex.id;
			return out;
		}
		friend ostream& operator<<(ostream& out, const Vertex& pvertex) {
			if (pvertex.id == "")throw Access_error("Going beyond the vector");
			out << pvertex.id;
			return out;
		}
		friend ostream& operator<<(ostream& out, Vertex* pvertex) {
			if (pvertex == NULL)throw Access_error("Going beyond the vector");
			out << pvertex->id;
			return out;
		}
		friend ostream& operator<<(ostream& out, const Vertex* pvertex) {
			if (pvertex == NULL)throw Access_error("Going beyond the vector");
			out << pvertex->id;
			return out;
		}


	};
}

class Ungraph {
	vector<graph_sistem::Vertex> vertex;
	vector<graph_sistem::Edge> edge;
	void delete_edge(int number_of_edge);
	bool check_vertex(string name_of_vertex, int& number_of_vertex);
	bool check_edge(string first_vertex, string second_vertex, int& number_of_edge);
public:

	Ungraph() {
		vertex.resize(2, graph_sistem::Vertex());
		edge.resize(2, graph_sistem::Edge());
	}

	void add_vertex(string name_of_vertex);
	void delete_vertex(string name_of_vertex);

	void add_edge(string first_vertex, string second_vertex);
	void delete_edge(string first_vertex, string second_vertex);

	bool check_vertex(string name_of_vertex);
	bool check_edge(string first_vertex, string second_vertex);

	int numb_of_vertex() { return vertex.size() - 2; }
	int number_of_edge() { return edge.size() - 2; }

	int degree_of_vertex(string name_of_vertex);
	int degree_of_edge(string first_vertex, string seconde_vertex);


	template<class Iter>
	class Graph_iterator {
		friend class Ungraph;
		typedef Iter iterator_type;
		typedef input_iterator_tag iterator_category;
		typedef iterator_type value_type;
		typedef ptrdiff_t difference_type;
		typedef iterator_type* pointer;
		typedef iterator_type& reference;
		Iter* value;
	public:
		Graph_iterator() { value = NULL; }
		Graph_iterator(Iter* p) :value(p) {}
		Graph_iterator(Graph_iterator& other) : value(other.value) {}
		Graph_iterator(Graph_iterator const& other) : value(other.value) {}

		bool operator==(Graph_iterator const& other) { return value == other.value; }
		bool operator!=(Graph_iterator const& other) { return value != other.value; }
		Graph_iterator& operator=(Graph_iterator const& other) { value = other.value; return *this; }

		typename Graph_iterator::reference operator*() const {
			return *value;
		}

		Graph_iterator& operator++() {
			value++;
			return *this;
		}
		Graph_iterator& operator--() {
			value--;
			return *this;
		}

		Graph_iterator& operator+(int number) {
			while (number) {
				++* this;
				number--;
			}
			return *this;
		}
		Graph_iterator& operator-(int number) {
			while (number) {
				--* this;
				number--;
			}
			return *this;
		}

		Graph_iterator& operator +=(int number) {
			return *this = *this + number;
		}
		Graph_iterator& operator -=(int number) {
			return *this = *this - number;
		}
	};

	template<class Iter>
	class Graph_reverse_iterator {
		friend class Ungraph;
		typedef Iter iterator_type;
		typedef input_iterator_tag iterator_category;
		typedef iterator_type value_type;
		typedef ptrdiff_t difference_type;
		typedef iterator_type* pointer;
		typedef iterator_type& reference;
		Iter* value;
	public:
		Graph_reverse_iterator() { value = NULL; }
		Graph_reverse_iterator(Iter* p) :value(p) {}
		Graph_reverse_iterator(Graph_reverse_iterator& other) : value(other.value) {}
		Graph_reverse_iterator(const Graph_reverse_iterator& other) : value(other.value) {}

		bool operator==(Graph_reverse_iterator const& other) { return value == other.value; }
		bool operator!=(Graph_reverse_iterator const& other) { return value != other.value; }
		Graph_reverse_iterator& operator=(Graph_reverse_iterator const& other) { value = other.value; return *this; }

		typename Graph_reverse_iterator::reference operator*() const {
			return *value;
		}

		Graph_reverse_iterator& operator++() {
			value--;
			return *this;
		}
		Graph_reverse_iterator& operator--() {
			value++;
			return *this;
		}

		Graph_reverse_iterator& operator+(int number) {
			while (number) {
				++* this;
				number--;
			}
			return *this;
		}
		Graph_reverse_iterator& operator-(int number) {
			while (number) {
				--* this;
				number--;
			}
			return *this;
		}

		Graph_reverse_iterator& operator +=(int number) {
			return *this = *this + number;
		}
		Graph_reverse_iterator& operator -=(int number) {
			return *this = *this - number;
		}
	};

	typedef Graph_iterator<graph_sistem::Vertex> Vertex_iterator;
	typedef Graph_iterator<const graph_sistem::Vertex> Vertex_citerator;
	typedef Graph_reverse_iterator<graph_sistem::Vertex> Vertex_riterator;

	typedef Graph_iterator<graph_sistem::Vertex*> Adjacent_iterator;
	typedef Graph_iterator<graph_sistem::Vertex*> Adjacent_citerator;
	typedef Graph_reverse_iterator<graph_sistem::Vertex*> Adjacent_riterator;



	Vertex_iterator vertex_begin() {
		if (!vertex.size() == 2)throw  Access_error("Vector has no elements");
		return Vertex_iterator(&vertex[1]);
	}
	Vertex_iterator vertex_end() {
		if (!vertex.size() == 2)throw Access_error("Vector has no elements");
		return Vertex_iterator(&vertex[vertex.size() - 1]);
	}

	Vertex_citerator vertex_cbegin() {
		if (!vertex.size() == 2)throw Access_error("Vector has no elements");
		return Vertex_citerator(&vertex[1]);
	}
	Vertex_citerator vertex_cend() {
		if (!vertex.size() == 2)throw Access_error("Vector has no elements");
		return Vertex_citerator(&vertex[vertex.size() - 1]);
	}

	Vertex_riterator vertex_rbegin() {
		if (!vertex.size() == 2)throw Access_error("Vector has no elements");
		return Vertex_riterator(&vertex[vertex.size() - 2]);
	}
	Vertex_riterator vertex_rend() {
		if (!vertex.size() == 2)throw Access_error("Vector has no elements");
		return Vertex_riterator(&vertex[0]);
	}



	Adjacent_iterator vertex_begin(string vertex_name) {
		int vertex_number;
		if (!check_vertex(vertex_name, vertex_number))throw Note_found_error("Vertex note found");
		if (vertex[vertex_number].adjacent_vertex.size() == 2)throw Access_error("Vector has no elements");
		return Adjacent_iterator(&vertex[vertex_number].adjacent_vertex[1]);
	}
	Adjacent_iterator vertex_end(string vertex_name) {
		int vertex_number;
		if (!check_vertex(vertex_name, vertex_number))throw Note_found_error("Vertex note found");
		if (vertex[vertex_number].adjacent_vertex.size() == 2)throw Access_error("Vector has no elements");
		return Adjacent_iterator(&vertex[vertex_number].adjacent_vertex[vertex[vertex_number].adjacent_vertex.size() - 1]);
	}

	Adjacent_riterator vertex_rbegin(string vertex_name) {
		int vertex_number;
		if (!check_vertex(vertex_name, vertex_number))throw Note_found_error("Vertex note found");
		if (vertex[vertex_number].adjacent_vertex.size() == 2)throw Access_error("Vector has no elements");
		return Adjacent_riterator(&vertex[vertex_number].adjacent_vertex[vertex[vertex_number].adjacent_vertex.size() - 2]);
	}
	Adjacent_riterator vertex_rend(string vertex_name) {
		int vertex_number;
		if (!check_vertex(vertex_name, vertex_number))throw Note_found_error("Vertex note found");
		if (vertex[vertex_number].adjacent_vertex.size() == 2)throw Access_error("Vector has no elements");
		return Adjacent_riterator(&vertex[vertex_number].adjacent_vertex[0]);
	}

	Adjacent_citerator vertex_cbegin(string vertex_name) {
		int vertex_number;
		if (!check_vertex(vertex_name, vertex_number))throw Note_found_error("Vertex note found");
		if (vertex[vertex_number].adjacent_vertex.size() == 2)throw Access_error("Vector has no elements");
		return Adjacent_citerator(&vertex[vertex_number].adjacent_vertex[1]);
	}
	Adjacent_citerator vertex_cend(string vertex_name) {
		int vertex_number;
		if (!check_vertex(vertex_name, vertex_number))throw Note_found_error("Vertex note found");
		if (vertex[vertex_number].adjacent_vertex.size() == 2)throw Access_error("Vector has no elements");
		return Adjacent_citerator(&vertex[vertex_number].adjacent_vertex[vertex[vertex_number].adjacent_vertex.size() - 1]);
	}



	typedef Graph_iterator<graph_sistem::Edge> Edge_iterator;
	typedef Graph_iterator<const graph_sistem::Edge> Edge_citerator;
	typedef Graph_reverse_iterator<graph_sistem::Edge> Edge_riterator;

	typedef Graph_iterator<graph_sistem::Edge> Incidental_iterator;
	typedef Graph_iterator<const graph_sistem::Edge> Incidental_citerator;
	typedef Graph_reverse_iterator<graph_sistem::Edge> Incidental_riterator;

	Edge_iterator edge_begin() {
		if (edge.size() == 2)throw Access_error("Vector has no elements");
		return Edge_iterator(&edge[1]);
	}
	Edge_iterator edge_end() {
		if (edge.size() == 2)throw Access_error("Vector has no elements");
		return Edge_iterator(&edge[edge.size() - 1]);
	}

	Edge_citerator edge_cbegin() {
		if (edge.size() == 2)throw Access_error("Vector has no elements");
		return Edge_citerator(&edge[1]);
	}
	Edge_citerator edge_cend() {
		if (edge.size() == 2)throw Access_error("Vector has no elements");
		return Edge_citerator(&edge[edge.size() - 1]);
	}

	Edge_riterator edge_rbegin() {
		if (edge.size() == 2)throw Access_error("Vector has no elements");
		return Edge_riterator(&edge[edge.size() - 2]);
	}
	Edge_riterator edge_rend() {
		if (edge.size() == 2)throw Access_error("Vector has no elements");
		return Edge_riterator(&edge[0]);
	}



	Incidental_iterator edge_begin(string vertex_name) {
		int vertex_number;
		if (!check_vertex(vertex_name, vertex_number))throw Note_found_error("Vertex note found");
		if (vertex[vertex_number].incidental_edge.size() == 2)throw Access_error("Vector has no elements");
		return Incidental_iterator(&vertex[vertex_number].incidental_edge[1]);
	}
	Incidental_iterator edge_end(string vertex_name) {
		int vertex_number;
		if (!check_vertex(vertex_name, vertex_number))throw Note_found_error("Vertex note found");
		if (vertex[vertex_number].incidental_edge.size() == 2)throw Access_error("Vector has no elements");
		return Incidental_iterator(&vertex[vertex_number].incidental_edge[vertex[vertex_number].incidental_edge.size() - 1]);
	}

	Incidental_citerator edge_cbegin(string vertex_name) {
		int vertex_number;
		if (!check_vertex(vertex_name, vertex_number))throw Note_found_error("Vertex note found");
		if (vertex[vertex_number].incidental_edge.size() == 2)throw Access_error("Vector has no elements");
		return Incidental_citerator(&vertex[vertex_number].incidental_edge[1]);
	}
	Incidental_citerator edge_cend(string vertex_name) {
		int vertex_number;
		if (!check_vertex(vertex_name, vertex_number))throw Note_found_error("Vertex note found");
		if (vertex[vertex_number].incidental_edge.size() == 2)throw Access_error("Vector has no elements");
		return Incidental_citerator(&vertex[vertex_number].incidental_edge[vertex[vertex_number].incidental_edge.size() - 1]);
	}

	Incidental_riterator edge_rbegin(string vertex_name) {
		int vertex_number;
		if (!check_vertex(vertex_name, vertex_number))throw Note_found_error("Vertex note found");
		if (vertex[vertex_number].incidental_edge.size() == 2)throw Access_error("Vector has no elements");
		return Incidental_riterator(&vertex[vertex_number].incidental_edge[vertex[vertex_number].incidental_edge.size() - 2]);
	}
	Incidental_riterator edge_rend(string vertex_name) {
		int vertex_number;
		if (!check_vertex(vertex_name, vertex_number))throw Note_found_error("Vertex note found");
		if (vertex[vertex_number].incidental_edge.size() == 2)throw Access_error("Vector has no elements");
		return Incidental_riterator(&vertex[vertex_number].incidental_edge[0]);
	}

	void erase(Vertex_iterator object) { delete_vertex(object.value->id); }
	void erase(Vertex_citerator object) { delete_vertex(object.value->id); }
	void erase(Vertex_riterator object) { delete_vertex(object.value->id); }

	void erase(Edge_iterator object) { delete_edge(object.value->edge.first->id, object.value->edge.second->id); }
	void erase(Edge_citerator object) { delete_edge(object.value->edge.first->id, object.value->edge.second->id); }
	void erase(Edge_riterator object) { delete_edge(object.value->edge.first->id, object.value->edge.second->id); }

	void erase(Adjacent_iterator object) { delete_vertex((*object)->id); }
	void erase(Adjacent_riterator object) { delete_vertex((*object)->id); }

};