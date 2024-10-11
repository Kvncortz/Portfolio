# logical operator = evaluate mulitple conditions (or, and, not)
#                    or  = at least one condition must be true
#                    and = both conditions must be true
#                    not = inverts the condition (not False, not True)


""" The or operator
temp = 20
is_raining = True

if temp > 35 or temp < 0 or is_raining:
    print("The outdoor event is cancelled")
else:
    print("The outdoor even is still on")
"""

temp = 30
is_sunny = False

if temp >= 28 and is_sunny:
    print("Is is HOT outside🥵")
    print("It is SUNNY outside😎")
elif temp <=0 and is_sunny:
    print("Is is COLD outside🥶")
    print("It is SUNNY outside😎")
elif 28 > temp > 0 and is_sunny:
    print("It is warm outside")
    print("It is SUNNY outside😎")
elif temp >= 28 and not is_sunny:
    print("It is HOT outside")
    print("It is CLOUDY outside😎")

