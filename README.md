# Simple Quiz - Arduino

<p>This is the simple quiz made for Arduino UNO microcontroller.</p>

<p>To use this program, it is needed to connect components and Arduino microcontroller according to a schema displayed below. </p>

<img src="https://user-images.githubusercontent.com/23532087/66988855-84464f00-f0c3-11e9-8c15-fa52700f596f.png" width="550" height="350" />

<img src="https://user-images.githubusercontent.com/23532087/66988887-932d0180-f0c3-11e9-93b1-61196d46d15c.png" width="550" height="400" />

<p>When program is started, question is displayed on serial monitor. The user needs to answer if that question is true or false by pressing a button.
The user has 5 seconds to answer, after each second corresponding sound is heard and one LED is turning on. In this way, the user is signalled that one second has passed and how much time is left.</p>
<p>If the user does not answer, all the LEDs are turned on and the corresponding sound is heard.</p>
<p>If the user answer correctly, the green LED is turned on and corresponding sound is heard,otherwise the red LED is turned on and corresponding sound is heard.</p>
<p>The score is displayed on serial monitor, as total number of correct and incorrect answers.</p>