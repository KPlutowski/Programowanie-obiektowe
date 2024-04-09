#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(const size_t rows, const size_t cols) : rows(rows), cols(cols)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            matrix[i][j] = nullptr;
}
SparseMatrix::SparseMatrix(const SparseMatrix &other)
{
    copy(other);
}
SparseMatrix::SparseMatrix(SparseMatrix &&other)
{
    move(std::move(other));
}
SparseMatrix::~SparseMatrix()
{
    clear();
}

void SparseMatrix::insert(const size_t row, const size_t col, int *value)
{
    matrix[row][col] = value;
}
void SparseMatrix::reset(const size_t row, const size_t col)
{
    delete matrix[row][col];
    matrix[row][col] = nullptr;
}

std::unordered_map<int, int *> &SparseMatrix::operator[](const size_t row)
{
    std::cout << "non-const\n";
    return matrix.at(row);
}

std::ostream &operator<<(std::ostream &os, const SparseMatrix &matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            if (matrix.matrix.at(i).at(j))
                os << *matrix.matrix.at(i).at(j) << ' ';
            else
                os << 0 << ' ';
        }
        os << '\n';
    }
    return os;
}

void SparseMatrix::copy(const SparseMatrix &other)
{
    rows = other.rows;
    cols = other.cols;
    matrix = other.matrix;
    for (auto &row : matrix)
    {
        for (auto &element : row.second)
        {
            if (element.second)
                element.second = new int(*element.second);
        }
    }
}
void SparseMatrix::move(SparseMatrix &&other)
{
    rows = other.rows;
    cols = other.cols;
    matrix = std::move(other.matrix);
    other.rows = 0;
    other.cols = 0;
}
void SparseMatrix::clear()
{
    for (auto &row : matrix)
    {
        for (auto &element : row.second)
        {
            delete element.second;
        }
    }
}
