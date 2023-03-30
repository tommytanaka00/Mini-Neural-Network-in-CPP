//MlpNetwork.h

#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Activation.h"
#include "Digit.h"
#include "Dense.h"

#define MLP_SIZE 4

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784}, {64, 128}, {20, 64}, {10, 20}};
const MatrixDims biasDims[]    = {{128, 1}, {64, 1}, {20, 1},  {10, 1}};

// Insert MlpNetwork class here...
/**
 * The whole MlpNetwork. Can distinguish numbers from a 28x28 picture
 */
class MlpNetwork
{
private:
    Dense layer1;
    Dense layer2;
    Dense layer3;
    Dense layer4;

public:
    /**
     * Constructor for MlpNetwork
     * @param weights Array of weights (matrices with sizes like weightsDims)
     * @param biases Array of biases (vectors with sizes like biasDims)
     */
    MlpNetwork(const Matrix weights[4], const Matrix biases[4]);

    /**
     * Applies the whole MlpNetwork on a vector and outputs the final result
     * with the highest percentage of likelihood of it being the number
     * @param vector size imgDims.rows*imgDims.cols x 1
     * @return The Digit containing the number and the probability
     */
    Digit operator()(const Matrix& vector);

};

#endif // MLPNETWORK_H
