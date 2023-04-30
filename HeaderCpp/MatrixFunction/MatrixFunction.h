#pragma once
#include <HeaderCpp/Base/Base.h>
#include <Vector2.h>
#include <Vector3.h>
#include <cmath>
#include <cassert>


Matrix3x3 Multiply(Matrix3x3 matrix1, Matrix3x3 matrix2);


Matrix3x3 Inverse(Matrix3x3 matrix);


Matrix3x3 MakeAffineMatrix(Vector2 scale, float rotate, Vector2 translate);
Matrix3x3 MakeOrthographicMatrix(float left, float top, float right, float bottom);


Matrix3x3 MakeViewportMatrix(float left, float top, float width, float height);


Vector2 Transform(Vector2 vector, Matrix3x3 matrix);


