#pragma once
#include <iostream>
using std::cout;
using std::ostream;

template <class T> 
T _abs(T x) // return the absulote value (for dbl epsilon)
{
    return (x < 0) ? -x : x;
}

template <int row, int col, class T = int> //the default value of a matrix will be int
class Matrix
{
private:
    T matrix[row][col];
public:
    // ----------------------------------- c'tor

    inline Matrix(const T value = 0) : matrix() // c'tor with value / default value 0
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                matrix[i][j] = value;  // initalize the matrix with the value
    }

    // ----------------------------------- methods

    static inline Matrix<row, col, T> getIdentityMatrix()  // returns an id matrix 
    {
        Matrix<row, col, T> id; // new 0 matrix 
        for (int i = 0; i < row; i++) id.matrix[i][i] = (T)1; // update the diag to 1
        return id;
    }

    inline T* getDiag(int& number) const // return pointer of array that contains the main diag
    {
        number = (row > col) ? col : row; // size the min of row and col 
        T* diag = new T[number];
        for (int i = 0; i < number; i++) diag[i] = matrix[i][i]; // updating the array
        return diag;
    }

    // ----------------------------------- operators

    // operator =
    inline Matrix<row, col, T>& operator=(const Matrix<row, col, T>& other) // operator = for: (matrix=matrix)
    {
        if (this == &other) return *this; // if its the same object 
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                matrix[i][j] = other.matrix[i][j];
        return *this;
    }

    inline Matrix<row, col, T>& operator=(const T& scalar) // operator = for: (matrix=scalar)
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                matrix[i][j] = scalar;
        return *this;
    }

    // operator ()
    inline T& operator()(int i, int j) { return matrix[i][j]; } // return a pointer to the wanted cell :  matrix(i,j) 

    inline operator T() const // conversion operator that returns the trace of a matrix :   int(matrix) 
    {
        T trace = 0;
        int len = (row > col) ? col : row; // len of the diag
        for (int i = 0; i < len; i++) trace += matrix[i][i];  // sum up all the elements in the diag 
        return trace;
    }

    // operator +
    inline Matrix<row, col, T> operator+(const T& scalar) const // operator + for: (matrix+scalar) 
    {
        Matrix<row, col, T> mat; // create new matrix
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                mat(i, j) = matrix[i][j] + scalar; // update elements
        return mat;
    }

    inline Matrix<row, col, T> operator+(const Matrix<row, col, T>& other) const // operator + for: (matrix+matrix)
    {
        Matrix<row, col, T> mat; // create new matrix
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                mat(i, j) = matrix[i][j] + other.matrix[i][j]; // update elements
        return mat;
    }

    inline friend Matrix<row, col, T> operator+(const T& scalar, const Matrix<row, col, T>& mat1) // operator + for: (scalar+matrix)  
    {
        return mat1 + scalar;
    }

    // operator -
    inline Matrix<row, col, T> operator-() const // unary operator - for: (-matrix)
    {
        Matrix <row, col, T> mat = *this * (T)(-1); // using the * operator
        return mat;
    }

    inline Matrix<row, col, T> operator-(const T& scalar) const // operator - for: (matrix-scalar)
    {
        Matrix <row, col, T> mat = *this + (-scalar); // using the + operator
        return mat;
    }

    inline Matrix<row, col, T> operator-(const Matrix<row, col, T>& other) const // operator - for: (matrix-matrix)
    {
        Matrix<row, col, T> mat; // create new matrix
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                mat(i, j) = matrix[i][j] - other.matrix[i][j]; // update elements
        return mat;
    }

    inline friend Matrix<row, col, T> operator-(const T& scalar, const Matrix<row, col, T>& mat1) // operator - for: (scalar-matrix)  
    {
        Matrix<row, col, T> mat2(scalar); // create a new scalar matrix 
        return mat2 - mat1;
    }

    // operator *
    inline Matrix<row, col, T> operator*(const T& scalar) const // operator * for:  (matrix*scalar)
    {
        Matrix<row, col, T> mat; // create new matrix
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                mat(i, j) = matrix[i][j] * scalar; // update elements
        return mat;
    }

    inline Matrix<row, col, T> operator*(const Matrix<row, col, T>& other) const // operator * for:  (matrix*matrix)
    {
        Matrix<row, col, T> mat; // create new matrix
        int i, j, k;
        T res; // result counter
        for (i = 0; i < row; i++) // loop for rows
        {
            for (j = 0; j < col; j++) // loop for cols
            {
                res = 0; // reset the result
                for (k = 0; k < col; k++) // loop for each element
                {
                    res += matrix[i][k] * other.matrix[k][j]; // calculate  
                }
                mat.matrix[i][j] = res;
            }
        }
        return mat;
    }

    inline friend Matrix<row, col, T> operator*(const T& scalar, const Matrix<row, col, T>& mat1) // operator * for:  (scalar*matrix)
    {
        return mat1 * scalar;
    }

    // operator ++
    inline Matrix<row, col, T>& operator++() // operator ++ prefix: (++a)
    {
        return *this = *this + (T)1; // returning the changed value 
    }

    inline const Matrix<row, col, T> operator++(int) // operator ++ postfix with dummy parameter: (a++)
    {
        Matrix <row, col, T> temp = *this; // create a temp the same value 
        ++(*this); // changing the value
        return temp; // returning the original value
    }

    // operator --
    inline Matrix<row, col, T>& operator--() // operator -- prefix: (--a) 
    {
        return *this = *this - (T)1; // returning the changed value 
    }

    inline const Matrix<row, col, T> operator--(int) // operator -- postfix with dummy parameter: (a--)
    {
        Matrix <row, col, T> temp = *this; // create a temp the same value 
        --(*this); // changing the value
        return temp; // returning the original value
    }

    // operator ==  
    inline bool operator==(const Matrix<row, col, T>& other) const // operator == for: (matrix==matrix)
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (_abs(matrix[i][j] - other.matrix[i][j]) >= DBL_EPSILON) return false; // check all elements if equal
        return true;
    }

    // operator !=
    inline bool operator!=(const Matrix<row, col, T>& other) const // operator != for matrices
    {
        return !((*this) == other); // using == operator
    }

    // operator <<   
    template <int rows, int cols, typename Ts>
    inline friend ostream& operator<<(ostream& output, const Matrix<rows, cols, Ts>& other); // declaration as a friend 
};


template <int rows, int cols, typename Ts>
inline ostream& operator<<(ostream& output, const Matrix<rows, cols, Ts>& other) // operator << implementation
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            output << other.matrix[i][j] << " ";
        }
        output << "\n";
    }
    return output;
}


