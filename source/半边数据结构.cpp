#include "stdafx.h" 
#include <iostream>
#include<vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <stack>
#include <fstream>

using namespace std;

template <typename Refs>
struct s_Vertex
{
	typedef typename Refs::Edge  Edge;
	Edge* edge;
};

template <typename Refs>
struct s_Edge
{
	typedef typename Refs::Vertex Vertex;
	Vertex*  vertex;
};

struct basedItems
{
	template <typename Refs, typename T>
	struct  Vertex_wrapper
	{
		typedef s_Vertex<Refs>  Vertex;
	};
	template <typename Refs, typename T>
	struct  Edge_wrapper
	{
		typedef s_Edge<Refs>  Edge;
	};
};

template <typename items, typename T>
struct HalfEdgeDS
{
	typedef HalfEdgeDS<items,T>  self;
	typedef typename items::template  Vertex_wrapper<self, T>   vertex_w;
	typedef typename items::template  Edge_wrapper<self, T>    edge_w;
	typedef typename vertex_w::Vertex                          Vertex;
	typedef typename edge_w::Edge                              Edge;
};


//template <typename refs>
//struct  derivedvertex : public s_Vertex<refs>
//{
//	int m_data;
//};

template <typename refs, typename T>
struct  ext_vertex : public s_Vertex<refs>
{
	T name;

};

struct deriveditems : public basedItems 
{
	template <typename refs, typename T>
	struct  Vertex_wrapper
	{
		typedef  ext_vertex<refs, T>   Vertex;
	};
};




int  main()
{
	typedef HalfEdgeDS<deriveditems, int>  HDS;
	typedef ext_vertex<HDS, int>        Vertex;
	typedef s_Edge<HDS>            Edge;
	Vertex    node1;
	node1.name = 100;
	Edge  edge1;
	edge1.vertex = &node1;
	cout << edge1.vertex->name;
	return 0;
}

