////
//// Created by ummagumm_a on 02.03.2021.
////
//
//#include "Matrix.h"
//
//using namespace std;
//
//template <typename T>
//Matrix<T>::Matrix(int rows, int columns)
//        :
//        nRows(rows),
//        nColumns(columns),
//        contents(rows, vector<T>(columns))
//{}
//
//template <typename T>
//Matrix<T>::Matrix(Matrix& rhs)
//{
//    nRows = rhs.getNRows();
//    nColumns = rhs.getNColumns();
//    contents = rhs.getContents();
//}
//
//template <typename T>
//std::istream& operator>>(std::istream& in, Matrix<T>& rhs)
//{
//    T tmp;
//    for (int i = 0; i < rhs.nRows; ++i) {
//        for (int j = 0; j < rhs.nColumns; ++j) {
//            in >> tmp;
//            rhs.setElementAt(i, j, tmp);
//        }
//    }
//
//    return in;
//}
//
//template <typename T>
//std::ostream& operator<<(std::ostream& out, const Matrix<T>& rhs)
//{
//    for (int i = 0; i < rhs.nRows; ++i) {
//        for (int j = 0; j < rhs.nColumns; ++j) {
//            out << rhs.getElementAt(i, j) << " ";
//        }
//
//        if (i != rhs.nRows - 1) out << std::endl;
//    }
//
//    return out;
//}
//
//template <typename T>
//Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs)
//{
//    if (this == &rhs) return *this;
//
//    nRows = rhs.getNRows();
//    nColumns = rhs.getNColumns();
//    contents = rhs.getContents();
//
//    return *this;
//}
//
//template <typename T>
//
//Matrix<T>& operator+(const Matrix<T>& lhs, const Matrix<T>& rhs)
//{
//    if (lhs.getNColumns() != rhs.getNColumns()
//        || lhs.getNRows() != rhs.getNRows()
//        )
//        throw Matrix<T>::DimensionalProblemException();
//
//    const auto matrixSum = new Matrix(lhs.getNRows(), lhs.getNColumns());
//
//    T sum;
//    for (int i = 0; i < lhs.getNRows(); ++i) {
//        for (int j = 0; j < lhs.getNColumns(); ++j) {
//            sum = lhs.getElementAt(i, j) + rhs.getElementAt(i, j);
//
//            matrixSum->setElementAt(i, j, sum);
//        }
//    }
//
//    return *matrixSum;
//}
//
//template <typename T>
//
//Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& rhs)
//{
//    if (nColumns != rhs.getNColumns()
//        || nRows != rhs.getNRows()
//            )
//        throw DimensionalProblemException();
//
//    vector<vector<T>> newContents(nRows, vector<T>(nColumns));
//
//    T sum;
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
//
//template <typename T>
//Matrix<T>& operator-(const Matrix<T>& lhs, const Matrix<T>& rhs)
//{
//    if (lhs.getNColumns() != rhs.getNColumns()
//        || lhs.getNRows() != rhs.getNRows()
//            )
//        throw Matrix<T>::DimensionalProblemException();
//
//    const auto matrixDifference = new Matrix(lhs.getNRows(), lhs.getNColumns());
//
//    T difference;
//    for (int i = 0; i < lhs.getNRows(); ++i) {
//        for (int j = 0; j < lhs.getNColumns(); ++j) {
//            difference = lhs.getElementAt(i, j) - rhs.getElementAt(i, j);
//
//            matrixDifference->setElementAt(i, j, difference);
//        }
//    }
//
//    return *matrixDifference;
//}
//
//template <typename T>
//Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& rhs)
//{
//    if (nColumns != rhs.getNColumns()
//        || nRows != rhs.getNRows()
//            )
//        throw DimensionalProblemException();
//
//    vector<vector<T>> newContents(nRows, vector<T>(nColumns));
//
//    T difference;
//    for (int i = 0; i < nRows; ++i) {
//        for (int j = 0; j < nColumns; ++j) {
//            difference = this->getElementAt(i, j) - rhs.getElementAt(i, j);
//
//            newContents[i][j] = difference;
//        }
//    }
//
//    contents = newContents;
//
//    return *this;
//}
//
//template <typename T>
//Matrix<T>& operator*(const Matrix<T>& lhs, const Matrix<T>& rhs)
//{
//    if (lhs.getNColumns() != rhs.getNRows())
//        throw Matrix<T>::DimensionalProblemException();
//
//    const auto matrixProduct = new Matrix(lhs.getNRows(), rhs.getNColumns());
//
//    T product;
//    for (int i = 0; i < lhs.getNRows(); ++i)
//    {
//        for (int j = 0; j < rhs.getNColumns(); ++j)
//        {
//            product = 0;
//
//            for (int k = 0; k < lhs.getNColumns(); ++k)
//            {
//                product += lhs.getElementAt(i, k) * rhs.getElementAt(k, j);
//            }
//
//            matrixProduct->setElementAt(i, j, product);
//        }
//    }
//
//    return *matrixProduct;
//}
//
//template <typename T>
//Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& rhs)
//{
//    if (nColumns != rhs.getNRows())
//        throw DimensionalProblemException();
//
//    vector<vector<T>> newContents(nRows, vector<T>(nColumns));
//
//    T product;
//    for (int i = 0; i < nRows; ++i)
//    {
//        for (int j = 0; j < rhs.getNColumns(); ++j)
//        {
//            product = 0;
//
//            for (int k = 0; k < nColumns; ++k)
//            {
//                product += this->getElementAt(i, k) * rhs.getElementAt(k, j);
//            }
//
//            newContents[i][j] = product;
//        }
//    }
//
//    contents = newContents;
//
//    return *this;
//}
//
//template <typename T>
//Matrix<T> Matrix<T>::transposed() const
//{
//    auto transposedMatrix = new Matrix<T>(nColumns, nRows);
//
//    for (int i = 0; i < nColumns; ++i)
//    {
//        for (int j = 0; j < nRows; ++j)
//        {
//            transposedMatrix->setElementAt(i, j, contents[j][i]);
//        }
//    }
//
//    return *transposedMatrix;
//}
//
//template <typename T>
//void Matrix<T>::setElementAt(const int row, const int column, const T value)
//{
//    contents[row][column] = value;
//}
//
//template <typename T>
//int Matrix<T>::getNColumns() const {
//    return nColumns;
//}
//
//template <typename T>
//int Matrix<T>::getNRows() const {
//    return nRows;
//}
//
//template <typename T>
//const vector<vector<T>> &Matrix<T>::getContents() const {
//    return contents;
//}
//
//template <typename T>
//T Matrix<T>::getElementAt(const int row, const int column) const
//{
//    return contents[row][column];
//}