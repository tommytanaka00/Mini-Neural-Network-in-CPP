// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>


/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
    int rows, cols;
} MatrixDims;

// Insert Matrix class here...

/**
 * Class of a matrix
 */
class Matrix
{
private:
    float *_matrix;
    MatrixDims _dimentions;

public:
    /**
     * Constructor for Matrix. Creates a rows x cols Matrix. Initializes all the places as 0
     * @param rows Number of rows
     * @param cols Number of columns
     */
    Matrix(int rows, int cols);

    /**
     * Default Constructor for Matrix. Creates a 1x1 matrix.
     */
    Matrix();

    /**
     * Copy constructor for Matrix.
     */
    Matrix(const Matrix&);

    /**
     * Destructor for Matrix. Frees the memory allocated for _matrix.
     */
    ~Matrix();

    /**
     * Getter for number of rows
     */
    int getRows() const;

    /**
     * Getter for number of cols
     */
    int getCols() const;

    /**
     * Transforms a matrix into a vector with (rows*cols) rows and 1 columns.
     * @return Reference to the updated matrix (as a vector)
     */
    Matrix& vectorize();

    /**
     * Prints the matrix in a simple way
     */
    void plainPrint() const;

    /**
     * Assignment operator
     */
    Matrix& operator=(const Matrix& rhs);

    /**
     * Multiplying by a constant from the left
     */
    Matrix operator*(const float c) const;


    /**
     * Matrix multiplication
     */
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);

    /**
     * Multiplying by a constant from the right
     */
    friend Matrix operator*(const float c, const Matrix& m);

    /**
     * Matrix addition
     */
    Matrix operator+(const Matrix& rhs) const;

    /**
     * Matrix addition
     */
    Matrix& operator+=(const Matrix& rhs);

    /**
     * Gets the index by (row, col) (const version)
     */
    const float& operator()(const unsigned int i, const unsigned int j) const;

    /**
     * Gets the index by (row, col) (non const version)
     */
    float& operator()(const unsigned int i, const unsigned int j);

    /**
     * Gets the index by coordinate of the _matrix (const version)
     */
    const float& operator[](const unsigned int coord) const;

    /**
     * Gets the index by coordinate of the _matrix (const version)
     */
    float& operator[](const unsigned int coord);


    /**
     * Out stream: prints the matrix with **s and spaces
     */
    friend std::ostream& operator<<(std::ostream& out, const Matrix& rhsM);

    /**
     * In stream: read a matrix from a file
     */
    friend std::istream& operator>>(std::istream& in, Matrix& rhsM);
};




#endif //MATRIX_H
