#include "Undirected_graph.h"

using namespace graph_sistem;

void Ungraph::add_vertex(string name_of_vertex)
{
	if (name_of_vertex == "")throw System_error("Invalid vertex name");
	if(check_vertex(name_of_vertex))return;

	Vertex template_vertex(name_of_vertex);
	if (vertex.size()) {
		template_vertex.edge.reserve(vertex[0].edge.size());
	}
	vertex[vertex.size() - 1] = template_vertex;
	vertex.push_back(Vertex());
}

void Ungraph::delete_vertex(string name_of_vertex)
{
	int number_of_delete_vertex;
	if (check_vertex(name_of_vertex, number_of_delete_vertex)) {
		for (int i = 0; i < vertex[number_of_delete_vertex].edge.size(); i++)
			if (vertex[number_of_delete_vertex].edge[i])delete_edge(i);
	}
	else
		throw Note_found_error("Edge not found");


	vector<string> address_correction;
	for (int i = number_of_delete_vertex + 1; i < vertex.size() - 1; i++)
		address_correction.push_back(vertex[i].id);

	//correction of pointers
	for (int i = 1; i < edge.size() - 1; i++) {
		for (int j = 0; j < address_correction.size(); j++) {
			if (edge[i].edge.first->id == address_correction[j])
				edge[i].edge.first--;
			if (edge[i].edge.second->id == address_correction[j])
				edge[i].edge.second--;
		}
	}

	for (int i = 1; i < vertex.size() - 1; i++) {
		for (int j = 1; j < vertex[i].incidental_edge.size() - 1; j++) {
			for (int k = 0; k < address_correction.size(); k++) {
				if (vertex[i].incidental_edge[j].edge.first->id == address_correction[k])
					vertex[i].incidental_edge[j].edge.first--;
				if (vertex[i].incidental_edge[j].edge.second->id == address_correction[k])
					vertex[i].incidental_edge[j].edge.second--;
			}
		}
	}

	for (int i = 1; i < vertex.size() - 1; i++) {
		for (int j = 1; j < vertex[i].adjacent_vertex.size() - 1; j++) {
			for (int k = 0; k < address_correction.size(); k++) {
				if (vertex[i].adjacent_vertex[j]->id == address_correction[k])
					vertex[i].adjacent_vertex[j]--;
			}
		}
	}

	for (int i = 1; i < edge.size() - 1; i++) {
		if (edge[i].edge.first->id == name_of_vertex || edge[i].edge.second->id == name_of_vertex)
			edge.erase(edge.begin() + i);
	}

	vertex.erase(vertex.begin() + number_of_delete_vertex);

}

void Ungraph::add_edge(string first_vertex, string second_vertex)
{
	int first_vertex_number, second_vertex_number;
	if (!check_vertex(first_vertex, first_vertex_number) || !check_vertex(second_vertex, second_vertex_number))throw 5;
	if (check_edge(first_vertex, second_vertex))return;
	for (int i = 0; i < vertex.size();i++) {
		if (vertex[i].id == first_vertex || vertex[i].id == second_vertex)
			vertex[i].edge.push_back(true);
		else
			vertex[i].edge.push_back(false);
	}

	Edge temp_edge(&vertex[first_vertex_number],&vertex[second_vertex_number]);
	edge[edge.size() - 1] = temp_edge;
	edge.push_back(Edge());

	
	vertex[first_vertex_number].adjacent_vertex[vertex[first_vertex_number].adjacent_vertex.size() - 1] = &vertex[second_vertex_number];
	vertex[first_vertex_number].adjacent_vertex.push_back(NULL);

	vertex[second_vertex_number].adjacent_vertex[vertex[second_vertex_number].adjacent_vertex.size() - 1] = &vertex[first_vertex_number];
	vertex[second_vertex_number].adjacent_vertex.push_back(NULL);

	vertex[first_vertex_number].incidental_edge[vertex[first_vertex_number].incidental_edge.size() - 1] = temp_edge;
	vertex[first_vertex_number].incidental_edge.push_back(Edge());

	vertex[second_vertex_number].incidental_edge[vertex[second_vertex_number].incidental_edge.size() - 1] = temp_edge;
	vertex[second_vertex_number].incidental_edge.push_back(Edge());

}

