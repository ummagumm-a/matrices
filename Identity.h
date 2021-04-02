//
// Created by ummagumm_a on 02.04.2021.
//

#ifndef AGLA_II_IDENTITY_H
#define AGLA_II_IDENTITY_H

#include "SquareMatrix.h"

template <typename T>
class Identity : public SquareMatrix<T>
{
public:
    explicit Identity(int n)
        :
        SquareMatrix<T>(n)
    {
        for (int i = 0; i < n; ++i)
        {
            SquareMatrix<T>::setElementAt(i, i, static_cast<T>(1));
        }
    }
};


#endif //AGLA_II_IDENTITY_H
