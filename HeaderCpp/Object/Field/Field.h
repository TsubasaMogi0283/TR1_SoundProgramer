#pragma once
#include <HeaderCpp/Object/Object.h>
#include <HeaderCpp/Base/Base.h>

class Field : public Object {
public:
	Field(Vector2 fieldPosition, Vector2 fieldSpeed);

	~Field();

	void Update();

	void Draw(int textureHandle, unsigned int objectColour);

private:


};
