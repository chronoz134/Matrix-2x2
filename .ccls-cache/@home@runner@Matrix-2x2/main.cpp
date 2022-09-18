#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

struct Matrix {
  double r1c1 = 0, r1c2 = 0, r2c1 = 0, r2c2 = 0;
	string name;
};
int get_scalar(double &x) {
  cout << "Please enter an integer for the scalar value" << endl;
  cin >> x;
  return x;
}
Matrix calc_sum(Matrix m1, Matrix m2, Matrix &sum) {
  Matrix total;
  total.r1c1 = m1.r1c1 + m2.r1c1;
  total.r1c2 = m1.r1c2 + m2.r1c2;
  total.r2c1 = m1.r2c1 + m2.r2c1;
  total.r2c2 = m1.r2c2 + m2.r2c2;
  sum = total;
  return sum;
}
Matrix calc_diff(Matrix m1, Matrix m2, Matrix &diff) {
  diff.r1c1 = m1.r1c1 - m2.r1c1;
  diff.r1c1 = m1.r1c2 - m2.r1c2;
  diff.r1c1 = m1.r2c1 - m2.r2c1;
  diff.r1c1 = m1.r2c2 - m2.r2c2;
  return diff;
}
Matrix scalar_mult(double k, Matrix m1, Matrix &result) {
  result.r1c1 = k * m1.r1c1;
  result.r1c2 = k * m1.r1c2;
  result.r2c1 = k * m1.r2c1;
  result.r2c2 = k * m1.r2c2;
  return result;
}
Matrix calc_prod(Matrix m1, Matrix m2, Matrix &result) {
  result.r1c1 = (m1.r1c1 * m2.r1c1) + (m1.r1c2 * m2.r2c1);
  result.r1c2 = (m1.r1c1 * m2.r1c2) + (m1.r1c2 * m2.r2c2);
  result.r2c1 = (m1.r2c1 * m2.r1c1) + (m1.r2c2 * m2.r2c1);
  result.r2c2 = (m1.r2c1 * m2.r1c2) + (m1.r2c2 * m2.r2c2);
  return result;
}
Matrix calc_inv(Matrix m, Matrix &m_inv) {
  int determinant = (m.r1c1 * m.r2c2) - (m.r2c1 * m.r1c2);
  m_inv.r1c1 = m.r2c2 / determinant;
  m_inv.r1c2 = (-1 * m.r1c2) / determinant;
  m_inv.r2c1 = (-1 * m.r2c1) / determinant;
  m_inv.r2c2 = m.r1c1 / determinant;
  return m_inv;
}
void display_menu(string MENU){
  cout<<"\nWelcome! What would you like to calculate between the matrices?"<<endl
      <<"1. Sum"<<endl
      <<"2. Difference"<<endl
      <<"3. Scalar Multiple"<<endl
      <<"4. Product"<<endl
      <<"5. Inverse"<<endl
      <<"6. EXIT"<<endl;   
}  
int menu_selection(int &selection){
  cin>>selection;
  return selection;
}
void valid_selection(int &selection){ 
  while (selection < 1 || selection > 6){
    cout<<"\n**ERROR** Option not valid\n"
        <<"\nWelcome! What would you like to calculate between the matrices?"<<endl
        <<"1. Sum"<<endl
        <<"2. Difference"<<endl
        <<"3. Scalar Multiple"<<endl
        <<"4. Product"<<endl
        <<"5. Inverse"<<endl
        <<"6. EXIT"<<endl; 
        cin>>selection;
    }
  }
