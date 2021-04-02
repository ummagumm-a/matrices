//
// Created by ummagumm_a on 02.04.2021.
//

#include "EliminationMatrix.h"

EliminationMatrix::EliminationMatrix(int dimension, int row, int column, int value)
    :
    Identity(dimension)
{
    setElementAt(row, column, value);
}