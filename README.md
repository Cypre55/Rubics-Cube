# Read Me
Hello, I am ChaoticSaint46, a freshman at IIT KGP. This is the first-ever project I am hosting. It has always been my dream project to make a 3x3 Rubics Cube solver. I actually know how to solve the cube blindfolded. I would only have to study at the cube only once and I would generate a 20ish sequence of alphabets and then execute it. That is exactly how I want to make this solver. I can try my best at coding the algorithm generator, but i need help with the arduino programming.
For the principle of blindfold solving, please watch the following video: https://www.youtube.com/watch?v=A64Sy4WKiWY&t=130s

**Colour Coding**\
0 == Blue\
1 == White\
2 == Red\
3 == Yellow\
4 == Orange\
5 == Green

**Stuff To Do**
* Scanning the Cube - Arduino program (to get numbers as output and fill a similar 2d array separate for edges and corners)
  * Colour input is taken as rgb
  * So have to calibrate the rgb value in the start
  * then give 0-5 values
  * write into a file
* Algo generator - C program **(Old Pochmann method and M2 Method)**
  * Read the input file and store into an array
  * M execution (U B D F cycle) - Write Algo according to it, whether M was executed or not, A1 and A2, B1 and B2 so on.
  * I C W S edges switch on even numbers
  * Phases- Edges and Corners 
  * Compare the cube[] with unsolvedcube[] and note the alphabet and remember that it's done 
  * At reality checks, choose an alphabet that hasn't been used yet
  * write the output into a file
* Execution - Arduino program
  * Take the output file and run

**Original Configuration**(Describing a solved Cube)
* Corners (colours taken in anticlockwise manner and labeled)
  * 0 : 0 4 1 A
  * 1 : 0 3 4 B
  * 2 : 0 2 3 C
  * 3 : 0 1 2 D
  * 4 : 1 0 4 E
  * 5 : 1 2 0 F
  * 6 : 1 5 2 G
  * 7 : 1 4 5 H
  * 8 : 2 0 1 I
  * 9 : 2 3 0 J
  * 10: 2 5 3 K
  * 11: 2 1 5 L
  * 12: 3 0 2 M
  * 13: 3 4 0 N
  * 14: 3 5 4 O
  * 15: 3 2 5 P
  * 16: 4 0 3 Q
  * 17: 4 1 0 R
  * 18: 4 5 1 S
  * 19: 4 3 5 T
  * 20: 5 2 1 U
  * 21: 5 3 2 V
  * 22: 5 4 3 W
  * 23: 5 1 4 X
* Edges ( Basically Corners but excluding the 3rd element)

**Corners**\
SWAP: R U' R' U' R U R' F' R U R' U' R' F R\
A: Reality Check\
B: R D' SWAP D R'\ 
C: F SWAP F'\
D: F R' SWAP R F'\
E: Reality Check\
F: F2 SWAP F2\
G: D2 R SWAP R' D2\
H: D2 SWAP D2\
I: F' D SWAP F D'\
J: R2 D' SWAP D R2\
K: D R SWAP R' D'\
L: D SWAP D'\
M: R' SWAP R\
N: R2 SWAP R2\
O: R SWAP R'\
P: SWAP\
Q: R' F SWAP F' R\
R: Reality Check\
S: D' R SWAP R' D\
T: D' SWAP D\
U: F' SWAP F\
V: F' R' SWAP R F\
W: D2 F' SWAP F D2\
X: D F' SWAP F D'

**EDGES(Incorrect, Needs to be changed)**\
A: M2\
B: R' U R U' M2 U R' U' R\
C: U2 M' U2 M'\
D: L U' L' U M2 U' L U L'\
E: B L' B' M2 B L B'\
F: B L2 B' M2 B L2 B'\
G: B L B' M2 B L' N\
H: L B L' B' M2 B L B' L'\
I: D M' U R2 U' M U R2 U' D' M2\
J: U R U' M2 U R' U'\
K: Reality Check\
L: U' L' U M2 U' L U\
M: B' R B M2 B' R B\
N: R' B' R B M2 B' R' B R\
O: B' R' B M2 B' R B\
P: B' R2 B M2 B' R2 B\
Q: B' R B U R2 U' M2 U R2 U' B' R' B\
R: U' L U ​M2 U' L U\
S: M2 D U R2 U' M' U R2 U' M D'\ 
T: U R' U' M2 U R U'\
U: Reality Check\
V: U R2 U' M2 U R2 U'\
W: M U2 M U2\
X: U' L2 U M2 U' L2 U
