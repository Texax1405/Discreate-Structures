#include "tsp.h"

using namespace std;

int main()
{
    ifstream inputFile("graph.txt");
    int numVertices;
    inputFile >> numVertices;

    int graph[30][30];
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            inputFile >> graph[i][j];
        }
    }
    
    char startVertex;
    inputFile >> startVertex;
    char goalVertex;
    inputFile >> goalVertex;

    inputFile.close();

    //Find shortest path by using Bellman-Ford algorithm
    int* values= new int[numVertices];
    int* prev = new int[numVertices];

    BF(graph, numVertices, startVertex, values, prev);

    string path = BF_Path(graph, numVertices, startVertex, goalVertex);
    cout << "Shortest path from A to E: " << path << endl;

    //Traveling Salesman Problem
    cout << "Traveling Salesman Problem: ";
    Traveling(graph, numVertices, startVertex);

    return 0;
}