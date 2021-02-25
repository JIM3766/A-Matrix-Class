#include <iostream>
#include "matrix.h"
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

//创建矩阵
Matrix::Matrix(int row, int col)
{
    if (col < 0 || row < 0)//不能传入负数
    {
        cout << "error matrix!\n";
        col = row = 0;
        return;
    }
    cols = col;
    rows = row;
    data = new float* [row];
    for (int i = 0; i < row; i++)
    {
        data[i] = new float[col];
    }
}

//复制构造函数
Matrix::Matrix(Matrix& B)
{
    cols = B.cols;
    rows = B.rows;
    data = new float* [rows];
    for (int i = 0; i < rows; i++)
    {
        data[i] = new float[cols];
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = B.data[i][j];
        }
    }
}


//重载<<运算符
ostream& operator <<(ostream& ostr, const Matrix& m)
{
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
            ostr << setw(4) << m.data[i][j] << " ";
        ostr << '\n';
    }
    ostr << '\n';
    return ostr;
}

//重载>>运算符
istream& operator >>(istream& istr, const Matrix& m)
{
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            istr >> m.data[i][j];
        }
    }
    return istr;
}

//重载+运算符
Matrix& Matrix::operator + (const Matrix& B)
{
    if (B.rows != rows || B.cols != cols)//矩阵大小不一样
    {
        cout << "The two matrixs can't do the operation!\n";
        //return Matrix();//返回空矩阵
    }
    Matrix* C = new Matrix(rows, cols);
    //new的东西是在堆里面,函数结束不会被删除
    Matrix& Re = *C;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            C->data[i][j] = data[i][j] + B.data[i][j];
        }
    }  
    return Re;//传引用就不会调用构造函数，节省开销
}

//重载-运算符
Matrix& Matrix::operator - (const Matrix& B)
{
    if (B.rows != rows || B.cols != cols)//矩阵大小不一样
    {
        cout << "The two matrixs can't do the operation!\n";
        //return Matrix();//返回空矩阵
    }
    Matrix* C = new Matrix(rows, cols);
    //new的东西是在堆里面,函数结束不会被删除
    Matrix& Re = *C;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            C->data[i][j] = data[i][j] - B.data[i][j];
        }
    }
    return Re;//传引用就不会调用构造函数，节省开销
}

//重载=运算符
Matrix& Matrix::operator=(const Matrix& B)
{
    if (this != &B)//防止自赋值
    {
        if (data != NULL)
            delete data;
        cols = B.cols;
        rows = B.rows;
        data = new float* [rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new float[cols];
        }//重新开辟内存
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = B.data[i][j];
            }
        }
    }
    return *this;
}

//析构函数
Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
    cout << "析构函数已调用" << endl;
}

//重载矩阵乘法运算符
Matrix& Matrix::operator * (const Matrix& B)
{
    Matrix* C = new Matrix(rows, B.cols);
    if (cols == B.rows)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < B.cols; j++)
            {
                float sum = 0;
                for (int k = 0; k < cols; k++)
                {
                    sum += data[i][k] * B.data[k][j];
                }
                C->data[i][j] = sum;
            }
        }
        Matrix& Re = *C;
        return Re;
    }
    else
    {
        cout << "定义的矩阵有误" << endl;
    }
}

Matrix& Matrix::operator * (float b)
{
    Matrix* C = new Matrix(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            C->data[i][j] = b * data[i][j];
        }
    }
    Matrix& Re = *C;
    return Re;
}

Matrix& operator * (float a, const Matrix& B)
{
    Matrix* C = new Matrix(B.rows, B.cols);
    for (int i = 0; i < B.rows; i++)
    {
        for (int j = 0; j < B.cols; j++)
        {
            C->data[i][j] = a * B.data[i][j];
        }
    }
    Matrix& Re = *C;
    return Re;
}

//随机初始化矩阵
Matrix& Matrix::initData(float n, float m)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = (float) (n + (float)(rand()) / RAND_MAX * (m - n));
        }
    }
    return *this;
}

//重载==运算符
bool operator == (const Matrix& A, const Matrix& B)
{
    if (A.rows == B.rows || A.cols == B.cols)
    {
        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < A.cols; j++)
            {
                if (A.data[i][j] != B.data[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

//重载!=运算符
bool operator != (const Matrix& A, const Matrix& B)
{
    if (A.rows == B.rows || A.cols == B.cols)
    {
        for (int i = 0; i < A.rows; i++)
        {
            for (int j = 0; j < A.cols; j++)
            {
                if (A.data[i][j] != B.data[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    }
    else
    {
        return true;
    }
}