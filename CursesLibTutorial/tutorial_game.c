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
  	{ WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR},
  	{ WALL_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, LADDER_CHAR, WALL_CHAR},
  	{ WALL_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, WALL_CHAR},
	{ WALL_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, WALL_CHAR},
	{ WALL_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, WALL_CHAR},
  	{ WALL_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, WALL_CHAR},
	{ WALL_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, WALL_CHAR},
	{ WALL_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, WALL_CHAR},
  	{ WALL_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, WALL_CHAR},
	{ WALL_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, WALL_CHAR},
	{ WALL_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, WALL_CHAR},
	{ WALL_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, WALL_CHAR},
	{ WALL_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, WALL_CHAR},
	{ WALL_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, BLANK_CHAR, WALL_CHAR},
	{ WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR, WALL_CHAR}
  };

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

  // Add the player
  move(player_y, player_x);
  addch(PLAYER_CHAR);

  // Now display the maze
  refresh();

  // Main game loop
  while (done == 0) {
    int charPress;
    int oldX;
    int oldY;
    int shouldMove;

    shouldMove = 0;
    oldX = player_x;
    oldY = player_y;

    // Get the player's move
    charPress = getch();

    // Since we surrounded the maze with walls, we only need to check that the
    // the player didn't move onto a wall
    if (charPress == 'w') {
      if (MAZE[player_y - 1][player_x] != WALL_CHAR) {
        // If they moved up not into a wall

	// We should set move to true
        shouldMove = 1;
        
        player_y = player_y - 1;
     }
    } else if (charPress == 's') {
      if (MAZE[player_y + 1][player_x] != WALL_CHAR) {
        // If they moved down not into a wall

        // We should set move to true
        shouldMove = 1;

        player_y = player_y + 1;
      }
    } else if (charPress == 'a') {
      if (MAZE[player_y][player_x - 1] != WALL_CHAR) {
        // If they moved right not into a wall

	// We should set move to true
        shouldMove = 1;
        
        player_x = player_x - 1;
      }
    } else if (charPress == 'd') {
      if (MAZE[player_y][player_x + 1] != WALL_CHAR) {
        // If they moved left not into a wall

        // We should set move to true
        shouldMove = 1;

        player_x = player_x + 1;
      }
    }

    // If the player moved, we need to update the screen
    if (shouldMove) {
      // We need to reset the previous tile
      move(oldY, oldX);
      addch(MAZE[oldY][oldX]);

      // Now we will draw the player
      move(player_y, player_x);
      addch(PLAYER_CHAR);

      refresh();   
    }

    // If the player made it to the ladder
    if (MAZE[player_y][player_x] == LADDER_CHAR) {
      done = 1;
    }  
  }

  // Get rid of the curses window and return to the normal terminal's behavior
  endwin();
}
