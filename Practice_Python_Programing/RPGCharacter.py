full_dot = '●'
empty_dot = '○'

def create_character(name, strength, intelligence, charisma):

    if not isinstance(name, str):
        return 'The character name should be a string'
    elif not name:
        return 'The character should have a name'
    elif len(name) > 10:
        return 'The character name is too long'
    elif " " in name:
        return 'The character name should not contain spaces'

    if not all(isinstance(x, int) for x in (strength, intelligence, charisma)):
        return 'All stats should be integers'
    elif not all(x >= 1 for x in (strength, intelligence, charisma)):
        return 'All stats should be no less than 1'
    elif not all(x <= 4 for x in (strength, intelligence, charisma)):
        return 'All stats should be no more than 4'
    elif not strength + intelligence + charisma == 7:
        return 'The character should start with 7 points'
    
    s = '\nSTR '
    for x in range(1, 11):
        if x <= strength:
            s += full_dot
        else:
            s += empty_dot

    i = '\nINT '
    for x in range(1, 11):
        if x <= intelligence:
            i += full_dot
        else:
            i += empty_dot

    c = '\nCHR '
    for x in range(1, 11):
        if x <= charisma:
            c += full_dot
        else:
            c += empty_dot

    return name + s + i + c

character_messages = create_character('Kendrick', 4, 2, 1)
print(character_messages)
