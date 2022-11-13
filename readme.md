## Task Scheduler II (2365)

You are given a  **0-indexed**  array of positive integers  `tasks`, representing tasks that need to be completed  **in order**, where  `tasks[i]`  represents the  **type**  of the  `ith`  task.
You are also given a positive integer  `space`, which represents the  **minimum**  number of days that must pass  **after**  the completion of a task before another task of the  **same**  type can be performed.

Each day, until all tasks have been completed, you must either:

-   Complete the next task from  `tasks`, or
-   Take a break.

Return _the  **minimum**  number of days needed to complete all tasks_.

**Intuition**
lets say we are given `tasks = [1,2,1,2,3,1], space = 3` we know the following:
1. We need to find a way store the day in which we complete `n` task
2. If we completed a task of type n within the past x days and x is less than space, then we need to take a break.
3. If we have taken a break it should be applicable for all tasks we performed before taking it. 
	a. in the example we complete task 1, then task 2 and then take 2 days of break because the next task is of type 1. We should be able to go right into task 2 because the break + day it took us to complete task 1 give > space - day in which task 2 was completed.

**Solution**
 1. We will use a map `freq` to store days when task where completed, and int variable day which will be our return value. 
 2. Iterate over vector of tasks and check if the current task has already been seen.
 3. If the task has been seen check if the `diff = day - freq[task] - 1 > space`
 4. If it is greater then, we can simply perform the task before the proper amount of time has passed since we last completed it.
 5. If not then we need to take a break of size `space - diff`
 6. We also assign set completed day of the task to day.

*** In short ***
1. we use the days variable to mark the index of a task we've seen in the past. 
2. If we have seen the task before, we must calculate the difference by subtracting the day in which that task was finished from the current day. If the space needed is greater than the diff, then we must add it to the difference by subtracting diff from space. 
3. we mark current task completed on current day and increment day to account the time it took to complete the given task.