#pragma once

#include <stddef.h>
#include <stdint.h>

#define __USE_MISC 
#include <dirent.h>

typedef struct dirwalk_flags{
    uint8_t display_symbolic_link;
    uint8_t display_directory;
    uint8_t display_files;
    uint8_t is_sort;
}dirwalk_flags;

int get_flags(const int argc, const char* argv[], dirwalk_flags* flags);
void my_dirwalk(DIR* dir,const char* file_path, const dirwalk_flags flags);
