namespace sr2d {

class Game
{
private:
	SDL_Renderer *renderer;
	SDL_Window *window;
	bool done;

public:
	void init(int width, int height);
	void loop();
	void quit();
};

}
