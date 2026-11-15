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
        int k;

        k = p->h_len;
        p->h_arr[k] = x;
        p->h_len++;
        swim(p, k);
}

static void swim(Heap *p, int k)
{
        int parent;

        while (k > 0) {
                parent = (k - 1) / 2;

                if (!less(&p->h_arr[k], &p->h_arr[parent]))
                        break;

                Msg tmp = p->h_arr[k];
                p->h_arr[k] = p->h_arr[parent];
                p->h_arr[parent] = tmp;

                k = parent;
        }
}

static void sink(Heap *p, int k)
{
        int left, right, child;

        while (1) {
                left = 2 * k + 1;
                right = left + 1;

                if (left >= p->h_len)
                        break;

                child = left;
                if (right < p->h_len &&
                    less(&p->h_arr[right], &p->h_arr[left]))
                        child = right;

                if (!less(&p->h_arr[child], &p->h_arr[k]))
                        break;

                Msg tmp = p->h_arr[k];
                p->h_arr[k] = p->h_arr[child];
                p->h_arr[child] = tmp;

                k = child;
        }
}
Msg delMin(Heap *p)
{
        Msg result = p->h_arr[0];

        p->h_len--;
        if (p->h_len > 0) {
                p->h_arr[0] = p->h_arr[p->h_len];
                sink(p, 0);
        }

        return result;
}
