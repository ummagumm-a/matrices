//
// Created by ummagumm_a on 02.04.2021.
//

#include "PermutationMatrix.h"

PermutationMatrix::PermutationMatrix(int dimension, int row1, int row2)
    :
    Identity(dimension)
{
    setElementAt(row1, row1, 0);
    setElementAt(row2, row2, 0);

    setElementAt(row1, row2, 1);
    setElementAt(row2, row1, 1);
}