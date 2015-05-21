/*
 * A game use to show the uses of ncurses. 
 *
 * For this game we will build a simple maze that the user can navigate around,
 * until they reach a special square.
 *
 * Author : Antonio Calabrese
 */
#include <ncurses.h>
#include <unistd.h>

// Constants representing the maze
#define MAZE_WIDTH 15
#define MAZE_HEIGHT 15

// Maze "object" representations
static char const WALL_CHAR = 'X';
static char const LADDER_CHAR = 'H';
static char const PLAYER_CHAR = 'O';
static char const BLANK_CHAR = '.';

int main(int argc, char *argv[]) {
  // Start the player at the bottom of the maze
  int player_x = 1;
  int player_y = 1;
  int done = 0;
  int i;
  int j;

  char MAZE[MAZE_HEIGHT][MAZE_WIDTH] = {
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'},
  	{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'}
  };

  // First create a blank maze
  /*for (i = 0 ; i < MAZE_HEIGHT ; i++) {
  	for (j = 0 ; j < MAZE_WIDTH ; j++) {
  		MAZE[i][j] = BLANK_CHAR;
  	}
  }*/

  // Called to initialize the screen
  initscr();

  // Set specific parameters
  noecho();
  curs_set(FALSE);

  // Clear the display
  clear();

  // First display just the maze
  for (i = 0 ; i < MAZE_HEIGHT ; i++) {
  	for (j = 0 ; j < MAZE_WIDTH ; j++) {
  		move(j, i);
  		addch(MAZE[j][i]);
  	}
  }

  // Now display the maze
  refresh();

  sleep(1);

  // Get rid of the curses window and return to the normal terminal's behavior
  endwin();
}