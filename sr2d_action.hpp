namespace sr2d {

class Action {
public:
	uint32_t ontype;
	SDL_Keycode onkey;
	void (*action)(struct Context *);

	Action(uint32_t, SDL_Keycode, void (*action)(struct Context *));
};

}
