

void PUT32 ( unsigned int, unsigned int );
unsigned int GET32 ( unsigned int );
void DELAY ( unsigned int );

#define RESETS_BASE                 0x4000C000

//#define RESETS_RESET_RW        (RESETS_BASE+0x0+0x0000)
//#define RESETS_RESET_XOR       (RESETS_BASE+0x0+0x1000)
//#define RESETS_RESET_SET       (RESETS_BASE+0x0+0x2000)
#define RESETS_RESET_CLR       (RESETS_BASE+0x0+0x3000)

#define RESETS_RESET_DONE_RW   (RESETS_BASE+0x8+0x0000)
//#define RESETS_RESET_DONE_XOR  (RESETS_BASE+0x8+0x1000)
//#define RESETS_RESET_DONE_SET  (RESETS_BASE+0x8+0x2000)
//#define RESETS_RESET_DONE_CLR  (RESETS_BASE+0x8+0x3000)


#define CLOCKS_BASE                 0x40008000

#define CLK_REF_CTRL_RW             (CLOCKS_BASE+0x30+0x0000)
//#define CLK_REF_CTRL_XOR            (CLOCKS_BASE+0x30+0x1000)
//#define CLK_REF_CTRL_SET            (CLOCKS_BASE+0x30+0x2000)
//#define CLK_REF_CTRL_CLR            (CLOCKS_BASE+0x30+0x3000)

#define CLK_SYS_CTRL_RW             (CLOCKS_BASE+0x3C+0x0000)
//#define CLK_SYS_CTRL_XOR            (CLOCKS_BASE+0x3C+0x1000)
//#define CLK_SYS_CTRL_SET            (CLOCKS_BASE+0x3C+0x2000)
//#define CLK_SYS_CTRL_CLR            (CLOCKS_BASE+0x3C+0x3000)

#define CLK_PERI_CTRL_RW            (CLOCKS_BASE+0x48+0x0000)
//#define CLK_PERI_CTRL_XOR           (CLOCKS_BASE+0x48+0x1000)
//#define CLK_PERI_CTRL_SET           (CLOCKS_BASE+0x48+0x2000)
//#define CLK_PERI_CTRL_CLR           (CLOCKS_BASE+0x48+0x3000)

#define CLK_SYS_RESUS_CTRL_RW       (CLOCKS_BASE+0x78+0x0000)
//#define CLK_SYS_RESUS_CTRL_XOR      (CLOCKS_BASE+0x78+0x1000)
//#define CLK_SYS_RESUS_CTRL_SET      (CLOCKS_BASE+0x78+0x2000)
//#define CLK_SYS_RESUS_CTRL_CLR      (CLOCKS_BASE+0x78+0x3000)

#define XOSC_BASE                   0x40024000

#define XOSC_CTRL_RW                (XOSC_BASE+0x00+0x0000)
//#define XOSC_CTRL_XOR               (XOSC_BASE+0x00+0x1000)
#define XOSC_CTRL_SET               (XOSC_BASE+0x00+0x2000)
//#define XOSC_CTRL_CLR               (XOSC_BASE+0x00+0x3000)

#define XOSC_STATUS_RW              (XOSC_BASE+0x04+0x0000)
//#define XOSC_STATUS_XOR             (XOSC_BASE+0x04+0x1000)
//#define XOSC_STATUS_SET             (XOSC_BASE+0x04+0x2000)
//#define XOSC_STATUS_CLR             (XOSC_BASE+0x04+0x3000)

#define XOSC_STARTUP_RW             (XOSC_BASE+0x0C+0x0000)
//#define XOSC_STARTUP_XOR            (XOSC_BASE+0x0C+0x1000)
//#define XOSC_STARTUP_SET            (XOSC_BASE+0x0C+0x2000)
//#define XOSC_STARTUP_CLR            (XOSC_BASE+0x0C+0x3000)


#define IO_BANK0_BASE               0x40014000

#define IO_BANK0_GPIO2_CTRL_RW      (IO_BANK0_BASE+0x014+0x0000)
#define IO_BANK0_GPIO3_CTRL_RW      (IO_BANK0_BASE+0x01C+0x0000)
#define IO_BANK0_GPIO4_CTRL_RW      (IO_BANK0_BASE+0x024+0x0000)
#define IO_BANK0_GPIO5_CTRL_RW      (IO_BANK0_BASE+0x02C+0x0000)
#define IO_BANK0_GPIO6_CTRL_RW      (IO_BANK0_BASE+0x034+0x0000)