void out_selection(int &num){
  cout<<"Choose one of the following: (1)Print to Screen / (2)Print to Outfile / (3)Print to Both"<<endl;
  cin>>num;
}
void out_validation (int &num){
  while (num < 1 || num > 3){
    cout<<"\n**ERROR** Option not valid\n"
        <<"\nChoose one of the following: (1)Print to Screen / (2)Print to Outfile / (3)Print to Both"<<endl;
        cin>>num;
  }
}
void new_matrix_menu(int &select){
	cout <<"Do you want to enter a new scalar value and new matrices? Enter 0" << endl
			 <<"Do you wish to run another operation? Enter 1" << endl
			 <<"Enter 6 to end" << endl;
	cin >> select;
	
} 
void outfile_notif(int num){
	if (num == 2){
		cout <<"*******Result Printed to Outfile**********" << endl << endl;
	}
}
void out_print(int num, Matrix &m, string name, ofstream &outfile){
  switch (num){
    case 1:
      cout << fixed << setprecision(1);
	    cout << "This is the " << name <<endl;
      cout << setw(13) << left << "--" << setw(10) << left << setw(10) <<"--"<< endl;
      cout << left << "| " << m.r1c1 << setw(10) << right << setw(10) << m.r1c2 <<" |" <<  endl;
	    cout << left << "| "  << setw(10) << right << setw(13)  <<" |" << endl;
	    cout << left << "| " << m.r2c1 << setw(10) << right << setw(10) << m.r2c2 <<" |" << endl;
	    cout << setw(13) << left << "--" << setw(10) << left << setw(10) <<"--"<< endl;
      break;
    case 2:
      outfile << "This is the " << name <<endl;
      outfile << setw(13) << left << "--" << setw(10) << left << setw(10) <<"--"<< endl;
      outfile << left << "| " << m.r1c1 << setw(10) << right << setw(10) << m.r1c2 <<" |" << endl;
	    outfile << left << "| "  << setw(10) << right << setw(13)  <<" |" << endl;
	    outfile << left << "| " << m.r2c1 << setw(10) << right << setw(10) << m.r2c2 <<" |" << endl;
	    outfile << setw(13) << left << "--" << setw(10) << left << setw(10) <<"--"<< endl;
      break;
    case 3:
      cout << fixed << setprecision(1);
	    cout << "This is the " << name <<endl;
      cout << setw(13) << left << "--" << setw(10) << left << setw(10) <<"--"<< endl;
      cout << left << "| " << m.r1c1 << setw(10) << right << setw(10) << m.r1c2 <<" |" << endl;
	    cout << left << "| "  << setw(10) << right << setw(13)  <<" |" << endl;
	    cout << left << "| " << m.r2c1 << setw(10) << right << setw(10) << m.r2c2 <<" |" << endl;
	    cout << setw(13) << left << "--" << setw(10) << left << setw(10) <<"--"<< endl;

	    outfile << "This is the " << name <<endl;
      outfile << setw(13) << left << "--" << setw(10) << left << setw(10) <<"--"<< endl;
      outfile << left << "| " << m.r1c1 << setw(10) << right << setw(10) << m.r1c2 <<" |" << endl;
	    outfile << left << "| "  << setw(10) << right << setw(13)  <<" |" << endl;
	    outfile << left << "| " << m.r2c1 << setw(10) << right << setw(10) << m.r2c2 <<" |" << endl;
	    outfile << setw(13) << left << "--" << setw(10) << left << setw(10) <<"--"<< endl;
      break;
  }
}
Matrix get_Matrix(Matrix & matrix) {
	cout<< "Please Enter an appropriate name for the matrix" << endl;
	cin >> matrix.name;
  cout << "Please enter an integer for 1-1 of the matrix" << endl;
  cin >> matrix.r1c1;
  cout << "Please enter an integer for 1-2 of the matrix" << endl;
  cin >> matrix.r1c2;
  cout << "Please enter an integer for 2-1 of the matrix" << endl;
  cin >> matrix.r2c1;
  cout << "Please enter an integer for 2-2 of the matrix" << endl;
  cin >> matrix.r2c2;
  return matrix;
}

int main() {
  Matrix m1;
  Matrix m2;
  Matrix added;
  Matrix diff;
  Matrix prod;
  Matrix m_inv;
  Matrix scalar;
  double scalval;
  int select;
  int num;
  string menu;
	
	ofstream outfile;
	outfile.open("output.txt");

	do{
		get_scalar(scalval);
  	get_Matrix(m1);
  	get_Matrix(m2);
	  do{
			display_menu(menu);
			menu_selection(select);
  		valid_selection(select);
	    switch(select){
	      case 1:
	        calc_sum(m1, m2, added);
	        out_selection(num);
	        out_validation(num);
	        out_print(num, m1, m1.name,outfile);
	        out_print(num, m2, m2.name,outfile);
	        out_print(num, added, "SUM = ",outfile);
					outfile_notif(num);
					new_matrix_menu(select);
	        break;
	      case 2:
	        calc_diff(m1, m2, diff);
	        out_selection(num);
	        out_validation(num);
	        out_print(num, m1, m1.name,outfile);
	        out_print(num, m2, m2.name,outfile);
	        out_print(num, diff, "DIFFERENCE = ",outfile);
					outfile_notif(num);
					new_matrix_menu(select);
	      	break;
	      case 3:
	        scalar_mult(scalval, m1, scalar);
	        out_selection(num);
	        out_validation(num);
	        out_print(num, m1, m1.name,outfile);
	        out_print(num, m2, m2.name,outfile);
	        out_print(num, scalar, "SCALAR MULTIPLICATION = ",outfile);
					outfile_notif(num);
					new_matrix_menu(select);
	      	break;
	      case 4:
	        calc_prod(m1, m2, prod);
	        out_selection(num);
	        out_validation(num);
	        out_print(num, m1, m1.name,outfile);
	        out_print(num, m2, m2.name,outfile);
	        out_print(num, prod, "PRODUCT = ",outfile);
					outfile_notif(num);
					new_matrix_menu(select);
	      	break;
	      case 5:
	        calc_inv(m1, m_inv);
	        out_selection(num);
	        out_validation(num);
	        out_print(num, m1, m1.name,outfile);
	        out_print(num, m2, m2.name,outfile);
	        out_print(num, m_inv, "INVERSE = ",outfile);
					outfile_notif(num);
					new_matrix_menu(select);
	      	break;
	    	} 
  		}while (select >=1 && select <=5);
		}while(select != 6);

	
	outfile.close();
	cout<<"**Thank You for using our matrix calculator!**";
  return 0;
}