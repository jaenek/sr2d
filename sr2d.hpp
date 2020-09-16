#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <SDL2/SDL.h>

namespace sr2d
{

template <typename... T>
void println(T... args)
{
    auto print = [](auto a) {
        std::cerr << a;
    };

    (print(args), ...);
	std::cerr << std::endl;
}

void sec(int code)
{
    if (code < 0) {
        println(stderr, "SDL Error: ", SDL_GetError());
        abort();
    }
}

template <typename T>
T *sec(T *ptr)
{
    if (ptr == nullptr) {
        println(stderr, "SDL Error: ", SDL_GetError());
        abort();
    }
    return ptr;
}

enum Key {
	UNKNOWN      = SDLK_UNKNOWN, // 0x00 ('\0')
	BACKSPACE    = SDLK_BACKSPACE, // 0x08 ('\b')
	TAB          = SDLK_TAB, // 0x09 ('\t')
	RETURN       = SDLK_RETURN, // 0x0D ('\r')
	ESCAPE       = SDLK_ESCAPE, // 0x1B ('\033')
	SPACE        = SDLK_SPACE, // 0x20 (' ')
	EXCLAIM      = SDLK_EXCLAIM, // 0x21 ('!')
	DOUBLEQUOTE  = SDLK_QUOTEDBL, // 0x22 ('"')
	OCTOTHROPE   = SDLK_HASH, // 0x23 ('#')
	DOLLAR       = SDLK_DOLLAR, // 0x24 ('$')
	PERCENT      = SDLK_PERCENT, // 0x25 ('%')
	AMPERSAND    = SDLK_AMPERSAND, // 0x26 ('&')
	QUOTE        = SDLK_QUOTE, // 0x27 ('\'')
	LEFTPAREN    = SDLK_LEFTPAREN, // 0x28 ('(')
	RIGHTPAREN   = SDLK_RIGHTPAREN, // 0x29 (')')
	ASTERISK     = SDLK_ASTERISK, // 0x2A ('*')
	PLUS         = SDLK_PLUS, // 0x2B ('+')
	COMMA        = SDLK_COMMA, // 0x2C (',')
	MINUS        = SDLK_MINUS, // 0x2D ('-')
	PERIOD       = SDLK_PERIOD, // 0x2E ('.')
	SLASH        = SDLK_SLASH, // 0x2F ('/')
	K0           = SDLK_0, // 0x30 ('0')
	K1           = SDLK_1, // 0x31 ('1')
	K2           = SDLK_2, // 0x32 ('2')
	K3           = SDLK_3, // 0x33 ('3')
	K4           = SDLK_4, // 0x34 ('4')
	K5           = SDLK_5, // 0x35 ('5')
	K6           = SDLK_6, // 0x36 ('6')
	K7           = SDLK_7, // 0x37 ('7')
	K8           = SDLK_8, // 0x38 ('8')
	K9           = SDLK_9, // 0x39 ('9')
	COLON        = SDLK_COLON, // 0x3A (':')
	SEMICOLON    = SDLK_SEMICOLON, // 0x3B (';')
	LESS         = SDLK_LESS, // 0x3C ('<')
	EQUALS       = SDLK_EQUALS, // 0x3D ('=')
	GREATER      = SDLK_GREATER, // 0x3E ('>')
	QUESTION     = SDLK_QUESTION, // 0x3F ('?')
	AT           = SDLK_AT, // 0x40 ('@')
	LEFTBRACKET  = SDLK_LEFTBRACKET, // 0x5B ('[')
	BACKSLASH    = SDLK_BACKSLASH, // 0x5C ('\\')
	RIGHTBRACKET = SDLK_RIGHTBRACKET, // 0x5D (']')
	CARET        = SDLK_CARET, // 0x5E ('^')
	UNDERSCORE   = SDLK_UNDERSCORE, // 0x5F ('_')
	BACKQUOTE    = SDLK_BACKQUOTE, // 0x60 ('`')
	A            = SDLK_a, // 0x61 ('a')
	B            = SDLK_b, // 0x62 ('b')
	C            = SDLK_c, // 0x63 ('c')
	D            = SDLK_d, // 0x64 ('d')
	E            = SDLK_e, // 0x65 ('e')
	F            = SDLK_f, // 0x66 ('f')
	G            = SDLK_g, // 0x67 ('g')
	H            = SDLK_h, // 0x68 ('h')
	I            = SDLK_i, // 0x69 ('i')
	J            = SDLK_j, // 0x6A ('j')
	K            = SDLK_k, // 0x6B ('k')
	L            = SDLK_l, // 0x6C ('l')
	M            = SDLK_m, // 0x6D ('m')
	N            = SDLK_n, // 0x6E ('n')
	O            = SDLK_o, // 0x6F ('o')
	P            = SDLK_p, // 0x70 ('p')
	Q            = SDLK_q, // 0x71 ('q')
	R            = SDLK_r, // 0x72 ('r')
	S            = SDLK_s, // 0x73 ('s')
	T            = SDLK_t, // 0x74 ('t')
	U            = SDLK_u, // 0x75 ('u')
	V            = SDLK_v, // 0x76 ('v')
	W            = SDLK_w, // 0x77 ('w')
	X            = SDLK_x, // 0x78 ('x')
	Y            = SDLK_y, // 0x79 ('y')
	Z            = SDLK_z, // 0x7A ('z')
	DELETE       = SDLK_DELETE, // 0x7F ('\177')
	CAPSLOCK     = SDLK_CAPSLOCK, // 0x40000039
	F1           = SDLK_F1, // 0x4000003A
	F2           = SDLK_F2, // 0x4000003B
	F3           = SDLK_F3, // 0x4000003C
	F4           = SDLK_F4, // 0x4000003D
	F5           = SDLK_F5, // 0x4000003E
	F6           = SDLK_F6, // 0x4000003F
	F7           = SDLK_F7, // 0x40000040
	F8           = SDLK_F8, // 0x40000041
	F9           = SDLK_F9, // 0x40000042
	F10          = SDLK_F10, // 0x40000043
	F11          = SDLK_F11, // 0x40000044
	F12          = SDLK_F12, // 0x40000045
	PRINTSCREEN  = SDLK_PRINTSCREEN, // 0x40000046
	SCROLLLOCK   = SDLK_SCROLLLOCK, // 0x40000047
	PAUSE        = SDLK_PAUSE, // 0x40000048
	INSERT       = SDLK_INSERT, // 0x40000049
	HOME         = SDLK_HOME, // 0x4000004A
	PAGEUP       = SDLK_PAGEUP, // 0x4000004B
	END          = SDLK_END, // 0x4000004D
	PAGEDOWN     = SDLK_PAGEDOWN, // 0x4000004E
	RIGHT        = SDLK_RIGHT, // 0x4000004F
	LEFT         = SDLK_LEFT, // 0x40000050
	DOWN         = SDLK_DOWN, // 0x40000051
	UP           = SDLK_UP // 0x40000052
};

struct KeyState {
	bool pressed;
	bool held;
	bool released;
};

struct Vec2i {
	int x, y;

