#include<iostream>
#include<queue>
using namespace std;

// DFS
void printDFS(int **edges, int v, int sv, bool *visited) {
    cout << sv << endl;
    visited[sv] = true;

    for(int i = 0; i < v; i++) {
        if(sv == i) {
            continue;
        }
        // if their is an edge between sv and i 
        // and also i is not visited then print i
        if(edges[sv][i] == 1 && visited[i] == false) {
            printDFS(edges, v, i, visited);
        }
    }
}

void DFS(int **edges, int v) {
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }

    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            printDFS(edges, v, i, visited);
        }
    }
    delete []visited;
}

// BFS
void printBFS(int **edges, int v, int sv, bool *visited) {
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    while (! q.empty()){
        int front = q.front();
        q.pop();

        cout << front << endl;

        for(int i = 0; i < v; i++) {
            if(front == i) {
                continue;
            }
            if(edges[front][i] && visited[i] == false) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int v) {
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }

    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            printBFS(edges, v, i, visited);
        }
    }
    delete [] visited;
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

    //DFS(edges, v);
    BFS(edges, v);

    for(int i = 0; i < v; i++) {
        delete [] edges[i];
    }
    delete []edges;
}