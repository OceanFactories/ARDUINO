#define a 9 // mendefinisikan segmen ' a ' pada pin digital 4
#define b 8 // mendefinisikan segmen ' b ' pada pin digital 5
#define c 7 // mendefinisikan segmen ' c ' pada pin Analog 3 .
#define d 6 // mendefinisikan segmen ' d ' pada pin Analog 4 .
#define e 5 // mendefinisikan segmen ' e ' pada pin Analog 5
#define f 4 // mendefinisikan segmen ' f ' pada pin digital 3
#define g 3 // mendefinisikan segmen ' g ' pada pin digital 2
#define dp 2 // mendefinisikan segmen ' dot poin ' pada pin Analog 2
int nilai = 0;
int mapval = 0;
void setup ( )
  {
   pinMode( A0, INPUT);
   pinMode ( a , OUTPUT ) ; // A
   pinMode ( b , OUTPUT ) ; // B
   pinMode ( c , OUTPUT ) ; // C
   pinMode ( d , OUTPUT ) ; // D
   pinMode ( e , OUTPUT ) ; // E
   pinMode ( f , OUTPUT ) ; // E
   pinMode ( g , OUTPUT ) ; // G
   pinMode ( dp , OUTPUT ) ; // dot // dot point
   Serial.begin(9600);
}
byte angka = 0 ;
void loop(){
  Serial.println(mapval);
 nilai = analogRead(A0);
 mapval = map(nilai, 0,1023,0,255);
 if(mapval>256/10){
  angka = 0;
 }
 if(mapval>256*2/10){
  angka = 1;
 }
 if(mapval>256*3/10){
  angka = 2;
 }
 if(mapval>256*4/10){
  angka = 3;
 }
 if(mapval>256*5/10){
  angka = 4;
 }
 if(mapval>256*6/10){
  angka = 5;
 }
 if(mapval>256*7/10){
  angka = 6;
 }
 if(mapval>256*8/10){
  angka = 7;
 }
 if(mapval>256*9/10){
  angka = 8;
 }
 if(mapval>=255){
  angka = 9;
 }
switch ( angka ) {
    case 0 :
    digitalWrite ( a , HIGH ) ;
    digitalWrite ( b , HIGH ) ; 
    digitalWrite ( c , HIGH ) ;
    digitalWrite ( d , HIGH ) ;
    digitalWrite ( e , HIGH ) ;
    digitalWrite ( f , HIGH ) ;
    digitalWrite ( g , LOW ) ;
    break ;
    
    case 1 :
    digitalWrite ( a , LOW ) ;
    digitalWrite ( b , HIGH ) ;
    digitalWrite ( c , HIGH ) ;
    digitalWrite ( d , LOW ) ;
    digitalWrite ( e , LOW ) ;
    digitalWrite ( f , LOW ) ;
    digitalWrite ( g , LOW ) ;
    break ;
    
    case 2 :
    digitalWrite ( a , HIGH ) ;
    digitalWrite ( b , HIGH ) ;
    digitalWrite ( c , LOW ) ;
    digitalWrite ( d , HIGH ) ;
    digitalWrite ( e , HIGH ) ;
    digitalWrite ( f , LOW ) ;
    digitalWrite ( g , HIGH ) ;
    break ;
    
    case 3 :
    digitalWrite( a , HIGH ) ;
    digitalWrite( b , HIGH ) ;
    digitalWrite( c , HIGH ) ;
    digitalWrite( d , HIGH ) ;
    digitalWrite( e , LOW ) ;
    digitalWrite( f , LOW ) ;
    digitalWrite( g , HIGH ) ;
    break ;  
           
    case 4 :
    digitalWrite ( a , LOW ) ;
    digitalWrite ( b , HIGH ) ;
    digitalWrite ( c , HIGH ) ;
    digitalWrite ( d , LOW ) ;
    digitalWrite ( e , LOW ) ;
    digitalWrite ( f , HIGH ) ;
    digitalWrite ( g , HIGH ) ;
    break ;
    
    case 5 :
    digitalWrite( a , HIGH ) ;
    digitalWrite( b , LOW ) ;
    digitalWrite( c , HIGH ) ;
    digitalWrite( d , HIGH ) ;
    digitalWrite( e , LOW ) ;
    digitalWrite( f , HIGH ) ;
    digitalWrite( g , HIGH ) ;
    break ; 
    
    case 6 :
    digitalWrite( a , HIGH ) ;
    digitalWrite( b , LOW ) ;
    digitalWrite( c , HIGH ) ;
    digitalWrite( d , HIGH ) ;
    digitalWrite( e , HIGH ) ;
    digitalWrite( f , HIGH ) ;
    digitalWrite( g , HIGH ) ;
    break ; 
    case 7 :
    digitalWrite( a , HIGH ) ;
    digitalWrite( b , HIGH ) ;
    digitalWrite( c , HIGH ) ;
    digitalWrite( d , LOW ) ;
    digitalWrite( e , LOW ) ;
    digitalWrite( f , LOW ) ;
    digitalWrite( g , LOW ) ;
    break ; 
    
    case 8 :
    digitalWrite( a , HIGH ) ;
    digitalWrite( b , HIGH ) ;
    digitalWrite( c , HIGH ) ;
    digitalWrite( d , HIGH ) ;
    digitalWrite( e , HIGH ) ;
    digitalWrite( f , HIGH ) ;
    digitalWrite( g , HIGH ) ;
    break ; 
    
    case 9 :
    digitalWrite( a , HIGH ) ;
    digitalWrite( b , HIGH ) ;
    digitalWrite( c , HIGH ) ;
    digitalWrite( d , HIGH ) ;
    digitalWrite( e , LOW ) ;
    digitalWrite( f , HIGH ) ;
    digitalWrite( g , HIGH ) ;
    break ; 
}
   }
