#include "sr2d.cpp"

const int SCREEN_WIDTH  = 600;
const int SCREEN_HEIGHT = 480;
const int PLAYER_WIDTH  = 40;
const int PLAYER_HEIGHT = 40;
const int PLAYER_SPEED  = 10;

sr2d::Game game;

struct sr2d::Context {
	struct player {
		sr2d::Vector pos;
		sr2d::Vector size;
	} player;
} ctx;

void moveup(struct sr2d::Context *ctx)
{
	ctx->player.pos.y -= PLAYER_SPEED;
}

void movedown(struct sr2d::Context *ctx)
{
	ctx->player.pos.y += PLAYER_SPEED;
}

void moveleft(struct sr2d::Context *ctx)
{
	ctx->player.pos.x -= PLAYER_SPEED;
}

void moveright(struct sr2d::Context *ctx)
{
	ctx->player.pos.x += PLAYER_SPEED;
}

void update(struct sr2d::Context *ctx)
{
	if (ctx->player.pos.x < 0) ctx->player.pos.x = 0;
	if (ctx->player.pos.y < 0) ctx->player.pos.y = 0;
	if (ctx->player.pos.x > SCREEN_WIDTH - PLAYER_WIDTH) ctx->player.pos.x = SCREEN_WIDTH - PLAYER_WIDTH;
	if (ctx->player.pos.y > SCREEN_HEIGHT - PLAYER_HEIGHT) ctx->player.pos.y = SCREEN_HEIGHT - PLAYER_HEIGHT;
}

void render(SDL_Renderer *renderer, struct sr2d::Context *ctx)
{
	auto bgcolor = SDL_Color{0, 0, 0, 255};
	sr2d::sec(SDL_SetRenderDrawColor(renderer, bgcolor.r, bgcolor.g, bgcolor.b, bgcolor.a));
	sr2d::sec(SDL_RenderClear(renderer));

	SDL_Rect player = SDL_Rect{
			(int)ctx->player.pos.x, (int)ctx->player.pos.y,
			(int)ctx->player.size.x, (int)ctx->player.size.y
	};
	sr2d::sec(SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255));
	sr2d::sec(SDL_RenderFillRect(renderer, &player));
}

int main(void)
{
	game.init("simple grid game", SCREEN_WIDTH, SCREEN_HEIGHT, &ctx);

	ctx.player.pos = sr2d::Vector(SCREEN_WIDTH/2-20, SCREEN_HEIGHT/2-20);
	ctx.player.size = sr2d::Vector(PLAYER_WIDTH, PLAYER_HEIGHT);

	game.actions.push_back(sr2d::Action{SDL_KEYDOWN, SDLK_UP, moveup});
	game.actions.push_back(sr2d::Action{SDL_KEYDOWN, SDLK_DOWN, movedown});
	game.actions.push_back(sr2d::Action{SDL_KEYDOWN, SDLK_LEFT, moveleft});
	game.actions.push_back(sr2d::Action{SDL_KEYDOWN, SDLK_RIGHT, moveright});

	game.loop(update, render);

	game.quit();
}
