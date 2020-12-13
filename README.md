# Rubik's Cube Solver

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com) \
For the principle of blindfold solving, please watch the following video: https://www.youtube.com/watch?v=A64Sy4WKiWY&t=130s
Update: There has been a change of plan. The project is just about generating a solution and not actuating the movements

**Colour Coding**\
0 == Blue\
1 == White\
2 == Red\
3 == Yellow\
4 == Orange\
5 == Green

**Stuff To Do**
* Algo generator - C program **(Old Pochmann method and M2 Method)**
  * [x] Read the input file and store into an array
  * [x] I C W S edges switch on even numbers
  * [x] Phases- Edges and Corners
  * [x] Compare the cube[] with unsolvedcube[] and note the alphabet and remember that it's done
  * [x] At reality checks, choose an alphabet that hasn't been used yet
  * [x] write the output into a file

**Future Work**
* Lower no. of moves taken, Optimise
* Physical Solver

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

**Parity**\
D' L2 D R2 L2 U' L2 U

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

**EDGES**\
Basically, Edges when executed pair restore the middle slice back to original form. In our case, we cannot rotate it. The lowercase algorithms are for when middle slice is inverted and uppercase is for when it is not.
a: R R L L,\
A: R R L L,\
b: R' D R D' R R L L U R' U' R,\
B: R' U R U' R R L L D R' D' R,\
c: D D R' L B B R' L,\
C: U U R' L F F R' L,\
d: L D' L' D R R L L U' L U L',\
D: L U' L' U R R L L D' L D L',\
e: F L' F' R R L L B L B',\
E: B L' B' R R L L F L F',\
f: F L L F' R R L L B L L B',\
F: B L L B' R R L L F L L F',\
g: F L F' R R L L B L' B',\
G: B L B' R R L L F L' F',\
h: L F L' F' R R L L B L B' L',\
H: L B L' B' R R L L F L F' L',\
i: U R' L B R R B' R L' D R R D' U' R R L L,\
I: D R' L F R R F' R L' U R R U' D' R R L L,\
j: D R D' R R L L U R' U',\
J: U R U' R R L L D R' D',\
K: Reality Check,\
l: D' L' D R R L L U' L U,\
L: U' L' U R R L L D' L D,\
m: F' R F R R L L B' R B,\
M: B' R B R R L L F' R F,\
n: R' F' R F R R L L B' R' B R,\
N: R' B' R B R R L L F' R' F R,\
o: F' R' F R R L L B' R B,\
O: B' R' B R R L L F' R F,\
p: F' R R F R R L L B' R R B,\
P: B' R R B R R L L F' R R F,\
q: F' R F D R R D' R R L L U R R U' B' R' B,\
Q: B' R B U R R U' R R L L D R R D' F' R' F,\
r: D' L D R R L L U' L U,\
R: U' L U R R L L D' L D,\
s: R R L L D U R R U' R' L F R R F' R L' D',\
S: R R L L U D R R D' R' L B R R B' R L' U',\
t: D R' D' R R L L U R U',\
T: U R' U' R R L L D R D',\
U: Reality Check,\
v: D R R D' R R L L U R R U',\
V: U R R U' R R L L D R R D',\
w: R L' F F R L' U U,\
W: R L' B B R L' D D,\
x: D' L L D R R L L U' L L U,\
X: U' L L U R R L L D' L L D