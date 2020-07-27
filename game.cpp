#include "sr2d.cpp"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 480;

sr2d::Game game;

struct sr2d::Context {
	struct player {
		struct pos {
			float x;
			float y;
		} pos;
		float w;
		float h;
	} player;
} ctx;

void move(struct sr2d::Context *ctx) {
	ctx->player.pos.y += 1;
}

void render(SDL_Renderer *renderer, struct sr2d::Context *ctx) {
	SDL_Rect player = SDL_Rect{
			(int)ctx->player.pos.x, (int)ctx->player.pos.y,
			(int)ctx->player.w, (int)ctx->player.h
	};
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &player);
}

int main(void)
{
	game.init("simple grid game", SCREEN_WIDTH, SCREEN_HEIGHT, &ctx);

	ctx.player.w = 40;
	ctx.player.h = 40;
	ctx.player.pos.x = SCREEN_WIDTH/2-20;
	ctx.player.pos.y = SCREEN_HEIGHT/2-20;

	game.loop(render);

	game.quit();
}
