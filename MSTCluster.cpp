#include "MSTCluster.h"
#include <vector>
#include <iostream>
#include <bits/stdc++.h> 

MSTCluster::MSTCluster(int numVertices, std::vector<std::vector<int>> adjMatrix) {
	_numVertices = numVertices;
	_adjMatrix = adjMatrix;
}

// A function to find the vertex with  
// minimum key value, from the set of vertices  
// not yet included in MST  
int MSTCluster::minKey(int key[], bool vertSet[])  
{  
    // Initialize min value  
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < _numVertices; v++)  
        if (vertSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  

// A function to find the MST from a weighted non-directional graph
// returns the adjacency matrix of the MST
// time complexity of O(n^2)
std::vector<std::vector<int>> MSTCluster::primMST() {

	// 2D vector to store MST adjacency matrix
	std::vector<int> rowVec(_numVertices, 0);
	std::vector<std::vector<int>> mstAdjMatrix(_numVertices, rowVec);

	// Array to store constructed MST  
    int parent[_numVertices];  
      
    // Key values used to pick minimum weight edge in cut  
    int key[_numVertices];  
      
    // To represent set of vertices not yet included in MST  
    bool vertSet[_numVertices];  
  
    // Initialize all keys as max int (infinite) 
    for (int i = 0; i < _numVertices; i++){
		key[i] = INT_MAX, vertSet[i] = false;
	}    
  
    // Always include first 1st vertex in MST.  
    // Make key 0 so that this vertex is picked as first vertex.  
    key[0] = 0;  

	// set first node as root of MST
    parent[0] = -1;  
  
    // The MST will have _numVertices vertices  
    for (int count = 0; count < _numVertices - 1; count++) 
    {  
        // Pick the minimum key vertex from the  
        // set of vertices not yet included in MST  
        int u = minKey(key, vertSet);  
  
        // Add the picked vertex to the vertex set
        vertSet[u] = true;  
  
        // Update key value and parent index of  
        // the adjacent vertices of the picked vertex.  
        // Consider only those vertices which are not  
        // yet included in MST  

        for (int v = 0; v < _numVertices; v++)  {

			// _adjMatrix[u][v] is non zero only for adjacent vertices of m  
            // vertSet[v] is false for vertices not yet included in MST  
            // Update the key only if _adjMatrix[u][v] is smaller than key[v]  
            if (_adjMatrix[u][v] && vertSet[v] == false && _adjMatrix[u][v] < key[v])  {
				parent[v] = u, key[v] = _adjMatrix[u][v];  
			}
		}
    }  

	// set values of the MST adjacency matrix
	for (int i = 1; i < _numVertices; i++) {
        mstAdjMatrix[parent[i]][i] = _adjMatrix[i][parent[i]];
        mstAdjMatrix[i][parent[i]] = _adjMatrix[i][parent[i]];
    }  

	return mstAdjMatrix;
}

// A function to find the adjacency matrix representation of
// a graph with k-clusters derived from the MST of the graph
std::vector<std::vector<int>> MSTCluster::KCluster(int clusters) {

	// calculate the MST adjacency matrix of the weighted graph
	std::vector<std::vector<int>> clusterMatrix = primMST();

	std::cout << "Edges removed and their weights:" << std::endl;

	// find edges with maximum weight
	for (int k = 0; k < clusters - 1; k++){

		// set the current maximum edge weight to 0
		int maxWeight = 0;

		// set the current vertices adjacent to maximum weight edge to 0
		int maxX = 0; 
		int maxY = 0;
		
		for (int i = 1; i < _numVertices; i++) {
			for (int j = i + 1; j < _numVertices; j++) {

				// if the current edge weight is greater than the current max weight
				if (clusterMatrix[i][j] > maxWeight) {

					// set the maximum edge weight to the current edge weight
					maxWeight = clusterMatrix[i][j];

					// set the vertices adjacent to maximum weight edge
					maxX = i;
					maxY = j;
				}
			}
		}

		// remove the maximum weight edge from adjacency matrix
		clusterMatrix[maxX][maxY] = 0;
		clusterMatrix[maxY][maxX] = 0;

		std::cout << maxX << ":" << maxY <<" (" << maxWeight << ")" << std::endl;
	}

	return clusterMatrix;
}