#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        matrix[i].resize(cols);
    }
}

Matrix::Matrix(int rows, int cols, double value) : rows(rows), cols(cols) {
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        matrix[i].resize(cols, value);
    }
}

Matrix::Matrix(const std::vector<std::vector<double>> &matrix) : matrix(matrix) {
    rows = matrix.size();
    cols = matrix[0].size();
}

Matrix::Matrix(const Matrix &matrix) : rows(matrix.rows), cols(matrix.cols), matrix(matrix.matrix) {}

Matrix::Matrix(Matrix &&matrix) noexcept : rows(matrix.rows), cols(matrix.cols), matrix(std::move(matrix.matrix)) {
    matrix.rows = 0;
    matrix.cols = 0;
}

Matrix::~Matrix() {
    matrix.clear();
    rows = 0;
    cols = 0;
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    if (this == &matrix) {
        return *this;
    }
    this->matrix = matrix.matrix;
    rows = matrix.rows;
    cols = matrix.cols;
    return *this;
}

Matrix &Matrix::operator=(Matrix &&matrix) noexcept {
    if (this == &matrix) {
        return *this;
    }
    this->matrix = std::move(matrix.matrix);
    rows = matrix.rows;
    cols = matrix.cols;
    matrix.rows = 0;
    matrix.cols = 0;
    return *this;
}

Matrix Matrix::operator+(const Matrix &matrix) const {
    if (rows != matrix.rows || cols != matrix.cols) {
        throw std::invalid_argument("Matrix sizes are not equal");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrix[i][j] = this->matrix[i][j] + matrix.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &matrix) const {
    if (rows != matrix.rows || cols != matrix.cols) {
        throw std::invalid_argument("Matrix sizes are not equal");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrix[i][j] = this->matrix[i][j] - matrix.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &matrix) const {
    if (cols != matrix.rows) {
        throw std::invalid_argument("Matrix sizes are not equal");
    }
    Matrix result(rows, matrix.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            for (int k = 0; k < cols; k++) {
                result.matrix[i][j] += this->matrix[i][k] * matrix.matrix[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(double value) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrix[i][j] = this->matrix[i][j] * value;
        }
    }
    return result;
}

Matrix Matrix::operator/(double value) const {
    if (value == 0) {
        throw std::invalid_argument("Division by zero");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrix[i][j] = this->matrix[i][j] / value;
        }
    }
    return result;
}

Matrix& Matrix::operator+=(const Matrix &matrix) {
    if (rows != matrix.rows || cols != matrix.cols) {
        throw std::invalid_argument("Matrix sizes are not equal");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->matrix[i][j] += matrix.matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix &matrix) {
    if (rows != matrix.rows || cols != matrix.cols) {
        throw std::invalid_argument("Matrix sizes are not equal");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->matrix[i][j] -= matrix.matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix &matrix) {
    if (cols != matrix.rows) {
        throw std::invalid_argument("Matrix sizes are not equal");
    }
    Matrix result(rows, matrix.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            for (int k = 0; k < cols; k++) {
                result.matrix[i][j] += this->matrix[i][k] * matrix.matrix[k][j];
            }
        }
    }
    *this = result;
    return *this;
}

Matrix& Matrix::operator*=(double value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->matrix[i][j] *= value;
        }
    }
    return *this;
}

Matrix& Matrix::operator/=(double value) {
    if (value == 0) {
        throw std::invalid_argument("Division by zero");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            this->matrix[i][j] /= value;
        }
    }
    return *this;
}

std::vector<double> &Matrix::operator[](int row) {
    if (row < 0 || row >= rows) {
        throw std::out_of_range("Index out of range");
    }
    return matrix[row];
}

const double &Matrix::operator()(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Index out of range");
    }
    return matrix[row][col];
}

Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            result.matrix[i][j] = matrix[j][i];
        }
    }
    return result;
}

