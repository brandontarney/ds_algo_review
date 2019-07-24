/*
   DepthFirstSearch.cpp
	- implement a depth-first-search algorithm using recursion
	- 'w' == white (unvisited), 'g' == gray (visited, but not finished), 'b' == blue (visited & finished)
	- Note, track the following:
		- node-state : {unvisisted, visisted, complete} - prevents duplicate visits
		- previous-node - for providing the path found 
		- distance/cost - for deciding on the cost of a path found
*/

#include<queue>
#include<cstdio>
#include<ctime>

using namespace std;



namespace my_namespace {

#define numVertexes 10
#define numAdjacentVertexes 10

class DFS
{
	char colors[numVertexes];
	int prevVertex[numVertexes];
	int cost[numVertexes];

public:
	void DepthFirstSearch( const size_t graph[][] );
	void DFSVisit( const size_t vertexIdx );
	int cost;
}

void DFS::DepthFirstSearch( const size_t graph[][] )
{
	this->cost = 0;
	/*
	const size_t numAdjacentVertexes = sizeof(graph[0]) / sizeof(size_t);
	const size_t numVertexes = sizeof(graph) / sizeof(graph[0]);
	*/
	for (size_t vertexItr = 0; vertexItr < numVertexes; vertexItr++)
	{
		this->colors[vertexItr] = 'w';
		this->preVertex[vertexItr] = -1;
	}
	for (vertexItr = 0; vertexItr < numVertexes; vertexItr++)
	{
		if (colors[vertexItr] == 'w')
		{
			this->DFSVisit(vertexItr);
		}
	}
}

void DFS::DFSVisit( const int vertexIdx )
{
	this->colors[vertexIdx] = 'g';
	this->cost++;
	for (size_t adjacentVertexItr = 0; adjacentVertexItr < numAdjacentVertexes; adjacentVertex++)
	{
		const size_t adjacentVertexIdx = graph[vertexIdx][adjacentVertexItr];
		if (adjacentVertexIdx != -1)
		{
			if (this->colors[adjacentVertexIdx] == 'w')
			{
				this->prevVertex[adjacentVertexIdx] = vertexIdx;
				this->cost[adjacentVertexIdx] = this->cost;
				this->DFSVisit(adjacentVertexIdx);
			}
			else
			{
				printf("This vertex (%d) has been visited before", adjacentVertexIdx);
			}
		}
		else
		{
			printf("No more adjacent vertexes");
			break;
		}
	}
	this->colors[vertexIdx] = 'b';
}


} //end namespace
