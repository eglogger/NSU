// В выражение (((1? 2)?3)?4)?5 вместо каждого знака “?” вставить знак одного из четырех арифметических   действий : +, - , * , / так,
// чтобы результат вычислений равнялся 25.

// 0 - "+"
// 0 - "-"
// 0 - "*"
// 0 - "/"


#include <stdio.h>

int main() {

    int s = 0;

    for(int q = 0; q < 4; q++) {
        for (int w = 0; w < 4; w++) {
            for (int e = 0; e < 4; e++) {
                for (int r = 0; r < 4; r++) {

                    s = 1;

                    switch (q){
                        case 0:
                            s += 2;
                            break;
                        case 1:
                            s -= 2;
                            break;
                        case 2:
                            s *= 2;
                            break;
                        case 3:
                            s /= 2;
                            break;
                    }

                    switch (w){
                        case 0:
                            s += 3;
                            break;
                        case 1:
                            s -= 3;
                            break;
                        case 2:
                            s *= 3;
                            break;
                        case 3:
                            s /= 3;
                            break;
                    }

                    switch (e){
                        case 0:
                            s += 4;
                            break;
                        case 1:
                            s -= 4;
                            break;
                        case 2:
                            s *= 4;
                            break;
                        case 3:
                            s /= 4;
                            break;
                    }

                    switch (r){
                        case 0:
                            s += 5;
                            break;
                        case 1:
                            s -= 5;
                            break;
                        case 2:
                            s *= 5;
                            break;
                        case 3:
                            s /= 5;
                            break;
                    }

                    if (s == 25) {
                        printf("%d %d %d %d %d", q, w, e, r, s);
                        return(0);
                    }
                }
            }
        }
    }
    
    return(0);
    
}