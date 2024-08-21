void clearLED(uint8_t y, uint8_t z, uint8_t x) {
  cube[y][z][x].r = 0;
  cube[y][z][x].g = 0;
  cube[y][z][x].b = 0;
}

void setLED(uint8_t y, uint8_t z, uint8_t x, uint16_t red, uint16_t green, uint16_t blue) {
  cube[y][z][x].r = red;
  cube[y][z][x].g = green;
  cube[y][z][x].b = blue;
}

void lightCube() {
  for (uint8_t y = 0; y < NUM_COL_CUBED; y++) 
  {
    for (uint8_t z = 0; z < NUM_COL_CUBED; z++) 
    {
      for (uint8_t x = 0; x < NUM_COL_CUBED; x++) 
      {
        setLED(y,z,x, 255, 255, 255);
      }
    }
  }
}

void clearCube() {
  for (uint8_t y = 0; y < NUM_COL_CUBED; y++) 
  {
    for (uint8_t z = 0; z < NUM_COL_CUBED; z++) 
    {
      for (uint8_t x = 0; x < NUM_COL_CUBED; x++) 
      {
        clearLED(y,z,x);
      }
    }
  }
}

void renderCube() 
{
  // for (uint8_t y = 0; y < NUM_COL_CUBED; y++) 
  // {
  //   if (y == 0) 
  //   {
  //     tlc.setLED(0, cube[y][0][0].r, cube[y][0][0].g, cube[y][0][0].b);
  //     tlc.setLED(1, cube[y][0][1].r, cube[y][0][1].g, cube[y][0][1].b);
  //     tlc.setLED(2, cube[y][0][2].r, cube[y][0][2].g, cube[y][0][2].b);
  //     tlc.setLED(3, cube[y][0][3].r, cube[y][0][3].g, cube[y][0][3].b);
  //     tlc.setLED(4, cube[y][1][0].r, cube[y][1][0].g, cube[y][1][0].b);
  //     tlc.setLED(5, cube[y][1][1].r, cube[y][1][1].g, cube[y][1][1].b);
  //     tlc.setLED(6, cube[y][1][2].r, cube[y][1][2].g, cube[y][1][2].b);
  //     tlc.setLED(7, cube[y][1][3].r, cube[y][1][3].g, cube[y][1][3].b);
  //     tlc.setLED(8, cube[y][2][0].r, cube[y][2][0].g, cube[y][2][0].b);
  //     tlc.setLED(9, cube[y][2][1].r, cube[y][2][1].g, cube[y][2][1].b);
  //     tlc.setLED(10, cube[y][2][2].r, cube[y][2][2].g, cube[y][2][2].b);
  //     tlc.setLED(11, cube[y][2][3].r, cube[y][2][3].g, cube[y][2][3].b);
  //     tlc.setLED(12, cube[y][3][0].r, cube[y][3][0].g, cube[y][3][0].b);
  //     tlc.setLED(13, cube[y][3][1].r, cube[y][3][1].g, cube[y][3][1].b);
  //     tlc.setLED(14, cube[y][3][2].r, cube[y][3][2].g, cube[y][3][2].b);
  //     tlc.setLED(15, cube[y][3][3].r, cube[y][3][3].g, cube[y][3][3].b);
  //     tlc.write();
  //     mcp_3.digitalWrite(0, LOW);
  //     mcp_3.digitalWrite(0, HIGH);
  //   }
  //   else if (y == 3) 
  //   {
  //     tlc.setLED(0, cube[y][0][0].r, cube[y][0][0].g, cube[y][0][0].b);
  //     tlc.setLED(1, cube[y][0][1].r, cube[y][0][1].g, cube[y][0][1].b);
  //     tlc.setLED(2, cube[y][0][2].r, cube[y][0][2].g, cube[y][0][2].b);
  //     tlc.setLED(3, cube[y][0][3].r, cube[y][0][3].g, cube[y][0][3].b);
  //     tlc.setLED(4, cube[y][1][0].r, cube[y][1][0].g, cube[y][1][0].b);
  //     tlc.setLED(5, cube[y][1][1].r, cube[y][1][1].g, cube[y][1][1].b);
  //     tlc.setLED(6, cube[y][1][2].r, cube[y][1][2].g, cube[y][1][2].b);
  //     tlc.setLED(7, cube[y][1][3].r, cube[y][1][3].g, cube[y][1][3].b);
  //     tlc.setLED(8, cube[y][2][0].r, cube[y][2][0].g, cube[y][2][0].b);
  //     tlc.setLED(9, cube[y][2][1].r, cube[y][2][1].g, cube[y][2][1].b);
  //     tlc.setLED(10, cube[y][2][2].r, cube[y][2][2].g, cube[y][2][2].b);
  //     tlc.setLED(11, cube[y][2][3].r, cube[y][2][3].g, cube[y][2][3].b);
  //     tlc.setLED(12, cube[y][3][0].r, cube[y][3][0].g, cube[y][3][0].b);
  //     tlc.setLED(13, cube[y][3][1].r, cube[y][3][1].g, cube[y][3][1].b);
  //     tlc.setLED(14, cube[y][3][2].r, cube[y][3][2].g, cube[y][3][2].b);
  //     tlc.setLED(15, cube[y][3][3].r, cube[y][3][3].g, cube[y][3][3].b);
  //     tlc.write();
  //     mcp_3.digitalWrite(3, LOW);
  //     mcp_3.digitalWrite(3, HIGH);
  //   }
  // }

  for (uint8_t y = 0; y < NUM_COL_CUBED; y++) 
  {
    for (uint8_t z = 0; z < NUM_COL_CUBED; z++) 
    {
      for (uint8_t x = 0; x < NUM_COL_CUBED; x++) 
      {
        tlc.setLED(4*z+x, cube[y][z][x].r, cube[y][z][x].g, cube[y][z][x].b);
      }
    }
    tlc.write();
    mcp_3.digitalWrite(y, LOW);
    mcp_3.digitalWrite(y, HIGH);
  }
}

