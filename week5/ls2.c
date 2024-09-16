#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int checkL(int argc, char *argv[]);
void showStatInfo(const char *fname, struct stat *buf);
void doLs(const char * dirName, int l);

int main(int argc, char *argv[])
{
    if (argc == 1){
        doLs(".", 0);
    }else{
        int l = checkL(argc, argv);
	  if (argc==2 && l == 1){
            doLs(".", 1);
        }
        while(--argc){
            if (strcmp(*++argv, "-l")!=0 ){
                printf("\n%s:\n", *argv);
                doLs(*argv, l);
            }    
        }
    }

}
/**
 * @brief List file in directory 
 * 
 * @param dirName name of directory
 */
void doLs(const char * dirName, int l)
{
    DIR *pDir;
    struct dirent *pEntry;

    if ((pDir = opendir(dirName))==NULL){
        perror("Opening directory");
    }else{
        while ((pEntry = readdir(pDir))!=NULL){
            if (l && pEntry->d_name[0] != '.'){
                struct stat info; 
                printf("%s\n", pEntry->d_name);
                stat(pEntry->d_name, &info) ;
                showStatInfo(pEntry->d_name, &info);
            }else if(pEntry->d_name[0] != '.'){
                printf("%s\n", pEntry->d_name);
            }
        }
    }
    closedir(pDir);
}


void showStatInfo(const char *fname, struct stat *buf)
{
    printf("   mode: %o\n", buf->st_mode);
    printf("   links: %ld\n", buf->st_nlink);
    printf("   user: %d\n", buf->st_uid);
    printf("   group: %d\n", buf->st_gid);
    printf("   size: %ld\n", buf->st_size);
    printf("   modtime: %ld\n", buf->st_mtime);
    printf("   name: %s\n", fname);
}

int checkL(int argc, char *argv[])
{
    for (int i =1; i<argc; i++){
        if (strcmp(argv[i],"-l")==0){
            return 1;
        }
    }
    return 0;
}


