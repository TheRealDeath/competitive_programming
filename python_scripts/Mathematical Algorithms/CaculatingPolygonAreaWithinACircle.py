import math
def arean(circle_radius, number_of_sides):
  s = (circle_radius*math.sin(math.pi/number_of_sides))
  a = (circle_radius*math.cos(math.pi/number_of_sides))*number_of_sides
  return float(('%.3f' % (s*a)))