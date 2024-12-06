/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw6_2.
 *     When you finish the development, download this file and submit to Canvas
 *     according to the submission instructions.
 *
 *     Please DO NOT change the name of the main procecure "main()"
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: Homework 6-2
 * Abstract: A program that displays all-pairs shortest paths using the Floyd Warshall's algorithm
 * Name: Aryeh Freud
 * Date: 10/14/2024
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Your code should be here.
    // The following is just a sample statement and you need to replace it with your code
    int n;
    cin >> n; // input for the number of vertices in the graph

    // input adj matrix for graph
    vector<vector<int>> distMatrix(n, vector<int>(n));
    for(int i = 0; i < n; i++){ // loop through each vertex in row
        for(int j = 0; j < n; j++){ // loop through each vertex in colum
            cin >> distMatrix[i][j];
        }
    }

    // floyd warshall algorithm
    for(int k = 0; k < n; k++){ // k is the intermediate vertex
        for(int i = 0; i < n; i++){ // the source vertex
            for(int j = 0; j < n; j++){ // destination vertex
                if(distMatrix[i][k] != -1 && distMatrix[k][j] != -1){ // check if valid path from i to k and k to j
                    if(distMatrix[i][j] == -1 || distMatrix[i][k] + distMatrix[k][j] < distMatrix[i][j]){
                        distMatrix[i][j] = distMatrix[i][k] + distMatrix[k][j]; // update shortest path
                    }
                }
            }
        }
    }

    // output shortest distance matrix
    for(int i = 0; i < n; i++){ // loops through each row
        for(int j = 0; j < n; j++){ // loops through each column
            if(distMatrix[i][j] == -1){
                cout << "-1"; // if no path exists
            }else {
                cout << distMatrix[i][j]; // shortest distance
            }
            if(j < n - 1){
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

