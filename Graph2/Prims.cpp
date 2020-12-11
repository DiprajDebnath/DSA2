#include<iostream>
using namespace std;

int findLeastWV(int n, int *weight, bool *visited) {
    int w = INT32_MAX;
    int index;
    for(int i = 0; i < n; i++) {
        if(visited[i] == false){
            if(weight[i] < w) {
                w = weight[i];
                index = i;
            }
        }
    }

    return index;
}

void Prims(int **input, int n, int e) {
    bool *visited = new bool[n];
    int *weight = new int[n];
    int *parent = new int[n];

    for(int i = 0; i < n; i++){
        visited[i] = false;
        parent[i] = -1;
        weight[i] = INT32_MAX;
    }

    weight[0] = 0; // Start vertex

    for(int i = 1; i < n; i++) {
        // Find least weight un-visited vertex
        int a = findLeastWV(n, weight, visited);
        visited[a] = true;
        for(int j = 0; j < n; j++) {
            if(input[a][j] != -1) {
                if(input[a][j] < weight[j]){
                    weight[j] = input[a][j];
                    parent[j] = a;
                }
            }
        }
    }

    for(int i = 1; i < n; i++) {
        cout << i << " " << parent[i] << " " << weight[i] << endl;
    }
}

int main() {
    int n, e;

    cin >> n >> e;

    int **input = new int*[n];
    for(int i = 0; i < n; i++){
        input[i] = new int[n];
        for(int j = 0; j < n; j++){
            input[i][j] = -1;
        }
    }

    for(int i = 0; i < e; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        input[s][d] = w;
    }

    Prims(input, n, e);
}