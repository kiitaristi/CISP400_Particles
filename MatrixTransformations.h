#pragma once

#include "Matrices.h"

namespace Matrices
{
	class RotationMatrix : public Matrix
	{
	public:
		RotationMatrix(double theta);
	};

	class ScalingMatrix : public Matrix
	{
	public:
		ScalingMatrix(double scale);
	};

	class TranslationMatrix : public Matrix
	{
	public:
		TranslationMatrix(double xShift, double yShift, int nCols);
	};
}
