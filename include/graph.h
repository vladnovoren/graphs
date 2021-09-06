#ifndef GRAPH_H
#define GRAPH_H

#include "geometry.h"


struct Ranges {
	float min_x;
	float max_x;

	float min_y;
	float max_y;
};

struct CoordSys {
	SDL_Texture* texture;
	SDL_Rect rect;
	Ranges ranges;
	float center_x;
	float center_y;
	float dx;
	float dy;
};

struct Graph {
	SDL_Texture* texture;
	SDL_Rect rect;
	CoordSys coord_sys;
	List vectors;
};



int CoordSys_Init(CoordSys* coord_sys, SDL_Renderer* renderer, const SDL_Rect rect, const Ranges ranges);

int CoordSys_Render(CoordSys* coord_sys, SDL_Renderer* renderer);

float PrettyFunction(float x);

float CoordSys_RealToPixelX(CoordSys* coord_sys, float x);

float CoordSys_RealToPixelY(CoordSys* coord_sys, float y);

int CoordSys_PlotFunc(CoordSys* coord_sys, SDL_Renderer* renderer);

void CoordSys_Destruct(CoordSys* coord_sys);

// Graphs
int Graph_Init(Graph* graph, SDL_Renderer* renderer, const SDL_Rect rect, const Ranges ranges);

int Graph_RenderCopyCoordSys(Graph* graph, SDL_Renderer* renderer);

int Graph_RenderCopyAllToWindow(Graph* graph, SDL_Renderer* renderer);

int Graph_AddVector(Graph* graph, SDL_Renderer* renderer, const Vector vector);

int Graph_Destruct(Graph* graph);


#endif /* graph.h */
