#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if (argc != 2) {
        fprintf(stderr, "\x1b[31m""Usage: %s <path_to_file_or_directory>\n", argv[0]);
        return 1; // Indicate an error
    }

    const char *path = argv[1];
    struct stat file_info;

    if (stat(path, &file_info) == 0) {
        if (S_ISREG(file_info.st_mode)) {
            remove(path);
        } 
        else if (S_ISDIR(file_info.st_mode)) {
            rmdir(path);
            
        } 
        else {
            printf("'%s' is neither a regular file nor a directory.\n", path);
        }
    }
    return 0;
    
}