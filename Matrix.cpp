//
// Created by ummagumm_a on 02.03.2021.
//

#include "Matrix.h"

using namespace std;

Matrix::Matrix(int rows, int columns)
        :
        nRows(rows),
        nColumns(columns),
        contents(rows, vector<int>(columns))
{}

Matrix::Matrix(Matrix& rhs)
{
    nRows = rhs.getNRows();
    nColumns = rhs.getNColumns();
    contents = rhs.getContents();
}

std::istream& operator>>(std::istream& in, Matrix& rhs)
{
    int tmp;
    for (int i = 0; i < rhs.nRows; ++i) {
        for (int j = 0; j < rhs.nColumns; ++j) {
            in >> tmp;
            rhs.setElementAt(i, j, tmp);
        }
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& rhs)
{
    for (int i = 0; i < rhs.nRows; ++i) {
        for (int j = 0; j < rhs.nColumns; ++j) {
            out << rhs.getElementAt(i, j) << " ";
        }

        if (i != rhs.nRows - 1) out << std::endl;
    }

    return out;
}

Matrix& Matrix::operator=(const Matrix& rhs)
{
    if (this == &rhs) return *this;

    nRows = rhs.getNRows();
    nColumns = rhs.getNColumns();
    contents = rhs.getContents();

    return *this;
}

Matrix& operator+(const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.getNColumns() != rhs.getNColumns()
        || lhs.getNRows() != rhs.getNRows()
        )
        throw Matrix::DimensionalProblemException();

    const auto matrixSum = new Matrix(lhs.getNRows(), lhs.getNColumns());

    int sum;
    for (int i = 0; i < lhs.getNRows(); ++i) {
        for (int j = 0; j < lhs.getNColumns(); ++j) {
            sum = lhs.getElementAt(i, j) + rhs.getElementAt(i, j);

            matrixSum->setElementAt(i, j, sum);
        }
    }

    return *matrixSum;
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
    if (nColumns != rhs.getNColumns()
        || nRows != rhs.getNRows()
            )
        throw Matrix::DimensionalProblemException();

    vector<vector<int>> newContents(nRows, vector<int>(nColumns));

    int sum;
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nColumns; ++j) {
            sum = this->getElementAt(i, j) + rhs.getElementAt(i, j);

            newContents[i][j] = sum;
        }
    }

    contents = newContents;

    return *this;
}

Matrix& operator-(const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.getNColumns() != rhs.getNColumns()
        || lhs.getNRows() != rhs.getNRows()
            )
        throw Matrix::DimensionalProblemException();

    const auto matrixDifference = new Matrix(lhs.getNRows(), lhs.getNColumns());

    int difference;
    for (int i = 0; i < lhs.getNRows(); ++i) {
        for (int j = 0; j < lhs.getNColumns(); ++j) {
            difference = lhs.getElementAt(i, j) - rhs.getElementAt(i, j);

            matrixDifference->setElementAt(i, j, difference);
        }
    }

    return *matrixDifference;
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
    if (nColumns != rhs.getNColumns()
        || nRows != rhs.getNRows()
            )
        throw Matrix::DimensionalProblemException();

    vector<vector<int>> newContents(nRows, vector<int>(nColumns));

    int difference;
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nColumns; ++j) {
            difference = this->getElementAt(i, j) - rhs.getElementAt(i, j);

            newContents[i][j] = difference;
        }
    }

    contents = newContents;

    return *this;
}

Matrix& operator*(const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.getNColumns() != rhs.getNRows())
        throw Matrix::DimensionalProblemException();

    const auto matrixProduct = new Matrix(lhs.getNRows(), rhs.getNColumns());

    int product;
    for (int i = 0; i < lhs.getNRows(); ++i)
    {
        for (int j = 0; j < rhs.getNColumns(); ++j)
        {
            product = 0;

            for (int k = 0; k < lhs.getNColumns(); ++k)
            {
                product += lhs.getElementAt(i, k) * rhs.getElementAt(k, j);
            }

            matrixProduct->setElementAt(i, j, product);
        }
    }

    return *matrixProduct;
}

Matrix& Matrix::operator*=(const Matrix& rhs)
{
    if (nColumns != rhs.getNRows())
        throw Matrix::DimensionalProblemException();

    vector<vector<int>> newContents(nRows, vector<int>(nColumns));

    int product;
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

Matrix Matrix::transposed() const
{
    auto transposedMatrix = new Matrix(nColumns, nRows);

    for (int i = 0; i < nColumns; ++i)
    {
        for (int j = 0; j < nRows; ++j)
        {
            transposedMatrix->setElementAt(i, j, contents[j][i]);
        }
    }

    return *transposedMatrix;

}

void Matrix::setElementAt(const int row, const int column, const int value)
{
    contents[row][column] = value;
}

int Matrix::getNColumns() const {
    return nColumns;
}

int Matrix::getNRows() const {
    return nRows;
}

const vector<vector<int>> &Matrix::getContents() const {
    return contents;
}

int Matrix::getElementAt(const int row, const int column) const
{
    return contents[row][column];
}