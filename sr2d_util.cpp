namespace sr2d {

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

}
