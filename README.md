# cornwalltech

Practicing git for CornwallTech work experience.

Hello Mission to Mars!

Story 1: 

Learnt a lot about file explorer and how to use git in the terminal with slight experience in GitHub. The steps were not clear enough on having to relocate after the ssh key, so I kept making a README file in the key folder. If I could go back I would ask for help sooner. My brother helped me complete this.

Followed TechCornwall course 'TinkerCad Tutorial' and experimented with tutorial and given code of 3 LEDs flickering. Added potentiometer and pushbutton.

Following YouTube tutorial as I only used TechCornwall guide prior. Opened ReadMe in notepad, added text, saved ready to push back to GitHub. Adding Story 2.



Story 2: TinkerCad LEDs alternatively flashing

Followed TinkerCad image guide showing two LEDs, two 220 ohm resistors, Arduino Uno R3 and a solderless breadboard. I sourced code specific to making the LEDs flash alternatively. Gained fundamental TinkerCad and Arduino IDE knowledge.



Story 2a: Followed YouTube tutorial and learnt how to add variables and functions.



Story 3: Used TinkerCad Arduino board and set a pattern to 6 LEDs with three colours: green, yellow, red signifying move forward, stop, reverse. Coded using TinkerCad blocks. 1 of the red LEDs will not turn on, even after rewiring so I asked Robert for help.

I have rearranged the LEDs using the image guide and everything is working as it should.



Story 4: Added variables and functions to my code in Story 3. Re-wrote using C++ text.



Story 5: Wrote code to instruct the rover to move in a "snake" pattern, alternating the speeds of the left and right motors. Did not loop.



Story 6: Following the image guide, I added two pushbuttons which count the amount of interrupts for each motor of the rover. I was provided code and how many counts per metre it takes the rover. I modified it so that the rover will progress 2 metres and then terminate the program.



Story 7: The task was to drive into a tape "garage" and drive in a square figure of eight. I wrote a lot of void() blocks to make this easier; such as fwdRover, rightRover, leftRover etc. For the Story 7() I used "for" loops for accuracy in solving the story. I also magpied an example in the TechCornwall Arduino IDE course to check the temperature at the start of the Story 7() with a thermometer that is in the a0. This is in the checkEnvironment() at the start of the Story 7(). As instructed, I incorporated the given code from the NewPingExample.ino in the Arduino IDE library. This helped to include the ultrasonic sensor I added to the circuit to detect objects in front of the rover.



Story 8: I programmed an avoidance manoeuvre the rover performs if the ultrasonic sensors detect an object within approximately 12cm. The avoidance manoeuvre is where the rover detects an object, stops, pauses, reverses and turns 90 degrees left without hitting the object. This is in the checkEnvironment() which runs at the start of the loop.



Story 9: I included an "if"() so that the rover will want to stop if there is no ground within 5cm of the front of the robot. If it is moving forwards, when it encounters a drop in terrain over 12cm it is to stop and reverse half a second, stop and remain stopped.



Story 10:

