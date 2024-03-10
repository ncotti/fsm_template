# FSM Template

This repo serves as a template for any C implementation of a FSM (Finite State Machine).
To use, copy all files in the `src` and `inc` folders.

An example implementation was made based on the following model:

![FSM example model](/images/fsm.svg)

## Run the example

```bash
# Start CMake
cmake -B build .

# Compile
cmake --build build

# Run
./build/main
```

## Basic explanation

In the files `src/states.c` and `inc/states.h`, the states and the rules to start a state transition are defined.

In the files `src/transition.c` and `inc/transition.h`, the transitions between states are defined as a matrix of $Number \space of \space States \times Number \space of \space States$, where the position $"ij"$ represent the transition from state $"i"$ to state $"j"$.

Finally, in the files `src/fsm.c` and `inc/fsm.h`, the state-machine implementation is defined in the function `fsm()`. Besides, an example external event of requesting a character from stdin is implemented.
