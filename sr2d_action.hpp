namespace sr2d {

class Action {
private:
	uint32_t ontype;
	SDL_Keycode onkey;
	void (*action)(struct Context *);

public:
	Action(uint32_t, SDL_Keycode, void (*action)(struct Context *));
};

}
