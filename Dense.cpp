#include "Dense.h"

/**
 * See header file for the comment
 */
Dense::Dense(const Matrix& W, const Matrix& b, ActivationType actType):  _W(W), _b(b), _actType(actType)
{
    //nothing needed here (for the time being)
}

/**
 * See header file for the comment
 */
Matrix Dense::getWeights() const //return reference? Do I need const?
{
    return _W;
}


/**
 * See header file for the comment
 */
Matrix Dense::getBias() const //return reference?
{
    return _b;
}

/**
 * See header file for the comment
 */
ActivationType Dense::getActivation() const
{
    return  _actType;
}


/**
 * See header file for the comment
 */
Matrix Dense::operator()(const Matrix& vec)
{
    Matrix outPutMatrix = (_W * vec) + _b;
    Activation act = _actType;
    outPutMatrix = act(outPutMatrix);
    return outPutMatrix;
}

