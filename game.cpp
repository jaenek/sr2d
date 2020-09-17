#include "sr2d.hpp"

const int SCREEN_WIDTH  = 600;
const int SCREEN_HEIGHT = 480;
const int PLAYER_SIZE  = 40;
const int PLAYER_SPEED  = 5;
const int PLAYER_MAX_SPEED  = 40;

struct Pusher : sr2d::Game {
	int velx, vely;
	sr2d::Animation *player;
	sr2d::Texture *block;
	sr2d::Grid *grid;

	Pusher() : Game("Pusher", SCREEN_WIDTH, SCREEN_HEIGHT) {
		player = new sr2d::Animation("pepper_animation.bmp", PLAYER_SIZE, 12, 40, 40);

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
			if (abs(vely) < PLAYER_MAX_SPEED)
				vely -= PLAYER_SPEED;
		if (getkey(sr2d::DOWN).pressed)
			if (abs(vely) < PLAYER_MAX_SPEED)
				vely += PLAYER_SPEED;
		if (getkey(sr2d::LEFT).pressed)
			if (abs(velx) < PLAYER_MAX_SPEED)
				velx -= PLAYER_SPEED;
		if (getkey(sr2d::RIGHT).pressed)
			if (abs(velx) < PLAYER_MAX_SPEED)
				velx += PLAYER_SPEED;

		player->x += velx;
		player->y += vely;

		if (grid->boxintersection(player)) {
			sr2d::println("collision: ", player->x, ",", player->y);
			player->x -= velx;
			player->y -= vely;
		}

		if (velx > 0) velx--;
		if (velx < 0) velx++;
		if (vely > 0) vely--;
		if (vely < 0) vely++;


		drawgrid(grid);
		drawanimation(player);
	}
} game;

int main(void)
{
	game.coreupdate();
}
