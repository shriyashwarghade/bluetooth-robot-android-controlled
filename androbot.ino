String voice;

int EN1 = 9;  
int EN2 = 10;  
int IN1 = 8;
int IN2 = 7;
int IN3 = 5; 
int IN4 = 6;

void walk()
{
   digitalWrite(IN3,HIGH); 
   digitalWrite(IN4,LOW); 
   digitalWrite(IN1,HIGH);
   digitalWrite(IN2,LOW);
   
}

void back()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH); 

}


void right()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(1000);
  digitalWrite(IN1,LOW);
  digitalWrite(IN4,LOW);
}

void right180()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(2000);
  digitalWrite(IN1,LOW);
  digitalWrite(IN4,LOW);
}

void right360()
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(4000);
  digitalWrite(IN1,LOW);
  digitalWrite(IN4,LOW);
}

void left()
{
  digitalWrite(IN2,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(IN3,HIGH);
  delay(1000);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
}

void left180()
{
  digitalWrite(IN2,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(IN3,HIGH);
  delay(2000);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
}
void left360()
{
  digitalWrite(IN2,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(IN3,HIGH);
  delay(4000);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
}

void allstop()
{
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
}

void setup() 
{ 
  Serial.begin(9600);   
  for(int i=5;i<=10;i++)  //For Arduino Motor driver
    pinMode(i, OUTPUT);  //set pin 5,6,7,8,9,10 to output mode
} 
  
void loop() 
{ 
  while (Serial.available())
  {  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  if (voice.length() > 0) 
  {
    
    Serial.println(voice);
    
  
  
      if(voice == "walk")//assign the value on pressing which you want the led to blink
         {
             walk();
             
         }
      
      else if(voice=="back")//assign the value on pressing which you want the led to blink
         {
             
                 back();
         }
      else if(voice == "right")//assign the value on pressing which you want the led to blink
         {
             
                 right();
         }
      
       else if(voice == "left")//assign the value on pressing which you want the led to blink
         {
             left();
         }
        else if(voice == "right180")//assign the value on pressing which you want the led to blink
         {
             
                 right180();
         }
         
         
         else if(voice == "right360")//assign the value on pressing which you want the led to blink
         {
               right360();
               
         }  
         
         else if(voice == "left180")//assign the value on pressing which you want the led to blink
         {
           left180();
           
          }
          
          else if(voice == "left360")//assign the value on pressing which you want the led to blink
         {
           left360();
           
          }


      else
        {
             
                  allstop();
         }
      voice="";
} 
}
