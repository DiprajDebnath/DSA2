#include<iostream>
#include<algorithm>
using namespace std;

class Edge {
    public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight; // < to sort increasing order
}

int findParent(int v, int *parent) {
    if(parent[v] == v){
        return v;
    }

    return findParent(parent[v], parent); // Recursive call
}

void kruskals(Edge *input, int n, int E) {
    // Sort the input array - ascending order based on weights
    sort(input, input + E, compare);

    Edge *output = new Edge[n-1];

    int *parent = new int[n];
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (count != n-1)
    {
        Edge currentEdge = input[i];

        // Check if we can add the current edge in MST or not
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if(sourceParent != destParent) {
            output[count] = currentEdge;
            count++;
            parent[currentEdge.dest] = currentEdge.source;
        }
        i++;
    }

    for(int i = 0; i < n-1; i++) {
        cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
    }
    
}

int main(){
    int n, E;
    cin >> n >> E;
    Edge *input = new Edge[E];

    for(int i = 0; i < E; i++){
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input, n, E);
}


/* 
Input
6 11
1 3 1
0 1 2
0 3 3
0 2 4
4 5 5
2 3 6
3 5 7
2 1 8
2 4 9
2 5 10
3 4 11

Output
1 3 1
0 1 2
0 2 4
4 5 5
3 5 7
*/