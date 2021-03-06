#include "TextureManager.h"

#include <iostream>


void TextureManager::clean(){
	for (auto texture : g_texture_map){
		SDL_DestroyTexture(texture.second);
	}

	g_texture_map.clear();

	if (instance != nullptr){
		delete instance;
	}
	instance = nullptr;
}

TextureManager * TextureManager::getInstance(){
	if (instance == nullptr){
		instance = new TextureManager();
	}

	return instance;
}

bool TextureManager::load(const std::string file, const std::string id,
								  SDL_Renderer * g_renderer){

	bool success = true;

	SDL_Surface * asset_surface = IMG_Load(file.c_str());

	if (asset_surface != nullptr) {
		SDL_Texture * texture;
		texture = SDL_CreateTextureFromSurface(g_renderer, asset_surface);

		SDL_FreeSurface(asset_surface);

		if (texture != nullptr){
			g_texture_map[id] = texture;
		} else {
			std::cerr << "Failed to load texture "  << std::endl;
			std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
			success = false;
		}

	} else {
		std::cerr << "Failed to load surface from " << file << std::endl;
		std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
		success = false;
	}

	return success;
}




void TextureManager::draw(const std::string id, const int X, const int Y,
								  const int WIDTH, const int HEIGHT,
								  SDL_Renderer * g_renderer,
								  const SDL_RendererFlip FLIP){
	SDL_Rect source_rect;
	SDL_Rect dest_rect;

	source_rect.x = 0;
	source_rect.y = 0;
	source_rect.w = dest_rect.w = WIDTH;
	source_rect.h = dest_rect.h = HEIGHT;

	dest_rect.x = X;
	dest_rect.y = Y;

	SDL_RenderCopyEx(g_renderer, g_texture_map[id],
						  &source_rect, &dest_rect,
						  0, 0, FLIP);

}


void TextureManager::drawFrame(const std::string id, const int X, const int Y,
										 const int WIDTH, const int HEIGHT,
										 const int CURRENT_ROW, const int CURRENT_FRAME,
										 SDL_Renderer * g_renderer,
										 const SDL_RendererFlip FLIP){
	SDL_Rect source_rect;
	SDL_Rect dest_rect;

	source_rect.x = WIDTH * CURRENT_FRAME;
	source_rect.y = HEIGHT * (CURRENT_ROW - 1);
	source_rect.w = dest_rect.w = WIDTH;
	source_rect.h = dest_rect.h = HEIGHT;

	dest_rect.x = X;
	dest_rect.y = Y;

	SDL_RenderCopyEx(g_renderer, g_texture_map[id],
						  &source_rect, &dest_rect,
						  0, 0, FLIP);

}

void TextureManager::clearFromTextureMap(const std::string id) {

	SDL_DestroyTexture(g_texture_map[id]);


	g_texture_map.erase(id);
}



void TextureManager::drawTile(const std::string id, const int MARGIN,
										const int SPACING, const int X, const int Y,
										const int WIDTH, const int HEIGHT,
										const int CURRENT_ROW, const int CURRENT_FRAME,
										SDL_Renderer * renderer) {
	SDL_Rect src_rect;
	SDL_Rect dest_rect;

	src_rect.x = MARGIN + (SPACING + WIDTH) * CURRENT_FRAME;
	src_rect.y = MARGIN + (SPACING + HEIGHT) * CURRENT_ROW;
	src_rect.w = dest_rect.w = WIDTH;
	src_rect.h = dest_rect.h = HEIGHT;

	dest_rect.x = X;
	dest_rect.y = Y;

	SDL_RenderCopyEx(renderer, g_texture_map[id], &src_rect, &dest_rect,
						  0, 0, SDL_FLIP_NONE);
}





TextureManager * TextureManager::instance = nullptr;
std::map<std::string, SDL_Texture *> TextureManager::g_texture_map;
