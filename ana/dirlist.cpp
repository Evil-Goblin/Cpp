#include <stdio.h>
#include <io.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    _finddata_t fd;
    long handle;
    int result = 1;
    char path[] = {"C:\\Users\\All Users\\Documents\\*.*"};
    // char docu[100];

    // char path[] = {"C:\\Users\\"};;
    // char mpath[] = {"*.*"};;
    // char hpath[100];
    // sprintf(hpath,"%s%s",path,mpath);
    handle = _findfirst(path, &fd);  //현재 폴더 내 모든 파일을 찾는다.
  
    if (handle == -1)
    {
        printf("There were no files.\n");
        // return 0;
    }
    printf("%s\n", path);
  
    while (result != -1)
    {
        printf("File: %s\n", fd.name);
        result = _findnext(handle, &fd);
    }
    printf("\n\n====================================\n==================================\n\n");

    result = 1;
    char path1[] = {"C:\\Users\\Default\\Documents\\*.*"};
    // char docu[100];

    // char path[] = {"C:\\Users\\"};;
    // char mpath[] = {"*.*"};;
    // char hpath[100];
    // sprintf(hpath,"%s%s",path,mpath);
    handle = _findfirst(path1, &fd);  //현재 폴더 내 모든 파일을 찾는다.
  
    if (handle == -1)
    {
        printf("There were no files.\n");
        // return 0;
    }
    printf("%s\n", path1);
  
    while (result != -1)
    {
        printf("File: %s\n", fd.name);
        result = _findnext(handle, &fd);
    }
    printf("\n\n====================================\n==================================\n\n");
    
    result = 1;
    char path2[] = {"C:\\Users\\Default\\Documents\\*.*"};
    // char docu[100];

    // char path[] = {"C:\\Users\\"};;
    // char mpath[] = {"*.*"};;
    // char hpath[100];
    // sprintf(hpath,"%s%s",path,mpath);
    handle = _findfirst(path2, &fd);  //현재 폴더 내 모든 파일을 찾는다.
  
    if (handle == -1)
    {
        printf("There were no files.\n");
        // return 0;
    }
    printf("%s\n", path2);
  
    while (result != -1)
    {
        printf("File: %s\n", fd.name);
        result = _findnext(handle, &fd);
    }
    printf("\n\n====================================\n==================================\n\n");
    result = 1;
    char path3[] = {"C:\\Users\\stuko\\Documents\\*.*"};
    // char docu[100];

    // char path[] = {"C:\\Users\\"};;
    // char mpath[] = {"*.*"};;
    // char hpath[100];
    // sprintf(hpath,"%s%s",path,mpath);
    handle = _findfirst(path3, &fd);  //현재 폴더 내 모든 파일을 찾는다.
  
    if (handle == -1)
    {
        printf("There were no files.\n");
        // return 0;
    }
    printf("%s\n", path3);
  
    while (result != -1)
    {
        printf("File: %s\n", fd.name);
        result = _findnext(handle, &fd);
    }
    _findclose(handle);

    return 0;
}