#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int sig_num,pid;

    printf("Enter the signal number: ");
    scanf("%d", &sig_num);

    printf("Enter the process ID: ");
    scanf("%d", &pid);

    int res = kill(pid, sig_num);
    return 0;
}

