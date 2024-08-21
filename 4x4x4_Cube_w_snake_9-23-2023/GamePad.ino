/*
 * Check which button has been pressed
 * Only one signal is sent for each button press
 * No logic implemented if multiple buttons pressed at once
 */
void checkButtons(Adafruit_MCP23X17 *mcp) 
{
  uint16_t pinsAtMCP = ~mcp->getCapturedInterrupt();
  if (((pinsAtMCP & LEFT_MASK) == LEFT_MASK) && (lastButtonPressed != LEFT_BUTTON)) {
    lastButtonPressed = LEFT_BUTTON;
    leftPress();
  } else if (((pinsAtMCP & UP_MASK) == UP_MASK) && (lastButtonPressed != UP_BUTTON)) {
    lastButtonPressed = UP_BUTTON;
    forwardPress();
  } else if (((pinsAtMCP & DOWN_MASK) == DOWN_MASK) && (lastButtonPressed != DOWN_BUTTON)) {
    lastButtonPressed = DOWN_BUTTON;
    backwardPress();
  } else if (((pinsAtMCP & RIGHT_MASK) == RIGHT_MASK) && (lastButtonPressed != RIGHT_BUTTON)) {
    lastButtonPressed = RIGHT_BUTTON;
    rightPress();
  } else if (((pinsAtMCP & A_MASK) == A_MASK) && (lastButtonPressed != A_BUTTON)) {
    lastButtonPressed = A_BUTTON;
    upPress();
  } else if (((pinsAtMCP & B_MASK) == B_MASK) && (lastButtonPressed != B_BUTTON)) {
    lastButtonPressed = B_BUTTON;
    downPress();
  }
}

/*
 * Logic for when FORWARD BUTTON IS PRESSED
 * Contains logic for when:
 *  Playing Snake: move snake FORWARD
 */
void forwardPress() 
{
  if (snake.dir != BACKWARD) 
  {
    snake.dir = FORWARD;
  }
}

/*
 * Logic for when BACKWARD BUTTON IS PRESSED
 * Contains logic for when:
 *  Playing Snake: move snake BACKWARD
 */
void backwardPress() 
{
  if (snake.dir != FORWARD) 
  {
    snake.dir = BACKWARD;
  }
}

/*
 * Logic for when LEFT BUTTON IS PRESSED
 * Contains logic for when:
 *  Playing Snake: move snake LEFT
 */
void leftPress() 
{
  if (snake.dir != RIGHT) 
  {
    snake.dir = LEFT;
  }
}

/*
 * Logic for when RIGHT BUTTON IS PRESSED
 * Contains logic for when:
 *  Playing Snake: move snake RIGHT
 */
void rightPress() 
{
  if (snake.dir != LEFT) 
  {
    snake.dir = RIGHT;
  }
}

/*
 * Logic for when UP BUTTON IS PRESSED
 * Contains logic for when:
 *  Playing Snake: move snake UP
 */
void upPress() 
{
  if (snake.dir != DOWN) 
  {
    snake.dir = UP;
  }
}

/*
 * Logic for when DOWN BUTTON IS PRESSED
 * Contains logic for when:
 *  Playing Snake: move snake DOWN
 *  Testing Cube movement: move cube DOWN
 *  Animations are playing: begin playing Snake
 */
void downPress() 
{
  if (snake.dir != UP) 
  {
    snake.dir = DOWN;
  }
}
