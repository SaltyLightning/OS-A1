#pragma once

struct process
{
	int bound; //what type of bound is the process
	int cpu_timeout_bound; // the time before a process will leave the cpu 
	int io_time; // the time spent in the io queue
	int total_time_in_machine; // total time spent in system
	int current_cpu_time; //current time spent in cpu
	int time_before_io; // time before the process is moved to io queue
	int time_waiting; // time spent in the ready queue
	int io_bound; // max time to spend in IO queue
	int total_time_in_cpu; // total time spent in cpu
	int total_io_time; // total time spent in the io queue
	int total_ready_time; // total time spent in the ready queue
	int smallest_ready_time; // shortest time spent in hte ready queue
	int longest_ready_time; // most time spent in the ready queue
	int starting_priority; // starting priority of a process
	int current_priority; // current priority of a process 
	int process_id; //id for a process
	int location; // where the process currently resides
};

