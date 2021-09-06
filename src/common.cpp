#include "common.h"


int GetSdlErr(int err_code) {
  fprintf(stderr, "%s\n", SDL_GetError());
  return err_code;
}
