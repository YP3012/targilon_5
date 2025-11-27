# github link - https://github.com/YP3012/targilon_5.git

# Task 1 – Running the C++ example:
I ran the C++ code from the slides.
The program creates 20 threads, each printing a number.
The important part here is that the numbers come out in a random order, because the threads run at the same time.

# Task 2 – Fixing the C++ output with a mutex:
Then I added a std::mutex around the printing line.
This forces only one thread at a time to write to the console.
The order is still random but the output is now clean and separated, unlike before.

# Task 3 – Running the Java example:
The Java code starts two threads, each incrementing a shared counter 10,000 times.
Even though we expect 20,000, the result is always less.
This happens because bar++ is not safe when two threads do it together.

# Task 4 – Adding synchronized in Java:
After marking baz() and getBar() as synchronized, the result becomes exactly 20,000 every time.
The synchronization forces the threads to take turns when accessing the shared variable, so nothing gets lost.

# Task 5 - synchronized(this):
In Task 5 I changed the code so that only the increment is inside a synchronized(this) block.
This works the same as a synchronized method, because both lock on the same object (this).
The result is still always 20,000, showing that both techniques provide the same protection here.

# Task 6 - run second java example:
Without synchronization, the program runs fast but the final value is completely wrong because the increments collide. With many threads and many iterations, the loss is dramatic.

# Task 7 - adding synchronized(this):
In this task I ran the same program from Task 6, but this time the baz() method was wrapped in a synchronized(this) block.
Now every increment is protected, so only one thread can update the counter at a time.
Because of that, the final result becomes exactly 100,000,000