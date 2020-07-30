namespace sr2d {

void Game::init(const char *title, int width, int height, struct Context *ctx)
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

	context = ctx;
}

void Game::loop(void (*update)(struct Context *), void (*render)(SDL_Renderer*, struct Context *))
{
    Uint32 prev_ticks = SDL_GetTicks();
    float lag_sec = 0;
    while (!done) {
        Uint32 curr_ticks = SDL_GetTicks();
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

        // RENDER
		render(renderer, context);

        SDL_RenderPresent(renderer);
    }
}

void Game::quit()
{
    SDL_Quit();
}

}
