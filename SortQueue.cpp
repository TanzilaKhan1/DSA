//25
// 25
//  25
//  25
//  25
#include <iostream>
using namespace std;

struct Queue
{

    struct node
    {
        node *next;
        int val;
    };
    node *head = NULL;
    node *tail = NULL;

    void enqueue(int x)
    {

        // Your code starts here #001
        node *s = new node();
        s->val = x;
        s->next = NULL;
        if (head == NULL)
        {
            head = s;
            tail = s;
        }
        else
        {
            tail->next = s;
            tail = s;
        }

        // Your code ends here #001
    }

    int dequeue()
    {

        // Your code starts here #002
        if (head == NULL)
        {
            return -1;
        }
        int data = head->val;
        if (tail == head)
        {
            free(head);
            head = NULL;
            tail = NULL;
        }
        else
        {
            node *m = head;
            head = head->next;
            free(m);
        }
        return data;

        // Your code ends here #002
    }
};

Queue *sortQueue(Queue *q)
{
    // Your code starts here #003

    Queue *temp = q;
    int add = 1000;

    short int arr[2005];
    for (int i = 0; i < 2005; i++)
    {
        arr[i] = 0;
    }

    int num, ind;
    while (temp->head != NULL)
    {
        num = temp->head->val + add;
        arr[num]++;
        temp->head = temp->head->next;
    }

    temp = NULL;

    Queue *sorted = new Queue;

    for (ind = 0; ind < 2005; ind++)
    {
        num = ind - add;
        while (arr[ind] > 0)
        {
            sorted->enqueue(num);
            arr[ind]--;
        }
    }
    return sorted;

    // Your code ends here #003
}

int main()
{

    Queue *q = new Queue();
    int i, n;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        q->enqueue(value);
    }
    Queue *sq = sortQueue(q);
    for (i = 0; i < n; i++)
    {
        cout << sq->dequeue() << endl;
    }
    return 0;
}
