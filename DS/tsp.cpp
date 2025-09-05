#include "tsp.h"

int tsp(int currPos, int mask, int graph[30][30], int numVertices, char startVertex, vector<vector<int>>& dp, vector<vector<int>>& nextPos){
    if (mask == (1 << numVertices) - 1){
        nextPos[currPos][mask] = startVertex - 'A';
        return graph[currPos][startVertex - 'A'] > 0 ? graph[currPos][startVertex - 'A'] : 1e8;
    }
    
    if (dp[currPos][mask] != -1){
        return dp[currPos][mask];
    }

    int ans = 1e8;
    for (int i = 0; i < numVertices; i++){
        if (!(mask & (1 << i)) && graph[currPos][i] > 0){
            int newAns = graph[currPos][i] + tsp(i, mask | (1 << i), graph, numVertices, startVertex, dp, nextPos);
            if (ans > newAns){
                ans = newAns;
                nextPos[currPos][mask] = i;
            }
        }
    }

    dp[currPos][mask] = ans;
    return ans;
}   

string Traveling(int graph[30][30], int numVertices, char startVertex) {
    vector<vector<int>> dp(numVertices, vector<int>(1 << numVertices, -1));
    vector<vector<int>> nextPos(numVertices, vector<int>(1 << numVertices, -1));
    int startIdx = startVertex - 'A';
    int mask = 1 << startIdx;
    int currPos = startIdx;

    tsp(startIdx, 1 << startIdx, graph, numVertices, startVertex, dp, nextPos);

    vector<char> s;
    s.push_back(startVertex);
    while (true) {
        int next = nextPos[currPos][mask];
        if (next == -1) break;
        s.push_back(next + 'A');
        mask |= (1 << next);
        currPos = next;
    }

    s.push_back(startVertex);

    string ans = "";
    for (int i = 0; i < s.size(); i++){
        ans = ans + s[i] + " ";
    }

    ans.pop_back();
    return ans;
}

