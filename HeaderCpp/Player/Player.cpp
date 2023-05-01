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



void Player::UpDate(char* keys ) {

	//When player's character is walking,soundeffect is played.
	walkingDirection_ = None;
	isWalking_ = false;
	//Back
	if (keys[DIK_UP] != 0 || keys[DIK_W] != 0) {
		isWalking_ = true;
		walkingDirection_ = Back;
		playerPosition_.y -= playerSpeed_.y;
		

	}
	//Front
	if (keys[DIK_DOWN] != 0 || keys[DIK_S] != 0) {
		isWalking_ = true;
		walkingDirection_ = Front;
		playerPosition_.y += playerSpeed_.y;
		

	}
	
	if (keys[DIK_RIGHT] != 0 || keys[DIK_D] != 0) {
		isWalking_ = true;
		walkingDirection_ = Right;
		playerPosition_.x += playerSpeed_.x;
		

	}
	
	if (keys[DIK_LEFT] != 0 || keys[DIK_A] != 0) {
		isWalking_ = true;
		walkingDirection_ = Left;
		playerPosition_.x -= playerSpeed_.x;
		

	}


	if (playerPosition_.x < 0) {
		playerPosition_.x = 0;
	}
	if (playerPosition_.y < 0) {
		playerPosition_.y = 0;
	}

	if (playerCenterPosition_.x > WINDOW_SIZE_WIDTH - playerRadius_.x) {
		playerCenterPosition_.x = WINDOW_SIZE_WIDTH - playerRadius_.x;
	}
	if (playerCenterPosition_.y < WINDOW_SIZE_HEIGHT - playerRadius_.y) {
		playerCenterPosition_.y = WINDOW_SIZE_HEIGHT - playerRadius_.y;
	}

	

}

void Player::Draw(int textureHandle,unsigned int playerColour) {
	Novice::DrawSprite(
		int(playerPosition_.x),
		int(playerPosition_.y),
		textureHandle, 1.0f, 1.0f, 0.0f, playerColour);
}


void Player::SetPlayerPosition(float playerPositionX, float playerPositionY) {
	this->playerPosition_.x = playerPositionX;
	this->playerPosition_.y = playerPositionY;

}

void Player::SetPlayerCenterPosition(float playerCenterPositionX, float playerCenterPositionY) {
	this->playerCenterPosition_.x = playerCenterPositionX;
	this->playerCenterPosition_.y = playerCenterPositionY;
}

void Player::SetPlayerSpeed(float playerSpeedX, float playerSpeedY) {
	this->playerSpeed_.x = playerSpeedX;
	this->playerSpeed_.y = playerSpeedY;
		
}
