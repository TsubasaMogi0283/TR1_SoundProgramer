#pragma once
#include <HeaderCpp/Object/Object.h>
#include <HeaderCpp/Base/Base.h>

class Field : public Object {
public:
	Field(Vector2 fieldPosition, Vector2 fieldSpeed);

	~Field();

	void Update();

	void Draw(int textureHandle, unsigned int objectColour);


	int GetFieldDirection() {
		return fieldDirection_;
	}

	Vector2 GetFieldPosition() {
		return objectPosition_;
	}

	Vector2 GetFieldScrollSpeed() {
		return objectSpeed_;
	}



	void SetFieldPosition(float fieldPositionX, float fieldPositionY);

	void SetFieldDirection(int fieldDirection);

	void SetFieldScrollSpeed(float scrollSpeedX, float scrollSpeedY);

private:
	int fieldDirection_;

};
