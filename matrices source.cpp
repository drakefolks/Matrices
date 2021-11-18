#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int main()
{
	int row1 = 0, column1 = 0;
	int row2 = 0, column2 = 0;
	vector <vector<double>> matrix1;
	vector <vector<double>> matrix2;
	vector <vector<double>> matrix3;

	cout << "Please enter matrix one dimensions (rows and columns)\n";
	cout << "Enter your row count\n";
	cin >> row1;
	cout << "Enter your column count\n";
	cin >> column1;

	cout << "Please enter matrix two dimensions (rows and columns)\n";
	cout << "Enter your row count\n";
	cin >> row2;
	cout << "Enter your column count\n";
	cin >> column2;

	matrix1.resize(row1, vector<double>(column1));
	matrix2.resize(row2, vector<double>(column2));

	if (row1 == row2 && column1 == column2)
	{
		cout << "Proceed to addition\n";

		cout << "\nEnter elements of first matrix\n";
		for (int i = 0; i < row1; i++)
		{
			for (int q = 0; q < column1; q++)
			{
				cout << "Row " << (i + 1) << " column " << (q + 1) << endl;
				cin >> matrix1[i][q];
			}
		}

		cout << "\nEnter elements of second matrix\n";
		for (int i = 0; i < row2; i++)
		{
			for (int q = 0; q < column2; q++)
			{
				cout << "Row " << (i + 1) << " column " << (q + 1) << endl;
				cin >> matrix2[i][q];
			}
		}

		cout << "\nAdding:\n";
		for (int i = 0; i < row1; i++)
		{
			for (int q = 0; q < column1; q++)
			{
				cout << setw(2) << matrix1[i][q] << "+" << matrix2[i][q] << setw(2) << " ";
				
				if (q == column1 - 1)
				{
					cout << "\n";
				}
			}
		}

		cout << "\nTotal:\n";
		for (int i = 0; i < row1; i++)
		{
			for (int q = 0; q < column1; q++)
			{
				cout << setw(2) << matrix1[i][q] + matrix2[i][q] << setw(2) << " ";

				if (q == column1 - 1)
				{
					cout << "\n";
				}
			}
		}
	}


	else if (column1 == row2)
	{
		
		//whenever the row count of the second one is < the first one you get a range error.
		double matrix3_row = row1;
		double matrix3_column = column2;

		matrix3.resize(matrix3_row, vector<double>(matrix3_column));

		string ans;
		cout << "These matrices can be multiplied.\n";
		cout << "Proceed to multiplication?(y or n)\n";
		cin >> ans;

		if (ans == "n" || ans == "N" || ans == "No" || ans == "no")
		{
			exit;
		}

		else
		{
			
			cout << "\nEnter elements of first matrix\n";
			for (int i = 0; i < row1; i++)
			{
				for (int q = 0; q < column1; q++)
				{
					cout << "Row " << (i) << " column " << (q) << endl;
					cin >> matrix1[i][q];
				}
			}

			cout << "\nEnter elements of second matrix\n";
			for (int i = 0; i < row2; i++)
			{
				for (int q = 0; q < column2; q++)
				{
					cout << "Row " << (i ) << " column " << (q ) << endl;
					cin >> matrix2[i][q];
				}
			}
			/*
			double sum1 = (matrix1[0][0] * matrix2[0][0]) + (matrix1[0][1] * matrix2[1][0]);
			double sum2 = (matrix1[0][0] * matrix2[0][1]) + (matrix1[0][1] * matrix2[1][1]);
			double sum3 = (matrix1[1][0] * matrix2[0][0]) + (matrix1[1][1] * matrix2[1][0]);
			double sum4 = (matrix1[1][0] * matrix2[0][1]) + (matrix1[1][1] * matrix2[1][1]);
			double sum5 = (matrix1[2][0] * matrix2[0][0]) + (matrix1[2][1] * matrix2[1][0]);
			double sum6 = (matrix1[2][0] * matrix2[0][1]) + (matrix1[2][1] * matrix2[1][1]);

			cout << "sum is " << sum1 << endl;
			cout << "sum is " << sum2 << endl;
			cout << "sum is " << sum3 << endl;
			cout << "sum is " << sum4 << endl;
			cout << "sum is " << sum5 << endl;
			cout << "sum is " << sum6 << endl;
			*/

			
			int b = 0;
			for (int a = 0; a < row1; a++)
			{
				for (int b = 0; b < column2; b++)
				{
					for (int c = 0; c < column1; c++)
					{
						matrix3[a][b] += matrix1[a][c] * matrix2[c][b];
					}
				}
			}
			
			cout << "\nTwo matrices multiplied together:\n";
			for (int i = 0; i < matrix3_row; i++)
			{
				for (int q = 0; q < matrix3_column; q++)
				{
					cout << setw(2) << matrix3[i][q] << setw(2) << " ";

					if (q == matrix3_column - 1)
					{
						cout << "\n";
					}
				}
			}
			
		}
	}

	else
	{
		cout << "\nCannot add these two matrices or you cannot multiply them.\n";
	}

}