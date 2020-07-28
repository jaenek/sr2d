namespace sr2d {

class Grid {
private:
	std::vector<Cell> cells;

public:
	Grid(int x, int y, int width, int height, int marginx, int marginy);
	Cell cellfrompoint(SDL_Point point);
}

}
