#include <HeaderCpp/Object/Object.h>
#include "Field.h"


Field::Field(Vector2 fieldPosition,Vector2 fieldSpeed) {
	this->objectPosition_.x = fieldPosition.x;
	this->objectPosition_.y = fieldPosition.y;

	this->objectPositionCenter_.x = 0;
	this->objectPositionCenter_.y = 0;

	this->objectSpeed_.x = fieldSpeed.x;
	this->objectSpeed_.y = fieldSpeed.y;

	this->objectRadius_.x = 0;
	this->objectRadius_.y = 0;

	
}

Field::~Field() {

}

void Field::Update() {





}

void Field::Draw(int textureHandle, unsigned int objectColour) {
	Novice::DrawSprite(
		int(objectPosition_.x),
		int(objectPosition_.y),
		textureHandle, 1.0f, 1.0f, 0.0f, objectColour);
}