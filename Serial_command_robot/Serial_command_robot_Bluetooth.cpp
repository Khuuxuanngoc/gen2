#include "Serial_command_robot_Bluetooth.h"
#ifndef _DIS_SERIAL_H_COMMAND_ROBOT_BLUETOOTH_H_

#include "Serial_command_robot_DCMotor.h"
#include "Serial_command_robot_ReadBat.h"

Vietduino_Serial mySerial;

CREATE_FUNCTION(Check_Serial,2) {
  mySerial.begin(9600);

  while(1){
    if(mySerial.available()){
        String kk = mySerial.readStringUntil('\n');

        if(kk != ""){
          switch(uc_mode){
            case _RADA_MODE_MANUAL_:
              RadaBot_Run(splitString(kk, COMMAND_JOYSTICK, ",", ",", 1));

              if(kk.indexOf(COMMAND_SERVO_L) > -1){
                uc_Servo_Pos_L = constrain(splitString(kk, COMMAND_SERVO_L, ",", ",", 1).toInt(),\
                                           ML_SERVO_VALUE_MIN, ML_SERVO_VALUE_MAX);
                Servo_L.write(uc_Servo_Pos_L, uc_servo_speed);
              }else if(kk.indexOf(COMMAND_SERVO_R) > -1){
                uc_Servo_Pos_R = constrain(splitString(kk, COMMAND_SERVO_R, ",", ",", 1).toInt(),\
                                           ML_SERVO_VALUE_MIN, ML_SERVO_VALUE_MAX);
                Servo_R.write(uc_Servo_Pos_R, uc_servo_speed);

              }else if(kk.indexOf(COMMAND_SPEED) > -1){
                uc_rada_dcSpeed_value = splitString(kk, COMMAND_SPEED, ",", ",", 1).toInt();

              }else if(kk.indexOf(COMMAND_INFO) > -1){
                mySerial.println(String(COMMAND_INFO) + "," + \
                                  String((unsigned char)g_f_Vin_value) + "," +\
                                  String(uc_Servo_Pos_L) + "," + \
                                  String(uc_Servo_Pos_R) + "," + \
                                  String(uc_rada_dcSpeed_value));
              }else;
                
              // if(kk.indexOf("AT") > -1){
              //   mySerial.println("OK");
              // }else if(kk == "RR"){
              //   mySerial.println("OK-rr");
              //   RadaBot_Run("FF");
              // }

            break;

            case _RADA_MODE_AVOID_:

            break;

            case _RADA_MODE_FOLLOW_:

            break;

            case _RADA_MODE_LOWVOLT_:
              if(kk.indexOf(COMMAND_INFO) > -1){
                mySerial.println(String(COMMAND_INFO) + "," + \
                                  String((unsigned char)g_f_Vin_value) + "," +\
                                  String(uc_Servo_Pos_L) + "," + \
                                  String(uc_Servo_Pos_R) + "," + \
                                  String(uc_rada_dcSpeed_value) + ",");
              }else;
            break;
          }
          
        }
    }
    M_DELAY_US(10);
  }

  END_CREATE_FUNCTION
}

void Send_info_OverBluetooth(){
  mySerial.println(String(COMMAND_INFO) + "," + \
                                  String((unsigned char)g_f_Vin_value) + "," +\
                                  String(uc_Servo_Pos_L) + "," + \
                                  String(uc_Servo_Pos_R) + "," + \
                                  String(uc_rada_dcSpeed_value)+ ",");
}

#endif