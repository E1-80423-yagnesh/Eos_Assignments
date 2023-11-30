#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/msg.h>

#define MQ_KEY 0x00001234

typedef struct msg {
    long type;
    int numbers[2];
} msg_t;

int main() {
    int ret, s, mqid;

    // Create message queue
    mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
    if (mqid < 0) {
        perror("msgget() failed");
        _exit(1);
    }

    ret = fork();

    if (ret == 0) {
        // Child process
        msg_t m2;
        printf("\nchild: waiting for data from parent...\n");
        msgrcv(mqid, &m2, sizeof(m2.numbers), 99, 0);
        printf("child: received - %d and %d\n", m2.numbers[0], m2.numbers[1]);

        int sum = m2.numbers[0] + m2.numbers[1];
        printf("child: Sum: %d\n", sum);

        m2.type = 33;
        m2.numbers[0] = sum;
        // Sending the sum back to the parent
        msgsnd(mqid, &m2, sizeof(m2.numbers), 0);
    } else {
        // Parent process
        msg_t m1;
        printf("parent: enter two numbers: ");
        scanf("%d %d", &m1.numbers[0], &m1.numbers[1]);
        m1.type = 99;

        // Sending the numbers to the child
        msgsnd(mqid, &m1, sizeof(m1.numbers), 0);

        // Receiving the sum from the child
        msgrcv(mqid, &m1, sizeof(m1.numbers), 33, 0);
        printf("parent: received - %d\n", m1.numbers[0]);

        waitpid(-1, &s, 0);

        // Destroy message queue
        msgctl(mqid, IPC_RMID, NULL);
    }

    return 0;
}

