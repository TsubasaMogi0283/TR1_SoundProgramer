#pragma once
#include <HeaderCpp/Base/Base.h>

const int WINDOW_SIZE_WIDTH = 1280;
const int WINDOW_SIZE_HEIGHT = 720;

const int SECOND = 60;



struct Matrix2x2 {
	float m[2][2];
};

struct Matrix3x3 {
	float m[3][3];
};

struct FieldCoodinate {
	Vector2 FieldPosition;
	Vector2 FieldSpeed;
};


enum PlayerDirection {
	None,
	Front,
	Back,
	Right,
	Left,
};

enum FieldDirection {
	FieldNone,
	FieldFront,
	FieldBack,
	FieldRight,
	FieldLeft,
};

	