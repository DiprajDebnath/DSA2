 #include<iostream>
 #include<algorithm>
 using namespace std;

class Edge {
    int sour; // Source
    int dest; // Destination
    int weight; // Edge weight

    public:
    Edge() {

    }

    Edge(int source, int destination, int weight) {
        this->sour = source;
        this->dest = destination;
        this->weight = weight;
    }

    void print() {
        cout << this->sour << " " << this->dest << " " << this->weight << endl;
    }

    int getWeight() {
        return this->weight;
    }
    int getSource() {
        return this->sour;
    }
    int getDestination() {
        return this->dest;
    }
};

bool compare(Edge* e1, Edge* e2)
{
    return (e1->getWeight() < e2->getWeight());
}

int main() {
    int n, e; // Number of vertices and edges
    cin >> n >> e;

    // Parent array for union find algo to detect cycle
    int *parent = new int[n];
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Input and output arrays
    Edge **input = new Edge*[e];
    Edge **output = new Edge*[n-1];

    for(int i = 0; i < e; i++){
        int v1, v2, ed;
        cin >> v1 >> v2 >> ed;
        input[i] = new Edge(v1,v2,ed);
    }

    // Sorting input array
    sort(input, input+e, compare);

    // while loop
    int k = 0;
    int count = 0;
    while(count < n-1) {
        Edge *edg = input[k];
        int v1 = edg->getSource();
        int v2 = edg->getDestination();
        int pv1 = v1, pv2 = v2;

        while(parent[pv1] != pv1){
            pv1 = parent[pv1];
        }
        while(parent[pv2] != pv2){
            pv2 = parent[pv2];
        }

        if(pv1 != pv2){
            output[count] = new Edge(v1, v2, edg->getWeight());
            count++;
            parent[v2] = v1;
        }

        k++;
    }

    // print MST array
    for(int i = 0; i < e; i++){
        output[i]->print();
    }

    // Delete input array
    for(int i = 0; i < e; i++) {
        delete input[i];
    }
    delete []input;

    // Delete output array
    delete []output;

    // Delete parent array
    delete []parent;
}