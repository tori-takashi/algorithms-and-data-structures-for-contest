#include <iostream>
#include <cstdio>
#define LEN 100005

typedef struct pp
{
    char name[100];
    int t;
} P;

P Q[LEN + 1];
int head, tail, n;

void enqueue(P x)
{
    Q[tail] = x;
    tail = (tail + 1) % LEN;
}

P dequeue()
{
    P value = Q[head];
    head = (head + 1) % LEN;
    return value;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

bool is_empty()
{
    return head == tail;
}

int main()
{
    int i, q;
    int finished_task_number = 0;
    scanf("%d %d", &n, &q);

    for (i = 1; i <= n; i++)
    {
        scanf("%s", Q[i].name);
        scanf("%d", &Q[i].t);
    }

    int cumulative_time = 0;
    head = 1;
    tail = n + 1;
    while (head != tail)
    {
        P current_task = dequeue();
        int requested_time = min(q, current_task.t);
        current_task.t -= requested_time;
        cumulative_time += requested_time;
        if (current_task.t > 0)
        {
            enqueue(current_task);
        }
        else
        {
            printf("%s %d\n", current_task.name, cumulative_time);
        }
    }

    return 0;
}