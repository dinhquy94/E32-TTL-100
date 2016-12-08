/* E32-UART library

Loaken license
written by Loaken - LAWA_PROJECT
*/ 
  
 #if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include <SoftwareSerial.h> 
class E32UartReciever {
	public:
		E32UartReciever(byte lowAdd, byte highAdd, byte Chanel);
		byte getHightAdd();
		byte getLowAdd();
		byte getChanel(); 
	private:
		byte _lowAdd;
		byte _highAdd;
		byte _Chanel; 
};
class E32Uart {
	public:
		E32Uart(SoftwareSerial * serial, uint8_t M0, uint8_t M1);
		void SendMessage(E32UartReciever reciever, String message);
		int getCurrentMode();	
		void setMode(int mode);
	private:  
		SoftwareSerial *_serial;
		void setup();
		int _mode;
		uint8_t _M0;
		uint8_t _M1;
};
