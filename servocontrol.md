Below is the component circuit of servocontrol.cpp:

![rangkaian](https://i.imgur.com/fAeoM45.png)

Device opreations:
1. The ultrasonic sensor emits a signal and captures the reflected signal, allowing it to detect objects at a certain distance.
2. If the sensor reading is below 10 cm, the servo will not rotate.
3. If the sensor reading is above 10 cm, the servo will rotate according to the sensor reading
4. For every 2 cm increment in the sensor reading, the servo will rotate by 10 degrees.
