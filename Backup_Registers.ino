#include <libmaple/bkp.h>
uint16_t Count;
void setup() {
  // put your setup code here, to run once:
Serial1.begin(115200);
 bkp_init(); 
  Count= bkp_read(1);
  Serial1.println("BCKP Registers Init");
}

void loop() {
  // put your main code here, to run repeatedly:
    Count++;
    bkp_enable_writes();        //guardamos los datos en memoria remanente batt
    bkp_write(1,Count);
    bkp_disable_writes();
    Serial1.print("Cuenta es: ");
    Serial1.println(bkp_read(1));
    delay(500);
}
