#include "dir.h"

#include <stdio.h>

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