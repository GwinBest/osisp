#include "dir.h"
#include "my_dirwalk.h"

#include <stdio.h>

int main(int argc, char* argv[]) {
    dirwalk_flags flags = {
        .display_directory = 0,
        .display_files = 0,
        .display_symbolic_link = 0,
        .is_sort = 0
    };

    if(get_flags(argc, argv, &flags)) {
        return 1;
    }

    DIR* dir;
    if((dir = init_dir(".")) == 0) {
        return 1;
    }

    my_dirwalk(dir, ".", flags);

    closedir(dir);
    return 0;
}