#include <iostream>
#include <cassert>

using namespace std;

struct Matrix {
	int n;
	int m;

	int data[101][101];
};

void enterMatrix(Matrix& matrix) {
	int n;
	int m;
    
    cout << "Enter row count: ";
	cin >> n;
    cout << "Enter column count: ";
	cin >> m;

	matrix.n = n;
	matrix.m = m;

    cout << "Enter the matrix itself\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matrix.data[i][j];
		}
	}
}

void printMatrix(const Matrix& matrix) {
	for (int i = 0; i < matrix.n; i++)
	{
		for (int j = 0; j < matrix.m; j++)
		{
			cout << matrix.data[i][j] << ' ';
		}
		cout << '\n';
	}
}

Matrix addMatrices(const Matrix& a, const Matrix& b) {
	assert(a.m == b.m);
	assert(a.n == b.n);

	Matrix result = a;
	for (int i = 0; i < a.n; i++)
	{
		for (int j = 0; j < a.m; j++)
		{
			result.data[i][j] += b.data[i][j];
		}
	}
	return result;
}

Matrix transposeMatrix(const Matrix& matrix) {
	Matrix result;
	result.n = matrix.m;
	result.m = matrix.n;

	for (int i = 0; i < matrix.n; i++)
	{
		for (int j = 0; j < matrix.m; j++)
		{
			result.data[j][i] = matrix.data[i][j];
		}
	}
	return result;
}


int main() {
    // Важно, така направена матрицата се използва място от 
    // стековата рамка за поне 2*sizeof(int) (за m и n) + 101*101*sizeof(int)
    // за всяка една матрица независимо дали е голяма или малка.
    Matrix m;
    enterMatrix(m);

    //printMatrix(m);

    cout << "Transposed matrix: \n";
    printMatrix(transposeMatrix(m));

    Matrix toBeAdded;
    enterMatrix(toBeAdded);
    cout << "Sum of te previously entered matrices: \n";
    printMatrix(addMatrices(m, toBeAdded));

    return 0;
}