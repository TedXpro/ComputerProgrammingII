#include <iostream>
#include <vector>

using namespace std;

void performOperations(vector<vector<int>>, vector<vector<int>>, int, int);

int main()
{
    int row, col;
    cout << "Enter the row of the matrix: ";
    cin >> row;
    cout << "Enter the column of the matrix: ";
    cin >> col;
    vector<vector<int>> matrix1, matrix2;
    for (int index = 1; index <= 2; index++)
    {
        cout << "\t\tEnter the elements of matrix" << index << endl;
        string letter;
        if (index == 1)
            letter = "first";
        else
            letter = "second";

        for (int i = 0; i < row; i++)
        {
            vector<int> m;
            cout << "Enter the " << (i + 1) << "th row of the " << letter << " matrix.\n";
            for (int j = 0; j < col; j++)
            {
                int num;
                cout << "Enter element #" << i << j << ": ";
                cin >> num;
                m.push_back(num);
            }
            if (index == 1)
                matrix1.push_back(m);
            else
                matrix2.push_back(m);
        }
    }

    performOperations(matrix1, matrix2, row, col);

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << matrix1[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << matrix2[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

/**
 * This function will perform Addition, Subtraction and multiplication
 * on the two matrices.
 *
 * @param mat1 holds the address of the first matrix.
 * @param mat2 holds the address of the second matrix.
 * @param row holds the row of the matrices.
 * @param col holds the column of the matrices.
 */
void performOperations(vector<vector<int>> mat1, vector<vector<int>> mat2, int row, int col)
{
    for (int index = 1; index <= 2; index++)
    {
        if (index == 1)
            cout << "A + B:\n";
        else
            cout << "A - B:\n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (index == 1)
                    cout << mat1[i][j] + mat2[i][j] << " ";
                else
                    cout << mat1[i][j] - mat2[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<vector<int>> product;
    for (int i = 0; i < row; i++)
    {        
        for (int j = 0; j < col; j++)
        {
            vector<int> pro;
            int num = 0;
            for (int k = 0; k < col; k++)
                num += mat1[i][k] * mat2[k][j];

            pro.push_back(num);
            product.push_back(pro);
        }
    }

    cout << "AB:\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }
}