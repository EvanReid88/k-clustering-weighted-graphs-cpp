// MSTProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "MSTCluster.h"

void printMatrix(int numVertices, std::vector<std::vector<int>> matrix) {
	for (int i = 0; i < numVertices; i++) {
		for (int j = 0; j < numVertices; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	// TODO add check for symmetry when creating mst class (b/c graphs are non-directional)

	int numVertices = 5;

	// must be symmetric
	std::vector<std::vector<int>> vec{
	 {0 ,0 ,9 ,11,2 },
	 {0 ,0 ,4 ,2 ,5 },
	 {9 ,4 ,0 ,0 ,6 },
	 {11,2 ,0 ,0 ,0 },
	 {2 ,5 ,6 ,0 ,0 },
	};

	MSTCluster newMST = MSTCluster(numVertices, vec);

	// determine adjacency matrix representation of a 2-cluster graph 
	std::vector<std::vector<int>> kClusters = newMST.KCluster(2);

	printMatrix(numVertices, kClusters);
}
