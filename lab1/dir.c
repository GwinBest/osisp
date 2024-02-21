#include "dir.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* const get_dir_path(const int argc, const char* argv[]) {
    char path = NULL;
    for(size_t i = 1; i < argc; ++i) {
        if(argv[i][0] == '/' && argv[i][1] == '\0') {
            return "/";
        }

        if(argv[i][0] == '.') {
            return argv[i];
        }
    }
    
    return ".";
}

DIR* init_dir(const char* dir_root) {
    if(dir_root == 0) {
        dir_root = ".";
    }

    DIR* dir;
    if((dir = opendir(dir_root)) == 0) {
        perror("Cannot open directory");
    }

    return dir;
}

int close_dir(DIR* dir) {
    return closedir(dir);
}