#ifndef _SERIAL_H_COMMAND_ROBOT_IO_H_
#define _SERIAL_H_COMMAND_ROBOT_IO_H_

//********@Choose board type***********
//*                                   *
    #define RADA_BOARD
  //  #define FOLLOW_BOARD
  
//________END Choose board type_____


//***********@Define PIN***************
//*                                   *  
  #if defined(RADA_BOARD) || defined(FOLLOW_BOARD)
    #define I_BATERY_VOLT_PIN         (A7)

    #define O_SERVO_PIN_L             (9)
    #define O_SERVO_PIN_R             (10)

    #define O_LED_WARN_PIN            (13)
    
    #define O_PWM_PIN_L               (4)
    #define O_DIR_PIN_L               (5)
    #define O_DIR_PIN_R               (6)
    #define O_PWM_PIN_R               (7)

    #if defined(RADA_BOARD)
      #define O_BUZZER_PIN            (3)
      #define O_TRIG_PIN              (11)
      #define I_ECHO_PIN              (12)

      #define I_DIP_SW_PIN_2          (A0)
      #define I_DIP_SW_PIN_1          (A1)
      
    #else // FOLLOW_BOT
      #define O_LED_PIN_4             (3)
      #define O_LED_PIN_3             (2)
      #define O_LED_PIN_2             (A5)
      #define O_LED_PIN_1             (A4)
      
      #define I_IRSENSOR_PIN_1        (A3)
      #define I_IRSENSOR_PIN_2        (A2)
      #define I_IRSENSOR_PIN_3        (A1)
      #define I_IRSENSOR_PIN_4        (A0)

      #define I_BTN_PIN               (8)
      
    #endif
    

  #else
    #error Please choose board type at line 4 (Serial_command_robot_io.h)

  #endif
  
//________END Define PIN_____________  
#endif