void Ungraph::delete_edge(int edge_number)
{
	for (int i = 1; i < vertex.size() - 1; i++)
		vertex[i].edge.erase(vertex[i].edge.begin() + edge_number);

	edge_number++;

	//delete incidental_edge
	for (int i = 1; i < edge[edge_number].edge.first->incidental_edge.size() - 1; i++)
		if (edge[edge_number].edge.first->incidental_edge[i].edge.first->id == edge[edge_number].edge.second->id || edge[edge_number].edge.first->incidental_edge[i].edge.second->id == edge[edge_number].edge.second->id) {
			edge[edge_number].edge.first->incidental_edge.erase(edge[edge_number].edge.first->incidental_edge.begin() + i);
			break;
		}

	for (int i = 1; i < edge[edge_number].edge.second->incidental_edge.size() - 1; i++)
		if (edge[edge_number].edge.second->incidental_edge[i].edge.second->id == edge[edge_number].edge.first->id || edge[edge_number].edge.second->incidental_edge[i].edge.first->id == edge[edge_number].edge.first->id) {
			edge[edge_number].edge.second->incidental_edge.erase(edge[edge_number].edge.second->incidental_edge.begin() + i);
			break;
		}

	//delete adjacent_vertex
	for (int i = 1; i < edge[edge_number].edge.first->adjacent_vertex.size() - 1; i++) {
		if (edge[edge_number].edge.first->adjacent_vertex[i]->id == edge[edge_number].edge.second->id) {

			auto it = edge[edge_number].edge.first->adjacent_vertex.end() - 1;
			edge[edge_number].edge.first->adjacent_vertex.erase(edge[edge_number].edge.first->adjacent_vertex.begin() + i);
			break;
		}
	}
	
	for (int i = 1; i < edge[edge_number].edge.second->adjacent_vertex.size() - 1; i++) {
		if (edge[edge_number].edge.second->adjacent_vertex[i]->id == edge[edge_number].edge.first->id) {

			auto it = edge[edge_number].edge.second->adjacent_vertex.end() - 1;
			edge[edge_number].edge.second->adjacent_vertex.erase(edge[edge_number].edge.second->adjacent_vertex.begin() + i);
			break;
		}
	}
}

void Ungraph::delete_edge(string first_vertex, string second_vertex)
{
	int edge_number;
	if (!check_edge(first_vertex, second_vertex, edge_number))throw Note_found_error("Edge not found");
	delete_edge(edge_number);
	edge.erase(edge.begin() + edge_number + 1);
}

bool Ungraph::check_vertex(string name_of_vertex)
{
	for (auto temp_vertex : vertex)
		if (temp_vertex.id == name_of_vertex)return true;
	return false;
}

bool Ungraph::check_vertex(string name_of_vertex, int& number_of_vertex)
{
	for (int i = 0; i < vertex.size(); i++)
		if (vertex[i].id == name_of_vertex) {
			number_of_vertex = i;
			return true;
		}
	return false;
}

bool Ungraph::check_edge(string first_vertex, string second_vertex, int& number_of_edge)
{
	int number_of_first_vertex, number_of_second_vertex;
	if (check_vertex(first_vertex, number_of_first_vertex) && check_vertex(second_vertex, number_of_second_vertex)) {
		for (int i=0; i < vertex[number_of_first_vertex].edge.size(); i++)
			if (vertex[number_of_first_vertex].edge[i] == true && vertex[number_of_second_vertex].edge[i] == true) {
				number_of_edge = i;
				return true;
			}
	}
	return false;
}

bool Ungraph::check_edge(string first_vertex, string second_vertex)
{
	int number_of_first_vertex, number_of_second_vertex;
	if (check_vertex(first_vertex, number_of_first_vertex) && check_vertex(second_vertex, number_of_second_vertex)) {
		for (int i = 0; i < vertex[number_of_first_vertex].edge.size(); i++)
			if (vertex[number_of_first_vertex].edge[i] == true && vertex[number_of_second_vertex].edge[i] == true)
				return true;
	}
	return false;
}

int Ungraph::degree_of_vertex(string name_of_vertex)
{
	int number_of_vertex;
	if (check_vertex(name_of_vertex, number_of_vertex)) {
		int degree = 0;
		for (auto temp_edge : vertex[number_of_vertex].edge)
			if (temp_edge)degree++;
		return degree;
	}
	else
		throw Note_found_error("Vertex note found");
}

int Ungraph::degree_of_edge(string first_vertex, string seconde_vertex)
{
	if (!check_vertex(first_vertex) || !check_vertex(seconde_vertex))throw Note_found_error("Vertex note found");
	if (check_edge(first_vertex, seconde_vertex))return 2;
	else return 0;
}