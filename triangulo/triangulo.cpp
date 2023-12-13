#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

void SDLInit(SDL_Window*& window) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL library error" << endl;
    }
    window = SDL_CreateWindow("Triangulo", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        cout << "SDL Window error" << endl;
    } else {
        cout << "SDL Window created" << endl;
    }
}

void SDLShutdown(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

struct App {
  private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool exit;

  public:
    App() {
        SDLInit(this->window);
        this->exit = false;
    }
    ~App() { SDLShutdown(this->window, this->renderer); }

    void render() {
        // SDL_RenderClear(this->renderer);
        // SDL_SetRenderDrawColor(this->renderer, 1.0, 0.0, 0.0, 1.0);
    }

    bool exited() {
        return this->exit;
    }
};

int main(void) {
    cout << "Bienvenido al programa triangulo" << endl;
    App* app = new App();
    while (1) {
         // app->render();   
    }
    delete app;
    return 0;
}
