// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#define collection cin.tie(NULL);ios_base::sync_with_stdio(false);
using namespace std;
long long N, B;
int** A;
int** Answer;
int** Matrixmulti(int** matrixvalueA, int** matrixvalueB)
{
	long long** matrix = new long long* [N];
	int** intmatrix = new int* [N];
	for (int i = 0; i < N; i++)
	{
		matrix[i] = new long long[N];
		intmatrix[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = 0;
			intmatrix[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				matrix[i][j] += ((matrixvalueA[i][k]) * (matrixvalueB[k][j])) % 1000;
				matrix[i][j] %= 1000;
			}
			intmatrix[i][j] = (int)matrix[i][j];
		}
	}
	return intmatrix;
}
int** MatrixSquared(long long n)
{
	if (n == 1)
	{
		return A;
	}
	int** Matrix = MatrixSquared(n / 2);
	int** answermatrix;
	if (n % 2 == 0)
	{
		answermatrix = Matrixmulti(Matrix, Matrix);
	}
	else
	{
		answermatrix = Matrixmulti(Matrixmulti(Matrix, Matrix), A);
	}
	return answermatrix;
}
int main()
{
	collection
		cin >> N >> B;
	A = new int* [N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			A[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}
	Answer = MatrixSquared(B);
	string line = "";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			line += to_string(Answer[i][j] % 1000);
			line += ' ';
		}
		line += '\n';
	}
	cout << line;
}