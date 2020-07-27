namespace sr2d {

class Game
{
private:
	SDL_Renderer *renderer;
	SDL_Window *window;
	bool done;
	struct Context *context;

public:
	void init(const char *title, int width, int height, struct Context *);
	void loop(void (*render)(SDL_Renderer *, struct Context *));
	void quit();
};

}
