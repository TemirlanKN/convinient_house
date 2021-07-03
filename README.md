# convinient_house
Repository includes a simple solution(c++ programm) of finding the best house to live. This task was given in a Google Coding Interview by a Google Software Engineer Clement Mihailescu (Co_Foubder & CEO of AlgoExpert).

Imagine that you're about to move to a new location and you want to find an apartment where you want to living. You have one street with many blocks (blocks are exactly apperments). You want to be sure that apartment you living is really good for you, the way you determine if apartment is good for you is if is's close to some buildings that you really value. For example you may value gym, supermarkets, library and you want them to be near you living house.

You will be given information (on c++ programm you should enter by yourself) about at each apartment whether or not there is a building (like office, school, gym).
And you should to find the apartment that minimises a distance between your house and buildings you value.

For example:
'''
Apartments = [
  {
    "gym" : false
    "school" : true
    "store" : false
  },
  {
    "gym" : true
    "school" : false
    "store" : false
  },
  {
    "gym" : true
    "school" : true
    "store" : false
  },
  {
    "gym" : false
    "school" : true
    "store" : false
  },
  {
    "gym" : false
    "school" : true
    "store" : true
  }.
'''

'''
Required buildings = { "gym", "school", "store" }.
Also it ca be like = {"gym", "store"} or just {"store"}.
'''

In repo trere is a programm which find the best apartments to live. Input : list of apartents with their buildings(places) with boolean sign (true if it exists or false if it doesn't exist in the apartment).

Also in programm convinient_house.cpp by default defined that there are exactly 3 places for every apartment(or house). You can change that in the code:
'''
#define places 3
'''
to
'''
#define places (number you want)
'''
