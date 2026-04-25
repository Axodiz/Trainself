#include <AssetManager.h>

ImFont *AssetManager::getFont(const std::string &name) const
{
	auto it = fonts.find(name);
	if(it != fonts.end()){
		return it->second;
	}
	std::cout << "There is no font with this name" << std::endl;
	return NULL;
}

void AssetManager::loadFont(ImFont *font, std::string name)
{
	auto it = fonts.find(name);
	if(it == fonts.end())
		fonts[name] = font;
	else
		std::cout << "Name is already exists" << std::endl;
}
