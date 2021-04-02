//
// Created by ummagumm_a on 02.04.2021.
//

#ifndef AGLA_II_PERMUTATIONMATRIX_H
#define AGLA_II_PERMUTATIONMATRIX_H

#include "Identity.h"

template <typename T>
class PermutationMatrix : public Identity<T>
{
public:
    PermutationMatrix(int dimension, int row1, int row2)
        :
        Identity<T>(dimension)
    {
        Identity<T>::setElementAt(row1, row1, static_cast<T>(0));
        Identity<T>::setElementAt(row2, row2, static_cast<T>(0));

        Identity<T>::setElementAt(row1, row2, static_cast<T>(1));
        Identity<T>::setElementAt(row2, row1, static_cast<T>(1));
    }
};


#endif //AGLA_II_PERMUTATIONMATRIX_H
