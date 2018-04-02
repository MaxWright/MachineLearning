#include <iostream>
#include <stdlib.h>
#include <vector>
#include "header/qLearning.h"

// Special thanks to the individual behind Mnemosyne_Studio for the tutorial on QLearning
// Their website: http://mnemstudio.org/index.php
int main() {
    // The reward matrix.
    int r[6][6] = {
            {-1,-1, -1, -1, 0, -1},
            {-1, -1, -1, 0, -1, 100},
            {-1, -1, -1, 0, -1, -1},
            {-1, 0, 0, -1, 0, -1},
            {0, -1, -1, 0, -1, 100},
            {-1, 0, -1, -1, 0, 100},
    };

    // The Q Matrix, or what the machine knows.
    int q[6][6] = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
    };

    // Print Matricies
    std::cout << std::endl;
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < 6; ++j) {
            std::cout << q[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < 6; ++j) {
            std::cout << r[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Learn
    int moves = 10000;
    int position = 0;
    for(int i = 0; i < moves; ++i) {
        // Where Can I go?
        std::vector<int> possibilities;
        for(int j = 0; j < 6; ++j) {
            if(r[position][j] == -1) {

            } else {
                possibilities.push_back(j);
            }
        }
        // Move
        int oldPosition = position;
        position = possibilities[ rand() % possibilities.size() ];

        // What did I learn?
        // The reward for moving there plus the max of the q values thereafter.
        int max = 0;
        for(int j = 0; j < 6; ++j) {
            if(q[position][j] > max) {
                max = q[position][j];
            }
        }
        q[oldPosition][position] = r[oldPosition][position] + max * 80 / 100;
    }

    // Print Matricies
    std::cout << std::endl;
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < 6; ++j) {
            std::cout << q[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for(int i = 0; i < 6; ++i) {
        for(int j = 0; j < 6; ++j) {
            std::cout << r[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}