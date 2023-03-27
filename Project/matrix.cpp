/*      Name                ID
1. Newal Yeman          UGR/9108/14
2. Yigerem Bisrat       UGR//14
3. Yodahe Gossa         UGR/9595/14
4. Yoak Moges           UGR/3567/14
5. Yohannes Belay       UGR/4223/14
*/
#include <iostream>
#include <vector>

using namespace std;

void acceptMatrix(vector<vector<int>> *, vector<vector<int>> *, int, int, int, bool flag = true);
vector<vector<int>> performAddition(vector<vector<int>> *, vector<vector<int>> *, int, int, bool);
vector<vector<int>> performMultiplication(vector<vector<int>> *, vector<vector<int>> *, int, int, int);
void displayResult(vector<vector<int>> *, int, int);

int main()
{
    int choice;
    cout << "\tWelcome to Matrix Operations.\n";
    cout << "1. A + B\n";
    cout << "2. A - B\n";
    cout << "3. A * B\n";
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice > 3 || choice < 1)
    {
        cout << "Your choice must be between 1 - 3: ";
        cin >> choice;
    }

    int row, col;
    vector<vector<int>> matrix1, matrix2;
    if (choice == 1)
    {
        cout << "Enter the row of the matrices: ";
        cin >> row;
        cout << "Enter the column of the matirces: ";
        cin >> col;

        acceptMatrix(&matrix1, &matrix2, row, col,0);
        vector<vector<int>> sum = performAddition(&matrix1, &matrix2, row, col, true);
        displayResult(&sum, row, col);
    }
    else if (choice == 2)
    {
        cout << "Enter the row of the matrices: ";
        cin >> row;
        cout << "Enter the column of the matirces: ";
        cin >> col;

        acceptMatrix(&matrix1, &matrix2, row, col,0);
        vector<vector<int>> sum = performAddition(&matrix1, &matrix2, row, col, false);
        displayResult(&sum, row, col);
    }
    else
    {
        int row1, col1, row2, col2; // to holds the rows and columns of the two matrices.
        cout << "Enter row of the first matrix: ";
        cin >> row1;
        cout << "Enter the column of the first matrix: ";
        cin >> col1;
        // row2 = col1; // since the column of the first matrix must be equall to the second matrix.
        cout << "Enter the column of the second matrix: ";
        cin >> col2;
        acceptMatrix(&matrix1, &matrix2, row1, col1, col2, false);
        vector<vector<int>> product = performMultiplication(&matrix1, &matrix2, row1, col1, col2);

        displayResult(&product, row1, col2);
    }
}

/**
 * This function will accept the matrix elements.
 *
 * @param mat1 holds the elements of matrix 1.
 * @param mat2 holds the elements of matrix 2.
 * @param i holds the row of the matrices.
 * @param j holds the column of the matrices.
 */
void acceptMatrix(vector<vector<int>> *mat1, vector<vector<int>> *mat2, int i, int j, int k, bool flag)
{
    if (flag == true)
    {
        for (int index = 1; index <= 2; index++)
        {
            cout << "\t\tEnter the elements of matrix" << index << endl;
            string letter;
            if (index == 1)
                letter = "first";
            else
                letter = "second";

            for (int r = 0; r < i; r++)
            {
                vector<int> m;
                cout << "Enter the " << (r + 1) << "th row of the " << letter << " matrix.\n";
                for (int c = 0; c < j; c++)
                {
                    int num;
                    cout << "Enter element #" << r << c << ": ";
                    cin >> num;
                    m.push_back(num);
                }
                if (index == 1)
                    (*mat1).push_back(m);
                else
                    (*mat2).push_back(m);
            }
        }
    }
    else
    {
        cout << "Enter elements of the first matrix:\n";
        for (int r = 0; r < i; r++)
        {
            cout << "Enter elements of " << (r + 1) << "th row:\n";

            vector<int> m;
            for (int c = 0; c < j; c++)
            {
                int num;
                cout << "Enter " << r << c << " element: ";
                cin >> num;
                m.push_back(num);
            }
            (*mat1).push_back(m);
        }
        cout << "Enter elements of the second matrix:\n";
        for (int r = 0; r < j; r++)
        {
            cout << "Enter elements of " << (r + 1) << "th row:\n";
            vector<int> m;
            for (int c = 0; c < k; c++)
            {
                int num;
                cout << "Enter " << r << c << " element: ";
                cin >> num;
                m.push_back(num);
            }
            (*mat2).push_back(m);
        }
    }
}

/**
 * This function will perform matrix addition on two matrices.
 *
 * @param mat1 holds the elements of the first matrix.
 * @param mat2 holds the elements of the seconde matrix/
 * @param i holds the row of the matrices.
 * @param j holds the column fo the matrices.
 *
 * @return the sum or difference of the two matrices.
 */
vector<vector<int>> performAddition(vector<vector<int>> *mat1, vector<vector<int>> *mat2, int i, int j, bool flag)
{
    vector<vector<int>> sum;
    vector<int> s;

    for (int r = 0; r < i; r++)
    {
        for (int c = 0; c < j; c++)
        {
            int n;
            if (flag == true)
                n = (*mat1)[r][c] + (*mat2)[r][c];
            else
                n = (*mat1)[r][c] - (*mat2)[r][c];
            s.push_back(n);
        }
        sum.push_back(s);
    }
    return sum;
}

/**
 * This function will perform vector multiplication on the two matrices.
 *
 * @param mat1 will hold the elements of the first matrix.
 * @param mat2 will hold the elements of the second matrix.
 * @param r1 holds the row of the first matrix.
 * @param c1 holds the column of the first matrix.
 * @param r2 holds the row of the second matrix.
 * @param c2 holds the column of the second matrix.
 *
 * @return the vector product of the two matrices.
 */
vector<vector<int>> performMultiplication(vector<vector<int>> *mat1, vector<vector<int>> *mat2, int r1, int c1, int c2)
{
    vector<vector<int>> product;
    for (int i = 0; i < r1; i++)
    {
        vector<int> pro;
        for (int j = 0; j < c2; j++)
        {
            int num = 0;
            for (int k = 0; k < c1; k++)
            {
                num += ((*mat1)[i][k] * (*mat2)[k][j]);
            }
            pro.push_back(num);
        }
        product.push_back(pro);
    }
    return product;
}

/**
 * This function will display the result.
 *
 * @param matrix holds the elements of the result.
 * @param row holds the row of the result matrix.
 * @param col holds the column of the result matrix.
 */
void displayResult(vector<vector<int>> *matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << (*matrix)[i][j] << " ";
        cout << endl;
    }
}