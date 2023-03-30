#include <iostream>
#include <fstream>
#include "Matrix.h"

#define ERROR_MESSAGE_IDX_NOT_POS "Error: Index given not positive"
#define ERROR_MESSAGE_MATRIX_SIZE_DOESNT_MATCH "Error: Matrix sizes don't match for adding"
#define ERROR_MESSAGE_INVALID_IDX "Error: Invalid index given"
#define ERROR_MESSAGE_MATRIX_SIZE_DOESNT_CORRESPOND "Error: Matrix sizes don't corrispond for multiplying"
#define ERROR_MESSAGE_MATRIX_INPUT_STREAM "Error: Input failed"


/**
 * See header file for the comment
 */
Matrix::Matrix(int rows, int cols): _dimentions{rows, cols}
{
    if (rows <= 0 || cols <= 0)
    {
        std::cerr << ERROR_MESSAGE_IDX_NOT_POS << std::endl;
        exit(EXIT_FAILURE);
    }
    _matrix = new float[rows * cols];
    for (int i = 0; i < rows * cols; i++)
    {
        _matrix[i] = 0.0f; //initializing to 0
    }
}

/**
 * See header file for the comment
 */
Matrix::Matrix(): Matrix::Matrix(1, 1) //default initializer
{
    //nothing needed here
}

/**
 * See header file for the comment
 */
Matrix::Matrix(const Matrix& M): Matrix::Matrix(M._dimentions.rows, M._dimentions.cols) //copy constructor
{
    for (int i = 0; i < _dimentions.rows * _dimentions.cols; i++)
    {
        _matrix[i] = M._matrix[i]; //no redundant checks as opposed to using the []/() operators
                                    // (we know that the indices match)
    }
}

/**
 * See header file for the comment
 */
Matrix::~Matrix()
{
    delete[] _matrix;
}


int Matrix::getRows() const
{
    return  _dimentions.rows;
}

int Matrix::getCols() const
{
    return _dimentions.cols;
}

Matrix& Matrix::vectorize()
{
    _dimentions.rows = _dimentions.rows * _dimentions.cols;
    _dimentions.cols = 1;
    return *this;
}


