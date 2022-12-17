#define TRIS_SDO TRISCbits.RC7
#define TRIS_SDI TRISBbits.RB0
#define TRIS_SCL TRISBbits.RB1
#define TRIS_SS  TRISAbits.RA5
#define SS       LATAbits.LA5
#define PIN_IN  1
#define PIN_OUT 0

#define MasterCLK4    0 
#define MasterCLK16   1
#define MasterCLK64   2
#define MasterCLKTMR  3
#define SlaveSS       4
#define SlaveGPIO     5

#define SMP_MIDDLE   0
#define SMP_END      1
#define SSP_ON       1
#define SSP_OFF      0

#define CLK0          0
#define CLK1          1
#define CLK2          2
#define CLK3          3

void SPI_Master_Init(char MS_CLK_SS, char Forma);
void SPI_Slave_Init(char MS_CLK_SS, char Forma);
void SPI_Tx(char dato);
char SPI_Rx();



