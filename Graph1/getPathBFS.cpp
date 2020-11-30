#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int>* BFS(int **edges, int v, int sv, int ev, bool *visited) {
    unordered_map<int, int> map;
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    bool found = false;
    while (! q.empty()){
        int front = q.front();
        q.pop();
        for(int i = 0; i < v; i++) {
            if(front == i) {
                continue;
            }
            if(edges[front][i] && visited[i] == false) {
                q.push(i);
                visited[i] = true;
                map[i] = front;
                if(i == ev){
                    found = true;
                    break;
                }
            }
        }
    }
    
    vector<int> *path = NULL;
    if(found) {
        path = new vector<int>;
        int start = ev;
        path->push_back(start);
        while(start != sv) {
            path->push_back(map[start]);
            start = map[start];
        }
    }

    return path;
}

void hasPath(int **edges, int v, int v1, int v2) {
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }
    vector<int> *path = BFS(edges, v, v1, v2, visited);
    delete [] visited;
    
    if(path){
        vector<int>::iterator it = path->begin();
        while(it != path->end()){
            cout << *it << " ";
            it++;
        }
    }
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

    hasPath(edges, v, v1, v2);
}