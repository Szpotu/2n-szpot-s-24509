#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main (int argc, char *argv[])
{
    int i,PID, fd, quotSize;

    if(argc == 2)
    {
        char * fileName = argv[1];
        // Create child process
        pid_t newProcess = fork();
        if(newProcess == 0)// CHILD
        {
            char buffer[50];
            //Open file by descriptor
            fd = open(fileName, O_CREAT|O_RDWR|O_TRUNC,0600);
            for(i = 0; i < 10; i++)
            {
                 PID = (int)getpid();
                // Returns size of sentence and save into buffer
                quotSize = snprintf(buffer, sizeof(buffer),"Wywołanie nr %d. Numer procesu: %d\n",i,PID);
                write(fd, buffer, quotSize);
            }
            close(fd);
            exit(10);
        }
        else if(newProcess > 0)//Parent
        {
            int status;
            wait(&status);
            if(WIFEXITED(status))
            {
                int childStatus = WEXITSTATUS(status);
                printf("Child process exit: %d. \n Program finished sucesfully!\n", childStatus);
            }
        }
        else
        {
            perror("Bug");
            exit(-1);
        }

    }
    else
    {
        perror("Nie podano nazwy pliku");
        exit(-1);
    }
    return 0;
}
