#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <imgui.h>

#include <string>
#include <unordered_map>
#include <iostream>

class AssetManager
{
public:
	AssetManager() = default;
	ImFont *getFont(const std::string &name) const;
	void loadFont(ImFont *font, std::string name);

private:
	std::unordered_map<std::string, ImFont *> fonts;
};

#endif
