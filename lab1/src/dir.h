#pragma once

#define __USE_MISC 
#include <dirent.h>

const char* get_dir_path(const int argc, const char* argv[]);

DIR* init_dir(const char* dir_root);
int close_dir(DIR* dir);