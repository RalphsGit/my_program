#include <iostream>
#include <vector>
#include<string>
#include <sstream>
using namespace std;

void parse_to_array(string input, int arr[3]) {
    istringstream iss(input);
    for (int i = 0; i < 3; i++) {
        iss >> arr[i];
    }
}

void matrix_multiplication (int matrix_1[3][3], int matrix_2[3][3], int result[3][3]) {
    
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            int sum = 0;
            for(int a = 0; a<3; a++) {
                sum += matrix_1[i][a] * matrix_2[a][j];
            }
            result[i][j] = sum;
        }
    }
}

int main() {
    // Write C++ code here
    std::cout << "Welcome. Enter your lines separated by space, when the line is over click enter." << endl << endl;
    
    while(true) {
    
    int matrix_1 [3][3];
    int matrix_2 [3][3];
    
    cout << "Enter Matrix 1: " << endl;

    for(int i = 0; i<3; i++) {
        cout << "Line "<< to_string(i+1) <<": ";
        int arr[3];
        string line;
        getline(cin, line);
        parse_to_array(line, matrix_1[i]);
    }
    
    cout << endl;
    
    cout << "Enter Matrix 2: " << endl;

    for(int i = 0; i<3; i++) {
        cout << "Line "<< to_string(i+1) <<": ";
        int arr[3];
        string line;
        getline(cin, line);
        parse_to_array(line, matrix_2[i]);
    }
    
    cout << endl << "Thank you. The result of the multiplication of matrix 1 with matrix 2 is: " << endl << endl;
    
    
    
    // 1 2 3
    // 3 2 1
    // 9 8 9
    
    // int matrix_1[3][3]= {{1,2,3},  
    //                     {3,2,1},
    //                     {9,8,9}};
                        
    // 1 2 1
    // 2 1 2
    // 3 0 3
                        
    // int matrix_2[3][3] = {{1,2,1},
    //                     {2,1,2},
    //                     {3,0,3}};
                        
    int result [3][3];
                        
    matrix_multiplication(matrix_1, matrix_2, result);
    
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
}

    return 0;
}

