#include <iostream>
#include <cfloat> // so i can use DBL_EPSILON 
using std::cout;
using std::ostream;

template <class T>
T _abs( T x ) // return the absulote value
{   
    return (x < 0) ? -x : x;
}

template <int row, int col, class T=int> //the default value of a matrix will be int
class Matrix
{
private:
    T matrix[row][col];
public:
// ----------------------------------- c'tor

    inline Matrix(T value=0) : matrix() // c'tor with value / default value 0
    {
        for(int i=0; i<row ; i++)
            for(int j=0; j<col; j++)  
                matrix[i][j]= value;  // initalize the matrix with the value
    }

// ----------------------------------- methods

    static inline Matrix<row,col,T> getIdentityMatrix()  // returns an id matrix 
    {
        Matrix<row,col,T> id; // new 0 matrix 
        for(int i=0; i<row ; i++) id.matrix[i][i]=(T)1; // update the diag to 1
        return id;
    }

    inline T* getDiag(int& number) const // return pointer of array that contains the main diag
    {
        number= (row>col)? col: row; // size the min of row and col 
        T* diag=new T[number];
        for(int i=0; i<number ; i++) diag[i]=matrix[i][i]; // updating the array
        return diag;
    }

// ----------------------------------- operators

// operator =
    inline Matrix<row,col,T>& operator=(const Matrix<row,col,T>& other) // operator = for: (matrix=matrix)
    {
        if (this == &other) return *this; // if its the same object 
        for (int i=0 ; i<row ; i++) 
            for (int j=0 ; j<col ; j++) 
                matrix[i][j] = other.matrix[i][j];
         return *this;
    }

    inline Matrix<row,col,T>& operator=(const T& scalar) // operator = for: (matrix=scalar)
    {
        for (int i=0 ; i<row ; i++) 
            for (int j=0 ; j<col ; j++) 
                matrix[i][j] = scalar;
        return *this;
    }

// operator ()
    inline T& operator()(int i,int j) { return matrix[i][j]; } // return a pointer to the wanted cell :  matrix(i,j) 

    inline operator T() const // conversion operator that returns the trace of a matrix :   int(matrix) 
    {
        T trace=0;
        int len= (row>col)? col: row; // len of the diag
        for(int i=0; i<len ; i++) trace+=matrix[i][i];  // sum up all the elements in the diag 
        return trace;
    }

// operator +
    inline Matrix<row,col,T> operator+(const T& scalar) const // operator + for: (matrix+scalar) 
    {
        Matrix<row,col,T> mat; // create new matrix
        for(int i=0; i<row ; i++)
            for(int j=0; j<col; j++)  
                mat(i,j) = matrix[i][j]+ scalar; // update elements
        return mat;
    }

    inline Matrix<row,col,T> operator+(const Matrix<row,col,T>& other) const // operator + for: (matrix+matrix)
    {
        Matrix<row,col,T> mat; // create new matrix
        for(int i=0; i<row ; i++)
            for(int j=0; j<col; j++)  
                mat(i,j) = matrix[i][j] + other.matrix[i][j] ; // update elements
        return mat;
    }

    inline friend Matrix<row,col,T> operator+(const T& scalar,const Matrix<row,col,T>& mat1) // operator + for: (scalar+matrix)  
    {
        return mat1+scalar;
    } 

// operator -
    inline Matrix<row,col,T> operator-() const // unary operator - for: (-matrix)
    {
        Matrix <row,col,T> mat = *this*(T)(-1); // using the * operator
        return mat;
    }
    
    inline Matrix<row,col,T> operator-(const T& scalar) const // operator - for: (matrix-scalar)
    {
        Matrix <row,col,T> mat = *this+(-scalar); // using the + operator
        return mat;
    }

    inline Matrix<row,col,T> operator-(const Matrix<row,col,T>& other) const // operator - for: (matrix-matrix)
    {
        Matrix<row,col,T> mat; // create new matrix
        for(int i=0; i<row ; i++)
            for(int j=0; j<col; j++)  
                mat(i,j) = matrix[i][j] - other.matrix[i][j] ; // update elements
        return mat;
    }

