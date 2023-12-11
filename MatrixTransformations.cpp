#include "MatrixTransformations.h"

namespace Matrices
{
	RotationMatrix::RotationMatrix(double theta)
		: Matrix(2, 2)
	{
		a.at(0).at(0) = cos(theta);
		a.at(0).at(1) = -1 * (sin(theta));
		a.at(1).at(0) = sin(theta);
		a.at(1).at(1) = cos(theta);
	}

	ScalingMatrix::ScalingMatrix(double scale)
		: Matrix(2, 2)
	{
		a.at(0).at(0) = scale;
		a.at(0).at(1) = 0;
		a.at(1).at(0) = 0;
		a.at(1).at(1) = scale;
	}

	TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols)
		: Matrix(2, nCols)
	{
		for (int i = 0; i < nCols; i++)
		{
			a.at(0).at(i) = xShift;
			a.at(1).at(i) = yShift;
		}
	}
}