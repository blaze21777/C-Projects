///*
// * EEPROM Write
// *
// * Stores values read from analog input 0 into the EEPROM.
// * These values will stay in the EEPROM when the board is
// * turned off and may be retrieved later by another sketch.
// */
//
//#include <EEPROM.h>
//
///** the current address in the EEPROM (i.e. which byte we're going to write to next) **/
//int address = 0;
//
//int val;
//byte value[8];
////long long unixTimeSecs;
////uint64_t unixTimeSecs;
////uint32_t unixTimeSecs; // same as unsigned long. WORKS too
//unsigned long unixTimeSecs;
//
//void setup1() {
////  /** Empty setup. **/
//  // initialize serial and wait for port to open:
//  Serial.begin(9600);
//  while (!Serial) {
//    ; // wait for serial port to connect. Needed for native USB port only
//  }
//
//  val = 0;
////  unixTimeSecs = 0;
//  unixTimeSecs = 1580306259UL; // `158030625` & `158030625UL` used for testing
//
//  // ------------------------ ------------------------ USED TO TEST REBUILDING OF LONG FROM BYTES (USED W/O LOOP) ------------------------ ------------------------ 
////  for(int i=0; i<=3; i++) {
////    value[i] = (unixTimeSecs >> (8*i));
////  }
////
//////Serial.println("\""  IGNITION  "\" was sent to \""  ID  "\"(that's me!)");
//////String msg = "forward by " + (String)distance + " mm";
////
////  // TEST WRITING WORKS
////  // Values from largest to smallest ()
////  for(int i=3; i>=0; i--) {
////    Serial.println("value[" + (String)i + "] = " + (String)value[i]);
//////    Serial.printf("value[%d] = %d\n", i, value[i]);
////  }
////  // OUTPUT showing it writes to vars ok (tested using `158030625UL` AND `158030625`. Was a unix epoch time w/ least sig digit removed. Works generally though)
//////                                                                                                                               value[3] = 9
//////value[2] = 107
//////value[1] = 91
//////value[0] = 33
////// last 16 bits give: 23329
////
//////  Serial.println("That gives(not through variable yet):");
////////  Serial.println(  (value[3]*pow(2,8*3)) + (value[2]*pow(2,8*2)) + (value[1]*pow(2,8*1)) + (value[0]*pow(2,8*0))  );// less by 1.00, prob due to use of floats
//////
////////  // FAILS cause ints not promoted, so become 0 after int size number of shifts i.e. 8 for Arduino Uno
////////  Serial.println(  (value[3] << (8*3)) + (value[2] << (8*2)) + (value[1] << (8*1)) + (value[0] << (8*0))  );
//////
//////  // WORKS cause ints promoted before being shifted
//////  Serial.println(  ((unsigned long)(value[3]) << (8*3)) +
//////                   ((unsigned long)(value[2]) << (8*2)) +
//////                   ((unsigned long)(value[1]) << (8*1)) +
//////                   ((unsigned long)(value[0]) << (8*0))
//////                   );
////
////// TEST READING WORKS
////  unixTimeSecs = 0; // reading into it now, so ok to set to 0
////  for(int i=0; i<=3; i++) {
////    unixTimeSecs += ((unsigned long)(value[i]) << (8*i));
////  }
////  Serial.println("That gives(through variable):");
////  Serial.println(unixTimeSecs);
//
//  // ------------------------ ------------------------ ------------------------ ------------------------ ------------------------ ------------------------ 
//  
//}
//
////void loop(){}
//
//void loop1() {
//  /***
//    Need to divide by 4 because analog inputs range from
//    0 to 1023 and each byte of the EEPROM can only hold a
//    value from 0 to 255.
//  ***/
//
////  int val = analogRead(0) / 4;
//
//  /***
//    Write the value to the appropriate byte of the EEPROM.
//    these values will remain there when the board is
//    turned off.
//  ***/
//
//  // Write, then read the value, then increment
////  EEPROM.write(address, val);
//
//  for(int i=0; i<=3; i++) {
//    value[i] = (unixTimeSecs >> (8*i));
//  }
//
//  EEPROM.write(address+0, value[0]); // takes about 3ms
//  EEPROM.write(address+1, value[1]);
//  EEPROM.write(address+2, value[2]);
//  EEPROM.write(address+3, value[3]);
////  EEPROM.write(address+4, value[4]);
////  EEPROM.write(address+5, value[5]);
////  EEPROM.write(address+6, value[6]);
////  EEPROM.write(address+7, value[7]);
//  
//  
//
//
//  delay(1000);
//
//  
//  // read a byte from the current address of the EEPROM
////  val = EEPROM.read(address);
//  value[0] = EEPROM.read(address+0);
//  value[1] = EEPROM.read(address+1);
//  value[2] = EEPROM.read(address+2);
//  value[3] = EEPROM.read(address+3);
////  value[4] = EEPROM.read(address+4);
////  value[5] = EEPROM.read(address+5);
////  value[6] = EEPROM.read(address+6);
////  value[7] = EEPROM.read(address+7);
//
//  unixTimeSecs = 0; // reading into it now, so ok to set to 0
//  for(int i=0; i<=3; i++) {
//    //unixTimeSecs += (value[i] << (8*i));
//    unixTimeSecs += ((unsigned long)(value[i]) << (8*i));
//  }
//
//  Serial.print(address);
//  Serial.print("\t");
////  Serial.print(val, DEC);
////  Serial.println();
//
//  unixTimeSecs++;
//  Serial.print("Increment unixTimeSecs to ");
//  
//////  Serial.print(unixTimeSecs, DEC);
//////  uint64_t ll = 123456789012345678ULL;
////  uint64_t ll = unixTimeSecs;
////  uint64_t xx = ll/1000000000ULL; // e.g. 12 / 9 gives '1'(1st digit) . I prefer shifting personally, as using that approx looks like you'll be off
////
////  if (xx >0) Serial.print((long)xx);
////  Serial.print((long)(ll-xx*1000000000));
////  
////  Serial.println();
//
//  Serial.print(unixTimeSecs, DEC);
//  Serial.println();
//
//
////  val++;
//
////  // Not needed
////  for(int i=0; i<=7; i++) {
////    value[i] = (unixTimeSecs >> (8*i));
////  }
//  
////  Serial.print(unixTimeSecs, DEC);
////  Serial.println();
//  
//
////https://forum.arduino.cc/index.php?topic=134116.0
////(Topic: uint64_t in Serial.print)
//
//
//  
////
////  /***
////    Advance to the next address, when at the end restart at the beginning.
////
////    Larger AVR processors have larger EEPROM sizes, E.g:
////    - Arduno Duemilanove: 512b EEPROM storage.
////    - Arduino Uno:        1kb EEPROM storage.
////    - Arduino Mega:       4kb EEPROM storage.
////
////    Rather than hard-coding the length, you should use the pre-provided length function.
////    This will make your code portable to all AVR processors.
////  ***/
////  addr = addr + 1;
////  if (addr == EEPROM.length()) {
////    addr = 0;
////  }
////
////  /***
////    As the EEPROM sizes are powers of two, wrapping (preventing overflow) of an
////    EEPROM address is also doable by a bitwise and of the length - 1.
////
////    ++addr &= EEPROM.length() - 1;
////  ***/
////
////
////  delay(100);
//}
