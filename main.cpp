#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>

//declare main function
int main(int argc, char *argv[]) 
{
    
    /* 1. Read values from a file into the matrix: */

    //prompt user for their input file
    std::string fileName;
    std::cout << "Type the name of your input file: ";
    std::cin >> fileName;
    std::ifstream file(fileName);

    //declare needed variable
    int N;
    file >> N;

    //create our two matrices
    Matrix A = Matrix(N);
    Matrix B = Matrix(N);

    //parse through matrix A values and save them
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a;
            file >> a;
            A.set_value(i, j, a);
        }
    }

    //parse through matrix B values and save them
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int b;
            file >> b;
            B.set_value(i, j, b);
        }
    }

    //close our input file
    file.close();

    //print matrix A to the screen
    std::cout << "Matrix A:" << std::endl;
    A.print_matrix();

    //print matrix B to the screen
    std::cout << "Matrix B:" << std::endl;
    B.print_matrix();

    /* 2. Add two matrices and display the result: */

    std::cout << "Matrix A + Matrix B:" << std::endl;
    //add our matrices together
    Matrix SUM = A + B;
    //print the sum to the screen
    SUM.print_matrix();

    /* 3. Multiply two matrices and display the result: */

    std::cout << "Matrix A * Matrix B:" << std::endl;
    //multiply our matrices together
    Matrix PRODUCT = A * B;
    //print the product to the screen
    PRODUCT.print_matrix();

    /* 4. Get the sum of matrix diagonal elements: */

    std::cout << "Sum of the top left and bottom right elements in matrix A:" << std::endl;
    //print the sum of major elements to the screen
    std::cout << A.sum_diagonal_major() << std::endl << std::endl;

    std::cout << "Sum of top right and bottom left elements in matrix A:" << std::endl;
    //print the sum of minor elements to the screen
    std::cout << A.sum_diagonal_minor() << std::endl << std::endl;

    /* 5. Swap matrix rows and display the result: */

    Matrix A_swapRow = Matrix(A);

    //declare elements needed for later operation
    int row1, row2;

    //prompt user for the rows that will be swapped
    std::cout << "Input 2 rows to swap (note: row index starts with zero):\nRow 1: ";
    //save the user's input
    std::cin >> row1;
    std::cout << "Row 2: ";
    //save the user's second input
    std::cin >> row2;

    //swap the two rows provided by the user
    A_swapRow.swap_rows(row1, row2);
    std::cout << "\nMatrix A with rows " << row1 << " and " << row2 << " swapped:" << std::endl;
    //print the swapped matrix to the screen
    A_swapRow.print_matrix();

    /* 6. Swap matrix columns and display the result: */

    Matrix A_swapCol = Matrix(A);

    //declare elements needed for later operation
    int col1, col2;

    //prompt user for the columns that will be swapped
    std::cout << "Input 2 columns to swap (note: column index starts with zero):\nColumn 1: ";
    //save the user's input
    std::cin >> col1;
    std::cout << "Column 2: ";
    //save the user's second input
    std::cin >> col2;

    //swap the columns
    A_swapCol.swap_cols(col1, col2);
    std::cout << "\nMatrix A with columns " << col1 << " and " << col2 << " swapped:" << std::endl;
    //print the swapped matrix to the screen
    A_swapCol.print_matrix();

    /* 7. Update matrix rows and display the result: */

    char matrix;

    //declare elements that will store our inputs
    int row_x, col_x, new_val;
    //begin prompting user for their inputs
    std::cout << "Input your matrix, row index, column index, and the value you want to insert:\nMatrix: ";
    //save the user's selected matrix
    std::cin >> matrix;
    std::cout << "Row Index: ";
    //save the user's selected row
    std::cin >> row_x;
    std::cout << "Column Index: ";
    //save the user's selected column
    std::cin >> col_x;
    std::cout << "New Value: ";
    //save the new value provided by the user
    std::cin >> new_val;
    //check if the user chose matrix A
    if (matrix == 'A' || matrix == 'a') {
        //replace the value
        A.set_value(row_x, col_x, new_val);
        std::cout << "\nUpdated matrix A:" << std::endl;
        //print updated matrix to the screen
        A.print_matrix();
    }
    //check if the user chose matrix B
    else if (matrix == 'B' || matrix == 'b') {
        //replace the value
        B.set_value(row_x, col_x, new_val);
        std::cout << "\nUpdated Matrix B:" << std::endl;
        //print the updated matrix to the screen
        B.print_matrix();
    }
    //if the user provided any other value for their selected matrix, throw an error
    else {
        std::cout << "ERROR: Invalid matrix";
    }

    //return zero
    return 0;
}