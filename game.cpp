#include "sr2d.hpp"

const int SCREEN_WIDTH  = 600;
const int SCREEN_HEIGHT = 480;
const int PLAYER_WIDTH  = 40;
const int PLAYER_HEIGHT = 40;
const int PLAYER_SPEED  = 40;

struct Pusher : sr2d::Game {
	struct Player {
		struct Pos {
			int x, y;
		} pos;
		struct Size {
			int w, h;
		} size;
	} player;

	Pusher() : Game("Pusher", SCREEN_WIDTH, SCREEN_HEIGHT) {
		player.pos = Player::Pos{SCREEN_WIDTH/2-20, SCREEN_HEIGHT/2-20};
		player.size = Player::Size{PLAYER_WIDTH, PLAYER_HEIGHT};
	}

	void update(float elapsed) {
		if (getkey(sr2d::Key::ESCAPE))
			quit();

		if (getkey(sr2d::Key::UP))
			player.pos.y -= PLAYER_SPEED;
		if (getkey(sr2d::Key::DOWN))
			player.pos.y += PLAYER_SPEED;
		if (getkey(sr2d::Key::LEFT))
			player.pos.x -= PLAYER_SPEED;
		if (getkey(sr2d::Key::RIGHT))
			player.pos.x += PLAYER_SPEED;


		if (player.pos.x < 0) player.pos.x = 0;
		if (player.pos.y < 0) player.pos.y = 0;
		if (player.pos.x > SCREEN_WIDTH - PLAYER_WIDTH) player.pos.x = SCREEN_WIDTH - PLAYER_WIDTH;
		if (player.pos.y > SCREEN_HEIGHT - PLAYER_HEIGHT) player.pos.y = SCREEN_HEIGHT - PLAYER_HEIGHT;

		fillrect(player.pos.x, player.pos.y, player.size.w, player.size.h);
	}
} game;

int main(void)
{
	game.coreupdate();
}
