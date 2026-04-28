#include <AssetManager.h>
#include <iostream>

ImFont *AssetManager::getFont(const std::string &name) const
{
	auto it = m_fonts.find(name);
	if(it != m_fonts.end()){
		return it->second;
	}
	std::cout << "There is no font with this name" << std::endl;
	return NULL;
}

void AssetManager::loadFontFromFile(const char *path, float size, std::string name)
{
	ImFont *font = m_io->Fonts->AddFontFromFileTTF(path, size);
	loadFont(font, name);
}

void AssetManager::loadFont(ImFont *font, std::string name)
{
	auto it = m_fonts.find(name);
	if(it == m_fonts.end())
		m_fonts[name] = font;
	else
		std::cout << "Name is already exists" << std::endl;
}
