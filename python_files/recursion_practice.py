"""problems for practicing some simple recursion problems"""


def raise_iter(number, exponent):
    """iterative version of raising an exponent to a number"""
    prod = 1
    for i in range(exponent, 0, -1):
        prod *= number
    return prod


def raises(number, exponent):
    """raising a number to exponenn"""
    if exponent == 0:
        return 1
    else:
        return number * raises(number, exponent - 1)


def raise_1(base, exponent):
    """efficient version of raising an exposnnet to a number"""
    if exponent == 0:
        return 1
    else:
        half = raise_1(base, exponent // 2)
        if exponent % 2 == 0:
            return half * half
        else:
            return base * half * half


def check_palindrome(string):
    if len(string) <= 1:
        return True
    return string[0] == string[-1] and check_palindrome(string[1:-1])


def binary_search(sorted_arr, left, right, target):
    if left > right:
        return -1
    middle = left + right // 2
    if sorted_arr[middle] == target:
        return middle
    else:
        if sorted_arr[middle] > target:
            return binary_search(sorted_arr, left, middle - 1, target)
        else:
            return binary_search(sorted_arr, middle + 1, right, target)


def choose_k(n, k):
    if k == 0 or k == n:
        return 1
    else:
        return choose_k(n - 1, k) + choose_k(n - 1, k - 1)


if __name__ == '__main__':
    assert (raises(2, 6))
    assert (raise_iter(2, 6))
    assert raise_1(2, 6) == 64
    assert check_palindrome("ti aba it") == True, "not a palindrome"
    arr = [1, 2, 3, 4, 5, 6]
    assert (binary_search(arr, 0, len(arr) - 1, 3)) == 2
    assert (choose_k(4, 2)) == 6
