#include <HeaderCpp/Player/Player.h>

Player::Player(Vector2 playerPosition, Vector2 playerSpeed, Vector2 playerRadius) {
	this->playerPosition_.x = playerPosition.x;
	this->playerPosition_.y = playerPosition.y;

	this->playerCenterPosition_.x = 0;
	this->playerCenterPosition_.y = 0;

	this->playerSpeed_.x = playerSpeed.x;
	this->playerSpeed_.y = playerSpeed.y;

	this->playerRadius_.x = playerRadius.x;
	this->playerRadius_.y = playerRadius.y;

	this->isWalking_ = false;
	this->walkingDirection_ = None;

}

Player::~Player() {
	
}



void Player::SetPlayerPosition(float playerPositionX, float playerPositionY) {
	this->playerPosition_.x = playerPositionX;
	this->playerPosition_.y = playerPositionY;

}

void Player::SetPlayerCenterPosition(float playerCenterPositionX, float playerCenterPositionY) {
	this->playerCenterPosition_.x = playerCenterPositionX;
	this->playerCenterPosition_.y = playerCenterPositionY;
}


void Player::SetPlayerSpeedX(float playerSpeedX) {
	this->playerSpeed_.x = playerSpeedX;
}
void Player::SetPlayerSpeedY(float playerSpeedY) {
	this->playerSpeed_.y = playerSpeedY;
}


void Player::UpDate(char* keys ) {

	//When player's character is walking,soundeffect is played.
	walkingDirection_ = None;
	isWalking_ = false;



	playerPosition_.x += playerSpeed_.x;
	playerPosition_.y += playerSpeed_.y;


	SetPlayerCenterPosition(playerPosition_.x + playerRadius_.x, playerPosition_.y + playerRadius_.y);

	//Back
	if (keys[DIK_UP] != 0 || keys[DIK_W] != 0) {
		isWalking_ = true;
		walkingDirection_ = Back;
	}
	//Front
	if (keys[DIK_DOWN] != 0 || keys[DIK_S] != 0) {
		isWalking_ = true;
		walkingDirection_ = Front;
	}
	//Right
	if (keys[DIK_RIGHT] != 0 || keys[DIK_D] != 0) {
		isWalking_ = true;
		walkingDirection_ = Right;
	}
	
	if (keys[DIK_LEFT] != 0 || keys[DIK_A] != 0) {
		isWalking_ = true;
		walkingDirection_ = Left;
	}


	if (isWalking_ == true) {
		if (walkingDirection_ == Back) {
			playerSpeed_.x = 0.0f;
			playerSpeed_.y = -3.0f;
		}
		if (walkingDirection_ == Front) {
			playerSpeed_.x = 0.0f;
			playerSpeed_.y = 3.0f;
		}
		if (walkingDirection_ == Right) {
			playerSpeed_.x = 3.0f;
			playerSpeed_.y = 0.0f;
		}
		if (walkingDirection_ == Left) {
			playerSpeed_.x = -3.0f;
			playerSpeed_.y = 0.0f;
		}

	}

	if (isWalking_ == false) {
		playerSpeed_.x = 0.0f;
		playerSpeed_.y = 0.0f;
	}
	


	if (playerPosition_.x < 0) {
		playerPosition_.x = 0;
	}


}

void Player::Draw(int textureHandle,unsigned int playerColour) {
	Novice::DrawSprite(
		int(playerPosition_.x),
		int(playerPosition_.y),
		textureHandle, 1.0f, 1.0f, 0.0f, playerColour);

	Novice::ScreenPrintf(0, 30, "PlayerCenter[%f][%f]",playerCenterPosition_.x, playerCenterPosition_.y);
}



