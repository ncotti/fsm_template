# FSM Template

This repo serves as a template for any C implementation of a FSM (Finite State Machine).
To use, copy all files in the `src` and `inc` folders.

An example implementation was made based on the following two models:

<center>

| ![FSM template letters](/images/fsm_template_letters.svg) |
|:--:|
| *FSM First* |

| ![FSM template numbers](/images/fsm_template_numbers.svg) |
|:--:|
| *FSM Second* |

</center>

## Run the example

```bash
# Start CMake
cmake -B build .

# Compile
cmake --build build

# Run
./build/main
```

## How to use in your projects

Copy all the files in the folder `src/fsm_first`, and do the following:

1. Find and replace all instances of `fsm_first` and `FSM_FIRST` with `fsm_<name>` and `FSM_<name>` respectively, where `<name>` can be any name of your liking. Besides, rename the files.

2. In `fsm_<name>.h`:
    * Define the states inside the enumeration `fsm_<name>_state_t`.

    * Set the amount of states with `FSM_<name>_STATE_QTY`.

    * Set the initial state with `FSM_<name>_INITIAL_STATE`.

    * Define the types or arguments received by the state machine with the members of the struct `fsm_<name>_data_t`. For this step, you may find and replace all instances of the struct with a personalized set of arguments.

3. In `fsm_<name>_states.c`:
    * Define all functions for each state. These functions should ONLY check whether a state transition should be performed, and return the next state. They shouldn't have any code.

    * Complete the variable `fsm_<name>_fn_list` with a list of all state functions. The order of the functions should match the order of the states in the enumeration.

4. In `fsm_<name>_transitions.c`:
    * Define the necessary functions for transitions between states. These functions should be the only ones to perform "actions" such as modify data or trigger events.

    * Complete the `fsm_<name>_transition_table` as a matrix, where the rows and columns correspond with the order of the states as defined in the enumeration.

5. To include the FSM in your code, add the header `#include "fsm_<name>/fsm_<name>.h` and call the function `current_state = fsm_<name>(&data)`.
