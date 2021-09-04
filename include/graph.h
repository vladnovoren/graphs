#ifndef GRAPH_H
#define GRAPH_H

#include <SDL2/SDL.h>
#include "geometry.h"


struct CoordSys {
	SDL_Rect graph_rect;

	float min_x;
	float max_x;

	float min_y;
	float max_y;
};


struct Graph {
	CoordSys coord_sys;
	List vectors;
};


int GetSdlErr();

int DrawGraph(SDL_Renderer* renderer, const Graph* graph);


#endif /* graph.h */
