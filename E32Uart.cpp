/* E32-UART library

Loaken license
written by Loaken - LAWA_PROJECT
*/

#include "E32Uart.h"   
#include <SoftwareSerial.h> 
E32UartReciever::E32UartReciever(byte lowAdd, byte highAdd, byte Chanel) {
	     _lowAdd = lowAdd;
		 _highAdd = highAdd;		 
		 _Chanel = Chanel;
}
byte E32UartReciever::getLowAdd() {
	return _lowAdd;
}
byte E32UartReciever::getHightAdd() {
	return _highAdd;
}
byte E32UartReciever::getChanel() {
	return _Chanel;
}
E32Uart::E32Uart(SoftwareSerial * serial, uint8_t M0, uint8_t M1) {	 
	 _serial = serial;
	 _M0 = M0;
	 _M1 = M1;
	 E32Uart::setup();
}
void E32Uart::setup() {
	//_mySerial = new SoftwareSerial(_txPin, _rxPin);
	_serial->begin(9600);
	pinMode(_M0, OUTPUT);
	pinMode(_M1, OUTPUT); 
	_mode = 0;
	digitalWrite(_M0, 0);
	digitalWrite(_M0, 0);
}
int E32Uart::getCurrentMode(){
	return _mode;
}
void E32Uart::setMode(int mode){
  char m0 = 0;
  char m1 = 0; 
  switch(mode) {
    // working
    case 0: 
      m0=0;
      m1=0;
	  _mode = 0;
      break;
    // wake-up
    case 1: 
      m0=0;
      m1=1;
	  _mode = 1;
      break;
    // power-saving
    case 2:
      m0=1;
      m1=0;
	  _mode = 2;
      break;
    // sleep
    case 3: 
      m0=1;
      m1=1;
	  _mode = 3;
      break;   
    default:
      return ;
  } 
  digitalWrite(_M0, m0);
  digitalWrite(_M1, m1);      
  return;
}
void E32Uart::SendMessage(E32UartReciever reciever, String message) {
	uint8_t lowAdd = reciever.getLowAdd();
	uint8_t highAdd = reciever.getHightAdd();
	uint8_t chanel = reciever.getChanel();
	byte add_packet[] = { lowAdd, highAdd, chanel};   
    _serial->write(add_packet, sizeof(add_packet));
    _serial->println(message);
	return ;
	
}