namespace sr2d {

struct Drawable {
	SDL_Surface *surface;
	SDL_Texture *texture;
	SDL_Rect *rect;

	Drawable(SDL_Renderer *renderer, SDL_Rect *rect);
	virtual void draw(SDL_Renderer *renderer);
};

}
