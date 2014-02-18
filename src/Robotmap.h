#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// #define LEFTMOTOR 1Wait(2.0);
// #define RIGHTMOTOR 2

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1

#define MOTOR_A_PWM 1
#define MOTOR_B_PWM 4
#define MOTOR_C_PWM 3
#define MOTOR_D_PWM 2

#define BEAGLEBONE_IP "10.47.74.42"
#define BEAGLEBONE_PORT 4774

#define JOY_DRV_DEAD_X 0.05
#define JOY_DRV_DEAD_Y 0.05
#define JOY_DRV_DEAD_Z 0.15

#define CATCH_BUTTON 2

#define GYRO_PORT 1

#define PIMP_ROLL_BUTTON 7

#define ENCODER_A_1 1
#define ENCODER_A_2 2
#define ENCODER_B_1 3
#define ENCODER_B_2 4
#define ENCODER_C_1 5
#define ENCODER_C_2 6
#define ENCODER_D_1 7
#define ENCODER_D_2 8

#define ENCODER_A_REV false 
#define ENCODER_B_REV false 
#define ENCODER_C_REV true 
#define ENCODER_D_REV true

#define CHOPSTICK_MOTOR_PWM 5
#define CHOPSTICKS_ROTATE_SPEED -1.0
#define CHOPSTICKS_SPIN_UP_BUTTON 5
#define CHOPSTICKS_SPIN_DOWN_BUTTON 3

#define VERTICAL_CHOPSTICKS_MOTOR_PWM 6
#define CHOPSTICKS_MOVE_DOWN_SPEED 1.0
#define CHOPSTICKS_MOVE_UP_SPEED -1.0
#define CHOPSTICKS_MOVE_UP_BUTTON 6
#define CHOPSTICKS_MOVE_DOWN_BUTTON 4


#define RELEASE_MOTOR_PWM 8
#define THROW_BUTTON 1
#define RELEASE_SPEED 1
#define RELEASE_RELOAD 0.2
#define RETRACT_BUTTON 12
#define PAYOUT_BUTTON 11
#define BALL_ULTRASONIC 4
#define BALL_ULTRASONIC_MODULE 1

#define WINCH_MOTOR_PWM 7
#define WINCH_RETRACT_SPEED 1.0
 
#define QR_FIRING_LIMIT_SWITCH 9
#define QR_PASSING_LIMIT_SWITCH 11
#define CATA_LIMIT_SWITCH 10

#define QR_OPEN_TIMEOUT 4.0
#define QR_CLOSE_TIMEOUT 4.0
#define QR_CLOSE_MIN_TIME 1.2
#define WINCH_PAYOUT_TIMEOUT 1.5
#define WINCH_RETRACT_TIMEOUT 4.0

#define LINE_COUNTER_TRIGGER 3

#define KP 0.0
#define KI 4.0e-4
#define KD 0.0
#define VMAX 2300.0
#define KFF 1.0/VMAX

#define BALL_ULTRASONIC_THRESHOLD 0.1

#define LINE_SENSOR_MINIMUM_THRESHHOLD 1.6
#define LINE_SENSOR_MAXIMUM_THRESHHOLD 2.0

#define WINCH_PAYOUT_COUNTS 5

#define WINCH_OPEN_BUTTON 9

#define QR_CLOSE_BUTTON 10

//#define IR_DEBUG 1

#define MIN_FIRE_RANGE 2.0
#define MAX_FIRE_RANGE 3.0
 
#endif
