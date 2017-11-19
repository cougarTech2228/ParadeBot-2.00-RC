# ParadeBot-2.00-RC
This is the code for the first version of the new parade bot's drive system.  

11/18/2017

This is going to be a quick drive system for the new parade bot that will allow us to be up and running for the winter parade. 

This is primarily based around a 2.4 GHz RC transmiter.

The drive control is going to be tank drive, because that is easiest to do. The motor controlers will plug directly into the RC recievers, each side of the robot should only require 1 channel. (there are two CIMS and therefor two controllers, but they will be conntected together like we did on the old parade bot and conntected to a single channel)
*we could probably change it from tank drive using the arduino, but that wuld be more complicated and we just have to get it working first.

On a third channel, which is mapped to a switch on the controller, the arduino will be plugged in. The arduino will have a simple program that will handle dispensing candy from the hopper and actuating the device used for shooting the candy. 

Here's an example of the RC/arduino setup from sparkfun: https://www.sparkfun.com/tutorials/348 

That's basically it so far.
