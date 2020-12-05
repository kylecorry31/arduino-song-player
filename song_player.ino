
#include <avr/pgmspace.h>

// Country Roads Intro
// Frequency (Hz), Duration (ms)
const PROGMEM int SONG[] = {
    330, 360,
    330, 360,
    370, 360,
    330, 720,
    370, 360,
    330, 360,
    370, 360,
    440, 720,
    
    494, 360,
    494, 360,
    554, 360,
    494, 360,
    370, 180,
    370, 180,
    370, 180,
    330, 180,
    370, 180,
    440, 720
};

const int BUZZER_PIN = 6;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  int len = sizeof(SONG) / sizeof(int);
  for (int i = 0; i < len; i += 2){
    int note = pgm_read_word_near(SONG + i) * 2;
    int duration = pgm_read_word_near(SONG + i + 1);

    Serial.print(note);
    Serial.print(", ");
    Serial.println(duration);

    if (note == 0){
      noTone(BUZZER_PIN);
      delay(duration);
    } else {
     tone(BUZZER_PIN, note);
     delay(duration);
     noTone(BUZZER_PIN); 
    }
  }
  noTone(BUZZER_PIN);
}

void loop() {
  // Nothing here
  digitalWrite(BUZZER_PIN, LOW);
}
