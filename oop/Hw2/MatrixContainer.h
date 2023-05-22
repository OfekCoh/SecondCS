#pragma once
#include "Matrix.h"

template <int row, int col, class T = int> //the default value of a matrix will be int
class MatrixContainer
{
private:
    Matrix<row, col, T>* array;
    int size_arr; // amount of matrices in the container
    int capacity_arr; // size of the dynamic array

public:
    // ----------------------------------- c'tor & d'tor
    MatrixContainer() : array(new Matrix<row, col, T>[1]), size_arr(0), capacity_arr(1) {} // c'tor- starts the array with size 1

    ~MatrixContainer() { delete[] array; } // free array memory

    // ----------------------------------- methods
    inline void addMatrix(const Matrix<row, col, T>& matrix) // add a matrix to the container
    {
        array[size_arr++] = matrix; // add the matrix to the next free element and update size 
        if (size_arr == capacity_arr) fixArray(); //array is full, double it and copy the elements
    }

    inline void removeLastMatrix() // removing the last matrix from the container
    {
        if(size_arr==0) return; // if the container if empty 
        if (--size_arr == (capacity_arr / 4)) fixArray();
    }

    inline int size() const // return the amount of matrices in the container
    {
        return size_arr;
    }

    inline int capacity() const // return the size of the dynamic array
    {
        return capacity_arr;
    }

    // ----------------------------------- help func
    inline void fixArray()
    {
        int new_capacity = (size_arr == capacity_arr) ? (2 * capacity_arr) : (capacity_arr / 2); // checks if the array is full or 1/4 
        Matrix<row, col, T>* new_arr = new Matrix<row, col, T>[new_capacity]; // create new array
        for (int i = 0; i < size_arr; i++) new_arr[i] = array[i]; // copy elements 
        delete[] array; // delete old array memory
        array = new_arr; // update feild array
        capacity_arr = new_capacity; // update capacity array
    }

    // ----------------------------------- operators
    // operator []
    inline Matrix<row, col, T>& operator[] (const int& index) // return a reference to the matrix at the index.
    {
        return array[index];
    }

    // operator <<   
    template <int rows, int cols, typename Ts>
    inline friend ostream& operator<<(ostream& output, const MatrixContainer<rows, cols, Ts>& other); // declaration as a friend 
};

template <int rows, int cols, typename Ts>
inline ostream& operator<<(ostream& output, const MatrixContainer<rows, cols, Ts>& other) // operator << implementation
{
    cout << "There are " << other.size() << " matrices in the container. The matrices:" << std::endl ;
    for (int i = 0; i < other.size(); i++) output << other.array[i] << std::endl; ; // print all matrices
    return output;
}