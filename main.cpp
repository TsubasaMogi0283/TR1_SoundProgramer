#include <Novice.h>

#include <Vector2.h>
#include <cmath>
#include <HeaderCpp/Base/Base.h>
#include <HeaderCpp/Scene/Scene.h>

#include <HeaderCpp/Transparency/Transparency.h>
#include <HeaderCpp/Object/Object.h>
//#include <HeaderCpp/Player/Player.h>
//#include <HeaderCpp/Object/Field/Field.h>


const char kWindowTitle[] = "LE2B_26_モギ_ツバサ_TR1";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

#pragma region Resouece(Texture)
	//Texture 
	//フィールドのテクスチャ
	//4枚用意して大きいマップにする
	int fieldTexture = Novice::LoadTexture("./Resources/Field/Field.png");


	//Player
	//64x64
	const int PLAYER_TEXTURE_CHANGE_INTERVAL = 40;
	int playerTextureChangeTime = 0;
	int playerTextureHandleAll = 0;
	unsigned int playerTransparency = Transparency100;

	//前
	int playerFrontTexture[2] = { 0 };
	playerFrontTexture[0] = Novice::LoadTexture("./Resources/Player/Front/Front0.png");
	playerFrontTexture[1] = Novice::LoadTexture("./Resources/Player/Front/Front1.png");
	//後ろ
	int playerBackTexture[2] = { 0 };
	playerBackTexture[0] = Novice::LoadTexture("./Resources/Player/Back/Back0.png");
	playerBackTexture[1] = Novice::LoadTexture("./Resources/Player/Back/Back1.png");
	//左
	int playerLeftTexture[2] = { 0 };
	playerLeftTexture[0] = Novice::LoadTexture("./Resources/Player/Left/Left0.png");
	playerLeftTexture[1] = Novice::LoadTexture("./Resources/Player/Left/Left1.png");
	//右
	int playerRightTexture[2] = { 0 };
	playerRightTexture[0] = Novice::LoadTexture("./Resources/Player/Right/Right0.png");
	playerRightTexture[1] = Novice::LoadTexture("./Resources/Player/Right/Right1.png");


	//Event
	int waterFallTexture = Novice::LoadTexture("./Resources/Event/WaterFall.png");


#pragma endregion

#pragma region Resource(Music)
	//Music,SE
	int walkingSEHandle = -1;
	int walkingSE = Novice::LoadAudio("./Resources/Music/SE/Action/Walk.wav");

	int ambientWindSEHandle = -1;
	int ambientWindSE = Novice::LoadAudio("./Resources/Music/SE/Ambient/Ambient_WeakWind.wav");


	int waterFallSEHandle = -1;
	int waterFallSE = Novice::LoadAudio("./Resources/Music/SE/Ambient/Cymatics_LIFE_Waterfall_3.wav");


