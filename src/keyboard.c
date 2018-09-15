#include <keyboard.h>

unsigned char lastPressedChar = 0;

#define CONSBUFSIZE 512
static struct {
	unsigned char buf[CONSBUFSIZE];
	unsigned int rpos;
	unsigned int wpos;
} cons;

void init_keyboard() {

  int i = 0;

  for (i = 0 ; i < 256; i++) {
      default_map[i] = 0;
  }

  for (i = 0 ; i < 256; i++) {
      shift_map[i] = 0;
  }

  default_map[0x01] = KEY_ESC_VALUE;
  default_map[0x02] = '1';
  default_map[0x03] = '2';
  default_map[0x04] = '3';
  default_map[0x05] = '4';
  default_map[0x06] = '5';
  default_map[0x07] = '6';
  default_map[0x08] = '7';
  default_map[0x09] = '8';
  default_map[0x0A] = '9';
  default_map[0x0B] = '0';
  default_map[0x0C] = '-';
  default_map[0x0D] = '=';


  default_map[0x10] = 'q';
  default_map[0x11] = 'w';
  default_map[0x12] = 'e';
  default_map[0x13] = 'r';
  default_map[0x14] = 't';
  default_map[0x15] = 'y';
  default_map[0x16] = 'u';
  default_map[0x17] = 'i';
  default_map[0x18] = 'o';
  default_map[0x19] = 'p';
  default_map[0x1A] = '@';
  default_map[0x1B] = '[';


  default_map[0x1E] = 'a';
  default_map[0x1F] = 's';
  default_map[0x20] = 'd';
  default_map[0x21] = 'f';
  default_map[0x22] = 'g';
  default_map[0x23] = 'h';
  default_map[0x24] = 'j';
  default_map[0x25] = 'k';
  default_map[0x26] = 'l';
  default_map[0x27] = 135; //C CEDILHA
  default_map[0x28] = '~';
  default_map[0x29] = '\'';

  default_map[0x2B] = ']';
  default_map[0x2C] = 'z';
  default_map[0x2D] = 'x';
  default_map[0x2E] = 'c';
  default_map[0x2F] = 'v';
  default_map[0x30] = 'b';
  default_map[0x31] = 'n';
  default_map[0x32] = 'm';
  default_map[0x33] = ',';
  default_map[0x34] = '.';
  default_map[0x35] = ';';


  default_map[0x56] = '\\';
  default_map[0x73] = '//';
  default_map[0x53] = ',';
  default_map[0x7E] = '.';

  default_map[0x0E] = KEY_BACKSPACE_VALUE;
  default_map[0x0F] = KEY_TAB_VALUE;
  default_map[0x01] = KEY_ESC_VALUE;
  default_map[0x1D] = KEY_CTRL_VALUE;
  default_map[0x2A] = KEY_SHIFT_LEFT_VALUE;
  default_map[0x36] = KEY_SHIFT_RIGHT_VALUE;
  default_map[0x1C] = KEY_ENTER_VALUE;
  default_map[0x3A] = KEY_CAPS_LOCK_VALUE;
  default_map[0x38] = KEY_ALT_VALUE;
  default_map[0x45] = KEY_NUM_LOCK_VALUE;

  default_map[0x39] = ' '; //SPACE
  //Numeric Key Pad
  default_map[0x37] = '*';
  default_map[0x47] = '7';
  default_map[0x48] = '8';
  default_map[0x49] = '9';
  default_map[0x4a] = '-';
  default_map[0x4b] = '4';
  default_map[0x4c] = '5';
  default_map[0x4d] = '6';
  default_map[0x4e] = '+';
  default_map[0x4f] = '1';
  default_map[0x50] = '2';
  default_map[0x51] = '3';
  default_map[0x52] = '0';





  shift_map[0x01] = KEY_ESC_VALUE;
  shift_map[0x02] = '!';
  shift_map[0x03] = '@';
  shift_map[0x04] = '#';
  shift_map[0x05] = '$';
  shift_map[0x06] = '%';
  shift_map[0x07] = '¨';
  shift_map[0x08] = '&';
  shift_map[0x09] = '*';
  shift_map[0x0A] = '(';
  shift_map[0x0B] = ')';
  shift_map[0x0C] = '_';
  shift_map[0x0D] = '+';


  shift_map[0x10] = 'Q';
  shift_map[0x11] = 'W';
  shift_map[0x12] = 'E';
  shift_map[0x13] = 'R';
  shift_map[0x14] = 'T';
  shift_map[0x15] = 'Y';
  shift_map[0x16] = 'U';
  shift_map[0x17] = 'I';
  shift_map[0x18] = 'O';
  shift_map[0x19] = 'P';
  shift_map[0x1A] = '`';
  shift_map[0x1B] = '{';


  shift_map[0x1E] = 'A';
  shift_map[0x1F] = 'S';
  shift_map[0x20] = 'D';
  shift_map[0x21] = 'F';
  shift_map[0x22] = 'G';
  shift_map[0x23] = 'H';
  shift_map[0x24] = 'J';
  shift_map[0x25] = 'K';
  shift_map[0x26] = 'L';
  shift_map[0x27] = 128; //C CEDILHA
  shift_map[0x28] = '^';
  shift_map[0x29] = '|';

  shift_map[0x2B] = '}';
  shift_map[0x2C] = 'Z';
  shift_map[0x2D] = 'X';
  shift_map[0x2E] = 'C';
  shift_map[0x2F] = 'V';
  shift_map[0x30] = 'B';
  shift_map[0x31] = 'N';
  shift_map[0x32] = 'M';
  shift_map[0x33] = '<';
  shift_map[0x34] = '>';
  shift_map[0x35] = ':';


  shift_map[0x56] = '|';
  shift_map[0x73] = '?';
  shift_map[0x53] = ',';
  shift_map[0x7E] = '.';

  shift_map[0x0E] = KEY_BACKSPACE_VALUE;
  shift_map[0x0F] = KEY_TAB_VALUE;
  shift_map[0x01] = KEY_ESC_VALUE;
  shift_map[0x1D] = KEY_CTRL_VALUE;
  shift_map[0x2A] = KEY_SHIFT_LEFT_VALUE;
  shift_map[0x36] = KEY_SHIFT_RIGHT_VALUE;
  shift_map[0x1C] = KEY_ENTER_VALUE;
  shift_map[0x3A] = KEY_CAPS_LOCK_VALUE;
  shift_map[0x38] = KEY_ALT_VALUE;
  shift_map[0x45] = KEY_NUM_LOCK_VALUE;

  shift_map[0x39] = ' '; //SPACE
  //Numeric Key Pad
  shift_map[0x37] = '*';
  shift_map[0x47] = '7';
  shift_map[0x48] = '8';
  shift_map[0x49] = '9';
  shift_map[0x4a] = '-';
  shift_map[0x4b] = '4';
  shift_map[0x4c] = '5';
  shift_map[0x4d] = '6';
  shift_map[0x4e] = '+';
  shift_map[0x4f] = '1';
  shift_map[0x50] = '2';
  shift_map[0x51] = '3';
  shift_map[0x52] = '0';


  cons.rpos = 0;
  cons.wpos = 0;


}

