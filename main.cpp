#include <bits/stdc++.h>

void day1A()
{
    std::vector<int> inputNumbers;

    int a;
    while (std::cin >> a) {
        inputNumbers.push_back(a);
    }

    for (int i = 0; i < inputNumbers.size(); ++i) {
        for (int j = i + 1; j < inputNumbers.size(); ++j) {
            if (inputNumbers[i] + inputNumbers[j] == 2020) {
                std::cout << inputNumbers[i] * inputNumbers[j] << std::endl;
            }
        }
    }
}

void day1B()
{
    std::vector<int> inputNumbers;

    int a;
    while (std::cin >> a) {
        inputNumbers.push_back(a);
    }

    for (int i = 0; i < inputNumbers.size(); ++i) {
        for (int j = i + 1; j < inputNumbers.size(); ++j) {
            for (int k = j + 1; k < inputNumbers.size(); ++k) {
                if (inputNumbers[i] + inputNumbers[j] + inputNumbers[k] == 2020) {
                    std::cout << inputNumbers[i] * inputNumbers[j] * inputNumbers[k] << std::endl;
                }
            }
        }
    }
}

void day2A()
{
    int min, max;
    std::string word;
    char c, discard;

    int okcount = 0;

    while (std::cin >> min) {
        std::cin >> discard;// discard -
        std::cin >> max;
        std::cin >> c;
        std::cin >> discard; // discard :
        std::cin >> word;
        
        int count = 0;
        for (char letter : word) {
            if (letter == c) {
                count++;
            }
        }

        if (min <= count && max >= count) {
            okcount++;
        }
    }

    std::cout << okcount << std::endl;
}

void day2B()
{
    int first, second;
    std::string word;
    char c, discard;

    int okcount = 0;

    while (std::cin >> first) {
        std::cin >> discard;// discard -
        std::cin >> second;
        std::cin >> c;
        std::cin >> discard; // discard :
        std::cin >> word;

        int count = 0;
        bool f = false;
        bool s = false;
        int pos = 1;
        for (char letter : word) {
            if (pos == first) {
                if (letter == c) {
                    f = true;
                }
            } else if (pos == second) {
                if (letter == c) {
                    s = true;
                }
            }

            pos++;
        }

        if (f != s) {
            okcount++;
        }
    }

    std::cout << okcount << std::endl;
}

void day3A()
{
    int stepSize = 3;
    int lineCount = 0;
    int treeCount = 0;

    std::string line;


    while (std::cin >> line) {
        int position = (lineCount * stepSize) % line.size();

        if (line[position] == '#') {
            treeCount++;
        }

        lineCount++;
    }


    std::cout << treeCount << std::endl;
}

void day3B()
{
    int lineCount = 0;

    int oneCount = 0;
    int threeCount = 0;
    int fiveCount = 0;
    int sevenCount = 0;
    int oneTwoCount = 0;
    std::string line;


    while (std::cin >> line) {
        if (line[(lineCount * 1) % line.size()] == '#') {
            oneCount++;
        }

        if (line[(lineCount * 3) % line.size()] == '#') {
            threeCount++;
        }

        if (line[(lineCount * 5) % line.size()] == '#') {
            fiveCount++;
        }

        if (line[(lineCount * 7) % line.size()] == '#') {
            sevenCount++;
        }

        if (lineCount % 2 == 0) {
            if (line[((lineCount / 2) * 1) % line.size()] == '#') {
                oneTwoCount++;
            }
        }

        lineCount++;
    }

    long double res = (double)oneCount * threeCount * fiveCount * sevenCount * oneTwoCount;


    std::cout << res << std::endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    // day1A();
    // day1B();
    
    // day2A();
    // day2B();
    
    // day3A();
    // day3B();
}