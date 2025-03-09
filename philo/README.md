# Philosophers

## Overview

The `philosophers` project is a simulation of the classic [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) using multithreading. The goal is to manage the behavior of philosophers who alternately eat, think, and sleep, while avoiding deadlock and ensuring that no philosopher starves.

## Features

- Simulation of multiple philosophers
- Use of threads to manage philosopher actions
- Mutexes to handle resource sharing (forks)
- Avoidance of deadlock and starvation

## Usage

### Compiling

To compile the project, run:

```sh
make
```

This will generate the executable: `philo`.

### Running the Simulation

To start the simulation, run:

```sh
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: The number of philosophers and also the number of forks.
- `time_to_die`: Time in milliseconds a philosopher can live without eating.
- `time_to_eat`: Time in milliseconds it takes for a philosopher to eat.
- `time_to_sleep`: Time in milliseconds a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): If all philosophers eat at least this number of times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

Example:

```sh
./philo 5 800 200 200
```

This starts a simulation with 5 philosophers, where each philosopher will die if they don't eat within 800 milliseconds, take 200 milliseconds to eat, and 200 milliseconds to sleep.

## Resources

- [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
