//
// Created by ummagumm_a on 02.03.2021.
//

#include "SquareMatrix.h"

using namespace std;

SquareMatrix::SquareMatrix(int n)
        :
        Matrix(n, n)
{}

SquareMatrix::SquareMatrix(SquareMatrix& rhs)
    :
    Matrix(rhs)
{}

//SquareMatrix& SquareMatrix::operator=(const SquareMatrix& rhs)
//{
//    *this = static_cast<SquareMatrix&>(Matrix::operator=(rhs));
//    return *this;
//}
//
//SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& rhs)
//{
//    if (nColumns != rhs.getNColumns()
//        || nRows != rhs.getNRows()
//            )
//        throw SquareMatrix::DimensionalProblemException();
//
//    vector<vector<int>> newContents(nRows, vector<int>(nColumns));
//
//    int sum;
//    for (int i = 0; i < nRows; ++i) {
//        for (int j = 0; j < nColumns; ++j) {
//            sum = this->getElementAt(i, j) + rhs.getElementAt(i, j);
//
//            newContents[i][j] = sum;
//        }
//    }
//
//    contents = newContents;
//
//    return *this;
//}