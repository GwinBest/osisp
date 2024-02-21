#pragma once

#define __USE_MISC 
#include <dirent.h>

DIR* init_dir(const char* dir_root);
int close_dir(DIR* dir);