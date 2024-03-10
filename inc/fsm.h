#ifndef FSM_H_
#define FSM_H_

#include "states.h"
#include "transitions.h"
#include <stdio.h>

state_t fsm(state_t currentState, const instanceData_t* data);

#endif // FSM_H_