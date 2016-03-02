#include "my.h"

int is_dir(const char *path)
{
    struct stat path_stat;
    lstat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

int is_file(const char *path)
{
    struct stat path_stat;
    lstat(path, &path_stat);
    return S_ISLNK(path_stat.st_mode) || S_ISREG(path_stat.st_mode);
}