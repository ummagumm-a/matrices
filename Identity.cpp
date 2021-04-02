//
// Created by ummagumm_a on 02.04.2021.
//

#include "Identity.h"

Identity::Identity(int n)
    :
    SquareMatrix(n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) {
            if (i == j) setElementAt(i, j, 1);
            else setElementAt(i, j, 0);
        }
    }
}