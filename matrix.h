#pragma once
#include <iomanip>
using namespace std;

class Matrix
{
private:
	int cols;
	int rows;
	float** data;
public:
    Matrix() :cols(0), rows(0), data(0) {};
    Matrix(Matrix&);
    Matrix(int row, int col);
    Matrix& initData(float n, float m); //使用者可以自定义初始化数据的范围
    friend ostream& operator <<(ostream&, const Matrix&);
    friend istream& operator >>(istream&, const Matrix&);
    Matrix& operator + (const Matrix&);
    Matrix& operator - (const Matrix&);
    Matrix& operator = (const Matrix&);
    Matrix& operator * (const Matrix&);
    Matrix& operator * (float a);
    friend Matrix& operator * (float a, const Matrix& B);
    friend bool operator == (const Matrix& A, const Matrix& B);
    friend bool operator != (const Matrix& A, const Matrix& B);
    ~Matrix();
};

