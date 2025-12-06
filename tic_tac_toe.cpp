#include <iostream>

using std::cout;
using std::cin;
using std::endl;

char field[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool is_occupied(int index) {
    return !std::isdigit(field[index]);
}

bool is_all_occupied() {
    for (int i = 0; i < 9; i++) {
        if (!is_occupied(i)) {
            return false;
        }
    }
    return true;
}

char chek_winner() {
    short win_indexes[8][3] = {
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    for(auto& row : win_indexes) {
        if (field[row[0]] == field[row[1]] && field[row[1]] == field[row[2]] && field[row[0]] == field[row[2]]) {
            return field[row[0]];
        }
    }
    if (is_all_occupied()) {
        return 'D';
    }
    return '\0';
}

int main() {
    char chr;
    int index;
    bool cell = 1; // O = 0; X = 1

    while (true) {
        if (chek_winner()) {
            cout << "Winner is " << chek_winner() << endl;
            break;
        }
        for (int i = 0; i < 9; i++) {
            cout << field[i] << "   ";
            if ((i + 1) % 3 == 0) {
                cout << '\n';
            }
        }
        cout << "Select a index: ";
        cin >> chr;
        if (!std::isdigit(chr)) {
            cout << "[!] Is not digit, try again." << endl;
            continue;
        }
        index = chr - '0' - 1;
        if (is_occupied(index)) {
            cout << "[!] This cell is occupied." << endl;
            continue;
        }
        field[index] = (cell) ? 'X' : 'O';
        cell = !cell;

    }
}