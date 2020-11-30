#include<iostream>
using namespace std;

void DFS(int** edges, int v, int sv, bool* visited){
    if(visited[sv]) {
        return;
    }

    visited[sv] = true;
    
    for(int i = 0; i < v; i++) {
        if(edges[i][sv] != 0 && !visited[i]){
            DFS(edges, v, i, visited);
        }
    }
}

int cuntGroups(int **edges, int v) {
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }

    int count = 0;

    for(int i = 0; i < v; i++) {
        if(! visited[i]) {
            count++;
            DFS(edges, v, i, visited);
        }
    }

    return count;
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


    cout << cuntGroups(edges, v);
}