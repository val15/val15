char mot[20]; //le mot lu sur la voie série

int b;
int etatAllumer,etaboutton,eta;

void setup()
{
    //on dÃ©marre la liaison en la rÃ©glant Ã  une vitesse de 9600 bits par seconde.
    Serial.begin(9600);
    
    
 /* Serial.println(toMinuscule('Z'));
  Serial.println(toMaguscule('x'));*/
  
    pinMode(3, INPUT);
    pinMode(12, OUTPUT);
    digitalWrite(12,HIGH);
    
}
void loop()
{
    //votre programme
    
   // if(L==
    char carlu = 0; //variable contenant le caractÃ¨re Ã  lire
    int cardispo = 0; //variable contenant le nombre de caractÃ¨re disponibles dans le buffer
    
    cardispo = Serial.available();
    
    /*while(cardispo > 0) //tant qu'il y a des caractÃ¨res Ã  lire
    {
        carlu = Serial.read(); //on lit le caractÃ¨re
        if(carlu>='A' && carlu<='Z')
        {
            Serial.print(toMinuscule(carlu));
        }
       else if(carlu>='a' && carlu<='z')
        {
            Serial.print(toMaguscule(carlu));
        }
        else if(carlu=='0')
        {
          //Serial.print(carlu); //puis on le renvoi Ã  lâexpÃ©diteur tel quel
          digitalWrite(12,0);
        }
        else if(carlu=='1')
        {
          //Serial.print(carlu); //puis on le renvoi Ã  lâexpÃ©diteur tel quel
          digitalWrite(12,1);
          
        }
        cardispo = Serial.available(); //on relit le nombre de caractÃ¨res dispo
    }*/
    
    
    if(Serial.available())
    {
        //alors on va lire le contenu de la réception
        lireVoieSerie();
        //on entre dans une variable la valeur retournée par la fonction comparerMot()
        
    }
    
    
    eta = digitalRead(3);
    if((eta!=etaboutton) && eta==0)
      {
        if(!etatAllumer)
        {
          //b=1;
          Serial.println("0");
          etatAllumer=!etatAllumer;
        }
        else
        {
          //b=2;
          Serial.println("1");
           etatAllumer=!etatAllumer;
        }
      }
      etaboutton=eta;
      
      if(b==1)
        digitalWrite(12,0);
      if(b==2)
        digitalWrite(12,2);
    //fin du programme 
}

//lit un mot sur la voie série (lit jusqu'à rencontrer le caractère '\n')
void lireVoieSerie(void)
{
    int i = 0; //variable locale pour l'incrémentation des données du tableau
    
    //on lit les caractères tant qu'il y en a
    //OU si jamais le nombre de caractères lus atteint 19 (limite du tableau stockant le mot ­ 1 ca
    while(Serial.available() > 0 && i <= 19)
    {
        //on enregistre le caractère lu
        mot[i] = Serial.read();
        //laisse un peu de temps entre chaque accès a la mémoire
        delay(10);
        //on passe à l'indice suivant
        i++;
    }
    //on supprime le caractère '\n' et on le remplace par celui de fin de chaine '\0'
    mot[i] = '\0';
    Serial.println(mot);
    
    if(strcmp(mot, "allumer") == 0)
    {   
        digitalWrite(12,0);
    }
    
    if(strcmp(mot, "etindre") == 0)
    {   
        digitalWrite(12,1);
    }
}




char toMinuscule(char I)
{
  char i,c=0;
  char chT='A';
  for(c=0;c<27;c++)
  {
    
    if(I==chT)
    {
      i='a'+c;
    }
    chT++;  
  }  
  return i;  
}

char toMaguscule(char I)
{
  char i,c=0;
  char chT='a';
  for(c=0;c<27;c++)
  {
    
    if(I==chT)
    {
      i='A'+c;
    }
    chT++;  
  }  
  return i;  
}
