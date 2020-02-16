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


def find_permute(str):
    print(str)
    if len(str) == 1:
        return str
    permutations = find_permute(str[1:])
    results = list()
    first_char = str[0]
    print(permutations)
    for permute in permutations:
        for idx in range(len(permute)+1):
            results.append(permute[:idx] + first_char + permute[idx:])
    return results


def permute(so_far, rest, result):
    if len(rest) == 0:
        result.append(so_far)
    else:
        for i in range(0, len(rest)):
            next = so_far + rest[i]
            remaining = rest[:i] + rest[i+1:]
            permute(next, remaining, result)


def subset(so_far, rem):
    if rem == "":
        print(so_far)
    else:
        subset(so_far + rem[0], rem[1:])
        subset(so_far, rem[1:])


def isAnagram(so_far, rest, lex):
    if rest == "":
        if so_far in lex:
            print(so_far)
            return True
    else:
        for i in range(0,len(rest)):
            if isAnagram(so_far + rest[i], rest[:i] + rest[i+1:], lex):
                return True
    return False


if __name__ == '__main__':
    assert (raises(2, 6))
    assert (raise_iter(2, 6))
    assert raise_1(2, 6) == 64
    assert check_palindrome("ti aba it") == True, "not a palindrome"
    arr = [1, 2, 3, 4, 5, 6]
    assert (binary_search(arr, 0, len(arr) - 1, 3)) == 2
    assert (choose_k(4, 2)) == 6
    # (find_permute("dogs"))
    # result = []
    # permute("", "cat",result)
    # print(result)
    # (subset("", "abcd"))
    print(isAnagram("", "dope", ["dope","pode","boat","toab","rope","epod"]))