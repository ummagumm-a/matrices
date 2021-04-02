//
// Created by ummagumm_a on 23.03.2021.
//

#ifndef AGLA_II_SQUAREMATRIX_H
#define AGLA_II_SQUAREMATRIX_H

#include "Matrix.h"

class SquareMatrix : public Matrix {
private:
    class DimensionalProblemException : public std::exception
    {
        [[nodiscard]] const char* what() const noexcept override
        {
            return "Error: the dimensional problem occurred";
        }
    };
public:
    // Constructor for Matrix which sets its dimensions
    explicit SquareMatrix(int n);
    // Copy constructor
    SquareMatrix(SquareMatrix& rhs);

    [[nodiscard]] int dimension() const
    {
        return getNColumns();
    }
};


#endif //AGLA_II_SQUAREMATRIX_H
