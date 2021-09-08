#ifndef APP_H
#define APP_H

#include "plotter.h"
#include <ctime>

const char* const APP_TITLE = "Graphs";

const int APP_WINDOW_WIDTH  = 1400;
const int APP_WINDOW_HEIGHT = 800;

const SDL_Rect BIG_PLOT_LOCATION = {
  0,
  0,
  800,
  800
};

const SDL_Rect LIL_PLOT_LOCATION = {
  1000,
  0,
  400,
  400
};

const int BIG_PLOT_X = 0;
const int BIG_PLOT_Y = 0;

const int BIG_PLOT_WIDTH  = 800;
const int BIG_PLOT_HEIGHT = 800;

const int LIL_PLOT_X = 1000;
const int LIL_PLOT_Y = 0;

const int LIL_PLOT_WIDTH  = 400;
const int LIL_PLOT_HEIGHT = 400;


class App {
 private:
	SDL_Window*   window;
	SDL_Renderer* renderer;
 public:
  App();

  void ClearBack();

  void Exec();

  ~App();
};


// App running
int App_Init(App* app);

int App_ClearBlack(App* app);

int App_Exec(App* app);

int App_Deinit(App* app);


#endif /* app.h */
