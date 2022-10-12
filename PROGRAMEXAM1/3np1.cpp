// here are the required function signatures
// Gradescope will not work without them all included

bool isOdd(int n) {
    if (n % 2 != 0) {
        return true;
    } else {
        return false;
    }
}

int len3nplus1(int value) {
    int count = 0;
    while (value != 1) {
        if (isOdd(value)) {
            value = (3 * value) + 1;
            ++count;
        } else {
            value /= 2;
            ++count;
        }
    }
    return count + 1;
}

int sumSeq3nPlus1(int value) {
    int sum = value;
    while (value !=1) {
        if (isOdd(value)) {
            value = (3 * value) + 1;
            sum += value;
        } else {
            value /= 2;
            sum += value;
        }
    }
    return sum;
}

int longestSequence(int max) {
    int longestSequence = 1;
    for (int i = 1; i <= max; ++i) {
        if (len3nplus1(longestSequence) < len3nplus1(i)) {
            longestSequence = i;
        }
    }
    return longestSequence;
}

