#!/bin/bash
ARG="23 85 12 47 56 50 2 80 1 93 21 60 77 40 15 46 57 68 24 3 48 53 14 43 90 94 74 34 75 44 5 83 31 11 89 99 61 100 42 71 33 84 76 39 7 62 64 95 79 88 92 26 10 35 38 67 36 86 72 28 81 29 82 54 98 69 32 19 91 41 45 58 13 55 37 96 6 73 66 70 51 97 52 20 65 59 22 25 27 18 16 87 30 78 8 17 9 63 49 4";
./push_swap $ARG | wc -l
./push_swap $ARG |./checker $ARG