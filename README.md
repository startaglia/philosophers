# Philosopher
The philosopher project allows you to understand how to manage multi-processes or multi-threads that access a shared source.</br>
This is an implementation of the famous [Dining Philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem). The goal is to avoid deadlock and race conditions; each philosopher should be a thread and the fork is a shared source. No philosopher must die according to parameters provided by the subject.</br>

### Rules
  
    • The program should take the following arguments:
        • number_of_philosophers: the number of philosophers and also the numberof forks. 
        • time_to_die (in milliseconds): if a philosopher didn’t start eating time_to_die
          milliseconds since the beginning of their last meal or the beginning of the sim-
          ulation, they die.
        • time_to_eat (in milliseconds): the time it takes for a philosopher to eat.
          During that time, they will need to hold two forks.
        • time_to_sleep (in milliseconds): the time a philosopher will spend sleeping.
        • number_of_times_each_philosopher_must_eat (optional argument): if all
          philosophers have eaten at least number_of_times_each_philosopher_must_eat
          times, the simulation stops. If not specified, the simulation stops when a
          philosopher dies.
    • Each philosopher has a number ranging from 1 to number_of_philosophers.
    • Philosopher number 1 sits next to philosopher number number_of_philosophers.
      Any other philosopher number N sits between philosopher number N - 1 and philoso-
      pher number N + 1.
  
  The program's otput will be formatted like this:
  
    ◦ timestamp_in_ms id has taken a fork
    ◦ timestamp_in_ms id is eating
    ◦ timestamp_in_ms id is sleeping
    ◦ timestamp_in_ms id is thinking
    ◦ timestamp_in_ms id died

  An example of program execution:

<a href="https://42roma.it/"><img src="https://github.com/startaglia/startaglia/blob/main/.media/philo.gif"></a>

## Installing and running the project:

1- Clone the repo:
  
  ```sh
  git clone https://github.com/startaglia/philosopher.git philosopher
  ```

2- Enter in philosopher dir and compile the program with the `make` command
	
 ```
  cd philosopher
	make
 ```
Run the program and try whit different parameters.

### Input examples:
- a philosopher will not be able to eat so he dies: `make && ./philo 5 200 400 200`
- all philosophers will always be able to eat in time: `make re && ./philo 4 450 100 250`
- all philosophers will always manage to eat in time 7 times: `make re && ./philo 5 800 100 250 7`
 
### Makefile Available Targets:

`make` or `make all` - Makes exe file/s
`make clean` - Deletes all the resulting object files  
`make fclean` - Deletes the executables and all the resulting object files  
`make re` - fclean + all
</br></br>

## Sources
  [The Dining Philosopher’s Problem](https://medium.com/swlh/the-dining-philosophers-problem-bbdb92e6b788).</br>
  [Dining philosophers problem-wiki](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
   
## Technologies Used:

- **Programming Language**: C
- **Operating System**: Linux
- **Compiler**: GCC (GNU Compiler Collection)
- **Build System**: GNU Make
- **C Standard Library**
- **Concurrency**: Techniques for handling concurrent programming and synchronization in C using `pthread.h`
- **Process Management**: System calls like `fork()`, `exec()`, and `waitpid()`
- **Time Measurement**: Techniques for measuring time using `sys/time.h`
- **Command Line Arguments Handling**: Techniques such as `argc`/`argv`

## Authors:

- **Simone Tartaglia**
  - Email: [startaglia89@gmail.com](mailto:startaglia89@gmail.com)
  - GitHub: [startaglia](https://github.com/startaglia)
  - LinkedIn: [Simone Tartaglia](https://www.linkedin.com/in/simone-tartaglia-134723248/)
