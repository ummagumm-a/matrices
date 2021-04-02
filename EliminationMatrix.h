//
// Created by ummagumm_a on 02.04.2021.
//

#ifndef AGLA_II_ELIMINATIONMATRIX_H
#define AGLA_II_ELIMINATIONMATRIX_H

#include "Identity.h"

class EliminationMatrix : public Identity {
public:
    EliminationMatrix(int dimension, int row, int column, int value);
};


#endif //AGLA_II_ELIMINATIONMATRIX_H
