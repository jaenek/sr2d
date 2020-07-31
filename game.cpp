#include "sr2d.cpp"

const int SCREEN_WIDTH  = 600;
const int SCREEN_HEIGHT = 480;
const int PLAYER_WIDTH  = 40;
const int PLAYER_HEIGHT = 40;
const int PLAYER_SPEED  = 40;

sr2d::Game game;

struct sr2d::Context {
	struct player {
		SDL_Rect rect;
	} player;
} ctx;

void moveup(struct sr2d::Context *ctx)
{
	ctx->player.rect.y -= PLAYER_SPEED;
}

void movedown(struct sr2d::Context *ctx)
{
	ctx->player.rect.y += PLAYER_SPEED;
}

void moveleft(struct sr2d::Context *ctx)
{
	ctx->player.rect.x -= PLAYER_SPEED;
}

void moveright(struct sr2d::Context *ctx)
{
	ctx->player.rect.x += PLAYER_SPEED;
}

void update(struct sr2d::Context *ctx)
{
	if (ctx->player.rect.x < 0) ctx->player.rect.x = 0;
	if (ctx->player.rect.y < 0) ctx->player.rect.y = 0;
	if (ctx->player.rect.x > SCREEN_WIDTH - PLAYER_WIDTH) ctx->player.rect.x = SCREEN_WIDTH - PLAYER_WIDTH;
	if (ctx->player.rect.y > SCREEN_HEIGHT - PLAYER_HEIGHT) ctx->player.rect.y = SCREEN_HEIGHT - PLAYER_HEIGHT;
}

void render(SDL_Renderer *renderer, struct sr2d::Context *ctx)
{
	auto bgcolor = SDL_Color{0, 0, 0, 255};
	sr2d::sec(SDL_SetRenderDrawColor(renderer, bgcolor.r, bgcolor.g, bgcolor.b, bgcolor.a));
	sr2d::sec(SDL_RenderClear(renderer));

	sr2d::sec(SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255));
	sr2d::sec(SDL_RenderFillRect(renderer, &ctx->player.rect));
}

int main(void)
{
	game.init("simple grid game", SCREEN_WIDTH, SCREEN_HEIGHT, &ctx);

	ctx.player.rect = SDL_Rect{SCREEN_WIDTH/2-20, SCREEN_HEIGHT/2-20, PLAYER_WIDTH, PLAYER_HEIGHT};

	game.actions.emplace_back(SDL_KEYDOWN, SDLK_UP, moveup);
	game.actions.emplace_back(SDL_KEYDOWN, SDLK_DOWN, movedown);
	game.actions.emplace_back(SDL_KEYDOWN, SDLK_LEFT, moveleft);
	game.actions.emplace_back(SDL_KEYDOWN, SDLK_RIGHT, moveright);

	game.loop(update, render);

	game.quit();
}
