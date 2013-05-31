Implementation of Merge-Split Algorithm
Variables and Flags used
int N - Number of Processors
int n - Size of the data set
int data[] - Data Set in an array

N threads are created using the following algorithm:
procedure thread_create(thread_id, other parameters):
	thread_create(thread_id+1,other parameters)
	polling(until all threads are created)
	proceed with merge-split algorithm
Each thread recursively spawns a new thread
After creating its successor thread, it waits until all the N threads are created by polling on a flag
When all threads have been created, all threads parallely proceed with the first step of merge-split algorithm.
All threads perform quicksort on the segment of the data set allocated to them.
If a thread completes quicksort, it will continue polling until all threads have completed quicksort.
After all threads have completed quicksort:
	Even indexed threads perform merge operation on the segments alloted to them.
	Odd indexed threads perform merge operation on the segments alloted to them.

Elements used for Thread Synchronization
polling - Each thread waits until a condition is satisfied(change in semaphore value);
semaphores - A variable whose operations are atomic.
Issues Involved in Implementation
Readers-Writers Problem - Simultaneous read and write results in read of garbage data. handled using semaphores
Memory Locking/Sharing - Each processor is alloted a particular segment of the data set and individual semaphores handle each segment's availability to each processor
Thread Synchronization - Odd threads must wait until the even threads complete their merge operation and vice-versa
Overhead involved in thread generation and deletion - Thread spawning wastes processor time. Overcome be recursively creating threads before algorithm execution. Similarly, deletion overhead is overcome by recursively joining threads rather than sequential thread joins.
Maximum Number of physical Processors is 4 deadlocks possible if more threads requested - There are 4 processors in i7 having 8 threads(4 physical and 4 virtual). Overall, only 4 threads can be implemented. If more threads are created, not all of them occur in parallel and deadlocks do not occur because whatever scheduling algorithm the OS follows as long as each thread gets a chance, all threads can complete their operations.
