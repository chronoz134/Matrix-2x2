#include <iostream>
#include <string.h>
using namespace std;

struct Matrix{
	double r1c1 = 0,
				 r1c2 = 0,
				 r2c1 = 0,
				 r2c2 = 0;
	};

Matrix get_Matrix(Matrix & name, double m1=0, double m2=0, double m3=0,double m4=0){
	cout << "Please enter an integer for a11 of the matrix" << endl;
	cin >> name.r1c1;
	cout << "Please enter an integer for a12 of the matrix" << endl;
	cin >> name.r1c2;
	cout << "Please enter an integer for a21 of the matrix" << endl;
	cin >> name.r2c1;
	cout << "Please enter an integer for a22 of the matrix" << endl;
	cin >> name.r2c2;
	return name;
}
int get_scalar(int &x){
	cout << "Please enter an integer for the scalar value" << endl;
	cin >> x;
	return x;
}
Matrix calc_sum(Matrix m1, Matrix m2, Matrix &sum){
	Matrix total;
	total.r1c1 = m1.r1c1 + m2.r1c1;
	total.r1c2 = m1.r1c2 + m2.r1c2;
	total.r2c1 = m1.r2c1 + m2.r2c1;
	total.r2c2 = m1.r2c2 + m2.r2c2;
	sum = total;
	return sum;
}
Matrix calc_diff(Matrix m1, Matrix m2, Matrix &diff){
	diff.r1c1 = m1.r1c1 - m2.r1c1;
	diff.r1c1 = m1.r1c2 - m2.r1c2;
	diff.r1c1 = m1.r2c1 - m2.r2c1;
	diff.r1c1 = m1.r2c2 - m2.r2c2;
	return diff;
}
Matrix scalar_mult(int k, Matrix m1, Matrix &result){
	result.r1c1 = k * m1.r1c1;
	result.r1c2 = k * m1.r1c2;
	result.r2c1 = k * m1.r2c1;
	result.r2c2 = k * m1.r2c2;
	return result;
}
Matrix calc_prod(Matrix m1, Matrix m2, Matrix &result){
	result.r1c1 = (m1.r1c1 * m2.r1c1) + (m1.r1c2 * m2.r2c1);
	result.r1c2 = (m1.r1c1 * m2.r1c2) + (m1.r1c2 * m2.r2c2);
	result.r2c1 = (m1.r2c1 * m2.r1c1) + (m1.r2c2 * m2.r2c1);
	result.r2c2 = (m1.r2c1 * m2.r1c2) + (m1.r2c2 * m2.r2c2);
	return result;
}
Matrix calc_inv(Matrix m, Matrix &m_inv){
	int determinant = (m.r1c1 * m.r2c2) - (m.r2c1 * m.r1c2);
	m_inv.r1c1 = m.r2c2 / determinant;
	m_inv.r1c2 = (-1 * m.r1c2) / determinant;
	m_inv.r2c1 = (-1 * m.r2c1) / determinant;
	m_inv.r2c2 = m.r1c1 / determinant;
	return m_inv;
}
void printMatrix(Matrix m){
	cout << "{  " << m.r1c1 << "    " << m.r1c2 << "     }" << endl;
	cout <<"{   " << m.r2c1 << "    " << m.r2c2 << "     }" << endl;
	cout << "end" << endl;
}
int main() {
  Matrix m1;
	Matrix m2;
	Matrix added;
	Matrix diff;
	Matrix prod;
	Matrix m_inv;
	Matrix scalar;
	int scalval;

	get_scalar(scalval);
	get_Matrix(m1);
	get_Matrix(m2);
	printMatrix(m1);
	printMatrix(m2);
	calc_sum(m1,m2,added);
	calc_prod(m1,m2,prod);
	calc_diff(m1,m2,diff);
	calc_inv(m1,m_inv);
	scalar_mult(scalval,m1, scalar);
	cout << "This is the sum" << endl;
	printMatrix(added);
	cout << endl;
	cout <<"This is the prod" << endl;
	printMatrix(prod);
	cout << endl << "This is the diff" << endl;
	printMatrix(diff);
	cout << endl << "This is the inverse" << endl;
	printMatrix(m_inv);
	cout << endl << "This is the scalar" << endl;
	printMatrix(scalar);
	

	return 0;
}