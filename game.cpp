#include "sr2d.hpp"

const int SCREEN_WIDTH  = 600;
const int SCREEN_HEIGHT = 480;
const int PLAYER_WIDTH  = 40;
const int PLAYER_HEIGHT = 40;
const int PLAYER_SPEED  = 40;

struct Pusher : sr2d::Game {
	struct Context {
		struct Player {
			SDL_Rect rect;
		} player;
	} ctx;

	Pusher() {
		ctx.player.rect = SDL_Rect{SCREEN_WIDTH/2-20, SCREEN_HEIGHT/2-20, PLAYER_WIDTH, PLAYER_HEIGHT};
	}

	void update() {
		if (getkey(sr2d::Key::UP))
			ctx.player.rect.y -= PLAYER_SPEED;
		if (getkey(sr2d::Key::DOWN))
			ctx.player.rect.y += PLAYER_SPEED;
		if (getkey(sr2d::Key::LEFT))
			ctx.player.rect.x -= PLAYER_SPEED;
		if (getkey(sr2d::Key::RIGHT))
			ctx.player.rect.x += PLAYER_SPEED;

		if (ctx.player.rect.x < 0) ctx.player.rect.x = 0;
		if (ctx.player.rect.y < 0) ctx.player.rect.y = 0;
		if (ctx.player.rect.x > SCREEN_WIDTH - PLAYER_WIDTH) ctx.player.rect.x = SCREEN_WIDTH - PLAYER_WIDTH;
		if (ctx.player.rect.y > SCREEN_HEIGHT - PLAYER_HEIGHT) ctx.player.rect.y = SCREEN_HEIGHT - PLAYER_HEIGHT;
	}
} game;

int main(void)
{
	game.init("simple grid game", SCREEN_WIDTH, SCREEN_HEIGHT);

	game.drawables.emplace_back(game.renderer, &game.ctx.player.rect);

	game.coreupdate();

	game.quit();
}
