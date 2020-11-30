#include<iostream>
#include<string>
using namespace std;

bool codingNinja(char **matrix, int r, int c,int srow, int scol, bool**visited, string str){ 
    if(str.length() == 0) {
        return false;
    }
    if(srow < 0 || srow >= r || scol < 0 || scol >= c) {
        return false;
    }
    if(visited[srow][scol]){ // if visited return false
        return false;
    }

    if(matrix[srow][scol] == str[0] && visited[srow][scol] == false) {
        visited[srow][scol] = true;
        if(str.length() == 1){
            return true;
        }

        // visualization
        for(int s = 0; s < r; s++) {
            for(int t = 0; t < c; t++) {
                cout << visited[s][t] <<" ";
            }
            cout<<endl;
        }
        cout << endl;

        for(int k = -1; k < 2; k++) {
            for(int l = -1; l < 2; l++) {
                if(codingNinja(matrix, r, c, srow+k, scol+l, visited, str.substr(1))){
                    return true;
                }
            }
        }
    }
    visited[srow][scol] = false;
    return false;
}

bool codingNinja(char **matrix, int r, int c, string str){

    bool **visited = new bool*[r];
    for(int k = 0; k < r; k++) {
        visited[k] = new bool[c];
        for(int l = 0; l < c; l++) {
            visited[k][l] = false;
        }
    }

    int attempt = 0;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {

            cout << "attempt " << ++attempt << endl;

            // visualization
            cout << "fresh \n";
            for(int s = 0; s < r; s++) {
                for(int t = 0; t < c; t++) {
                    cout << visited[s][t] << " ";
                }
                cout<<endl;
            }
            cout << endl;

            if(matrix[i][j] == str[0]) {
                visited[i][j] = true;

                // visualization
                cout << "inside \n";
                for(int s = 0; s < r; s++) {
                    for(int t = 0; t < c; t++) {
                        cout << visited[s][t] << " ";
                    }
                    cout<<endl;
                }
                cout << endl;
    

                for(int k = -1; k < 2; k++) {
                    for(int l = -1; l < 2; l++) {
                        if(codingNinja(matrix, r, c, i+k, j+l, visited, str.substr(1))){
                            return true;
                        }
                    }
                }

                visited[i][j] = false;
            }
        }
    }
    return false;
}

int main() {
    int r, c;
    cin >> r >> c;

    char **matrix = new char*[r];
    for(int i = 0; i < r; i++){
        matrix[i] = new char[c];
        for(int j = 0; j < c; j++) {
            cin >> matrix[i][j]; // enter data row wise
        }
    }

    if(codingNinja(matrix, r, c, "CODINGNINJA")){
        cout << "true";
    } 
    else  {
        cout << "false";
    }
}