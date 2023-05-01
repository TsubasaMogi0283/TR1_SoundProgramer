#pragma once
#include <Vector2.h>
#include <Novice.h>

#include <HeaderCpp/Base/Base.h>

class  Player{
public:
	Player(Vector2 playerPosition, Vector2 playerSpeed, Vector2 playerRadius);
	
	
	~Player();


	void UpDate(char* keys);

	void Draw(int textureHandle, unsigned int playerColour);


	Vector2 GetPlayerPosition() {
		return playerPosition_;
	};
	Vector2 GetPlayerSpeed() {
		return playerSpeed_;
	}

	int GetPlayerDirection() {
		return walkingDirection_;
	}

	bool GetPlayerIsWalking() {
		return isWalking_;
	}

	void SetPlayerPosition(float x, float y);

	void SetPlayerSpeed(float x, float y);



private:
	Vector2 playerPosition_;
	Vector2 playerCenterPosition_;
	Vector2 playerRadius_;

	Vector2 playerSpeed_;


	//WalkingCondition
	bool isWalking_;
	int walkingDirection_;




};

