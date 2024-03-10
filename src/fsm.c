#include "fsm.h"

/// @brief Finite State Machine. Execute current state, change to a new state
///     if corresponds, and apply transition from one state to other.
/// @param currentState Current state of the machine.
/// @param data Pointer to the data from the events that could trigger a
///     state transition.
/// @return Next state.
state_t fsm(state_t currentState, const instanceData_t* data) {
    state_t newState = currentState.stFn(data);
    transitionFn_t transition = transitionTable[currentState.st][newState.st];
    if (transition) {
        transition();
    }
    return newState;
}

/// @brief Check if any external event was triggered, and store its output.
/// @param data All the information from the events will be put inside this
///     struct.
void externalEvent(instanceData_t* data) {
    do {
        data->inputCharacter = getchar();
    } while (data->inputCharacter == '\n');
}

/// @brief Simple main function to exemplify functionality of the FSM.
int main(void) {
    state_t current_state = stA;
    instanceData_t data;

    printf("Three states are defined: A, B, C.\n");
    printf("Enter the letter of the state to transition from state to state.\n");

    while(1) {
        externalEvent(&data);
        current_state = fsm(current_state, &data);
    }
    return 0;
}