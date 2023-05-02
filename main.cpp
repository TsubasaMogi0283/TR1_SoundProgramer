#include <Novice.h>

#include <Vector2.h>
#include <HeaderCpp/Base/Base.h>
#include <HeaderCpp/Scene/Scene.h>


#include <HeaderCpp/MatrixFunction/MatrixFunction.h>
#include <HeaderCpp/Transparency/Transparency.h>
#include <HeaderCpp/Object/Object.h>
#include <HeaderCpp/Player/Player.h>
#include <HeaderCpp/Object/Field/Field.h>


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

#pragma endregion

#pragma region Resource(Music)
	//Music,SE
	int walkingSEHandle = 0;
	int walkingSE = Novice::LoadAudio("./Resources/Music/SE/Action/Walk.wav");

#pragma endregion


	////Coodinate
	int fieldTransparency = Transparency100;


	//Player(64x64)の位置
	Vector2 PlayerPosition = { 100.0f,200.0f };
	Vector2 PlayerSpeed = { 3.0f,3.0f };
	Vector2 PlayerRadius = { 32.0f,32.0f };


	//World座標
	Vector2 WorldCoodinate = { 0.0f,0.0f };
	Vector2 WorldScrollAmount = { 0.0f,0.0f };
	Vector2 ScrollSpeed = { 0.0f,0.0f };



	/////クラス
	//
	//フィールド
	Field* FieldInstance[4];
	FieldInstance[0] = new Field({ WINDOW_SIZE_WIDTH * 0,WINDOW_SIZE_HEIGHT * 0 }, { 0,0 });
	FieldInstance[1] = new Field({ WINDOW_SIZE_WIDTH * 1,WINDOW_SIZE_HEIGHT * 0 }, {0,0});
	FieldInstance[2] = new Field({ WINDOW_SIZE_WIDTH * 0,WINDOW_SIZE_HEIGHT * 1 }, {0,0});
	FieldInstance[3] = new Field({ WINDOW_SIZE_WIDTH * 1,WINDOW_SIZE_HEIGHT * 1 }, {0,0});


	//Player
	Player* player1 = new Player({ PlayerPosition.x,PlayerPosition.y }, { PlayerSpeed.x,PlayerSpeed.y }, { PlayerRadius.x,PlayerRadius.y });

	
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
				player1->UpDate(keys);

				FieldInstance[0]->Update();

				//歩く時のSEが鳴る
				if (player1->GetPlayerIsWalking() == true) {
					if (Novice::IsPlayingAudio(walkingSEHandle) == 0 || walkingSEHandle == -1) {
						walkingSEHandle = Novice::PlayAudio(walkingSE, 1, 0.3f);
					}
				}
				//何も操作していない時は鳴らない
				if (player1->GetPlayerIsWalking() == false) {
					
					Novice::StopAudio(walkingSEHandle);
				}

				
				

				

				
				

				ScrollSpeed.x = 0.0f;
				ScrollSpeed.y = 0.0f;

				 
				//プレイヤーが右に移動したとき
				if (player1->GetPlayerDirection() == Right) {



					//この時はまだフィールド動かない
					ScrollSpeed.x = 0.0f;
					ScrollSpeed.y = 0.0f;
					FieldInstance[0]->SetFieldScrollSpeed(0.0f, 0.0f);


					if (player1->GetPlayerCenterPosition().x > WINDOW_SIZE_HEIGHT / 2.0f) {
						ScrollSpeed.x = 3.0f;
						player1->SetPlayerSpeedX(0.0f);
						FieldInstance[0]->SetFieldScrollSpeed(-3.0f, 0.0f);
					}

				}
				//プレイヤーが左に移動したとき
				if (player1->GetPlayerDirection() == Left) {


					//この時はまだフィールド動かない
					ScrollSpeed.x = 0.0f;
					ScrollSpeed.y = 0.0f;
					FieldInstance[0]->SetFieldScrollSpeed(0.0f, 0.0f);



					

				}
				//プレイヤーが右に移動したとき
				if (player1->GetPlayerDirection() == Front) {



					//この時はまだフィールド動かない
					ScrollSpeed.x = 0.0f;
					ScrollSpeed.y = 0.0f;
					FieldInstance[0]->SetFieldScrollSpeed(0.0f, 0.0f);


				}
				//プレイヤーが左に移動したとき
				if (player1->GetPlayerDirection() == Back) {


					//この時はまだフィールド動かない
					ScrollSpeed.x = 0.0f;
					ScrollSpeed.y = 0.0f;
					FieldInstance[0]->SetFieldScrollSpeed(0.0f, 0.0f);





				}
				
				
				WorldScrollAmount.x += ScrollSpeed.x;
				WorldScrollAmount.y += ScrollSpeed.y;

				WorldCoodinate.x = player1->GetPlayerPosition().x + WorldScrollAmount.x;
				WorldCoodinate.y = player1->GetPlayerPosition().y + WorldScrollAmount.y;


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
					FieldInstance[i]->Draw(fieldTexture, fieldTransparency);

				}
				
				playerTextureChangeTime += 1;
				//何も操作していない時
				if (player1->GetPlayerDirection() == None) {
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
				if (player1->GetPlayerDirection() == Back) {
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
				if (player1->GetPlayerDirection() == Front) {
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
				if (player1->GetPlayerDirection() == Right) {
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
				if (player1->GetPlayerDirection() == Left) {
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

				player1->Draw(playerTextureHandleAll, playerTransparency);

				Novice::ScreenPrintf(0, 0, "World[%f][%f]", WorldCoodinate.x, WorldCoodinate.y);
				Novice::ScreenPrintf(0, 15, "Player[%f][%f]", player1->GetPlayerPosition().x, player1->GetPlayerPosition().y);
				
				Novice::ScreenPrintf(0, 45, "PlayerDirection[%d]", player1->GetPlayerDirection());
				Novice::ScreenPrintf(0, 60, "ScrollSpeed[%f][%f]", ScrollSpeed.x, ScrollSpeed.y);
				Novice::ScreenPrintf(0, 75, "WorldScrollAmount[%f][%f]",WorldScrollAmount.x, WorldScrollAmount.y);
				

				//None, 0
				//Front,1
				//Back, 2
				//Right,3
				//Left, 4


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

	delete player1;
	for (int i = 0; i < 4; i++) {
		delete FieldInstance[i];

	}
	// ライブラリの終了
	Novice::Finalize();
	
	return 0;
}
