#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int checkL(int argc, char *argv[]);
void showStatInfo(const char *fname, struct stat *buf);
void doLs(const char * dirName, int l);
void modeToLetters(int mode, char str[]);

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
    char s[11];
    modeToLetters(buf->st_mode, s);
    printf("   mode: %s\n", s);

    printf("   links: %ld\n", buf->st_nlink);

    printf("   user: %d\n", buf->st_uid);
    struct passwd *uPtr = getpwuid(buf->st_uid);
    printf("   user: %s\n", uPtr->pw_name);

    printf("   group: %d\n", buf->st_gid);
    struct group * gPtr = getgrgid(buf->st_gid);
    printf("   group: %s\n", gPtr->gr_name);

    printf("   size: %ld\n", buf->st_size);
    printf("   modtime: %ld\n", buf->st_mtime);
    printf("   modtime: %.12s\n", 4 + ctime(&buf->st_mtime));

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
void modeToLetters(int mode, char str[])
{
    strcpy(str, "----------");
    switch (mode & __S_IFMT) 
    {
        case __S_IFBLK:  str[0] = 'b';    break;
        case __S_IFCHR:  str[0] = 'c';    break;
        case __S_IFDIR:  str[0] = 'd';    break;
        case __S_IFIFO:  str[0] = 'p';    break;
        case __S_IFLNK:  str[0] = 'l';    break;
        case __S_IFREG:                   break;
        case __S_IFSOCK: str[0] = 's';    break;
        default:       printf("unknown?\n");  
    }

    //3 bits for user
    if (mode & S_IRUSR) //NOTE bitwice AND, not logical
        str[1] = 'r';
    if (mode & S_IWUSR) 
        str[2] = 'w';
    if (mode & S_IXUSR) 
        str[3] = 'x';

    //3 bits for group
    if (mode & S_IRGRP) str[4] = 'r';
    if (mode & S_IWGRP) str[5] = 'w';
    if (mode & S_IXGRP) str[6] = 'x';

    //3 bits for other
    if (mode & S_IROTH) str[7] = 'r';
    if (mode & S_IWOTH) str[8] = 'w';
    if (mode & S_IXOTH) str[9] = 'x';

}



