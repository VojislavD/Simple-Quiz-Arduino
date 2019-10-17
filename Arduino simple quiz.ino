/* 
* Vojislav Dragicevic
* Arduino Simple Quiz
*/
const int button1 = 2;
const int button2 = 3;
const int ledGreen = 4;
const int ledRed = 5;
const int buzzer = 6;
const int led1s = 9;
const int led2s = 10;
const int led3s = 11;
const int led4s = 12;
const int led5s = 13;

int leftButtonState = 0;
int rightButtonState = 0;
int numOfCorrectAnsw = 0;
int numOfIncorrectAnsw = 0;
int helperForQuestions=0;
int helperForTimer = 0;
unsigned long start;
int i;

String questions[] = {
    "Link between CPU and memory is provided by bus.",
    "A/D block converts analog signal to binary number and forwards it to CPU block",
    "Longer leg is the negative side of the LED (cathode), and shorter leg is the positive side (anode).",
    "On the resistor the color of the third ring represents multiplier.",
    "Microcontrollers have a high power consumption.",
    "Microcontrollers understand only binary numbers.",
    "CISC is abbreviation of Complex Instruction Set Computer.",
    "RISC is abberviation of Reliable Instruction Set Computer.",
    "The ADC operates at frequencies between 50 kHz and 200 kHz.",
    "The position of the servo motor has range from 0 to 360 degrees."
  };
String correctAnsw[] = {
    "Yes",
    "Yes",
    "No",
    "Yes",
    "No",
    "Yes",
    "Yes",
    "No",
    "No",
    "No"
  };

void setup()
{ 
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(led1s, OUTPUT);
  pinMode(led2s, OUTPUT);
  pinMode(led3s, OUTPUT);
  pinMode(led4s, OUTPUT);
  pinMode(led5s, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{ 
  leftButtonState = digitalRead(button1);
  rightButtonState = digitalRead(button2);
   
  if(helperForQuestions%2 == 0 ) {
    i= random(10);
    displayQuestion(i);
    helperForQuestions++;
  }
  
  if(helperForTimer%2 == 0) {
    helperForTimer++;
    start = millis();
  }
  timeCounter();

  if(leftButtonState == HIGH || rightButtonState == HIGH) {
    checkAnswer(i);
    helperForTimer++;
    helperForQuestions++;
    turnOffAll();
  } else if(millis() > start+5500) {
    Serial.print("Time is up, correct answer is \"");
    Serial.print(correctAnsw[i]+"\".\n");
    numOfIncorrectAnsw++;
    displayScore();
    Serial.println("-------------------------------------------------------------------------------------------\n");
    timeIsUpSound();
    helperForTimer++;
    helperForQuestions++;
    delay(4000);
    turnOffAll();
  }

}

//Display question
void displayQuestion(int i) {
  Serial.println(questions[i]);
    delay(1000);
    Serial.println("Time starts in:");
    delay(1000);
    for(int j=3;j>0;j--){
      Serial.println(j);
      delay(1000);
    }
}

//Timer
void timeCounter() {
   if (millis() > start+1000 && millis() < start+1100) {
      digitalWrite(led1s, HIGH);
      beepSound();
    } else if (millis() > start+2000 && millis() < start+2100) {
      digitalWrite(led2s, HIGH);
      beepSound();
    } else if (millis() > start+3000 && millis() < start+3100) {
      digitalWrite(led3s, HIGH);
      beepSound();
    } else if (millis() > start+4000 && millis() < start+4100) {
      digitalWrite(led4s, HIGH);
      beepSound();
    } else if (millis() > start+5000 && millis() < start+5100) {
      digitalWrite(led5s, HIGH);
      beepSound();
  }
}

//Timer sound
void beepSound() {
  tone(buzzer, 400,100);
}

//Check if answer is correct
void checkAnswer(int i) {
  if(leftButtonState == HIGH){
      delay(1000);
      if(correctAnsw[i] == "Yes") {
        Serial.println("Your answer is correct.");
        numOfCorrectAnsw++;
        displayScore();
        Serial.println("-------------------------------------------------------------------------------------------\n");
        digitalWrite(ledGreen, HIGH);
        correctAnswerSound();
        delay(4000);
      } else {
        Serial.println("Your answer is incorrect.");
        numOfIncorrectAnsw++;
        displayScore();
        Serial.println("-------------------------------------------------------------------------------------------\n");
        digitalWrite(ledRed, HIGH);
        incorrectAnswerSound();
        delay(4000);
      }
    } else if(rightButtonState == HIGH) {
      delay(1000);
      if(correctAnsw[i] == "Yes") {
        Serial.println("Your answer is incorrect.");
        numOfIncorrectAnsw++;
        displayScore();
        Serial.println("-------------------------------------------------------------------------------------------\n");
        digitalWrite(ledRed, HIGH);
        incorrectAnswerSound();
        delay(4000);
      } else {
        Serial.println("Your answer is correct.");
        numOfCorrectAnsw++;
        displayScore();
        Serial.println("-------------------------------------------------------------------------------------------\n");
        digitalWrite(ledGreen, HIGH);
        correctAnswerSound();
        delay(4000);
      }
    }
}

//Display Score
void displayScore() {
  Serial.print("Your score: Correct answers = ");
  Serial.print(numOfCorrectAnsw);
  Serial.print("  |   Incorrect answers = ");
  Serial.print(numOfIncorrectAnsw);
  Serial.println();
}

//Correct answer sound
void correctAnswerSound() {
  tone(buzzer, 240);
  delay(50);
  tone(buzzer, 280);
  delay(70);
  tone(buzzer, 320);
  delay(100);
  tone(buzzer, 360);
  delay(140);
  tone(buzzer, 400);
  delay(190);
  noTone(buzzer);
}

//Incorrect answer sound
void incorrectAnswerSound() {
  tone(buzzer, 400);
  delay(70);
  tone(buzzer, 360);
  delay(110);
  tone(buzzer, 320);
  delay(170);
  tone(buzzer, 280);
  delay(220);
  tone(buzzer, 240);
  delay(270);
  noTone(buzzer);
}

//Time is up sound
void timeIsUpSound() {
  tone(buzzer, 400,2500);
}

//Turn off all leds
void turnOffAll() {
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(led1s, LOW);
  digitalWrite(led2s, LOW);
  digitalWrite(led3s, LOW);
  digitalWrite(led4s, LOW);
  digitalWrite(led5s, LOW);
}
