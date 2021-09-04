#ifndef VECTOR_MAIN_H
#define VECTOR_MAIN_H


struct Vector {
	float start_x;
	float start_y;

	float proj_x;
	float proj_y;
};


typedef Vector ListElemT;

bool VectorsEqual(const Vector* a, const Vector* b);


#endif /* vector_main.h */
