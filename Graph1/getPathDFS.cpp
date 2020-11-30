#include<iostream>
#include<vector>
using namespace std;

bool DFS(int **edges, int v, int sv, int ev, bool *visited, vector<int> *path) {
    if(sv == ev){
        return true;
    }

    for(int i = 0; i < v; i++){
        if(i == sv) {
            continue;
        }
        if(edges[sv][i] == 1 && !visited[i]) {
            visited[sv] = true;
            if(DFS(edges, v, i, ev, visited, path)){
                path->push_back(i);
                return true;
            }
        }
    }
    return false;
}

void getPath(int **edges, int v, int v1, int v2) {
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }

    vector<int> path;    
    if(DFS(edges, v, v1, v2, visited, &path)){
        path.push_back(v1);
        for(int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        //cout << endl;
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

    int v1, v2;
    cin >> v1 >> v2;

    getPath(edges, v, v1, v2);
}