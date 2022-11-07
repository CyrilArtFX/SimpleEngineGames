#pragma once
#include <map>
#include <string>
#include "Texture.h"
#include "Utils/Font.h"
using std::map;
using std::string;

class Assets
{
public:
	static map<string, Texture> textures;
	static map<string, Font*> fonts;

	static void setAssetsPath(const string& path);

	//  load an asset from file
	static Texture loadTexture(Renderer& renderer, const string& filename, const string& name);
	static Font* loadFont(const string& filename, const string& name, int size);

	//  retrieve a stored asset
	static Texture& getTexture(const string& name);
	static Font* getFont(const string& name);

	//  properly de-allocates all loaded resources
	static void clear();

private:
	Assets(){}

	//  load a single asset from file
	static Texture loadTextureFromFile(Renderer& renderer, const string& filePath);
	static Font* loadFontFromFile(const string& filePath, int size);

	static string assetsPath;
};

