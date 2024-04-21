#pragma once

struct MatrixTerm
{
	int row;
	int col;
	float value;
};

class SparseMatrix
{
public:
	SparseMatrix(int num_rows, int num_cols, int capacity);

	SparseMatrix(const SparseMatrix& b);

	~SparseMatrix();

	void SetValue(int row, int col, float value);

	float GetValue(int row, int col) const;

	SparseMatrix Transpose();

	void PrintTerms();
	void Print();;

private:
	MatrixTerm* terms_ = nullptr;
	int num_rows_ = 0;
	int num_cols_ = 0;
	int capacity_ = 0;
	int num_terms_ = 0;
};