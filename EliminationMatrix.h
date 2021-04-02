//
// Created by ummagumm_a on 02.04.2021.
//

#ifndef AGLA_II_ELIMINATIONMATRIX_H
#define AGLA_II_ELIMINATIONMATRIX_H

#include "Identity.h"

template <typename T>
class EliminationMatrix : public Identity<T> {
public:
    EliminationMatrix(int dimension, int row, int column, T value)
        :
        Identity<T>(dimension)
    {
        Identity<T>::setElementAt(row, column, value);
    }
};


#endif //AGLA_II_ELIMINATIONMATRIX_H
