#include "sr2d.hpp"

const int SCREEN_WIDTH  = 600;
const int SCREEN_HEIGHT = 480;
const int PLAYER_SIZE  = 40;
const int PLAYER_SPEED  = 40;

struct Pusher : sr2d::Game {
	sr2d::Animation *player;
	sr2d::Texture *block;
	sr2d::Grid *grid;

	Pusher() : Game("Pusher", SCREEN_WIDTH, SCREEN_HEIGHT) {
		player = new sr2d::Animation("pepper_animation.bmp", PLAYER_SIZE, 12, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

		block = new sr2d::Texture("block.bmp");

		grid = new sr2d::Grid(SCREEN_WIDTH/block->w, SCREEN_HEIGHT/block->h, SCREEN_WIDTH, SCREEN_HEIGHT);
		grid->lookup.insert({'#', block});
		grid->createfromtext(
			"###############"
			"#             #"
			"#             #"
			"# ####   #### #"
			"#             #"
			"#    #####    #"
			"#             #"
			"#  ##     ##  #"
			"#    ## ##    #"
			"#             #"
			"#    #   #    #"
			"###############");
	}

	void update(float elapsed) {
		if (getkey(sr2d::ESCAPE).pressed)
			quit();

		if (getkey(sr2d::Key::UP).pressed)
			player->y -= PLAYER_SPEED;
		if (getkey(sr2d::DOWN).pressed)
			player->y += PLAYER_SPEED;
		if (getkey(sr2d::LEFT).pressed)
			player->x -= PLAYER_SPEED;
		if (getkey(sr2d::RIGHT).pressed)
			player->x += PLAYER_SPEED;

		if (player->x < 0) player->x = 0;
		if (player->y < 0) player->y = 0;
		if (player->x > SCREEN_WIDTH - player->w) player->x = SCREEN_WIDTH - player->w;
		if (player->y > SCREEN_HEIGHT - player->h) player->y = SCREEN_HEIGHT - player->h;

		drawgrid(grid);
		drawanimation(player);
	}
} game;

int main(void)
{
	game.coreupdate();
}