void Matrix::plainPrint() const
{
    for (int i = 0; i < _dimentions.rows; i++)
    {
        for (int j = 0; j < _dimentions.cols; j++)
        {
            float val = (*this)(i, j);
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}


Matrix& Matrix::operator=(const Matrix& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    _dimentions.cols = rhs._dimentions.cols;
    _dimentions.rows = rhs._dimentions.rows;
    delete[] _matrix;
    _matrix = new float[_dimentions.rows * _dimentions.cols];
    for (int i = 0; i < _dimentions.rows * _dimentions.cols; i++)
    {
        _matrix[i] = rhs._matrix[i]; //no redundant checks as opposed to using the []/() operators
                                    // (we know that the indices match)
    }
    return *this;
}


/**
 * See header file for the comment
 */
Matrix Matrix::operator*(const float c) const
{
    Matrix newMatrix(_dimentions.rows, _dimentions.cols);
    for (int i = 0; i < _dimentions.rows * _dimentions.cols; i++)
    {
        newMatrix[i] = _matrix[i] * c;
    }
    return newMatrix;
}

/**
 * See header file for the comment
 */
Matrix Matrix::operator+(const Matrix& rhs) const
{
    if (_dimentions.rows != rhs._dimentions.rows || _dimentions.cols != rhs._dimentions.cols)
    {
        std::cerr << ERROR_MESSAGE_MATRIX_SIZE_DOESNT_MATCH << std::endl;
        exit(EXIT_FAILURE);
    }
    Matrix newMatrix(_dimentions.rows, _dimentions.cols);
    for (int i = 0; i < _dimentions.rows * _dimentions.cols; i++)
    {
        newMatrix[i] = _matrix[i] + rhs._matrix[i];
    }
    return newMatrix;
}

/**
 * See header file for the comment
 */
Matrix& Matrix::operator+=(const Matrix& rhs)
{
    if (_dimentions.rows != rhs._dimentions.rows || _dimentions.cols != rhs._dimentions.cols)
    {
        std::cerr << ERROR_MESSAGE_MATRIX_SIZE_DOESNT_MATCH << std::endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < _dimentions.rows * _dimentions.cols; i++)
    {
        _matrix[i] += rhs._matrix[i];
    }
    return *this;
}

/**
 * See header file for the comment
 */
const float& Matrix::operator()(const unsigned int i, const unsigned int j) const
{
    if (i >= (unsigned int) _dimentions.rows || j >= (unsigned int) _dimentions.cols)
    {
        std::cerr << ERROR_MESSAGE_INVALID_IDX << std::endl;
        exit(EXIT_FAILURE);
    }
    return _matrix[i * _dimentions.cols + j];
}

/**
 * See header file for the comment
 */
float& Matrix::operator()(const unsigned int i, const unsigned int j)
{
    if (i >= (unsigned int) _dimentions.rows || j >= (unsigned int) _dimentions.cols)
    {
        std::cerr << ERROR_MESSAGE_INVALID_IDX << std::endl;
        exit(EXIT_FAILURE);
    }
    return _matrix[i * _dimentions.cols + j];
}

/**
 * See header file for the comment
 */
const float& Matrix::operator[](const unsigned int coord) const
{
    if (coord >= (unsigned int) _dimentions.rows * _dimentions.cols)
    {
        std::cerr << ERROR_MESSAGE_INVALID_IDX << std::endl;
        exit(EXIT_FAILURE);
    }
    return _matrix[coord];
}

/**
 * See header file for the comment
 */
float& Matrix::operator[](const unsigned int coord)
{
    if (coord >= (unsigned int) _dimentions.rows * _dimentions.cols)
    {
        std::cerr << ERROR_MESSAGE_INVALID_IDX << std::endl;
        exit(EXIT_FAILURE);
    }
    return _matrix[coord];
}

/**
 * See header file for the comment
 */
Matrix operator*(const Matrix& lhs, const Matrix& rhs) //friend function
{
    if (lhs._dimentions.cols != rhs._dimentions.rows)
    {
        std::cerr << ERROR_MESSAGE_MATRIX_SIZE_DOESNT_CORRESPOND << std::endl;
        exit(EXIT_FAILURE);
    }
    Matrix newMatrix(lhs._dimentions.rows, rhs._dimentions.cols);
    for (int i = 0; i < lhs._dimentions.rows; i++)
    {
        for (int j = 0; j < rhs._dimentions.cols; j++)
        {
            newMatrix(i, j) = lhs(i, 0) * rhs(0, j);
            for (int k = 1; k < lhs._dimentions.cols; k++)
            {
                newMatrix(i, j) += lhs(i, k) * rhs(k, j);
            }
        }
    }
    return newMatrix;
}

/**
 * See header file for the comment
 */
Matrix operator*(const float c, const Matrix& rhsM) //friend function
{
    Matrix newMatrix(rhsM._dimentions.rows, rhsM._dimentions.cols);
    for (int i = 0; i < rhsM._dimentions.rows * rhsM._dimentions.cols; i++)
    {
        newMatrix[i] = c * rhsM._matrix[i];
    }
    return newMatrix;
}

/**
 * See header file for the comment
 */
std::ostream& operator<<(std::ostream& out, const Matrix& rhsM) //friend function
{
    for (int i = 0; i < rhsM._dimentions.rows; i++)
    {
        for (int j = 0; j < rhsM._dimentions.cols; j++)
        {
            if (rhsM(i, j) <= 0.1f)
            {
                out << "  ";
            }
            else
            {
                out << "**";
            }
        }
        out << std::endl;
    }
    return out;
}

/**
 * See header file for the comment
 */
std::istream& operator>>(std::istream& in, Matrix& rhsM) //friend function
{
    for (int i = 0; i < rhsM._dimentions.rows * rhsM._dimentions.cols; i++)
    {
        in.read((char*) &(rhsM[i]) , sizeof(float));
        if (!in.good() || in.eof()) //If it isn't good or there is an EOF too early
        {
            std::cerr << ERROR_MESSAGE_MATRIX_INPUT_STREAM << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    if (in.peek() != EOF) //There is no EOF at the end of the file
    {
        std::cerr << ERROR_MESSAGE_MATRIX_INPUT_STREAM << std::endl;
        exit(EXIT_FAILURE);
    }
    return in;
}
