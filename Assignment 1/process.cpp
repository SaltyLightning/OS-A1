#include "stdafx.h"

void iterate(struct process &p)
{
	if (p.bound == 0)
	{
	}
}

void shift_queue(struct process* queue, int bound)
{
	for (int x = 0; x < bound; x++)
	{
		queue[x] = queue[x + 1];
	}
}

struct process set_maxes(struct process p)
{
	return p;
}

void sort_ready_queue(struct process* ready, int bound)
{
	for (int outer = 0; outer < bound; outer++)
	{
		for (int inner = 0; inner < bound; inner++)
		{
			if (ready[inner].current_priority > ready[outer].current_priority)
			{
				struct process temp = ready[outer];
				ready[outer] = ready[inner];
				ready[inner] = temp;
			}
		}
	}
}