#ifndef APP_H
#define APP_H

#include "graphs.h"


struct App {
	SDL_Window*   window;
	SDL_Renderer* renderer;

  Graph lil_graph;
  Graph big_graph;
};


int App_Init(App* app);


#endif / app.h /