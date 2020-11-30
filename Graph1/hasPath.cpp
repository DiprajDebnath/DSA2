#include<iostream>
#include<queue>
using namespace std;

bool BFS(int **edges, int v, int sv, int ev, bool *visited) {
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    while (! q.empty()){
        int front = q.front();
        q.pop();
        for(int i = 0; i < v; i++) {
            if(front == i) {
                continue;
            }
            if(edges[front][i] && visited[i] == false) {
                if(i == ev){
                    return true;
                }
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}

bool hasPath(int **edges, int v, int v1, int v2) {
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }
    bool ans = BFS(edges, v, v1, v2, visited);
    delete [] visited;
    return ans;
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

    int v1, v2;
    cin >> v1 >> v2;

    cout << hasPath(edges, v, v1, v2) << endl;
}