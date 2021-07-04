# Palindrome checker written in Python3
#
# To run tests with doctest:
#   python3 -m doctest -v JasonTurley_palindrome_checker.py
#
# To run tests manually:
#   python3 JasonTurley_palindrome_checker


def palindrome_checker(word):
    """
    Doctest examples:
    >>> palindrome_checker("racecar")
    True

    >>> palindrome_checker("mom")
    True

    >>> palindrome_checker("spoon")
    False
    """

    # begin at the starting and ending letter in the word
    i = 0
    j = len(word) - 1

    # if at any point the letters are not equal, return False
    while i <= j:
        if word[i] != word[j]:
            return False

        i += 1
        j -= 1


    # the letters were equal for the entire loop, so return True
    return True



words = ["happy", "rotor", "pancakes", "dog__god"]

for word in words:
    if palindrome_checker(word):
        print("{} is a palindrome".format(word))
    else:
        print("{} is not a palindrome".format(word))
