#pragma once
#include <string>
#include <vector>
#include <exception>
#include <iosfwd>

template <class T>
class MatrixGeneric
{
private:
	size_t rows;
	size_t cols;
	std::vector<std::vector<T> > matrix;
public:
	MatrixGeneric(int _rows, int _cols)
	{
		rows = _rows;
		cols = _cols;
	}
};

typedef MatrixGeneric<double> MatrixD;