//#define IO_BANK0_GPIO25_STATUS_RW   (IO_BANK0_BASE+0x0C8+0x0000)
//#define IO_BANK0_GPIO25_STATUS_XOR  (IO_BANK0_BASE+0x0C8+0x1000)
//#define IO_BANK0_GPIO25_STATUS_SET  (IO_BANK0_BASE+0x0C8+0x2000)
//#define IO_BANK0_GPIO25_STATUS_CLR  (IO_BANK0_BASE+0x0C8+0x3000)

#define IO_BANK0_GPIO25_CTRL_RW     (IO_BANK0_BASE+0x0CC+0x0000)
//#define IO_BANK0_GPIO25_CTRL_XOR    (IO_BANK0_BASE+0x0CC+0x1000)
//#define IO_BANK0_GPIO25_CTRL_SET    (IO_BANK0_BASE+0x0CC+0x2000)
//#define IO_BANK0_GPIO25_CTRL_CLR    (IO_BANK0_BASE+0x0CC+0x3000)


#define PIO0_BASE                   0x50200000

#define PIO0_CTRL_RW                (PIO0_BASE+0x000+0x0000)
#define PIO0_FSTAT_RW               (PIO0_BASE+0x004+0x0000)
#define PIO0_TXF0_RW                (PIO0_BASE+0x010+0x0000)

#define PIO0_INSTR_MEM0_RW          (PIO0_BASE+0x048+0x0000)
#define PIO0_INSTR_MEM1_RW          (PIO0_BASE+0x04C+0x0000)

#define PIO0_INSTR_MEM2_RW          (PIO0_BASE+0x050+0x0000)
#define PIO0_INSTR_MEM3_RW          (PIO0_BASE+0x054+0x0000)
#define PIO0_INSTR_MEM4_RW          (PIO0_BASE+0x058+0x0000)
#define PIO0_INSTR_MEM5_RW          (PIO0_BASE+0x05C+0x0000)

#define PIO0_INSTR_MEM6_RW          (PIO0_BASE+0x060+0x0000)
#define PIO0_INSTR_MEM7_RW          (PIO0_BASE+0x064+0x0000)
#define PIO0_INSTR_MEM8_RW          (PIO0_BASE+0x068+0x0000)
#define PIO0_INSTR_MEM9_RW          (PIO0_BASE+0x06C+0x0000)

#define PIO0_INSTR_MEM10_RW         (PIO0_BASE+0x070+0x0000)
#define PIO0_INSTR_MEM11_RW         (PIO0_BASE+0x074+0x0000)
#define PIO0_INSTR_MEM12_RW         (PIO0_BASE+0x078+0x0000)
#define PIO0_INSTR_MEM13_RW         (PIO0_BASE+0x07C+0x0000)

#define PIO0_INSTR_MEM14_RW         (PIO0_BASE+0x080+0x0000)
#define PIO0_INSTR_MEM15_RW         (PIO0_BASE+0x084+0x0000)
#define PIO0_INSTR_MEM16_RW         (PIO0_BASE+0x088+0x0000)
#define PIO0_INSTR_MEM17_RW         (PIO0_BASE+0x08C+0x0000)

#define PIO0_INSTR_MEM18_RW         (PIO0_BASE+0x090+0x0000)
#define PIO0_INSTR_MEM19_RW         (PIO0_BASE+0x094+0x0000)
#define PIO0_INSTR_MEM20_RW         (PIO0_BASE+0x098+0x0000)
#define PIO0_INSTR_MEM21_RW         (PIO0_BASE+0x09C+0x0000)

#define PIO0_SM0_CLKDIV_RW          (PIO0_BASE+0x0C8+0x0000)
//#define PIO0_SM0_EXECCTRL_RW        (PIO0_BASE+0x0CC+0x0000)
//#define PIO0_SM0_EXECCTRL_SET       (PIO0_BASE+0x0CC+0x2000)
#define PIO0_SM0_SHIFTCTRL_RW       (PIO0_BASE+0x0D0+0x0000)
#define PIO0_SM0_PINCTRL_RW         (PIO0_BASE+0x0DC+0x0000)

//SCL GPIO 2
//SDA GPIO 3

#define SCL 0
#define SDA 1

