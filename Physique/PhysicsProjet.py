from manim import *
from electromagnetism import MyField
from electromagnetism import Current

class ExampleScene(Scene):
    def construct(self):
        current1 = Current(LEFT * 2.5)
        current2 = Current(RIGHT * 2.5, direction=IN)
        field = MyField(current1, current2)
        self.add(field, current1, current2)