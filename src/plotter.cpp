#include "plotter.h"


explicit Plotter::Plotter(SDL_Renderer* renderer, const SDL_Rect& location, const Ranges& ranges) {
  assert(renderer);

  texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, location.w, location.h);
  if (!texture) {
    GetSdlErr();
    return;
  }

  this->renderer = renderer;
  this->location = location;
  this->ranges = ranges;
}


Plotter::Plotter() {
  SDL_DestroyTexture(texture);
};