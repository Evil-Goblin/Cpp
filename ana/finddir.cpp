#include <stdio.h>
#include <io.h>
#include <conio.h>
#include <typeinfo>
#include <string.h>

int isFileOrDir(char* s) {
  _finddatai64_t c_file;
  intptr_t hFile;
  int result;


  if ( (hFile = _findfirsti64(s, &c_file)) == -1L )
    result = -1; // 파일 또는 디렉토리가 없으면 -1 반환
  else
    if (c_file.attrib & _A_SUBDIR)
      result = 0; // 디렉토리면 0 반환
  else
    result = 1; // 그밖의 경우는 "존재하는 파일"이기에 1 반환


  _findclose(hFile);

  return result;
}


int finddir(char* path){
    _finddata_t ffd;
    long handle;
    int result = 1;
    char mmpath[] = {"\\*.*"};
    char hhpath[100];
    sprintf(hhpath,"%s%s",path,mmpath);
    handle = _findfirst(hhpath, &ffd);  //현재 폴더 내 모든 파일을 찾는다.
  
    if (handle == -1)
    {
        printf("There were no files.\n");
        printf("%s\n", "finddir fail");
        return 0;
    }
  
    while (result != -1)
    {
        // if ( !strcmp(ffd.name,"Documents")) {
        //     printf("%s\n", path);
        //     printf("%s\n", "finddir success");
        //     return 1;
        // }
        printf("%s\n", ffd.name);
        // printf("type : ");
        // printf(typeid(ffd.name).name());
        // printf("type : ");
        // printf(typeid("ffd.name").name());
        // printf("\n");
        result = _findnext(handle, &ffd);
    }
  
    // _findclose(handle);
    return 0;
}

int main(int argc, char const *argv[])
{
    _finddata_t fd;
    long handle;
    int result = 1;
    char docu[100];

    char path[] = {"C:\\Users\\"};
    char mpath[] = {"*.*"};
    char hpath[100];
    sprintf(hpath,"%s%s",path,mpath);
    handle = _findfirst(hpath, &fd);  //현재 폴더 내 모든 파일을 찾는다.
  
    if (handle == -1)
    {
        printf("There were no files.\n");
        return 0;
    }
  
    while (result != -1)
    {
        if ( fd.name == "." ) {
            printf("%s\n", ". select");
        }
        char docu[100];
        sprintf(docu,"%s%s",path,fd.name);
        // printf("%s\n", docu);
        if (isFileOrDir(docu) == 0){
            printf("Dir : %s\n", docu);
            // if(finddir(docu) == 1){
            //     // printf("%s\n", docu);
            //     printf("%s\n", "success");
            //     break;
            // }
            int i = finddir(docu);
            printf("%d\n", i);
        }
        printf("%s\n", "--------------------");
        // printf("File: %s\n", fd.name);
        result = _findnext(handle, &fd);
    }
  
    _findclose(handle);

    return 0;
}


// int main(int argc, char const *argv[])
// {
//     _finddata_t fd;
//     long handle;
//     int result = 1;
//     handle = _findfirst("C:\\Users\\stuko\\*.*", &fd);  //현재 폴더 내 모든 파일을 찾는다.
  
//     if (handle == -1)
//     {
//         printf("There were no files.\n");
//         return 0;
//     }
  
//     while (result != -1)
//     {
//         printf("File: %s\n", fd.name);
//         result = _findnext(handle, &fd);
//     }
  
//     _findclose(handle);
//     return 0;
// }