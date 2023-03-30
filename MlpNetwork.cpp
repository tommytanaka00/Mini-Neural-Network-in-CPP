#include <iostream>
#include "MlpNetwork.h"
#include "Digit.h"

#define ERROR_MESSAGE_VECTOR_LENGTH_NOT_10 "Error: Outputted vector length not 10"

/**
 * See header file for the comment
 */
MlpNetwork::MlpNetwork(const Matrix weights[4], const Matrix biases[4]): layer1(weights[0], biases[0], Relu),
layer2(weights[1], biases[1], Relu), layer3(weights[2], biases[2], Relu),
layer4(weights[3], biases[3], Softmax)
{
    //nothing needed here
}

/**
 * See header file for the comment
 */
Digit MlpNetwork::operator()(const Matrix& vector)
{
    Matrix r = layer1(vector);
    r = layer2(r);
    r = layer3(r);
    r = layer4(r);
    //^ applying all the layers
    if (r.getRows() != 10)
    {
        std::cerr << ERROR_MESSAGE_VECTOR_LENGTH_NOT_10 << std::endl;
        exit(EXIT_FAILURE);
    }
    float maxProb = r[0];
    unsigned int maxNum = 0;
    for (int j = 1; j < r.getRows(); j++)// iterate from beginning to end, since if there are two identical probabilities
        //then we give back the one with the lower index
    {
        if (r[j] > maxProb)
        {
            maxProb = (float) r[j];
            maxNum = j; // +1 because the index starts from 0
        }
    }
    Digit finalDigit = {maxNum, maxProb};
    return finalDigit;
}



