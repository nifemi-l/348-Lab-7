#include <iostream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix
{
private:
    int data[SIZE][SIZE]; // 2D array for matrix data (using int for simplicity)

public:
    // 1. Read values from stdin into a matrix
    void readFromStdin() { 
        // prompt user
        std::cout << "Enter the matrix: ";

        // loop through SIZE times, assigning values to each position
        for (int i = 0; i < SIZE; i++) { 
            for (int j = 0; j < SIZE; j++) { 
                // print the position, adjust for user ease
                std::cout << "(" << i + 1 << "," << j + 1 << "):" << endl;

                // write value to position
                std::cin >> data[i][j];
            }
        }
    };

    // 2. Display a matrix
    // set func to const to cause compiler error in case of attempted data member manipulation
    void display() const { 
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) { 
                std::cout << data[i][j] << " ";
                
                if (j == 3) { 
                    std::cout << endl;
                }
            }

            if (i == 3) { 
                std::cout << endl;
            }
        }
    };

    // 3. Add two matrices (operator overloading for +)
    Matrix operator+(const Matrix &other) const { 
        Matrix result; 

        for (int i = 0; i < SIZE; i++) { 
            for (int j = 0; j < SIZE; j++) { 
                result.data[i][j] = data[i][j] + other.data[i][j]; 
            }
        }
        
        return result;
    };

    // 4. Multiply two matrices (operator overloading for *)
    Matrix operator*(const Matrix &other) const {
        Matrix result; 

        for (int i = 0; i < SIZE; i++) { 
            for (int j = 0; j < SIZE; j++) { 
                // 0 init for later increment
                result.data[i][j] = 0; 

                for (int k = 0; k < SIZE; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    };

    // 5. Compute the sum of matrix diagonal elements
    int sumOfDiagonals() const { 
        int sum = 0; 

        for (int i = 0; i < SIZE; i++) { 
            for (int j = 0; j < SIZE; j++) { 
                if (i == j) { 
                    sum += data[i][j];
                }
            }
        }

        return sum;
    };

    // 6. Swap matrix rows
    void swapRows(int row1, int row2) { 
        int store[SIZE];

        // store the value of row1
        for (int i = 0; i < SIZE; i++) { 
            store[i] = data[row1][i];
        }

        // set row1 equal to row2
        for (int i = 0; i < SIZE; i++) { 
            data[row1][i] = data[row2][i];
        }

        // set row2 equal to row1
        for (int i = 0; i < SIZE; i++) { 
            data[row2][i] = store[i];
        }
    };
};

int main()
{
    // Example usage:
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
    cout << "Matrix 1:" << endl;
    mat1.display();
    
    Matrix mat2;
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
    cout << "Matrix 2:" << endl;
    mat2.display();
    
    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;
    
    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();

    return 0;
}