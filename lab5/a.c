#include <stdio.h>

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int isFile(const char* name)
{
    DIR* directory = opendir(name);

    if(directory != NULL)
    {
     closedir(directory);
     return 0;
    }

    if(errno == ENOTDIR)
    {
     return 1;
    }

    return -1;
}

int main(void)
{
    const char* file = "./a";
    const char* directory = "./";

    printf("Is %s a file? %s.\n", file,
     ((isFile(file) == 1) ? "Yes" : "No"));


    return 0;
}