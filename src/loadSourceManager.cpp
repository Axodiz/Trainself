#include <loadSourceManager.h>

const AssetManager *loadSourceManager()
{
	AssetManager *srcMng = new AssetManager(&ImGui::GetIO());

	float fontSizeDefault = 16.0f;
	float fontSizeLarge = fontSizeDefault * 4;

	srcMng->loadFontFromFile("fonts/ProggyClean.ttf", fontSizeDefault, "ProggyClean_Default"); 
	srcMng->loadFontFromFile("fonts/ProggyClean.ttf", fontSizeLarge, "ProggyClean_Large"); 

	return srcMng;
}
