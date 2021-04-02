//
// Created by ummagumm_a on 02.03.2021.
//

#ifndef AGLA_II_MATRIX_H
#define AGLA_II_MATRIX_H

#include <string>
#include <iostream>
#include <exception>
#include <vector>

using namespace std;

template <typename T>
class Matrix;

template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& rhs)
{
    T tmp;
    for (int i = 0; i < rhs.nRows; ++i) {
    for (int j = 0; j < rhs.nColumns; ++j) {
    in >> tmp;
    rhs.setElementAt(i, j, tmp);
    }
}

return in;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& rhs)
{
    for (int i = 0; i < rhs.nRows; ++i) {
        for (int j = 0; j < rhs.nColumns; ++j) {
            out << rhs.getElementAt(i, j) << " ";
        }

        if (i != rhs.nRows - 1) out << std::endl;
    }

    return out;
}

template <typename T>
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
    Matrix(int rows, int columns)
        :
        nRows(rows),
        nColumns(columns),
        contents(rows, vector<T>(columns))
    {}

    // Copy assignment operator
    Matrix& operator=(const Matrix& rhs)
    {
        if (this == &rhs) return *this;

        nRows = rhs.getNRows();
        nColumns = rhs.getNColumns();
        contents = rhs.getContents();

        return *this;
    }

    // Matrix addition
    Matrix<T>& operator+(const Matrix<T>& rhs)
    {
        if (getNColumns() != rhs.getNColumns()
            || getNRows() != rhs.getNRows()
                )
            throw Matrix<T>::DimensionalProblemException();

        const auto matrixSum = new Matrix(getNRows(), getNColumns());

        T sum;
        for (int i = 0; i < getNRows(); ++i) {
            for (int j = 0; j < getNColumns(); ++j) {
                sum = getElementAt(i, j) + rhs.getElementAt(i, j);

                matrixSum->setElementAt(i, j, sum);
            }
        }

        return *matrixSum;
    }

    Matrix& operator+=(const Matrix& rhs)
    {
        if (nColumns != rhs.getNColumns()
            || nRows != rhs.getNRows()
                )
            throw DimensionalProblemException();

        vector<vector<T>> newContents(nRows, vector<T>(nColumns));

        T sum;
        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < nColumns; ++j) {
                sum = this->getElementAt(i, j) + rhs.getElementAt(i, j);

                newContents[i][j] = sum;
            }
        }

        contents = newContents;

        return *this;
    }

    // Matrix subtraction
    Matrix<T>& operator-(const Matrix<T>& rhs)
    {
        if (getNColumns() != rhs.getNColumns()
            || getNRows() != rhs.getNRows()
                )
            throw Matrix<T>::DimensionalProblemException();

        const auto matrixDifference = new Matrix(getNRows(), getNColumns());

        T difference;
        for (int i = 0; i < getNRows(); ++i) {
            for (int j = 0; j < getNColumns(); ++j) {
                difference = getElementAt(i, j) - rhs.getElementAt(i, j);

                matrixDifference->setElementAt(i, j, difference);
            }
        }

        return *matrixDifference;
    }

    Matrix& operator-=(const Matrix& rhs)
    {
        if (nColumns != rhs.getNColumns()
            || nRows != rhs.getNRows()
                )
            throw DimensionalProblemException();

        vector<vector<T>> newContents(nRows, vector<T>(nColumns));

        T difference;
        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < nColumns; ++j) {
                difference = this->getElementAt(i, j) - rhs.getElementAt(i, j);

                newContents[i][j] = difference;
            }
        }

        contents = newContents;

        return *this;
    }

    // Matrix multiplication
    template <typename N>
    Matrix<T>& operator*(const Matrix<N>& rhs)
    {
        if (getNColumns() != rhs.getNRows())
            throw DimensionalProblemException();

        const auto matrixProduct = new Matrix(getNRows(), rhs.getNColumns());

        T product;
        for (int i = 0; i < getNRows(); ++i)
        {
            for (int j = 0; j < rhs.getNColumns(); ++j)
            {
                product = 0;

                for (int k = 0; k < getNColumns(); ++k)
                {
                    product += getElementAt(i, k) * rhs.getElementAt(k, j);
                }

                matrixProduct->setElementAt(i, j, product);
            }
        }

        return *matrixProduct;
    }

    Matrix& operator*=(const Matrix& rhs)
    {
        if (nColumns != rhs.getNRows())
            throw DimensionalProblemException();

        vector<vector<T>> newContents(nRows, vector<T>(nColumns));

        T product;
        for (int i = 0; i < nRows; ++i)
        {
            for (int j = 0; j < rhs.getNColumns(); ++j)
            {
                product = 0;

                for (int k = 0; k < nColumns; ++k)
                {
                    product += this->getElementAt(i, k) * rhs.getElementAt(k, j);
                }

                newContents[i][j] = product;
            }
        }

        contents = newContents;

        return *this;
    }

    // Operators for writing to matrix from standard input
    friend std::istream& operator>> <>(std::istream& in, Matrix<T>& rhs);

    // Operators for outputting matrix to standard output
    friend std::ostream& operator<< <>(std::ostream& out, const Matrix<T>& rhs);

    // Transpose matrix
    [[nodiscard]] Matrix transposed() const
    {
        auto transposedMatrix = new Matrix<T>(nColumns, nRows);

        for (int i = 0; i < nColumns; ++i)
        {
            for (int j = 0; j < nRows; ++j)
            {
                transposedMatrix->setElementAt(i, j, contents[j][i]);
            }
        }

        return *transposedMatrix;
    }

public:
    // Getters
    [[nodiscard]] int getNColumns() const
    {
        return nColumns;
    }

    [[nodiscard]] int getNRows() const
    {
        return nRows;
    }

    [[nodiscard]] const std::vector<std::vector<T>> &getContents() const
    {
        return contents;
    }

    // Get particular element
    [[nodiscard]] T getElementAt(int row, int column) const
    {
        return contents[row][column];
    }

    // Set particular element
    void setElementAt(int row, int column, T value)
    {
        contents[row][column] = value;
    }
private:
    // Matrix's dimensions
    int nColumns;
    int nRows;
    // Elements of a matrix
    std::vector<std::vector<T>> contents;
};



#endif //AGLA_II_MATRIX_H
