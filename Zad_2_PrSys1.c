#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{    if(argc== 1|| argc > 2)
    {
        printf("Mozesz wywolac tylko jeden program.");
        return 1;
    }
    time_t t;
    int i, fileD;
    int numbers[10];
    char *fileName = argv[1];

    srand((unsigned)time(&t));

    for(i = 0; i < 10;i++){
       numbers[i] = rand() % 100;
       printf("Number %d: %d \n",i+1, numbers[i]);
    }
    fileD = open(fileName, O_CREAT|O_RDWR|O_APPEND,0600);
    write(fileD, numbers, sizeof(numbers));
    printf("%ld\n",sizeof(numbers));
    close(fileD);

    return 0;
}









