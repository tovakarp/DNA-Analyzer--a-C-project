
#include "seqdna.h"

char DnaSequence::pair(char c) {

    switch (c)
    {
        case ('A'): return 'T';

        case ('T'): return 'A';

        case ('C'): return 'G';

        case ('G'): return 'C';

        default: return '0';
    }

}

