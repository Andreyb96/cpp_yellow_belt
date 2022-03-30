#include <iostream>
#include <cassert>
#include <ostream>
#include <vector>

class Matrix
{
public:
	Matrix() {}

	Matrix(int rows, int cols) :
		_rows(rows)
		, _cols(cols)
	{
		if (rows < 0 || cols < 0)
		{
			throw std::out_of_range("Rows or cols is negative");
		}
		for (auto i = 0; i < _rows; i++)
		{
			_mat.push_back(std::vector<int>(_cols, 0));
		}
	}

	void Reset(int newRows, int newCols)
	{
		if (newRows < 0 || newCols < 0)
		{
			throw std::out_of_range("Rows or cols is negative");
		}

		_rows = newRows;
		_cols = newCols;
		_mat.clear();
		for (auto i = 0; i < _rows; i++)
		{
			_mat.push_back(std::vector<int>(_cols, 0));
		}
	}

	int At(int rowIdx, int colIdx) const
	{
		if (rowIdx < 0 || colIdx < 0 || rowIdx >= _rows || colIdx >= _cols)
		{
			throw std::out_of_range("Row or col idx out of range");
		}

		return _mat.at(rowIdx).at(colIdx);
	}

	int& At(int rowIdx, int colIdx)
	{
		if (rowIdx < 0 || colIdx < 0 || rowIdx >= _rows || colIdx >= _cols)
		{
			throw std::out_of_range("Row or col idx out of range");
		}

		return _mat.at(rowIdx).at(colIdx);
	}

	int GetNumRows() const
	{
		return _rows;
	}

	int GetNumColumns() const
	{
		return _cols;
	}
private:
	int _rows = 0;
	int _cols = 0;
	std::vector<std::vector<int>> _mat;
};

std::ostream& operator<<(std::ostream &out, Matrix mat)
{
	out << mat.GetNumRows() << " " << mat.GetNumColumns() << "\n";
	for (auto i = 0; i < mat.GetNumRows(); i++)
	{
		for (auto j = 0; j < mat.GetNumColumns(); j++)
		{
			out << mat.At(i, j) << " ";
		}
		out << "\n";
	}
	return out;
}

std::istream& operator>>(std::istream &in, Matrix& mat)
{
	int rows, cols;
	in >> rows >> cols;
	mat = Matrix(rows, cols);
	for (auto i = 0; i < rows; i++)
	{
		for (auto j = 0; j < cols; j++)
		{
			in >> mat.At(i, j);
		}
	}

	return in;
}

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
	if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns())
	{
		return false;
	}

	for (auto i = 0; i < lhs.GetNumRows(); i++)
	{
		for (auto j = 0; j < lhs.GetNumColumns(); j++)
		{
			if (lhs.At(i, j) != rhs.At(i, j))
			{
				return false;
			}
		}
	}

	return true;
}

Matrix operator+(Matrix lhs, const Matrix& rhs)
{
	Matrix result;

	if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns())
	{
		throw std::out_of_range("Matrices are of different dimensions");
	}

	result = Matrix(lhs.GetNumRows(), lhs.GetNumColumns());

	for (auto i = 0; i < lhs.GetNumRows(); i++)
	{
		for (auto j = 0; j < lhs.GetNumColumns(); j++)
		{
			result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
		}
	}

	return result;
}

int main() {
	Matrix one;
	Matrix two;

	std::cin >> one >> two;
	std::cout << one + two << std::endl;
	return 0;
}