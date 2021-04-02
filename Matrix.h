//
// Created by ummagumm_a on 02.03.2021.
//

#ifndef AGLA_II_MATRIX_H
#define AGLA_II_MATRIX_H

#include <string>
#include <iostream>
#include <exception>
#include <vector>

class Matrix
{
private:
    class DimensionalProblemException : public std::exception
    {
        [[nodiscard]] const char* what() const noexcept override
        {
            return "Error: the dimensional problem occurred";
        }
    };
public:
    // Constructor for Matrix which sets its dimensions
    Matrix(int rows, int columns);
    // Copy constructor
    Matrix(Matrix& rhs);

    // Copy assignment operator
    Matrix& operator=(const Matrix& rhs);
    // Matrix addition
    friend Matrix& operator+(const Matrix& lhs, const Matrix& rhs);
    Matrix& operator+=(const Matrix& rhs);
    // Matrix subtraction
    friend Matrix& operator-(const Matrix& lhs, const Matrix& rhs);
    Matrix& operator-=(const Matrix& rhs);
    // Matrix multiplication
    friend Matrix& operator*(const Matrix& lhs, const Matrix& rhs);
    Matrix& operator*=(const Matrix& rhs);

    // Operators for writing to matrix from standard input
    friend std::istream& operator>>(std::istream& in, Matrix& rhs);
    // Operators for outputting matrix to standard output
    friend std::ostream& operator<<(std::ostream& out, const Matrix& rhs);

    // Transpose matrix
    [[nodiscard]] Matrix transposed() const;

public:
    // Getters
    [[nodiscard]] int getNColumns() const;
    [[nodiscard]] int getNRows() const;
    [[nodiscard]] const std::vector<std::vector<int>> &getContents() const;
    // Get particular element
    [[nodiscard]] int getElementAt(int row, int column) const;

    // Set particular element
    void setElementAt(int row, int column, int value);
private:
    // Matrix's dimensions
    int nColumns;
    int nRows;
    // Elements of a matrix
    std::vector<std::vector<int>> contents;
};



#endif //AGLA_II_MATRIX_H
