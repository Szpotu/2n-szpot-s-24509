//Napisz program, który utworzy nowy plik z numerem PID aktualnego procesu.
//Jeśli proces otrzyma sygnał SIGUSR1, PPID aktualnie działajcego procesu
// będzie dołączony do pliku. Jeśli zostanie otrzymany sygnał SIGUSR2, plik jest
//czyszczony. Po otrzymaniu któregokolwiek z tych sygnałów, program kończy działanie.


#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
char* fileName = "sgnl.txt";
FILE * file;
static void handler(int);

int main(void)
{

    file = fopen(fileName, "w+");
    int PID = (int)getpid();

    printf("CHILD PID: %d\n", PID);
    fprintf(file, "CHILD PID : %d\n",PID);
    fflush(file); // Niekoniecznie, ale chyba dobry nawyk ?
    fclose(file); // Close stream

    if(signal(SIGUSR1, handler) == SIG_ERR || signal(SIGUSR2, handler) == SIG_ERR)
    {
        printf("Problem: Uncachable signal");
    }
    while(1)
    {
        pause();
    }

}

void handler(int signal){
    if(signal == SIGUSR1) // User defined signal
    {
        int PPID = (int) getppid(); // Get PPID
        file = fopen(fileName,"w+"); // Create stream
        printf("Caught user defined signal 1.\n Actuall PPID process: %d",PPID);//Print actual parent PID
        fprintf(file, "%d",PPID); // Write it into file
        fflush(file); // Clean buffer
        fclose(file); // Close all streams
    }
    else if(signal == SIGUSR2)
    { // Clear File
        printf("\n Caught defined signal 2.\n The file was cleared\n");
        file = fopen(fileName,"w");
        fclose(file);
    }
    else
    {
        perror("Signal");
    }
}
