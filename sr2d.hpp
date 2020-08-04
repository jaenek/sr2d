#include <iostream>
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
	ESCAPE      = SDLK_ESCAPE, // 0x1B ('\033')
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

struct Renderer {
	SDL_Window *window;
	SDL_Renderer *renderer;

	Renderer(const char *title, int width, int height);
	void drawline(int x1, int y1, int x2, int y2);
	void drawrect(int x, int y, int w, int h);
	void fillrect(int x, int y, int w, int h);
};

Renderer::Renderer(const char *title, int width, int height)
{
	sec(SDL_Init(SDL_INIT_VIDEO));

    window = sec(SDL_CreateWindow(title, 0, 0, width, height, SDL_WINDOW_MAXIMIZED));

    renderer = sec(SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED));
	sec(SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND));
}

void Renderer::drawline(int x1, int y1, int x2, int y2)
{
	sec(SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255));
	sec(SDL_RenderDrawLine(renderer, x1, y1, x2, y2));
}

void Renderer::drawrect(int x, int y, int w, int h)
{
	sec(SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255));
	SDL_Rect rect = SDL_Rect{x, y, w, h};
	sec(SDL_RenderDrawRect(renderer, &rect));
}

void Renderer::fillrect(int x, int y, int w, int h)
{
	sec(SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255));
	SDL_Rect rect = SDL_Rect{x, y, w, h};
	sec(SDL_RenderFillRect(renderer, &rect));
}

struct Game : Renderer {
	bool done;
	uint32_t prevticks;
	std::map<Key, bool> keyboardstate;

	Game(const char *title, int width, int height) : Renderer(title, width, height) {};
	float getelapsed();
	bool getkey(Key k);
	void coreupdate();
	virtual void update(float elapsed) {};
	void quit();

};

float Game::getelapsed()
{
	return SDL_GetTicks() - prevticks / 1000.f;
}

bool Game::getkey(Key k)
{
	return keyboardstate[k];
}

void Game::coreupdate()
{
    while (!done) {
		// HANDLE INPUT
		// clear keyboard state map
		for (auto &k : keyboardstate) {
			k.second = false;
		}

		// detect new events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
				done = true;
			}

			// handled events are numubers from 0 to 0x40000052(Key::UP)
			if (event.key.type == SDL_KEYDOWN && event.key.keysym.sym <= Key::UP) {
				keyboardstate[static_cast<Key>(event.key.keysym.sym)] = true;
			}

        }

		// CLEAR
		sec(SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255));
		sec(SDL_RenderClear(renderer));

		// UPDATE
		update(getelapsed());

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
