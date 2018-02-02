#pragma once
/*--Definitions--*/
#define CPU 0
#define IO 1
#define READY 2
#define DEAD 3
/*--Function Prototypes--*/
void initialize_initial_queue(struct process* processes);
struct process create_process_from_bound(int bound);
struct process set_basic_params();
struct process set_maxes(struct process p);
void sort_ready_queue(struct process* ready, int bound);
void iterate(struct process &p);
void shift_queue(struct process* queue, int bound);
/*--Process Prams--*/
const int quantam = 5;
const int max_wait = 25;
const int base_time = 10;
