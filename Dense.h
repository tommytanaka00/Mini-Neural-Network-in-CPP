// Dense.h

#ifndef DENSE_H
#define DENSE_H

#include <iostream>
#include "Matrix.h"
#include "Activation.h"
#include "Digit.h"

/**
 * One layer of the MlpNetwork
 */
class Dense
{
private:
    Matrix _W;
    Matrix _b;
    ActivationType _actType;

public:
    /**
     *
     * @param W
     * @param b
     * @param actType
     */
    Dense(const Matrix& W, const Matrix& b, ActivationType actType);

    /**
     * Getter for weight
     */
    Matrix getWeights() const; //return reference?

    /**
     * Getter for bias
     */
    Matrix getBias() const; //return reference?

    /**
     * Getter for activation
     */
    ActivationType getActivation() const;

    /**
     * Applies one layer of MlpNetwork (Applies actType(W*vec + b))
     * @param vec expects a vector with vec.col == 1
     * @return the resulting Matrix
     */
    Matrix operator()(const Matrix& vec);
};



#endif //DENSE_H
