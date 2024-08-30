#include <stdio.h>
#include <stdlib.h>
int main() {
int P[] = {111, 112, 113, 114, 115, 116, 121, 122, 123, 124, 125, 126, 131,
132, 133, 134, 135, 136, 141, 142, 143, 144, 145, 146, 151, 152, 153, 154, 155,
156, 161, 162, 163, 164, 165, 166, 211, 212, 213, 214, 215, 216, 221, 222, 223,
224, 225, 226, 231, 232, 233, 234, 235, 236, 241, 242, 243, 244, 245, 246, 251,
252, 253, 254, 255, 256, 261, 262, 263, 264, 265, 266, 311, 312, 313, 314, 315,
316, 321, 322, 323, 324, 325, 326, 331, 332, 333, 334, 335, 336, 341, 342, 343,
344, 345, 346, 351, 352, 353, 354, 355, 356, 361, 362, 363, 364, 365, 366, 411,
412, 413, 414, 415, 416, 421, 422, 423, 424, 425, 426, 431, 432, 433, 434, 435,
436, 441, 442, 443, 444, 445, 446, 451, 452, 453, 454, 455, 456, 461, 462, 463,
464, 465, 466, 511, 512, 513, 514, 515, 516, 521, 522, 523, 524, 525, 526, 531,
532, 533, 534, 535, 536, 541, 542, 543, 544, 545, 546, 551, 552, 553, 554, 555,
556, 561, 562, 563, 564, 565, 566, 611, 612, 613, 614, 615, 616, 621, 622, 623,
624, 625, 626, 631, 632, 633, 634, 635, 636, 641, 642, 643, 644, 645, 646, 651,
652, 653, 654, 655, 656, 661, 662, 663, 664, 665, 666};
int key, i, nstart, guess;
int j = 0, z;
int turn = 0;
int chances = 6;
int clue1=0, clue2=0;
int a=0, b=0, c=0, d=0, e=0, f=0;
int num1[4];
/* ----- GAMES INTRO AND RULES ----- */
printf("GAME OBJECTIVES: \nPlayer 1 picks a number from set P to be his KEY.\
nAs Player 2 guesses and inputs numbers one by one, chance (starting from 6)
decreases for every wrong answer he makes.\n"); // game objectives
printf("\nPress 1 to start: ");
scanf("%d", &nstart);
while(nstart != 1){
printf("Invalid input.\nPress 1 to start:");
scanf("%d", &nstart);
}
system("clear"); // clears the system to formally start the game
// system("cls"); for window
/* ----- PLAYER 1'S TURN ----- */
while (j==0)
{
printf("PLAYER 1'S TURN.\nSelect any 3 digit number with digits from 1-6.\
nInput the key: ");
scanf("%d", &key);
int arrLen = sizeof P / sizeof P[0];
int isElementPresent = 0;
for (int i = 0; i < arrLen; i++) {
if (P[i] == key) {
isElementPresent = 1;
break;
}
}
if (isElementPresent) {
printf("%d is an acceptable key.\n\n", key);
a = key / 100;
b = key / 10 % 10;
c = key % 10;
printf("a is %d.\n", a);
printf("b is %d.\n", b);
printf("c is %d.\n", c);
j = 1;
}
else {
printf("%d is not an acceptable key.\n\n", key);
j = 0;
}
}
system("clear"); // clears the system to formally start the game
// system("cls"); for window
/* ----- PLAYER 2'S TURN ----- */
while (turn==0 && chances > 0 && key != guess){ // loop while it is still
turn and chances are greater than 0 or key has not yet been guessed
int isElementPresent = 0;
printf("\nPLAYER 2'S TURN.");
printf("\nSelect any 3 digit number with digits from 1-6."); // shows
choices
printf("\n\nChances left are %d\n", chances);
printf("Input your guess: ");
scanf("%d", &guess);
for(i=0; i<216; i++){ // checks if input is in P array
if (guess == P[i] && guess != key){ // if guess is an element of P
array but not x (the key)
isElementPresent = 1;
}
else if (guess == P[i] && guess == key){ // if guess is an element of P
array and also the x
isElementPresent = 2;
}
}
if(isElementPresent == 1){ // if guess is within P array but not the
key
// dividing input into hundredths, tenths, and ones place
for comparison
d = guess / 100;
e = guess / 10 % 10;
f = guess % 10;
printf("\nd is %d.\n", d);
printf("e is %d.\n", e);
printf("f is %d.\n", f);
//clue checker
// clue1: checks the cardinality of same numbers from x and guess
regardless of position
z=0;
i=0;
num1[0]=a;
num1[1]=d;
num1[2]=e;
num1[3]=f;
for(j = i + 1; j < 4; j++)
{
if(num1[i] == num1[j])
{
z++;
if(z==1){
clue1=clue1+z;
break;
}
}
}
if(a!=b){
z=0;
i=0;
num1[0]=b;
num1[1]=d;
num1[2]=e;
num1[3]=f;
for(j = i + 1; j < 4; j++)
{
if(num1[i] == num1[j])
{
z++;
if(z==1){
clue1=clue1+z;
break;
}
}
}
}
if(a!=b&&b!=c&&a!=c){
z=0;
i=0;
num1[0]=c;
num1[1]=d;
num1[2]=e;
num1[3]=f;
for(j = i + 1; j < 4; j++)
{
if(num1[i] == num1[j])
{
z++;
if(z==1){
clue1=clue1+z;
break;
}
}
}
}
// clue2: checks if the digits from guess match the correct value and
position in x
if (a==d){ // checker for a==d
clue2 = clue2 + 1;
}
if (b==e){ //checker for b==e
clue2 = clue2 + 1;
}
if (c==f){// checker for c==f
clue2 = clue2 + 1;
}
printf("\nClue 1: %d", clue1);
printf("\nClue 2: %d\n", clue2);
clue1 = 0;
clue2 = 0;
}
else if(isElementPresent == 2)
{
turn = 1;
}
else// condition if input is not an element of P
{
printf("Error: Guess is not part of choices. Please try again.\n");
}
chances--;
}
/* ----- WINNER CONDITIONS ----- */
if (chances == 0 && key != guess){ // if after 6 attempts and key is not equal
to the guess
printf("Player 1 wins!");
}
else if (key == guess){ //if the guess is correct
printf("Player 2 wins!");
}
return 0;
}