#pragma once

#include <vector>
#include <unordered_map>
#include <utility>
#include<iostream>
#include <memory>

class SparseMatrix
{
private:
    std::unordered_map<int,std::unordered_map<int,int*>> matrix;
    size_t rows;
    size_t cols;

    void copy(const SparseMatrix &other);
    void move(SparseMatrix &&other);
    void clear();

public:
    SparseMatrix(const size_t rows,const size_t cols);
    ~SparseMatrix();
    SparseMatrix(SparseMatrix&& other);
    SparseMatrix(const SparseMatrix& other);

    void insert(const size_t row, const size_t col,int* value);
    void reset(const size_t row, const size_t col);

    std::unordered_map<int,int *>& operator[](const size_t row);
 
    friend std::ostream& operator<<(std::ostream& os,const SparseMatrix& matrix);
};

