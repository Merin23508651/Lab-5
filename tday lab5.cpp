[5:11 PM] MD.SHAMSUL ALAM
#include <bits/stdc++.h>

using namespace std;

void print(int **p, int row, int col)

{

    for (int i = 0; i < row; i++)

    {

        for (int j = 0; j < col; j++)

        {

            cout << p[i][j] << " ";

        }

        cout << endl;

    }

    cout << "--------------------" << endl;

}

int **create(int row, int col)

{

    int **m = new int *[row];

    for (int i = 0; i < row; i++)

    {

        m[i] = new int[col];

    }

    srand(time(0));

    for (int i = 0; i < row; i++)

    {

        for (int j = 0; j < col; j++)

        {

            m[i][j] = rand() % 10;

        }

    }

    return m;

}

int **sumMatrix(int **a, int **b, int row, int col)

{

    int **c = new int *[row];

    for (int i = 0; i < row; i++)

    {

        c[i] = new int[col];

    }

    for (int i = 0; i < row; i++)

    {

        for (int j = 0; j < col; j++)

        {

            c[i][j] = a[i][j] + b[i][j];

        }

    }

    return c;

}

int main()

{

    int row = 4;

    int col = 5;

    int **m = create(row, col);

    print(m, row, col);

    int **m1 = create(row, col);

    print(m1, row, col);

    int **m2 = sumMatrix(m, m1, row, col);

    print(m2, row, col);


    return 0;

}