Matrix Matrix::inverse() const {
    if (rows != cols) {
        throw std::invalid_argument("Matrix is not square");
    }
    int n = rows;
    Matrix result(n, n);
    std::vector<std::vector<double>> temp(n, std::vector<double>(2 * n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = matrix[i][j];
            temp[i][j + n] = (i == j) ? 1 : 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (temp[i][i] == 0) {
            int k = i + 1;
            while (k < n && temp[k][i] == 0) {
                k++;
            }
            if (k == n) {
                throw std::invalid_argument("Matrix is singular");
            }
            for (int j = 0; j < 2 * n; j++) {
                std::swap(temp[i][j], temp[k][j]);
            }
        }
        double div = temp[i][i];
        for (int j = 0; j < 2 * n; j++) {
            temp[i][j] /= div;
        }
        for (int j = 0; j < n; j++) {
            if (j != i) {
                double mult = temp[j][i];
                for (int k = 0; k < 2 * n; k++) {
                    temp[j][k] -= mult * temp[i][k];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result.matrix[i][j] = temp[i][j + n];
        }
    }
    return result;
}

double Matrix::determinant() const {
    if (rows != cols) {
        throw std::invalid_argument("Matrix is not square");
    }
    int n = rows;
    std::vector<std::vector<double>> temp(n, std::vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = matrix[i][j];
        }
    }
    double det = 1;
    for (int i = 0; i < n; i++) {
        if (temp[i][i] == 0) {
            int k = i + 1;
            while (k < n && temp[k][i] == 0) {
                k++;
            }
            if (k == n) {
                return 0;
            }
            for (int j = 0; j < n; j++) {
                std::swap(temp[i][j], temp[k][j]);
            }
            det = -det;
        }
        det *= temp[i][i];
        for (int j = i + 1; j < n; j++) {
            double mult = temp[j][i] / temp[i][i];
            for (int k = i; k < n; k++) {
                temp[j][k] -= mult * temp[i][k];
            }
        }
    }
    return det;
}

int Matrix::rank() const{
    int n = rows;
    int m = cols;
    std::vector<std::vector<double>> temp(n, std::vector<double>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = matrix[i][j];
        }
    }
    int rank = 0;
    for (int i = 0; i < m; i++) {
        int j = rank;
        while (j < n && temp[j][i] == 0) {
            j++;
        }
        if (j == n) {
            continue;
        }
        for (int k = 0; k < m; k++) {
            std::swap(temp[rank][k], temp[j][k]);
        }
        for (int k = 0; k < n; k++) {
            if (k != rank && temp[k][i] != 0) {
                double mult = temp[k][i] / temp[rank][i];
                for (int l = 0; l < m; l++) {
                    temp[k][l] -= mult * temp[rank][l];
                }
            }
        }
        rank++;
    }
    return rank;
}

int Matrix::getRows() const {
    return this->rows;
}

int Matrix::getCols() const {
    return this->cols;
}

void Matrix::setRows(int rows) {
    if (rows < 0) {
        throw std::invalid_argument("Number of rows must be greater than zero");
    }
    this->rows = rows;
    matrix.resize(rows);
}

void Matrix::setCols(int cols) {
    if (cols < 0) {
        throw std::invalid_argument("Number of columns must be greater than zero");
    }
    this->cols = cols;
    for (int i = 0; i < rows; i++) {
        matrix[i].resize(cols);
    }
}

void Matrix::resize(int rows, int cols) {
    if (rows < 0 || cols < 0) {
        throw std::invalid_argument("Number of rows and columns must be greater than zero");
    }
    this->rows = rows;
    this->cols = cols;
    matrix.resize(rows);
    for (int i = 0; i < rows; i++) {
        matrix[i].resize(cols);
    }
}

void Matrix::clear() {
    matrix.clear();
    rows = 0;
    cols = 0;
}

bool Matrix::operator==(const Matrix &matrix) const {
    if (rows != matrix.rows || cols != matrix.cols) {
        return false;
    }
    for (int i = 0; i < rows; i++) {
        if (this->matrix[i] != matrix.matrix[i]) {
            return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &matrix) const {
    return !(*this == matrix);
}

//оператор вывода данных в поток (чтобы можно было писать std::cout << matrix)
std::ostream &operator<<(std::ostream &out, Matrix &matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            out << matrix[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

//оператор ввода данных из потока (чтобы можно было писать std::cin >> matrix)
std::istream &operator>>(std::istream &in, Matrix &matrix) {
    int rows, cols;
    in >> rows >> cols;
    matrix.resize(rows, cols);
    std::string elem;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            in >> elem;
            matrix[i][j] = std::stod(elem);
        }
    }
    return in;
}