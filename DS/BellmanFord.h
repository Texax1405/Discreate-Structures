#include <bits/stdc++.h>

using namespace std;

void BF(int graph[30][30], int numVertices, char startVertices, int values[], int prev[]);

string BF_Path(int graph[30][30], int numVertices, char startVertices, char goalVertex);
