#include <bits/stdc++.h>


// DONE
void day1A()
{
    /*
        Before you leave, the Elves in accounting just need you to fix your expense
        report (your puzzle input); apparently, something isn't quite adding up.

        Specifically, they need you to find the two entries that sum to 2020 and
        then multiply those two numbers together.

        For example, suppose your expense report contained the following:

        1721
        979
        366
        299
        675
        1456

        In this list, the two entries that sum to 2020 are 1721 and 299. Multiplying
        them together produces 1721 * 299 = 514579, so the correct answer is 514579.
    */

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

// DONE
void day1B()
{
    /*
        The Elves in accounting are thankful for your help; one of them even offers
        you a starfish coin they had left over from a past vacation. They offer you
        a second one if you can find three numbers in your expense report that meet
        the same criteria.

        Using the above example again, the three entries that sum to 2020 are 979, 
        366, and 675. Multiplying them together produces the answer, 241861950.
    */
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
    /*
        Your flight departs in a few days from the coastal airport; the easiest
        way down to the coast from here is via toboggan.

        The shopkeeper at the North Pole Toboggan Rental Shop is having a bad day.
        "Something's wrong with our computers; we can't log in!" You ask if you 
        can take a look.

        Their password database seems to be a little corrupted: some of the 
        passwords wouldn't have been allowed by the Official Toboggan Corporate
        Policy that was in effect when they were chosen.

        To try to debug the problem, they have created a list (your puzzle input)
        of passwords (according to the corrupted database) and the corporate 
        policy when that password was set.

        For example, suppose you have the following list:

        1-3 a: abcde
        1-3 b: cdefg
        2-9 c: ccccccccc
        Each line gives the password policy and then the password. The password 
        policy indicates the lowest and highest number of times a given letter 
        must appear for the password to be valid. For example, 1-3 a means that
        the password must contain a at least 1 time and at most 3 times.

        In the above example, 2 passwords are valid. The middle password, cdefg,
        is not; it contains no instances of b, but needs at least 1. The first
        and third passwords are valid: they contain one a or nine c, both within
        the limits of their respective policies.

        How many passwords are valid according to their policies?    
    */
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
    /*
        While it appears you validated the passwords correctly, they don't seem
        to be what the Official Toboggan Corporate Authentication System is expecting.

        The shopkeeper suddenly realizes that he just accidentally explained the
        password policy rules from his old job at the sled rental place down the
        street! The Official Toboggan Corporate Policy actually works a little differently.

        Each policy actually describes two positions in the password, where 1 means
        the first character, 2 means the second character, and so on. (Be careful; 
        Toboggan Corporate Policies have no concept of "index zero"!) Exactly one of
        these positions must contain the given letter. Other occurrences of the letter
        are irrelevant for the purposes of policy enforcement.

        Given the same example list from above:

        1-3 a: abcde is valid: position 1 contains a and position 3 does not.
        1-3 b: cdefg is invalid: neither position 1 nor position 3 contains b.
        2-9 c: ccccccccc is invalid: both position 2 and position 9 contain c.
        How many passwords are valid according to the new interpretation of the policies?
    */
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


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    day2B();
}