#define SETCONTRAST         0x81
#define DISPLAYALLONRESUME  0xA4
#define DISPLAYALLON        0xA5
#define NORMALDISPLAY       0xA6
#define INVERTDISPLAY       0xA7
#define DISPLAYOFF          0xAE
#define DISPLAYON           0xAF
#define SETDISPLAYOFFSET    0xD3
#define SETCOMPINS          0xDA
#define SETVCOMDESELECT     0xDB
#define SETDISPLAYCLOCKDIV  0xD5
#define SETPRECHARGE        0xD9
#define SETMULTIPLEX        0xA8
#define SETLOWCOLUMN        0x00
#define SETHIGHCOLUMN       0x10
#define SETSTARTLINE        0x40
#define MEMORYMODE          0x20
#define COMSCANINC          0xC0
#define COMSCANDEC          0xC8
#define SEGREMAP            0xA0
#define CHARGEPUMP          0x8D
#define EXTERNALVCC         0x01
#define SWITCHCAPVCC        0x02



const unsigned char dfont[12][4][16]=
{
//
//
// **************
//* ************ *
//** ********** **
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//**            **
//
//**            **
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//** ********** **
//* ************ *
// **************
//
//
//
{
  {0xF8,0xF4,0xEC,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0xEC,0xF4,0xF8},
  {0x7F,0x7F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x7F,0x7F},
  {0xFF,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0xFF},
  {0x0F,0x17,0x1B,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1B,0x17,0x0F},
},
//
//
//
//               *
//              **
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//              **
//
//              **
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//              **
//               *
//
//
//
//
{
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xF0,0xF8},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x7F,0x7F},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0xFF},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x0F},
},
//
//
// **************
//  ************ *
//   ********** **
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//   ********** **
//  ************
//** **********
//***
//***
//***
//***
//***
//***
//***
//***
//***
//** **********
//* ************
// **************
//
//
//
{
  {0x00,0x04,0x0C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0xEC,0xF4,0xF8},
  {0x00,0x00,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xBF,0x7F,0x7F},
  {0xFF,0xFF,0xFE,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00},
  {0x0F,0x17,0x1B,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x18,0x10,0x00},
},
//
//
// **************
//  ************ *
//   ********** **
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//   ********** **
//  ************
//   ********** **
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//   ********** **
//  ************ *
// **************
//
//
//
{
  {0x00,0x04,0x0C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0xEC,0xF4,0xF8},
  {0x00,0x00,0x80,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xBF,0x7F,0x7F},
  {0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFE,0xFF,0xFF},
  {0x00,0x10,0x18,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1B,0x17,0x0F},
},
//
//
//
//*              *
//**            **
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//** ********** **
//  ************
//   ********** **
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//              **
//               *
//
//
//
//
{
  {0xF8,0xF0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xF0,0xF8},
  {0x7F,0x7F,0xBF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xBF,0x7F,0x7F},
  {0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFE,0xFF,0xFF},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x0F},
},
//
//
// **************
//* ************
//** **********
//***
//***
//***
//***
//***
//***
//***
//***
//***
//** **********
//  ************
//   ********** **
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//   ********** **
//  ************ *
// **************
//
//
//
{
  {0xF8,0xF4,0xEC,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x0C,0x04,0x00},
  {0x7F,0x7F,0xBF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00},
  {0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFE,0xFF,0xFF},
  {0x00,0x10,0x18,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1B,0x17,0x0F},
},
//
//
// **************
//* ************
//** **********
//***
//***
//***
//***
//***
//***
//***
//***
//***
//** **********
//  ************
//** ********** **
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//** ********** **
//* ************ *
// **************
//
//
//
{
  {0xF8,0xF4,0xEC,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x0C,0x04,0x00},
  {0x7F,0x7F,0xBF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00},
  {0xFF,0xFF,0xFE,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFE,0xFF,0xFF},
  {0x0F,0x17,0x1B,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1B,0x17,0x0F},
},
//
//
// **************
//  ************ *
//   ********** **
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//              **
//
//              **
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//              **
//               *
//
//
//
//
{
  {0x00,0x04,0x0C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0xEC,0xF4,0xF8},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x7F,0x7F},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0xFF,0xFF},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x0F},
},
//
//
// **************
//* ************ *
//** ********** **
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//** ********** **
//  ************
//** ********** **
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//** ********** **
//* ************ *
// **************
//
//
//
{
  {0xF8,0xF4,0xEC,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0xEC,0xF4,0xF8},
  {0x7F,0x7F,0xBF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xBF,0x7F,0x7F},
  {0xFF,0xFF,0xFE,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFE,0xFF,0xFF},
  {0x0F,0x17,0x1B,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1B,0x17,0x0F},
},
//
//
// **************
//* ************ *
//** ********** **
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//***          ***
//** ********** **
//  ************
//   ********** **
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//             ***
//   ********** **
//  ************ *
// **************
//
//
//
{
  {0xF8,0xF4,0xEC,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0xEC,0xF4,0xF8},
  {0x7F,0x7F,0xBF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xBF,0x7F,0x7F},
  {0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFE,0xFF,0xFF},
  {0x00,0x10,0x18,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1C,0x1B,0x17,0x0F},
},

