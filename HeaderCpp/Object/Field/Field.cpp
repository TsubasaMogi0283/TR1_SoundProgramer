#include "Field.h"

#include <HeaderCpp/Object/Object.h>
#include <HeaderCpp/Player/Player.h>
#include <HeaderCpp/Base/Base.h>

Field::Field(Vector2 fieldPosition,Vector2 fieldSpeed) {
	this->objectPosition_.x = fieldPosition.x;
	this->objectPosition_.y = fieldPosition.y;

	this->objectPositionCenter_.x = 0;
	this->objectPositionCenter_.y = 0;

	this->objectSpeed_.x = fieldSpeed.x;
	this->objectSpeed_.y = fieldSpeed.y;

	this->objectRadius_.x = 0;
	this->objectRadius_.y = 0;

	this->fieldDirection_ = FieldNone;
}

Field::~Field() {

}

void Field::Update() {

	//Player Same Movement
	objectPosition_.x += objectSpeed_.x;
	objectPosition_.y += objectSpeed_.y;


}

void Field::Draw(int textureHandle, unsigned int objectColour) {
	Novice::DrawSprite(
		int(objectPosition_.x),
		int(objectPosition_.y),
		textureHandle, 1.0f, 1.0f, 0.0f, objectColour);
}

#pragma region _FieldAccessors

void Field::SetFieldPosition(float fieldPositionX, float fieldPositionY) {
	this->objectPosition_.x = fieldPositionX;
	this->objectPosition_.y = fieldPositionY;

}


void Field::SetFieldDirection(int fieldDirection) {
	this->fieldDirection_ = fieldDirection;
}

void Field::SetFieldScrollSpeed(float scrollSpeedX, float scrollSpeedY) {
	this->objectSpeed_.x = scrollSpeedX;
	this->objectSpeed_.y = scrollSpeedY;

}

#pragma endregion