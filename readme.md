The first part: electronic current and voltage detection module
1. Battery charge and discharge control, automatically set off after setting;
2. Can set the charge and discharge time;
3. With serial communication function, the working status of the relay can be monitored in real time through the serial port;
4. An additional signal output, when the relay conduction condition is met, the output level is high, and other devices can be controlled.
5. With reverse connection protection, reverse connection does not burn;
Detection detection voltage detection 0-150V (within 1% accuracy)
Operating mode:
Upper voltage limit: UL1, lower voltage limit nL1, upper voltage limit is greater than the lower voltage limit (UL1>nL1)
U-1: Charging measurement: When the measured voltage is lower than the lower limit voltage, the relay pulls in, the upper limit voltage is higher, and the relay is disconnected;
U-2: Charging measurement time control: set charging time (OP); when the measured voltage is lower than the lower limit voltage, the relay pulls in, the OP time starts counting down after the pull-in, the time is up, the relay is disconnected; above the upper limit voltage, the relay disconnect.

U-1 and U-2 use one IO port to control one relay K1 (U1, U2 can set the same value)

U-3: Discharge detection: When the measured voltage is lower than the lower limit voltage, the relay is disconnected, higher than the upper limit voltage, and the relay is closed;
U-4: Discharge detection time control: set discharge time (OP); when the measured voltage is higher than the upper limit voltage, the relay is closed, and the OP time starts counting down after the pull-in, the time is up, the relay is disconnected; when the measured voltage is lower than the lower limit Voltage, relay disconnected;

U-3 and U-4 use one IO control relay K2 (U3, U4 can set the same value)

U-5: Interval in the interval: When the measured voltage is between the upper limit and the lower limit, the relay is closed and the other conditions are disconnected;

U-5 one IO port, control relay K3
U-6: Interval outside the range: When the measured voltage is lower than the lower limit voltage or higher than the upper limit voltage, the relay is closed, and the relay is disconnected in other cases;
U-6 an IO port, control relay K4

The values ​​set by K1, K2, K3, and K4 do not affect each other.
Current detection section
Relay action upper limit setting current range: 0.1A ~ 50.0A Note: Setting 0.0A is to cancel the overcurrent action function
Relay action lower limit setting current range: 0.1A ~ 49.9A Note: Set 0.0A to cancel the overcurrent action function
Relay action start time: 0S ~ 9.9S
Current upper limit setting ----- with an IO control relay K4+ timing (upper K4 and same)
Mode U7 enters the overcurrent setting mode, and the digital tube will flash, as shown in Figure 4. At this time, the upper limit current value of the relay action is set. The value is set by the "plus" and "minus" keys. When the current exceeds the setting If the value is fixed, the relay will act.
The upper limit is divided into two files:
A current setting value + time (OP)
B = A*1.2
A or B value reaches relay action
A value time setting: OP time setting (0---99S)
The B value does not require time setting, and the relay works when the B value is reached.

Mode U8 enters the current lower limit + time setting (OP) and the upper limit current with the same relay

In the alarm setting mode, the digital tube will flash, as shown in Figure 6. At this time, the relay action lower limit current value is set. The value is set by the "plus" and "minus" keys. When the current is lower than the set value, Then the relay operates.
Lower limit time setting OP (0-600S)
https://item.taobao.com/item.htm?spm=a1z09.2.0.0.3b572e8dGpQFlq&id=541149851101&_u=m33im9c2a21 (network instance)
Each of the above modes can be individually set to have no effect on each other. The digital tube and buttons are placed on the back of the component because they are stuck on the chassis; two digital tubes display voltage and one display current.
