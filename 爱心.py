import turtle
import random
import time
from playsound import playsound



# 设置画布和画笔
canvas = turtle.Screen()
canvas.bgcolor("black")
pen = turtle.Turtle()
pen.speed(0)
pen.penup()
pen.hideturtle()


# 画红色爱心
pen.color("red")
pen.goto(0, 0)
pen.begin_fill()
pen.left(45)
pen.forward(100)
pen.circle(50, 180)
pen.right(90)
pen.circle(50, 180)
pen.forward(100)
pen.end_fill()

# 画五颜六色的星星
colors = ["yellow", "blue", "green", "purple", "orange"]
star_positions = [(0, 150), (-100, 100), (100, 100), (-150, 0), (150, 0), (0, -150), (-50, -50), (50, -50), (-100, -100), (100, -100)]
for position in star_positions:
    pen.color(random.choice(colors))
    pen.goto(position)
    pen.begin_fill()
    for i in range(5):
        pen.forward(50)
        pen.right(144)
    pen.end_fill()
    time.sleep(0.7)

# 写出汉字
pen.color("pink")
pen.goto(-200, -200)
pen.write("飘飘", font=("Arial", 30, "normal"))

# 天上掉落粉色的雪花
snowflake_pen = turtle.Turtle()
snowflake_pen.hideturtle()
snowflake_pen.penup()
snowflake_pen.speed(0)
snowflake_pen.color("pink")
for i in range(100):
    x = random.randint(-300, 300)
    y = random.randint(0, 400)
    snowflake_pen.goto(x, y)
    snowflake_pen.dot()
# 画粉色小心心
pen.color("pink")
pen.goto(-100, -220)
pen.begin_fill()
pen.left(45)
pen.forward(50)
pen.circle(25, 180)
pen.right(90)
pen.circle(25, 180)
pen.forward(50)
pen.end_fill()


pen.color("pink")
pen.goto(0, 0)
pen.write("拜托啦，多多关照，要共度余生哦~", align="center", font=("Arial", 30, "normal"))
canvas.update()

# 等待3秒

# 显示画布
canvas.mainloop()