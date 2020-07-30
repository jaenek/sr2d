namespace sr2d {

struct Game
{
	SDL_Renderer *renderer;
	SDL_Window *window;
	bool done;
	struct Context *context;
	std::vector<Action> actions;

	void init(const char *title, int width, int height, struct Context *);
	void loop(void (*update)(struct Context *), void (*render)(SDL_Renderer *, struct Context *));
	void quit();
};

}
