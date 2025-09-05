#include <BellmanFord.h>

void BF(int graph[30][30], int numVertices, 
        char startVertices, vector<int>& values, vector<int>& prev){

    // Update data
    int startIndex = startVertices - 'A';

    if (values[startIndex] == -1){
        for (int i = 0; i < numVertices; i++){
            values[i] = graph[startIndex][i];
            prev[i] = startIndex;
            
            if (values[i] == 0){
                values[i] = -1;
                prev[i] = -1;
            }
        }

        values[startIndex] = 0;
        prev[startIndex] = -1;

        return;
    }

    // tempMatrix
    int tempValues[30];
    for (int i = 0; i < numVertices; i++){
        tempValues[i] = values[i];
    }

    // Iteration Step
    for (int u = 0; u < numVertices; u++){
        if (tempValues[u] == -1 && values[u] == -1){
            values[u] = 1e8;
            prev[u] = 0;
            tempValues[u] = 1e8;
        }

        for (int v = 0; v < numVertices; v++){
            if (graph[v][u] != 0 && tempValues[v] != -1 && tempValues[v] + graph[v][u] < values[u]){
                values[u] = tempValues[v] + graph[v][u];
                prev[u] = v;
            }
        }
    }
    for (int i = 0; i < numVertices; i++){
        if (values[i] == 1e8){
            values[i] = -1;
            tempValues[i] = -1;
        }
    }      
}

string BF_Path(int graph[30][30], int numVertices, char startVertex, char goalVertex){
    // Your code is here
    
    vector<int> prev(numVertices);
    vector<int> values(numVertices);
    int numGoal = goalVertex - 'A';
    int numStart = startVertex - 'A';
    string path = "";
    int curr = numGoal;

    for (int i = 0; i < numVertices; i++){
        values[i] = -1;
        prev[i] = -1;
    }

    for (int i = 0; i < numVertices - 1; i++){
        BF(graph, numVertices, startVertex, values, prev);
    }
    
    if (values[numGoal] == -1){
        return "There's no exit!";
    }

    while (curr != numStart){
        path = char(curr + 'A') + (path.empty() ? "" : ' ' + path);
        curr = prev[curr];
    }

    path = startVertex + (path.empty() ? "" : ' ' + path);

    return path;
}



