
def apply_discount(price, discount):
    if isinstance(price, (int, float)) == False:
        return 'The price should be a number'
    elif price <= 0:
        return 'The price should be greater than 0'

    if  isinstance(discount, (int, float)) == False:
        return 'The discount should be a number'
    elif discount < 0 or discount > 100:
        return 'The discount should be between 0 and 100'

    discount_price = price * (discount/100)
    final_price = price - discount_price

    return final_price

price = 100
discount = 20
total = apply_discount(price, discount)
print(total)