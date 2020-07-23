namespace sr2d {

void Game::init(int width, int height)
{
	sr2d::sec(SDL_Init(SDL_INIT_VIDEO));

    this->window =
        sr2d::sec(SDL_CreateWindow(
                "sr2d",
                0, 0, width, height,
                SDL_WINDOW_RESIZABLE));

    this->renderer =
        sr2d::sec(SDL_CreateRenderer(
                this->window, -1,
                SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED));

	sr2d::sec(SDL_SetRenderDrawBlendMode(
            this->renderer,
            SDL_BLENDMODE_BLEND));
}

void Game::loop()
{
    Uint32 prev_ticks = SDL_GetTicks();
    float lag_sec = 0;
    while (!this->done) {
        Uint32 curr_ticks = SDL_GetTicks();
        float elapsed_sec = (float) (curr_ticks - prev_ticks) / 1000.0f;
        prev_ticks = curr_ticks;
        lag_sec += elapsed_sec;

        // HANDLE INPUT
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
				case SDL_QUIT: {
					this->done = true;
				} break;

				case SDL_KEYDOWN: {
					switch (event.key.keysym.sym) {
						case SDLK_SPACE: {
							if (!event.key.repeat) {
								//e.entity_jump({PLAYER_ENTITY_INDEX});
							}
						} break;
					}
				} break;
			}
        }

        // RENDER
        sec(SDL_SetRenderDrawColor(this->renderer, 1, 174, 216, 255));
        sec(SDL_RenderClear(this->renderer));
        SDL_RenderPresent(this->renderer);
    }
}

void Game::quit()
{
    SDL_Quit();
}

}