#pragma endregion


	////Coodinate
	int fieldTransparency = Transparency100;


	//Player(64x64)の位置
	Vector2 PlayerPosition = { 100.0f,200.0f };
	Vector2 PlayerCenterPosition = { 0.0f,0.0f };
	Vector2 PlayerSpeed = { 3.0f,3.0f };
	Vector2 NewPlayerSpeed = { 0.0f,0.0f };
	Vector2 NewPlayerSpeedVelocity = { 3.0f,3.0f };
	Vector2 PlayerRadius = { 32.0f,32.0f };


	bool isWalking=false;
	int walkingDirection=None;
	int isScroll = NoScroll;


	//World座標
	Vector2 WorldPlayerCoodinate = { 0.0f,0.0f };
	Vector2 WorldField1Coodinate = { 0.0f,0.0f };
	Vector2 WorldScrollAmount = { 0.0f,0.0f };
	Vector2 ScrollSpeed = { 0.0f,0.0f };



	//Object
	//256x256
	Vector2 WaterFallRadius = { 128.0f,128.0f };
	Vector2 WaterFallCoodinate = { (WINDOW_SIZE_WIDTH * 2.0f)- (WaterFallRadius.x * 2.0f),0.0f };
	Vector2 WaterFallNewCoodinate = { 0.0f,0.0f };
	Vector2 WaterFallCoodinateCenter = { 0.0f,0.0f };
	Vector2 WaterFallCollisionRadius = { 0.0f,0.0f };
	float waterFallCollisionDistance = 0.0f;



	/////クラス
	//
	//フィールド
	//Field* FieldInstance[4];
	//FieldInstance[0] = new Field({ WINDOW_SIZE_WIDTH * 0,WINDOW_SIZE_HEIGHT * 0 }, { 0,0 });
	//FieldInstance[1] = new Field({ WINDOW_SIZE_WIDTH * 1,WINDOW_SIZE_HEIGHT * 0 }, {0,0});
	//FieldInstance[2] = new Field({ WINDOW_SIZE_WIDTH * 0,WINDOW_SIZE_HEIGHT * 1 }, {0,0});
	//FieldInstance[3] = new Field({ WINDOW_SIZE_WIDTH * 1,WINDOW_SIZE_HEIGHT * 1 }, {0,0});

	FieldCoodinate Field1 = { {WINDOW_SIZE_WIDTH * 0,WINDOW_SIZE_HEIGHT * 0 }, { 0.0f,0.0f } };
	FieldCoodinate Field2 = { {WINDOW_SIZE_WIDTH * 1,WINDOW_SIZE_HEIGHT * 0 }, { 0.0f,0.0f } };
	FieldCoodinate Field3 = { {WINDOW_SIZE_WIDTH * 0,WINDOW_SIZE_HEIGHT * 1 }, { 0.0f,0.0f } };
	FieldCoodinate Field4 = { {WINDOW_SIZE_WIDTH * 1,WINDOW_SIZE_HEIGHT * 1 }, { 0.0f,0.0f } };


	//Player
	//Player* player1 = new Player({ PlayerPosition.x,PlayerPosition.y }, { PlayerSpeed.x,PlayerSpeed.y }, { PlayerRadius.x,PlayerRadius.y });

	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///


		switch (condition) {
		case Display:
			switch (displayCondition) {
			case Displaying:


				//十字キーで移動
				//player1->UpDate(keys);

				//FieldInstance[0]->Update();

				

#pragma region 操作
				//Back
				if (keys[DIK_UP] != 0 || keys[DIK_W] != 0) {
					isWalking = true;
					walkingDirection = Back;
				}
				//Front
				else if (keys[DIK_DOWN] != 0 || keys[DIK_S] != 0) {
					isWalking = true;
					walkingDirection = Front;
				}
				//Right
				else if (keys[DIK_RIGHT] != 0 || keys[DIK_D] != 0) {
					isWalking = true;
					walkingDirection = Right;
				}
				//Left
				else if (keys[DIK_LEFT] != 0 || keys[DIK_A] != 0) {
					isWalking = true;
					walkingDirection = Left;
				}
				//何も押していない時
				else {
					walkingDirection = None;
					isWalking = false;
				}

#pragma endregion



				

				
				if (walkingDirection == None) {
					PlayerSpeed.x = 0.0f;
					PlayerSpeed.y = 0.0f;

					ScrollSpeed.x = 0.0f;
					ScrollSpeed.y = 0.0f;

				}

				


				//1枚目の半分まで
				if (WorldPlayerCoodinate.x >= 0.0f &&
					WorldPlayerCoodinate.x < (WINDOW_SIZE_WIDTH / 2.0f) - PlayerRadius.x) {
					Field1.FieldPosition.x = 0.0f;
					WorldScrollAmount.x = 0.0f;
					
					//プレイヤーが右に移動したとき
					if (walkingDirection == Right) {
						ScrollSpeed.x = 0.0f;
						PlayerSpeed.x = 3.0f;
					}
					//プレイヤーが左に移動したとき
					if (walkingDirection == Left) {
						ScrollSpeed.x = 0.0f;
						PlayerSpeed.x = -3.0f;
					}
					//プレイヤーが下に移動したとき
					if (walkingDirection == Front) {
						ScrollSpeed.y = 0.0f;
						PlayerSpeed.y = 3.0f;
					}
					//プレイヤーが上に移動したとき
					if (walkingDirection == Back) {
						ScrollSpeed.y = 0.0f;
						PlayerSpeed.y = -3.0f;
					}
					
					
				}
				//1枚目の半分から2枚目の半分まで
				if (WorldPlayerCoodinate.x > (WINDOW_SIZE_WIDTH / 2.0f) - PlayerRadius.x &&
					WorldPlayerCoodinate.x < WINDOW_SIZE_WIDTH + (WINDOW_SIZE_WIDTH / 2.0f) - PlayerRadius.x) {
					//右へ移動
					if (walkingDirection == Right) {
						isScroll = Scroll;
						ScrollSpeed.x = 3.0f;
						PlayerSpeed.x = 0.0f;
					}
					//右へ移動
					if (walkingDirection == Left) {
						isScroll = Scroll;
						ScrollSpeed.x = -3.0f;
						PlayerSpeed.x = 0.0f;
					}
					//プレイヤーが下に移動したとき
					if (walkingDirection == Front) {
						isScroll = Scroll;
						ScrollSpeed.y = 0.0f;
						PlayerSpeed.x = 0.0f;
						PlayerSpeed.y = 3.0f;
					}
					//プレイヤーが上に移動したとき
					if (walkingDirection == Back) {
						isScroll = Scroll;
						ScrollSpeed.y = 0.0f;
						PlayerSpeed.x = 0.0f;
						PlayerSpeed.y = -3.0f;
					}
				}
				//2枚目の半分から最後まで
				if (WorldPlayerCoodinate.x > WINDOW_SIZE_WIDTH + (WINDOW_SIZE_WIDTH / 2.0f) - PlayerRadius.x &&
					WorldPlayerCoodinate.x < WINDOW_SIZE_WIDTH * 2.0f - PlayerRadius.x* 2.0f) {
					
					
					//右へ移動
					if (walkingDirection == Right) {
						isScroll = NoScroll;
						ScrollSpeed.x = 0.0f;
						PlayerSpeed.x = 3.0f;
					}
					//右へ移動
					if (walkingDirection == Left) {
						isScroll = NoScroll;
						ScrollSpeed.x = 0.0f;
						PlayerSpeed.x = -3.0f;
					}
					//プレイヤーが下に移動したとき
					if (walkingDirection == Front) {
						isScroll = NoScroll;
						ScrollSpeed.y = 0.0f;
						PlayerSpeed.y = 3.0f;
					}
					//プレイヤーが上に移動したとき
					if (walkingDirection == Back) {
						isScroll = NoScroll;
						ScrollSpeed.y = 0.0f;
						PlayerSpeed.y = -3.0f;
					}
				}
				


				if (WorldPlayerCoodinate.x < 0.0f) {
					WorldPlayerCoodinate.x = 0.0f;
					PlayerPosition.x = 0.0f;

				}
				if (WorldPlayerCoodinate.x > WINDOW_SIZE_WIDTH * 2.0f - PlayerRadius.x * 2.0f) {
					WorldPlayerCoodinate.x = WINDOW_SIZE_WIDTH * 2.0f - PlayerRadius.x * 2.0f;
					PlayerPosition.x = WINDOW_SIZE_WIDTH - PlayerRadius.x * 2.0f;

				}



				//イベント

				//環境音
				if (Novice::IsPlayingAudio(ambientWindSEHandle) == 0 || ambientWindSEHandle == -1) {
					ambientWindSEHandle = Novice::PlayAudio(ambientWindSE, 1, 0.6f);
				}

				//歩く時のSEが鳴る
				if (isWalking == true) {
					if (Novice::IsPlayingAudio(walkingSEHandle) == 0 || walkingSEHandle == -1) {
						walkingSEHandle = Novice::PlayAudio(walkingSE, 1, 0.3f);
					}
				}
				//何も操作していない時は鳴らない
				if (isWalking == false) {

					Novice::StopAudio(walkingSEHandle);
				}


#pragma region 滝の環境音
				//滝
				if (Novice::IsPlayingAudio(waterFallSEHandle) == 0 || waterFallSEHandle == -1) {
					waterFallSEHandle = Novice::PlayAudio(waterFallSE, 1, 0.0f);
				}
				//間近
				if (waterFallCollisionDistance < PlayerRadius.x + WaterFallRadius.x) {
					Novice::SetAudioVolume(waterFallSEHandle, 0.6f);

				}
				//少し離れる
				if (waterFallCollisionDistance >= PlayerRadius.x + WaterFallRadius.x &&
					waterFallCollisionDistance < 300.0f) {
					Novice::SetAudioVolume(waterFallSEHandle, 0.3f);

				}
				//遠い
				if (waterFallCollisionDistance >= 300.0f) {
					Novice::SetAudioVolume(waterFallSEHandle, 0.0f);

				}
#pragma endregion


#pragma region プレイヤー移動の正規化

				float length = sqrtf(PlayerSpeed.x * PlayerSpeed.x + PlayerSpeed.y * PlayerSpeed.y);

				NewPlayerSpeed.x = PlayerSpeed.x;
				NewPlayerSpeed.y = PlayerSpeed.y;

				if (length != 0.0f) {
					NewPlayerSpeed.x = PlayerSpeed.x / length;
					NewPlayerSpeed.y = PlayerSpeed.y / length;

				}

#pragma endregion


				PlayerPosition.x += NewPlayerSpeed.x*NewPlayerSpeedVelocity.x;
				PlayerPosition.y += NewPlayerSpeed.y*NewPlayerSpeedVelocity.y;

				PlayerCenterPosition.x = PlayerPosition.x + PlayerRadius.x;
				PlayerCenterPosition.y = PlayerPosition.y + PlayerRadius.y;
				//
				//Field1.FieldPosition.x += Field1.FieldSpeed.x;
				//Field1.FieldPosition.y += Field1.FieldSpeed.y;
				
				//スクロールの合計値
				WorldScrollAmount.x += ScrollSpeed.x;
				WorldScrollAmount.y += ScrollSpeed.y;
				//プレイヤーのワールド座標
				WorldPlayerCoodinate.x = PlayerPosition.x + WorldScrollAmount.x;
				WorldPlayerCoodinate.y = PlayerPosition.y + WorldScrollAmount.y;


				//フィールドのワールド座標
				WorldField1Coodinate.x = Field1.FieldPosition.x - WorldScrollAmount.x;


				//滝
				WaterFallNewCoodinate.x = WaterFallCoodinate.x - WorldScrollAmount.x;
				WaterFallNewCoodinate.y = WaterFallCoodinate.y - WorldScrollAmount.y;

				WaterFallCoodinateCenter.x = WaterFallNewCoodinate.x + WaterFallRadius.x;
				WaterFallCoodinateCenter.y = WaterFallNewCoodinate.y + WaterFallRadius.y;

				//当たり判定
				WaterFallCollisionRadius.x = WaterFallCoodinateCenter.x - PlayerCenterPosition.x;
				WaterFallCollisionRadius.y = WaterFallCoodinateCenter.y - PlayerCenterPosition.y;
				waterFallCollisionDistance = sqrtf(WaterFallCollisionRadius.x * WaterFallCollisionRadius.x + WaterFallCollisionRadius.y * WaterFallCollisionRadius.y);


				break;

			}


			


			break;

		case Initialize:
			switch (initializeCondition) {
			case Initialazing:

				break;

			}


			break;

		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///


		switch (condition) {
		case Display:
			switch (displayCondition) {
			case Displaying:

				//フィールドの描画
				for (int i = 0; i < 4; i++) {
					//FieldInstance[i]->Draw(fieldTexture, fieldTransparency);


					Novice::DrawSprite(int(Field1.FieldPosition.x - WorldScrollAmount.x), int(Field1.FieldPosition.y), fieldTexture, 1.0f, 1.0f, 0.0f, fieldTransparency);
					Novice::DrawSprite(int(Field2.FieldPosition.x - WorldScrollAmount.x), int(Field2.FieldPosition.y), fieldTexture, 1.0f, 1.0f, 0.0f, fieldTransparency);
					Novice::DrawSprite(int(Field3.FieldPosition.x - WorldScrollAmount.x), int(Field3.FieldPosition.y), fieldTexture, 1.0f, 1.0f, 0.0f, fieldTransparency);
					Novice::DrawSprite(int(Field4.FieldPosition.x - WorldScrollAmount.x), int(Field4.FieldPosition.y), fieldTexture, 1.0f, 1.0f, 0.0f, fieldTransparency);

				}
				
				playerTextureChangeTime += 1;
				//何も操作していない時
				if (walkingDirection == None) {
					if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 0) {
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 0 && playerTextureChangeTime <= PLAYER_TEXTURE_CHANGE_INTERVAL * 1) {
							playerTextureHandleAll = playerFrontTexture[0];
						}
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 1 && playerTextureChangeTime <= PLAYER_TEXTURE_CHANGE_INTERVAL * 2) {
							playerTextureHandleAll = playerFrontTexture[1];
						}
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 2 ) {
							playerTextureChangeTime = 0;
						}
					}
				}
				//上
				if (walkingDirection == Back) {
					if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 0) {
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 0 && playerTextureChangeTime <= PLAYER_TEXTURE_CHANGE_INTERVAL * 1) {
							playerTextureHandleAll = playerBackTexture[0];
						}
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 1 && playerTextureChangeTime <= PLAYER_TEXTURE_CHANGE_INTERVAL * 2) {
							playerTextureHandleAll = playerBackTexture[1];
						}
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 2) {
							playerTextureChangeTime = 0;
						}
					}
				}
				//下
				if (walkingDirection == Front) {
					if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 0) {
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 0 && playerTextureChangeTime <= PLAYER_TEXTURE_CHANGE_INTERVAL * 1) {
							playerTextureHandleAll = playerFrontTexture[0];
						}
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 1 && playerTextureChangeTime <= PLAYER_TEXTURE_CHANGE_INTERVAL * 2) {
							playerTextureHandleAll = playerFrontTexture[1];
						}
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 2) {
							playerTextureChangeTime = 0;
						}
					}
				}
				//右
				if (walkingDirection == Right) {
					if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 0) {
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 0 && playerTextureChangeTime <= PLAYER_TEXTURE_CHANGE_INTERVAL * 1) {
							playerTextureHandleAll = playerRightTexture[0];
						}
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 1 && playerTextureChangeTime <= PLAYER_TEXTURE_CHANGE_INTERVAL * 2) {
							playerTextureHandleAll = playerRightTexture[1];
						}
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 2) {
							playerTextureChangeTime = 0;
						}
					}
				}
				//左
				if (walkingDirection == Left) {
					if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 0) {
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 0 && playerTextureChangeTime <= PLAYER_TEXTURE_CHANGE_INTERVAL * 1) {
							playerTextureHandleAll = playerLeftTexture[0];
						}
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 1 && playerTextureChangeTime <= PLAYER_TEXTURE_CHANGE_INTERVAL * 2) {
							playerTextureHandleAll = playerLeftTexture[1];
						}
						if (playerTextureChangeTime > PLAYER_TEXTURE_CHANGE_INTERVAL * 2) {
							playerTextureChangeTime = 0;
						}
					}
				}

				//player1->Draw(playerTextureHandleAll, playerTransparency);

				Novice::DrawSprite(
					int(PlayerPosition.x),
					int(PlayerPosition.y),
					playerTextureHandleAll, 1.0f, 1.0f, 0.0f, playerTransparency);

				//滝
				Novice::DrawSprite(
					int(WaterFallNewCoodinate.x),
					int(WaterFallNewCoodinate.y),
					waterFallTexture, 1.0f, 1.0f, 0.0f, Transparency100);
				Novice::DrawEllipse(
					int (WaterFallCoodinateCenter.x), 
					int (WaterFallCoodinateCenter.y), 
					int (WaterFallRadius.x), 
					int (WaterFallRadius.y), 0.0f, RED, kFillModeWireFrame);




				Novice::ScreenPrintf(0, 0, "World[%f][%f]", WorldPlayerCoodinate.x, WorldPlayerCoodinate.y);
				Novice::ScreenPrintf(0, 15, "Player[%f][%f]", PlayerPosition.x, PlayerPosition.y);
				Novice::ScreenPrintf(0, 30, "PlayerCenter[%f][%f]", PlayerCenterPosition.x, PlayerCenterPosition.y);
				Novice::ScreenPrintf(0, 45, "PlayerDirection[%d]", walkingDirection);
				Novice::ScreenPrintf(0, 60, "ScrollSpeed[%f][%f]", ScrollSpeed.x, ScrollSpeed.y);
				Novice::ScreenPrintf(0, 75, "WorldScrollAmount[%f][%f]",WorldScrollAmount.x, WorldScrollAmount.y);
				Novice::ScreenPrintf(0, 90, "WaterFallDistance[%f]", waterFallCollisionDistance);



				break;

			}

			break;

		case Initialize:
			switch (initializeCondition) {
			case Initialazing:

				break;

			}


			break;

		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	//delete player1;
	for (int i = 0; i < 4; i++) {
		//delete FieldInstance[i];

	}
	// ライブラリの終了
	Novice::Finalize();
	
	return 0;
}