{
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
},

{
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x0E,0x0E,0x0E,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x70,0x70,0x70,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
},

};

static void pio_fifo_write ( unsigned int x )
{
    while(1)
    {
        if((GET32(PIO0_FSTAT_RW)&(1<<(16+0)))==0) break;
    }
    PUT32(PIO0_TXF0_RW,x);
}

static void send_start ( void )
{
    pio_fifo_write((1<<SDA)|(1<<SCL));
    pio_fifo_write((0<<SDA)|(1<<SCL));
    pio_fifo_write((0<<SDA)|(0<<SCL));
}

static void send_stop ( void )
{
    pio_fifo_write((0<<SDA)|(0<<SCL));
    pio_fifo_write((0<<SDA)|(1<<SCL));
    pio_fifo_write((1<<SDA)|(1<<SCL));
}

static void send_byte ( unsigned int b )
{
    unsigned int ra;
    unsigned int data;
    for(ra=0x80;ra;ra>>=1)
    {
        if(ra&b) data=1; else data=0;
        pio_fifo_write((data<<SDA)|(0<<SCL));
        pio_fifo_write((data<<SDA)|(1<<SCL));
        pio_fifo_write((data<<SDA)|(0<<SCL));
    }
    pio_fifo_write((0<<SDA)|(0<<SCL));
    pio_fifo_write((0<<SDA)|(1<<SCL));
    pio_fifo_write((0<<SDA)|(0<<SCL));
}

#define PADDR 0x78
static void send_command ( unsigned int cmd )
{
    send_start();
    send_byte(PADDR);
    send_byte(0x00);
    send_byte(cmd);
    send_stop();
}
static void send_data ( unsigned int data )
{
    send_start();
    send_byte(PADDR);
    send_byte(0x40);
    send_byte(data);
    send_stop();
}
static void SetPageStart ( unsigned int x )
{
    send_command(0xB0|(x&0x07));
}
static void SetColumn ( unsigned int x )
{
    send_command(0x00|((x>>0)&0x0F));
    send_command(0x10|((x>>4)&0x0F));
}
static void ClearScreen ( void )
{
    unsigned int ra;
    unsigned int rb;

    for(ra=0;ra<4;ra++) //128x32
//    for(ra=0;ra<8;ra++) //128x64
    {
        SetPageStart(ra);
        SetColumn(0);
        for(rb=0;rb<0x80;rb++) send_data(0);
    }
}




static void clock_init ( void )
{
    PUT32(CLK_SYS_RESUS_CTRL_RW,0);
    //PUT32(CLK_REF_CTRL_RW,0);
    //PUT32(CLK_SYS_CTRL_RW,0);
    PUT32(XOSC_CTRL_RW,0xAA0);      //1 - 15MHZ
    PUT32(XOSC_STARTUP_RW,47);      //straight from the datasheet
    PUT32(XOSC_CTRL_SET,0xFAB000);  //enable
    while(1)
    {
        if((GET32(XOSC_STATUS_RW)&0x80000000)!=0) break;
    }
    PUT32(CLK_REF_CTRL_RW,2); //XOSC
    PUT32(CLK_SYS_CTRL_RW,0); //reset/clk_ref
}


