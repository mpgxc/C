def SelectionMinor(arr):
    new_array = []
    arr_cpy = arr.copy()

    for __ in arr_cpy:
        minor = min(arr_cpy)

        new_array.append(minor)

        arr_cpy.remove(minor)

    return new_array
