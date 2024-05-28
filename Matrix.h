#ifndef MATRIXES_MATRIX_H
#define MATRIXES_MATRIX_H

#include <vector>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<double>> matrix;
    int rows;
    int cols;
public:
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, double value);
    Matrix(const std::vector<std::vector<double>> &matrix);
    Matrix(const Matrix &matrix);
    Matrix(Matrix &&matrix) noexcept;
    ~Matrix();

    Matrix &operator=(const Matrix &matrix);
    Matrix &operator=(Matrix &&matrix) noexcept;

    Matrix operator+(const Matrix &matrix) const;
    Matrix operator-(const Matrix &matrix) const;
    Matrix operator*(const Matrix &matrix) const;
    Matrix operator*(double value) const;
    Matrix operator/(double value) const;

    Matrix &operator+=(const Matrix &matrix);
    Matrix &operator-=(const Matrix &matrix);
    Matrix &operator*=(const Matrix &matrix);
    Matrix &operator*=(double value);
    Matrix &operator/=(double value);

    std::vector<double> &operator[](int index);
    const double &operator()(int row, int col) const;

    Matrix transpose() const;
    Matrix inverse() const;
    double determinant() const;
    int rank() const;

    int getRows() const;
    int getCols() const;

    void setRows(int rows);
    void setCols(int cols);

    void resize(int rows, int cols);
    void clear();

    bool operator==(const Matrix &matrix) const;
    bool operator!=(const Matrix &matrix) const;

    friend std::ostream &operator<<(std::ostream &os, Matrix &matrix);
    friend std::istream &operator>>(std::istream &is, Matrix &matrix);
};

#endif //MATRIXES_MATRIX_H