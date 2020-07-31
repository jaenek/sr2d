#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

namespace sr2d {

template <typename... T>
void println(T... args)
{
    auto print = [](auto a) {
        std::cerr << a;
    };

    (print(args), ...);
	std::cerr << std::endl;
}

void sec(int code)
{
    if (code < 0) {
        println(stderr, "SDL Error: ", SDL_GetError());
        abort();
    }
}

template <typename T>
T *sec(T *ptr)
{
    if (ptr == nullptr) {
        println(stderr, "SDL Error: ", SDL_GetError());
        abort();
    }
    return ptr;
}

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

void Game::init(const char *title, int width, int height)
{
	sec(SDL_Init(SDL_INIT_VIDEO));

    window =
        sec(SDL_CreateWindow(
                title,
                0, 0, width, height,
                SDL_WINDOW_MAXIMIZED));

    renderer =
        sec(SDL_CreateRenderer(
                window, -1,
                SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED));

	sec(SDL_SetRenderDrawBlendMode(
            renderer,
            SDL_BLENDMODE_BLEND));
}

void Game::loop(void (*update)(struct Context *))
{
    uint32_t prev_ticks = SDL_GetTicks();
    float lag_sec = 0;
    while (!done) {
        uint32_t curr_ticks = SDL_GetTicks();
        float elapsed_sec = (float) (curr_ticks - prev_ticks) / 1000.0f;
        prev_ticks = curr_ticks;
        lag_sec += elapsed_sec;

        // HANDLE INPUT
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
				done = true;
			}

			for (auto a : actions) {
				if (event.key.type == a.ontype && event.key.keysym.sym == a.onkey) {
					a.action(context);
				}
			}

        }

		// UPDATE
		update(context);

        // DRAW
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		for (auto d : drawables) {
			d.draw(renderer);
		}

        SDL_RenderPresent(renderer);
    }
}

void Game::quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
    SDL_Quit();
}

struct Drawable {
	SDL_Surface *surface;
	SDL_Texture *texture;
	SDL_Rect *rect;

	Drawable(SDL_Renderer *renderer, SDL_Rect *rect);
	virtual void draw(SDL_Renderer *renderer);
};

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

struct Action {
	uint32_t ontype;
	SDL_Keycode onkey;
	void (*action)(struct Context *);

	Action(uint32_t, SDL_Keycode, void (*action)(struct Context *));
};

Action::Action(uint32_t type, SDL_Keycode key, void(*func)(struct Context *))
{
	ontype = type;
	onkey = key;
	action = func;
}

}
