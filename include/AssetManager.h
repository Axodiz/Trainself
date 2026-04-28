#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <string>
#include <unordered_map>

#include <imgui.h>

class AssetManager
{
public:
	AssetManager() = default;
	ImFont *getFont(const std::string &name) const;
	void loadFont(ImFont *font, std::string name);

private:
	std::unordered_map<std::string, ImFont *> m_fonts;
};

#endif
