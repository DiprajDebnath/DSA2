#include<iostream>
#include<queue>
using namespace std;

void DFS(int **edges, int v, int sv, bool *visited) {
    // cout << sv << endl;
    visited[sv] = true;

    for(int i = 0; i < v; i++) {
        if(sv == i) {
            continue;
        }
        // if their is an edge between sv and i 
        // and also i is not visited then print i
        if(edges[sv][i] == 1 && visited[i] == false) {
            DFS(edges, v, i, visited);
        }
    }
}

bool isConnected(int **edges, int v) {
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }

    DFS(edges, v, 0, visited);

    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
           return false;
        }
    }
    delete []visited;
    return true;
}


int main() {
    int v, e;
    cin >> v >> e;
    
    int **edges = new int*[v];
    for(int i = 0; i < v; i++) {
        edges[i] = new int[v];
        for(int j = 0; j < v; j++){
            edges[i][j] = 0; // by default 0, means no edge
        }
    }

    // Take input
    for(int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    if(isConnected(edges, v)){
        cout << "true";
    }
    else {
        cout << "false";
    }
}