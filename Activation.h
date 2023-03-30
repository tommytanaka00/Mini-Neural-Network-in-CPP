//Activation.h
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
    Relu,
    Softmax
};

// Insert Activation class here...
/**
 * Activation: applies a function Relu or Softmax
 */
class Activation
{
private:
    ActivationType _actType;

public:

    /**
     * Constructor for Activation
     * @param actType
     */
    Activation(ActivationType actType);

    /**
     * Getter for activationType
     */
    ActivationType getActivationType() const;

    /**
     * Applies the actType function (Relu or Softmax) on a vector and returns a resulting vector
     * @param vec Expects the vec.col == 1
     */
    Matrix operator()(const Matrix& vec) const;
};

#endif //ACTIVATION_H
