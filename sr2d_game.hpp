namespace sr2d {

struct Game
{
	SDL_Renderer *renderer;
	SDL_Window *window;
	bool done;
	struct Context *context;
	std::vector<Action> actions;
	std::vector<Drawable> drawables;

	void init(const char *title, int width, int height);
	void loop(void (*update)(struct Context *));
	void quit();
};

}
