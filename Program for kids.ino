int randNumber;

int btn1 = 12;
int btn2 = 10;
int btn3 = 8;

int temp = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  randNumber = random(3);

  int val = map(analogRead(A0), 0, 1023, 1, 5);
  Serial.println("곧 문제가 나옵니다.");
  delay(500);
  Serial.print(val); Serial.println("초의 시간이 주어집니다.");
  delay(1000);

  unsigned long now = millis();
  unsigned long will = now + (val * 1000);

  if(randNumber == 1){
    Serial.println("Push Rabbit Button!!!");
    Serial.println("Push Rabbit Button!!!");
    Serial.println("Push Rabbit Button!!!");
    delay(500); //delay

    Serial.println("Push button!");

    while(1){
      unsigned long tempnow = millis();
      if(tempnow > will){ //시간초과
        temp = 2;
        break;
      }

      if(digitalRead(btn1) == HIGH){
      if(tempnow < will){ //시간내에 맞춤
        temp = 1;
        break;
      }
      else{
        temp = 2; //시간초과
        break;
      }
      }
      else if(digitalRead(btn2) == HIGH || digitalRead(btn3) == HIGH){
        if(tempnow < will){
          temp = 3;
          break;
        }
        else{
          temp = 2;
          break;
        }
      }
    }    
  }


  /////////////////////////////////////////////////////////////////////////////////////////////////
  if(randNumber == 2){
    Serial.println("Push Elephant Button!!!");
    Serial.println("Push Elephant Button!!!");
    Serial.println("Push Elephant Button!!!");
    delay(500);

    Serial.println("Push button!");

    while(1){
      unsigned long tempnow = millis();
      if(tempnow > will){ //시간초과
        temp = 2;
        break;
      }

      if(digitalRead(btn2) == HIGH){
      if(tempnow < will){ //시간내에 맞춤
        temp = 1;
        break;
      }
      else{
        temp = 2; //시간초과
        break;
      }
      }
      else if(digitalRead(btn1) == HIGH || digitalRead(btn3) == HIGH){
        if(tempnow < will){
          temp = 3;
          break;
        }
        else{
          temp = 2;
          break;
        }
      }
    }
  }

  ///////////////////////////////////////////////////////////////////////////////////////
  if(randNumber == 3){
    Serial.println("Push Dog Button!!!");
    Serial.println("Push Dog Button!!!");
    Serial.println("Push Dog Button!!!");
    delay(500);

    Serial.println("Push button!");

    while(1){
      unsigned long tempnow = millis();
      if(tempnow > will){ //시간초과
        temp = 2;
        break;
      }

      if(digitalRead(btn3) == HIGH){
      if(tempnow < will){ //시간내에 맞춤
        temp = 1;
        break;
      }
      else{
        temp = 2; //시간초과
        break;
      }
      }
      else if(digitalRead(btn2) == HIGH || digitalRead(btn1) == HIGH){
        if(tempnow < will){
          temp = 3;
          break;
        }
        else{
          temp = 2;
          break;
        }
      }
    } 
  }

    if(temp == 1) for(int i = 0; i < 9; i++) Serial.println("맞았습니다!!");
    else if(temp == 2) for(int i = 0; i < 9; i++)  Serial.println("시간초과!!");
    else if(temp == 3) for(int i = 0; i < 9; i++)  Serial.println("틀렸습니다!!");
    else delay(500);

    temp = 0;
      Serial.println("");
      Serial.println("");

}
