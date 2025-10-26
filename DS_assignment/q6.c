// Imagine a print server with a circular queue of capacity 5 to manage incoming print
// jobs.
// Initial State: The queue is empty. front = -1, rear = -1.
// Enqueue Operations:
// a. Job A arrives: enQueue(Job A). Queue: [Job A, _, _, _, _], front = 0, rear = 0.
// b. Job B arrives: enQueue(Job B). Queue: [Job A, Job B, _, _, _], front = 0, rear = 1.
// c. Job C arrives: enQueue(Job C). Queue: [Job A, Job B, Job C, _, _], front = 0,rear = 2.
// d. Job D arrives: enQueue(Job D). Queue: [Job A, Job B, Job C, Job D, _], front =
// 0, rear = 3.
// e. Job E arrives: enQueue(Job E). Queue: [Job A, Job B, Job C, Job D, Job E], front
// = 0, rear = 4. (Queue is full)

// Dequeue Operations:
// f. Print server processes Job A: deQueue(). Queue: [_, Job B, Job C, Job D, Job
// E], front = 1, rear = 4.
// g. Print server processes Job B: deQueue(). Queue: [_, _, Job C, Job D, Job E],
// front = 2, rear = 4.

// Enqueue with Wrap-around:
// h. Job F arrives: enQueue(Job F). Since the queue is circular, Job F is placed at
// index 0. Queue: [Job F, _, Job C, Job D, Job E], front = 2, rear = 0.
// i. Job G arrives: enQueue(Job G). Queue: [Job F, Job G, Job C, Job D, Job E],
// front = 2, rear = 1.

// Implement the Circular Queue: Provide a detailed implementation of the circular
// queue data structure (using an array) in C programming language. Include methods
// for enQueue, deQueue, isFull, isEmpty, and peek (to view the front element without
// removing)