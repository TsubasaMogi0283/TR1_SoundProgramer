#include <HeaderCpp/Function/Function.h>

float Clamp(float t, float min, float max) {
	if (t < min) {
		return min;
	}
	else if (t > max) {
		return max;
	}

	return t;


}



float Dot(Vector2 V1, Vector2 V2) {
	return V1.x * V2.x + V1.y * V2.y;
}

float Length(Vector2 V1) {
	return sqrt(V1.x * V1.x + V1.y * V1.y);
}

Vector2 Normalize(Vector2 V1) {
	Vector2 result = {0.0f,0.0};

	float length = sqrt(V1.x * V1.x + V1.y * V1.y);

	float newX = V1.x;
	float newY = V1.y;

	if (length != 0.0f) {
		newX = V1.x / length;
		newY = V1.y / length;

	}

	result.x = newX;
	result.y = newY;


	return result;
}