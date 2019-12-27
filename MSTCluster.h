#pragma once

#include <vector>

class MSTCluster
{
	private:
	int _numVertices;
	std::vector<std::vector<int>> _adjMatrix;
		
	public:
		MSTCluster(int numVertices, std::vector<std::vector<int>> adjMatrix);
        int minKey(int key[], bool vertSet[]);
		std::vector<std::vector<int>> primMST();
        std::vector<std::vector<int>> KCluster(int clusters);
	
};
