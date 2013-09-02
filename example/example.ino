void setup() 

{

  Serial.begin(115200);

  Serial.println("Waiting for Card\n");
  Serial1.begin(9600);

  Serial1.write(0x02); //Send the command to RFID, please refer to RFID manual

}

void loop() // run over and over

{

  if (Serial1.available())
    {
      Serial.print("\n\rCARD SERIAL: ");
      for (unsigned int i=0; i<4 ;i=i){
        //Serial.print("2");   
        if (Serial1.available()) {
            //Serial.print("\n\ri is: ");Serial.print(i);Serial.print(" ");
            Serial.print(Serial1.read(),HEX); //Display the Serial Number in HEX
            i++;
          }
        }
       
       Serial.println("\n\rRead Card Make...");
       Serial1.write(0xAB);Serial1.write(0x02);Serial1.write(0x01);
       
       Get_Reply();
       
       Serial1.write(0x02); //Send the command to RFID, please refer to RFID manual
    }
   
}

void Get_Reply() {
       while (!Serial1.available());
       devnull = Serial1.read();
       while (!Serial1.available());
       returnLength = Serial1.read() - 1;
       
       for (unsigned int i=0;i< returnLength;i=i){
         //Serial.print("2");
         if (Serial1.available()) {
            //Serial.print("\n\ri is: ");Serial.print(i);Serial.print(" ");
            Serial.print(Serial1.read(),HEX); //Display the Serial Number in HEX
            i++;
          }
        }
}
/*
   if (Serial.available()){
    command = Serial.read();
    switch ( command ){
    case '1':
        Serial.println("\n\rRead Card Make...");
        Serial1.write(0xAB);Serial1.write(0x02);Serial1.write(0x01);
        break;
    case '2':
        Serial.println("\n\rRead Card Serial...");
        Serial1.write(0xAB);Serial1.write(0x02);Serial1.write(0x02);
        break;
    case '3':
        Serial.println("\n\rRead Card DATA...");
        Serial1.write(0xAB);
        Serial1.write(0x0A);
        Serial1.write(0x03);
        Serial1.write(0x04);
        Serial1.write(0x00,HEX);
        Serial1.write(0xFF);
        Serial1.write(0xFF);
        Serial1.write(0xFF);
        Serial1.write(0xFF);
        Serial1.write(0xFF);
        Serial1.write(0xFF);
        break;
    }
  }
  */ 
