#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <string>
#include <unordered_map>

#include <imgui.h>

class AssetManager
{
public:
	AssetManager(const ImGuiIO *io)
		: m_io(io){};

	void loadFontFromFile(const char *path, float size, std::string name);
	ImFont *getFont(const std::string &name) const;

private:
	void loadFont(ImFont *font, std::string name);

	const ImGuiIO *m_io;
	std::unordered_map<std::string, ImFont *> m_fonts;
};

#endif
