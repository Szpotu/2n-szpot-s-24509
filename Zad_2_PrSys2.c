#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc==2)
    {

        int replace;
        int value;
        int i, fileD;

        fileD = open(argv[1], O_RDONLY);
        for(i = 0; i < 10; i++)
        {
            replace = lseek(fileD, i * sizeof(int),SEEK_SET);
            replace = read(fileD, &value,sizeof(int));
            printf("%d * 3 =  : %d \n",value, value*3);
        }
        close(fileD);
    }
    else
    {
        printf("Za mala liczba argumentow");
        return 1;
    }
    return 0;
}

