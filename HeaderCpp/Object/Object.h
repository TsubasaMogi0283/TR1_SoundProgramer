#pragma once
#include <Vector2.h>
#include <Novice.h>

class  Object {
public:
	Object(Vector2 objectPosition);

	~Object();

	void Update();

	void Draw(int textureHandle, unsigned int objectColour);


private:
	Vector2 objectPosition_;
	Vector2 objectPositionCenter_;


};
