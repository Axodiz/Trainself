#include <loadSourceManager.h>

std::shared_ptr<AssetManager> loadSourceManager()
{
	auto srcMng = std::make_shared<AssetManager>(&ImGui::GetIO());

	float fontSizeDefault = 16.0f;
	float fontSizeLarge = fontSizeDefault * 4;

	srcMng->loadFontFromFile("fonts/ProggyClean.ttf", fontSizeDefault, "ProggyClean_Default"); 
	srcMng->loadFontFromFile("fonts/ProggyClean.ttf", fontSizeLarge, "ProggyClean_Large"); 

	return srcMng;
}
