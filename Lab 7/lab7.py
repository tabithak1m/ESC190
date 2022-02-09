# 2. Write Python code to find the cost of the minimum-energy seam in a list of lists.

energies = [[24,      22,      30,      15,      18,      19],
            [12,      23,      15,      23,      10,      15],
            [11,      13,      22,      13,      21,      14],
            [13,      15,      17,      28,      19,      21],
            [17,      17,      7,       27,      20,      19]]

    # The correct output for the given energies data is 15+10+13+17+7 = 62.



def min_energy(energies_og):
    energies = []
    for i in range(len(energies_og)):
        energy_row = []
        for j in range(len(energies_og[0])):
            min = 0
            if i>0:
                up = energies[i-1][j]
                min = up
                if j>0:
                    upleft = energies[i-1][j-1]
                    if upleft < min:
                        min = upleft
                if j<len(energies_og[0])-1:
                    upright = energies[i-1][j+1]
                    if upright < min:
                        min = upright
            energy_row.append(energies_og[i][j] + min)
        energies.append(energy_row)

    path = [0]*len(energies)
    for y in range(len(energies)-1, -1, -1):
        min = 0
        if y == len(energies)-1:
            for x in range(len(energies[0])):
                if energies[y][x] < energies[y][min]:
                    min = x;
        else:
            for x in range(-1,2):
                offset = path[y+1]
                if offset + x < 0 or offset + x >= len(energies[0]):
                    continue
                if energies[y][offset+x] < energies[y][offset+min]:
                    min = x
            min += path[y+1]
        path[y] = min;

    return path

def print_cost(energies, seam):
    string = ""
    for i in range(len(energies)):
        string += str(energies[i][seam[i]]) + "+"
    string = string[:-1]
    string += "="+str(eval(string))
    print(string)