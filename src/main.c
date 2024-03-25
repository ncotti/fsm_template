#include "fsm_first/fsm_first.h"
#include "fsm_second/fsm_second.h"
#include <stdio.h>

/// @brief Check if any external event was triggered, and store its output.
/// @param data All the information from the events.
void external_event(fsm_first_data_t* data) {
    do {
        data->input_char = getchar();
    } while (data->input_char == '\n');
}

/// @brief Simple main function to exemplify functionality of the FSM.
int main(void) {
    fsm_first_data_t data;

    printf("Three states are defined: A, B, C.\n");
    printf("Enter the letter of the state to transition from state to state.\n");

    while(1) {
        external_event(&data);
        fsm_first(&data);
        fsm_second((fsm_second_data_t*) &data);
    }
    return 0;
}