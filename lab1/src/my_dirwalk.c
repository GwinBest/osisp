#include "my_dirwalk.h"

#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>

extern int alphasort();

int get_flags(const int argc, const char* argv[], dirwalk_flags* flags) {
    int is_flag_set = 0;

    char flag;
    while ((flag = getopt(argc, argv, "ldfs")) != -1) {
        switch (flag) {
        case 'l': {
            if (flags->display_symbolic_link) { 
                    printf("warning: flag -l already set\n");
            }
            flags->display_symbolic_link = 1;
            is_flag_set = 1;

            break;
        }
        case 'd': {
            if (flags->display_directory) {
                printf("warning: flag -d already set\n");
            }
            flags->display_directory = 1;
            is_flag_set = 1;

            break;
        }
        case 'f': {
            if (flags->display_files) {
                printf("warning: flag -f already set\n");
            }
            flags->display_files = 1;
            is_flag_set = 1;

            break;
        }
        case 's': {
            if (flags->is_sort) {
                printf("warning: flag -s already set\n");
            }
            flags->is_sort = 1;

            break;
        }
        default: {
            printf("error: flag -%c is undefined.\nAvailable flags -l, -d, -f, -s\n", flag);

            return 1;
        }
        }   
    }

    if (!is_flag_set) {
        flags->display_directory = 1;
        flags->display_files = 1;
        flags->display_symbolic_link = 1;
    }
    
    return 0;
}

void my_dirwalk(DIR* dir, const char* file_path, const dirwalk_flags flags) {
    if (dir == NULL) {
        printf("dir is null\n");
        return;
    }

    struct dirent** dp;
    int files_count = flags.is_sort ? scandir(file_path, &dp, NULL, alphasort) :
        scandir(file_path, &dp, NULL, NULL);

    if (files_count == -1) {
        printf("read dir error\n");
        return;
    }

    for (size_t i = 0; i < files_count; ++i) {
        switch (dp[i]->d_type)
        {
        case DT_DIR: {
            if(!strcmp(dp[i]->d_name, "..") || !strcmp(dp[i]->d_name, ".")) {
                break;
            }

            if(flags.display_directory) {
                printf("%s/%s\n", file_path, dp[i]->d_name);

                char f_path[256];
                sprintf(f_path, "%s/%s", file_path, dp[i]->d_name);
                my_dirwalk(dir, f_path, flags);
            }

            break;
        }     
        case DT_REG: {
            if(flags.display_files) {
                printf("%s/%s\n", file_path, dp[i]->d_name);
            }

            break;
        }
        case DT_LNK: {
            if(flags.display_symbolic_link) {
                printf("%s/%s\n", file_path, dp[i]->d_name);
            }

            break;
        }
        default: {
            printf("%s/%s\n", file_path, dp[i]->d_name);
            
            break;
        }
        }

        free(dp[i]);
    }

    free(dp);
}