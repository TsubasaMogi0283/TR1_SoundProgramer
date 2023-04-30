#include <HeaderCpp/Object/Object.h>


Object::Object(Vector2 objectPosition) {
	this->objectPosition_ = objectPosition;

	this->objectPositionCenter_.x = 0.0f;
	this->objectPositionCenter_.y = 0.0f;


}

Object::~Object() {

}

void Object::Update() {

}

void Object::Draw(int textureHandle, unsigned int objectColour) {
	Novice::DrawSprite(
		int(objectPosition_.x),
		int(objectPosition_.y),
		textureHandle, 1.0f, 1.0f, 0.0f, objectColour);
}