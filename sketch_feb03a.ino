#include <Servo.h>

int PUERTA = 0;
int SALA = 5; 
int COCINA = 6; 
int DORMITORIO = 7; 
int BANO = 8;
int PATIO = 9;
int CARPORT = 10;
int PORTON = 11;

int estado = 0;
int buttonState = 0;  
int sistemaDeSeguridad = 0;
Servo myservo;

void setup() {
  Serial.begin(9600);
  pinMode(SALA, OUTPUT);
  pinMode(COCINA, OUTPUT);
  pinMode(DORMITORIO, OUTPUT);
  pinMode(BANO, OUTPUT);
  pinMode(PATIO, OUTPUT);
  pinMode(CARPORT, OUTPUT);  
  myservo.attach(PORTON);
  myservo.write(0);
}

void loop() {

  if (sistemaDeSeguridad == 1) {
    buttonState = analogRead(PUERTA);
    if (buttonState < 1000) {
      Serial.write("Z");
    }
  }
  
  if(Serial.available()>0) { // lee el bluetooth y almacena en estado
    estado = Serial.read();
  }

  if(estado=='A'){  
    sistemaDeSeguridad = 1; 
    myservo.write(0);         
  }

  if(estado=='B'){  
    sistemaDeSeguridad = 0;         
  }

  if(estado=='C'){  
    if (sistemaDeSeguridad == 0) { 
       myservo.write(80); 
    }   
  }

  if(estado=='D'){  
    //CERRAR PORTÓN
    myservo.write(0);     
  }
  
  if(estado=='E'){           
    digitalWrite(SALA, HIGH);     
  }

  if(estado=='F'){          
    digitalWrite(SALA, LOW);     
  }

  if(estado=='G'){          
    digitalWrite(COCINA, HIGH);     
  }

  if(estado=='H'){    
    digitalWrite(COCINA, LOW);     
  }

  if(estado=='I'){           
    digitalWrite(DORMITORIO, HIGH);     
  }

  if(estado=='J'){          
    digitalWrite(DORMITORIO, LOW);     
  }

  if(estado=='K'){           
    digitalWrite(BANO, HIGH);     
  }

  if(estado=='L'){          
    digitalWrite(BANO, LOW);     
  }

  if(estado=='M'){           
    digitalWrite(PATIO, HIGH);     
  }

  if(estado=='N'){          
    digitalWrite(PATIO, LOW);     
  }
  
  if(estado=='O'){           
    digitalWrite(CARPORT, HIGH);     
  }

  if(estado=='P'){          
    digitalWrite(CARPORT, LOW);     
  }
  
}
