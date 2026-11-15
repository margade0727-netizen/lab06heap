#include "DS.h"

static void swim(Heap *p, int);
static void sink(Heap *p, int);

int less(const Msg *a, const Msg *b)
{
        if (a->priority != b->priority)
                return a->priority < b->priority;
        return a->time < b->time;
}

void insert(Heap *p, const Msg x)
{
        if (p->h_len >= 100000)
                return;
        p->h_arr[p->h_len++] = x;
        swim(p, p->h_len - 1);
}

static void swim(Heap *p, int k)
{
        Msg tmp;
        while (k > 0 && less(&p->h_arr[k], &p->h_arr[(k - 1) / 2])) {
                tmp = p->h_arr[k];
                p->h_arr[k] = p->h_arr[(k - 1) / 2];
                p->h_arr[(k - 1) / 2] = tmp;
                k = (k - 1) / 2;
        }
}

static void sink(Heap *p, int k)
{
        Msg tmp;
        int j;
        while (2 * k + 1 < p->h_len) {
                j = 2 * k + 1;
                if (j + 1 < p->h_len && less(&p->h_arr[j + 1], &p->h_arr[j]))
                        j++;
                if (!less(&p->h_arr[j], &p->h_arr[k]))
                        break;
                tmp = p->h_arr[k];
                p->h_arr[k] = p->h_arr[j];
                p->h_arr[j] = tmp;
                k = j;
        }
}

Msg delMin(Heap *p)
{
        Msg min;
        if (p->h_len == 0) {
                memset(&min, 0, sizeof(Msg));
                return min;
        }
        min = p->h_arr[0];
        p->h_len--;
        if (p->h_len > 0) {
                p->h_arr[0] = p->h_arr[p->h_len];
                sink(p, 0);
        }
        return min;
}