// void upDown(uint16_t r, uint16_t g, uint16_t b, uint8_t milliSec) 
// {
//   clearCube();
//   for(uint16_t i=0; i<8*NUM_TLC5947; i++) {
//       tlc.setLED(i, r, g, b);
//   }
//   tlc.write();
//   mcp_3.writeGPIOA(L0);
//   delay(milliSec);
//   mcp_3.writeGPIOA(L1);
//   delay(milliSec);
//   mcp_3.writeGPIOA(L2);
//   delay(milliSec);
//   mcp_3.writeGPIOA(L3);
//   delay(milliSec);
//   mcp_3.writeGPIOA(L2);
//   delay(milliSec);
//   mcp_3.writeGPIOA(L1);
//   delay(milliSec);
//   mcp_3.writeGPIOA(L0);
//   delay(milliSec);
//   clearCube();
//   mcp_3.writeGPIOA(ALL_LAYERS);
// }

// void rightLeft(uint16_t r, uint16_t g, uint16_t b, uint16_t milliSec) 
// {
//   clearCube();
//   mcp_3.writeGPIOA(ALL_LAYERS);

//   tlc.setLED(0, r, g, b);
//   tlc.setLED(1, r, g, b);
//   tlc.setLED(2, r, g, b);
//   tlc.setLED(3, r, g, b);
//   tlc.write();      
//   delay(milliSec);
  
//   tlc.setLED(0, 0, 0, 0);
//   tlc.setLED(1, 0, 0, 0);
//   tlc.setLED(2, 0, 0, 0);
//   tlc.setLED(3, 0, 0, 0);
//   tlc.setLED(4, r, g, b);
//   tlc.setLED(5, r, g, b);
//   tlc.setLED(6, r, g, b);
//   tlc.setLED(7, r, g, b);
//   tlc.write();       
//   delay(milliSec);  
  
//   tlc.setLED(4, 0, 0, 0);
//   tlc.setLED(5, 0, 0, 0);
//   tlc.setLED(6, 0, 0, 0);
//   tlc.setLED(7, 0, 0, 0);
//   tlc.setLED(8, r, g, b);
//   tlc.setLED(9, r, g, b);
//   tlc.setLED(10, r, g, b);
//   tlc.setLED(11, r, g, b);
//   tlc.write();   
//   delay(milliSec);

//   tlc.setLED(8, 0, 0, 0);
//   tlc.setLED(9, 0, 0, 0);
//   tlc.setLED(10, 0, 0, 0);
//   tlc.setLED(11, 0, 0, 0);
//   tlc.setLED(12, r, g, b);
//   tlc.setLED(13, r, g, b);
//   tlc.setLED(14, r, g, b);
//   tlc.setLED(15, r, g, b);
//   tlc.write();      
//   delay(milliSec);

//   tlc.setLED(12, 0, 0, 0);
//   tlc.setLED(13, 0, 0, 0);
//   tlc.setLED(14, 0, 0, 0);
//   tlc.setLED(15, 0, 0, 0);
//   tlc.setLED(8, r, g, b);
//   tlc.setLED(9, r, g, b);
//   tlc.setLED(10, r, g, b);
//   tlc.setLED(11, r, g, b);
//   tlc.write();      
//   delay(milliSec);

