# Philosophers

A C implementation of the dining philosophers problem, built as part of the 42 curriculum. Philosophers run as threads and coordinate access to shared forks using mutexes.

## What this demonstrates

- Thread creation and shared-state coordination.
- Mutex-based access to shared resources.
- Timing, meal tracking and monitoring a simulation's lifecycle.
- Input validation and cleanup of allocated resources.

## Build and run

Requires a POSIX environment, Make, a C compiler and pthread support.

```sh
git clone https://github.com/derealthink/42-school.git
cd 42-school/projects/philosophers-42
make
./philo 5 800 200 200 7
```

```text
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [meals_per_philosopher]
```

Times are in milliseconds. The optional final argument sets the meal target. Scheduling affects the output; timing examples do not guarantee a particular outcome.

The current Makefile does not explicitly link pthreads. On systems that require it, build with:

```sh
cc -Wall -Wextra -Werror -pthread main.c init.c thread.c parse_utils.c atoi.c routine.c free_destroy.c monitor.c -o philo
```

## Source guide

| Files | Responsibility |
| --- | --- |
| `main.c`, `parse_utils.c`, `atoi.c` | Arguments and entry point |
| `init.c`, `thread.c` | State initialization and threads |
| `routine.c`, `monitor.c` | Philosopher behavior and monitoring |
| `free_destroy.c` | Cleanup |

Use `make clean` to remove object files and `make fclean` to remove the executable too.

---

Part of my [42 School project collection](../../README.md).
