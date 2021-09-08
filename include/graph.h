#ifndef GRAPH_H
#define GRAPH_H

#include "geometry.h"


// struct Ranges {
// 	double min_x;
// 	double max_x;

// 	double min_y;
// 	double max_y;
// };

struct CoordSys {
	SDL_Texture* texture;
	SDL_Rect rect;
	Ranges ranges;
	double center_x;
	double center_y;
	double dx;
	double dy;
};

struct Graph {
	SDL_Texture* texture;
	SDL_Rect rect;
	CoordSys coord_sys;
	List vectors;
};



int CoordSys_Init(CoordSys* coord_sys, SDL_Renderer* renderer, const SDL_Rect rect, const Ranges ranges);

int CoordSys_Render(CoordSys* coord_sys, SDL_Renderer* renderer);

double PrettyFunction(double x);

double CoordSys_RealToPixelX(CoordSys* coord_sys, double x);

double CoordSys_RealToPixelY(CoordSys* coord_sys, double y);

int CoordSys_PlotFunc(CoordSys* coord_sys, SDL_Renderer* renderer);

void CoordSys_Destruct(CoordSys* coord_sys);

// Graphs
int Graph_Init(Graph* graph, SDL_Renderer* renderer, const SDL_Rect rect, const Ranges ranges);

int Graph_RenderCopyCoordSys(Graph* graph, SDL_Renderer* renderer);

int Graph_RenderCopyAllToWindow(Graph* graph, SDL_Renderer* renderer);

int Graph_AddVector(Graph* graph, SDL_Renderer* renderer, const Vector vector);

int Graph_Destruct(Graph* graph);


#endif /* graph.h */