	Vec2i(int x, int y) { this->x = x; this->y = y; }
};

struct Color {
	uint8_t r, g, b, a;

	Color(int r, int g, int b, int a=255) { this->r = r; this->g = g; this->b = b; this->a = a; };
};

static const Color RED(255, 0, 0), GREEN(0, 255, 0), BLUE(0, 0, 255), WHITE(255, 255, 255), BLACK(0, 0, 0), BLANK(0, 0, 0, 0);

struct Rect {
	int x, y, w, h;

	Rect(int x, int y, int s) { this->x = x; this->y = y; this->w = s; this->h = s; }
	Rect(int x, int y, int w, int h) { this->x = x; this->y = y; this->w = w; this->h = h; }
	SDL_Rect toSDL() { return SDL_Rect{x, y, w, h}; }
	Vec2i center() { return Vec2i(x+w/2, y+h/2); }
};

struct Texture : Rect {
	uint32_t id;

	Texture(const char *filename, int x=0, int y=0) : Rect(x, y, 0) { init(filename); };
	void init(const char *filename);
};

struct Animation : Rect {
	Rect *src;
	uint32_t id;
	uint8_t framerate;
	int texturewidth;
	float last;

	Animation(const char *filename, int framewidth, int framerate, int x=0, int y=0) : Rect(x, y, 0) { init(filename, framewidth, framerate, x, y); };
	void init(const char *filename, int framewidth, int framerate, int x, int y);
};

struct Grid : Rect {
	uint32_t columns, rows;
	int cw, ch;
	std::map<char, Texture*> lookup;
	std::vector<Texture*> cells;

	Grid(uint32_t nx, uint32_t ny, int w, int h) : Rect(0, 0, nx*w, ny*h) { init(nx, ny, w, h); };
	Grid(int x, int y, int nx, int ny, int w, int h) : Rect(x, y, nx*w, ny*h) { init(nx, ny, w, h); };
	void init(uint32_t nx, uint32_t ny, int cw, int ch);
	void createfromtext(std::string text);
};

struct Game {
	SDL_Window *window;
	SDL_Renderer *renderer;
	std::vector<SDL_Texture*> textures;
	std::map<Key, KeyState> keyboardstate;
	bool done;

	uint32_t createtexture(int width, int height);
	void updatetexture(uint32_t id, SDL_Surface *surface);
	float getelapsed();
	void quit();

