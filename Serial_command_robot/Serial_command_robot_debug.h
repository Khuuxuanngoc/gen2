#ifndef SERIAL_H_COMMAND_ROBOT_DEBUG_H_
#define SERIAL_H_COMMAND_ROBOT_DEBUG_H_

#define Db_volt(x)          Serial.print(x)
#define Db_voltn(x)         Serial.println(x)


#if defined(M_DISABLE_DEBUG)
    #define Db_volt(x)      
    #define Db_voltn(x)     
#endif

//-------------Tem disable file .h and .cpp-------------------
// #define _DIS_SERIAL_H_COMMAND_ROBOT_BLUETOOTH_H_
// #define _DIS_SERIAL_H_COMMAND_ROBOT_DCMOTOR_H_
// #define _DIS_SERIAL_H_COMMAND_ROBOT_SERVORC_H_

#endif