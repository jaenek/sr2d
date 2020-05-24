const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 480;

Game game = {};

int main(void)
{
    sec(SDL_Init(SDL_INIT_VIDEO));

    SDL_Window *window =
        sec(SDL_CreateWindow(
                "sr2d",
                0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
                SDL_WINDOW_RESIZABLE));

    SDL_Renderer *renderer =
        sec(SDL_CreateRenderer(
                window, -1,
                SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED));

    sec(SDL_SetRenderDrawBlendMode(
            renderer,
            SDL_BLENDMODE_BLEND));

    Uint32 prev_ticks = SDL_GetTicks();
    float lag_sec = 0;
    while (!game.quit) {
        Uint32 curr_ticks = SDL_GetTicks();
        float elapsed_sec = (float) (curr_ticks - prev_ticks) / 1000.0f;
        prev_ticks = curr_ticks;
        lag_sec += elapsed_sec;

        // HANDLE INPUT
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
				case SDL_QUIT: {
					game.quit = true;
				} break;

				case SDL_KEYDOWN: {
					switch (event.key.keysym.sym) {
						case SDLK_SPACE: {
							if (!event.key.repeat) {
								//game.entity_jump({PLAYER_ENTITY_INDEX});
							}
						} break;
					}
				} break;
			}
        }

        // RENDER
        sec(SDL_SetRenderDrawColor(renderer, 1, 174, 216, 255));
        sec(SDL_RenderClear(renderer));
        //game.render(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();

	return 0;
}
