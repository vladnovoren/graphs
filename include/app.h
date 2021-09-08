#ifndef APP_H
#define APP_H

#include "graph.h"
#include <ctime>

const char* const APP_TITLE = "Graphs";

const int APP_WINDOW_WIDTH  = 1400;
const int APP_WINDOW_HEIGHT = 800;

const int BIG_GRAPH_X = 0;
const int BIG_GRAPH_Y = 0;

const int BIG_GRAPH_WIDTH  = 800;
const int BIG_GRAPH_HEIGHT = 800;

const int LIL_GRAPH_X = 1000;
const int LIL_GRAPH_Y = 0;

const int LIL_GRAPH_WIDTH  = 400;
const int LIL_GRAPH_HEIGHT = 400;


struct App {
	SDL_Window*   window;
	SDL_Renderer* renderer;

  Graph lil_graph;
  Graph big_graph;
};


// App running
int App_Init(App* app);

int App_ClearBlack(App* app);

int App_Exec(App* app);

int App_Deinit(App* app);


#endif /* app.h */