    inline friend Matrix<row,col,T> operator-(const T& scalar,const Matrix<row,col,T>& mat1) // operator - for: (scalar-matrix)  
    {
        Matrix<row,col,T> mat2(scalar); // create a new scalar matrix 
        return mat2-mat1;
    } 

// operator *
    inline Matrix<row,col,T> operator*(const T& scalar) const // operator * for:  (matrix*scalar)
    {
        Matrix<row,col,T> mat; // create new matrix
        for(int i=0; i<row ; i++)
            for(int j=0; j<col; j++)  
                mat(i,j) = matrix[i][j] * scalar; // update elements
        return mat;
    }

    inline Matrix<row,col,T> operator*(const Matrix<row,col,T> & other) const // operator * for:  (matrix*matrix)
    {
        Matrix<row,col,T> mat; // create new matrix
        int i,j,k;
        T res; // result counter
        for(i=0; i<row ; i++) // loop for rows
        {
            for(j=0; j<col ; j++) // loop for cols
            {
                res=0; // reset the result
                for(k=0; k<col ; k++) // loop for each element
                {
                    res+= matrix[i][k]*other.matrix[k][j]; // calculate  
                }
                mat.matrix[i][j]=res;
            }
        }
        return mat;
    }

    inline friend Matrix<row,col,T> operator*(const T& scalar,const Matrix<row,col,T>& mat1) // operator * for:  (scalar*matrix)
    {
        return mat1*scalar;
    }

// operator ++
    inline Matrix<row,col,T>& operator++() // operator ++ prefix: (++a)
    {
        return *this= *this+(T)1; // returning the changed value 
    }

    inline Matrix<row,col,T> operator++(int) // operator ++ postfix with dummy parameter: (a++)
    {
        Matrix <row,col,T> temp= *this; // create a temp the same value 
        ++(*this); // changing the value
        return temp; // returning the original value
    }

// operator --
    inline Matrix<row,col,T>& operator--() // operator -- prefix: (--a) 
    {
        return *this= *this-(T)1; // returning the changed value 
    }

    inline Matrix<row,col,T> operator--(int) // operator -- postfix with dummy parameter: (a--)
    {
        Matrix <row,col,T> temp= *this; // create a temp the same value 
        --(*this); // changing the value
        return temp; // returning the original value
    }

// operator ==  
    inline bool operator==(const Matrix<row,col,T>& other) const // operator == for: (matrix==matrix)
    {
        for(int i=0; i<row ; i++)
            for(int j=0; j<col; j++)  
                if( _abs(matrix[i][j]-other.matrix[i][j]) >= DBL_EPSILON) return false ; // check all elements if equal
        return true;
    }

// operator !=
    inline bool operator!=(const Matrix<row,col,T>& other) const // operator != for matrices
    {
        return !( (*this)== other); // using == operator
    }
    
// operator <<   
    template <int rows, int cols, typename Ts>
    inline friend ostream& operator<<(ostream& output, const Matrix<rows,cols,Ts>& other ); // declaration as a friend 
};


template <int rows, int cols, typename Ts>
inline ostream& operator<<(ostream& output, const Matrix<rows,cols,Ts>& other ) // operator << implementation
{
    for (int i=0 ; i<rows ; i++)
    {
        for (int j=0 ; j<cols ; j++)
        {
            output << other.matrix[i][j] << " ";
        }
        output << "\n";
    }
    return output; 
}


// ----------------------------------------------------------------------------- their tests begin



template <int row, int col, typename T>
void printDiag(Matrix<row, col, T>& mat) {
    int number;
    T* diag = mat.getDiag(number);
    for (int i = 0; i < number; i++)
    {
        std::cout << diag[i] << " ";
    }
    std::cout << std::endl;
    delete[] diag;
}
// template <int row, int col, typename T>
//void print(Matrix<row, col, T>& mat) {
// Note : std::cout<<mat should be identical to print(mat) 
//    int i, j;
//    for (i = 0; i < row; i++)
//    {
//        for (j = 0; j < col; j++)
//        {
//            std::cout << mat.data[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//}

