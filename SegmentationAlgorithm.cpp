#include <iostream>

#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 3
#define EMPTY_CELL '-'
#define FILLED_CELL '#'

void printMatrix(char (*matrix)[MATRIX_WIDTH])
{
    for (int i = 0; i < MATRIX_HEIGHT; i++)
    {
        for (int j = 0; j < MATRIX_WIDTH; j++)
        {
            std::cout << matrix[i][j] << '\t';
        }

        std::cout << '\n';
    }
}

void printMatrix(int** matrix)
{
    for (int i = 0; i < MATRIX_HEIGHT; i++)
    {
        for (int j = 0; j < MATRIX_WIDTH; j++)
        {
            std::cout << matrix[i][j] << '\t';
        }

        std::cout << '\n';
    }
}

int** getGroupMatrix(char (*matrix)[MATRIX_WIDTH])
{
    int** groupMatrix = new int*[MATRIX_HEIGHT];

    for (int i = 0; i < MATRIX_HEIGHT; i++)
    {
        groupMatrix[i] = new int[MATRIX_WIDTH];

        for (int j = 0; j < MATRIX_WIDTH; j++)
        {
            groupMatrix[i][j] = 0;
        }
    }

    int group = 1;

    for (int i = 0; i < MATRIX_HEIGHT; i++)
    {
        for (int j = 0; j < MATRIX_WIDTH; j++)
        {
            if (matrix[i][j] == EMPTY_CELL)
            {
                continue;
            }

            if (i - 1 < 0 || j - 1 < 0 || (matrix[i - 1][j] == EMPTY_CELL && matrix[i][j - 1] == EMPTY_CELL))
            {
                groupMatrix[i][j] = group;
                group++;
            }
            else if (matrix[i - 1][j] == FILLED_CELL)
            {
                groupMatrix[i][j] = groupMatrix[i - 1][j];
            }
            else if (matrix[i][j - 1] == FILLED_CELL)
            {
                groupMatrix[i][j] = groupMatrix[i][j - 1];
            }
        }
    }

    return groupMatrix;
}

int main()
{
    char matrix[MATRIX_HEIGHT][MATRIX_WIDTH] = {
        {'#', '-', '-'},
        {'-', '#', '#'},
        {'#', '-', '#'}
    };

    std::cout << "Initial matrix:\n";
    printMatrix(matrix);

    int** groupMatrix = getGroupMatrix(matrix);

    std::cout << "\nGroup matrix:\n";
    printMatrix(groupMatrix);
}
