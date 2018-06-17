#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_CS_PIN           53

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_CS_PIN           49

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_CS_PIN           40
int x, y, z, ileX, ileY, ileZ, tmp;
int licznik = 1000;
String s;
bool flaga=true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(X_MAX_PIN, INPUT);
  digitalWrite(X_MAX_PIN, HIGH);
  pinMode(Y_MAX_PIN, INPUT);
  digitalWrite(Y_MAX_PIN, HIGH);
  pinMode(Z_MAX_PIN, INPUT);
  digitalWrite(Z_MAX_PIN, HIGH);
  pinMode(X_ENABLE_PIN, OUTPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  pinMode(X_DIR_PIN, OUTPUT);
  digitalWrite(X_DIR_PIN, LOW);
  pinMode(X_STEP_PIN, OUTPUT);

  pinMode(Y_ENABLE_PIN, OUTPUT);
  digitalWrite(Y_ENABLE_PIN, LOW);
  pinMode(Y_DIR_PIN, OUTPUT);
  digitalWrite(Y_DIR_PIN, LOW);
  pinMode(Y_STEP_PIN, OUTPUT);

  pinMode(Z_ENABLE_PIN, OUTPUT);
  digitalWrite(Z_ENABLE_PIN, LOW);
  pinMode(Z_DIR_PIN, OUTPUT);
  digitalWrite(Z_DIR_PIN, LOW);
  pinMode(Z_STEP_PIN, OUTPUT);
  // ileX=licznik;
  // ileY=licznik;
  // ileZ=licznik;


}

void loop() {
  // put your main code here, to run repeatedly:
  x = digitalRead(X_MAX_PIN);
  y = digitalRead(Y_MAX_PIN);
  z = digitalRead(Z_MAX_PIN);
  while (Serial.available())
  {
    s = Serial.readStringUntil('\n');
    sscanf(s.c_str(), "x %d y %d z %d \n", &ileX, &ileY, &ileZ);
    flaga=false;
    
    if (ileX < 0)
    {
      ileX = -ileX;
      digitalWrite(X_DIR_PIN, HIGH);
    }
    else
    {
      digitalWrite(X_DIR_PIN, LOW);
    }


    if (ileY < 0)
    {
      ileY = -ileY;
      digitalWrite(Y_DIR_PIN, HIGH);
    }
    else
    {
      digitalWrite(Y_DIR_PIN, LOW);
    }


    if (ileZ < 0)
    {
      ileZ = -ileZ;
      digitalWrite(Z_DIR_PIN, HIGH);
    }
    else
    {
      digitalWrite(Z_DIR_PIN, LOW);
    }
    /*tmp = Serial.parseInt();
      if(tmp > 0)
      {
      ileX=tmp;
      ileY=tmp;
      ileZ=tmp;
      }*/
  }


  if (x == 0 && ileX > 0)
  {
    digitalWrite(X_STEP_PIN, HIGH);
    ileX--;
  }
  if (y == 0 && ileY > 0)
  {
    digitalWrite(Y_STEP_PIN, HIGH);
    ileY--;
  }
  if (z == 0 && ileZ > 0)
  {
    digitalWrite(Z_STEP_PIN, HIGH);
    ileZ--;
  }
  delayMicroseconds(200);
  digitalWrite(X_STEP_PIN, LOW);
  digitalWrite(Y_STEP_PIN, LOW);
  digitalWrite(Z_STEP_PIN, LOW);
  delayMicroseconds(200);

  if (ileX == 0 && ileY == 0 && ileZ == 0 && flaga==false)
  {
    Serial.println("Jestem na miejscu!");

    flaga=true;
  }


  // Serial.print(x);
  //Serial.print(y);
  //Serial.println(z);// po dopisku ln nowa linia
}