unsigned int notmain ( void )
{
    unsigned int ra;
    unsigned int rb;

    clock_init();

    PUT32(CLK_PERI_CTRL_RW,(1<<11)|(4<<5));

    PUT32(RESETS_RESET_CLR,(1<<5)); //IO_BANK0
    while(1)
    {
        if((GET32(RESETS_RESET_DONE_RW)&(1<<5))!=0) break;
    }

    //PUT32(RESETS_RESET_CLR,(1<<8)); //PADS_BANK0
    //while(1)
    //{
        //if((GET32(RESETS_RESET_DONE_RW)&(1<<8))!=0) break;
    //}

    PUT32(RESETS_RESET_CLR,(1<<10)); //PIO0
    while(1)
    {
        if((GET32(RESETS_RESET_DONE_RW)&(1<<10))!=0) break;
    }

#include "pio.h"

    PUT32(PIO0_SM0_CLKDIV_RW,0x00060000);

    PUT32(PIO0_SM0_PINCTRL_RW,(2<<26)|(2<<5)|(2<<20)|(2<<0));

    PUT32(IO_BANK0_GPIO2_CTRL_RW,6); //PIO
    PUT32(IO_BANK0_GPIO3_CTRL_RW,6); //PIO

    PUT32(PIO0_CTRL_RW,1<<0);


    pio_fifo_write((1<<SDA)|(1<<SCL));
    pio_fifo_write((1<<SDA)|(1<<SCL));
    pio_fifo_write((0<<SDA)|(1<<SCL));
    pio_fifo_write((0<<SDA)|(0<<SCL));
    pio_fifo_write((0<<SDA)|(1<<SCL));
    pio_fifo_write((0<<SDA)|(0<<SCL));
    pio_fifo_write((0<<SDA)|(1<<SCL));
    pio_fifo_write((1<<SDA)|(1<<SCL));
    pio_fifo_write((1<<SDA)|(1<<SCL));



    // Display Init sequence for 64x48 OLED module
    send_command(DISPLAYOFF);           // 0xAE
    send_command(SETDISPLAYCLOCKDIV);   // 0xD5
    send_command(0x80);                 // the suggested ratio 0x80
    send_command(SETMULTIPLEX);         // 0xA8
    //send_command(64-1); //128x64
    send_command(32-1); //128x32
    send_command(SETDISPLAYOFFSET);     // 0xD3
    send_command(0x0);                  // no offset
    send_command(SETSTARTLINE | 0x0);   // line #0
    send_command(CHARGEPUMP);           // enable charge pump
    send_command(0x14);
    send_command(MEMORYMODE);
    send_command(0x02);
    send_command(SEGREMAP | 0x1);
    send_command(COMSCANDEC);
    send_command(SETCOMPINS);           // 0xDA
    //send_command(0x12); //128x64
    send_command(0x02); //128x32
    send_command(SETCONTRAST);          // 0x81
    send_command(0x0); //dimmest
//    send_command(0x8F);
    send_command(SETPRECHARGE);         // 0xd9
    send_command(0xF1);
    send_command(SETVCOMDESELECT);          // 0xDB
    send_command(0x00); //lowest/dimmest
    //send_command(0x40);
    send_command(NORMALDISPLAY);            // 0xA6
    send_command(DISPLAYALLONRESUME);   // 0xA4
    ClearScreen();
    send_command(DISPLAYON);                //--turn on oled panel


if(0)
{
    for(ra=0;ra<4;ra++) //128x32
//    for(ra=0;ra<8;ra++) //128x64
    {
        SetPageStart(ra);
        SetColumn(0);
        for(rb=0;rb<20;rb++) send_data(0x00);
        for(rb=0;rb<16;rb++) send_data(dfont[0][ra][rb]);
        for(rb=0;rb<4;rb++) send_data(0x00);
        for(rb=0;rb<16;rb++) send_data(dfont[1][ra][rb]);
        for(rb=0;rb<16;rb++) send_data(dfont[11][ra][rb]);
        for(rb=0;rb<16;rb++) send_data(dfont[2][ra][rb]);
        for(rb=0;rb<4;rb++) send_data(0x00);
        for(rb=0;rb<16;rb++) send_data(dfont[3][ra][rb]);
        for(rb=0;rb<20;rb++) send_data(0x00);
    }
}

if(1)
{
    for(ra=0;ra<4;ra++) //128x32
//    for(ra=0;ra<8;ra++) //128x64
    {
        SetPageStart(ra);
        SetColumn(0);

        for(rb=0;rb<16;rb++) send_data(dfont[8][ra][rb]);
        for(rb=0;rb<4;rb++) send_data(0x00);
        for(rb=0;rb<16;rb++) send_data(dfont[8][ra][rb]);

        for(rb=0;rb<10;rb++) send_data(0x00);

        for(rb=0;rb<16;rb++) send_data(dfont[8][ra][rb]);
        for(rb=0;rb<4;rb++) send_data(0x00);
        for(rb=0;rb<16;rb++) send_data(dfont[8][ra][rb]);

        for(rb=0;rb<10;rb++) send_data(0x00);

        for(rb=0;rb<16;rb++) send_data(dfont[8][ra][rb]);
        for(rb=0;rb<4;rb++) send_data(0x00);
        for(rb=0;rb<16;rb++) send_data(dfont[8][ra][rb]);

    }
}

    return(0);
}

//-------------------------------------------------------------------------
//
// Copyright (c) 2021 David Welch dwelch@dwelch.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------

