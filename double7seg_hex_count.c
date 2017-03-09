#include <avr/io.h>
#include <util/delay.h>

/* -- define segmentation characters -- */

#define segF		0b01110100
#define segE		0b01110110
#define segd		0b01001111
#define segC		0b00110110
#define segb 		0b01100111
#define segA		0b01111101

#define segnine		0b01111001
#define segeight	0b01111111
#define segseven	0b00011001
#define segsix		0b01110111
#define segfive 	0b01110011
#define segfour		0b01101001
#define segthree	0b01011011
#define segtwo		0b01011110
#define segone		0b00001001
#define segzero		0b00111111
#define segOFF		0b00000000


/* -- define delay -- */

#define delay	250
#define blink	250


/* -- declarations --- */

uint8_t COUNT, COUNT1, TOP;


/* --- funtions --- */
void blinksegs() {
  DDRB = 0xFF;
  DDRD = 0xFF;
  _delay_ms(blink);
  DDRB = 0x00;
  DDRD = 0x00;
  _delay_ms(blink);   
} 

void setseg0(uint8_t seg_) {
  DDRB = seg_;
}

void setseg1(uint8_t seg_) {
  DDRD = seg_; 
}

void hextenscount(void) {

  if (COUNT1 < TOP) {

    switch (COUNT1) {
      
	    case 0:
      setseg0(segzero);
      break;

	    case 1:
      setseg0(segone);
      break;

	    case 2:
      setseg0(segtwo);
      break;

	    case 3:
      setseg0(segthree);
      break;

	    case 4:
      setseg0(segfour);
      break;

	    case 5:
      setseg0(segfive);
      break;

	    case 6:
      setseg0(segsix);
      break;

	    case 7:
      setseg0(segseven);
      break;

	    case 8:
      setseg0(segeight);
      break;

	    case 9:
      setseg0(segnine);
      break;

	    case 10:
      setseg0(segA);
      break;

	    case 11:
      setseg0(segb);
      break;

	    case 12:
      setseg0(segC);
      break;

	    case 13:
      setseg0(segd);
      break;

	    case 14:
      setseg0(segE);
      break;

	    case 15:
      setseg0(segF);
      break;
    }
  }
}


void hexonescount(void) {

  if (COUNT < TOP) {

    switch (COUNT) {
      
	    case 0:
      setseg1(segzero);
      break;

	    case 1:
      setseg1(segone);
      break;

	    case 2:
      setseg1(segtwo);
      break;

	    case 3:
      setseg1(segthree);
      break;

	    case 4:
      setseg1(segfour);
      break;

	    case 5:
      setseg1(segfive);
      break;

	    case 6:
      setseg1(segsix);
      break;

	    case 7:
      setseg1(segseven);
      break;

	    case 8:
      setseg1(segeight);
      break;

	    case 9:
      setseg1(segnine);
      break;

	    case 10:
      setseg1(segA);
      break;

	    case 11:
      setseg1(segb);
      break;

	    case 12:
      setseg1(segC);
      break;

	    case 13:
      setseg1(segd);
      break;

	    case 14:
      setseg1(segE);
      break;

	    case 15:
      setseg1(segF);
      break;
    }
  }
}


int main(void) {

  DDRB = 0xFF;
  DDRD = 0xFF;
  blinksegs();
  blinksegs();

  COUNT = 0;
  COUNT1 = 0;
  TOP = 16;
  
  while(1) {

    hextenscount();
    hexonescount();
    COUNT ++;
    
    _delay_ms(delay);
    
    if (COUNT == TOP) {
      COUNT = 0;
      COUNT1 ++;

      if (COUNT1 == TOP) {
        COUNT1 = 0;
  	blinksegs();
	blinksegs();
      }

    }
  }
  return(0);  
}
