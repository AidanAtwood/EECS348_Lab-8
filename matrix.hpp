#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>

class Matrix {

private:
    int size;
    std::vector<std::vector<int>> matrix;

public:
    Matrix(std::size_t N);
    Matrix(std::vector<std::vector<int>> nums);

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(std::size_t i, std::size_t j, int n);
    int get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;
    void swap_rows(std::size_t row1, std::size_t row2);
    void swap_cols(std::size_t col1, std::size_t col2);
    void print_matrix() const;
};

#endif // __MATRIX_HPP__