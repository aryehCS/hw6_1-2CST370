/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw6_1.
 *     When you finish the development, download this file and submit to Canvas
 *     according to the submission instructions.
 *
 *     Please DO NOT change the name of the main procedure "main()"
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: Homework 6-1
 * Abstract: Program to collect max number of coins on an n x m board.
 * Name: Aryeh Freud
 * Date: 10/13/2024
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Your code should be here.
    // The following is just a sample statement and you need to replace it with your code
    int n;
    int m;
    cin >> n >> m; // read in dimensions of the grid

    // input the board
    vector<vector<int>> coinBoard(n, vector<int>(m)); // vector to store the board
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> coinBoard[i][j]; // fill the board
        }
    }

    // vector for storing max coins collected up to each cell
    vector<vector<int>> coinCount(n, vector<int>(m)); 

    // init the starting point
    coinCount[0][0] = coinBoard[0][0];

    // fills the first row - only moves right
    for(int j = 1; j < m; j++){
        coinCount[0][j] = coinCount[0][j - 1] + coinBoard[0][j];
    }

    // fills the first column - only moves down
    for(int i = 1; i < n; i++){
        coinCount[i][0] = coinCount[i - 1][0] + coinBoard[i][0];
    }

    // fill the rest of the table by choosing the max coins from the left or top
    for(int i = 1; i < n; i++){ // loop through each row starting at second row
        for(int j = 1; j < m; j++){ // loop through each column starting at second one
            // the max coins collectable at that cell
            coinCount[i][j] = max(coinCount[i - 1][j], coinCount[i][j - 1]) + coinBoard[i][j]; 
        }
    }

    // output max number of coins collected
    cout << "Max coins:" << coinCount[n - 1][m - 1] << endl;

    // backtrack to find the path
    vector<pair<int, int>> path;
    int i = n - 1; // start at last row
    int j = m - 1; // start at last column
    while(i > 0 || j > 0){ // backtrack until we reach top left corner
        path.push_back({i + 1, j + 1}); // add current position to path
        if(i == 0){ // if in first row, can only move left
            j--;
        } else if(j == 0){ // if in first column, can only move up
            i--;
        } else if(coinCount[i][j - 1] >= coinCount[i - 1][j]){ // if not in first row or column, choose the left or up (whichever is larger)
            j--; // move left
        } else{
            i--; // move up
        }
    }

    path.push_back({1, 1}); // add the starting point to the path

    // output the path from start to end
    cout << "Path:";
    for(int k = path.size() - 1; k >= 0; k--){ // reverse the path
        cout << "(" << path[k].first << "," << path[k].second << ")";
        if(k != 0){
            cout << "->";
        }
    }
    cout << endl;

    return 0;
}

