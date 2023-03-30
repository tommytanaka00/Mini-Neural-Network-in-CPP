#include <cmath>
#include "Matrix.h"
#include "Activation.h"

//#define ERROR_MESSAGE_NOT_VECTOR "Error: Inputted matrix not a vector"

/**
 * See header file for the comment
 */
Activation::Activation(ActivationType actType): _actType(actType)
{
    //Nothing needed here;
}

/**
 * See header file for the comment
 */
ActivationType Activation::getActivationType() const
{
    return _actType;
}

/**
 * See header file for the comment
 */
Matrix Activation::operator()(const Matrix& vec) const
// expects that vec is a vector with vec.cols = 1
{
    Matrix newVec(vec.getRows(), 1);
    if (_actType == Relu)
    {
        for (int i = 0; i < vec.getRows(); i++)
        {
            if (vec(i, 0) > 0.0f) //else: since newVec already has 0 initialized it is 0 as needed
            {
                newVec(i, 0) = vec(i, 0);
            }
        }
    }
    else if (_actType == Softmax)
    {
        float sumOfExp = std::exp(vec(0, 0));
        {
            for (int i = 1; i < vec.getRows(); i++)  //Sum of all the exponents
            {
                sumOfExp += std::exp(vec(i, 0));
            }
        }
        for (int k = 0; k < vec.getRows(); k++)
        {
            newVec(k, 0) = std::exp(vec(k, 0)) * (1.0f / sumOfExp);
        }
    }
    return newVec;
}