//   tlc.setLED(8, 0, 0, 0);
//   tlc.setLED(9, 0, 0, 0);
//   tlc.setLED(10, 0, 0, 0);
//   tlc.setLED(11, 0, 0, 0);
//   tlc.setLED(4, r, g, b);
//   tlc.setLED(5, r, g, b);
//   tlc.setLED(6, r, g, b);
//   tlc.setLED(7, r, g, b);
//   tlc.write();      
//   delay(milliSec);

//   tlc.setLED(4, 0, 0, 0);
//   tlc.setLED(5, 0, 0, 0);
//   tlc.setLED(6, 0, 0, 0);
//   tlc.setLED(7, 0, 0, 0);
//   tlc.setLED(0, r, g, b);
//   tlc.setLED(1, r, g, b);
//   tlc.setLED(2, r, g, b);
//   tlc.setLED(3, r, g, b);
//   tlc.write();      
//   delay(milliSec);
  
//   clearCube();
//   mcp_3.writeGPIOA(NO_LAYERS);
// }

// void backForth(uint16_t r, uint16_t g, uint16_t b, uint16_t milliSec) 
// {
//   clearCube();
//   mcp_3.writeGPIOA(ALL_LAYERS);

//   tlc.setLED(0, r, g, b);
//   tlc.setLED(4, r, g, b);
//   tlc.setLED(8, r, g, b);
//   tlc.setLED(12, r, g, b);
//   tlc.write();      
//   delay(milliSec);
  
//   tlc.setLED(0, 0, 0, 0);
//   tlc.setLED(4, 0, 0, 0);
//   tlc.setLED(8, 0, 0, 0);
//   tlc.setLED(12, 0, 0, 0);
//   tlc.setLED(1, r, g, b);
//   tlc.setLED(5, r, g, b);
//   tlc.setLED(9, r, g, b);
//   tlc.setLED(13, r, g, b);
//   tlc.write();      
//   delay(milliSec);
  
//   tlc.setLED(1, 0, 0, 0);
//   tlc.setLED(5, 0, 0, 0);
//   tlc.setLED(9, 0, 0, 0);
//   tlc.setLED(13, 0, 0, 0);
//   tlc.setLED(2, r, g, b);
//   tlc.setLED(6, r, g, b);
//   tlc.setLED(10, r, g, b);
//   tlc.setLED(14, r, g, b);
//   tlc.write();      
//   delay(milliSec);

//   tlc.setLED(2, 0, 0, 0);
//   tlc.setLED(6, 0, 0, 0);
//   tlc.setLED(10, 0, 0, 0);
//   tlc.setLED(14, 0, 0, 0);
//   tlc.setLED(3, r, g, b);
//   tlc.setLED(7, r, g, b);
//   tlc.setLED(11, r, g, b);
//   tlc.setLED(15, r, g, b);
//   tlc.write();      
//   delay(milliSec);
  
//   tlc.setLED(3, 0, 0, 0);
//   tlc.setLED(7, 0, 0, 0);
//   tlc.setLED(11, 0, 0, 0);
//   tlc.setLED(15, 0, 0, 0);
//   tlc.setLED(2, r, g, b);
//   tlc.setLED(6, r, g, b);
//   tlc.setLED(10, r, g, b);
//   tlc.setLED(14, r, g, b);
//   tlc.write();      
//   delay(milliSec);
  
//   tlc.setLED(2, 0, 0, 0);
//   tlc.setLED(6, 0, 0, 0);
//   tlc.setLED(10, 0, 0, 0);
//   tlc.setLED(14, 0, 0, 0);
//   tlc.setLED(1, r, g, b);
//   tlc.setLED(5, r, g, b);
//   tlc.setLED(9, r, g, b);
//   tlc.setLED(13, r, g, b);
//   tlc.write();      
//   delay(milliSec);
  
//   tlc.setLED(1, 0, 0, 0);
//   tlc.setLED(5, 0, 0, 0);
//   tlc.setLED(9, 0, 0, 0);
//   tlc.setLED(13, 0, 0, 0);
//   tlc.setLED(0, r, g, b);
//   tlc.setLED(4, r, g, b);
//   tlc.setLED(8, r, g, b);
//   tlc.setLED(12, r, g, b);
//   tlc.write();      
//   delay(milliSec);
  
//   clearCube();
//   mcp_3.writeGPIOA(NO_LAYERS);
// }