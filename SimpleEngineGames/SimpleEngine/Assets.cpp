#include "Assets.h"
#include "Utils/Log.h"

map<string, Texture> Assets::textures;
map<string, Font*> Assets::fonts;
string Assets::assetsPath{ "" };

void Assets::setAssetsPath(const string& path)
{
	assetsPath = path;
}

Texture Assets::loadTexture(Renderer& renderer, const string& filename, const string& name)
{
	textures[name] = loadTextureFromFile(renderer, (assetsPath + filename).c_str());
	return textures[name];
}

Font* Assets::loadFont(const string& filename, const string& name, int size)
{
	fonts[name] = loadFontFromFile((assetsPath + filename).c_str(), size);
	return fonts[name];
}

Texture& Assets::getTexture(const string& name)
{
	if (textures.find(name) == end(textures))
	{
		Log::error(LogCategory::Application, "Texture " + name + " does not exist in assets manager.");
	}
	return textures[name];
}

Font* Assets::getFont(const string& name)
{
	if (fonts.find(name) == end(fonts))
	{
		Log::error(LogCategory::Application, "Font " + name + " does not exist in assets manager.");
	}
	return fonts[name];
}

void Assets::clear()
{
	for (auto iter : textures)
	{
		iter.second.unload();
	}
	textures.clear();

	fonts.clear();
}

Texture Assets::loadTextureFromFile(Renderer& renderer, const string& filePath) 
{
	Texture texture;
	texture.load(renderer, filePath);
	return texture;
}

Font* Assets::loadFontFromFile(const string& filePath, int size)
{
	Font font;
	return font.load(filePath, size);
}