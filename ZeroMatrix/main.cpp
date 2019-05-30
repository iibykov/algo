#include <iostream>
#include <vector>
#include <random>

using namespace std;

void nullifyRow(vector< vector<int> > &matrix, size_t row)
{
    for (size_t j = 0; j < matrix[0].size(); j++)
        matrix[row][j] = 0;
}

void nullifyColumn(vector< vector<int> > &matrix, size_t col)
{
    for (size_t i= 0; i < matrix.size(); i++)
        matrix[i][col] = 0;
}

void setZeros(vector< vector<int> > &matrix)
{
    bool rowHasZero = false;
    bool colHasZero = false;

    // Check if first row has a zero
    for (size_t j = 0; j < matrix[0].size(); ++j)
    {
        if (matrix[0][j] == 0)
        {
            rowHasZero = true;
            break;
        }
    }

    // Check if first column has a zero
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        if (matrix[i][0] == 0)
        {
            colHasZero = true;
            break;
        }
    }

    // Check for zeros in the rest of the array
    for (size_t i= 1; i < matrix.size(); ++i)
    {
        for (size_t j = 1; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Nullify rows based on values in first column
    for (size_t i= 1; i < matrix.size(); ++i)
    {
        if (matrix[i][0] == 0)
        {
            nullifyRow(matrix, i);
        }
    }

    // Nullify columns based on values in first row
    for (size_t j = 1; j < matrix[0].size(); ++j)
    {
        if (matrix[0][j] == 0)
        {
            nullifyColumn(matrix, j);
        }
    }

    // Nullify first row
    if (rowHasZero)
        nullifyRow(matrix, 0);

    // Nullify first column
    if (colHasZero)
    nullifyColumn(matrix, 0);
}

void printMatrix(const vector< vector<int> > &matrix)
{
    cout <<  endl;
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            cout << matrix[i][j] << "\t";
        }

        cout <<  endl;
    }
}

int main()
{
    const int n = 8;
    const int m = 8;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, n * m / 2);

    vector< vector<int> > matrix(n);
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            matrix[i].push_back(distribution(generator));

    printMatrix(matrix);
    setZeros(matrix);
    printMatrix(matrix);

    return 0;
}
