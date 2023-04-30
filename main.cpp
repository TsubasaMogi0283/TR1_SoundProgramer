#include <Novice.h>

#include <Vector2.h>
#include <HeaderCpp/Base/Base.h>
#include <HeaderCpp/Scene/Scene.h>


#include <HeaderCpp/MatrixFunction/MatrixFunction.h>
#include <HeaderCpp/Transparency/Transparency.h>
#include <HeaderCpp/Object/Object.h>
#include <HeaderCpp/Player/Player.h>


const char kWindowTitle[] = "LE2B_26_モギ_ツバサ_TR1";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, WINDOW_SIZE_WIDTH, WINDOW_SIZE_HEIGHT);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	////Resource
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





	//Music,SE
	int walkingSEHandle = 0;
	int walkingSE = Novice::LoadAudio("./Resources/Music/SE/Action/Walk.wav");






	////Coodinate
	int fieldTransparency = Transparency100;


	//Playerの位置
	Vector2 PlayerPosition = { 100,200 };
	Vector2 PlayerSpeed = { 3,3 };
	Vector2 PlayerRadius = { 32,32 };


	//World座標
	Vector2 WorldCoodinate = { 0,0 };
	Vector2 ScrollSpeed = { 0,0 };



	/////クラス
	//
	//フィールド
	Object* Field[4];
	Field[0] = new Object({ WINDOW_SIZE_WIDTH * 0,WINDOW_SIZE_HEIGHT * 0 });
	Field[1] = new Object({ WINDOW_SIZE_WIDTH * 1,WINDOW_SIZE_HEIGHT * 0 });
	Field[2] = new Object({ WINDOW_SIZE_WIDTH * 0,WINDOW_SIZE_HEIGHT * 1 });
	Field[3] = new Object({ WINDOW_SIZE_WIDTH * 1,WINDOW_SIZE_HEIGHT * 1 });


	//Player
	Player* player1 = new Player({0,0 },{ PlayerSpeed.x,PlayerSpeed .y}, { PlayerRadius.x,PlayerRadius.y });



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


				player1->UpDate(keys, walkingSE, walkingSEHandle);










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
					Field[i]->Draw(fieldTexture, fieldTransparency);

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

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
