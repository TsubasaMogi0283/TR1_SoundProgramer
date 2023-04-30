#include <HeaderCpp/MatrixFunction/MatrixFunction.h>


Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2) {
	Matrix3x3 result;
	result.m[0][0] = (matrix1.m[0][0] * matrix2.m[0][0]) + (matrix1.m[0][1] * matrix2.m[1][0]) + (matrix1.m[0][2] * matrix2.m[2][0]);
	result.m[0][1] = (matrix1.m[0][0] * matrix2.m[0][1]) + (matrix1.m[0][1] * matrix2.m[1][1]) + (matrix1.m[0][2] * matrix2.m[2][1]);
	result.m[0][2] = (matrix1.m[0][0] * matrix2.m[0][2]) + (matrix1.m[0][1] * matrix2.m[1][2]) + (matrix1.m[0][2] * matrix2.m[2][2]);

	result.m[1][0] = (matrix1.m[1][0] * matrix2.m[0][0]) + (matrix1.m[1][1] * matrix2.m[1][0]) + (matrix1.m[1][2] * matrix2.m[2][0]);
	result.m[1][1] = (matrix1.m[1][0] * matrix2.m[0][1]) + (matrix1.m[1][1] * matrix2.m[1][1]) + (matrix1.m[1][2] * matrix2.m[2][1]);
	result.m[1][2] = (matrix1.m[1][0] * matrix2.m[0][2]) + (matrix1.m[1][1] * matrix2.m[1][2]) + (matrix1.m[1][2] * matrix2.m[2][2]);

	result.m[2][0] = (matrix1.m[2][0] * matrix2.m[0][0]) + (matrix1.m[2][1] * matrix2.m[1][0]) + (matrix1.m[2][2] * matrix2.m[2][0]);
	result.m[2][1] = (matrix1.m[2][0] * matrix2.m[0][1]) + (matrix1.m[2][1] * matrix2.m[1][1]) + (matrix1.m[2][2] * matrix2.m[2][1]);
	result.m[2][2] = (matrix1.m[2][0] * matrix2.m[0][2]) + (matrix1.m[2][1] * matrix2.m[1][2]) + (matrix1.m[2][2] * matrix2.m[2][2]);
	return result;
}


Matrix3x3 Inverse(Matrix3x3 matrix) {
	Matrix3x3 result;
	float determinant = matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] +
		matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] +
		matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1] -
		matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] -
		matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] -
		matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1];
	assert(determinant != 0.0f);
	float determinantRecp = 1.0f / determinant;

	result.m[0][0] = (matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1]) * determinantRecp;
	result.m[0][1] = -(matrix.m[0][1] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][1]) * determinantRecp;
	result.m[0][2] = (matrix.m[0][0] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][1]) * determinantRecp;

	result.m[1][0] = -(matrix.m[1][0] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][0]) * determinantRecp;
	result.m[1][1] = (matrix.m[0][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][0]) * determinantRecp;
	result.m[1][2] = -(matrix.m[0][0] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][0]) * determinantRecp;

	result.m[2][0] = (matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][0]) * determinantRecp;
	result.m[2][1] = -(matrix.m[0][0] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[2][0]) * determinantRecp;
	result.m[2][2] = (matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0]) * determinantRecp;

	return result;
}



Matrix3x3 MakeAffineMatrix(Vector2 scale, float rotate, Vector2 translate) {
	float cos = cosf(rotate);
	float sin = sinf(rotate);

	Matrix3x3 result;
	result.m[0][0] = scale.x * cos;
	result.m[0][1] = scale.x * sin;
	result.m[0][2] = 0;

	result.m[1][0] = -scale.y * sin;
	result.m[1][1] = scale.y * cos;
	result.m[1][2] = 0;

	result.m[2][0] = translate.x;
	result.m[2][1] = translate.y;
	result.m[2][2] = 1;

	return result;
}

Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom) {
	Matrix3x3 result;
	assert(left != right);
	assert(top != bottom);

	result.m[0][0] = 2.0f / (right - left);
	result.m[0][1] = 0;
	result.m[0][2] = 0;

	result.m[1][0] = 0;
	result.m[1][1] = 2.0f / (top - bottom);
	result.m[1][2] = 0;

	result.m[2][0] = (left + right) / (left - right);
	result.m[2][1] = (top + bottom) / (bottom - top);
	result.m[2][2] = 1;



	return result;
}


Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height) {
	Matrix3x3 result;


	result.m[0][0] = width / 2;
	result.m[0][1] = 0;
	result.m[0][2] = 0;

	result.m[1][0] = 0;
	result.m[1][1] = -(height / 2);
	result.m[1][2] = 0;

	result.m[2][0] = left + (width / 2);
	result.m[2][1] = top + (height / 2);
	result.m[2][2] = 1;



	return result;
}


Vector2 Transform(Vector2 vector, Matrix3x3 matrix) {
	Vector2 result;
	result.x = (vector.x * matrix.m[0][0]) + (vector.y * matrix.m[1][0]) + (1.0f * matrix.m[2][0]);
	result.y = (vector.x * matrix.m[0][1]) + (vector.y * matrix.m[1][1]) + (1.0f * matrix.m[2][1]);
	
	float w = (vector.x * matrix.m[0][2]) + (vector.y * matrix.m[1][2]) + (1.0f * matrix.m[2][2]);

	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	return result;
}