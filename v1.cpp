#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Define the colors
const char RED = 'R';
const char BLUE = 'B';
const char GREEN = 'G';
const char YELLOW = 'Y';
const char ORANGE = 'O';
const char WHITE = 'W';

// Define the Rubik's Cube as a 6x3x3 vector of characters
vector<vector<vector<char>>> rubiksCube(6, vector<vector<char>>(3, vector<char>(3)));

// Helper function to get the color of a face
char getFaceColor(int face) {
    switch (face) {
        case 0: return GREEN;
        case 1: return YELLOW;
        case 2: return RED;
        case 3: return WHITE;
        case 4: return ORANGE;
        case 5: return BLUE;
        default: return ' ';
    }
}

// Initialize the Rubik's Cube with colors
void initializeCube() {
    for (int face = 0; face < 6; ++face) {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                rubiksCube[face][row][col] = getFaceColor(face);
            }
        }
    }
}

// Function to print the Rubik's Cube
void printCube() {
    for (int face = 0; face < 6; ++face) {
        cout << "Face " << face << ":\n";
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                cout << rubiksCube[face][row][col] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}

// Function to perform a move on the Rubik's Cube
void performMove(char move) {

    vector<vector<char>> tempFace(3, vector<char>(3));

    if (move == 'R') {  // R move


        vector<vector<char>> transposedFace(3, vector<char>(3));
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) transposedFace[row][col] = rubiksCube[2][row][col];
        }
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) rubiksCube[2][col][2-row] = transposedFace[row][col];
        }


        vector<char> face0, face1, face3, face5;

        for (int i = 0; i < 3; i++) {
            face0.push_back(rubiksCube[0][i][2]);
            face1.push_back(rubiksCube[1][i][2]);
            face3.push_back(rubiksCube[3][i][0]);
            face5.push_back(rubiksCube[5][i][2]);
        }

        reverse(face3.begin(), face3.end());
        reverse(face0.begin(), face0.end());
        for (int i = 0; i < 3; i++) {
            rubiksCube[0][i][2] = face1[i];
            rubiksCube[1][i][2] = face5[i];
            rubiksCube[3][i][0] = face0[i];
            rubiksCube[5][i][2] = face3[i];
        }
        // there is a transpose of face 2  (first row is last col, last row is first col,..)
        
    }
    else if (move == 'r') {  // R prime move
        vector<char> face0, face1, face3, face5;


        vector<vector<char>> transposedFace(3, vector<char>(3));
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) transposedFace[row][col] = rubiksCube[2][row][2-col];
        }
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) rubiksCube[2][col][row] = transposedFace[row][col];
        }


        for (int i = 0; i < 3; i++) {
            face0.push_back(rubiksCube[0][i][2]);
            face1.push_back(rubiksCube[1][i][2]);
            face3.push_back(rubiksCube[3][i][0]);
            face5.push_back(rubiksCube[5][i][2]);
        }
        reverse(face3.begin(), face3.end());
        reverse(face5.begin(), face5.end());
        for (int i = 0; i < 3; i++) {
            rubiksCube[0][i][2] = face3[i];
            rubiksCube[1][i][2] = face0[i];
            rubiksCube[3][i][0] = face5[i];
            rubiksCube[5][i][2] = face1[i];
        }
    }
    else if (move == 'U') {  // U move

        vector<vector<char>> transposedFace(3, vector<char>(3));
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) transposedFace[row][col] = rubiksCube[0][row][col];
        }
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) rubiksCube[0][col][2-row] = transposedFace[row][col];
        }

        vector<char> face1, face2, face3, face4;

        for (int i = 0; i < 3; i++) {
            face1.push_back(rubiksCube[1][0][i]);
            face2.push_back(rubiksCube[2][0][i]);
            face3.push_back(rubiksCube[3][0][i]);
            face4.push_back(rubiksCube[4][0][i]);
        }
        for (int i = 0; i < 3; i++) {
            rubiksCube[1][0][i] = face2[i];
            rubiksCube[2][0][i] = face3[i];
            rubiksCube[3][0][i] = face4[i];
            rubiksCube[4][0][i] = face1[i];
        }
    }
    else if (move == 'u') {  // U prime move
        vector<char> face1, face2, face3, face4;


        vector<vector<char>> transposedFace(3, vector<char>(3));
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) transposedFace[row][col] = rubiksCube[0][row][2-col];
        }
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) rubiksCube[0][col][row] = transposedFace[row][col];
        }

        for (int i = 0; i < 3; i++) {
            face1.push_back(rubiksCube[1][0][i]);
            face2.push_back(rubiksCube[2][0][i]);
            face3.push_back(rubiksCube[3][0][i]);
            face4.push_back(rubiksCube[4][0][i]);
        }
        for (int i = 0; i < 3; i++) {
            rubiksCube[1][0][i] = face4[i];
            rubiksCube[2][0][i] = face1[i];
            rubiksCube[3][0][i] = face2[i];
            rubiksCube[4][0][i] = face3[i];
        }
        
    }
    else if (move == 'D') {  // D move
        vector<char> face1, face2, face3, face4;


        vector<vector<char>> transposedFace(3, vector<char>(3));
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) transposedFace[row][col] = rubiksCube[5][row][col];
        }
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) rubiksCube[5][col][2-row] = transposedFace[row][col];
        }


        for (int i = 0; i < 3; i++) {
            face1.push_back(rubiksCube[1][2][i]);
            face2.push_back(rubiksCube[2][2][i]);
            face3.push_back(rubiksCube[3][2][i]);
            face4.push_back(rubiksCube[4][2][i]);
        }
        for (int i = 0; i < 3; i++) {
            rubiksCube[1][0][i] = face4[i];
            rubiksCube[2][0][i] = face1[i];
            rubiksCube[3][0][i] = face2[i];
            rubiksCube[4][0][i] = face3[i];
        }
    }
    else if (move == 'd') {  
        vector<char> face1, face2, face3, face4;

        vector<vector<char>> transposedFace(3, vector<char>(3));
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) transposedFace[row][col] = rubiksCube[5][row][2-col];
        }
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) rubiksCube[5][col][row] = transposedFace[row][col];
        }

        for (int i = 0; i < 3; i++) {
            face1.push_back(rubiksCube[1][2][i]);
            face2.push_back(rubiksCube[2][2][i]);
            face3.push_back(rubiksCube[3][2][i]);
            face4.push_back(rubiksCube[4][2][i]);
        }
        for (int i = 0; i < 3; i++) {
            rubiksCube[1][0][i] = face2[i];
            rubiksCube[2][0][i] = face3[i];
            rubiksCube[3][0][i] = face4[i];
            rubiksCube[4][0][i] = face1[i];
        }
    }
    else if (move == 'F') {  
        vector<char> face0, face5, face2, face4;


        vector<vector<char>> transposedFace(3, vector<char>(3));
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) transposedFace[row][col] = rubiksCube[1][row][col];
        }
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) rubiksCube[1][col][2-row] = transposedFace[row][col];
        }

        for (int i = 0; i < 3; i++) {
            face0.push_back(rubiksCube[0][2][i]);
            face5.push_back(rubiksCube[5][0][i]);
            face2.push_back(rubiksCube[2][i][0]);
            face4.push_back(rubiksCube[4][i][2]);
        }
        reverse(face4.begin(), face4.end());
        reverse(face2.begin(), face2.end());

        for (int i = 0; i < 3; i++) {
            rubiksCube[0][2][i] = face4[i];
            rubiksCube[2][i][0] = face0[i];
            rubiksCube[5][0][i] = face2[i];
            rubiksCube[4][i][2] = face5[i];
        }
    }

    else if (move == 'f') {  
        vector<char> face0, face5, face2, face4;

        vector<vector<char>> transposedFace(3, vector<char>(3));
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) transposedFace[row][col] = rubiksCube[1][row][2-col];
        }
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) rubiksCube[1][col][row] = transposedFace[row][col];
        }
        for (int i = 0; i < 3; i++) {
            face0.push_back(rubiksCube[0][2][i]);
            face5.push_back(rubiksCube[5][0][i]);
            face2.push_back(rubiksCube[2][i][0]);
            face4.push_back(rubiksCube[4][i][2]);
        }
        reverse(face5.begin(), face5.end());
        reverse(face0.begin(), face0.end());

        for (int i = 0; i < 3; i++) {
            rubiksCube[0][2][i] = face2[i];
            rubiksCube[2][i][0] = face5[i];
            rubiksCube[5][0][i] = face4[i];
            rubiksCube[4][i][2] = face0[i];
        }
    }
    else if (move == 'B') {  
        vector<char> face0, face5, face2, face4;


        vector<vector<char>> transposedFace(3, vector<char>(3));
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) transposedFace[row][col] = rubiksCube[3][row][col];
        }
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) rubiksCube[3][col][2-row] = transposedFace[row][col];
        }

        for (int i = 0; i < 3; i++) {
            face0.push_back(rubiksCube[0][0][i]);
            face5.push_back(rubiksCube[5][2][i]);
            face2.push_back(rubiksCube[2][i][2]);
            face4.push_back(rubiksCube[4][i][0]);
        }
        reverse(face5.begin(), face5.end());
        reverse(face0.begin(), face0.end());

        for (int i = 0; i < 3; i++) {
            rubiksCube[0][0][i] = face2[i];
            rubiksCube[2][i][2] = face5[i];
            rubiksCube[5][2][i] = face4[i];
            rubiksCube[4][i][0] = face0[i];
        }
    }

    else if (move == 'b') {  // D prime move
        vector<char> face0, face5, face2, face4;

         vector<vector<char>> transposedFace(3, vector<char>(3));
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) transposedFace[row][col] = rubiksCube[3][row][2-col];
        }
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) rubiksCube[3][col][row] = transposedFace[row][col];
        }
        for (int i = 0; i < 3; i++) {
            face0.push_back(rubiksCube[0][0][i]);
            face5.push_back(rubiksCube[5][2][i]);
            face2.push_back(rubiksCube[2][i][2]);
            face4.push_back(rubiksCube[4][i][0]);
        }
        reverse(face4.begin(), face4.end());
        reverse(face2.begin(), face2.end());

        for (int i = 0; i < 3; i++) {
            rubiksCube[0][0][i] = face4[i];
            rubiksCube[2][i][2] = face0[i];
            rubiksCube[5][2][i] = face2[i];
            rubiksCube[4][i][0] = face5[i];
        }
    }
}
int main() {
    //initializeCube();
    //cout << "Initial Rubik's Cube:\n";
    string input="boobgobgowwygyrywygwgyrrrrrwywgwbgbbrooroyoorgbbgbwyyw";
    int index=0;
    for (int face = 0; face < 6; ++face) {
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                rubiksCube[face][row][col] = input[index++];
            }
        }
    }
    printCube();

    string moves="URbBrUuFUfrRbBbRU";
    index=0;
    while(index<moves.size()){
        performMove(moves[index++]);
    }
    printCube();
    return 0;
}