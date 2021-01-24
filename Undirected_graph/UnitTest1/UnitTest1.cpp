#include "CppUnitTest.h"
#include "../Undirected_graph/Undirected_graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Adding_a_vertex)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			Assert::IsTrue(G.check_vertex("First_vertex"));
		}
		TEST_METHOD(Adding_a_edge)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			Assert::IsTrue(G.check_edge("First_vertex", "Second_vertex"));
		}
		TEST_METHOD(Delete_vertex)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.delete_vertex("First_vertex");
			Assert::IsTrue(!G.check_vertex("First_vertex"));
		}
		TEST_METHOD(Delete_edge)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			G.delete_edge("First_vertex", "Second_vertex");
			Assert::IsTrue(!G.check_edge("First_vertex", "Second_vertex"));
		}
		TEST_METHOD(Number_of_vertex)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			Assert::IsTrue(G.numb_of_vertex() == 3);
		}
		TEST_METHOD(Number_of_edge)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			G.add_edge("First_vertex", "Third_vertex");
			G.add_edge("Second_vertex", "Third_vertex");
			Assert::IsTrue(G.number_of_edge() == 3);
		}
		TEST_METHOD(Degree_of_vertex)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			G.add_edge("First_vertex", "Third_vertex");
			Assert::IsTrue(G.degree_of_vertex("First_vertex") == 2);
		}
		TEST_METHOD(Degree_of_edge)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			G.add_edge("First_vertex", "Third_vertex");
			Assert::IsTrue(G.degree_of_edge("First_vertex", "Second_vertex") == 2);
		}
		TEST_METHOD(Vertex_iterator)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			Ungraph::Vertex_iterator it = G.vertex_begin();
			Assert::IsTrue(it == G.vertex_begin());
		}
		TEST_METHOD(Edge_iterator)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			G.add_edge("First_vertex", "Third_vertex");
			G.add_edge("Second_vertex", "Third_vertex");
			Ungraph::Edge_iterator it = G.edge_begin();
			it += 3;
			Assert::IsTrue(it == G.edge_end());
		}
		TEST_METHOD(Vertex_citerator)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			Ungraph::Vertex_citerator it = G.vertex_cbegin();
			Assert::IsTrue(it == G.vertex_cbegin());
		}
		TEST_METHOD(Edge_citerator)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			G.add_edge("First_vertex", "Third_vertex");
			G.add_edge("Second_vertex", "Third_vertex");
			Ungraph::Edge_citerator it = G.edge_cbegin();
			it += 3;
			Assert::IsTrue(it == G.edge_cend());
		}
		TEST_METHOD(Vertex_riterator)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			Ungraph::Vertex_riterator it = G.vertex_rbegin();
			Assert::IsTrue(it == G.vertex_rbegin());
		}
		TEST_METHOD(Edge_riterator)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			G.add_edge("First_vertex", "Third_vertex");
			G.add_edge("Second_vertex", "Third_vertex");
			Ungraph::Edge_riterator it = G.edge_rbegin();
			it += 3;
			Assert::IsTrue(it == G.edge_rend());
		}
		TEST_METHOD(Adjacent_iterator)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			G.add_edge("First_vertex", "Third_vertex");
			G.add_edge("Second_vertex", "Third_vertex");
			Ungraph::Adjacent_iterator it = G.vertex_begin("First_vertex");
			it += 2;
			Assert::IsTrue(it == G.vertex_end("First_vertex"));
		}
		TEST_METHOD(Incidental_iterator)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			G.add_edge("First_vertex", "Third_vertex");
			G.add_edge("Second_vertex", "Third_vertex");
			Ungraph::Incidental_iterator it = G.edge_begin("First_vertex");
			it += 2;
			Assert::IsTrue(it == G.edge_end("First_vertex"));
		}
		TEST_METHOD(Adjacent_citerator)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			G.add_edge("First_vertex", "Third_vertex");
			G.add_edge("Second_vertex", "Third_vertex");
			Ungraph::Adjacent_citerator it = G.vertex_cbegin("First_vertex");
			it += 2;
			Assert::IsTrue(it == G.vertex_cend("First_vertex"));
		}
		TEST_METHOD(Incidental_citerator)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			G.add_edge("First_vertex", "Third_vertex");
			G.add_edge("Second_vertex", "Third_vertex");
			Ungraph::Incidental_citerator it = G.edge_cbegin("First_vertex");
			it += 2;
			Assert::IsTrue(it == G.edge_cend("First_vertex"));
		}
		TEST_METHOD(Adjacent_riterator)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			G.add_edge("First_vertex", "Third_vertex");
			G.add_edge("Second_vertex", "Third_vertex");
			Ungraph::Adjacent_riterator it = G.vertex_rbegin("First_vertex");
			it += 2;
			Assert::IsTrue(it == G.vertex_rend("First_vertex"));
		}
		TEST_METHOD(Incidental_riterator)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_vertex("Third_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			G.add_edge("First_vertex", "Third_vertex");
			G.add_edge("Second_vertex", "Third_vertex");
			Ungraph::Edge_riterator it = G.edge_rbegin("First_vertex");
			it += 2;
			Assert::IsTrue(it == G.edge_rend("First_vertex"));
		}
		TEST_METHOD(Delete_iterator_vertex)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			Ungraph::Vertex_iterator it = G.vertex_begin();
			G.erase(it);
			Assert::IsTrue(!G.numb_of_vertex());
		}
		TEST_METHOD(Delete_iterator_edge)
		{
			Ungraph G;
			G.add_vertex("First_vertex");
			G.add_vertex("Second_vertex");
			G.add_edge("First_vertex", "Second_vertex");
			Ungraph::Edge_iterator it = G.edge_begin();
			G.erase(it);
			Assert::IsTrue(!G.number_of_edge());
		}
	};
}
