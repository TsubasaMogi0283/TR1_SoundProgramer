#include <HeaderCpp/Transparency/Transparency.h>

int textureChangeTime = 0;
const int TEXTURE_CHANGE_INTERVAL = 30;
void Frash(unsigned int& textureTransparency) {

	textureChangeTime += 1;
	if (textureChangeTime > TEXTURE_CHANGE_INTERVAL * 0) {
		if (textureChangeTime > TEXTURE_CHANGE_INTERVAL * 0 && textureChangeTime <= TEXTURE_CHANGE_INTERVAL * 1) {
			textureTransparency = Transparency100;
		}
		if (textureChangeTime > TEXTURE_CHANGE_INTERVAL * 1 && textureChangeTime <= TEXTURE_CHANGE_INTERVAL * 2) {
			textureTransparency = Transparency0;
		}
		if (textureChangeTime > TEXTURE_CHANGE_INTERVAL * 2) {
			textureChangeTime = TEXTURE_CHANGE_INTERVAL * 0;
		}
	}

}


int textureChangeTimeFast = 0;
const int TEXTURE_CHANGE_FAST_INTERVAL = 3;
void FrashFast(unsigned int& textureTransparency, int& nextConditionName, int nextSceneName) {

	textureChangeTimeFast += 1;
	if (textureChangeTimeFast > TEXTURE_CHANGE_FAST_INTERVAL * 0) {
		if (textureChangeTimeFast > TEXTURE_CHANGE_FAST_INTERVAL * 0 && textureChangeTimeFast <= TEXTURE_CHANGE_FAST_INTERVAL * 1) {
			textureTransparency = Transparency100;
		}
		if (textureChangeTimeFast > TEXTURE_CHANGE_FAST_INTERVAL * 1 && textureChangeTimeFast <= TEXTURE_CHANGE_FAST_INTERVAL * 2) {
			textureTransparency = Transparency0;
		}
		if (textureChangeTimeFast > TEXTURE_CHANGE_FAST_INTERVAL * 2 && textureChangeTimeFast <= TEXTURE_CHANGE_FAST_INTERVAL * 3) {
			textureTransparency = Transparency100;
		}
		if (textureChangeTimeFast > TEXTURE_CHANGE_FAST_INTERVAL * 3 && textureChangeTimeFast <= TEXTURE_CHANGE_FAST_INTERVAL * 4) {
			textureTransparency = Transparency0;
		}
		if (textureChangeTimeFast > TEXTURE_CHANGE_FAST_INTERVAL * 4 && textureChangeTimeFast <= TEXTURE_CHANGE_FAST_INTERVAL * 5) {
			textureTransparency = Transparency100;
		}
		if (textureChangeTimeFast > TEXTURE_CHANGE_FAST_INTERVAL * 5 && textureChangeTimeFast <= TEXTURE_CHANGE_FAST_INTERVAL * 6) {
			textureTransparency = Transparency0;
		}
		if (textureChangeTimeFast > TEXTURE_CHANGE_FAST_INTERVAL * 6 && textureChangeTimeFast <= TEXTURE_CHANGE_FAST_INTERVAL * 7) {
			textureTransparency = Transparency100;
		}
		if (textureChangeTimeFast > TEXTURE_CHANGE_FAST_INTERVAL * 7 && textureChangeTimeFast <= TEXTURE_CHANGE_FAST_INTERVAL * 8) {
			textureTransparency = Transparency0;
		}
		if (textureChangeTimeFast > TEXTURE_CHANGE_FAST_INTERVAL * 8) {

			nextConditionName = nextSceneName;
			textureChangeTimeFast = TEXTURE_CHANGE_FAST_INTERVAL * 0;
		}


	}
}
