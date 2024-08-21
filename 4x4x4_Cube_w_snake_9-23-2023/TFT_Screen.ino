void updateScore(uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4, Adafruit_ST7789 *tft) 
{
  tft->setTextWrap(false);
  tft->fillScreen(ST77XX_WHITE);
  tft->setCursor(tft->width()/6, tft->height()/6 - 10);
  tft->setTextColor(ST77XX_GREEN);
  tft->setTextSize(5);
  tft->println("P1");
  tft->fillRect(tft->width()/6 - 1, tft->height()/6 + 26, 52, 4, ST77XX_GREEN);
  if (p1 <= 9) { tft->setCursor(tft->width()/6 + 15, tft->height()/6 + 31);}
  else if (p1 > 99) { tft->setCursor(tft->width()/6 - 9, tft->height()/6 + 31); }
  else if (p1 > 9) { tft->setCursor(tft->width()/6 + 3, tft->height()/6 + 31); }
  tft->setTextSize(4);
  tft->println(p1);
  
  tft->setCursor(4*tft->width()/6, tft->height()/6 - 10);
  tft->setTextColor(ST77XX_BLUE);
  tft->setTextSize(5);
  tft->println("P2");
  tft->fillRect(4*tft->width()/6 - 1, tft->height()/6 + 26, 52, 4, ST77XX_BLUE);
  if (p2 <= 9) { tft->setCursor(4*tft->width()/6 + 15, tft->height()/6 + 31);}
  else if (p2 > 99) { tft->setCursor(4*tft->width()/6 - 9, tft->height()/6 + 31); }
  else if (p2 > 9) { tft->setCursor(4*tft->width()/6 + 3, tft->height()/6 + 31); }
  tft->setTextSize(4);
  tft->println(p2);
  
  tft->setCursor(tft->width()/6, 4*tft->height()/6 - 10);
  tft->setTextColor(ST77XX_YELLOW);
  tft->setTextSize(5);
  tft->println("P3");
  tft->fillRect(tft->width()/6 - 1, 4*tft->height()/6 + 26, 52, 4, ST77XX_YELLOW);
  if (p3 <= 9) { tft->setCursor(tft->width()/6 + 15, 4*tft->height()/6 + 31);}
  else if (p3 > 99) { tft->setCursor(tft->width()/6 - 9, 4*tft->height()/6 + 31); }
  else if (p3 > 9) { tft->setCursor(tft->width()/6 + 3, 4*tft->height()/6 + 31); }
  tft->setTextSize(4);
  tft->println(p3);
  
  tft->setCursor(4*tft->width()/6, 4*tft->height()/6 - 10);
  tft->setTextColor(ST77XX_MAGENTA);
  tft->setTextSize(5);
  tft->println("P4");
  tft->fillRect(4*tft->width()/6 - 1, 4*tft->height()/6 + 26, 52, 4, ST77XX_MAGENTA);
  if (p4 <= 9) { tft->setCursor(4*tft->width()/6 + 15, 4*tft->height()/6 + 31);}
  else if (p4 > 99) { tft->setCursor(4*tft->width()/6 - 9, 4*tft->height()/6 + 31); }
  else if (p4 > 9) { tft->setCursor(4*tft->width()/6 + 3, 4*tft->height()/6 + 31); }
  tft->setTextSize(4);
  tft->println(p4);
}