#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iomanip>

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

//create an empty matrix with dimensions NxN
Matrix::Matrix(size_t N) {
    //save our N value
    size = N;
    //resize our matrix with respect to our N value
    matrix.resize(N, std::vector<int>(size, 0));
}

//create matrix based on our input
Matrix::Matrix(std::vector<std::vector<int>> nums) {
    //save size
    size = nums.size();
    //save the values (nums) inside the matrix
    matrix = nums;
} 

//declare overloaded operation that will add and return our two matrices
Matrix Matrix::operator+(const Matrix &rhs) const {
    Matrix sum = Matrix(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        }
    }
    return sum;
}

//declare overloaded operation that will multiply and return our two matrices
Matrix Matrix::operator*(const Matrix &rhs) const {
    Matrix product = Matrix(size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
           for (int k = 0; k < size; k++) {
                product.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
           }
        }
    }
    return product;
}

//declare operation that will save a value inside our matrix
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    //if our input is out of range, throw an error
    if (i >= size || j >= size) {
        //error message
        throw std::out_of_range("Index out of range");
    }
    matrix[i][j] = n;
}

//declare operation that will return a value from our matrix
int Matrix::get_value(std::size_t i, std::size_t j) const {
    //if our input is out of range, throw an error
    if (i >= size || j >= size) {
        //error message
        throw std::out_of_range("Index out of range");
    }
    return matrix[i][j];
}

//declare a simple operation that returns the size of our matrix
int Matrix::get_size() const {
    return size;
}

//declare operation that adds and returns the sum of the top left and bottom right diagonal elements of a matrix
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

//declare operation that adds and returns the sum of the top right and bottom left elements of a matrix
int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i][size - 1 - i];
    }
    return sum;
}

//declare operation that will swap rows of our matrix
void Matrix::swap_rows(std::size_t row1, std::size_t row2) {
    //ensure the provided rows are in range, throwing an error if not
    if (row1 >= size || row2 >= size) {
        //error message
        throw std::out_of_range("Index out of range");
    }
    //swap our rows
    std::swap(matrix[row1], matrix[row2]);
}

//declare operation that will swap columns of our matrix
void Matrix::swap_cols(std::size_t col1, std::size_t col2) {
    //ensure the provided columns are in range, throwing an error if not
    if (col1 >= size || col2 >= size) {
        //error message
        throw std::out_of_range("Index out of range");
    }
    //create a loop for parsing through our matrix in order to find the correct columns
    for (int i = 0; i < size; i++) {
        //swap our columns
        std::swap(matrix[i][col1], matrix[i][col2]);
    }
}

//declare operation that will print the matrices
void Matrix::print_matrix() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            //start printing matrix elements to the terminal
            std::cout << std::setw(4) << matrix[i][j] << " ";
        }
        //print to the terminal
        std::cout << std::endl;
    }
    //print to the terminal
    std::cout << std::endl;
}