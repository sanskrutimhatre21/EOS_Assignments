#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/wait.h>

#define MQ_KEY      0x1234

typedef struct msg {
    long type;
    int a, b, c;
} msg_t;

int main() {
    int mqid, ret, ret2, s;
    mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
    if (mqid < 0) {
        perror("msgget() failed");
        _exit(1);
    }

    ret = fork();
    if (ret == 0) {
        msg_t m1;
        m1.type = 1;

        printf("Child: Enter two numbers: ");
        scanf("%d%d", &m1.a, &m1.b);
        ret = msgsnd(mqid, &m1, sizeof(m1) - sizeof(m1.type), 0);
        printf("Child: Message sent: %d\n", ret);

        msg_t m2;
        printf("Child: Waiting for the result...\n");
        ret2 = msgrcv(mqid, &m2, sizeof(m2) - sizeof(m2.type), 2, 0);
        if (ret2 > 0) {
            printf("Child: Result received: %d + %d = %d\n", m1.a, m1.b, m2.c);
        } else {
            printf("Child: Failed to receive result.\n");
        }

        _exit(0);
    } else {
        msg_t m1, m2;
        printf("Parent: Waiting for the message from the child...\n");
        ret = msgrcv(mqid, &m1, sizeof(m1) - sizeof(m1.type), 1, 0);
        printf("Parent: Message received: %d, %d\n", m1.a, m1.b);
        
        m2.type = 2;
        m2.c = m1.a + m1.b;
        ret = msgsnd(mqid, &m2, sizeof(m2) - sizeof(m2.type), 0);
        printf("Parent: Result sent: %d\n", ret);

        wait(&s);
    }
    msgctl(mqid, IPC_RMID, NULL);

    return 0;
}








