
#include "ArduinoC.h"


#define leftForward 2
#define leftSpeed 3
#define leftBackward 4

#define rightForward 5
#define rightSpeed 6
#define rightBackward 7

#define forwardDir 'F'
#define backDir 'B'
#define leftDir 'L'
#define rightDir 'R'
#define forwardLeftDir 'G'
#define forwardRightDir 'l'
#define backLeftDir 'H'
#define backRightDir 'J'
#define stopDir 'S'
#define stopAll 'D'
int speed = 200;
CarMotors car(leftForward, leftSpeed, leftBackward, rightForward, rightSpeed, rightBackward);

void setup()
{
    car.setUp();
    Serial.begin(9600);
}
void loop()
{
    if (Serial.available())
    {
        char read = Serial.read();
        switch (read)
        {
        case forwardDir:
            car.forward(speed);
            break;
        case backDir:
            car.backward(speed);
            break;
        case leftDir:
            car.left(speed);
            break;
        case rightDir:
            car.right(speed);
            break;
        case forwardRightDir:
            car.forwardRight(speed);
            break;

        case forwardLeftDir:
            car.forwardLeft(speed);
            break;
        case backLeftDir:
            car.backwardLeft(speed);
            break;
        case backRightDir:
            car.backwardRight(speed);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'q':
            speed = map(read != 'q' ? int(read - '0') : 10, 0, 10, 0, 255);
            break;
        case stopAll:
        case stopDir:
            car.stop();
        default:
            car.stop();
            break;
        }
    }
}
