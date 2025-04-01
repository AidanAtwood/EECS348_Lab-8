#include "matrix.hpp"
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include <iostream>

using namespace std;

Matrix::Matrix(size_t N) : size(N), data(N, vector<int>(N, 0)) {}

Matrix::Matrix(const vector<vector<int>>& nums) {
    if (nums.empty() || nums.size() != nums[0].size()) {
        throw invalid_argument("Matrix must be a perfect square (ex. 4x4)");
    }
    size = nums.size();
    data = nums;
}

Matrix Matrix::read_file(const string& filename, size_t matrix_nums) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file");
    }

    size_t N;
    file >> N;

    for (size_t m = 0; m < matrix_nums; ++m) {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < N; ++j) {
                int dummy;
                file >> dummy;
            }
        }
    }

    vector<vector<int>> matrix_data(N, vector<int>(N));
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            if (!(file >> matrix_data[i][j])) {
                throw runtime_error("Invalid data in matrix");
            }
        }
    }

    return Matrix(matrix_data);
}

void Matrix::set_value(int row, int col, int value) {
    if (row < 0 || row >= get_size() || col < 0 || col >= get_size())
        throw out_of_range("Index is out of range")
    data[row][col] = value;
}

int Matrix::get_value(size_t row, size_t col, int value) {
    if (row >= size || col >= size) {
        throw out_of_range("Index is out of range");
    }
    return data[row][col];
}

size_t Matrix::get_size() const {
    return size;
}

int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += data[i][i];
    }
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += data[i][size - 1 - i];
    }
    return sum;
}

void Matrix::swap_rows(size_t r1, size_t r2) {
    if (r1 >= size || r2 >= size) {
        throw out_of_range("Row(s) out of range");
    }
    swap(data[r1], data[r2]);
}

void Matrix::swap_cols(size_t c1, size_t c2) {
    if (c1 >= size || c2 >= size) {
        throw out_of_range("Column(s) out of range");
    }
    for (size_t i = 0; i < size; ++i) {
        swap(data[i][c1], data[i][c2]);
    }
}

void Matrix::print_matrix() const {
    for (const auto& row : data) {
        for (int val : row) {
            cout << setw(4) << val;
        }
        cout << '\n'
    }
}

Matrix Matrix::operator+(const Matrix& rhs) const {
    if (size != rhs.size) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }

    Matrix result(size);
    for (std::size_t a = 0; a < size; ++a) {
        for (std::size_t b = 0; b < size; ++b) {
            result.data[a][b] = data[a][b] + rhs.data[a][b];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& rhs) const {
    if (size != rhs.size) {
        throw std::invalid_argument("Matrix dimensions must match for multiplication");
    }

    Matrix result(size);
    for (std::size_t a = 0; a < size; ++a) {
        for (std::size_t b = 0; b < size; ++b) {
            result.data[i][j] = 0;
            for (std::size_t c = 0; c < size; ++c) {
                result.data[a][b] += data[a][c] * rhs.data[c][b];
            }
        }
    }
    return result;
}

void 