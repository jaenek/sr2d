namespace sr2d {

class Game
{
private:
	SDL_Renderer *renderer;
	SDL_Window *window;
	bool done;
	struct *context;

public:
	void init(int width, int height);
	void loop(void (*render)(SDL_Render *, struct *));
	void quit();
};

}
