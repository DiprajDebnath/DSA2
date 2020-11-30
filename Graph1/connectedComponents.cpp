#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int>* BFS(int **edges, int v, int sv,bool *visited) {
    queue<int> q;
    vector<int> *path = new vector<int>;
    q.push(sv);
    visited[sv] = true;

    bool found = false;
    while (! q.empty()){
        int front = q.front();
        q.pop();

        path->push_back(front);

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

    return path;
}

void hasPath(int **edges, int v) {
    bool *visited = new bool[v];
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }

    vector<vector<int>*> path;
    
    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            path.push_back(BFS(edges, v, i, visited));
        }
    }

    for(int i = 0; i < path.size(); i++) {
        vector<int> *p = path[i];
        vector<int>::iterator it = p->begin();
        while(it != p->end()){
            cout << *it << " ";
            it++;
        }
        cout << endl;
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


    hasPath(edges, v);
}