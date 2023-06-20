#include <cstdlib>
//#include <bits/stdc++.h>
#include "../state/state.hpp"
#include "./submission.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
/*
Move Minimax::get_move(State *state, int depth){

  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  auto actions = state->legal_actions;
  long long int next_val = 0, next_num = 0, t = 0;
  for(auto i : actions) {
    if(state->evaluate() > next_val) {
        next_val = state->evaluate();
        next_num = t;
    }
    i = i;
    t++;
  }
  depth = depth;
  return actions[next_num];
  //return actions[(rand()+depth)%actions.size()];
  
}
*/
/*
Move Minimax::get_move(State *state, int depth) {
    if (!state->legal_actions.size())
    state->get_legal_actions();

    auto actions = state->legal_actions;
    int best_val = INT_MIN;
    int best_action = -1;

    for (int i = 0; i < actions.size(); i++) {
        State *next_state = state->apply_action(actions[i]);

        int val = minimax(&next_state, depth - 1, false);

        if (val > best_val) {
            best_val = val;
            best_action = i;
        }
    }

    return actions[best_action];
}

int Minimax::minimax(State *state, int depth, bool maximizing_player) {
    if (depth == 0 || state->is_terminal()) {
        return state->evaluate();
    }

    if (maximizing_player) {
        int max_val = INT_MIN;
        for (auto action : state->legal_actions) {
            State *next_state = this->next_state(action);
            int val = minimax(&next_state, depth - 1, false);
            //max_val = max(max_val, val);
            max_val = val > max_val ? val : max_val;
        }
        return max_val;
    } else {
        int min_val = INT_MAX;
        for (auto action : state->legal_actions) {
            State *next_state = state->apply_action(action);
            int val = minimax(&next_state, depth - 1, true);
            //min_val = min(min_val, val);
            min_val = val < min_val ? val : min_val;
        }
        return min_val;
    }
}
*/

/***********/
Move Minimax::get_move(State* state, int depth)
{
  if(!state->legal_actions.size())
    state->get_legal_actions();

  //std::vector<Move> action = state->legal_actions;
  auto action = state->legal_actions;
  //std::vector<Move>::iterator it;
  //Move best_move = action[(rand()+depth)%action.size()];
  Move best_move;
  int max = INT_MIN;
  for(auto it = action.begin(); it != action.end(); it++) {
    int possible_state_value = minimax(state->next_state(*it), depth, true);

    if(possible_state_value > max) {
      max = possible_state_value;
      best_move = *it;
    }
  }
  return best_move;
}

int Minimax::minimax(State* state, int depth, bool maximize)
{
  state->get_legal_actions();
  if(depth == 0 || state->legal_actions.size() == 0) {
    return state->evaluate();
  }
  //std::vector<Move> action = state->legal_actions;
  auto action = state->legal_actions;
  //std::vector<Move>::iterator it;
  if(maximize) {
    int value = INT_MIN;
    for(auto it = action.begin(); it != action.end(); it++) {
        if(minimax(state->next_state(*it), depth - 1, false) > value) {
            value = minimax(state->next_state(*it), depth - 1, false);
        }
    }
    return value;
  } else {
    int value = INT_MAX;
    for(auto it = action.begin(); it != action.end(); it++) {
        if(minimax(state->next_state(*it), depth - 1, true) < value) {
            value = minimax(state->next_state(*it), depth - 1, true);
        }
    }
    return value;
  }
}