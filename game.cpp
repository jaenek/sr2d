#include "sr2d.cpp"

const int SCREEN_WIDTH  = 600;
const int SCREEN_HEIGHT = 480;
const int PLAYER_WIDTH  = 40;
const int PLAYER_HEIGHT = 40;
const int PLAYER_SPEED  = 40;

sr2d::Game game;

struct sr2d::Context {
	struct Player {
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

int main(void)
{
	game.init("simple grid game", SCREEN_WIDTH, SCREEN_HEIGHT);

	game.context = &ctx;
	game.context->player = sr2d::Context::Player{ SDL_Rect{SCREEN_WIDTH/2-20, SCREEN_HEIGHT/2-20, PLAYER_WIDTH, PLAYER_HEIGHT} };

	game.drawables.emplace_back(game.renderer, &game.context->player.rect);

	game.actions.emplace_back(SDL_KEYDOWN, SDLK_UP, moveup);
	game.actions.emplace_back(SDL_KEYDOWN, SDLK_DOWN, movedown);
	game.actions.emplace_back(SDL_KEYDOWN, SDLK_LEFT, moveleft);
	game.actions.emplace_back(SDL_KEYDOWN, SDLK_RIGHT, moveright);

	game.loop(update);

	game.quit();
}