int main() {
   //freopen("output_matrix.txt", "w", stdout);

   Matrix<4, 4> mat;
   std::cout << mat << std::endl;

   Matrix<4,4> identity = mat.getIdentityMatrix();
   std::cout << identity << std::endl;

   Matrix<4, 4> res = (identity + 2) * 3;
   std::cout << res << std::endl;

   Matrix<4, 3> mat1(9);
   Matrix<4, 3> mat2(4);

   std::cout << (mat1 - 4) << std::endl;

   mat2(2, 1) = 0;

   const int cell = (2 + mat1 - 1)(1, 2);

   std::cout << "The value of cell 1, 2 is: " << cell << std::endl;

   std::cout << (1 + mat2) << std::endl;

   std::cout << ++mat1 << std::endl;
   std::cout << --mat2 << std::endl;

   std::cout << "Values of mat1 and mat2, before..." << std::endl;
   std::cout << mat1++ << std::endl;
   std::cout << mat2-- << std::endl;

   std::cout << "Values of mat1 and mat2, after..." << std::endl;
   std::cout << mat1 << std::endl;
   std::cout << mat2 << std::endl;

   mat2(0, 0) = 13;

   /*
    * Matrix diagonal is:
    * 1. In case of nxn matrix it's simple all (i, i) cell for all
    * i between 0 and n - 1.
    * 2. In case of nxm matrix it's all cells (i, i) cells for all
    * i between 0 and min(n,m).
    */
   std::cout << "Printing main diagonal of mat2:" << std::endl;
   printDiag(mat2);

   /*
    *
    * Trace of any given Matrix nxm is the sum of main
    * diagonal entries.
    *
    * 
    */
   std::cout << "trace(mat2) = " << int(mat2) << std::endl;
   std::cout << std::endl;

   Matrix<4, 2, double> m1, m2;

   m1(0, 0) = 1;  m1(0, 1) = -1;   //  1 -1
   m1(1, 0) = 3;  m1(1, 1) = 7;    //  3  7
   m1(2, 0) = -5; m1(2, 1) = 0;    // -5  0
   m1(3, 0) = 2; m1(3, 1) = 2;    // -2  2


   std::cout << "Matrix m1: " << std::endl;
   std::cout << m1 << std::endl;
   std::cout << "Printing main diagonal of m1:" << std::endl;
   printDiag(m1);
   std::cout << "trace(m1) = " << double(m1) << std::endl;
   std::cout << std::endl;

   m2(0, 0) = 5;      m2(0, 1) = 1;   //  5  1
   m2(1, 0) = -2;     m2(1, 1) = 2;   // -2  2
   m2(2, 0) = 0;      m2(2, 1) = 6;   //  0  6
   m2(3, 0) = 4;      m2(3, 1) = 8;   //  4  8

   std::cout << "Matrix m2: " << std::endl;
   std::cout << m2 << std::endl;
   std::cout << "Printing main diagonal of m2:" << std::endl;
   printDiag(m2);
   std::cout << "trace(m2) = " << double(m2) << std::endl;
   std::cout << std::endl;

   Matrix<4, 2, double> m3 = m1 + m2;

   std::cout << "Matrix m3 = m1 + m2: " << std::endl;
   std::cout << m3 << std::endl;
   std::cout << "Printing main diagonal of m3:" << std::endl;
   printDiag(m3);
   std::cout << "trace(m3) = " << double(m3) << std::endl;
   std::cout << std::endl;

   Matrix<4, 2, double> m4 = m3 + double(1) - m2 * double(2) + m1;
   ++m4;
   std::cout << "Matrix m4 = m3 + 1 - 2*m2 + m1:" << std::endl;
   std::cout << "++m4" << std::endl;
   std::cout << "m4:" << std::endl;
   std::cout << m4 << std::endl;
   std::cout << "Printing main diagonal of m4:" << std::endl;
   printDiag(m4);
   std::cout << "trace(m4) = " << double(m4) << std::endl;
   std::cout << std::endl;


   Matrix<2, 4, float> mf1(2.5f);

   mf1(0, 0) += 3; mf1(0, 3) -= 0.5f;
   mf1(1, 1) = 0; mf1(1, 2) = 0;
   ++mf1;
   mf1 = (-mf1 + 1.7f) + mf1 * 0.25f - float(1);
   std::cout << "Matrix mf1:" << std::endl;
   std::cout << mf1 << std::endl;
   std::cout << "Printing main diagonal of mf1:" << std::endl;
   printDiag(mf1);
   std::cout << "trace(mf1) = " <<float(mf1) << std::endl;
   std::cout << std::endl;

   return 0;
}
