////
//// Created by ummagumm_a on 02.04.2021.
////
//
//#include "PermutationMatrix.h"
//
//template <typename T>
//PermutationMatrix<T>::PermutationMatrix(int dimension, int row1, int row2)
//    :
//    Identity<T>(dimension)
//{
//    Identity<T>::setElementAt(row1, row1, static_cast<T>(0));
//    Identity<T>::setElementAt(row2, row2, static_cast<T>(0));
//
//    Identity<T>::setElementAt(row1, row2, static_cast<T>(0));
//    Identity<T>::setElementAt(row2, row1, static_cast<T>(0));
//}