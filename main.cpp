#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "matrix.h"
using namespace std;

#define M 10
#define K 7
#define N 5

int main()
{
	Matrix* A = new Matrix(M, K);
	Matrix* B = new Matrix(K, N);
	Matrix* C = new Matrix(M, N);
	A->initData(0, 10);
	B->initData(0, 5);
	cout << "A：" << endl;
	cout << *A << endl;
	cout << "B：" << endl;
	cout << *B << endl;

	*C = *A * *B;
	cout << "C：" << endl;
	cout << *C << endl;

	Matrix* D = new Matrix(M, K);
	float b = 2.0;
	*D = *A * b;
	cout << "D：" << endl;
	cout << *D << endl;

	Matrix* E = new Matrix(M, K);
	float a = 2.0;
	*E = a * *A;
	cout << "E：" << endl;
	cout << *E << endl;

	Matrix* F = new Matrix(2, 2);
	Matrix* G = new Matrix(2, 3);
	cout << "请输入F和G矩阵:" << endl;
	cin >>  *F >> *G;
	if (*F == *G)
		cout << "两个矩阵不同" << endl;
	if (*F != *G)
		cout << "两个矩阵相同" << endl;

	Matrix* mat1 = new Matrix(M, N);
	Matrix* mat2 = new Matrix(M, N);
	Matrix* mat3 = new Matrix(M, N);
	mat1->initData(0, 10);
	mat2->initData(0, 50);
	*mat3 = *mat1 + *mat2;
	cout << "mat1：" << endl;
	cout << *mat1 << endl;
	cout << "mat2：" << endl;
	cout << *mat2 << endl;
	cout << "mat1+mat2：" << endl;
	cout << *mat3 << endl;

	delete A, B, C, D, E, F, G, mat1, mat2, mat3;
	return 0;
}