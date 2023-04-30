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



void Player::UpDate(char* keys,int walkingSE,int walkingSEHandle ) {

	
	//When player's character is walking,soundeffect is played.
	walkingDirection_ = None;
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



	if (isWalking_ == true) {

		//WalkingSE Is Playing!!
			//BPM120?
		if (Novice::IsPlayingAudio(walkingSEHandle) == 0 || walkingSEHandle == -1) {
			walkingSEHandle = Novice::PlayAudio(walkingSE, 1, 0.5f);
		}


	}

	if (isWalking_ == false) {
		Novice::StopAudio(walkingSEHandle);
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

void Player::SetPlayerSpeed(float playerSpeedX, float playerSpeedY) {
	this->playerSpeed_.x = playerSpeedX;
	this->playerSpeed_.y = playerSpeedY;
		
}