unsigned char shift_flag = 0;



void putCharInBuffer(unsigned char myChar) {
    if (cons.wpos >= 512) {
        cons.wpos = 0;
    }
    cons.buf[cons.wpos] = myChar;
    cons.wpos++;
}

unsigned char getCharFromBuffer() {

    unsigned char result = 0;
    if (cons.rpos != cons.wpos) {
        if (cons.rpos >= 512) {
            cons.rpos = 0;
        }
        result = cons.buf[cons.rpos];
        cons.rpos++;
    }
    return result;

}


void keyboard_handler() {

    unsigned char scancode;
    scancode = inportb(0x60);

    if (scancode  == L_SHIFT_PRESS || scancode  == R_SHIFT_PRESS) {
        shift_flag = 1;
        return;
    }

    if (scancode  == L_SHIFT_RELEASE || scancode  == R_SHIFT_RELEASE) {
        shift_flag = 0;
        return;
    }

    //Tecla de scape
    if (scancode != 0xe0) {

        //Verifica se o bit mais alta é 1 (verdadeiro). Caso positivo indica que é um tecla de controle
        if (scancode & 0x80) {
            //tratar alt, ctrl, etc...

        } else {

            //ESCREVE NA TELA
                if (shift_flag == 1) {
                    putCharInBuffer(shift_map[scancode]);
                } else {
                    putCharInBuffer(default_map[scancode]);
                }
        }

    }

}


unsigned char getChar() {
    unsigned char result = 0;
    while (1) {

        result = getCharFromBuffer();
        if (result != 0) {
            break;
        }

        //Delay
        inportb(0x84);
        inportb(0x84);
        inportb(0x84);
        inportb(0x84);

    };

    return result;
}




unsigned char* readLine() {

    unsigned char c;
    unsigned char buffer[1024];
    unsigned int i = 0;
    for (i = 0; i < 1024; i++) {
            buffer[i]=0;
    }
    unsigned pos = 0;


    while (1) {

        c = getChar();

        if (c == '\n' || c == '\r') {
            putch(c);
            break;
        }

        if (c == 0x08) {
            if (pos > 0) {
                putch(c);
                pos--;
            }
        } else {
            putch(c);
            buffer[pos++] = c;
        }
    }

    buffer[pos] = KEY_ENTER_VALUE;
    return buffer;

}

