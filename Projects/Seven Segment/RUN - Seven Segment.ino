char angka=0;

#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
#define s1 digitalRead(13)
#define s2 digitalRead(12)


void tampilkan_angka (void){
if (angka==0){
//0
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);

digitalWrite(g,0);
//--
}
if (angka==1){
//1
digitalWrite(a,0);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,0);
//--
}

if (angka==2){
//2
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,0);
digitalWrite(d,1);
digitalWrite(e,1);

digitalWrite(f,0);
digitalWrite(g,1);
//--
}
if (angka==3){
//3
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,1);
//--
}

if (angka==4){
//4
digitalWrite(a,0);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,0);

digitalWrite(e,0);
digitalWrite(f,1);
digitalWrite(g,1);
//--
}
if (angka==5){
//5
digitalWrite(a,1);
digitalWrite(b,0);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,0);
digitalWrite(f,1);
digitalWrite(g,1);
//--
}

if (angka==6){
//6
digitalWrite(a,1);
digitalWrite(b,0);
digitalWrite(c,1);

digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,1);
//--
}
if (angka==7){
//7
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,0);
digitalWrite(e,0);
digitalWrite(f,0);
digitalWrite(g,0);
//--
}
if (angka==8){
//8
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);

digitalWrite(d,1);
digitalWrite(e,1);
digitalWrite(f,1);
digitalWrite(g,1);
//--
}
if (angka==9){
//9
digitalWrite(a,1);
digitalWrite(b,1);
digitalWrite(c,1);
digitalWrite(d,1);
digitalWrite(e,0);
digitalWrite(f,1);
digitalWrite(g,1);
//--
}
}

void setup() {
// put your setup code here,
//to run once:

pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);

pinMode(9,INPUT);
pinMode(10,INPUT);


}

void loop() {
// put your main code here,
//to run repeatedly:
tampilkan_angka();

if (s1==0){
tampilkan_angka();

angka++;
delay(200);
delay(200);
}

if (s2==0){
tampilkan_angka();
angka--;
delay(200);
delay(200);
}

if (angka>9){
angka=9;
}
if (angka<0){
angka=0;
}

}
