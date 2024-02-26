#include "dir.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* const get_dir_path(const int argc, const char* argv[]) {
    for(int i = 1; i < argc; ++i) {
        if(argv[i][0] != '-') {
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
        printf("Cannot open directory %s\n", dir_root);
    }

    return dir;
}

int close_dir(DIR* dir) {
    return closedir(dir);
}