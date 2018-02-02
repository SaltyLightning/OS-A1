#include "stdafx.h"

void initialize_initial_queue(process * processes)
{
	for (int bound = 0; bound < 5; bound++)
	{
		for (int current_proc = 0; current_proc < 20; current_proc++)
		{
			struct process p = create_process_from_bound(bound);
			p.process_id = current_proc + 20 * bound;
			p.starting_priority = p.current_priority = current_proc;
			processes[p.process_id] = p;

		}
	}
}

struct process create_process_from_bound(int bound)
{
	struct process p;
	p.bound = bound;
	p = set_basic_params();
	switch(bound)
	{
		case 0:
			p.io_time = 0;
			p.cpu_timeout_bound = base_time;
			break;
		case 1:
			p.io_time = base_time / 4;
			p.cpu_timeout_bound = p.io_time * 3;
			break;
		case 2:
			p.io_time = p.cpu_timeout_bound = base_time / 2;
			break;
		case 3:
			p.cpu_timeout_bound = base_time / 4;
			p.io_time = p.io_time * 3;
			break;
		case 4:
			p.io_time = base_time;
			p.cpu_timeout_bound = 1;
			break;
		default:
			break;
	}
	return p;
}

struct process set_basic_params()
{
	struct process p;
	p.total_time_in_machine = p.longest_ready_time =
		p.total_io_time = p.smallest_ready_time = p.time_waiting =
		p.time_before_io = p.total_ready_time =
		p.total_time_in_cpu = p.current_cpu_time = 0;
	p.location = 2;
	return p;
}
