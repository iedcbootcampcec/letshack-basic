def filter_even(number_list):
    result_list = []
    for number in number_list:
        if number % 2 == 0:
            result_list.append(number)
    return result_list
my_list = [1, 2, 3, 4, 5, 6, 7, 8, 9]

even_list = filter_even(my_list)
print(even_list)

type(even_list)
