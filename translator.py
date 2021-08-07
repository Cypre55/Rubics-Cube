cornerMoves = {
    "B": "R d R u r u R U r f R U r u r F R D r",
    "C": "F R u r u R U r f R U r u r F R f",
    "D": "F r R u r u R U r f R U r u r F R R f",
    "F": "F F R u r u R U r f R U r u r F R F F",
    "G": "D D R R u r u R U r f R U r u r F R r D D",
    "H": "D D R u r u R U r f R U r u r F R D D",
    "I": "f D R u r u R U r f R U r u r F R F d",
    "J": "R R d R u r u R U r f R U r u r F R D R R",
    "K": "D R R u r u R U r f R U r u r F R r d",
    "L": "D R u r u R U r f R U r u r F R d",
    "M": "r R u r u R U r f R U r u r F R R",
    "N": "R R R u r u R U r f R U r u r F R R R",
    "O": "R R u r u R U r f R U r u r F R r",
    "P": "R u r u R U r f R U r u r F R",
    "Q": "r F R u r u R U r f R U r u r F R f R",
    "S": "d R R u r u R U r f R U r u r F R r D",
    "T": "d R u r u R U r f R U r u r F R D",
    "U": "f R u r u R U r f R U r u r F R F",
    "V": "f r R u r u R U r f R U r u r F R R F",
    "W": "D D f R u r u R U r f R U r u r F R F D D",
    "X": "D f R u r u R U r f R U r u r F R F d",
    "Z": "",
}

edgeMoves = {
    "a": "R R L L",
    "A": "R R L L",
    "b": "r D R d R R L L U r u R",
    "B": "r U R u R R L L D r d R",
    "c": "D D r L B B r L",
    "C": "U U r L F F r L",
    "d": "L d l D R R L L u L U l",
    "D": "L u l U R R L L d L D l",
    "e": "F l f R R L L B L b",
    "E": "B l b R R L L F L f",
    "f": "F L L f R R L L B L L b",
    "F": "B L L b R R L L F L L f",
    "g": "F L f R R L L B l b",
    "G": "B L b R R L L F l f",
    "h": "L F l f R R L L B L b l",
    "H": "L B l b R R L L F L f l",
    "i": "U r L B R R b R l D R R d u R R L L",
    "I": "D r L F R R f R l U R R u d R R L L",
    "j": "D R d R R L L U r u",
    "J": "U R u R R L L D r d",
    "l": "d l D R R L L u L U",
    "L": "u l U R R L L d L D",
    "m": "f R F R R L L b R B",
    "M": "b R B R R L L f R F",
    "n": "r f R F R R L L b r B R",
    "N": "r b R B R R L L f r F R",
    "o": "f r F R R L L b R B",
    "O": "b r B R R L L f R F",
    "p": "f R R F R R L L b R R B",
    "P": "b R R B R R L L f R R F",
    "q": "f R F D R R d R R L L U R R u b r B",
    "Q": "b R B U R R u R R L L D R R d f r F",
    "r": "d L D R R L L u L U",
    "R": "u L U R R L L d L D",
    "s": "R R L L D U R R u r L F R R f R l d",
    "S": "R R L L U D R R d r L B R R b R l u",
    "t": "D r d R R L L U R u",
    "T": "U r u R R L L D R d",
    "v": "D R R d R R L L U R R u",
    "V": "U R R u R R L L D R R d",
    "w": "R l F F R l U U",
    "W": "R l B B R l D D",
    "x": "d L L D R R L L u L L U",
    "X": "u L L U R R L L d L L D",
    "Z": "",
}

parity = "R U r u r F R R u r u R U r f"

with open("sols.txt", "r") as f:
    lines = f.readlines()

moves = []
cornerLine = lines[0].split()

for move in cornerLine:
    moves.append(cornerMoves[move] + " ")

if len(lines) == 3:
    moves.append(parity + " ")

edgeLine = lines[1].split()

for move in edgeLine:
    moves.append(edgeMoves[move] + " ")

with open("moves.txt", "w") as f:
    f.writelines(moves)

print("Moves saved to moves.txt")

