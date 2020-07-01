#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
/*
Napisz program, który utworzy nowy proces. Proces rodzica musi czekać na
 proces potomny, a kiedy ten zostanie zakończony, powinna zostać wyświetlona
 wartość zwrócona z tego procesu. W procesie potomnym, utwórz nowy plik, który
 będzie zawierał liczby z przedziału 9 do 99, które dzielą się przez 3 bez reszty.
 Proces potomny musi zakończyć się ze statusem wyjścia 0, lub 1 w przypadku błędu.
 */
 int main(int argc, char *argv[])
{
    int id = fork();
    int i,p,fd, j =0;
    int numbers[31];
    if(id == 0){

        printf("Child\n");
        p = 1;
        printf("PID: %d, PPID: %d|", getpid(),getppid());
        printf("ID:  %d\n", id);
        }
    else
    {
        wait(&id);
        printf("\nParent\n");
        p = 2;
        printf("PID  %d|PPID: %d|",getpid(), getppid());
        printf("ID:  %d\n", id);
    }


    printf("Number divided with 0 rest: \n");
    for(i = 9; i <= 99; i++)
    {
        if(i % 3 == 0){
                numbers[j] = i;
                printf("%d  |", numbers[j]);
                j++;
        }
    }
    fd = open("ChldPrcsFile.txt",O_CREAT|O_RDWR,0600);
    if(fd == -1)
    {
        perror("File descriptor bug");
        exit(1);
    }
    else
    {
     write(fd, numbers, sizeof(numbers));
     close(fd);
     exit(0);
    }

    printf("Proces %d\n", p);
    return 0;
}

