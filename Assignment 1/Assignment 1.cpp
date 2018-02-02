// Assignment 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{	
	/* Initialization */
	struct process init_queue[100];
	struct process cpu;
	struct process io_queue[100];
	struct process ready_queue[100];
	int current_p_num = 1;
	int current_io_num = 0, ready_bound = 0;

	initialize_initial_queue(init_queue);
	cpu = init_queue[0];
	for (int tick =  0; cpu.location != DEAD ; tick++) //while all processes have not been run to completion
	{
		if (cpu.current_cpu_time == cpu.cpu_timeout_bound) //If an process is ready to leave the cpu..
		{
			cpu = set_maxes(cpu); // set maxes for the current process in the cpu
			
			cpu = ready_queue[0]; //put the next process into the cpu
			cpu.location = CPU;

			shift_queue(ready_queue, ready_bound--); //shift over the ready queue
		}
		
		if (cpu.current_cpu_time == quantam) //if a process has timed out 
		{
			cpu = set_maxes(cpu); // set maxes for the current process in the cpu

			cpu.location = READY; //swap out the current process into the ready queue
			struct process temp = cpu; 
			cpu = ready_queue[0]; 
			ready_queue[0] = temp; 
			cpu.location = CPU;
		}

		if (cpu.time_before_io == 0) // if it's time for a process to recieve IO
		{
			cpu = set_maxes(cpu); // set maxes for the current process in the cpu
			
			cpu.location = IO; // move the process currently in the cpu to the io queue
			io_queue[current_io_num++] = cpu;

			cpu = ready_queue[0]; //put the next process into the cpu
			cpu.location = CPU;

			shift_queue(ready_queue, ready_bound--); //shift over the ready queue
		}

		for (int io_it = 0; io_it < current_io_num; io_it++)// resolve the io queue
		{
			if (io_queue[io_it].time_before_io == 0) //if an process is ready to leave the IO queue...
			{
				ready_queue[ready_bound++] = io_queue[io_it]; //move the process to the ready queue
				io_queue[io_it] = io_queue[0]; //move the first process to the position of hte deleted item
				shift_queue(io_queue, io_it); //shift over
				current_io_num--;
			}
			else
			{
				io_queue[io_it].time_before_io--;
			}
		}
		
		// resolve ready queue
		for (int ready_it = 0; ready_it < ready_bound; ready_it++)
		{
			
		}
	}
    return 0;
}

