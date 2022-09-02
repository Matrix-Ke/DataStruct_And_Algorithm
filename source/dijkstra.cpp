#include <iostream> 
#include <set>
#include <unordered_set>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

struct MyStruct
{
	MyStruct(int first, int second) : neighbor(first), weigh(second) {};
	int neighbor;
	int weigh;
	bool operator < (const  MyStruct& rhs) const 
	{
		return this->neighbor < rhs.neighbor;
	}

	bool operator == (const MyStruct& rhs) const
	{
		return this->neighbor == rhs.neighbor;
	}
};




class Graph
{
public:
	Graph(int size)
	{
		gSize = size+1;
		container.resize(gSize);
	}
	bool insert(int head, int neighbor, int weigh)
	{	
		const auto& res = container[head].insert(MyStruct(neighbor, weigh));
		const auto& res2 = container[neighbor].insert(MyStruct(head, weigh));
		return res.second && res2.second;
	}
	int dijkstra(int src, int tar)
	{
		vector<int>   dist(gSize, INT_MAX);
		dist[src] = 0;
		vector<bool>  exist(gSize, false);
		for (int headIndex = 1; headIndex < gSize; headIndex++)
		{
			auto& curSet = container[headIndex];
			auto itr = curSet.begin();
			exist[headIndex] = true;
			while ( itr != curSet.end())
			{
				int neighbor = itr->neighbor;
				if (/*exist[neighbor] != true &&*/ dist[headIndex] + itr->weigh < dist[neighbor])
				{
					dist[neighbor] = dist[headIndex] + itr->weigh;
				}
				++itr;
			}
		}
		return dist[tar];

	}
	int gSize;
	vector<set<MyStruct>>   container;
};


int main()
{
	Graph   G(7);
	G.insert(1, 2, 1);
	G.insert(2, 3, 14);
	G.insert(3, 4, 3);
	G.insert(4, 5, 6);
	G.insert(5, 6, 9);
	G.insert(6, 1, 7);
	G.insert(7, 6, 3);
	G.insert(7, 1, 4);
	G.insert(7, 2, 6);
	G.insert(7, 4, 8);
	int dist = G.dijkstra(1, 4);
	cout << dist << endl;
	return 0;
}
