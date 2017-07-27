#include "eval.h"
#include "debug.h"
#include "script.h"
#include "state.h"
#include "states.h"
#include "maze.h"
#include "config.h"
#include "direction.h"
#include <string.h>
bool eval(State * c, Input * in, Maze * maze) {

  Directions d;

  get_Directions(&d, in);

  //if (is_Goal(in) && !is_State("start", c)) {
  //  set_State("stop_robot", c);
  //  return false;
  //}
  
  //int next_direction = -1;
  //if (is_Junction(&d)) {
  //  if (!visited(maze, maze->current_node)) {
  //    visit_Node(maze, &d, maze->current_node);
  //  } 
  //  for (int i = 0; i < 4; i++) {
  //    if (is_Edge(maze, maze->current_node, i)) {
  //      //next_direction = i % robot->facing;
  //      maze->current_node = maze->edges[maze->current_node][i];
  //    }
  //  }
  //  set_State("stop_robot", c);
  //  return false;
  //}
  
  if (is_State("reverse_left", c) && on_Center_Line(in)) {
    if (on_Center_Line(in) && line_Right(in)) {
      set_State("correct_right", c);
    }
    else if (on_Center_Line(in) && line_Left(in)) {
      set_State("correct_left", c);
    }
    if (!on_Center_Line(in) && line_Right(in)) {
      set_State("turn_right", c);
    }
    else if (!on_Center_Line(in) && line_Left(in)) {
      set_State("turn_left", c);
    }
    else {
      set_State("move_forward", c);
    }
    return false;
  }
  if (is_Dir(&d, LEFT) && !(is_State("turn_right",c))) {
    set_State("reverse_left", c);
    return false;
  }
  
  //if (is_Dir(&d, RIGHT) && !(is_State("turn_left",c))) {
  //  set_State("turn_right", c);
  //  return false;
  //}
  //else if (!is_Dir(&d, FORWARD)) {
  //  set_State("turn_around", c);
  //  return false;
  //}

  if (on_Center_Line(in) && off_Right(in)) {
    set_State("correct_right", c);
  }
  else if (on_Center_Line(in) && off_Left(in)) {
    set_State("correct_left", c);
  }
  else if (line_Right(in)) {
    set_State("turn_right", c);
  }
  else if (line_Left(in)) {
    set_State("turn_left", c);
  }
  //else if (on_Center_Line(in)) {
  //  set_State("move_forward", c);
  //}
  else {
    //set_State("stop_robot", c); 
  }
  return false;
}
