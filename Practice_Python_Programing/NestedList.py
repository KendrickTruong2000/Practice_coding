def flatten_nestedlist(lst):
    flatten = []
    
    for item in lst:
        if isinstance(item, list):
            flatten.extend(flatten_nestedlist(item))
        else:
            flatten.append(item)
    
    return flatten

a = []
nested_list = [1, [2, [3, 4], 5]]
a = flatten_nestedlist(nested_list)
print(a)