# K-Clustering using Minimum Weight Spanning Trees with Adjacency Matrix Representation

- MSTCluster.cpp is a c++ class which utilizes prim's algorithm for determining minimum weight spanning tree from an adjacency matrix representation of a weighted, non-directional graph. 
- The algorithm then removes the k-1 maximum weight edges in the MST to determine the graph with k-clusters.

# Example

- KClustering_example.cpp initializes a 2D vector representing the adjacency matrix of a weighted graph (must be symmetric since the graph is non-directional)
- The program will print the adjacency matrix of the derived graph with k-clusters