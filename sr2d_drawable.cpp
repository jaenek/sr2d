namespace sr2d {

Drawable::Drawable(SDL_Renderer *renderer, SDL_Rect *rect) {
	this->rect = rect;

	surface = SDL_CreateRGBSurface(0, rect->w, rect->h, 32, 0, 0, 0, 0);

	sec(SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255)));
	texture = sec(SDL_CreateTextureFromSurface(renderer, surface));
	SDL_FreeSurface(surface);
}

void Drawable::draw(SDL_Renderer *renderer) {
	sec(SDL_RenderCopy(renderer, texture, NULL, rect));
}

}
