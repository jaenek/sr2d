namespace sr2d {

Action::Action(uint32_t type, SDL_Keycode key, void(*func)(struct Context *))
{
	ontype = type;
	onkey = key;
	action = func;
}

}
