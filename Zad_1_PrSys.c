#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1

int main(int argc, char *argv[])
{


    char buffer[BUFFER_SIZE];
    ssize_t retIn, retOut;
    int fd1, fd2;

    if (argc != 2)
    {
        printf("Not enough elements");
        return -1;
    }

    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1)
    {
        perror("Bug");
        return -1;
    }

    char *fileName = argv[1];
    char *newFile = strcat(fileName,".red.txt");
    fd2 = open(newFile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd2 == -1)
    {
        perror("write");
        return -1;
    }

    // Co trzeci element z lseek
    while ((retIn = read(fd1, &buffer, BUFFER_SIZE)) > 0)
    {
        lseek(fd1, 2, SEEK_CUR);
        retOut = write(fd2, &buffer, BUFFER_SIZE);
    }
 
    close(fd1);
    close(fd2);

    return 0;

}
//for(int i = 0; i < sizeof(buffer); i+=sizeof(buffer[i]))




