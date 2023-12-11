#include "Matrices.h"

namespace Matrices
{
	Matrix::Matrix(int _rows, int _cols)
	{
		rows = _rows;
		cols = _cols;

		a.resize(rows, vector<double>(cols, 0));
	}

	Matrix operator+(const Matrix& a, const Matrix& b)
	{
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols()) { throw runtime_error("Error: dimensions must agree"); }

		Matrix c(a.getRows(), a.getCols());

		for (int i = 0; i < a.getRows(); i++)
		{
			for (int j = 0; j < a.getCols(); j++)
			{
				c(i, j) = a(i, j) + b(i, j);
			}
		}

		return c;
	}

	Matrix operator*(const Matrix& a, const Matrix& b)
	{

		if (a.getCols() != b.getRows()) { throw runtime_error("Error: dimensions must agree"); }

		Matrix c(a.getRows(), b.getCols());

		for (int i = 0; i < a.getRows(); i++)
		{
			for (int k = 0; k < b.getCols(); k++)
			{
				double elementaryProduct = 0.0;

				for (int j = 0; j < a.getCols(); j++)
				{
					elementaryProduct += a(i, j) * b(j, k);
				}

				c(i, k) = elementaryProduct;
			}
		}

		return c;
	}

	bool operator==(const Matrix& a, const Matrix& b)
	{
		bool isEqual = false;
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			isEqual = false;
		}
		else
		{
			for (int i = 0; i < a.getRows(); i++)
			{
				for (int j = 0; j < a.getCols(); j++)
				{
					if (abs(a(i, j) - b(i, j)) < 0.001)
					{
						isEqual = true;
					}
					else
					{
						isEqual = false;
						break;
					}
				}
			}
		}

		return isEqual;
	}

	bool operator!=(const Matrix& a, const Matrix& b)
	{
		bool isNotEqual = false;
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			isNotEqual = true;
		}
		else
		{
			for (int i = 0; i < a.getRows(); i++)
			{
				for (int j = 0; j < a.getCols(); j++)
				{
					if (abs(a(i, j) - b(i, j)) < 0.001)
					{
						isNotEqual = false;
					}
					else
					{
						isNotEqual = true;
						break;
					}
				}
			}
		}

		return isNotEqual;
	}

	ostream& operator<<(ostream& os, const Matrix& a)
	{
		for (int i = 0; i < a.getRows(); i++)
		{
			for (int j = 0; j < a.getCols(); j++)
			{
				os << setw(10) << a(i, j) << ' ';
			}

			os << '\n' << '\n';
		}

		return os;
	}
}