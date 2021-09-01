#ifndef GRAPHS_H
#define GRAPHS_H

#include <SDL2/SDL.h>


struct Graph {
	SDL_Texture* texture;
};



int GetSdlErr();

int Graph_Create(Graph* graph);

int Graph_Destruct(Graph* graph);


#endif /* graphs.h */
