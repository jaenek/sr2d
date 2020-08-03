#include "sr2d.hpp"

const int SCREEN_WIDTH  = 600;
const int SCREEN_HEIGHT = 480;
const int PLAYER_WIDTH  = 40;
const int PLAYER_HEIGHT = 40;
const int PLAYER_SPEED  = 40;

struct Pusher : sr2d::Game {
	struct Context {
		struct Player {
			struct Pos {
				int x, y;
			} pos;
			struct Size {
				int w, h;
			} size;
		} player;
	} ctx;

	Pusher() {
		ctx.player.pos = Context::Player::Pos{SCREEN_WIDTH/2-20, SCREEN_HEIGHT/2-20};
		ctx.player.size = Context::Player::Size{PLAYER_WIDTH, PLAYER_HEIGHT};
	}

	void update() {
		if (getkey(sr2d::Key::UP))
			ctx.player.pos.y -= PLAYER_SPEED;
		if (getkey(sr2d::Key::DOWN))
			ctx.player.pos.y += PLAYER_SPEED;
		if (getkey(sr2d::Key::LEFT))
			ctx.player.pos.x -= PLAYER_SPEED;
		if (getkey(sr2d::Key::RIGHT))
			ctx.player.pos.x += PLAYER_SPEED;

		if (ctx.player.pos.x < 0) ctx.player.pos.x = 0;
		if (ctx.player.pos.y < 0) ctx.player.pos.y = 0;
		if (ctx.player.pos.x > SCREEN_WIDTH - PLAYER_WIDTH) ctx.player.pos.x = SCREEN_WIDTH - PLAYER_WIDTH;
		if (ctx.player.pos.y > SCREEN_HEIGHT - PLAYER_HEIGHT) ctx.player.pos.y = SCREEN_HEIGHT - PLAYER_HEIGHT;

		fillrect(ctx.player.pos.x, ctx.player.pos.y, ctx.player.size.w, ctx.player.size.h);
	}
} game;

int main(void)
{
	game.init("simple grid game", SCREEN_WIDTH, SCREEN_HEIGHT);

	game.coreupdate();

	game.quit();
}