	Game(const char *title, int width, int height);
	void drawline(int x1, int y1, int x2, int y2, Color color);
	void drawrect(Rect *r, Color c);
	void fillrect(Rect *r, Color c);
	void drawtexture(Texture *t);
	void drawanimation(Animation *a);
	void drawgrid(Grid *g);
	KeyState getkey(Key k);
	virtual void update(float elapsed) {};
	void coreupdate();

};

static Game *_game;

void Texture::init(const char *filename)
{
	SDL_Surface *surface = sec(SDL_LoadBMP(filename));

	w = surface->w;
	h = surface->h;
	id = _game->createtexture(w, h);

	_game->updatetexture(id, surface);

	SDL_FreeSurface(surface);
}

void Animation::init(const char *filename, int framewidth, int framerate, int x, int y)
{
	SDL_Surface *surface = sec(SDL_LoadBMP(filename));

	this->x = x;
	this->y = y;
	w = framewidth;
	h = surface->h;
	this->framerate = framerate;
	texturewidth = surface->w;
	id = _game->createtexture(surface->w, h);

	_game->updatetexture(id, surface);

	SDL_FreeSurface(surface);

	src = new Rect(0,0, framewidth, h);
}

void Grid::init(uint32_t columns, uint32_t rows, int width, int height)
{
	this->columns = columns;
	this->rows = rows;

	cw = width/columns;
	ch = height/rows;

	cells.resize(rows*columns);
}

void Grid::createfromtext(std::string text)
{
	if (text.size() > rows*columns) {
		println("Error: text argument is to long (", text.size(), "), expected maximum size = ", rows*columns, "(", columns, "x", rows, ")");
		abort();
	}

	uint32_t i = 0;
	for (auto c : text) {
		auto el = lookup.find(c);
		if (el != lookup.end()) {
			cells[i] = el->second;
		}
		i++;
	}
}

Game::Game(const char *title, int width, int height)
{
	_game = this;

	sec(SDL_Init(SDL_INIT_VIDEO));

    window = sec(SDL_CreateWindow(title, 0, 0, width, height, SDL_WINDOW_MAXIMIZED));

    renderer = sec(SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED));
	sec(SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND));
}

float Game::getelapsed()
{
	return SDL_GetTicks() / 1000.f;
}

uint32_t Game::createtexture(int width, int height) {
	textures.emplace_back(SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height));
	return textures.size() - 1;
}

void Game::updatetexture(uint32_t id, SDL_Surface *surface) {
	sec(SDL_LockSurface(surface));
	sec(SDL_UpdateTexture(textures[id], nullptr, surface->pixels, surface->pitch));
	SDL_UnlockSurface(surface);
}

void Game::drawline(int x1, int y1, int x2, int y2, Color c)
{
	sec(SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a));
	sec(SDL_RenderDrawLine(renderer, x1, y1, x2, y2));
}

void Game::drawrect(Rect *r, Color c)
{
	sec(SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a));
	SDL_Rect rect = r->toSDL();
	sec(SDL_RenderDrawRect(renderer, &rect));
}

void Game::fillrect(Rect *r, Color c)
{
	sec(SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a));
	SDL_Rect rect = r->toSDL();
	sec(SDL_RenderFillRect(renderer, &rect));
}

void Game::drawtexture(Texture *t)
{
	SDL_Rect dest = t->toSDL();
	sec(SDL_RenderCopy(renderer, textures[t->id], nullptr, &dest));
}

void Game::drawanimation(Animation *a)
{
	float time = _game->getelapsed();
	if ((time - a->last) > 1./a->framerate) {
		a->src->x += a->w;
		if (a->src->x >= a->texturewidth) {
			a->src->x = 0;
		}
		a->last = time;
	}

	SDL_Rect src = a->src->toSDL();
	SDL_Rect dest = a->toSDL();
	sec(SDL_RenderCopy(renderer, textures[a->id], &src, &dest));
}

void Game::drawgrid(Grid *g)
{
	for (uint32_t i = 0; i < g->cells.size(); i++) {
		if (g->cells[i] != nullptr) {
			g->cells[i]->x = (i%g->columns)*g->cw;
			g->cells[i]->y = (i/g->columns)*g->ch;
			drawtexture(g->cells[i]);
		}
	}
}

KeyState Game::getkey(Key k)
{
	return keyboardstate[k];
}

void Game::coreupdate()
{
    while (!done) {
		// HANDLE INPUT
		// update keyboard state map
		for (auto &k : keyboardstate) {
			k.second.pressed = false;
		}

		// detect new events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
				done = true;
			}

			// handled events are numubers from 0 to 0x40000052(Key::UP)
			if (event.key.type == SDL_KEYDOWN && event.key.keysym.sym <= Key::UP) {
				keyboardstate[static_cast<Key>(event.key.keysym.sym)].pressed = true;
				keyboardstate[static_cast<Key>(event.key.keysym.sym)].held = true;
			}

			if (event.key.type == SDL_KEYUP && event.key.keysym.sym <= Key::UP) {
				keyboardstate[static_cast<Key>(event.key.keysym.sym)].held = false;
				keyboardstate[static_cast<Key>(event.key.keysym.sym)].released = true;
			}

        }

		// CLEAR
		sec(SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255));
		sec(SDL_RenderClear(renderer));

		// UPDATE
		update(_game->getelapsed());

		// RENDER
        SDL_RenderPresent(renderer);
    }
}

void Game::quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
    SDL_Quit();
	exit(EXIT_SUCCESS);
}
}
